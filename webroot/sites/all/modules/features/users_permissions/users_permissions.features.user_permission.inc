<?php
/**
 * @file
 * users_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function users_permissions_user_default_permissions() {
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

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(),
    'module' => 'features_master',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(),
    'module' => 'features_master',
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

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(),
    'module' => 'features_master',
  );

  // Exported permission: 'administer block classes'.
  $permissions['administer block classes'] = array(
    'name' => 'administer block classes',
    'roles' => array(),
    'module' => 'features_master',
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

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
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

  // Exported permission: 'administer password policies'.
  $permissions['administer password policies'] = array(
    'name' => 'administer password policies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'password_policy',
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
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(),
    'module' => 'features_master',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
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

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(),
    'module' => 'features_master',
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

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(),
    'module' => 'features_master',
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

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(),
    'module' => 'features_master',
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
