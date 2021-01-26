<?php

/**
 * @file
 * menu_update_v2.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menu_update_v2_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_accessibility-guidance:node/7267.
  $menu_links['main-menu_accessibility-guidance:node/7267'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/7267',
    'router_path' => 'node/%',
    'link_title' => 'Accessibility Guidance',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'attributes' => array(
        'title' => 'Accessibility Guidance',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_accessibility-guidance:node/7267',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_faq:node/10110',
  );
  // Exported menu link: main-menu_accessibility-report:gov-wide-accessibility.
  $menu_links['main-menu_accessibility-report:gov-wide-accessibility'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'gov-wide-accessibility',
    'router_path' => 'gov-wide-accessibility',
    'link_title' => 'Accessibility Report',
    'options' => array(
      'attributes' => array(
        'title' => 'Accessibility Report',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_accessibility-report:gov-wide-accessibility',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -27,
    'customized' => 1,
  );
  // Exported menu link: main-menu_accessibility:gov-wide-accessibility.
  $menu_links['main-menu_accessibility:gov-wide-accessibility'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'gov-wide-accessibility',
    'router_path' => 'gov-wide-accessibility',
    'link_title' => 'Accessibility',
    'options' => array(
      'attributes' => array(
        'title' => 'Accessibility',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          3 => 3,
          13 => 13,
          16 => 16,
        ),
        'hide' => array(
          1 => 1,
          12 => 12,
          14 => 14,
          15 => 15,
        ),
      ),
      'identifier' => 'main-menu_accessibility:gov-wide-accessibility',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -32,
    'customized' => 1,
  );
  // Exported menu link: main-menu_accessibility:my-agency-accessibility.
  $menu_links['main-menu_accessibility:my-agency-accessibility'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'my-agency-accessibility',
    'router_path' => 'my-agency-accessibility',
    'link_title' => 'Accessibility',
    'options' => array(
      'attributes' => array(
        'title' => 'Accessibility',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_accessibility:my-agency-accessibility',
      'roles_for_menu' => array(
        'show' => array(
          12 => 12,
          14 => 14,
        ),
        'hide' => array(),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -31,
    'customized' => 1,
  );
  // Exported menu link: main-menu_agency-wide-accessibility-report:agency-wide-accessibility-summary-new.
  $menu_links['main-menu_agency-wide-accessibility-report:agency-wide-accessibility-summary-new'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'agency-wide-accessibility-summary-new',
    'router_path' => 'agency-wide-accessibility-summary-new',
    'link_title' => 'Agency-Wide Accessibility Report',
    'options' => array(
      'attributes' => array(
        'title' => 'Agency-Wide Accessibility Report',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_agency-wide-accessibility-report:agency-wide-accessibility-summary-new',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -28,
    'customized' => 1,
  );
  // Exported menu link: main-menu_agency-wide-accessibility-spot-checks:agency-wide-accessibility-summary-new.
  $menu_links['main-menu_agency-wide-accessibility-spot-checks:agency-wide-accessibility-summary-new'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'agency-wide-accessibility-summary-new',
    'router_path' => 'agency-wide-accessibility-summary-new',
    'link_title' => 'Agency-Wide Accessibility Spot Checks',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(
          3 => 3,
          16 => 16,
        ),
        'hide' => array(),
      ),
      'attributes' => array(
        'title' => 'Agency-Wide Accessibility Spot Checks',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_agency-wide-accessibility-spot-checks:agency-wide-accessibility-summary-new',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'main-menu_accessibility:gov-wide-accessibility',
  );
  // Exported menu link: main-menu_agency-wide-historical-scan-results:agency-wide-archive-data.
  $menu_links['main-menu_agency-wide-historical-scan-results:agency-wide-archive-data'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'agency-wide-archive-data',
    'router_path' => 'agency-wide-archive-data',
    'link_title' => 'Agency-Wide Historical Scan Results',
    'options' => array(
      'attributes' => array(
        'title' => 'Agency-Wide Historical Scan Results',
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
          15 => 15,
        ),
      ),
      'identifier' => 'main-menu_agency-wide-historical-scan-results:agency-wide-archive-data',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_agency-wide:agency/all/data',
  );
  // Exported menu link: main-menu_contact-us:mailto:dotgovdashboard@gsa.gov.
  $menu_links['main-menu_contact-us:mailto:dotgovdashboard@gsa.gov'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'mailto:dotgovdashboard@gsa.gov',
    'router_path' => '',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(
        'title' => 'Contact Us',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
          2 => 2,
        ),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_contact-us:mailto:dotgovdashboard@gsa.gov',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_user-guide:node/4755',
  );
  // Exported menu link: main-menu_data-discovery:multistep-search.
  $menu_links['main-menu_data-discovery:multistep-search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'multistep-search',
    'router_path' => 'multistep-search',
    'link_title' => 'Data Discovery',
    'options' => array(
      'attributes' => array(
        'title' => 'Data Discovery',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_data-discovery:multistep-search',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -24,
    'customized' => 1,
  );
  // Exported menu link: main-menu_data-discovery:search/site/*.
  $menu_links['main-menu_data-discovery:search/site/*'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search/site/*',
    'router_path' => 'search',
    'link_title' => 'Data Discovery',
    'options' => array(
      'attributes' => array(
        'title' => 'Data Discovery',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          3 => 3,
          6 => 6,
        ),
        'hide' => array(),
      ),
      'query' => array(
        'solrsort' => 'sort_label asc',
      ),
      'identifier' => 'main-menu_data-discovery:search/site/*',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_digital-dashboard-user-manual:node/4755.
  $menu_links['main-menu_digital-dashboard-user-manual:node/4755'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4755',
    'router_path' => 'node/%',
    'link_title' => 'Digital Dashboard User Manual',
    'options' => array(
      'attributes' => array(
        'title' => 'User Manual',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_digital-dashboard-user-manual:node/4755',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_user-guide:node/4755',
  );
  // Exported menu link: main-menu_government-wide-accessibility-report:gov-wide-accessibility-summary.
  $menu_links['main-menu_government-wide-accessibility-report:gov-wide-accessibility-summary'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'gov-wide-accessibility-summary',
    'router_path' => 'gov-wide-accessibility-summary',
    'link_title' => 'Government-Wide Accessibility Report',
    'options' => array(
      'attributes' => array(
        'title' => 'Government-Wide Accessibility Report',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_government-wide-accessibility-report:gov-wide-accessibility-summary',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -26,
    'customized' => 1,
  );
  // Exported menu link: main-menu_government-wide-accessibility-spot-checks:gov-wide-accessibility-summary.
  $menu_links['main-menu_government-wide-accessibility-spot-checks:gov-wide-accessibility-summary'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'gov-wide-accessibility-summary',
    'router_path' => 'gov-wide-accessibility-summary',
    'link_title' => 'Government-Wide Accessibility Spot Checks',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(
          3 => 3,
          16 => 16,
        ),
        'hide' => array(),
      ),
      'attributes' => array(
        'title' => 'Government-Wide Accessibility Spot Checks',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_government-wide-accessibility-spot-checks:gov-wide-accessibility-summary',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_accessibility:gov-wide-accessibility',
  );
  // Exported menu link: main-menu_government-wide-historical-scan-results:government-wide-archive-data.
  $menu_links['main-menu_government-wide-historical-scan-results:government-wide-archive-data'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'government-wide-archive-data',
    'router_path' => 'government-wide-archive-data',
    'link_title' => 'Government-Wide Historical Scan Results',
    'options' => array(
      'attributes' => array(
        'title' => 'Government-Wide Historical Scan Results
Government-Wide Historical Scan Results',
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
          15 => 15,
        ),
      ),
      'identifier' => 'main-menu_government-wide-historical-scan-results:government-wide-archive-data',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_government-wide:overall/gov-wide-compliance',
  );
  // Exported menu link: main-menu_improve-my-scores:node/7829.
  $menu_links['main-menu_improve-my-scores:node/7829'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/7829',
    'router_path' => 'node/%',
    'link_title' => 'Improve My Scores',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
          2 => 2,
          3 => 3,
          12 => 12,
          13 => 13,
          14 => 14,
          15 => 15,
          16 => 16,
        ),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_improve-my-scores:node/7829',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_faq:node/10110',
  );
  // Exported menu link: main-menu_marketplace:node/4749.
  $menu_links['main-menu_marketplace:node/4749'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4749',
    'router_path' => 'node/%',
    'link_title' => 'Marketplace',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'attributes' => array(
        'title' => 'Marketplace',
      ),
      'identifier' => 'main-menu_marketplace:node/4749',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_my-agency:myagency_home.
  $menu_links['main-menu_my-agency:myagency_home'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'myagency_home',
    'router_path' => 'myagency_home',
    'link_title' => 'My Agency',
    'options' => array(
      'attributes' => array(
        'title' => 'My Agency',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          12 => 12,
          13 => 13,
          14 => 14,
          15 => 15,
          16 => 16,
        ),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_my-agency:myagency_home',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: main-menu_my-websites:mywebsites.
  $menu_links['main-menu_my-websites:mywebsites'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'mywebsites',
    'router_path' => 'mywebsites',
    'link_title' => 'My Websites',
    'options' => array(
      'attributes' => array(
        'title' => 'My Websites',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          12 => 12,
          14 => 14,
          15 => 15,
        ),
        'hide' => array(
          3 => 3,
          13 => 13,
          16 => 16,
        ),
      ),
      'identifier' => 'main-menu_my-websites:mywebsites',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
  );
  // Exported menu link: main-menu_on-site-search-reports:website/search/reports.
  $menu_links['main-menu_on-site-search-reports:website/search/reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'website/search/reports',
    'router_path' => 'website/search/reports',
    'link_title' => 'On-Site Search Reports',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(),
        'hide' => array(),
      ),
      'attributes' => array(
        'title' => 'On-Site Search Reports',
      ),
      'identifier' => 'main-menu_on-site-search-reports:website/search/reports',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_website-specific:website/all/reports',
  );
  // Exported menu link: main-menu_popular-reports:reports.
  $menu_links['main-menu_popular-reports:reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'reports',
    'router_path' => 'reports',
    'link_title' => 'Popular Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'Popular Reports',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_popular-reports:reports',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_website-specific:website/all/reports',
  );
  // Exported menu link: main-menu_pulse:http://pulse.cio.gov/.
  $menu_links['main-menu_pulse:http://pulse.cio.gov/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://pulse.cio.gov/',
    'router_path' => '',
    'link_title' => 'Pulse',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
          2 => 2,
        ),
        'hide' => array(),
      ),
      'attributes' => array(
        'title' => 'Pulse',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_pulse:http://pulse.cio.gov/',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_scoring-methods:node/4752.
  $menu_links['main-menu_scoring-methods:node/4752'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4752',
    'router_path' => 'node/%',
    'link_title' => 'Scoring Methods',
    'options' => array(
      'attributes' => array(
        'title' => 'Scoring Methods',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          1 => 1,
          2 => 2,
          3 => 3,
          12 => 12,
          13 => 13,
          14 => 14,
          15 => 15,
          16 => 16,
        ),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_scoring-methods:node/4752',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_faq:node/10110',
  );
  // Exported menu link: main-menu_sites-using-cdn:search/site.
  $menu_links['main-menu_sites-using-cdn:search/site'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search/site',
    'router_path' => 'search',
    'link_title' => 'Sites Using CDN',
    'options' => array(
      'query' => array(
        'f[0]' => 'sm_field_cdn_provider_name:akamai',
        'f[1]' => 'sm_field_cdn_provider_name:cloudfront',
      ),
      'attributes' => array(
        'title' => 'Sites Using CDN',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          3 => 3,
          6 => 6,
        ),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_sites-using-cdn:search/site',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -40,
    'customized' => 1,
  );
  // Exported menu link: main-menu_technology-stack-report:technology-overview.
  $menu_links['main-menu_technology-stack-report:technology-overview'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'technology-overview',
    'router_path' => 'technology-overview',
    'link_title' => 'Technology Stack Report',
    'options' => array(
      'attributes' => array(
        'title' => 'Technology Stack Report',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_technology-stack-report:technology-overview',
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
  // Exported menu link: main-menu_technology-usage:top_technology_usage.
  $menu_links['main-menu_technology-usage:top_technology_usage'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'top_technology_usage',
    'router_path' => 'top_technology_usage',
    'link_title' => 'Technology Usage',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          3 => 3,
          13 => 13,
          16 => 16,
        ),
        'hide' => array(
          1 => 1,
          12 => 12,
          14 => 14,
        ),
      ),
      'identifier' => 'main-menu_technology-usage:top_technology_usage',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -37,
    'customized' => 1,
  );
  // Exported menu link: main-menu_top-technology-stack-usage:top_technology_usage.
  $menu_links['main-menu_top-technology-stack-usage:top_technology_usage'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'top_technology_usage',
    'router_path' => 'top_technology_usage',
    'link_title' => 'Top Technology Stack Usage',
    'options' => array(
      'attributes' => array(
        'title' => 'Top Technology Stack Usage',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_top-technology-stack-usage:top_technology_usage',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: main-menu_user-guide:node/4755.
  $menu_links['main-menu_user-guide:node/4755'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4755',
    'router_path' => 'node/%',
    'link_title' => 'User Guide',
    'options' => array(
      'attributes' => array(
        'title' => 'User Guide',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
          3 => 3,
          12 => 12,
          13 => 13,
          14 => 14,
          15 => 15,
          16 => 16,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_user-guide:node/4755',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_faq:node/10110',
  );
  // Exported menu link: main-menu_users:admin/people.
  $menu_links['main-menu_users:admin/people'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'Users',
    'options' => array(
      'attributes' => array(
        'title' => 'Users',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          3 => 3,
        ),
        'hide' => array(
          4 => 4,
          6 => 6,
        ),
      ),
      'identifier' => 'main-menu_users:admin/people',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_website-accessibility-report:accessibility-report-all-domains.
  $menu_links['main-menu_website-accessibility-report:accessibility-report-all-domains'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'accessibility-report-all-domains',
    'router_path' => 'accessibility-report-all-domains',
    'link_title' => 'Website Accessibility Report',
    'options' => array(
      'attributes' => array(
        'title' => 'Website Accessibility Report',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_website-accessibility-report:accessibility-report-all-domains',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -25,
    'customized' => 1,
  );
  // Exported menu link: main-menu_website-accessibility-spot-checks:accessibility-report-all-domains.
  $menu_links['main-menu_website-accessibility-spot-checks:accessibility-report-all-domains'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'accessibility-report-all-domains',
    'router_path' => 'accessibility-report-all-domains',
    'link_title' => 'Website Accessibility Spot Checks',
    'options' => array(
      'roles_for_menu' => array(
        'show' => array(
          3 => 3,
          16 => 16,
        ),
        'hide' => array(),
      ),
      'attributes' => array(
        'title' => 'Website Accessibility Spot Checks',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_website-accessibility-spot-checks:accessibility-report-all-domains',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'main-menu_accessibility:gov-wide-accessibility',
  );
  // Exported menu link: main-menu_website-specific-trend-analysis:myagency-trend-analysis-domains.
  $menu_links['main-menu_website-specific-trend-analysis:myagency-trend-analysis-domains'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'myagency-trend-analysis-domains',
    'router_path' => 'myagency-trend-analysis-domains',
    'link_title' => 'Website-Specific Trend Analysis',
    'options' => array(
      'attributes' => array(
        'title' => 'My Agency Website-Specific Trend Analysis',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          14 => 14,
        ),
        'hide' => array(),
      ),
      'identifier' => 'main-menu_website-specific-trend-analysis:myagency-trend-analysis-domains',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -36,
    'customized' => 1,
  );
  // Exported menu link: main-menu_website-specific-trend-analysis:trend-analysis-domains.
  $menu_links['main-menu_website-specific-trend-analysis:trend-analysis-domains'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'trend-analysis-domains',
    'router_path' => 'trend-analysis-domains',
    'link_title' => 'Website-Specific Trend Analysis',
    'options' => array(
      'attributes' => array(
        'title' => 'Trend Analysis',
      ),
      'alter' => TRUE,
      'roles_for_menu' => array(
        'show' => array(
          2 => 2,
        ),
        'hide' => array(
          1 => 1,
        ),
      ),
      'identifier' => 'main-menu_website-specific-trend-analysis:trend-analysis-domains',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_website-specific:website/all/reports',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Accessibility');
  t('Accessibility Guidance');
  t('Accessibility Report');
  t('Agency-Wide Accessibility Report');
  t('Agency-Wide Accessibility Spot Checks');
  t('Agency-Wide Historical Scan Results');
  t('Contact Us');
  t('Data Discovery');
  t('Digital Dashboard User Manual');
  t('Government-Wide Accessibility Report');
  t('Government-Wide Accessibility Spot Checks');
  t('Government-Wide Historical Scan Results');
  t('Improve My Scores');
  t('Marketplace');
  t('My Agency');
  t('My Websites');
  t('On-Site Search Reports');
  t('Popular Reports');
  t('Pulse');
  t('Scoring Methods');
  t('Sites Using CDN');
  t('Technology Stack Report');
  t('Technology Usage');
  t('Top Technology Stack Usage');
  t('User Guide');
  t('Users');
  t('Website Accessibility Report');
  t('Website Accessibility Spot Checks');
  t('Website-Specific Trend Analysis');

  return $menu_links;
}
