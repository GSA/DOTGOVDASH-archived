<?php

/**
 * @file
 * 21st_century_idea_act.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function 21st_century_idea_act_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function 21st_century_idea_act_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
