<?php

/**
 * @file
 * idea_act_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function idea_act_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function idea_act_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
