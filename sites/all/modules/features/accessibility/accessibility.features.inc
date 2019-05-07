<?php
/**
 * @file
 * accessibility.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function accessibility_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ctools_custom_content" && $api == "ctools_content") {
    return array("version" => "1");
  }
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function accessibility_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function accessibility_node_info() {
  $items = array(
    'accessibility_agency_scan_inform' => array(
      'name' => t('Accessibility Agency Scan Information'),
      'base' => 'node_content',
      'description' => t('Accessibility Agency Scan Information'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_password_policy_features_default_policies().
 */
function accessibility_password_policy_features_default_policies() {
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
      'created' => 0,
      'expiration' => 90,
      'warning' => '20,10,7,6,5,4,3,2,1',
      'weight' => 0,
      'roles' => array(
        0 => 'authenticated user',
        1 => 'administrator',
        2 => 'AGY-GSA-OGP-DIGITALDASHBOARD.AGENCYUSERS',
        3 => 'AGY-GSA-OGP-DIGITALDASHBOARD.ADMINISTRATOR',
        4 => 'AGY-GSA-OGP-DIGITALDASHBOARD.AGENCYADMIN',
        5 => 'AGY-GSA-OGP-DIGITALDASHBOARD.NORMALUSERS',
        6 => 'AGY-GSA-OGP-DIGITALDASHBOARD.SUPERADMINS',
      ),
    ),
  );
}
