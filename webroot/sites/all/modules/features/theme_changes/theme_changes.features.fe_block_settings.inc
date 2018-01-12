<?php
/**
 * @file
 * theme_changes.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function theme_changes_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-footer'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'footer',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'dotgov',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
