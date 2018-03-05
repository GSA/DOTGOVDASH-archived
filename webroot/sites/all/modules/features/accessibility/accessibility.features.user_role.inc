<?php
/**
 * @file
 * accessibility.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function accessibility_user_default_roles() {
  $roles = array();

  // Exported role: AGY-GSA-OGP-DIGITALDASHBOARD.ADMINISTRATOR.
  $roles['AGY-GSA-OGP-DIGITALDASHBOARD.ADMINISTRATOR'] = array(
    'name' => 'AGY-GSA-OGP-DIGITALDASHBOARD.ADMINISTRATOR',
    'weight' => 12,
  );

  // Exported role: AGY-GSA-OGP-DIGITALDASHBOARD.AGENCYADMIN.
  $roles['AGY-GSA-OGP-DIGITALDASHBOARD.AGENCYADMIN'] = array(
    'name' => 'AGY-GSA-OGP-DIGITALDASHBOARD.AGENCYADMIN',
    'weight' => 13,
  );

  // Exported role: AGY-GSA-OGP-DIGITALDASHBOARD.AGENCYUSERS.
  $roles['AGY-GSA-OGP-DIGITALDASHBOARD.AGENCYUSERS'] = array(
    'name' => 'AGY-GSA-OGP-DIGITALDASHBOARD.AGENCYUSERS',
    'weight' => 11,
  );

  // Exported role: AGY-GSA-OGP-DIGITALDASHBOARD.NORMALUSERS.
  $roles['AGY-GSA-OGP-DIGITALDASHBOARD.NORMALUSERS'] = array(
    'name' => 'AGY-GSA-OGP-DIGITALDASHBOARD.NORMALUSERS',
    'weight' => 14,
  );

  // Exported role: AGY-GSA-OGP-DIGITALDASHBOARD.SUPERADMINS.
  $roles['AGY-GSA-OGP-DIGITALDASHBOARD.SUPERADMINS'] = array(
    'name' => 'AGY-GSA-OGP-DIGITALDASHBOARD.SUPERADMINS',
    'weight' => 15,
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
