<?php

/**
 * @file
 * path_breadcrumbs_v2.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function path_breadcrumbs_v2_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'accessibility';
  $path_breadcrumb->name = 'Accessibility';
  $path_breadcrumb->path = 'gov-wide-accessibility';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['accessibility'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'accessibility_guidance';
  $path_breadcrumb->name = 'Accessibility Guidance';
  $path_breadcrumb->path = 'node/7267';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'FAQ',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'faq',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['accessibility_guidance'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'agency_accessibility';
  $path_breadcrumb->name = 'Agency Accessibility';
  $path_breadcrumb->path = 'my-agency-accessibility';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'My Agency',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'myagency_home',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'my-agency-accessibility',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['agency_accessibility'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'agency_all_data';
  $path_breadcrumb->name = 'agency-all-data';
  $path_breadcrumb->path = 'agency/all/data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Agency-Wide Reports',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'agency/all/data',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['agency_all_data'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'agency_dashboard';
  $path_breadcrumb->name = 'agency dashboard';
  $path_breadcrumb->path = 'agency_home/%id';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Agency-Wide Reports',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'agency/all/data',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'id' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['agency_dashboard'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'agency_wide_accessibility_summery';
  $path_breadcrumb->name = 'Agency-Wide Accessibility Report';
  $path_breadcrumb->path = 'agency-wide-accessibility-summary-new';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Agency-Wide Reports',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'agency/all/data',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['agency_wide_accessibility_summery'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'agency_wide_historical_scan_results';
  $path_breadcrumb->name = 'Agency-Wide Historical Scan Results';
  $path_breadcrumb->path = 'agency-wide-archive-data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Agency-Wide Reports',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'agency/all/data',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['agency_wide_historical_scan_results'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'agency_wide_mobile_reports';
  $path_breadcrumb->name = 'Agency-Wide Mobile Reports';
  $path_breadcrumb->path = 'website/mobile/reports';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Agency-Wide Reports',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'agency/all/data',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['agency_wide_mobile_reports'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'data_discovery';
  $path_breadcrumb->name = 'data_discovery';
  $path_breadcrumb->path = 'multistep-search';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Data Discovery',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'multistep-search',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['data_discovery'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'domain_level_accessibility_report';
  $path_breadcrumb->name = 'Domain Level Accessibility Report';
  $path_breadcrumb->path = 'accessibilityreportalldomains?field_web_agency_id_nid_selective=node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'agency_home/%node',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['domain_level_accessibility_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'domain_wide_trend_analysis';
  $path_breadcrumb->name = 'Domain-Wide Trend Analysis';
  $path_breadcrumb->path = 'trend-analysis-domains';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Website-Specific Reports',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'website/all/reports',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['domain_wide_trend_analysis'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'faq';
  $path_breadcrumb->name = 'FAQ';
  $path_breadcrumb->path = 'node/4754';
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
  $export['faq'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_accessibility_report';
  $path_breadcrumb->name = 'Government-Wide Accessibility Report';
  $path_breadcrumb->path = 'gov-wide-accessibility-summary';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['government_wide_accessibility_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_bod_report';
  $path_breadcrumb->name = 'Government-Wide M-15-13 and BOD 18-01 Report';
  $path_breadcrumb->path = 'agency/all/m1513_bod_data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => 'Top Performing Agencies',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => 'agency/all/reports-data',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['government_wide_bod_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_dap_report';
  $path_breadcrumb->name = 'Government-Wide DAP Report';
  $path_breadcrumb->path = 'agency/all/dap_data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => 'Top Performing Agencies',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => 'agency/all/reports-data',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['government_wide_dap_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_dap_report_clone';
  $path_breadcrumb->name = 'Government-Wide DNSSEC Report';
  $path_breadcrumb->path = 'agency/all/dnssec_data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => 'Top Performing Agencies',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => 'agency/all/reports-data',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['government_wide_dap_report_clone'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_historical_scan_results';
  $path_breadcrumb->name = 'Government-Wide Historical Scan Results';
  $path_breadcrumb->path = 'government-wide-archive-data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['government_wide_historical_scan_results'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_https_report';
  $path_breadcrumb->name = 'Government-Wide HTTPS Report';
  $path_breadcrumb->path = 'agency/all/https_data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => 'Top Performing Agencies',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => 'agency/all/reports-data',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['government_wide_https_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_insecure_data';
  $path_breadcrumb->name = 'Government-Wide Free of RC4/3DES and SSLv2/SSLv3 Report';
  $path_breadcrumb->path = 'agency/all/free_of_insecure_data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => 'Top Performing Agencies',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => 'agency/all/reports-data',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['government_wide_insecure_data'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_ipv6_report';
  $path_breadcrumb->name = 'Government-Wide IPv6 Report';
  $path_breadcrumb->path = 'agency/all/ipv6_data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => 'Top Performing Agencies',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => 'agency/all/reports-data',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['government_wide_ipv6_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_mobile_report';
  $path_breadcrumb->name = 'Government-Wide Mobile Report';
  $path_breadcrumb->path = 'mobile/report';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['government_wide_mobile_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'government_wide_site_speed';
  $path_breadcrumb->name = 'Government-Wide Site Speed Report';
  $path_breadcrumb->path = 'agency/all/sitespeed_data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => 'Top Performing Agencies',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance',
      1 => 'agency/all/reports-data',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['government_wide_site_speed'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'govt_wide_reports';
  $path_breadcrumb->name = 'govt-wide-reports';
  $path_breadcrumb->path = 'overall/gov-wide-compliance';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'overall/gov-wide-compliance',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['govt_wide_reports'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'historical_accessibility_scan';
  $path_breadcrumb->name = 'Historical Accessibility Scan';
  $path_breadcrumb->path = 'accessibility_historical_data/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Website-Specific Reports',
      1 => 'Website-Specific Trend Analysis',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'website/all/reports',
      1 => 'trend-analysis-domains',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'accessibility_historical_data/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['historical_accessibility_scan'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'improve_my_score';
  $path_breadcrumb->name = 'improve-my-scores';
  $path_breadcrumb->path = 'node/7829';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'FAQ',
      1 => 'Improve My Scores',
    ),
    'paths' => array(
      0 => 'faq',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['improve_my_score'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'myagency_home';
  $path_breadcrumb->name = 'myagency_home';
  $path_breadcrumb->path = 'myagency_home';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'My Agency',
    ),
    'paths' => array(
      0 => 'myagency_home',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['myagency_home'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'overall_compliance';
  $path_breadcrumb->name = 'overall-compliance';
  $path_breadcrumb->path = 'overall/compliance';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '<none>',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'overall/compliance',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['overall_compliance'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'popular_reports';
  $path_breadcrumb->name = 'Popular Reports';
  $path_breadcrumb->path = 'reports';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Domain-Wide Reports',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'website/all/reports',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['popular_reports'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'scoring_methods';
  $path_breadcrumb->name = 'Scoring Methods';
  $path_breadcrumb->path = 'node/4752';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'FAQs',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'faq',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['scoring_methods'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'technology_stack_report';
  $path_breadcrumb->name = 'Technology Stack Report';
  $path_breadcrumb->path = 'technology-overview';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Technology Usage',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'top_technology_usage',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['technology_stack_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'technology_usage';
  $path_breadcrumb->name = 'Technology Usage';
  $path_breadcrumb->path = 'top_technology_usage';
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
  $export['technology_usage'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'top_agencies';
  $path_breadcrumb->name = 'top-agencies';
  $path_breadcrumb->path = 'agency/all/reports-data';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Government-Wide Reports',
      1 => 'Top Performing Agencies',
    ),
    'paths' => array(
      0 => 'overall/gov-wide-compliance?field_web_agency_id_nid=All',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'agency/all/reports-data',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['top_agencies'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'trend_analysis';
  $path_breadcrumb->name = 'trend_analysis';
  $path_breadcrumb->path = 'trend_analysis/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Website-Specific Reports',
      1 => 'Website-Specific Trend Analysis',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'website/all/reports',
      1 => 'trend-analysis-domains',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'trend_analysis/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['trend_analysis'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_manual';
  $path_breadcrumb->name = 'User Manual';
  $path_breadcrumb->path = 'node/4755';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'FAQ',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'faq',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['user_manual'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'views2';
  $path_breadcrumb->name = 'views2';
  $path_breadcrumb->path = 'historical_scan_score_data/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => 'website/!node/information',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'historical_scan_score_data/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['views2'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'views_breadcrumb_hide';
  $path_breadcrumb->name = 'views_breadcrumb_hide';
  $path_breadcrumb->path = 'technology_scan_historical/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Website-Specific Reports',
      1 => 'Website-Specific Trend Analysis',
      2 => '!page_title',
    ),
    'paths' => array(
      0 => 'website/all/reports',
      1 => 'trend-analysis-domains',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'technology_scan_historical/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['views_breadcrumb_hide'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'website_accessibility_report';
  $path_breadcrumb->name = 'Website Accessibility Report';
  $path_breadcrumb->path = 'accessibility-report-all-domains';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Website-Specific Reports',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'website/all/reports',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['website_accessibility_report'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'website_information';
  $path_breadcrumb->name = 'website_information';
  $path_breadcrumb->path = 'website/%node/information';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Website Information',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'website/*/information',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['website_information'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'website_reports';
  $path_breadcrumb->name = 'website-reports';
  $path_breadcrumb->path = 'website/all/reports';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'website/all/reports',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['website_reports'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'website_search';
  $path_breadcrumb->name = 'website search';
  $path_breadcrumb->path = 'search/website_search/%search';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Search',
      1 => '!search',
    ),
    'paths' => array(
      0 => 'search/website_search',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'search' => array(
        'position' => 2,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['website_search'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'website_search_engine_page';
  $path_breadcrumb->name = 'Website Search Engine Page';
  $path_breadcrumb->path = 'website/search/reports';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Website-Specific Reports ',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'website/all/reports',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['website_search_engine_page'] = $path_breadcrumb;

  return $export;
}
