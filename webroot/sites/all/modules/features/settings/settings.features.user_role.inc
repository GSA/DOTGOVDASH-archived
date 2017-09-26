<?php
/**
 * @file
 * settings.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function settings_user_default_roles() {
  $roles = array();

  // Exported role: Agency Admin User.
  $roles['Agency Admin User'] = array(
    'name' => 'Agency Admin User',
    'weight' => 4,
  );

  // Exported role: Agency User.
  $roles['Agency User'] = array(
    'name' => 'Agency User',
    'weight' => 3,
  );

  // Exported role: Super User.
  $roles['Super User'] = array(
    'name' => 'Super User',
    'weight' => 5,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: authenticated user.
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
    'weight' => 1,
  );

  return $roles;
}
