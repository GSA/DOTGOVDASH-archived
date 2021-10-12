<?php

/**
 * @file
 * website_reports.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function website_reports_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'all_website_reports_new';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All Website Reports New';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Government-Wide Domain Level Mobile Report';
  $handler->display->display_options['css_class'] = 'white-back';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    13 => '13',
    16 => '16',
    1 => '1',
  );
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'filtered_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_web_agency_id_nid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'Filter By Agency',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'body' => 'body',
    'field_dap_score' => 'field_dap_score',
    'field_https_score' => 'field_https_score',
    'field_ssl_score' => 'field_ssl_score',
    'field_mobile_overall_score' => 'field_mobile_overall_score',
    'field_mobile_performance_score' => 'field_mobile_performance_score',
    'field_mobile_usability_score' => 'field_mobile_usability_score',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_web_agency_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dap_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_https_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ssl_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_overall_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_performance_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_usability_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'DAP Score';
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == "")
print "N/A";
else
print $data->field_field_dap_score[\'0\'][\'raw\'][\'value\'];
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['text'] = '[field_https_score-value]';
  $handler->display->display_options['fields']['field_https_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_https_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['text'] = '[field_mobile_overall_score-value]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['text'] = '[field_mobile_performance_score-value]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['text'] = '[field_mobile_usability_score-value] ';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Site Speed Score */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['text'] = '[field_site_speed_score-value]';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['path'] = '/test';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: DNSSEC Score */
  $handler->display->display_options['fields']['field_dnssec_score']['id'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['table'] = 'field_data_field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['field'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['text'] = '[field_dnssec_score-value]';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_dnssec_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: IPv6 Score */
  $handler->display->display_options['fields']['field_ipv6_score']['id'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['table'] = 'field_data_field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['field'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['text'] = '[field_ipv6_score-value]';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_ipv6_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 score */
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['id'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['table'] = 'field_data_field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['field'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['text'] = '[field_free_of_insecr_prot_score]';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: M-15-13 and BOD 18-01 Compliance Score */
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['id'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['table'] = 'field_data_field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['field'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['text'] = '[field_m15_13_compliance_score]';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Overall Score';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == \'\')
  $noitems = 5;
else
 $noitems = 6;
$totscore =  $data->field_field_dap_score[\'0\'][\'raw\'][\'value\']+$data->field_field_https_score[\'0\'][\'raw\'][\'value\']+$data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']+$data->field_field_dnssec_score[\'0\'][\'raw\'][\'value\']+$data->field_field_ipv6_score[\'0\'][\'raw\'][\'value\']+$data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'];
print round($totscore/$noitems);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'body' => 'body',
  );
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Filter By Agency';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Domain-Wide Reports';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'datatables';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_website_id' => 'field_website_id',
    'nid' => 'nid',
    'field_https_scan_node' => 'field_https_scan_node',
    'field_domain_scan_node' => 'field_domain_scan_node',
    'field_mobile_scan_node' => 'field_mobile_scan_node',
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'field_parent_agency_name' => 'field_parent_agency_name',
    'field_dap_score' => 'field_dap_score',
    'php_1' => 'php_1',
    'field_https_score' => 'field_https_score',
    'field_mobile_overall_score' => 'field_mobile_overall_score',
    'field_mobile_performance_score' => 'field_mobile_performance_score',
    'field_mobile_usability_score' => 'field_mobile_usability_score',
    'field_site_speed_score' => 'field_site_speed_score',
    'field_dnssec_score' => 'field_dnssec_score',
    'field_ipv6_score' => 'field_ipv6_score',
    'field_compl_m_15_13_bod' => 'field_compl_m_15_13_bod',
    'field_free_of_rc4_3des_and_sslv2' => 'field_free_of_rc4_3des_and_sslv2',
    'field_free_of_insecr_prot_score' => 'field_free_of_insecr_prot_score',
    'field_m15_13_compliance_score' => 'field_m15_13_compliance_score',
    'php_2' => 'php_2',
    'php_3' => 'php_3',
    'php' => 'php',
    'php_5' => 'php_5',
    'php_4' => 'php_4',
    'php_6' => 'php_6',
    'php_7' => 'php_7',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_website_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_https_scan_node' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_domain_scan_node' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_scan_node' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_web_agency_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parent_agency_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dap_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_https_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_overall_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_performance_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_usability_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_speed_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dnssec_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ipv6_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_compl_m_15_13_bod' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_free_of_rc4_3des_and_sslv2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_free_of_insecr_prot_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_m15_13_compliance_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_3' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_5' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_4' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_6' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_7' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['elements'] = array(
    'search_box' => 1,
    'table_info' => 1,
    'save_state' => 1,
    'table_tools' => 1,
  );
  $handler->display->display_options['style_options']['layout'] = array(
    'autowidth' => 0,
    'themeroller' => 0,
    'sdom' => '',
  );
  $handler->display->display_options['style_options']['pages'] = array(
    'pagination_style' => 'full_numbers',
    'length_change' => 1,
    'display_length' => '25',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p style="display:inline">Download Domain Wide Reports: </p><a href="/download/website/all/reports/csv">csv</a><p style="display:inline"> | </p><a href="/download/website/all/reports/xls">xls</a>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Sorry there are no results for your search, please reset the filters and search again';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Website ID (field_website_id) - reverse */
  $handler->display->display_options['relationships']['reverse_field_website_id_node']['id'] = 'reverse_field_website_id_node';
  $handler->display->display_options['relationships']['reverse_field_website_id_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_website_id_node']['field'] = 'reverse_field_website_id_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] <a href=\'https://[title]\' target=\'_new\'> <img src=\'/sites/all/themes/dotgov/images/external-link-symbol.png\' alt="Hyperlink icon"></a>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_nid';
  /* Field: Content: Parent Agency Name */
  $handler->display->display_options['fields']['field_parent_agency_name']['id'] = 'field_parent_agency_name';
  $handler->display->display_options['fields']['field_parent_agency_name']['table'] = 'field_data_field_parent_agency_name';
  $handler->display->display_options['fields']['field_parent_agency_name']['field'] = 'field_parent_agency_name';
  $handler->display->display_options['fields']['field_parent_agency_name']['label'] = 'Agency Name';
  $handler->display->display_options['fields']['field_parent_agency_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_parent_agency_name']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id]';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'DAP Score';
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == "")
print "<span title=\'Not Available\'>-</span>";
else
print $data->field_field_dap_score[\'0\'][\'raw\'][\'value\'];
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['text'] = '[field_https_score-value]';
  $handler->display->display_options['fields']['field_https_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_https_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['text'] = '[field_mobile_overall_score-value]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['text'] = '[field_mobile_performance_score-value]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['text'] = '[field_mobile_usability_score-value] ';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Site Speed Score */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['text'] = '[field_site_speed_score-value]';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['field_site_speed_score']['empty'] = '<span title=\'Not Available\'>-</span>';
  $handler->display->display_options['fields']['field_site_speed_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: DNSSEC Score */
  $handler->display->display_options['fields']['field_dnssec_score']['id'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['table'] = 'field_data_field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['field'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['text'] = '[field_dnssec_score-value]';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['field_dnssec_score']['empty'] = '<span title=\'Not Available\'>-</span>';
  $handler->display->display_options['fields']['field_dnssec_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_dnssec_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: IPv6 Score */
  $handler->display->display_options['fields']['field_ipv6_score']['id'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['table'] = 'field_data_field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['field'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['text'] = '[field_ipv6_score-value]';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['field_ipv6_score']['empty'] = '<span title=\'Not Available\'>-</span>';
  $handler->display->display_options['fields']['field_ipv6_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ipv6_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Compliant with M-15-13 and BOD 18-01	 */
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['id'] = 'field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['table'] = 'field_data_field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['field'] = 'field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['exclude'] = TRUE;
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 */
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['id'] = 'field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['table'] = 'field_data_field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['field'] = 'field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['exclude'] = TRUE;
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 score */
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['id'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['table'] = 'field_data_field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['field'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['text'] = '[field_free_of_insecr_prot_score]';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: M-15-13 and BOD 18-01 Compliance Score */
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['id'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['table'] = 'field_data_field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['field'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['text'] = '[field_m15_13_compliance_score]';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Free of RC4/3DES and SSLv2/SSLv3 Score';
  $handler->display->display_options['fields']['php_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_2']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
if($data->field_field_free_of_insecr_prot_score[\'0\'][\'raw\'][\'value\'] == NULL){
print "<span title=\'Not Available\'>-</span>";
}
else
print $data->field_field_free_of_insecr_prot_score[\'0\'][\'raw\'][\'value\'] 
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'M-15-13 and BOD 18-01 Compliance Score';
  $handler->display->display_options['fields']['php_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_3']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
if($data->field_field_m15_13_compliance_score[\'0\'][\'raw\'][\'value\'] == NULL){
print "<span title=\'Not Available\'>-</span>";
}
else
print $data->field_field_m15_13_compliance_score[\'0\'][\'raw\'][\'value\'] 
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Overall Score';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == \'\')
  $noitems = 5;
else
 $noitems = 6;
$totscore =  $data->field_field_dap_score[\'0\'][\'raw\'][\'value\']+$data->field_field_https_score[\'0\'][\'raw\'][\'value\']+$data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']+$data->field_field_dnssec_score[\'0\'][\'raw\'][\'value\']+$data->field_field_ipv6_score[\'0\'][\'raw\'][\'value\']+$data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'];
print round($totscore/$noitems);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'HTTPS Score';
  $handler->display->display_options['fields']['php_5']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_5']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
if(($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "-";
}
else{
print $data->field_field_https_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'Mobile Overall Score';
  $handler->display->display_options['fields']['php_4']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_4']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
if(($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "<span title=\'Not Available\'>-</span>";
}
else{
print $data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['label'] = 'Mobile Performance Score';
  $handler->display->display_options['fields']['php_6']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_6']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php
if(($data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] == \'\')){
//print "<span title=\'Not Available\'>-</span>";
print "-";
}
else{
print $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_7']['id'] = 'php_7';
  $handler->display->display_options['fields']['php_7']['table'] = 'views';
  $handler->display->display_options['fields']['php_7']['field'] = 'php';
  $handler->display->display_options['fields']['php_7']['label'] = 'Mobile Usability Score';
  $handler->display->display_options['fields']['php_7']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_7']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_7']['php_output'] = '<?php
if(($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == \'\')){
//print "<span title=\'Not Available\'>-</span>";
print "-";
}
else{
print $data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_7']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_7']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Filter By Agency';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['authcache'] = array(
    'status' => '1',
    'lifespan' => '518400',
    'peruser' => '1',
    'clients' => array(
      'authcache_ajax' => array(
        'status' => '1',
        'weight' => '0',
      ),
      'authcache_esi' => array(
        'status' => '1',
        'weight' => '0',
      ),
    ),
    'fallback' => 'cancel',
    'perpage' => 0,
  );
  $handler->display->display_options['path'] = 'website/all/reports-new';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/agency_home/[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['empty'] = 'N/A';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'DAP Score';
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == "")
print "N/A";
else
print $data->field_field_dap_score[\'0\'][\'raw\'][\'value\'];
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['text'] = '[field_https_score-value]';
  $handler->display->display_options['fields']['field_https_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_https_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['text'] = '[field_mobile_overall_score-value]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['text'] = '[field_mobile_performance_score-value]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['text'] = '[field_mobile_usability_score-value] ';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Site Speed Score */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['text'] = '[field_site_speed_score-value]';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['path'] = '/test';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: DNSSEC Score */
  $handler->display->display_options['fields']['field_dnssec_score']['id'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['table'] = 'field_data_field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['field'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['text'] = '[field_dnssec_score-value]';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_dnssec_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: IPv6 Score */
  $handler->display->display_options['fields']['field_ipv6_score']['id'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['table'] = 'field_data_field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['field'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['text'] = '[field_ipv6_score-value]';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_ipv6_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 score */
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['id'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['table'] = 'field_data_field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['field'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['text'] = '[field_free_of_insecr_prot_score]';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: M-15-13 and BOD 18-01 Compliance Score */
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['id'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['table'] = 'field_data_field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['field'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['text'] = '[field_m15_13_compliance_score]';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Overall Score';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == \'\')
  $noitems = 5;
else
 $noitems = 6;
$totscore =  $data->field_field_dap_score[\'0\'][\'raw\'][\'value\']+$data->field_field_https_score[\'0\'][\'raw\'][\'value\']+$data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']+$data->field_field_dnssec_score[\'0\'][\'raw\'][\'value\']+$data->field_field_ipv6_score[\'0\'][\'raw\'][\'value\']+$data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'];
print round($totscore/$noitems);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';

  /* Display: CSV Data Export */
  $handler = $view->new_display('views_data_export', 'CSV Data Export', 'views_data_export_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Sorry there are no results for your search, please reset the filters and search again';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'DAP Score';
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == "")
print "Not Available";
else
print $data->field_field_dap_score[\'0\'][\'raw\'][\'value\'];
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['text'] = '[field_https_score-value]';
  $handler->display->display_options['fields']['field_https_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_https_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['text'] = '[field_mobile_overall_score-value]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['text'] = '[field_mobile_performance_score-value]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['text'] = '[field_mobile_usability_score-value] ';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Site Speed Score */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['text'] = '[field_site_speed_score-value]';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['path'] = '/test';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: DNSSEC Score */
  $handler->display->display_options['fields']['field_dnssec_score']['id'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['table'] = 'field_data_field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['field'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['text'] = '[field_dnssec_score-value]';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_dnssec_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: IPv6 Score */
  $handler->display->display_options['fields']['field_ipv6_score']['id'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['table'] = 'field_data_field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['field'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['text'] = '[field_ipv6_score-value]';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_ipv6_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 score */
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['id'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['table'] = 'field_data_field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['field'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: M-15-13 and BOD 18-01 Compliance Score */
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['id'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['table'] = 'field_data_field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['field'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 */
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['id'] = 'field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['table'] = 'field_data_field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['field'] = 'field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['exclude'] = TRUE;
  /* Field: Content: Compliant with M-15-13 and BOD 18-01	 */
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['id'] = 'field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['table'] = 'field_data_field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['field'] = 'field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Free of RC4/3DES and SSLv2/SSLv3 Score';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
//dsm($data->field_field_free_of_insecr_prot_score);
if(trim($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\']) == \'Yes\'){
print "100";
}
elseif(trim($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\']) == \'No\'){
print "0";
}
elseif($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\'] == NULL){
print "Not Available";
}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'M-15-13 and BOD 18-01 Compliance Score';
  $handler->display->display_options['fields']['php_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
//dsm($data->field_field_free_of_insecr_prot_score);
if(trim($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\']) == \'Yes\'){
print "100";
}
elseif(trim($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\']) == \'No\'){
print "0";
}
elseif($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\'] == NULL){
print "Not Available";
}
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Overall Score';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == \'\')
  $noitems = 5;
else
 $noitems = 6;
$totscore =  $data->field_field_dap_score[\'0\'][\'raw\'][\'value\']+$data->field_field_https_score[\'0\'][\'raw\'][\'value\']+$data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']+$data->field_field_dnssec_score[\'0\'][\'raw\'][\'value\']+$data->field_field_ipv6_score[\'0\'][\'raw\'][\'value\']+$data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'];
print round($totscore/$noitems);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_7']['id'] = 'php_7';
  $handler->display->display_options['fields']['php_7']['table'] = 'views';
  $handler->display->display_options['fields']['php_7']['field'] = 'php';
  $handler->display->display_options['fields']['php_7']['label'] = 'HTTPS Score';
  $handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_7']['php_output'] = '<?php
if(($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_https_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_7']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_7']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'Mobile Overall Score';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
if(($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'Mobile Performance Score';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
if(($data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['label'] = 'Mobile Usability Score';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php
if(($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_8']['id'] = 'php_8';
  $handler->display->display_options['fields']['php_8']['table'] = 'views';
  $handler->display->display_options['fields']['php_8']['field'] = 'php';
  $handler->display->display_options['fields']['php_8']['label'] = 'Site Speed Score';
  $handler->display->display_options['fields']['php_8']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_8']['php_output'] = '<?php
if (($data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'] == "0") || ($data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'] == NULL)  || ($data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'] == \'\'))
print "Not Available";
else
print $data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'];
?>';
  $handler->display->display_options['fields']['php_8']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_8']['php_click_sortable'] = '';
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_uswds_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['path'] = 'download/website/all/reports/csv';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Website-Specific Reports';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'filtered_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_web_agency_id_nid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'Filter By Agency',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '300';
  $handler->display->display_options['pager']['options']['offset'] = '';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_web_agency_id',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_redirect' => 'field_redirect',
    'field_https_scan_node' => 'field_https_scan_node',
    'field_domain_scan_node' => 'field_domain_scan_node',
    'field_mobile_scan_node' => 'field_mobile_scan_node',
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'field_dap_score' => 'field_dap_score',
    'field_site_speed_score' => 'field_site_speed_score',
    'field_dnssec_score' => 'field_dnssec_score',
    'field_ipv6_score' => 'field_ipv6_score',
    'field_free_of_insecr_prot_score' => 'field_free_of_insecr_prot_score',
    'field_m15_13_compliance_score' => 'field_m15_13_compliance_score',
    'field_https_score' => 'field_https_score',
    'php' => 'php',
    'field_uswds_score' => 'field_uswds_score',
    'field_mobile_usability_status' => 'field_mobile_usability_status',
    'field_mobile_performance_status' => 'field_mobile_performance_status',
    'php_1' => 'php_1',
    'php_2' => 'php_2',
    'php_3' => 'php_3',
  );
  $handler->display->display_options['style_options']['default'] = 'field_web_agency_id';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_redirect' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_https_scan_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_domain_scan_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_scan_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_web_agency_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dap_score' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_speed_score' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dnssec_score' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ipv6_score' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_free_of_insecr_prot_score' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_m15_13_compliance_score' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_https_score' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_score' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_usability_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_performance_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_3' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Download Website-Specific Reports: <a href="/download/website/all/reports/csv"> csv </a> | <a href="/download/website/all/reports/xls">xls</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Redirect */
  $handler->display->display_options['fields']['field_redirect']['id'] = 'field_redirect';
  $handler->display->display_options['fields']['field_redirect']['table'] = 'field_data_field_redirect';
  $handler->display->display_options['fields']['field_redirect']['field'] = 'field_redirect';
  $handler->display->display_options['fields']['field_redirect']['exclude'] = TRUE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/agency_home/[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_dap_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_dap_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Site Speed Score */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['path'] = '/test';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_site_speed_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_speed_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: DNSSEC Score */
  $handler->display->display_options['fields']['field_dnssec_score']['id'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['table'] = 'field_data_field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['field'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_dnssec_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_dnssec_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_dnssec_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_dnssec_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: IPv6 Score */
  $handler->display->display_options['fields']['field_ipv6_score']['id'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['table'] = 'field_data_field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['field'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_ipv6_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_ipv6_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_ipv6_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_ipv6_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 score */
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['id'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['table'] = 'field_data_field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['field'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: M-15-13 and BOD 18-01 Compliance Score */
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['id'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['table'] = 'field_data_field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['field'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_https_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_https_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_https_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Site Speed Score';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$node = node_load($data->nid);
if (!empty($node->field_redirect[\'und\'][0][\'value\']) && ($node->field_redirect[\'und\'][0][\'value\'] == \'Yes\')) {
return \'Not Applicable\';
}
elseif (!empty($node->field_site_speed_score[\'und\'][0][\'value\'])) {
return $node->field_site_speed_score[\'und\'][0][\'value\'];
}
else {
return \'0\';
}
';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print $value;

?>
';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '6';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = 'return $row1->php < $row2->php ? -1 : (int) ($row1->php > $row2->php);';
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_uswds_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Status */
  $handler->display->display_options['fields']['field_mobile_usability_status']['id'] = 'field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['table'] = 'field_data_field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['field'] = 'field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_status']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_mobile_usability_status']['type'] = 'text_plain';
  /* Field: Content: Mobile Performance Status */
  $handler->display->display_options['fields']['field_mobile_performance_status']['id'] = 'field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['table'] = 'field_data_field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['field'] = 'field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_status']['empty'] = 'Not Available';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'DAP Score';
  $handler->display->display_options['fields']['php_1']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = '$node = node_load($data->nid);
if (!empty($node->field_redirect[\'und\'][0][\'value\']) && ($node->field_redirect[\'und\'][0][\'value\'] == \'Yes\')) {
return \'Not Applicable\';
}
elseif (!empty($node->field_dap_score[\'und\'][0][\'value\'])) {
return $node->field_dap_score[\'und\'][0][\'value\'];
}
else {
return \'Not Available\';
}
';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print $value;

?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '6';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = 'return $row1->php_1 < $row2->php_1 ? -1 : (int) ($row1->php_1 > $row2->php_1);';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Mobile Usability Status';
  $handler->display->display_options['fields']['php_2']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = '$node = node_load($data->nid);
if (!empty($node->field_redirect[\'und\'][0][\'value\']) && ($node->field_redirect[\'und\'][0][\'value\'] == \'Yes\')) {
return \'Not Applicable\';
}
elseif (!empty($node->field_mobile_usability_status[\'und\'][0][\'value\'])) {
return $node->field_mobile_usability_status[\'und\'][0][\'value\'];
}
else {
return \'Not Available\';
}';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
print $value;

?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '6';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = 'return $row1->php_2 < $row2->php_2 ? -1 : (int) ($row1->php_2 > $row2->php_2);
';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'Mobile Performance Status';
  $handler->display->display_options['fields']['php_3']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = '$node = node_load($data->nid);
if (!empty($node->field_redirect[\'und\'][0][\'value\']) && ($node->field_redirect[\'und\'][0][\'value\'] == \'Yes\')) {
return \'Not Applicable\';
}
elseif (!empty($node->field_mobile_performance_status[\'und\'][\'0\'][\'value\'])) {
return $node->field_mobile_performance_status[\'und\'][0][\'value\'];
}
else {
return \'Not Available\';
}';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
print $value;

?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '6';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = 'return $row1->php_3 < $row2->php_3 ? -1 : (int) ($row1->php_3 > $row2->php_3);';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'body' => 'body',
  );
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Filter By Agency';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['id'] = 'field_web_agency_id_nid_1';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['operator'] = 'not empty';
  $handler->display->display_options['authcache'] = array(
    'status' => '1',
    'lifespan' => '518400',
    'peruser' => '1',
    'clients' => array(
      'authcache_ajax' => array(
        'status' => '1',
        'weight' => '0',
      ),
      'authcache_esi' => array(
        'status' => '1',
        'weight' => '0',
      ),
    ),
    'fallback' => 'cancel',
    'perpage' => 0,
  );
  $handler->display->display_options['path'] = 'website/all/reports-new';

  /* Display: XLS Data Export */
  $handler = $view->new_display('views_data_export', 'XLS Data Export', 'views_data_export_5');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Sorry there are no results for your search, please reset the filters and search again';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'DAP Score';
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == "")
print "Not Available";
else
print $data->field_field_dap_score[\'0\'][\'raw\'][\'value\'];
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['text'] = '[field_https_score-value]';
  $handler->display->display_options['fields']['field_https_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_https_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['text'] = '[field_mobile_overall_score-value]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['text'] = '[field_mobile_performance_score-value]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['text'] = '[field_mobile_usability_score-value] ';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Site Speed Score */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['text'] = '[field_site_speed_score-value]';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['path'] = '/test';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: DNSSEC Score */
  $handler->display->display_options['fields']['field_dnssec_score']['id'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['table'] = 'field_data_field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['field'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['text'] = '[field_dnssec_score-value]';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_dnssec_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: IPv6 Score */
  $handler->display->display_options['fields']['field_ipv6_score']['id'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['table'] = 'field_data_field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['field'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['text'] = '[field_ipv6_score-value]';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_ipv6_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 score */
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['id'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['table'] = 'field_data_field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['field'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: M-15-13 and BOD 18-01 Compliance Score */
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['id'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['table'] = 'field_data_field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['field'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 */
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['id'] = 'field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['table'] = 'field_data_field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['field'] = 'field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['exclude'] = TRUE;
  /* Field: Content: Compliant with M-15-13 and BOD 18-01	 */
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['id'] = 'field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['table'] = 'field_data_field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['field'] = 'field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Free of RC4/3DES and SSLv2/SSLv3 Score';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
//dsm($data->field_field_free_of_insecr_prot_score);
if(trim($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\']) == \'Yes\'){
print "100";
}
elseif(trim($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\']) == \'No\'){
print "0";
}
elseif($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\'] == NULL){
print "Not Available";
}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'M-15-13 and BOD 18-01 Compliance Score';
  $handler->display->display_options['fields']['php_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
//dsm($data->field_field_free_of_insecr_prot_score);
if(trim($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\']) == \'Yes\'){
print "100";
}
elseif(trim($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\']) == \'No\'){
print "0";
}
elseif($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\'] == NULL){
print "Not Available";
}
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Overall Score';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == \'\')
  $noitems = 5;
else
 $noitems = 6;
$totscore =  $data->field_field_dap_score[\'0\'][\'raw\'][\'value\']+$data->field_field_https_score[\'0\'][\'raw\'][\'value\']+$data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']+$data->field_field_dnssec_score[\'0\'][\'raw\'][\'value\']+$data->field_field_ipv6_score[\'0\'][\'raw\'][\'value\']+$data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'];
print round($totscore/$noitems);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_7']['id'] = 'php_7';
  $handler->display->display_options['fields']['php_7']['table'] = 'views';
  $handler->display->display_options['fields']['php_7']['field'] = 'php';
  $handler->display->display_options['fields']['php_7']['label'] = 'HTTPS Score';
  $handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_7']['php_output'] = '<?php
if(($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_https_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_7']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_7']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'Mobile Overall Score';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
if(($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'Mobile Performance Score';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
if(($data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['label'] = 'Mobile Usability Score';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php
if(($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_8']['id'] = 'php_8';
  $handler->display->display_options['fields']['php_8']['table'] = 'views';
  $handler->display->display_options['fields']['php_8']['field'] = 'php';
  $handler->display->display_options['fields']['php_8']['label'] = 'Site Speed Score';
  $handler->display->display_options['fields']['php_8']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_8']['php_output'] = '<?php
if (($data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'] == "0") || ($data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'] == NULL)  || ($data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'] == \'\'))
print "Not Available";
else
print $data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'];
?>';
  $handler->display->display_options['fields']['php_8']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_8']['php_click_sortable'] = '';
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_uswds_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['path'] = 'download/website/all/reports/xls';

  /* Display: Agency-Wide Mobile Reports */
  $handler = $view->new_display('page', 'Agency-Wide Mobile Reports', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Agency-Wide Mobile Reports';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'datatables';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_mobile_scan_node' => 'field_mobile_scan_node',
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'field_mobile_overall_score' => 'field_mobile_overall_score',
    'field_mobile_performance_score' => 'field_mobile_performance_score',
    'field_mobile_usability_score' => 'field_mobile_usability_score',
    'field_site_speed_score' => 'field_site_speed_score',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_scan_node' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_web_agency_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_overall_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_performance_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_usability_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_speed_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['elements'] = array(
    'search_box' => 1,
    'table_info' => 1,
    'save_state' => 0,
    'table_tools' => 0,
  );
  $handler->display->display_options['style_options']['layout'] = array(
    'autowidth' => 0,
    'themeroller' => 0,
    'sdom' => '',
  );
  $handler->display->display_options['style_options']['pages'] = array(
    'pagination_style' => 'full_numbers',
    'length_change' => 0,
    'display_length' => '25',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Download Agency-Wide Mobile Reports: <a href="/download/website/mobile/reports/csv">csv</a> | <a href="/download/website/mobile/reports/xls">xls</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/agency_home/[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['path'] = '/website/[nid]/information';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_mobile_overall_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_mobile_performance_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_mobile_usability_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Site Speed Score */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['path'] = '/test';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_site_speed_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_site_speed_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Mobile Score Rating';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if(trim($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']) == \'\'){
$score = "NA";
}
else
$score = round($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']);
if($score ==  \'NA\') print \'NA\';
elseif ($score < 50) print \'Slow\';
elseif ($score < 90) print \'Moderate\';
else print \'Fast\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Filter By Agency';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['id'] = 'field_web_agency_id_nid_1';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'website/mobile/reports-old';

  /* Display: CSV Mobile Data Export */
  $handler = $view->new_display('views_data_export', 'CSV Mobile Data Export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Sorry there are no results for your search, please reset the filters and search again';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['text'] = '[field_mobile_overall_score-value]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['text'] = '[field_mobile_performance_score-value]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['text'] = '[field_mobile_usability_score-value] ';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Overall Score';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == \'\')
  $noitems = 5;
else
 $noitems = 6;
$totscore =  $data->field_field_dap_score[\'0\'][\'raw\'][\'value\']+$data->field_field_https_score[\'0\'][\'raw\'][\'value\']+$data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']+$data->field_field_dnssec_score[\'0\'][\'raw\'][\'value\']+$data->field_field_ipv6_score[\'0\'][\'raw\'][\'value\']+$data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'];
print round($totscore/$noitems);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'Mobile Overall Score';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
if(($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'Mobile Performance Score';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
if(($data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['label'] = 'Mobile Usability Score';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php
if(($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Field: Content: Site Speed Score */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['text'] = '[field_site_speed_score-value]';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['path'] = '/test';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Mobile Score Rating';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if(trim($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']) == \'\'){
$score = "NA";
}
else
$score = round($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']);
if($score ==  \'NA\') print \'NA\';
elseif ($score < 50) print \'Slow\';
elseif ($score < 90) print \'Moderate\';
else print \'Fast\';
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['path'] = 'download/website/mobile/reports/csv-old';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: XLS Mobile Data Export */
  $handler = $view->new_display('views_data_export', 'XLS Mobile Data Export', 'views_data_export_3');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Sorry there are no results for your search, please reset the filters and search again';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['text'] = '[field_mobile_overall_score-value]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['text'] = '[field_mobile_performance_score-value]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['text'] = '[field_mobile_usability_score-value] ';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Overall Score';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == \'\')
  $noitems = 5;
else
 $noitems = 6;
$totscore =  $data->field_field_dap_score[\'0\'][\'raw\'][\'value\']+$data->field_field_https_score[\'0\'][\'raw\'][\'value\']+$data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']+$data->field_field_dnssec_score[\'0\'][\'raw\'][\'value\']+$data->field_field_ipv6_score[\'0\'][\'raw\'][\'value\']+$data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'];
print round($totscore/$noitems);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'Mobile Overall Score';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
if(($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'Mobile Performance Score';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
if(($data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['label'] = 'Mobile Usability Score';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php
if(($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Field: Content: Site Speed Score */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['text'] = '[field_site_speed_score-value]';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['path'] = '/test';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Mobile Score Rating';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if(trim($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']) == \'\'){
$score = "NA";
}
else
$score = round($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']);
if($score ==  \'NA\') print \'NA\';
elseif ($score < 50) print \'Slow\';
elseif ($score < 90) print \'Moderate\';
else print \'Fast\';
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['path'] = 'download/website/mobile/reports/xls-old';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Search Engine Page */
  $handler = $view->new_display('page', 'Search Engine Page', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search Engine Page';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_https_scan_node' => 'field_https_scan_node',
    'field_domain_scan_node' => 'field_domain_scan_node',
    'field_mobile_scan_node' => 'field_mobile_scan_node',
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'field_search_engine_name' => 'field_search_engine_name',
    'field_search_status' => 'field_search_status',
    'php' => 'php',
    'php_1' => 'php_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_https_scan_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_domain_scan_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_scan_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_web_agency_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_search_engine_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_search_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['caption'] = 'On-Site Search Reports';
  $handler->display->display_options['style_options']['summary'] = 'On-Site Search Reports';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p style="display:inline;float:right;font-size:16px;">Download Website On-Site Search Reports: <a href="/download/website/search/reports/csv">csv</a> | <a href="/download/website/search/reports/xls">xls</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/agency_home/[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: Search Engine Name */
  $handler->display->display_options['fields']['field_search_engine_name']['id'] = 'field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['table'] = 'field_data_field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['field'] = 'field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['label'] = 'On-Site Search Engine Name';
  $handler->display->display_options['fields']['field_search_engine_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_search_engine_name']['empty'] = 'Not Available';
  /* Field: Content: Search Status */
  $handler->display->display_options['fields']['field_search_status']['id'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['table'] = 'field_data_field_search_status';
  $handler->display->display_options['fields']['field_search_status']['field'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['label'] = 'On-Site Search Status';
  $handler->display->display_options['fields']['field_search_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_search_status']['empty'] = 'Not Available';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'On-Site Search Status';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_search_status[\'0\'][\'raw\'][\'value\'] == ""){
print "Not Applicable";
}
else 
print $data->field_field_search_status[\'0\'][\'rendered\'][\'#markup\'];
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'On-Site Search Engine Name';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if($data->field_field_search_status[\'0\'][\'raw\'][\'value\'] == ""){
print "Not Applicable";
}
else {
if($data->field_field_search_engine_name[\'0\'][\'raw\'][\'value\'] == "")
print "Not Available";
else
print $data->field_field_search_engine_name[\'0\'][\'rendered\'][\'#markup\'];
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'body' => 'body',
  );
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['group'] = 1;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Filter By Agency';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['id'] = 'field_web_agency_id_nid_1';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'website/search/reports';

  /* Display: My Agency Search Engine Page */
  $handler = $view->new_display('page', 'My Agency Search Engine Page', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Website On-Site Search Reports';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_https_scan_node' => 'field_https_scan_node',
    'field_domain_scan_node' => 'field_domain_scan_node',
    'field_mobile_scan_node' => 'field_mobile_scan_node',
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'field_search_engine_name' => 'field_search_engine_name',
    'field_search_status' => 'field_search_status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_https_scan_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_domain_scan_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_scan_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_web_agency_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_search_engine_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_search_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/agency_home/[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: Search Engine Name */
  $handler->display->display_options['fields']['field_search_engine_name']['id'] = 'field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['table'] = 'field_data_field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['field'] = 'field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['label'] = 'On-Site Search Engine Name';
  $handler->display->display_options['fields']['field_search_engine_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_search_engine_name']['empty'] = 'Not Available';
  /* Field: Content: Search Status */
  $handler->display->display_options['fields']['field_search_status']['id'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['table'] = 'field_data_field_search_status';
  $handler->display->display_options['fields']['field_search_status']['field'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['label'] = 'On-Site Search Status';
  $handler->display->display_options['fields']['field_search_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_search_status']['empty'] = 'Not Available';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'On-Site Search Status';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_search_status[\'0\'][\'raw\'][\'value\'] == ""){
print "Not Applicable";
}
else 
print $data->field_field_search_status[\'0\'][\'rendered\'][\'#markup\'];
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'On-Site Search Engine Name';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if($data->field_field_search_status[\'0\'][\'raw\'][\'value\'] == ""){
print "Not Applicable";
}
else {
if($data->field_field_search_engine_name[\'0\'][\'raw\'][\'value\'] == "")
print "Not Available";
else
print $data->field_field_search_engine_name[\'0\'][\'rendered\'][\'#markup\'];
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_argument_options']['code'] = 'global $user;
$user_data = user_load($user->uid);
return $user_data->field_web_agency_id[\'und\'][0][\'nid\'];';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'body' => 'body',
  );
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['id'] = 'field_web_agency_id_nid_1';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'myagency/search/reports';

  /* Display: Search Engine Page Csv Export */
  $handler = $view->new_display('views_data_export', 'Search Engine Page Csv Export', 'views_data_export_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search Engine Page Csv Export';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'search_engine_%view.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: Search Engine Name */
  $handler->display->display_options['fields']['field_search_engine_name']['id'] = 'field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['table'] = 'field_data_field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['field'] = 'field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['label'] = 'On-Site Search Engine Name';
  $handler->display->display_options['fields']['field_search_engine_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_search_engine_name']['empty'] = 'Not Available';
  /* Field: Content: Search Status */
  $handler->display->display_options['fields']['field_search_status']['id'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['table'] = 'field_data_field_search_status';
  $handler->display->display_options['fields']['field_search_status']['field'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['label'] = 'On-Site Search Status';
  $handler->display->display_options['fields']['field_search_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_search_status']['empty'] = 'Not Available';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'On-Site Search Status';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_search_status[\'0\'][\'raw\'][\'value\'] == ""){
print "Not Applicable";
}
else 
print $data->field_field_search_status[\'0\'][\'rendered\'][\'#markup\'];
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'On-Site Search Engine Name';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if($data->field_field_search_status[\'0\'][\'raw\'][\'value\'] == ""){
print "Not Applicable";
}
else {
if($data->field_field_search_engine_name[\'0\'][\'raw\'][\'value\'] == "")
print "Not Available";
else
print $data->field_field_search_engine_name[\'0\'][\'rendered\'][\'#markup\'];
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['path'] = 'download/website/search/reports/csv';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Search Engine Page Xls Export */
  $handler = $view->new_display('views_data_export', 'Search Engine Page Xls Export', 'views_data_export_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search Engine Page Xls Export';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: Search Engine Name */
  $handler->display->display_options['fields']['field_search_engine_name']['id'] = 'field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['table'] = 'field_data_field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['field'] = 'field_search_engine_name';
  $handler->display->display_options['fields']['field_search_engine_name']['label'] = 'On-Site Search Engine Name';
  $handler->display->display_options['fields']['field_search_engine_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_search_engine_name']['empty'] = 'Not Available';
  /* Field: Content: Search Status */
  $handler->display->display_options['fields']['field_search_status']['id'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['table'] = 'field_data_field_search_status';
  $handler->display->display_options['fields']['field_search_status']['field'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['label'] = 'On-Site Search Status';
  $handler->display->display_options['fields']['field_search_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_search_status']['empty'] = 'Not Available';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'On-Site Search Status';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_search_status[\'0\'][\'raw\'][\'value\'] == ""){
print "Not Applicable";
}
else 
print $data->field_field_search_status[\'0\'][\'rendered\'][\'#markup\'];
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'On-Site Search Engine Name';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if($data->field_field_search_status[\'0\'][\'raw\'][\'value\'] == ""){
print "Not Applicable";
}
else {
if($data->field_field_search_engine_name[\'0\'][\'raw\'][\'value\'] == "")
print "Not Available";
else
print $data->field_field_search_engine_name[\'0\'][\'rendered\'][\'#markup\'];
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['path'] = 'download/website/search/reports/xls';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: XLS Data Export */
  $handler = $view->new_display('views_data_export', 'XLS Data Export', 'views_data_export_9');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Sorry there are no results for your search, please reset the filters and search again';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Redirect */
  $handler->display->display_options['fields']['field_redirect']['id'] = 'field_redirect';
  $handler->display->display_options['fields']['field_redirect']['table'] = 'field_data_field_redirect';
  $handler->display->display_options['fields']['field_redirect']['field'] = 'field_redirect';
  $handler->display->display_options['fields']['field_redirect']['exclude'] = TRUE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'DAP Score';
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = '$node = node_load($data->nid);
if (!empty($node->field_redirect[\'und\'][0][\'value\']) && ($node->field_redirect[\'und\'][0][\'value\'] == \'Yes\')) {
return \'Not Applicable\';
}
elseif (!empty($node->field_dap_score[\'und\'][0][\'value\'])) {
return $node->field_dap_score[\'und\'][0][\'value\'];
}
else {
return \'Not Available\';
}
';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print $value;

?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['text'] = '[field_https_score-value]';
  $handler->display->display_options['fields']['field_https_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_https_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['text'] = '[field_mobile_overall_score-value]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['text'] = '[field_mobile_performance_score-value]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['text'] = '[field_mobile_usability_score-value] ';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Site Speed Score */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['text'] = '[field_site_speed_score-value]';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['path'] = '/test';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: DNSSEC Score */
  $handler->display->display_options['fields']['field_dnssec_score']['id'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['table'] = 'field_data_field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['field'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['text'] = '[field_dnssec_score-value]';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_dnssec_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: IPv6 Score */
  $handler->display->display_options['fields']['field_ipv6_score']['id'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['table'] = 'field_data_field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['field'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['text'] = '[field_ipv6_score-value]';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_ipv6_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 score */
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['id'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['table'] = 'field_data_field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['field'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: M-15-13 and BOD 18-01 Compliance Score */
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['id'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['table'] = 'field_data_field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['field'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 */
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['id'] = 'field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['table'] = 'field_data_field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['field'] = 'field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['exclude'] = TRUE;
  /* Field: Content: Compliant with M-15-13 and BOD 18-01	 */
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['id'] = 'field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['table'] = 'field_data_field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['field'] = 'field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Free of RC4/3DES and SSLv2/SSLv3 Score';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
//dsm($data->field_field_free_of_insecr_prot_score);
if(trim($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\']) == \'Yes\'){
print "100";
}
elseif(trim($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\']) == \'No\'){
print "0";
}
elseif($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\'] == NULL){
print "Not Available";
}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'M-15-13 and BOD 18-01 Compliance Score';
  $handler->display->display_options['fields']['php_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
//dsm($data->field_field_free_of_insecr_prot_score);
if(trim($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\']) == \'Yes\'){
print "100";
}
elseif(trim($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\']) == \'No\'){
print "0";
}
elseif($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\'] == NULL){
print "Not Available";
}
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Overall Score';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == \'\')
  $noitems = 5;
else
 $noitems = 6;
$totscore =  $data->field_field_dap_score[\'0\'][\'raw\'][\'value\']+$data->field_field_https_score[\'0\'][\'raw\'][\'value\']+$data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']+$data->field_field_dnssec_score[\'0\'][\'raw\'][\'value\']+$data->field_field_ipv6_score[\'0\'][\'raw\'][\'value\']+$data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'];
print round($totscore/$noitems);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_7']['id'] = 'php_7';
  $handler->display->display_options['fields']['php_7']['table'] = 'views';
  $handler->display->display_options['fields']['php_7']['field'] = 'php';
  $handler->display->display_options['fields']['php_7']['label'] = 'HTTPS Score';
  $handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_7']['php_output'] = '<?php
if(($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_https_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_7']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_7']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'Mobile Overall Score';
  $handler->display->display_options['fields']['php_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
if($data->field_field_redirect[\'0\'][\'raw\'][\'value\'] == "Yes"){
print "Not Applicable";
}
else{
if(($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'];
}
}
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'Mobile Performance Status';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
if($data->field_field_redirect[\'0\'][\'raw\'][\'value\'] == "Yes"){
print "Not Applicable";
}
else{
if("0" <= $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] && $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] < "50"){
print "Poor";
}
elseif ("49" < $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] && $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] < "90"){
print \'Needs Improvement\';
}
elseif ("89" < $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] && $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] <= "100"){
print \'Good\';
}
else print \'Not Available\';
}
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['label'] = 'Mobile Usability Status';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php
if($data->field_field_redirect[\'0\'][\'raw\'][\'value\'] == "Yes"){
print "Not Applicable";
}
else{
if($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == "100"){
print "Mobile Friendly";
}
elseif ($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == "0"){
print \'Not Mobile Friendly\';
}
else print \'Not Available\';
}
?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_8']['id'] = 'php_8';
  $handler->display->display_options['fields']['php_8']['table'] = 'views';
  $handler->display->display_options['fields']['php_8']['field'] = 'php';
  $handler->display->display_options['fields']['php_8']['label'] = 'Site Speed Score';
  $handler->display->display_options['fields']['php_8']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_8']['php_value'] = '$node = node_load($data->nid);
if (!empty($node->field_redirect[\'und\'][0][\'value\']) && ($node->field_redirect[\'und\'][0][\'value\'] == \'Yes\')) {
return \'Not Applicable\';
}
elseif (!empty($node->field_site_speed_score[\'und\'][0][\'value\'])) {
return $node->field_site_speed_score[\'und\'][0][\'value\'];
}
else {
return \'0\';
}
';
  $handler->display->display_options['fields']['php_8']['php_output'] = '<?php
print $value;

?>
';
  $handler->display->display_options['fields']['php_8']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_8']['php_click_sortable'] = '';
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_uswds_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['path'] = 'download/website/all/reports/xls';

  /* Display: CSV Data Export */
  $handler = $view->new_display('views_data_export', 'CSV Data Export', 'views_data_export_10');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Sorry there are no results for your search, please reset the filters and search again';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_website_id_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Redirect */
  $handler->display->display_options['fields']['field_redirect']['id'] = 'field_redirect';
  $handler->display->display_options['fields']['field_redirect']['table'] = 'field_data_field_redirect';
  $handler->display->display_options['fields']['field_redirect']['field'] = 'field_redirect';
  $handler->display->display_options['fields']['field_redirect']['exclude'] = TRUE;
  /* Field: Content: HTTPS Scan Node */
  $handler->display->display_options['fields']['field_https_scan_node']['id'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['table'] = 'field_data_field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['field'] = 'field_https_scan_node';
  $handler->display->display_options['fields']['field_https_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_https_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Domain Scan Node */
  $handler->display->display_options['fields']['field_domain_scan_node']['id'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['table'] = 'field_data_field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['field'] = 'field_domain_scan_node';
  $handler->display->display_options['fields']['field_domain_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_domain_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_domain_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Mobile Scan node */
  $handler->display->display_options['fields']['field_mobile_scan_node']['id'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['table'] = 'field_data_field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['field'] = 'field_mobile_scan_node';
  $handler->display->display_options['fields']['field_mobile_scan_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_scan_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_mobile_scan_node']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'DAP Score';
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = '$node = node_load($data->nid);
if (!empty($node->field_redirect[\'und\'][0][\'value\']) && ($node->field_redirect[\'und\'][0][\'value\'] == \'Yes\')) {
return \'Not Applicable\';
}
elseif (!empty($node->field_dap_score[\'und\'][0][\'value\'])) {
return $node->field_dap_score[\'und\'][0][\'value\'];
}
else {
return \'Not Available\';
}
';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print $value;

?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['text'] = '[field_https_score-value]';
  $handler->display->display_options['fields']['field_https_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_https_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['text'] = '[field_mobile_overall_score-value]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_overall_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['text'] = '[field_mobile_performance_score-value]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_performance_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['text'] = '[field_mobile_usability_score-value] ';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['path'] = '/node/[field_mobile_scan_node]';
  $handler->display->display_options['fields']['field_mobile_usability_score']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Site Speed Score */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['text'] = '[field_site_speed_score-value]';
  $handler->display->display_options['fields']['field_site_speed_score']['alter']['path'] = '/test';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: DNSSEC Score */
  $handler->display->display_options['fields']['field_dnssec_score']['id'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['table'] = 'field_data_field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['field'] = 'field_dnssec_score';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['text'] = '[field_dnssec_score-value]';
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_dnssec_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_dnssec_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: IPv6 Score */
  $handler->display->display_options['fields']['field_ipv6_score']['id'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['table'] = 'field_data_field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['field'] = 'field_ipv6_score';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['text'] = '[field_ipv6_score-value]';
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ipv6_score']['alter']['path'] = '/node/[field_domain_scan_node]';
  $handler->display->display_options['fields']['field_ipv6_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 score */
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['id'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['table'] = 'field_data_field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['field'] = 'field_free_of_insecr_prot_score';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_free_of_insecr_prot_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: M-15-13 and BOD 18-01 Compliance Score */
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['id'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['table'] = 'field_data_field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['field'] = 'field_m15_13_compliance_score';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['alter']['path'] = '/node/[field_https_scan_node]';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_m15_13_compliance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Free of RC4/3DES and SSLv2/SSLv3 */
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['id'] = 'field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['table'] = 'field_data_field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['field'] = 'field_free_of_rc4_3des_and_sslv2';
  $handler->display->display_options['fields']['field_free_of_rc4_3des_and_sslv2']['exclude'] = TRUE;
  /* Field: Content: Compliant with M-15-13 and BOD 18-01	 */
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['id'] = 'field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['table'] = 'field_data_field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['field'] = 'field_compl_m_15_13_bod';
  $handler->display->display_options['fields']['field_compl_m_15_13_bod']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Free of RC4/3DES and SSLv2/SSLv3 Score';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
//dsm($data->field_field_free_of_insecr_prot_score);
if(trim($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\']) == \'Yes\'){
print "100";
}
elseif(trim($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\']) == \'No\'){
print "0";
}
elseif($data->field_field_free_of_rc4_3des_and_sslv2[\'0\'][\'raw\'][\'value\'] == NULL){
print "Not Available";
}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'M-15-13 and BOD 18-01 Compliance Score';
  $handler->display->display_options['fields']['php_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
//dsm($data->field_field_free_of_insecr_prot_score);
if(trim($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\']) == \'Yes\'){
print "100";
}
elseif(trim($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\']) == \'No\'){
print "0";
}
elseif($data->field_field_compl_m_15_13_bod[\'0\'][\'raw\'][\'value\'] == NULL){
print "Not Available";
}
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Overall Score';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == \'\')
  $noitems = 5;
else
 $noitems = 6;
$totscore =  $data->field_field_dap_score[\'0\'][\'raw\'][\'value\']+$data->field_field_https_score[\'0\'][\'raw\'][\'value\']+$data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']+$data->field_field_dnssec_score[\'0\'][\'raw\'][\'value\']+$data->field_field_ipv6_score[\'0\'][\'raw\'][\'value\']+$data->field_field_site_speed_score[\'0\'][\'raw\'][\'value\'];
print round($totscore/$noitems);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_7']['id'] = 'php_7';
  $handler->display->display_options['fields']['php_7']['table'] = 'views';
  $handler->display->display_options['fields']['php_7']['field'] = 'php';
  $handler->display->display_options['fields']['php_7']['label'] = 'HTTPS Score';
  $handler->display->display_options['fields']['php_7']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_7']['php_output'] = '<?php
if(($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_https_score[\'0\'][\'raw\'][\'value\'];
}
?>';
  $handler->display->display_options['fields']['php_7']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_7']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'Mobile Overall Score';
  $handler->display->display_options['fields']['php_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
if($data->field_field_redirect[\'0\'][\'raw\'][\'value\'] == "Yes"){
print "Not Applicable";
}
else{
if(($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == NULL) || ($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'] == \'\')){
print "Not Available";
}
else{
print $data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\'];
}
}
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'Mobile Performance Status';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
if($data->field_field_redirect[\'0\'][\'raw\'][\'value\'] == "Yes"){
print "Not Applicable";
}
else{
if("0" <= $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] && $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] < "50"){
print "Poor";
}
elseif ("49" < $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] && $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] < "90"){
print \'Needs Improvement\';
}
elseif ("89" < $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] && $data->field_field_mobile_performance_score[\'0\'][\'raw\'][\'value\'] <= "100"){
print \'Good\';
}
else print \'Not Available\';
}
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_6']['id'] = 'php_6';
  $handler->display->display_options['fields']['php_6']['table'] = 'views';
  $handler->display->display_options['fields']['php_6']['field'] = 'php';
  $handler->display->display_options['fields']['php_6']['label'] = 'Mobile Usability Status';
  $handler->display->display_options['fields']['php_6']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_6']['php_output'] = '<?php
if($data->field_field_redirect[\'0\'][\'raw\'][\'value\'] == "Yes"){
print "Not Applicable";
}
else{
if($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == "100"){
print "Mobile Friendly";
}
elseif ($data->field_field_mobile_usability_score[\'0\'][\'raw\'][\'value\'] == "0"){
print \'Not Mobile Friendly\';
}
else print \'Not Available\';
}
?>';
  $handler->display->display_options['fields']['php_6']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php_6']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_8']['id'] = 'php_8';
  $handler->display->display_options['fields']['php_8']['table'] = 'views';
  $handler->display->display_options['fields']['php_8']['field'] = 'php';
  $handler->display->display_options['fields']['php_8']['label'] = 'Site Speed Score';
  $handler->display->display_options['fields']['php_8']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_8']['php_value'] = '$node = node_load($data->nid);
if (!empty($node->field_redirect[\'und\'][0][\'value\']) && ($node->field_redirect[\'und\'][0][\'value\'] == \'Yes\')) {
return \'Not Applicable\';
}
elseif (!empty($node->field_site_speed_score[\'und\'][0][\'value\'])) {
return $node->field_site_speed_score[\'und\'][0][\'value\'];
}
else {
return \'0\';
}
';
  $handler->display->display_options['fields']['php_8']['php_output'] = '<?php
print $value;

?>
';
  $handler->display->display_options['fields']['php_8']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_8']['php_click_sortable'] = '';
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_uswds_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'website' => 'website',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['path'] = 'download/website/all/reports/csv';
  $export['all_website_reports_new'] = $view;

  return $export;
}
