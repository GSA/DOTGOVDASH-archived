<?php

/**
 * @file
 * website_reports.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function website_reports_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function website_reports_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
