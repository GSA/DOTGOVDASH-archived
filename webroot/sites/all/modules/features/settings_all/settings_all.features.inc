<?php
/**
 * @file
 * settings_all.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function settings_all_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
}
