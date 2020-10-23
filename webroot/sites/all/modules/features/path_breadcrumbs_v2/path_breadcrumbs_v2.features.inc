<?php

/**
 * @file
 * path_breadcrumbs_v2.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function path_breadcrumbs_v2_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
}
