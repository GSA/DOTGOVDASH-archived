<?php
/**
 * @file
 * accessibility.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function accessibility_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['autologout-info'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'info',
    'module' => 'autologout',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['backup_migrate-quick_backup'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'quick_backup',
    'module' => 'backup_migrate',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['block-agency_logo'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'agency_logo',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'overall/compliance
overall/compliance?field_web_agency_id_nid=*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dotgov',
        'weight' => -42,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['block-disclaimer_text'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'disclaimer_text',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>
reports',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dotgov',
        'weight' => -47,
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

  $export['cas-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'cas',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['comment-recent'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'recent',
    'module' => 'comment',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dotgov',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['context_ui-devel'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'devel',
    'module' => 'context_ui',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['context_ui-editor'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'editor',
    'module' => 'context_ui',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['current_search-dotgov'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'dotgov',
    'module' => 'current_search',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['current_search-standard'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'standard',
    'module' => 'current_search',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['devel-execute_php'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'execute_php',
    'module' => 'devel',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['devel-switch_user'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'switch_user',
    'module' => 'devel',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['diff-inline'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'inline',
    'module' => 'diff',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['dotgov_common-technology_stack'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'technology_stack',
    'module' => 'dotgov_common',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-0BB0WVi1QTSWY5phPp0f1B1gbChnr10h'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '0BB0WVi1QTSWY5phPp0f1B1gbChnr10h',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Font Script Applications',
    'visibility' => 0,
  );

  $export['facetapi-0ll6V3NOJOkCwbeS7ERkuk5vAy6zkGhK'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '0ll6V3NOJOkCwbeS7ERkuk5vAy6zkGhK',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-0mmkJY0hSs1XLAsMpuNJcZqlcqpW01p1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '0mmkJY0hSs1XLAsMpuNJcZqlcqpW01p1',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-1FpmY1XKlLKGgbDsWjf4t7pQk10QPg0z'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '1FpmY1XKlLKGgbDsWjf4t7pQk10QPg0z',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Web Server',
    'visibility' => 0,
  );

  $export['facetapi-1HuV60oTwnapD5yUfRMhRxt9ukJUZSCO'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '1HuV60oTwnapD5yUfRMhRxt9ukJUZSCO',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-1lcJzRh5ELFYDQdcB9sFkQvS3iIK91wk'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '1lcJzRh5ELFYDQdcB9sFkQvS3iIK91wk',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-25cj194oE6mjM6UE1sdNjY1Ihvdrz7K2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '25cj194oE6mjM6UE1sdNjY1Ihvdrz7K2',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'LMS Applications',
    'visibility' => 0,
  );

  $export['facetapi-29AdVE0IWV1T1taUCqw6ise71uisHRAf'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '29AdVE0IWV1T1taUCqw6ise71uisHRAf',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-2f5KEUMRkH7g8VAaZV09PP5Xard1AC1N'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '2f5KEUMRkH7g8VAaZV09PP5Xard1AC1N',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Ecommerce Applications',
    'visibility' => 0,
  );

  $export['facetapi-2lBM9irQyzh5tzBX2wq0RCxEO4EVihBf'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '2lBM9irQyzh5tzBX2wq0RCxEO4EVihBf',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Tag Managers',
    'visibility' => 0,
  );

  $export['facetapi-5nMaj2QHyFkNcch7WP05i2XrU05iBD0m'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '5nMaj2QHyFkNcch7WP05i2XrU05iBD0m',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-75GBNlcwLUoprelPjupbZ7Hs0nCrXXcW'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '75GBNlcwLUoprelPjupbZ7Hs0nCrXXcW',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'CMS Applications',
    'visibility' => 0,
  );

  $export['facetapi-9P1OXty7xdX0e1aWPkFXsxB0KZT05Wqh'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '9P1OXty7xdX0e1aWPkFXsxB0KZT05Wqh',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Marketing Automation',
    'visibility' => 0,
  );

  $export['facetapi-BUZYqpXQQ1RhOz0elA7NoIsC0a7GO9zv'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'BUZYqpXQQ1RhOz0elA7NoIsC0a7GO9zv',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-DY0JcJHsQLWrMqdvFtH8TAN1To91PSnG'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'DY0JcJHsQLWrMqdvFtH8TAN1To91PSnG',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-F12rZrdILhsKm2xwxtYoztEQiGIC7ovk'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'F12rZrdILhsKm2xwxtYoztEQiGIC7ovk',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Widget Applications',
    'visibility' => 0,
  );

  $export['facetapi-F1YLnHEkz5dibDJ5FQAtlqFLJyt7afPX'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'F1YLnHEkz5dibDJ5FQAtlqFLJyt7afPX',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-GW0FDePwlD16eoCETv5RGLOCYp7h9NIr'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'GW0FDePwlD16eoCETv5RGLOCYp7h9NIr',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Databases',
    'visibility' => 0,
  );

  $export['facetapi-GiPncE24sZPo5FQ6qyQgfKkg6JFY8mr6'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'GiPncE24sZPo5FQ6qyQgfKkg6JFY8mr6',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Build CI Systems',
    'visibility' => 0,
  );

  $export['facetapi-HElHllnoCDr80rCZEooDrqtgmVl1WskU'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'HElHllnoCDr80rCZEooDrqtgmVl1WskU',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Analytics Applications',
    'visibility' => 0,
  );

  $export['facetapi-JdhXlkP4rAS8LCZsmnODj7gG04uee53H'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'JdhXlkP4rAS8LCZsmnODj7gG04uee53H',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-LodmcvgmCjm7EJJ6PyTsVaIffjgYBL7g'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'LodmcvgmCjm7EJJ6PyTsVaIffjgYBL7g',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Captcha Applications',
    'visibility' => 0,
  );

  $export['facetapi-QpaPRpIcOFIeAPf0rcXNsxro7HLl0a8A'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'QpaPRpIcOFIeAPf0rcXNsxro7HLl0a8A',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-UVAt7FJR02ZsJ01fV88QugLUVdzB2iwA'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'UVAt7FJR02ZsJ01fV88QugLUVdzB2iwA',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Video Players',
    'visibility' => 0,
  );

  $export['facetapi-V5VY4NoBmsg3vfANfnUCtpUuyRX3Y9zp'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'V5VY4NoBmsg3vfANfnUCtpUuyRX3Y9zp',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Mobile Frameworks',
    'visibility' => 0,
  );

  $export['facetapi-X8a1kbtYWy1xJhbAF6qN0blUSax7XfOm'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'X8a1kbtYWy1xJhbAF6qN0blUSax7XfOm',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-ZZ5ecHjXlDx19RszAOsVsP7cTsbu8GEW'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ZZ5ecHjXlDx19RszAOsVsP7cTsbu8GEW',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-Zk2E7ARHMLPxIPZuddgTNUBh7l01jR7u'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'Zk2E7ARHMLPxIPZuddgTNUBh7l01jR7u',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-ZlF1quwma7FzBwJXSOO2VEExcGCnWAvC'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ZlF1quwma7FzBwJXSOO2VEExcGCnWAvC',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Javascript Frameworks',
    'visibility' => 0,
  );

  $export['facetapi-aBzpmggam0xTiO0vPX8Rlu0dtWHWQKKy'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'aBzpmggam0xTiO0vPX8Rlu0dtWHWQKKy',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Cache Tools',
    'visibility' => 0,
  );

  $export['facetapi-aOQGmd0jxWs7ldW31WbAmFnDDw2NNSnl'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'aOQGmd0jxWs7ldW31WbAmFnDDw2NNSnl',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Web Server Extensions',
    'visibility' => 0,
  );

  $export['facetapi-bk0405OO60p6nQ17XVxOrSdKuDJaq0y5'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'bk0405OO60p6nQ17XVxOrSdKuDJaq0y5',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Website Tags',
    'visibility' => 0,
  );

  $export['facetapi-cR5A29Lb9DogdsnumZESdchW7gp8h5Jl'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'cR5A29Lb9DogdsnumZESdchW7gp8h5Jl',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-crUBTkgrzB2gabWRwpea0MIi8KvsqdlR'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'crUBTkgrzB2gabWRwpea0MIi8KvsqdlR',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Advertising Networks',
    'visibility' => 0,
  );

  $export['facetapi-dGqetQNLiPEHu2WVpMs4FbQkuqtS4GNx'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'dGqetQNLiPEHu2WVpMs4FbQkuqtS4GNx',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-eBn2gMxPLGFd6bd6X368KsK0wQLcBD5G'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'eBn2gMxPLGFd6bd6X368KsK0wQLcBD5G',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Issue Trackers',
    'visibility' => 0,
  );

  $export['facetapi-gQR044z7FOsi2xWcggDHIUOvYpWS4p0P'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'gQR044z7FOsi2xWcggDHIUOvYpWS4p0P',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Photo Galleries',
    'visibility' => 0,
  );

  $export['facetapi-iRGuc7rV3Mb7aksWSlGFezZdG3NqgtiF'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'iRGuc7rV3Mb7aksWSlGFezZdG3NqgtiF',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-im04lYh9mepwYB7GLPY0DE10yNOKw4p0'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'im04lYh9mepwYB7GLPY0DE10yNOKw4p0',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Miscellaneous Application',
    'visibility' => 0,
  );

  $export['facetapi-lfFvZQW1qtjlk6e19NwBOl5jlMxdjPXd'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'lfFvZQW1qtjlk6e19NwBOl5jlMxdjPXd',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-mzhFnMHHdi6wkverMbzpP2bDeh31oD3D'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'mzhFnMHHdi6wkverMbzpP2bDeh31oD3D',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-nD01203UOLmCEPDrBTinpwzcqBw2j15x'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'nD01203UOLmCEPDrBTinpwzcqBw2j15x',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-nVGxnv8kQdaFBggr5Ogd3fgz3ftjtQCM'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'nVGxnv8kQdaFBggr5Ogd3fgz3ftjtQCM',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Operating Systems',
    'visibility' => 0,
  );

  $export['facetapi-oRlwDqDrVXc2wTVBoEsQtiJ1Gh4ITiqt'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'oRlwDqDrVXc2wTVBoEsQtiJ1Gh4ITiqt',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-r0dqywabRcnO6tf9wk6alPUtKRRA1nH8'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'r0dqywabRcnO6tf9wk6alPUtKRRA1nH8',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-rFOkYnHpSFLGeJYHUQdGoP2mYL1vbx9g'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'rFOkYnHpSFLGeJYHUQdGoP2mYL1vbx9g',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Programming Languages',
    'visibility' => 0,
  );

  $export['facetapi-tU0n3Dk2BIg1jdXb39uJ6fsjj0syEyqd'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'tU0n3Dk2BIg1jdXb39uJ6fsjj0syEyqd',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-v8CVSJdPtq988H67x3fPAeYe5L1n6iyf'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'v8CVSJdPtq988H67x3fPAeYe5L1n6iyf',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Web Frameworks',
    'visibility' => 0,
  );

  $export['facetapi-vxFxdg4pvr60fqe0P1GeFgGoNpHF0yKb'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'vxFxdg4pvr60fqe0P1GeFgGoNpHF0yKb',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-xPCqHIqG05Th8En9d0u0DTfWUVIwpCSr'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'xPCqHIqG05Th8En9d0u0DTfWUVIwpCSr',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Editor Applications',
    'visibility' => 0,
  );

  $export['facetapi-xmOisbopt7sEA41aousfrsujBgQ0lLSZ'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'xmOisbopt7sEA41aousfrsujBgQ0lLSZ',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Hosting Panels',
    'visibility' => 0,
  );

  $export['facetapi-y054hLlBC6kqutDj1wUZznZalZ9kEUxa'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'y054hLlBC6kqutDj1wUZznZalZ9kEUxa',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'Maps Applications',
    'visibility' => 0,
  );

  $export['facetapi-y5Kxc70Lb6FwHeh8MnddkuRcwZo10Lbx'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'y5Kxc70Lb6FwHeh8MnddkuRcwZo10Lbx',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'CDN applications',
    'visibility' => 0,
  );

  $export['facetapi-yWQkVPcUHOZQgROk0gHFbYYhCdAgd60h'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'yWQkVPcUHOZQgROk0gHFbYYhCdAgd60h',
    'module' => 'facetapi',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['favorites-0'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 0,
    'module' => 'favorites',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
    'title' => 'My Reports',
    'visibility' => 0,
  );

  $export['menu-devel'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'devel',
    'module' => 'menu',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['menu-features'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'features',
    'module' => 'menu',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['node-recent'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'recent',
    'module' => 'node',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dotgov',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'dashboard_main',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['node-syndicate'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'syndicate',
    'module' => 'node',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['profile-author-information'] = array(
    'cache' => 5,
    'custom' => 0,
    'delta' => 'author-information',
    'module' => 'profile',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -1,
      ),
      'dotgov' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'dotgov',
        'weight' => -47,
      ),
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['shortcut-shortcuts'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'shortcuts',
    'module' => 'shortcut',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['system-help'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'help',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'dotgov',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'dotgov',
        'weight' => -46,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['system-management'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'management',
    'module' => 'system',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['system-powered-by'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'powered-by',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 10,
      ),
      'dotgov' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dotgov',
        'weight' => 10,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dotgov',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-new'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'new',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dotgov',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-online'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'online',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dotgov',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-53f8f85e6144df4fc36a2a34f568d02e'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '53f8f85e6144df4fc36a2a34f568d02e',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-accessibility_report-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'accessibility_report-block_1',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-accessibility_report-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'accessibility_report-block_2',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-accessibility_report-block_3'] = array(
    'cache' => -1,
    'delta' => 'accessibility_report-block_3',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
  );

  $export['views-accessibility_report-block_4'] = array(
    'cache' => -1,
    'delta' => 'accessibility_report-block_4',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
  );

  $export['views-agency_logo-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'agency_logo-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'overall/compliance
overall/compliance?field_web_agency_id_nid=*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'dotgov',
        'weight' => -41,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-agency_page-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'agency_page-block_1',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-agency_page-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'agency_page-block_2',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_1',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_10'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_10',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_11'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_11',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_12'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_12',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_13'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_13',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_14'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_14',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_15'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_15',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_16'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_16',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_2',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_3',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_4'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_4',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dotgov',
        'weight' => -36,
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

  $export['views-all_agency_data-block_5'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_5',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_6'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_6',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_7'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_7',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_8'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_8',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-all_agency_data-block_9'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'all_agency_data-block_9',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-homepage-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'homepage-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'dotgov' => array(
        'region' => 'highlighted',
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

  $export['views-web_servers-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'web_servers-block',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-web_servers-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'web_servers-block_1',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-web_servers-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'web_servers-block_2',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-web_servers-block_3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'web_servers-block_3',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-web_servers-block_4'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'web_servers-block_4',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-web_servers-block_5'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'web_servers-block_5',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-web_servers-block_6'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'web_servers-block_6',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-web_servers-block_7'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'web_servers-block_7',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-website_information-block_6'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'website_information-block_6',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-website_information-block_7'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'website_information-block_7',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-website_information-block_8'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'website_information-block_8',
    'module' => 'views',
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
      'dotgov' => array(
        'region' => '',
        'status' => 0,
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
