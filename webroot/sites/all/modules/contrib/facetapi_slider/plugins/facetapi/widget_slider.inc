<?php

/**
 * @file
 */

/**
 * Slider widget for range filtering.
 */
class FacetapiWidgetSlider extends FacetapiWidget {

  /**
   * JavaScript settings.
   *
   * @var array
   */
  protected $jsSettings = array(
    'makeSlider' => 1,
  );

  /**
   * Renders the form.
   */
  public function execute() {

    $facet = $this->facet->getFacet();
    $adapter = $this->build['#adapter'];

    // Get our searched values from the active item.
    if (isset($facet)) {

      $searched_values = $adapter->getActiveItems($facet);
      if (!empty($searched_values)) {
        $searched_values = reset($searched_values);
        $value = $searched_values['value'];

        // Remove the two brackets.
        $range = explode(' TO ', trim($value, '{[]}'));

        $slider_min_handle = $range[0];
        $slider_max_handle = $range[1];

        if ($slider_min_handle == $slider_max_handle) {
          return FALSE;
        }
      }
    }

    // Sets the key, captures the facet's render array.
    // We do not move this to the top since we do not want to
    // initialize a build if it is not needed.
    $this->key = $this->build['#facet']['name'];
    $build = $this->facet->getBuild();
    $slider = reset($build);

    $slider_min = $slider['#range_min'];
    $slider_max = $slider['#range_max'];
    $slider_min_global = $slider['#global_range_min'];
    $slider_max_global = $slider['#global_range_max'];
    $precision = $this->settings->settings['precision'];
    $step = $this->settings->settings['step'];

    // If the min global value of the slider is higher than min or
    // if the max global value of the slider is lower than max
    // adapt the values so the slider doesn't oversize and you can slide back.
    if ($slider_min < $slider_min_global) {
      $slider_min_global = $slider_min;
    }

    if ($slider_max > $slider_max_global) {
      $slider_max_global = $slider_max;
    }

    // Rounding based on the step.
    $slider_min_global = round($slider_min_global / $step) * $step;
    $slider_max_global = ceil($slider_max_global / $step) * $step;

    if ($slider_min == $slider_max) {
      // Remove the slider because no results can be given.
      $this->build[$this->facet['field alias']] = NULL;
      return;
    }

    $this->jsSettings['sliderMin'] = $slider_min;
    $this->jsSettings['sliderMax'] = $slider_max;
    $this->jsSettings['sliderMinGlobal'] = $slider_min_global;
    $this->jsSettings['sliderMaxGlobal'] = $slider_max_global;
    $this->jsSettings['prefix'] = $this->settings->settings['prefix'];
    $this->jsSettings['suffix'] = $this->settings->settings['suffix'];
    $this->jsSettings['precision'] = $precision;
    $this->jsSettings['sliderStep'] = (double) $step;

    $this->build[$this->facet['field alias']] = drupal_get_form('facetapi_slider_widget_form_' . $this->facet['field alias'], $adapter, $this->build);
  }

  /**
   * Form builder function for the facet block.
   */
  public static function widgetForm($form, $form_state, $form_id, FacetapiAdapter $adapter, $build = array()) {
    $slider = array();

    if (isset($build['#facet']) && isset($build[$build['#facet']['field alias']]) && isset($build[$build['#facet']['field alias']][$build['#facet']['field']])) {
      $slider = $build[$build['#facet']['field alias']][$build['#facet']['field']];
    }
    $form['slider']['min'] = array(
      '#type' => 'textfield',
      '#title' => t('Min'),
      '#size' => 5,
      '#default_value' => isset($slider['#range_min']) ? $slider['#range_min'] : 0,
      '#attributes' => array(
        'class' => array('facetapi-slider-min'),
      ),
    );

    $form['slider']['max'] = array(
      '#type' => 'textfield',
      '#title' => t('Max'),
      '#size' => 5,
      '#default_value' => isset($slider['#range_max']) ? $slider['#range_max'] : 0,
      '#attributes' => array(
        'class' => array('facetapi-slider-max'),
      ),
    );
    $form['slider']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );
    $exclude = array('q' => 1, 'page' => 1);
    if (isset($build['#facet']['field alias'])) {
      $exclude[$build['#facet']['field alias']] = 1;
    }
    $form['slider']['field_alias'] = array(
      '#type' => 'hidden',
      '#default_value' => isset($build['#facet']['field alias']) ? $build['#facet']['field alias'] : '',
    );
    $form['slider']['field_type'] = array(
      '#type' => 'hidden',
      '#default_value' => isset($build['#facet']['field type']) ? $build['#facet']['field type'] : '',
    );
    $form['slider']['get'] = array(
      '#type' => 'hidden',
      '#default_value' => json_encode(array_diff_key($_GET, $exclude)),
    );
    $form['slider']['path'] = array(
      '#type' => 'hidden',
      '#default_value' => $_GET['q'],
    );
    // Only add JS if we are on the actual search page.
    if (isset($build['#attributes'])) {
      $form['#attributes'] = $build['#attributes'];
      $form['slider']['#attached']['library'][] = array('system', 'ui.slider');
      $form['slider']['#attached']['js'][] = drupal_get_path('module', 'facetapi_slider') . '/facetapi_slider.js';
    }
    $form['#action'] = url('facetapi/widget/submit/' . $form_id . '/' . $adapter->getSearcher());
    return $form;
  }

  public static function widgetFormValidate($form, &$form_state) {
    //Nothing to do...
  }

  public static function widgetFormSubmit($form, &$form_state) {
    $adapter = $form['#facetapi_adapter'];
    $url_processor = $adapter->getUrlProcessor();
    $filter_key = $url_processor->getFilterKey();

    $query_string = (array) json_decode($form_state['values']['get'], TRUE);
    if (empty($query_string[$filter_key])) {
      $query_string[$filter_key] = array();
    }

    $my_field = rawurlencode($form_state['values']['field_alias']);

    // Remove any existing filters for my field.
    foreach ($query_string[$filter_key] as $idx => $filter) {
      $parts = explode(':', $filter, 2);
      if ($parts[0] == $my_field) {
        unset($query_string[$filter_key][$idx]);
      }
    }

    $query_string[$filter_key][] = $my_field . ':' . "[{$form_state['values']['min']} TO {$form_state['values']['max']}]";
    $form_state['redirect'] = array($form_state['values']['path'], array('query' => $query_string));
  }

  /**
   * Allows the widget to provide additional settings to the form.
   */
  function settingsForm(&$form, &$form_state) {

    $form['widget']['widget_settings']['slider'][$this->id]['prefix'] = array(
      '#type' => 'textfield',
      '#title' => t('Prefix'),
      '#size' => 5,
      '#default_value' => $this->settings->settings['prefix'],
      '#description' => t('Adds a prefix to the slider, e.g. $, #.'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );

    $form['widget']['widget_settings']['slider'][$this->id]['suffix'] = array(
      '#type' => 'textfield',
      '#title' => t('Suffix'),
      '#size' => 5,
      '#default_value' => $this->settings->settings['suffix'],
      '#description' => t('Adds a suffix to the slider, e.g. &euro;, pcs., etc.'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );

    $form['widget']['widget_settings']['slider'][$this->id]['precision'] = array(
      '#type' => 'textfield',
      '#title' => t('Precision'),
      '#size' => 5,
      '#default_value' => $this->settings->settings['precision'],
      '#description' => t('Rounding of the slider value (number of decimals)'),
      '#element_validate' => array('element_validate_number'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );

    $form['widget']['widget_settings']['slider'][$this->id]['step'] = array(
      '#type' => 'textfield',
      '#title' => t('Step'),
      '#size' => 5,
      '#default_value' => $this->settings->settings['step'],
      '#description' => t('Size of the slider steps'),
      '#element_validate' => array('element_validate_number'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),

    );
  }

  /**
   * Returns defaults for the settings this widget provides.
   */
  function getDefaultSettings() {
    return array(
      'prefix' => '',
      'suffix' => '',
      'precision' => '0',
      'step' => '1',
    );
  }

}
