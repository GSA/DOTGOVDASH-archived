<?php

/**
 * @file
 * new_mobile_changes.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function new_mobile_changes_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_https_report_clone';
  $path_breadcrumb->name = 'Government-Wide Mobile Performance Report';
  $path_breadcrumb->path = 'agency/all/mobile_data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => 'Top Performing Agencies',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => 'agency/all/reports-data',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['government_wide_https_report_clone'] = $path_breadcrumb;

  return $export;
}
