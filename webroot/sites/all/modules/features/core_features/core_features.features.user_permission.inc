<?php
/**
 * @file
 * core_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function core_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access example charts'.
  $permissions['access example charts'] = array(
    'name' => 'access example charts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'charts',
  );

  // Exported permission: 'access overlay'.
  $permissions['access overlay'] = array(
    'name' => 'access overlay',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'overlay',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'admin tfa settings'.
  $permissions['admin tfa settings'] = array(
    'name' => 'admin tfa settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'tfa',
  );

  // Exported permission: 'administer CAPTCHA settings'.
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer analytics dashboard'.
  $permissions['administer analytics dashboard'] = array(
    'name' => 'administer analytics dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'analytics_dashboard',
  );

  // Exported permission: 'administer autologout'.
  $permissions['administer autologout'] = array(
    'name' => 'administer autologout',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'autologout',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer charts'.
  $permissions['administer charts'] = array(
    'name' => 'administer charts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'charts',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer custom content'.
  $permissions['administer custom content'] = array(
    'name' => 'administer custom content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools_custom_content',
  );

  // Exported permission: 'administer date tools'.
  $permissions['administer date tools'] = array(
    'name' => 'administer date tools',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'date_tools',
  );

  // Exported permission: 'administer empty page callbacks'.
  $permissions['administer empty page callbacks'] = array(
    'name' => 'administer empty page callbacks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'empty_page',
  );

  // Exported permission: 'administer facetapi pretty paths'.
  $permissions['administer facetapi pretty paths'] = array(
    'name' => 'administer facetapi pretty paths',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi_pretty_paths',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer login destination settings'.
  $permissions['administer login destination settings'] = array(
    'name' => 'administer login destination settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'login_destination',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer mini panels'.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panel-nodes'.
  $permissions['administer panel-nodes'] = array(
    'name' => 'administer panel-nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_node',
  );

  // Exported permission: 'administer panelizer'.
  $permissions['administer panelizer'] = array(
    'name' => 'administer panelizer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panels display styles'.
  $permissions['administer panels display styles'] = array(
    'name' => 'administer panels display styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels pane styles'.
  $permissions['administer panels pane styles'] = array(
    'name' => 'administer panels pane styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels region styles'.
  $permissions['administer panels region styles'] = array(
    'name' => 'administer panels region styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer password policies'.
  $permissions['administer password policies'] = array(
    'name' => 'administer password policies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'password_policy',
  );

  // Exported permission: 'administer path admin'.
  $permissions['administer path admin'] = array(
    'name' => 'administer path admin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rename_admin_paths',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer recaptcha'.
  $permissions['administer recaptcha'] = array(
    'name' => 'administer recaptcha',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'recaptcha',
  );

  // Exported permission: 'administer roles for menu'.
  $permissions['administer roles for menu'] = array(
    'name' => 'administer roles for menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'roles_for_menu',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer theme assignments'.
  $permissions['administer theme assignments'] = array(
    'name' => 'administer theme assignments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'themekey',
  );

  // Exported permission: 'administer themekey settings'.
  $permissions['administer themekey settings'] = array(
    'name' => 'administer themekey settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'themekey',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'assign node themes'.
  $permissions['assign node themes'] = array(
    'name' => 'assign node themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'themekey_ui',
  );

  // Exported permission: 'assign path alias themes'.
  $permissions['assign path alias themes'] = array(
    'name' => 'assign path alias themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'themekey_ui',
  );

  // Exported permission: 'assign theme to own nodes'.
  $permissions['assign theme to own nodes'] = array(
    'name' => 'assign theme to own nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'themekey_ui',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass access in place editing'.
  $permissions['bypass access in place editing'] = array(
    'name' => 'bypass access in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own logout threshold'.
  $permissions['change own logout threshold'] = array(
    'name' => 'change own logout threshold',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'autologout',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'create 508_scan_information content'.
  $permissions['create 508_scan_information content'] = array(
    'name' => 'create 508_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create agency content'.
  $permissions['create agency content'] = array(
    'name' => 'create agency content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create broken_link_scan content'.
  $permissions['create broken_link_scan content'] = array(
    'name' => 'create broken_link_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create cookie_law_scan content'.
  $permissions['create cookie_law_scan content'] = array(
    'name' => 'create cookie_law_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create dnssec_ipv6_information content'.
  $permissions['create dnssec_ipv6_information content'] = array(
    'name' => 'create dnssec_ipv6_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create domain_scan_information content'.
  $permissions['create domain_scan_information content'] = array(
    'name' => 'create domain_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create https_dap_scan_information content'.
  $permissions['create https_dap_scan_information content'] = array(
    'name' => 'create https_dap_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create mini panels'.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'create mobile_scan_information content'.
  $permissions['create mobile_scan_information content'] = array(
    'name' => 'create mobile_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create panel content'.
  $permissions['create panel content'] = array(
    'name' => 'create panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create scans content'.
  $permissions['create scans content'] = array(
    'name' => 'create scans content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create seo_scan_information content'.
  $permissions['create seo_scan_information content'] = array(
    'name' => 'create seo_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create site_speed_scan content'.
  $permissions['create site_speed_scan content'] = array(
    'name' => 'create site_speed_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create website content'.
  $permissions['create website content'] = array(
    'name' => 'create website content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create website_scan_info content'.
  $permissions['create website_scan_info content'] = array(
    'name' => 'create website_scan_info content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete any 508_scan_information content'.
  $permissions['delete any 508_scan_information content'] = array(
    'name' => 'delete any 508_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any agency content'.
  $permissions['delete any agency content'] = array(
    'name' => 'delete any agency content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any broken_link_scan content'.
  $permissions['delete any broken_link_scan content'] = array(
    'name' => 'delete any broken_link_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any cookie_law_scan content'.
  $permissions['delete any cookie_law_scan content'] = array(
    'name' => 'delete any cookie_law_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any dnssec_ipv6_information content'.
  $permissions['delete any dnssec_ipv6_information content'] = array(
    'name' => 'delete any dnssec_ipv6_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any domain_scan_information content'.
  $permissions['delete any domain_scan_information content'] = array(
    'name' => 'delete any domain_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any https_dap_scan_information content'.
  $permissions['delete any https_dap_scan_information content'] = array(
    'name' => 'delete any https_dap_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any mobile_scan_information content'.
  $permissions['delete any mobile_scan_information content'] = array(
    'name' => 'delete any mobile_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any panel content'.
  $permissions['delete any panel content'] = array(
    'name' => 'delete any panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any scans content'.
  $permissions['delete any scans content'] = array(
    'name' => 'delete any scans content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any seo_scan_information content'.
  $permissions['delete any seo_scan_information content'] = array(
    'name' => 'delete any seo_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any site_speed_scan content'.
  $permissions['delete any site_speed_scan content'] = array(
    'name' => 'delete any site_speed_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any website content'.
  $permissions['delete any website content'] = array(
    'name' => 'delete any website content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any website_scan_info content'.
  $permissions['delete any website_scan_info content'] = array(
    'name' => 'delete any website_scan_info content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own 508_scan_information content'.
  $permissions['delete own 508_scan_information content'] = array(
    'name' => 'delete own 508_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own agency content'.
  $permissions['delete own agency content'] = array(
    'name' => 'delete own agency content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own broken_link_scan content'.
  $permissions['delete own broken_link_scan content'] = array(
    'name' => 'delete own broken_link_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own cookie_law_scan content'.
  $permissions['delete own cookie_law_scan content'] = array(
    'name' => 'delete own cookie_law_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own dnssec_ipv6_information content'.
  $permissions['delete own dnssec_ipv6_information content'] = array(
    'name' => 'delete own dnssec_ipv6_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own domain_scan_information content'.
  $permissions['delete own domain_scan_information content'] = array(
    'name' => 'delete own domain_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own https_dap_scan_information content'.
  $permissions['delete own https_dap_scan_information content'] = array(
    'name' => 'delete own https_dap_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own mobile_scan_information content'.
  $permissions['delete own mobile_scan_information content'] = array(
    'name' => 'delete own mobile_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own panel content'.
  $permissions['delete own panel content'] = array(
    'name' => 'delete own panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own scans content'.
  $permissions['delete own scans content'] = array(
    'name' => 'delete own scans content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own seo_scan_information content'.
  $permissions['delete own seo_scan_information content'] = array(
    'name' => 'delete own seo_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own site_speed_scan content'.
  $permissions['delete own site_speed_scan content'] = array(
    'name' => 'delete own site_speed_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own website content'.
  $permissions['delete own website content'] = array(
    'name' => 'delete own website content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own website_scan_info content'.
  $permissions['delete own website_scan_info content'] = array(
    'name' => 'delete own website_scan_info content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in keywords'.
  $permissions['delete terms in keywords'] = array(
    'name' => 'delete terms in keywords',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in website_tags'.
  $permissions['delete terms in website_tags'] = array(
    'name' => 'delete terms in website_tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'diff view changes'.
  $permissions['diff view changes'] = array(
    'name' => 'diff view changes',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'diff',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any 508_scan_information content'.
  $permissions['edit any 508_scan_information content'] = array(
    'name' => 'edit any 508_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any agency content'.
  $permissions['edit any agency content'] = array(
    'name' => 'edit any agency content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any broken_link_scan content'.
  $permissions['edit any broken_link_scan content'] = array(
    'name' => 'edit any broken_link_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any cookie_law_scan content'.
  $permissions['edit any cookie_law_scan content'] = array(
    'name' => 'edit any cookie_law_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any dnssec_ipv6_information content'.
  $permissions['edit any dnssec_ipv6_information content'] = array(
    'name' => 'edit any dnssec_ipv6_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any domain_scan_information content'.
  $permissions['edit any domain_scan_information content'] = array(
    'name' => 'edit any domain_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any https_dap_scan_information content'.
  $permissions['edit any https_dap_scan_information content'] = array(
    'name' => 'edit any https_dap_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any mobile_scan_information content'.
  $permissions['edit any mobile_scan_information content'] = array(
    'name' => 'edit any mobile_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any panel content'.
  $permissions['edit any panel content'] = array(
    'name' => 'edit any panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any scans content'.
  $permissions['edit any scans content'] = array(
    'name' => 'edit any scans content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any seo_scan_information content'.
  $permissions['edit any seo_scan_information content'] = array(
    'name' => 'edit any seo_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any site_speed_scan content'.
  $permissions['edit any site_speed_scan content'] = array(
    'name' => 'edit any site_speed_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any website content'.
  $permissions['edit any website content'] = array(
    'name' => 'edit any website content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any website_scan_info content'.
  $permissions['edit any website_scan_info content'] = array(
    'name' => 'edit any website_scan_info content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own 508_scan_information content'.
  $permissions['edit own 508_scan_information content'] = array(
    'name' => 'edit own 508_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own agency content'.
  $permissions['edit own agency content'] = array(
    'name' => 'edit own agency content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own broken_link_scan content'.
  $permissions['edit own broken_link_scan content'] = array(
    'name' => 'edit own broken_link_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own cookie_law_scan content'.
  $permissions['edit own cookie_law_scan content'] = array(
    'name' => 'edit own cookie_law_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own dnssec_ipv6_information content'.
  $permissions['edit own dnssec_ipv6_information content'] = array(
    'name' => 'edit own dnssec_ipv6_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own domain_scan_information content'.
  $permissions['edit own domain_scan_information content'] = array(
    'name' => 'edit own domain_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own https_dap_scan_information content'.
  $permissions['edit own https_dap_scan_information content'] = array(
    'name' => 'edit own https_dap_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own mobile_scan_information content'.
  $permissions['edit own mobile_scan_information content'] = array(
    'name' => 'edit own mobile_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own panel content'.
  $permissions['edit own panel content'] = array(
    'name' => 'edit own panel content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own scans content'.
  $permissions['edit own scans content'] = array(
    'name' => 'edit own scans content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own seo_scan_information content'.
  $permissions['edit own seo_scan_information content'] = array(
    'name' => 'edit own seo_scan_information content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own site_speed_scan content'.
  $permissions['edit own site_speed_scan content'] = array(
    'name' => 'edit own site_speed_scan content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own website content'.
  $permissions['edit own website content'] = array(
    'name' => 'edit own website content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own website_scan_info content'.
  $permissions['edit own website_scan_info content'] = array(
    'name' => 'edit own website_scan_info content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in keywords'.
  $permissions['edit terms in keywords'] = array(
    'name' => 'edit terms in keywords',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in website_tags'.
  $permissions['edit terms in website_tags'] = array(
    'name' => 'edit terms in website_tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'force password change'.
  $permissions['force password change'] = array(
    'name' => 'force password change',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'password_policy',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Agency Admin User' => 'Agency Admin User',
      'Agency User' => 'Agency User',
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'select different theme'.
  $permissions['select different theme'] = array(
    'name' => 'select different theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'themekey_user_profile',
  );

  // Exported permission: 'setup own tfa'.
  $permissions['setup own tfa'] = array(
    'name' => 'setup own tfa',
    'roles' => array(
      'Agency Admin User' => 'Agency Admin User',
      'Agency User' => 'Agency User',
      'Super User' => 'Super User',
    ),
    'module' => 'tfa_basic',
  );

  // Exported permission: 'skip CAPTCHA'.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'themekey_debug_see_messages'.
  $permissions['themekey_debug_see_messages'] = array(
    'name' => 'themekey_debug_see_messages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'themekey_debug',
  );

  // Exported permission: 'unblock expired accounts'.
  $permissions['unblock expired accounts'] = array(
    'name' => 'unblock expired accounts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'password_policy',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'Agency Admin User' => 'Agency Admin User',
      'Agency User' => 'Agency User',
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use bulk exporter'.
  $permissions['use bulk exporter'] = array(
    'name' => 'use bulk exporter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bulk_export',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view analytics dashboard'.
  $permissions['view analytics dashboard'] = array(
    'name' => 'view analytics dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'analytics_dashboard',
  );

  // Exported permission: 'view date repeats'.
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'date_repeat_field',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
