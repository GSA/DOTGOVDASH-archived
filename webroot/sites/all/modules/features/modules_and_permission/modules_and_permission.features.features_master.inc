<?php
/**
 * @file
 * modules_and_permission.features.features_master.inc
 */

/**
 * Implements hook_features_master_defaults().
 */
function modules_and_permission_features_master_defaults() {
  $features_master = array();

  $features_master['modules'] = array(
    'admin_devel' => 'admin_devel',
    'admin_menu' => 'admin_menu',
    'admin_menu_toolbar' => 'admin_menu_toolbar',
    'analytics_dashboard' => 'analytics_dashboard',
    'apachesolr' => 'apachesolr',
    'apachesolr_access' => 'apachesolr_access',
    'apachesolr_autocomplete' => 'apachesolr_autocomplete',
    'apachesolr_search' => 'apachesolr_search',
    'apachesolrsearch' => 'apachesolrsearch',
    'autologout' => 'autologout',
    'better_exposed_filters' => 'better_exposed_filters',
    'block' => 'block',
    'bulk_export' => 'bulk_export',
    'captcha' => 'captcha',
    'charts' => 'charts',
    'charts_google' => 'charts_google',
    'charts_highcharts' => 'charts_highcharts',
    'color' => 'color',
    'comment' => 'comment',
    'context' => 'context',
    'context_layouts' => 'context_layouts',
    'context_ui' => 'context_ui',
    'contexts' => 'contexts',
    'contextual' => 'contextual',
    'ctools' => 'ctools',
    'ctools_custom_content' => 'ctools_custom_content',
    'current_search' => 'current_search',
    'dashboard' => 'dashboard',
    'datatables' => 'datatables',
    'date' => 'date',
    'date_all_day' => 'date_all_day',
    'date_api' => 'date_api',
    'date_context' => 'date_context',
    'date_facets' => 'date_facets',
    'date_popup' => 'date_popup',
    'date_repeat' => 'date_repeat',
    'date_repeat_field' => 'date_repeat_field',
    'date_tools' => 'date_tools',
    'date_views' => 'date_views',
    'dblog' => 'dblog',
    'delete_all' => 'delete_all',
    'devel' => 'devel',
    'diff' => 'diff',
    'dotgov_content_types' => 'dotgov_content_types',
    'empty_page' => 'empty_page',
    'entity' => 'entity',
    'facetapi' => 'facetapi',
    'facetapi_bonus' => 'facetapi_bonus',
    'facetapi_collapsible' => 'facetapi_collapsible',
    'facetapi_pretty_paths' => 'facetapi_pretty_paths',
    'facetapi_select' => 'facetapi_select',
    'facetapi_slider' => 'facetapi_slider',
    'fe_block' => 'fe_block',
    'fe_profile' => 'fe_profile',
    'features' => 'features',
    'features_master' => 'features_master',
    'field' => 'field',
    'field_sql_storage' => 'field_sql_storage',
    'field_ui' => 'field_ui',
    'file' => 'file',
    'filter' => 'filter',
    'google_chart_tools' => 'google_chart_tools',
    'google_chart_tools_example' => 'google_chart_tools_example',
    'google_chart_tools_views' => 'google_chart_tools_views',
    'help' => 'help',
    'image' => 'image',
    'image_captcha' => 'image_captcha',
    'job_scheduler' => 'job_scheduler',
    'job_scheduler_trigger' => 'job_scheduler_trigger',
    'jquery_update' => 'jquery_update',
    'libraries' => 'libraries',
    'list' => 'list',
    'menu' => 'menu',
    'menus' => 'menus',
    'modules_and_permission' => 'modules_and_permission',
    'node' => 'node',
    'node_reference' => 'node_reference',
    'number' => 'number',
    'options' => 'options',
    'overlay' => 'overlay',
    'page_manager' => 'page_manager',
    'panelizer' => 'panelizer',
    'panels' => 'panels',
    'panels_extra_layouts' => 'panels_extra_layouts',
    'panels_ipe' => 'panels_ipe',
    'panels_mini' => 'panels_mini',
    'panels_node' => 'panels_node',
    'password_policy' => 'password_policy',
    'path' => 'path',
    'pathauto' => 'pathauto',
    'profile' => 'profile',
    'rdf' => 'rdf',
    'recaptcha' => 'recaptcha',
    'references' => 'references',
    'search' => 'search',
    'serial' => 'serial',
    'settings_all' => 'settings_all',
    'shortcut' => 'shortcut',
    'standard' => 'standard',
    'system' => 'system',
    'taxonomy' => 'taxonomy',
    'text' => 'text',
    'tfa' => 'tfa',
    'token' => 'token',
    'update' => 'update',
    'user' => 'user',
    'user_reference' => 'user_reference',
    'users_permissions' => 'users_permissions',
    'views' => 'views',
    'views_all' => 'views_all',
    'views_bootstrap' => 'views_bootstrap',
    'views_content' => 'views_content',
    'views_php' => 'views_php',
    'views_revisions' => 'views_revisions',
    'views_ui' => 'views_ui',
    'views_url_path_arguments' => 'views_url_path_arguments',
  );
  $features_master['permissions'] = array(
    'access administration menu' => array(
      'name' => 'access administration menu',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access administration pages' => array(
      'name' => 'access administration pages',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access all views' => array(
      'name' => 'access all views',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access backup and migrate' => array(
      'name' => 'access backup and migrate',
      'roles' => array(),
    ),
    'access backup files' => array(
      'name' => 'access backup files',
      'roles' => array(),
    ),
    'access comments' => array(
      'name' => 'access comments',
      'roles' => array(
        'administrator' => 'administrator',
        'anonymous user' => 'anonymous user',
        'authenticated user' => 'authenticated user',
      ),
    ),
    'access content' => array(
      'name' => 'access content',
      'roles' => array(
        'administrator' => 'administrator',
        'anonymous user' => 'anonymous user',
        'authenticated user' => 'authenticated user',
      ),
    ),
    'access content overview' => array(
      'name' => 'access content overview',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access contextual links' => array(
      'name' => 'access contextual links',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access dashboard' => array(
      'name' => 'access dashboard',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access devel information' => array(
      'name' => 'access devel information',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access example charts' => array(
      'name' => 'access example charts',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access overlay' => array(
      'name' => 'access overlay',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access site in maintenance mode' => array(
      'name' => 'access site in maintenance mode',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access site reports' => array(
      'name' => 'access site reports',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access toolbar' => array(
      'name' => 'access toolbar',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'access user profiles' => array(
      'name' => 'access user profiles',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'admin tfa settings' => array(
      'name' => 'admin tfa settings',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer CAPTCHA settings' => array(
      'name' => 'administer CAPTCHA settings',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer actions' => array(
      'name' => 'administer actions',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer advanced pane settings' => array(
      'name' => 'administer advanced pane settings',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer analytics dashboard' => array(
      'name' => 'administer analytics dashboard',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer autologout' => array(
      'name' => 'administer autologout',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer backup and migrate' => array(
      'name' => 'administer backup and migrate',
      'roles' => array(),
    ),
    'administer block classes' => array(
      'name' => 'administer block classes',
      'roles' => array(),
    ),
    'administer blocks' => array(
      'name' => 'administer blocks',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer charts' => array(
      'name' => 'administer charts',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer comments' => array(
      'name' => 'administer comments',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer content types' => array(
      'name' => 'administer content types',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer contexts' => array(
      'name' => 'administer contexts',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer custom content' => array(
      'name' => 'administer custom content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer date tools' => array(
      'name' => 'administer date tools',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer empty page callbacks' => array(
      'name' => 'administer empty page callbacks',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer facetapi pretty paths' => array(
      'name' => 'administer facetapi pretty paths',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer facets' => array(
      'name' => 'administer facets',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer features' => array(
      'name' => 'administer features',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer fields' => array(
      'name' => 'administer fields',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer filters' => array(
      'name' => 'administer filters',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer image styles' => array(
      'name' => 'administer image styles',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer menu' => array(
      'name' => 'administer menu',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer mini panels' => array(
      'name' => 'administer mini panels',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer modules' => array(
      'name' => 'administer modules',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer nodes' => array(
      'name' => 'administer nodes',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer page manager' => array(
      'name' => 'administer page manager',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer pane access' => array(
      'name' => 'administer pane access',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer panel-nodes' => array(
      'name' => 'administer panel-nodes',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer panelizer' => array(
      'name' => 'administer panelizer',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer panels display styles' => array(
      'name' => 'administer panels display styles',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer panels layouts' => array(
      'name' => 'administer panels layouts',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer panels pane styles' => array(
      'name' => 'administer panels pane styles',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer panels region styles' => array(
      'name' => 'administer panels region styles',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer panels styles' => array(
      'name' => 'administer panels styles',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer password policies' => array(
      'name' => 'administer password policies',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer pathauto' => array(
      'name' => 'administer pathauto',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer permissions' => array(
      'name' => 'administer permissions',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer recaptcha' => array(
      'name' => 'administer recaptcha',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer search' => array(
      'name' => 'administer search',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer shortcuts' => array(
      'name' => 'administer shortcuts',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer site configuration' => array(
      'name' => 'administer site configuration',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer software updates' => array(
      'name' => 'administer software updates',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer taxonomy' => array(
      'name' => 'administer taxonomy',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer themes' => array(
      'name' => 'administer themes',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer url aliases' => array(
      'name' => 'administer url aliases',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer users' => array(
      'name' => 'administer users',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'administer uuid' => array(
      'name' => 'administer uuid',
      'roles' => array(),
    ),
    'administer views' => array(
      'name' => 'administer views',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'block IP addresses' => array(
      'name' => 'block IP addresses',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'bypass access in place editing' => array(
      'name' => 'bypass access in place editing',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'bypass node access' => array(
      'name' => 'bypass node access',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'cancel account' => array(
      'name' => 'cancel account',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'change layouts in place editing' => array(
      'name' => 'change layouts in place editing',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'change own logout threshold' => array(
      'name' => 'change own logout threshold',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'change own username' => array(
      'name' => 'change own username',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'context ajax block access' => array(
      'name' => 'context ajax block access',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'create 508_scan_information content' => array(
      'name' => 'create 508_scan_information content',
      'roles' => array(),
    ),
    'create agency content' => array(
      'name' => 'create agency content',
      'roles' => array(),
    ),
    'create article content' => array(
      'name' => 'create article content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'create broken_link_scan content' => array(
      'name' => 'create broken_link_scan content',
      'roles' => array(),
    ),
    'create cookie_law_scan content' => array(
      'name' => 'create cookie_law_scan content',
      'roles' => array(),
    ),
    'create dnssec_ipv6_information content' => array(
      'name' => 'create dnssec_ipv6_information content',
      'roles' => array(),
    ),
    'create domain_scan_information content' => array(
      'name' => 'create domain_scan_information content',
      'roles' => array(),
    ),
    'create https_dap_scan_information content' => array(
      'name' => 'create https_dap_scan_information content',
      'roles' => array(),
    ),
    'create mini panels' => array(
      'name' => 'create mini panels',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'create mobile_scan_information content' => array(
      'name' => 'create mobile_scan_information content',
      'roles' => array(),
    ),
    'create page content' => array(
      'name' => 'create page content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'create panel content' => array(
      'name' => 'create panel content',
      'roles' => array(),
    ),
    'create scans content' => array(
      'name' => 'create scans content',
      'roles' => array(),
    ),
    'create seo_scan_information content' => array(
      'name' => 'create seo_scan_information content',
      'roles' => array(),
    ),
    'create site_speed_scan content' => array(
      'name' => 'create site_speed_scan content',
      'roles' => array(),
    ),
    'create url aliases' => array(
      'name' => 'create url aliases',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'create website content' => array(
      'name' => 'create website content',
      'roles' => array(),
    ),
    'create website_scan_info content' => array(
      'name' => 'create website_scan_info content',
      'roles' => array(),
    ),
    'customize shortcut links' => array(
      'name' => 'customize shortcut links',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'delete any 508_scan_information content' => array(
      'name' => 'delete any 508_scan_information content',
      'roles' => array(),
    ),
    'delete any agency content' => array(
      'name' => 'delete any agency content',
      'roles' => array(),
    ),
    'delete any article content' => array(
      'name' => 'delete any article content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'delete any broken_link_scan content' => array(
      'name' => 'delete any broken_link_scan content',
      'roles' => array(),
    ),
    'delete any cookie_law_scan content' => array(
      'name' => 'delete any cookie_law_scan content',
      'roles' => array(),
    ),
    'delete any dnssec_ipv6_information content' => array(
      'name' => 'delete any dnssec_ipv6_information content',
      'roles' => array(),
    ),
    'delete any domain_scan_information content' => array(
      'name' => 'delete any domain_scan_information content',
      'roles' => array(),
    ),
    'delete any https_dap_scan_information content' => array(
      'name' => 'delete any https_dap_scan_information content',
      'roles' => array(),
    ),
    'delete any mobile_scan_information content' => array(
      'name' => 'delete any mobile_scan_information content',
      'roles' => array(),
    ),
    'delete any page content' => array(
      'name' => 'delete any page content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'delete any panel content' => array(
      'name' => 'delete any panel content',
      'roles' => array(),
    ),
    'delete any scans content' => array(
      'name' => 'delete any scans content',
      'roles' => array(),
    ),
    'delete any seo_scan_information content' => array(
      'name' => 'delete any seo_scan_information content',
      'roles' => array(),
    ),
    'delete any site_speed_scan content' => array(
      'name' => 'delete any site_speed_scan content',
      'roles' => array(),
    ),
    'delete any website content' => array(
      'name' => 'delete any website content',
      'roles' => array(),
    ),
    'delete any website_scan_info content' => array(
      'name' => 'delete any website_scan_info content',
      'roles' => array(),
    ),
    'delete backup files' => array(
      'name' => 'delete backup files',
      'roles' => array(),
    ),
    'delete own 508_scan_information content' => array(
      'name' => 'delete own 508_scan_information content',
      'roles' => array(),
    ),
    'delete own agency content' => array(
      'name' => 'delete own agency content',
      'roles' => array(),
    ),
    'delete own article content' => array(
      'name' => 'delete own article content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'delete own broken_link_scan content' => array(
      'name' => 'delete own broken_link_scan content',
      'roles' => array(),
    ),
    'delete own cookie_law_scan content' => array(
      'name' => 'delete own cookie_law_scan content',
      'roles' => array(),
    ),
    'delete own dnssec_ipv6_information content' => array(
      'name' => 'delete own dnssec_ipv6_information content',
      'roles' => array(),
    ),
    'delete own domain_scan_information content' => array(
      'name' => 'delete own domain_scan_information content',
      'roles' => array(),
    ),
    'delete own https_dap_scan_information content' => array(
      'name' => 'delete own https_dap_scan_information content',
      'roles' => array(),
    ),
    'delete own mobile_scan_information content' => array(
      'name' => 'delete own mobile_scan_information content',
      'roles' => array(),
    ),
    'delete own page content' => array(
      'name' => 'delete own page content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'delete own panel content' => array(
      'name' => 'delete own panel content',
      'roles' => array(),
    ),
    'delete own scans content' => array(
      'name' => 'delete own scans content',
      'roles' => array(),
    ),
    'delete own seo_scan_information content' => array(
      'name' => 'delete own seo_scan_information content',
      'roles' => array(),
    ),
    'delete own site_speed_scan content' => array(
      'name' => 'delete own site_speed_scan content',
      'roles' => array(),
    ),
    'delete own website content' => array(
      'name' => 'delete own website content',
      'roles' => array(),
    ),
    'delete own website_scan_info content' => array(
      'name' => 'delete own website_scan_info content',
      'roles' => array(),
    ),
    'delete revisions' => array(
      'name' => 'delete revisions',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'delete terms in 1' => array(
      'name' => 'delete terms in 1',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'delete terms in 2' => array(
      'name' => 'delete terms in 2',
      'roles' => array(),
    ),
    'delete terms in 3' => array(
      'name' => 'delete terms in 3',
      'roles' => array(),
    ),
    'diff view changes' => array(
      'name' => 'diff view changes',
      'roles' => array(
        'administrator' => 'administrator',
        'anonymous user' => 'anonymous user',
        'authenticated user' => 'authenticated user',
      ),
    ),
    'display drupal links' => array(
      'name' => 'display drupal links',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'edit any 508_scan_information content' => array(
      'name' => 'edit any 508_scan_information content',
      'roles' => array(),
    ),
    'edit any agency content' => array(
      'name' => 'edit any agency content',
      'roles' => array(),
    ),
    'edit any article content' => array(
      'name' => 'edit any article content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'edit any broken_link_scan content' => array(
      'name' => 'edit any broken_link_scan content',
      'roles' => array(),
    ),
    'edit any cookie_law_scan content' => array(
      'name' => 'edit any cookie_law_scan content',
      'roles' => array(),
    ),
    'edit any dnssec_ipv6_information content' => array(
      'name' => 'edit any dnssec_ipv6_information content',
      'roles' => array(),
    ),
    'edit any domain_scan_information content' => array(
      'name' => 'edit any domain_scan_information content',
      'roles' => array(),
    ),
    'edit any https_dap_scan_information content' => array(
      'name' => 'edit any https_dap_scan_information content',
      'roles' => array(),
    ),
    'edit any mobile_scan_information content' => array(
      'name' => 'edit any mobile_scan_information content',
      'roles' => array(),
    ),
    'edit any page content' => array(
      'name' => 'edit any page content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'edit any panel content' => array(
      'name' => 'edit any panel content',
      'roles' => array(),
    ),
    'edit any scans content' => array(
      'name' => 'edit any scans content',
      'roles' => array(),
    ),
    'edit any seo_scan_information content' => array(
      'name' => 'edit any seo_scan_information content',
      'roles' => array(),
    ),
    'edit any site_speed_scan content' => array(
      'name' => 'edit any site_speed_scan content',
      'roles' => array(),
    ),
    'edit any website content' => array(
      'name' => 'edit any website content',
      'roles' => array(),
    ),
    'edit any website_scan_info content' => array(
      'name' => 'edit any website_scan_info content',
      'roles' => array(),
    ),
    'edit own 508_scan_information content' => array(
      'name' => 'edit own 508_scan_information content',
      'roles' => array(),
    ),
    'edit own agency content' => array(
      'name' => 'edit own agency content',
      'roles' => array(),
    ),
    'edit own article content' => array(
      'name' => 'edit own article content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'edit own broken_link_scan content' => array(
      'name' => 'edit own broken_link_scan content',
      'roles' => array(),
    ),
    'edit own comments' => array(
      'name' => 'edit own comments',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'edit own cookie_law_scan content' => array(
      'name' => 'edit own cookie_law_scan content',
      'roles' => array(),
    ),
    'edit own dnssec_ipv6_information content' => array(
      'name' => 'edit own dnssec_ipv6_information content',
      'roles' => array(),
    ),
    'edit own domain_scan_information content' => array(
      'name' => 'edit own domain_scan_information content',
      'roles' => array(),
    ),
    'edit own https_dap_scan_information content' => array(
      'name' => 'edit own https_dap_scan_information content',
      'roles' => array(),
    ),
    'edit own mobile_scan_information content' => array(
      'name' => 'edit own mobile_scan_information content',
      'roles' => array(),
    ),
    'edit own page content' => array(
      'name' => 'edit own page content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'edit own panel content' => array(
      'name' => 'edit own panel content',
      'roles' => array(),
    ),
    'edit own scans content' => array(
      'name' => 'edit own scans content',
      'roles' => array(),
    ),
    'edit own seo_scan_information content' => array(
      'name' => 'edit own seo_scan_information content',
      'roles' => array(),
    ),
    'edit own site_speed_scan content' => array(
      'name' => 'edit own site_speed_scan content',
      'roles' => array(),
    ),
    'edit own website content' => array(
      'name' => 'edit own website content',
      'roles' => array(),
    ),
    'edit own website_scan_info content' => array(
      'name' => 'edit own website_scan_info content',
      'roles' => array(),
    ),
    'edit terms in 1' => array(
      'name' => 'edit terms in 1',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'edit terms in 2' => array(
      'name' => 'edit terms in 2',
      'roles' => array(),
    ),
    'edit terms in 3' => array(
      'name' => 'edit terms in 3',
      'roles' => array(),
    ),
    'execute php code' => array(
      'name' => 'execute php code',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'flush caches' => array(
      'name' => 'flush caches',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'force password change' => array(
      'name' => 'force password change',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'generate features' => array(
      'name' => 'generate features',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'manage features' => array(
      'name' => 'manage features',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'notify of path changes' => array(
      'name' => 'notify of path changes',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'perform backup' => array(
      'name' => 'perform backup',
      'roles' => array(),
    ),
    'post comments' => array(
      'name' => 'post comments',
      'roles' => array(
        'administrator' => 'administrator',
        'authenticated user' => 'authenticated user',
      ),
    ),
    'rename features' => array(
      'name' => 'rename features',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'restore from backup' => array(
      'name' => 'restore from backup',
      'roles' => array(),
    ),
    'revert revisions' => array(
      'name' => 'revert revisions',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'search content' => array(
      'name' => 'search content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'select account cancellation method' => array(
      'name' => 'select account cancellation method',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'skip CAPTCHA' => array(
      'name' => 'skip CAPTCHA',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'skip comment approval' => array(
      'name' => 'skip comment approval',
      'roles' => array(
        'administrator' => 'administrator',
        'authenticated user' => 'authenticated user',
      ),
    ),
    'switch shortcut sets' => array(
      'name' => 'switch shortcut sets',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'switch users' => array(
      'name' => 'switch users',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'unblock expired accounts' => array(
      'name' => 'unblock expired accounts',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'use advanced search' => array(
      'name' => 'use advanced search',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'use bulk exporter' => array(
      'name' => 'use bulk exporter',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'use ctools import' => array(
      'name' => 'use ctools import',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'use ipe with page manager' => array(
      'name' => 'use ipe with page manager',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'use page manager' => array(
      'name' => 'use page manager',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'use panels caching features' => array(
      'name' => 'use panels caching features',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'use panels dashboard' => array(
      'name' => 'use panels dashboard',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'use panels in place editing' => array(
      'name' => 'use panels in place editing',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'use panels locks' => array(
      'name' => 'use panels locks',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'use text format filtered_html' => array(
      'name' => 'use text format filtered_html',
      'roles' => array(
        'administrator' => 'administrator',
        'anonymous user' => 'anonymous user',
        'authenticated user' => 'authenticated user',
      ),
    ),
    'use text format full_html' => array(
      'name' => 'use text format full_html',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'view analytics dashboard' => array(
      'name' => 'view analytics dashboard',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'view date repeats' => array(
      'name' => 'view date repeats',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'view own unpublished content' => array(
      'name' => 'view own unpublished content',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'view pane admin links' => array(
      'name' => 'view pane admin links',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'view revisions' => array(
      'name' => 'view revisions',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
    'view the administration theme' => array(
      'name' => 'view the administration theme',
      'roles' => array(
        'administrator' => 'administrator',
      ),
    ),
  );
  $features_master['themes'] = array(
    'bartik' => 'bartik',
    'bootstrap' => 'bootstrap',
    'dotgov' => 'dotgov',
    'seven' => 'seven',
  );

  return $features_master;
}
