<?php

/**
 * @file
 * new_mobile_changes.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function new_mobile_changes_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_agency-wide-mobile-reports:website/mobile/reports.
  $menu_links['main-menu_agency-wide-mobile-reports:website/mobile/reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'website/mobile/reports',
    'router_path' => 'website/mobile/reports',
    'link_title' => 'Agency-Wide Mobile Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'Agency-Wide Mobile Reports',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_agency-wide-mobile-reports:website/mobile/reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_agency-wide-reports:agency/all/data',
  );
  // Exported menu link: main-menu_government-wide-mobile-reports:mobile/report.
  $menu_links['main-menu_government-wide-mobile-reports:mobile/report'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'mobile/report',
    'router_path' => 'mobile/report',
    'link_title' => 'Government-Wide Mobile Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'Government-Wide Mobile Reports',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_government-wide-mobile-reports:mobile/report',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_government-wide-reports:overall/gov-wide-compliance',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Agency-Wide Mobile Reports');
  t('Government-Wide Mobile Reports');

  return $menu_links;
}
