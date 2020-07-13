<?php

/**
 * @file
 * uswds_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uswds_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uswds_settings_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function uswds_settings_node_info() {
  $items = array(
    'uswds_scan' => array(
      'name' => t('USWDS Scan'),
      'base' => 'node_content',
      'description' => t('USWDS Scan'),
      'has_title' => '1',
      'title_label' => t('USWDS Scan Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
