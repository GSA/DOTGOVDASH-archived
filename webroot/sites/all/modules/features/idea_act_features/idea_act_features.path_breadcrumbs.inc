<?php

/**
 * @file
 * idea_act_features.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function idea_act_features_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'ideaact_agency_wide_report';
  $path_breadcrumb->name = 'ideaact_agency-wide_report';
  $path_breadcrumb->path = 'ideaact/agency-wide/report';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '21st Century IDEA Act Report',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'ideaact/home/dashboard',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['ideaact_agency_wide_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'ideaact_agencywide_dashboard';
  $path_breadcrumb->name = 'ideaact_agencywide_dashboard';
  $path_breadcrumb->path = 'ideaact/agencywide/dashboard/%id';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '21st Century IDEA Act Report',
      1 => '21st Century IDEA Act Agency-Wide Reports',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'ideaact/home/dashboard',
      1 => 'ideaact/agency-wide/report',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'id' => array(
        'position' => 3,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['ideaact_agencywide_dashboard'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'ideaact_govwide_dashboard';
  $path_breadcrumb->name = 'ideaact_govwide_dashboard';
  $path_breadcrumb->path = 'ideaact/govwide/dashboard';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '21st Century IDEA Act Report',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'ideaact/home/dashboard',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['ideaact_govwide_dashboard'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'ideaact_govwide_report';
  $path_breadcrumb->name = 'ideaact_govwide_report';
  $path_breadcrumb->path = 'ideaact/govwide/report';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '21st Century IDEA Act Report',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'ideaact/home/dashboard',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['ideaact_govwide_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'ideaact_govwide_report_clone';
  $path_breadcrumb->name = 'ideaact_accessibility_report';
  $path_breadcrumb->path = 'ideaact/report/accessibility/websites';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '21st Century IDEA Act Report',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'ideaact/home/dashboard',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['ideaact_govwide_report_clone'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'ideaact_govwide_report_clone_clone';
  $path_breadcrumb->name = 'ideaact_accessibility_website_report';
  $path_breadcrumb->path = 'ideaact/report/accessibility/website/%nid';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '21st Century IDEA Act Report',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'ideaact/home/dashboard',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'nid' => array(
        'position' => 4,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['ideaact_govwide_report_clone_clone'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'ideaact_home_dashboard';
  $path_breadcrumb->name = 'ideaact_home_dashboard';
  $path_breadcrumb->path = 'ideaact/home/dashboard';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['ideaact_home_dashboard'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'ideaact_website_dashboard';
  $path_breadcrumb->name = 'ideaact_website_dashboard';
  $path_breadcrumb->path = 'ideaact/website/dashboard/%id';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '21st Century IDEA Act Report',
      1 => '21st Century IDEA Act Reports',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'ideaact/home/dashboard',
      1 => 'ideaact/govwide/report',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'id' => array(
        'position' => 3,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['ideaact_website_dashboard'] = $path_breadcrumb;

  return $export;
}
