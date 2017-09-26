<?php
/**
 * @file
 * settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr" && $api == "apachesolr_environments") {
    return array("version" => "1");
  }
  if ($module == "apachesolr_search" && $api == "apachesolr_search_defaults") {
    return array("version" => "3");
  }
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "ctools_custom_content" && $api == "ctools_content") {
    return array("version" => "1");
  }
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function settings_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_password_policy_features_default_policies().
 */
function settings_password_policy_features_default_policies() {
  return array(
    'GSA Policy' => array(
      'name' => 'GSA Policy',
      'description' => 'GSA Policy',
      'enabled' => 1,
      'constraints' => array(
        'character_types' => 3,
        'digit' => 1,
        'history' => 9,
        'length' => 8,
        'lowercase' => 1,
        'punctuation' => 1,
        'uppercase' => 1,
        'username' => 1,
      ),
      'created' => 1495410071,
      'expiration' => 90,
      'warning' => '20,10,7,6,5,4,3,2,1',
      'weight' => 0,
      'roles' => array(
        0 => 'authenticated user',
        1 => 'administrator',
        2 => 'Agency User',
        3 => 'Agency Admin User',
        4 => 'Super User',
      ),
    ),
  );
}

/**
 * Implements hook_themekey_features_rule_chain().
 */
function settings_themekey_features_rule_chain() {
if (!defined('THEMEKEY_PAGECACHE_UNSUPPORTED')) {
    define('THEMEKEY_PAGECACHE_UNSUPPORTED', 0);
    define('THEMEKEY_PAGECACHE_SUPPORTED', 1);
    define('THEMEKEY_PAGECACHE_TIMEBASED', 2);
  }
$rules = array(
  0 => array(
    'rule' => array(
      'property' => 'user:role',
      'operator' => '=',
      'value' => 'Super User',
      'theme' => 'dotgov',
      'enabled' => 1,
      'wildcards' => 'a:0:{}',
      'module' => 'settings',
    ),
    'string' => '"user:role = Super User >>> dotgov"',
    'childs' => array(),
  ),
  1 => array(
    'rule' => array(
      'property' => 'user:role',
      'operator' => '=',
      'value' => 'Agency User',
      'theme' => 'dotgov',
      'enabled' => 1,
      'wildcards' => 'a:0:{}',
      'module' => 'settings',
    ),
    'string' => '"user:role = Agency User >>> dotgov"',
    'childs' => array(),
  ),
  2 => array(
    'rule' => array(
      'property' => 'user:role',
      'operator' => '=',
      'value' => 'Agency Admin User',
      'theme' => 'dotgov',
      'enabled' => 1,
      'wildcards' => 'a:0:{}',
      'module' => 'settings',
    ),
    'string' => '"user:role = Agency Admin User >>> dotgov"',
    'childs' => array(),
  ),
);

return $rules;
}
