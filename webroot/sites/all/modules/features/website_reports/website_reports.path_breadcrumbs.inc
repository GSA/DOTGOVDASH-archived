<?php

/**
 * @file
 * website_reports.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function website_reports_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'website_reports_clone';
  $path_breadcrumb->name = 'website-reports-new';
  $path_breadcrumb->path = 'website/all/reports-new';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Website-Specific Reports',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'website/all/reports-new',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['website_reports_clone'] = $path_breadcrumb;

  return $export;
}
