<?php
/**
 * @file
 * users_permissions.features.inc
 */

/**
 * Implements hook_password_policy_features_default_policies().
 */
function users_permissions_password_policy_features_default_policies() {
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
