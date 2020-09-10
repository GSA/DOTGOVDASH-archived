<?php

/**
 * @file
 * new_mobile_changes.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function new_mobile_changes_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer panelizer node mobile_scan_information defaults'.
  $permissions['administer panelizer node mobile_scan_information defaults'] = array(
    'name' => 'administer panelizer node mobile_scan_information defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'create mobile_scan_information content'.
  $permissions['create mobile_scan_information content'] = array(
    'name' => 'create mobile_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any mobile_scan_information content'.
  $permissions['delete any mobile_scan_information content'] = array(
    'name' => 'delete any mobile_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own mobile_scan_information content'.
  $permissions['delete own mobile_scan_information content'] = array(
    'name' => 'delete own mobile_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any mobile_scan_information content'.
  $permissions['edit any mobile_scan_information content'] = array(
    'name' => 'edit any mobile_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own mobile_scan_information content'.
  $permissions['edit own mobile_scan_information content'] = array(
    'name' => 'edit own mobile_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
