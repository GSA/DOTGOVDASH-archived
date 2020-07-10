<?php

/**
 * @file
 * uswds_settings.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function uswds_settings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_my-agency-uswds-code-usage-report:myagency/uswds/reports.
  $menu_links['main-menu_my-agency-uswds-code-usage-report:myagency/uswds/reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'myagency/uswds/reports',
    'router_path' => 'myagency/uswds/reports',
    'link_title' => 'My Agency USWDS Code Usage Report',
    'options' => array(
      'attributes' => array(
        'title' => 'My Agency USWDS Code Usage Report',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          3 => 3,
          12 => 12,
          13 => 13,
          14 => 14,
          16 => 16,
        ),
        'hide' => array(
          1 => 1,
          15 => 15,
        ),
      ),
      'identifier' => 'main-menu_my-agency-uswds-code-usage-report:myagency/uswds/reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_technology-usage:top_technology_usage',
  );
  // Exported menu link: main-menu_uswds-code-usage-report:website/all/uswds.
  $menu_links['main-menu_uswds-code-usage-report:website/all/uswds'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'website/all/uswds',
    'router_path' => 'website/all/uswds',
    'link_title' => 'USWDS Code Usage Report',
    'options' => array(
      'attributes' => array(
        'title' => 'USWDS Code Usage Report',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          3 => 3,
          13 => 13,
          16 => 16,
        ),
        'hide' => array(
          12 => 12,
          14 => 14,
        ),
      ),
      'identifier' => 'main-menu_uswds-code-usage-report:website/all/uswds',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_technology-usage:top_technology_usage',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('My Agency USWDS Code Usage Report');
  t('USWDS Code Usage Report');

  return $menu_links;
}
