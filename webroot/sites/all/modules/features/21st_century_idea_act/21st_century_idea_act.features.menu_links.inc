<?php

/**
 * @file
 * 21st_century_idea_act.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function 21st_century_idea_act_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_21st-century-idea-act-agency-wide-report:ideaact/agency-wide/report.
  $menu_links['main-menu_21st-century-idea-act-agency-wide-report:ideaact/agency-wide/report'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ideaact/agency-wide/report',
    'router_path' => 'ideaact/agency-wide/report',
    'link_title' => '21st Century IDEA Act Agency Wide Report',
    'options' => array(
      'attributes' => array(
        'title' => '21st Century IDEA Act Agency Wide Report',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
          2 => 2,
        ),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_21st-century-idea-act-agency-wide-report:ideaact/agency-wide/report',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_21st-century-idea-act-report:ideaact/home/dashboard',
  );
  // Exported menu link: main-menu_21st-century-idea-act-government-wide-websites-report:ideaact/govwide/report.
  $menu_links['main-menu_21st-century-idea-act-government-wide-websites-report:ideaact/govwide/report'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ideaact/govwide/report',
    'router_path' => 'ideaact/govwide/report',
    'link_title' => '21st Century IDEA Act Government Wide Websites Report',
    'options' => array(
      'attributes' => array(
        'title' => '21st Century IDEA Act Government Wide Websites Report',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
          2 => 2,
        ),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_21st-century-idea-act-government-wide-websites-report:ideaact/govwide/report',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_21st-century-idea-act-report:ideaact/home/dashboard',
  );
  // Exported menu link: main-menu_21st-century-idea-act-report:ideaact/home/dashboard.
  $menu_links['main-menu_21st-century-idea-act-report:ideaact/home/dashboard'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ideaact/home/dashboard',
    'router_path' => 'ideaact/home/dashboard',
    'link_title' => '21st Century IDEA Act Report',
    'options' => array(
      'attributes' => array(
        'title' => '21st Century IDEA Act Report Dashboard',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
          2 => 2,
        ),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_21st-century-idea-act-report:ideaact/home/dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -32,
    'customized' => 1,
  );
  // Exported menu link: navigation_21st-century-idea-act-government-dashboard:ideaact/govwide/dashboard.
  $menu_links['navigation_21st-century-idea-act-government-dashboard:ideaact/govwide/dashboard'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'ideaact/govwide/dashboard',
    'router_path' => 'ideaact/govwide/dashboard',
    'link_title' => '21st Century IDEA Act Government Dashboard',
    'options' => array(
      'identifier' => 'navigation_21st-century-idea-act-government-dashboard:ideaact/govwide/dashboard',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_21st-century-idea-act-home-page:ideaact/home/dashboard.
  $menu_links['navigation_21st-century-idea-act-home-page:ideaact/home/dashboard'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'ideaact/home/dashboard',
    'router_path' => 'ideaact/home/dashboard',
    'link_title' => '21st Century IDEA Act Home Page',
    'options' => array(
      'identifier' => 'navigation_21st-century-idea-act-home-page:ideaact/home/dashboard',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('21st Century IDEA Act Agency Wide Report');
  t('21st Century IDEA Act Government Dashboard');
  t('21st Century IDEA Act Government Wide Websites Report');
  t('21st Century IDEA Act Home Page');
  t('21st Century IDEA Act Report');

  return $menu_links;
}
