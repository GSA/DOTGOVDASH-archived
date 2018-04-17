<?php
/**
 * @file
 * accessibility_new.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function accessibility_new_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function accessibility_new_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function accessibility_new_node_info() {
  $items = array(
    'accessibility_agency_scan_inform' => array(
      'name' => t('Accessibility Agency Scan Information'),
      'base' => 'node_content',
      'description' => t('Accessibility Agency Scan Information'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
