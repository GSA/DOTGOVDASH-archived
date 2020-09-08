<?php

/**
 * @file
 * new_mobile_changes.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function new_mobile_changes_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agency_mobile_reports';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Agency Mobile Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Agency-Wide Mobile Reports';
  $handler->display->display_options['css_class'] = 'white-back';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    13 => '13',
    14 => '14',
    16 => '16',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'datatables';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'field_web_agency_id_1' => 'field_web_agency_id_1',
    'field_mobile_performance_status' => 'field_mobile_performance_status',
    'field_mobile_usability_status' => 'field_mobile_usability_status',
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
    'field_web_agency_id_1' => array(
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
    'display_length' => '50',
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Download Agency-Wide Mobile Reports: <a href="/download/website/mobile/reports/csv">csv</a> | <a href="/download/website/mobile/reports/xls">xls</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
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
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Agency';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_nid';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id_1']['id'] = 'field_web_agency_id_1';
  $handler->display->display_options['fields']['field_web_agency_id_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id_1']['alter']['path'] = 'agency_home/[field_web_agency_id_1-nid]';
  $handler->display->display_options['fields']['field_web_agency_id_1']['type'] = 'node_reference_plain';
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
  $handler->display->display_options['path'] = 'website/mobile/reports';

  /* Display: CSV export */
  $handler = $view->new_display('views_data_export', 'CSV export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'agency_mobile_data.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
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
  $handler->display->display_options['path'] = 'download/website/mobile/reports/csv';

  /* Display: XLS Data export */
  $handler = $view->new_display('views_data_export', 'XLS Data export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'agency_mobile_data.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
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
  $handler->display->display_options['path'] = 'download/website/mobile/reports/xls';
  $export['agency_mobile_reports'] = $view;

  $view = new view();
  $view->name = 'government_wide_mobile_report_new';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'custom_agencywide_archive';
  $view->human_name = 'Government Wide Mobile Report New';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Government-Wide Mobile Report';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
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
        'autosubmit' => 1,
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'datatables';
  $handler->display->display_options['style_options']['columns'] = array(
    'date_of_scan' => 'date_of_scan',
    'id' => 'id',
    'agency_id' => 'agency_id',
    'agency' => 'agency',
    'num_of_websites' => 'num_of_websites',
    'mob_perf_good' => 'mob_perf_good',
    'mob_perf_improve' => 'mob_perf_improve',
    'mob_perf_poor' => 'mob_perf_poor',
    'mob_usab_friendly' => 'mob_usab_friendly',
    'mob_usab_nonfriendly' => 'mob_usab_nonfriendly',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'date_of_scan' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'agency_id' => array(
      'sortable' => 1,
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
    'num_of_websites' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'mob_usab_nonfriendly' => array(
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
    'display_length' => '50',
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Download Government-Wide Mobile Reports: <a href="/download/mobile/report/csv">csv</a> | <a href="/download/mobile/report/xls">xls</a></p>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Relationship: Custom Table Views: Agency id */
  $handler->display->display_options['relationships']['agency_id']['id'] = 'agency_id';
  $handler->display->display_options['relationships']['agency_id']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['relationships']['agency_id']['field'] = 'agency_id';
  $handler->display->display_options['relationships']['agency_id']['required'] = TRUE;
  /* Field: Custom Table Views: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Custom Table Views: Agency */
  $handler->display->display_options['fields']['agency']['id'] = 'agency';
  $handler->display->display_options['fields']['agency']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['agency']['field'] = 'agency';
  $handler->display->display_options['fields']['agency']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['agency']['alter']['path'] = '/agency_home/[field_web_agency_id]';
  /* Field: Custom Table Views: Num of websites */
  $handler->display->display_options['fields']['num_of_websites']['id'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['num_of_websites']['field'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['label'] = 'Websites';
  /* Field: Custom Table Views: Mob perf good */
  $handler->display->display_options['fields']['mob_perf_good']['id'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_good']['field'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['label'] = 'Number of Websites with Good Status(Mobile Performance)';
  /* Field: Custom Table Views: Mob perf improve */
  $handler->display->display_options['fields']['mob_perf_improve']['id'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_improve']['field'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['label'] = 'Number of Websites with Needs Improvement Status(Mobile Performance)';
  /* Field: Custom Table Views: Mob perf poor */
  $handler->display->display_options['fields']['mob_perf_poor']['id'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_poor']['field'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['label'] = 'Number of Websites with Poor Status (Mobile Performance)';
  /* Field: Custom Table Views: Mob usab friendly */
  $handler->display->display_options['fields']['mob_usab_friendly']['id'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_usab_friendly']['field'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['label'] = 'Number of Websites with Mobile Friendly Status (Mobile Usability)';
  /* Field: Custom Table Views: Mob usab nonfriendly */
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['id'] = 'mob_usab_nonfriendly';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['field'] = 'mob_usab_nonfriendly';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['label'] = 'Number of Websites with Not Mobile Friendly Status (Mobile Usability)';
  /* Sort criterion: Custom Table Views: Date of scan */
  $handler->display->display_options['sorts']['date_of_scan']['id'] = 'date_of_scan';
  $handler->display->display_options['sorts']['date_of_scan']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['sorts']['date_of_scan']['field'] = 'date_of_scan';
  $handler->display->display_options['sorts']['date_of_scan']['order'] = 'DESC';
  /* Filter criterion: Custom Table Views: Agency */
  $handler->display->display_options['filters']['agency']['id'] = 'agency';
  $handler->display->display_options['filters']['agency']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['filters']['agency']['field'] = 'agency';
  $handler->display->display_options['filters']['agency']['exposed'] = TRUE;
  $handler->display->display_options['filters']['agency']['expose']['operator_id'] = 'agency_op';
  $handler->display->display_options['filters']['agency']['expose']['label'] = 'Agency';
  $handler->display->display_options['filters']['agency']['expose']['operator'] = 'agency_op';
  $handler->display->display_options['filters']['agency']['expose']['identifier'] = 'agency';
  $handler->display->display_options['filters']['agency']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Custom Table Views: Agency id */
  $handler->display->display_options['filters']['agency_id']['id'] = 'agency_id';
  $handler->display->display_options['filters']['agency_id']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['filters']['agency_id']['field'] = 'agency_id';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'white-back';
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
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Custom Table Views: Date of scan */
  $handler->display->display_options['fields']['date_of_scan']['id'] = 'date_of_scan';
  $handler->display->display_options['fields']['date_of_scan']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['date_of_scan']['field'] = 'date_of_scan';
  $handler->display->display_options['fields']['date_of_scan']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date_of_scan']['date_format'] = 'long';
  $handler->display->display_options['fields']['date_of_scan']['second_date_format'] = 'long';
  /* Field: Custom Table Views: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Custom Table Views: Agency id */
  $handler->display->display_options['fields']['agency_id']['id'] = 'agency_id';
  $handler->display->display_options['fields']['agency_id']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['agency_id']['field'] = 'agency_id';
  $handler->display->display_options['fields']['agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['agency_id']['separator'] = '';
  /* Field: Custom Table Views: Agency */
  $handler->display->display_options['fields']['agency']['id'] = 'agency';
  $handler->display->display_options['fields']['agency']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['agency']['field'] = 'agency';
  $handler->display->display_options['fields']['agency']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['agency']['alter']['path'] = '/agency_home/[agency_id]';
  /* Field: Custom Table Views: Num of websites */
  $handler->display->display_options['fields']['num_of_websites']['id'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['num_of_websites']['field'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['label'] = 'Websites';
  /* Field: Custom Table Views: Mob perf good */
  $handler->display->display_options['fields']['mob_perf_good']['id'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_good']['field'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['label'] = 'Websites with Good Status (Mobile Performance)';
  /* Field: Custom Table Views: Mob perf improve */
  $handler->display->display_options['fields']['mob_perf_improve']['id'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_improve']['field'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['label'] = 'Websites with Needs Improvement Status (Mobile Performance)';
  /* Field: Custom Table Views: Mob perf poor */
  $handler->display->display_options['fields']['mob_perf_poor']['id'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_poor']['field'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['label'] = 'Websites with Poor Status (Mobile Performance)';
  /* Field: Custom Table Views: Mob usab friendly */
  $handler->display->display_options['fields']['mob_usab_friendly']['id'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_usab_friendly']['field'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['label'] = 'Websites with Mobile Friendly Status (Mobile Usability)';
  /* Field: Custom Table Views: Mob usab nonfriendly */
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['id'] = 'mob_usab_nonfriendly';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['field'] = 'mob_usab_nonfriendly';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['label'] = 'Websites with Not Mobile Friendly Status (Mobile Usability)';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Agency (selective) */
  $handler->display->display_options['filters']['agency_selective']['id'] = 'agency_selective';
  $handler->display->display_options['filters']['agency_selective']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['filters']['agency_selective']['field'] = 'agency_selective';
  $handler->display->display_options['filters']['agency_selective']['ui_name'] = 'Agency (selective)';
  $handler->display->display_options['filters']['agency_selective']['group'] = 1;
  $handler->display->display_options['filters']['agency_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['agency_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['agency_selective']['expose']['label'] = 'Agency';
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
  /* Filter criterion: Custom Table Views: Date of scan (selective) */
  $handler->display->display_options['filters']['date_of_scan_selective']['id'] = 'date_of_scan_selective';
  $handler->display->display_options['filters']['date_of_scan_selective']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['filters']['date_of_scan_selective']['field'] = 'date_of_scan_selective';
  $handler->display->display_options['filters']['date_of_scan_selective']['exposed'] = TRUE;
  $handler->display->display_options['path'] = 'mobile/report';

  /* Display: CSV export */
  $handler = $view->new_display('views_data_export', 'CSV export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'govtwide_mobile.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Custom Table Views: Date of scan */
  $handler->display->display_options['fields']['date_of_scan']['id'] = 'date_of_scan';
  $handler->display->display_options['fields']['date_of_scan']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['date_of_scan']['field'] = 'date_of_scan';
  $handler->display->display_options['fields']['date_of_scan']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date_of_scan']['date_format'] = 'long';
  $handler->display->display_options['fields']['date_of_scan']['second_date_format'] = 'long';
  /* Field: Custom Table Views: Agency */
  $handler->display->display_options['fields']['agency']['id'] = 'agency';
  $handler->display->display_options['fields']['agency']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['agency']['field'] = 'agency';
  $handler->display->display_options['fields']['agency']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['agency']['alter']['path'] = '/agency_home/[field_web_agency_id]';
  /* Field: Custom Table Views: Num of websites */
  $handler->display->display_options['fields']['num_of_websites']['id'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['num_of_websites']['field'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['label'] = 'Websites';
  /* Field: Custom Table Views: Mob perf good */
  $handler->display->display_options['fields']['mob_perf_good']['id'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_good']['field'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['label'] = 'Number of Websites with Good Status(Mobile Performance)';
  /* Field: Custom Table Views: Mob perf improve */
  $handler->display->display_options['fields']['mob_perf_improve']['id'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_improve']['field'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['label'] = 'Number of Websites with Needs Improvement Status(Mobile Performance)';
  /* Field: Custom Table Views: Mob perf poor */
  $handler->display->display_options['fields']['mob_perf_poor']['id'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_poor']['field'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['label'] = 'Number of Websites with Poor Status (Mobile Performance)';
  /* Field: Custom Table Views: Mob usab friendly */
  $handler->display->display_options['fields']['mob_usab_friendly']['id'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_usab_friendly']['field'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['label'] = 'Number of Websites with Mobile Friendly Status (Mobile Usability)';
  /* Field: Custom Table Views: Mob usab nonfriendly */
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['id'] = 'mob_usab_nonfriendly';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['field'] = 'mob_usab_nonfriendly';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['label'] = 'Number of Websites with Not Mobile Friendly Status (Mobile Usability)';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'agency_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'agency' => 'agency',
  );
  /* Filter criterion: Custom Table Views: Date of scan */
  $handler->display->display_options['filters']['date_of_scan']['id'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['filters']['date_of_scan']['field'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['operator'] = 'between';
  $handler->display->display_options['filters']['date_of_scan']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['date_of_scan']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_of_scan']['expose']['operator_id'] = 'date_of_scan_op';
  $handler->display->display_options['filters']['date_of_scan']['expose']['label'] = 'Date of scan';
  $handler->display->display_options['filters']['date_of_scan']['expose']['operator'] = 'date_of_scan_op';
  $handler->display->display_options['filters']['date_of_scan']['expose']['identifier'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['path'] = 'download/mobile/report/csv';

  /* Display: XLS export */
  $handler = $view->new_display('views_data_export', 'XLS export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'govtwide_mobile.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Custom Table Views: Date of scan */
  $handler->display->display_options['fields']['date_of_scan']['id'] = 'date_of_scan';
  $handler->display->display_options['fields']['date_of_scan']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['date_of_scan']['field'] = 'date_of_scan';
  $handler->display->display_options['fields']['date_of_scan']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date_of_scan']['date_format'] = 'long';
  $handler->display->display_options['fields']['date_of_scan']['second_date_format'] = 'long';
  /* Field: Custom Table Views: Agency */
  $handler->display->display_options['fields']['agency']['id'] = 'agency';
  $handler->display->display_options['fields']['agency']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['agency']['field'] = 'agency';
  $handler->display->display_options['fields']['agency']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['agency']['alter']['path'] = '/agency_home/[field_web_agency_id]';
  /* Field: Custom Table Views: Num of websites */
  $handler->display->display_options['fields']['num_of_websites']['id'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['num_of_websites']['field'] = 'num_of_websites';
  $handler->display->display_options['fields']['num_of_websites']['label'] = 'Websites';
  /* Field: Custom Table Views: Mob perf good */
  $handler->display->display_options['fields']['mob_perf_good']['id'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_good']['field'] = 'mob_perf_good';
  $handler->display->display_options['fields']['mob_perf_good']['label'] = 'Number of Websites with Good Status(Mobile Performance)';
  /* Field: Custom Table Views: Mob perf improve */
  $handler->display->display_options['fields']['mob_perf_improve']['id'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_improve']['field'] = 'mob_perf_improve';
  $handler->display->display_options['fields']['mob_perf_improve']['label'] = 'Number of Websites with Needs Improvement Status(Mobile Performance)';
  /* Field: Custom Table Views: Mob perf poor */
  $handler->display->display_options['fields']['mob_perf_poor']['id'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_perf_poor']['field'] = 'mob_perf_poor';
  $handler->display->display_options['fields']['mob_perf_poor']['label'] = 'Number of Websites with Poor Status (Mobile Performance)';
  /* Field: Custom Table Views: Mob usab friendly */
  $handler->display->display_options['fields']['mob_usab_friendly']['id'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_usab_friendly']['field'] = 'mob_usab_friendly';
  $handler->display->display_options['fields']['mob_usab_friendly']['label'] = 'Number of Websites with Mobile Friendly Status (Mobile Usability)';
  /* Field: Custom Table Views: Mob usab nonfriendly */
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['id'] = 'mob_usab_nonfriendly';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['field'] = 'mob_usab_nonfriendly';
  $handler->display->display_options['fields']['mob_usab_nonfriendly']['label'] = 'Number of Websites with Not Mobile Friendly Status (Mobile Usability)';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'agency_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'agency' => 'agency',
  );
  /* Filter criterion: Custom Table Views: Date of scan */
  $handler->display->display_options['filters']['date_of_scan']['id'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['table'] = 'custom_agencywide_archive';
  $handler->display->display_options['filters']['date_of_scan']['field'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['operator'] = 'between';
  $handler->display->display_options['filters']['date_of_scan']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_of_scan']['expose']['operator_id'] = 'date_of_scan_op';
  $handler->display->display_options['filters']['date_of_scan']['expose']['label'] = 'Date of scan';
  $handler->display->display_options['filters']['date_of_scan']['expose']['operator'] = 'date_of_scan_op';
  $handler->display->display_options['filters']['date_of_scan']['expose']['identifier'] = 'date_of_scan';
  $handler->display->display_options['filters']['date_of_scan']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['path'] = 'download/mobile/report/xls';
  $export['government_wide_mobile_report_new'] = $view;

  $view = new view();
  $view->name = 'mobile_report_export';
  $view->description = 'Csv and Xls Export for Mobile Report';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mobile Report Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mobile Report';
  $handler->display->display_options['css_class'] = 'white-back';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    13 => '13',
    16 => '16',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_web_agency_id' => 'field_web_agency_id',
    'field_web_agency_id_1' => 'field_web_agency_id_1',
    'field_ssl_score' => 'field_ssl_score',
    'field_dap_score' => 'field_dap_score',
    'field_https_score' => 'field_https_score',
    'field_mobile_overall_score' => 'field_mobile_overall_score',
    'field_mobile_performance_score' => 'field_mobile_performance_score',
    'field_mobile_usability_score' => 'field_mobile_usability_score',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_web_agency_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_web_agency_id_1' => array(
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
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  /* Field: COUNT(Field: Agency ID) */
  $handler->display->display_options['fields']['field_web_agency_id_1']['id'] = 'field_web_agency_id_1';
  $handler->display->display_options['fields']['field_web_agency_id_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_web_agency_id_1']['label'] = 'Websites';
  $handler->display->display_options['fields']['field_web_agency_id_1']['separator'] = ', ';
  /* Field: AVG(Content: SSL Score) */
  $handler->display->display_options['fields']['field_ssl_score']['id'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['table'] = 'field_data_field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['field'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_ssl_score']['label'] = 'Average SSL Score';
  $handler->display->display_options['fields']['field_ssl_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: DAP Score) */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_dap_score']['label'] = 'Average DAP Score';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: HTTPS Score) */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_https_score']['label'] = 'Average HTTPS Score';
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: Mobile Overall Score) */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_overall_score']['label'] = 'Average Mobile Overall Score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: Mobile Performance Score) */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_performance_score']['label'] = 'Average Mobile Performance Score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: Mobile Usability Score) */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_usability_score']['label'] = 'Average Mobile Usability Score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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

  /* Display: Csv Mobile Report export */
  $handler = $view->new_display('views_data_export', 'Csv Mobile Report export', 'views_data_export_4');
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
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id_2']['id'] = 'field_web_agency_id_2';
  $handler->display->display_options['fields']['field_web_agency_id_2']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_2']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_2']['type'] = 'node_reference_nid';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency Name';
  $handler->display->display_options['fields']['field_web_agency_id']['empty'] = 'no result';
  /* Field: COUNT(Field: Agency ID) */
  $handler->display->display_options['fields']['field_web_agency_id_1']['id'] = 'field_web_agency_id_1';
  $handler->display->display_options['fields']['field_web_agency_id_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_web_agency_id_1']['label'] = 'Websites';
  $handler->display->display_options['fields']['field_web_agency_id_1']['separator'] = ', ';
  /* Field: AVG(Content: Mobile Overall Score) */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_overall_score']['label'] = 'Average Mobile Overall Score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['empty'] = '0';
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: Mobile Performance Score) */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_performance_score']['label'] = 'Average Mobile Performance Score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['empty'] = '0';
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: Mobile Usability Score) */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_usability_score']['label'] = 'Average Mobile Usability Score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['empty'] = '0';
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: Site Speed Score) */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_site_speed_score']['label'] = 'Average Site Speed Score';
  $handler->display->display_options['fields']['field_site_speed_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['empty'] = '0';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Mobile Score Rating';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$score = round($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']);
if ($score < 50) print \'Slow\';
elseif ($score < 90) print \'Moderate\';
else print \'Fast\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['path'] = 'download/mobile/report/csv-new';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Xls Mobile Report export */
  $handler = $view->new_display('views_data_export', 'Xls Mobile Report export', 'views_data_export_5');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id_2']['id'] = 'field_web_agency_id_2';
  $handler->display->display_options['fields']['field_web_agency_id_2']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_2']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_2']['type'] = 'node_reference_nid';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency Name';
  $handler->display->display_options['fields']['field_web_agency_id']['empty'] = 'no result';
  /* Field: COUNT(Field: Agency ID) */
  $handler->display->display_options['fields']['field_web_agency_id_1']['id'] = 'field_web_agency_id_1';
  $handler->display->display_options['fields']['field_web_agency_id_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_web_agency_id_1']['label'] = 'Websites';
  $handler->display->display_options['fields']['field_web_agency_id_1']['separator'] = ', ';
  /* Field: AVG(Content: Mobile Overall Score) */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_overall_score']['label'] = 'Average Mobile Overall Score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['empty'] = '0';
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: Mobile Performance Score) */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_performance_score']['label'] = 'Average Mobile Performance Score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['empty'] = '0';
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: Mobile Usability Score) */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_usability_score']['label'] = 'Average Mobile Usability Score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['empty'] = '0';
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: Site Speed Score) */
  $handler->display->display_options['fields']['field_site_speed_score']['id'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['table'] = 'field_data_field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['field'] = 'field_site_speed_score';
  $handler->display->display_options['fields']['field_site_speed_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_site_speed_score']['label'] = 'Average Site Speed Score';
  $handler->display->display_options['fields']['field_site_speed_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_speed_score']['empty'] = '0';
  $handler->display->display_options['fields']['field_site_speed_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Mobile Score Rating';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$score = round($data->field_field_mobile_overall_score[\'0\'][\'raw\'][\'value\']);
if ($score < 50) print \'Slow\';
elseif ($score < 90) print \'Moderate\';
else print \'Fast\';
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['path'] = 'download/mobile/report/xls-new';
  $handler->display->display_options['sitename_title'] = 0;
  $export['mobile_report_export'] = $view;

  return $export;
}
