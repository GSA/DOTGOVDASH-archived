<?php

/**
 * @file
 * 21st_century_idea_act.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function 21st_century_idea_act_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = '21st_century_idea_act_agency_wide_reports';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'custom_agencywide_archive';
  $view->human_name = '21st Century IDEA Act Agency-Wide Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '21st Century IDEA Act Agency-Wide Reports';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Custom Table Views: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['id']['field'] = 'id';

  /* Display: 21st Century IDEA Act Agency-Wide Reports */
  $handler = $view->new_display('page', '21st Century IDEA Act Agency-Wide Reports', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'white-back';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
  );
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
    'agency_selective' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
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
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'date_of_scan' => 'date_of_scan',
    'agency' => 'agency',
    'agency_id_1' => 'agency_id_1',
    'num_of_websites' => 'num_of_websites',
    'average_dap_score' => 'average_dap_score',
    'average_https_score' => 'average_https_score',
    'mob_perf_good' => 'mob_perf_good',
    'mob_perf_improve' => 'mob_perf_improve',
    'mob_perf_poor' => 'mob_perf_poor',
    'mob_usab_friendly' => 'mob_usab_friendly',
    'average_uswds_score' => 'average_uswds_score',
    'search_available' => 'search_available',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'date_of_scan' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'agency' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'agency_id_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'num_of_websites' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'average_dap_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'average_https_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mob_perf_good' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mob_perf_improve' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mob_perf_poor' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mob_usab_friendly' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'average_uswds_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'search_available' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['caption'] = 'Agency-Wide Report Table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Download Agency-Wide Reports: <a href="/download/ideaact/agency-wide/report/csv"> csv </a> | <a href="/download/ideaact/agency-wide/report/xls">xls</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Custom Table Views: Agency id */
  $handler->display->display_options['relationships']['agency_id']['id'] = 'agency_id';
  $handler->display->display_options['relationships']['agency_id']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['relationships']['agency_id']['field'] = 'agency_id';
  $handler->display->display_options['relationships']['agency_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Custom Table Views: Date of scan */
  $handler->display->display_options['fields']['date_of_scan']['id'] = 'date_of_scan';
  $handler->display->display_options['fields']['date_of_scan']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['date_of_scan']['field'] = 'date_of_scan';
  $handler->display->display_options['fields']['date_of_scan']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date_of_scan']['date_format'] = 'long';
  $handler->display->display_options['fields']['date_of_scan']['second_date_format'] = 'long';
  /* Field: Custom Table Views: Agency id */
  $handler->display->display_options['fields']['agency_id_1']['id'] = 'agency_id_1';
  $handler->display->display_options['fields']['agency_id_1']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['agency_id_1']['field'] = 'agency_id';
  $handler->display->display_options['fields']['agency_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['agency_id_1']['separator'] = '';
  /* Field: Custom Table Views: Agency */
  $handler->display->display_options['fields']['agency']['id'] = 'agency';
  $handler->display->display_options['fields']['agency']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['agency']['field'] = 'agency';
  $handler->display->display_options['fields']['agency']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['agency']['alter']['path'] = 'ideaact/agencywide/dashboard/[agency_id_1]';
  /* Field: Custom Table Views: Num of websites */
  $handler->display->display_options['fields']['num_of_websites']['id'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['num_of_websites']['field'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['group_type'] = 'avg';
  $handler->display->display_options['fields']['num_of_websites']['label'] = 'Websites';
  /* Field: Custom Table Views: Average dap score */
  $handler->display->display_options['fields']['average_dap_score']['id'] = 'average_dap_score';
  $handler->display->display_options['fields']['average_dap_score']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['average_dap_score']['field'] = 'average_dap_score';
  $handler->display->display_options['fields']['average_dap_score']['group_type'] = 'count';
  $handler->display->display_options['fields']['average_dap_score']['label'] = 'DAP Compliant Websites';
  /* Field: Custom Table Views: Average https score */
  $handler->display->display_options['fields']['average_https_score']['id'] = 'average_https_score';
  $handler->display->display_options['fields']['average_https_score']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['average_https_score']['field'] = 'average_https_score';
  $handler->display->display_options['fields']['average_https_score']['group_type'] = 'count';
  $handler->display->display_options['fields']['average_https_score']['label'] = 'HTTPS Compliant Websites';
  /* Field: Custom Table Views: Mob perf good */
  $handler->display->display_options['fields']['mob_perf_good']['id'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_good']['field'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_perf_good']['label'] = 'Mobile Performance Websites (Good)';
  /* Field: Custom Table Views: Mob perf improve */
  $handler->display->display_options['fields']['mob_perf_improve']['id'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_improve']['field'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_perf_improve']['label'] = 'Mobile Performance Websites (Needs Improvement)';
  /* Field: Custom Table Views: Mob perf poor */
  $handler->display->display_options['fields']['mob_perf_poor']['id'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_poor']['field'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_perf_poor']['label'] = 'Mobile Performance Websites (Poor)';
  /* Field: Custom Table Views: Mob usab friendly */
  $handler->display->display_options['fields']['mob_usab_friendly']['id'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_usab_friendly']['field'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_usab_friendly']['label'] = 'Mobile Usability Websites';
  /* Field: Custom Table Views: Average uswds score */
  $handler->display->display_options['fields']['average_uswds_score']['id'] = 'average_uswds_score';
  $handler->display->display_options['fields']['average_uswds_score']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['average_uswds_score']['field'] = 'average_uswds_score';
  $handler->display->display_options['fields']['average_uswds_score']['label'] = 'Websites with USWDS';
  /* Field: Custom Table Views: Search available */
  $handler->display->display_options['fields']['search_available']['id'] = 'search_available';
  $handler->display->display_options['fields']['search_available']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['search_available']['field'] = 'search_available';
  $handler->display->display_options['fields']['search_available']['label'] = 'Websites with Search';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Custom Table Views: Date of scan */
  $handler->display->display_options['sorts']['date_of_scan']['id'] = 'date_of_scan';
  $handler->display->display_options['sorts']['date_of_scan']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['sorts']['date_of_scan']['field'] = 'date_of_scan';
  $handler->display->display_options['sorts']['date_of_scan']['group_type'] = 'count';
  $handler->display->display_options['sorts']['date_of_scan']['order'] = 'DESC';
  /* Sort criterion: Custom Table Views: Agency */
  $handler->display->display_options['sorts']['agency']['id'] = 'agency';
  $handler->display->display_options['sorts']['agency']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['sorts']['agency']['field'] = 'agency';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Agency (selective) */
  $handler->display->display_options['filters']['agency_selective']['id'] = 'agency_selective';
  $handler->display->display_options['filters']['agency_selective']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['filters']['agency_selective']['field'] = 'agency_selective';
  $handler->display->display_options['filters']['agency_selective']['ui_name'] = 'Agency (selective)';
  $handler->display->display_options['filters']['agency_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['agency_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['agency_selective']['expose']['label'] = 'Filter By Agency';
  $handler->display->display_options['filters']['agency_selective']['expose']['identifier'] = 'agency_selective';
  $handler->display->display_options['filters']['agency_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['agency_selective']['selective_display_field'] = 'agency';
  $handler->display->display_options['filters']['agency_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Custom Table Views: Date of scan */
  $handler->display->display_options['filters']['date_of_scan']['id'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['filters']['date_of_scan']['field'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['operator'] = '>=';
  $handler->display->display_options['filters']['date_of_scan']['value']['value'] = '-2 month';
  $handler->display->display_options['filters']['date_of_scan']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['date_of_scan']['expose']['operator_id'] = 'date_of_scan_op';
  $handler->display->display_options['filters']['date_of_scan']['expose']['label'] = 'Date of scan';
  $handler->display->display_options['filters']['date_of_scan']['expose']['operator'] = 'date_of_scan_op';
  $handler->display->display_options['filters']['date_of_scan']['expose']['identifier'] = 'date_of_scan';
  $handler->display->display_options['path'] = 'ideaact/agency-wide/report';

  /* Display: 21st Century IDEA Act Agency-Wide Reports Csv Download */
  $handler = $view->new_display('views_data_export', '21st Century IDEA Act Agency-Wide Reports Csv Download', 'views_data_export_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
  );
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Custom Table Views: Agency id */
  $handler->display->display_options['relationships']['agency_id']['id'] = 'agency_id';
  $handler->display->display_options['relationships']['agency_id']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['relationships']['agency_id']['field'] = 'agency_id';
  $handler->display->display_options['relationships']['agency_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Custom Table Views: Date of scan */
  $handler->display->display_options['fields']['date_of_scan_1']['id'] = 'date_of_scan_1';
  $handler->display->display_options['fields']['date_of_scan_1']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['date_of_scan_1']['field'] = 'date_of_scan';
  $handler->display->display_options['fields']['date_of_scan_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date_of_scan_1']['date_format'] = 'long';
  $handler->display->display_options['fields']['date_of_scan_1']['second_date_format'] = 'long';
  /* Field: Custom Table Views: Agency */
  $handler->display->display_options['fields']['agency']['id'] = 'agency';
  $handler->display->display_options['fields']['agency']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['agency']['field'] = 'agency';
  /* Field: Custom Table Views: Agency id */
  $handler->display->display_options['fields']['agency_id']['id'] = 'agency_id';
  $handler->display->display_options['fields']['agency_id']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['agency_id']['field'] = 'agency_id';
  $handler->display->display_options['fields']['agency_id']['exclude'] = TRUE;
  /* Field: Custom Table Views: Num of websites */
  $handler->display->display_options['fields']['num_of_websites']['id'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['num_of_websites']['field'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['group_type'] = 'avg';
  $handler->display->display_options['fields']['num_of_websites']['label'] = 'Websites';
  /* Field: Custom Table Views: Average dap score */
  $handler->display->display_options['fields']['average_dap_score']['id'] = 'average_dap_score';
  $handler->display->display_options['fields']['average_dap_score']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['average_dap_score']['field'] = 'average_dap_score';
  $handler->display->display_options['fields']['average_dap_score']['group_type'] = 'count';
  $handler->display->display_options['fields']['average_dap_score']['label'] = 'DAP Compliant Websites';
  /* Field: Custom Table Views: Average https score */
  $handler->display->display_options['fields']['average_https_score']['id'] = 'average_https_score';
  $handler->display->display_options['fields']['average_https_score']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['average_https_score']['field'] = 'average_https_score';
  $handler->display->display_options['fields']['average_https_score']['group_type'] = 'count';
  $handler->display->display_options['fields']['average_https_score']['label'] = 'HTTPS Compliant Websites';
  /* Field: Custom Table Views: Mob perf good */
  $handler->display->display_options['fields']['mob_perf_good']['id'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_good']['field'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_perf_good']['label'] = 'Mobile Performance Websites (Good)';
  /* Field: Custom Table Views: Mob perf improve */
  $handler->display->display_options['fields']['mob_perf_improve']['id'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_improve']['field'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_perf_improve']['label'] = 'Mobile Performance Websites (Needs Improvement)';
  /* Field: Custom Table Views: Mob perf poor */
  $handler->display->display_options['fields']['mob_perf_poor']['id'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_poor']['field'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_perf_poor']['label'] = 'Mobile Performance Websites (Poor)';
  /* Field: Custom Table Views: Mob usab friendly */
  $handler->display->display_options['fields']['mob_usab_friendly']['id'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_usab_friendly']['field'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_usab_friendly']['label'] = 'Mobile Usability Websites';
  /* Field: Custom Table Views: Average uswds score */
  $handler->display->display_options['fields']['average_uswds_score']['id'] = 'average_uswds_score';
  $handler->display->display_options['fields']['average_uswds_score']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['average_uswds_score']['field'] = 'average_uswds_score';
  $handler->display->display_options['fields']['average_uswds_score']['label'] = 'Websites with USWDS';
  /* Field: Custom Table Views: Search available */
  $handler->display->display_options['fields']['search_available']['id'] = 'search_available';
  $handler->display->display_options['fields']['search_available']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['search_available']['field'] = 'search_available';
  $handler->display->display_options['fields']['search_available']['label'] = 'Websites with Search';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Custom Table Views: Agency */
  $handler->display->display_options['sorts']['agency']['id'] = 'agency';
  $handler->display->display_options['sorts']['agency']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['sorts']['agency']['field'] = 'agency';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Custom Table Views: Date of scan */
  $handler->display->display_options['filters']['date_of_scan']['id'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['filters']['date_of_scan']['field'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['operator'] = '>=';
  $handler->display->display_options['filters']['date_of_scan']['value']['value'] = '-1 month';
  $handler->display->display_options['filters']['date_of_scan']['value']['type'] = 'offset';
  $handler->display->display_options['path'] = 'download/ideaact/agency-wide/report/csv';

  /* Display: 21st Century IDEA Act Agency-Wide Reports Xls Download */
  $handler = $view->new_display('views_data_export', '21st Century IDEA Act Agency-Wide Reports Xls Download', 'views_data_export_2');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Custom Table Views: Agency id */
  $handler->display->display_options['relationships']['agency_id']['id'] = 'agency_id';
  $handler->display->display_options['relationships']['agency_id']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['relationships']['agency_id']['field'] = 'agency_id';
  $handler->display->display_options['relationships']['agency_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Custom Table Views: Date of scan */
  $handler->display->display_options['fields']['date_of_scan_1']['id'] = 'date_of_scan_1';
  $handler->display->display_options['fields']['date_of_scan_1']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['date_of_scan_1']['field'] = 'date_of_scan';
  $handler->display->display_options['fields']['date_of_scan_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date_of_scan_1']['date_format'] = 'long';
  $handler->display->display_options['fields']['date_of_scan_1']['second_date_format'] = 'long';
  /* Field: Custom Table Views: Agency */
  $handler->display->display_options['fields']['agency']['id'] = 'agency';
  $handler->display->display_options['fields']['agency']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['agency']['field'] = 'agency';
  /* Field: Custom Table Views: Agency id */
  $handler->display->display_options['fields']['agency_id']['id'] = 'agency_id';
  $handler->display->display_options['fields']['agency_id']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['agency_id']['field'] = 'agency_id';
  $handler->display->display_options['fields']['agency_id']['exclude'] = TRUE;
  /* Field: Custom Table Views: Num of websites */
  $handler->display->display_options['fields']['num_of_websites']['id'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['num_of_websites']['field'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['group_type'] = 'avg';
  $handler->display->display_options['fields']['num_of_websites']['label'] = 'Websites';
  /* Field: Custom Table Views: Average dap score */
  $handler->display->display_options['fields']['average_dap_score']['id'] = 'average_dap_score';
  $handler->display->display_options['fields']['average_dap_score']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['average_dap_score']['field'] = 'average_dap_score';
  $handler->display->display_options['fields']['average_dap_score']['group_type'] = 'count';
  $handler->display->display_options['fields']['average_dap_score']['label'] = 'DAP Compliant Websites';
  /* Field: Custom Table Views: Average https score */
  $handler->display->display_options['fields']['average_https_score']['id'] = 'average_https_score';
  $handler->display->display_options['fields']['average_https_score']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['average_https_score']['field'] = 'average_https_score';
  $handler->display->display_options['fields']['average_https_score']['group_type'] = 'count';
  $handler->display->display_options['fields']['average_https_score']['label'] = 'HTTPS Compliant Websites';
  /* Field: Custom Table Views: Mob perf good */
  $handler->display->display_options['fields']['mob_perf_good']['id'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_good']['field'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_perf_good']['label'] = 'Mobile Performance Websites (Good)';
  /* Field: Custom Table Views: Mob perf improve */
  $handler->display->display_options['fields']['mob_perf_improve']['id'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_improve']['field'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_perf_improve']['label'] = 'Mobile Performance Websites (Needs Improvement)';
  /* Field: Custom Table Views: Mob perf poor */
  $handler->display->display_options['fields']['mob_perf_poor']['id'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_poor']['field'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_perf_poor']['label'] = 'Mobile Performance Websites (Poor)';
  /* Field: Custom Table Views: Mob usab friendly */
  $handler->display->display_options['fields']['mob_usab_friendly']['id'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_usab_friendly']['field'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['group_type'] = 'avg';
  $handler->display->display_options['fields']['mob_usab_friendly']['label'] = 'Mobile Usability Websites';
  /* Field: Custom Table Views: Average uswds score */
  $handler->display->display_options['fields']['average_uswds_score']['id'] = 'average_uswds_score';
  $handler->display->display_options['fields']['average_uswds_score']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['average_uswds_score']['field'] = 'average_uswds_score';
  $handler->display->display_options['fields']['average_uswds_score']['label'] = 'Websites with USWDS';
  /* Field: Custom Table Views: Search available */
  $handler->display->display_options['fields']['search_available']['id'] = 'search_available';
  $handler->display->display_options['fields']['search_available']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['search_available']['field'] = 'search_available';
  $handler->display->display_options['fields']['search_available']['label'] = 'Websites with Search';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Custom Table Views: Agency */
  $handler->display->display_options['sorts']['agency']['id'] = 'agency';
  $handler->display->display_options['sorts']['agency']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['sorts']['agency']['field'] = 'agency';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Custom Table Views: Date of scan */
  $handler->display->display_options['filters']['date_of_scan']['id'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['filters']['date_of_scan']['field'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['operator'] = '>=';
  $handler->display->display_options['filters']['date_of_scan']['value']['value'] = '-1 month';
  $handler->display->display_options['filters']['date_of_scan']['value']['type'] = 'offset';
  $handler->display->display_options['path'] = 'download/ideaact/agency-wide/report/xls';
  $export['21st_century_idea_act_agency_wide_reports'] = $view;

  $view = new view();
  $view->name = 'ideaact_government_wide_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'IdeaAct Government Wide Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '21st Century IDEA Act Reports Download';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    13 => '13',
    16 => '16',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: 21st Century IDEA Act Reports */
  $handler = $view->new_display('page', '21st Century IDEA Act Reports', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '21st Century IDEA Act Reports';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'white-back';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'datatables';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'field_dap_score' => 'field_dap_score',
    'field_https_score' => 'field_https_score',
    'field_search_status' => 'field_search_status',
    'field_uswds_score' => 'field_uswds_score',
    'php' => 'php',
    'php_1' => 'php_1',
    'field_mobile_performance_status' => 'field_mobile_performance_status',
    'field_mobile_usability_status' => 'field_mobile_usability_status',
    'php_2' => 'php_2',
    'php_3' => 'php_3',
    'field_accessibility_total_errors' => 'field_accessibility_total_errors',
    'php_4' => 'php_4',
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
    'field_dap_score' => array(
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
    'field_search_status' => array(
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
    'php' => array(
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
    'field_mobile_performance_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mobile_usability_status' => array(
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
    'field_accessibility_total_errors' => array(
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
    'display_length' => '10',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Download Website-Specific Reports: <a href="/download/ideaact/govwide/report/csv"> csv </a> | <a href="/download/ideaact/govwide/report/xls">xls</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
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
  $handler->display->display_options['fields']['title']['alter']['path'] = 'ideaact/website/dashboard/[nid]';
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
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = 'ideaact/agencywide/dashboard/[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['label'] = 'DAP Status';
  $handler->display->display_options['fields']['field_dap_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_dap_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['label'] = 'HTTPS Status';
  $handler->display->display_options['fields']['field_https_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_https_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_https_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Search Status */
  $handler->display->display_options['fields']['field_search_status']['id'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['table'] = 'field_data_field_search_status';
  $handler->display->display_options['fields']['field_search_status']['field'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['exclude'] = TRUE;
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['label'] = 'USWDS Status';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_uswds_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_uswds_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'DAP Code Status';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if ($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == NULL) {
print "Not Available";
} else if ($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == 100) {
print "Present";
} else {
print "Not Present";
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'HTTPS Status';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if ($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == NULL) {
print "Not Available";
} else if ($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == 100) {
print "Yes";
} else {
print "No";
}
?>
';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: Mobile Performance Status */
  $handler->display->display_options['fields']['field_mobile_performance_status']['id'] = 'field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['table'] = 'field_data_field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['field'] = 'field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['empty'] = 'Not Available';
  /* Field: Content: Mobile Usability Status */
  $handler->display->display_options['fields']['field_mobile_usability_status']['id'] = 'field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['table'] = 'field_data_field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['field'] = 'field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['empty'] = 'Not Available';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Search Status';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
if (trim($data->field_field_search_status[\'0\'][\'raw\'][\'value\']) == 1) {
print "Available";
} else {
print "Not Available";
}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'USWDS Code Status';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
if ($data->field_field_uswds_score[\'0\'][\'raw\'][\'value\'] == NULL) {
print "Not Available";
} else if ($data->field_field_uswds_score[\'0\'][\'raw\'][\'value\'] == 100) {
print "Yes";
} else {
print "No";
}
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Content: Accessibility Total Errors */
  $handler->display->display_options['fields']['field_accessibility_total_errors']['id'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['field'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['label'] = 'Total Accessibility Issues';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['empty'] = '0';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_accessibility_total_errors']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_accessibility_total_errors']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
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
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['group'] = 1;
  $handler->display->display_options['path'] = 'ideaact/govwide/report';

  /* Display: 21st Century IDEA Act Reports Download */
  $handler = $view->new_display('views_data_export', '21st Century IDEA Act Reports Download', 'views_data_export_2');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
  );
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['label'] = 'DAP Status';
  $handler->display->display_options['fields']['field_dap_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_dap_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['label'] = 'HTTPS Status';
  $handler->display->display_options['fields']['field_https_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_https_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_https_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Search Status */
  $handler->display->display_options['fields']['field_search_status']['id'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['table'] = 'field_data_field_search_status';
  $handler->display->display_options['fields']['field_search_status']['field'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['exclude'] = TRUE;
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['label'] = 'USWDS Status';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'DAP Code Status';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if ($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == NULL) {
print "Not Available";
} else if ($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == 100) {
print "Present";
} else {
print "Not Present";
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'HTTPS Status';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if ($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == NULL) {
print "Not Available";
} else if ($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == 100) {
print "Yes";
} else {
print "No";
}
?>
';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: Mobile Performance Status */
  $handler->display->display_options['fields']['field_mobile_performance_status']['id'] = 'field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['table'] = 'field_data_field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['field'] = 'field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['empty'] = 'Not Available';
  /* Field: Content: Mobile Usability Status */
  $handler->display->display_options['fields']['field_mobile_usability_status']['id'] = 'field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['table'] = 'field_data_field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['field'] = 'field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['empty'] = 'Not Available';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Search Status';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
if (trim($data->field_field_search_status[\'0\'][\'raw\'][\'value\']) == 1) {
print "Available";
} else {
print "Not Available";
}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'USWDS Code Status';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
if ($data->field_field_uswds_score[\'0\'][\'raw\'][\'value\'] == NULL) {
print "Not Available";
} else if ($data->field_field_uswds_score[\'0\'][\'raw\'][\'value\'] == 100) {
print "Yes";
} else {
print "No";
}
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Content: Accessibility Total Errors */
  $handler->display->display_options['fields']['field_accessibility_total_errors']['id'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['field'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['label'] = 'Total Accessibility Issues';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['empty'] = '0';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_accessibility_total_errors']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_accessibility_total_errors']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
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
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['id'] = 'field_web_agency_id_nid_1';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['expose']['operator_id'] = 'field_web_agency_id_nid_1_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['expose']['label'] = 'Filter By Agency';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['expose']['operator'] = 'field_web_agency_id_nid_1_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['expose']['identifier'] = 'field_web_agency_id_nid_1';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'download/ideaact/govwide/report/csv';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: 21st Century IDEA Act Reports Download */
  $handler = $view->new_display('views_data_export', '21st Century IDEA Act Reports Download', 'views_data_export_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
    2 => '2',
  );
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['label'] = 'DAP Status';
  $handler->display->display_options['fields']['field_dap_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_dap_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_dap_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['label'] = 'HTTPS Status';
  $handler->display->display_options['fields']['field_https_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_https_score']['empty'] = 'Not Available';
  $handler->display->display_options['fields']['field_https_score']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_https_score']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Search Status */
  $handler->display->display_options['fields']['field_search_status']['id'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['table'] = 'field_data_field_search_status';
  $handler->display->display_options['fields']['field_search_status']['field'] = 'field_search_status';
  $handler->display->display_options['fields']['field_search_status']['exclude'] = TRUE;
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['label'] = 'USWDS Status';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'DAP Code Status';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if ($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == NULL) {
print "Not Available";
} else if ($data->field_field_dap_score[\'0\'][\'raw\'][\'value\'] == 100) {
print "Present";
} else {
print "Not Present";
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'HTTPS Status';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
if ($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == NULL) {
print "Not Available";
} else if ($data->field_field_https_score[\'0\'][\'raw\'][\'value\'] == 100) {
print "Yes";
} else {
print "No";
}
?>
';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: Mobile Performance Status */
  $handler->display->display_options['fields']['field_mobile_performance_status']['id'] = 'field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['table'] = 'field_data_field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['field'] = 'field_mobile_performance_status';
  $handler->display->display_options['fields']['field_mobile_performance_status']['empty'] = 'Not Available';
  /* Field: Content: Mobile Usability Status */
  $handler->display->display_options['fields']['field_mobile_usability_status']['id'] = 'field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['table'] = 'field_data_field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['field'] = 'field_mobile_usability_status';
  $handler->display->display_options['fields']['field_mobile_usability_status']['empty'] = 'Not Available';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Search Status';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
if (trim($data->field_field_search_status[\'0\'][\'raw\'][\'value\']) == 1) {
print "Available";
} else {
print "Not Available";
}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'USWDS Code Status';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
if ($data->field_field_uswds_score[\'0\'][\'raw\'][\'value\'] == NULL) {
print "Not Available";
} else if ($data->field_field_uswds_score[\'0\'][\'raw\'][\'value\'] == 100) {
print "Yes";
} else {
print "No";
}
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Content: Accessibility Total Errors */
  $handler->display->display_options['fields']['field_accessibility_total_errors']['id'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['field'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['label'] = 'Accessibility Total Issues';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
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
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['id'] = 'field_web_agency_id_nid_1';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['expose']['operator_id'] = 'field_web_agency_id_nid_1_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['expose']['label'] = 'Filter By Agency';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['expose']['operator'] = 'field_web_agency_id_nid_1_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['expose']['identifier'] = 'field_web_agency_id_nid_1';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['group'] = 1;
  $handler->display->display_options['path'] = 'download/ideaact/govwide/report/xls';
  $handler->display->display_options['sitename_title'] = 0;
  $export['ideaact_government_wide_report'] = $view;

  return $export;
}
