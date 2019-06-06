<?php
/**
 * @file
 * The primary PHP file for this theme.
 */
drupal_add_js('/sites/all/libraries/highcharts/highcharts.js');
drupal_add_js('/sites/all/libraries/highcharts/highcharts-more.js');
drupal_add_js('/sites/all/libraries/highcharts/solid-gauge.js');
drupal_add_js('/sites/all/themes/dotgov/js/loader.js');
drupal_add_css('//fonts.googleapis.com/css?family=Fira+Sans|Fjalla+One');
function dotgov_css_alter(&$css) {
  // Remove datatable css files.
unset($css[drupal_get_path('module', 'datatables') . '/dataTables/media/css/demo_table.css']);

}

function dotgov_menu_link__main_menu($variables)
{
  $element = $variables['element'];
  $sub_menu = '';
  
  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    } elseif ((!empty($element['#original_link']['depth'])) && $element['#original_link']['depth'] > 1) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      $element['#attributes']['class'][] = 'dropdown-submenu';
      $element['#localized_options']['html'] = TRUE;
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    } else {
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      $element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    }
  }
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements hook_preprocess_search_results().
 */
function dotgov_preprocess_search_results(&$vars) {
  // search.module shows 10 items per page (this isn't customizable)
  $itemsPerPage = 10;

  // Determine which page is being viewed
  // If $_REQUEST['page'] is not set, we are on page 1
  $currentPage = (isset($_REQUEST['page']) ? $_REQUEST['page'] : 0) + 1;

  // Get the total number of results from the global pager
  $total = $GLOBALS['pager_total_items'][0];

  // Determine which results are being shown ("Showing results x through y")
  $start = (10 * $currentPage) - 9;
  // If on the last page, only go up to $total, not the total that COULD be
  // shown on the page. This prevents things like "Displaying 11-20 of 17".
  $end = (($itemsPerPage * $currentPage) >= $total) ? $total : ($itemsPerPage * $currentPage);

  // If there is more than one page of results:
  if ($total > $itemsPerPage) {
    $vars['search_totals'] = t('Displaying !start - !end of !total records', array(
      '!start' => $start,
      '!end' => $end,
      '!total' => $total,
    ));
  }
  else {
    // Only one page of results, so make it simpler
    $vars['search_totals'] = t('Displaying !total !results_label', array(
      '!total' => $total,
      // Be smart about labels: show "result" for one, "results" for multiple
      '!results_label' => format_plural($total, 'result', 'results'),
    ));
  }
}
/*
 * HTML preprocess
 */
function dotgov_preprocess_html(&$variables) {
    if(arg(0) == "historical_scan_score_data") {
        drupal_add_js("https://code.jquery.com/jquery-2.2.4.js", "external");
    }
}

function dotgov_common_getMobileSnapshot($websiteid){
    $mobsnap = array();
    $query = db_query("SELECT c.* from field_data_field_mobile_websnapshot a, field_data_field_website_id b,file_managed c where b.field_website_id_nid=:nid and b.bundle='mobile_scan_information' and a.entity_id=b.entity_id and a.field_mobile_websnapshot_fid=c.fid", array(':nid' => $websiteid));
    foreach ($query as $result) {
        $mobsnap['uri'] = $result->uri;
        $mobsnap['fid'] = $result->fid;
    }
    return $mobsnap;
}


function dotgov_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {
    $output = '';
    
    if (arg(0) == 'search' && arg(1) == 'site') {
      $breadcrumb[1] = '<a href="/multistep-search">Data Discovery</a>';
    }
    elseif (arg(0) == 'historical_scan_score_data' && !empty(arg(1)) && is_mobile_scan(arg(1))) {
      $getTextBetweenTags = getTextBetweenTags($breadcrumb[1], 'a');
      $breadcrumb[1] = '<a href="/website/' . get_website_id_nid(arg(1)) . '/information">' . $getTextBetweenTags . '</a>';
    }
    elseif (arg(0) == 'website' && arg(1) == 'search' && arg(2) == 'reports') {
      $breadcrumb[1] = 'Website Search Reports';
    }
    elseif (arg(0) == 'accessibilityreportalldomains') {
      $breadcrumb[1] = 'Website Level Accessibility Report';
    }
    elseif (arg(0) == 'privacy-policy') {
      $breadcrumb[1] = 'Privacy Policy';
    }
    
    $output .= implode(' » ', $breadcrumb);
    return $output;
  }
}

/**
 * Helper function to extract values from html tags
 * @param $string
 * @param $tagname
 *
 * @return mixed
 */
function getTextBetweenTags($string, $tagname) {
  $pattern = "/<$tagname ?.*>(.*)<\/$tagname>/";
  preg_match($pattern, $string, $matches);
  return $matches[1];
}