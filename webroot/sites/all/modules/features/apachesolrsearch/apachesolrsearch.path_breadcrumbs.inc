<?php

/**
 * @file
 * apachesolrsearch.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function apachesolrsearch_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_uswds_data';
  $path_breadcrumb->name = 'Government-Wide USWDS data';
  $path_breadcrumb->path = 'agency/all/uswds';
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
  $export['government_wide_uswds_data'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'uswds_report';
  $path_breadcrumb->name = 'uswds report';
  $path_breadcrumb->path = 'website/all/uswds';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Technology Usage',
      1 => 'USWDS Code Usage Report',
    ),
    'paths' => array(
      0 => 'top_technology_usage',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['uswds_report'] = $path_breadcrumb;

  return $export;
}
