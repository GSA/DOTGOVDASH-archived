<?php
/**
 * @file
 * Contains the table style plugin.
 */

/**
 * Extends the Views table style plugin to allow for rows to be table headers
 */
class views_table_row_headers_plugin_style_table extends views_plugin_style_table {
  /**
   * Implement options_definition_alter
   *
   * Add the row_header option to the table plugin option set
   */
  function options_definition_alter(&$options) {
    $options['row_header'] = array(
      'default' => '',
      );
  }

  /**
   * Implement options_form
   *
   * Add a select form element to let users select which field should be the row header
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Use the field names array as the options for the select form element,
    // but add a "None" option at the beginning of the array
    $options[''] = t('None');
    $field_names = $this->display->handler->get_field_labels();
    foreach ($field_names as $key => $value) {
      $options[$key] = $value;
    }

    // Build the select form element
    $form['row_header'] = array(
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $this->options['row_header'],
      '#title' => t('Row header'),
      '#description' => t('The selected field will be marked up as a table header with a scope="row" attribute'),
    );
  }
}
