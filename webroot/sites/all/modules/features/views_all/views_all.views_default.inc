<?php
/**
 * @file
 * views_all.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_all_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agency_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'agency_page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Agency Page';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
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
  );
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: SSL Score */
  $handler->display->display_options['fields']['field_ssl_score']['id'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['table'] = 'field_data_field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['field'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_ssl_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['title'] = 'Agency %1';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary_options']['items_per_page'] = '25';
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

  /* Display: Agency Page */
  $handler = $view->new_display('page', 'Agency Page', 'page');
  $handler->display->display_options['display_description'] = 'Agency Page';
  $handler->display->display_options['path'] = 'agency/%/data';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id_1']['id'] = 'field_web_agency_id_1';
  $handler->display->display_options['fields']['field_web_agency_id_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_web_agency_id_1']['label'] = 'Number of Websites';
  $handler->display->display_options['fields']['field_web_agency_id_1']['separator'] = ', ';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: SSL Score */
  $handler->display->display_options['fields']['field_ssl_score']['id'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['table'] = 'field_data_field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['field'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_ssl_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_2');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id_1']['id'] = 'field_web_agency_id_1';
  $handler->display->display_options['fields']['field_web_agency_id_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_web_agency_id_1']['label'] = 'Number of Websites';
  $handler->display->display_options['fields']['field_web_agency_id_1']['separator'] = ', ';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: SSL Score */
  $handler->display->display_options['fields']['field_ssl_score']['id'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['table'] = 'field_data_field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['field'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_ssl_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $export['agency_page'] = $view;

  $view = new view();
  $view->name = 'all_agency_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All Agency Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Agency Data';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Agency';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'agency/all/data';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_web_agency_id' => 'field_web_agency_id',
    'field_ssl_score' => 'field_ssl_score',
  );
  $handler->display->display_options['style_options']['default'] = 'field_ssl_score';
  $handler->display->display_options['style_options']['info'] = array(
    'field_web_agency_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ssl_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
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

  /* Display: SSL Chart */
  $handler = $view->new_display('block', 'SSL Chart', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'column';
  $handler->display->display_options['style_options']['library'] = 'google';
  $handler->display->display_options['style_options']['label_field'] = 'field_agency_code';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_ssl_score' => 'field_ssl_score',
    'field_agency_code' => 0,
    'field_web_agency_id' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_agency_code' => '#2f7ed8',
    'field_web_agency_id' => '#0d233a',
    'field_ssl_score' => '#8bbc21',
  );
  $handler->display->display_options['style_options']['width'] = '';
  $handler->display->display_options['style_options']['height'] = '';
  $handler->display->display_options['style_options']['xaxis_labels_rotation'] = '45';
  $handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Agency Code */
  $handler->display->display_options['fields']['field_agency_code']['id'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['field'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['relationship'] = 'field_web_agency_id_nid';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: SSL Score (field_ssl_score)) */
  $handler->display->display_options['sorts']['field_ssl_score_value']['id'] = 'field_ssl_score_value';
  $handler->display->display_options['sorts']['field_ssl_score_value']['table'] = 'field_data_field_ssl_score';
  $handler->display->display_options['sorts']['field_ssl_score_value']['field'] = 'field_ssl_score_value';
  $handler->display->display_options['sorts']['field_ssl_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_ssl_score_value']['order'] = 'DESC';
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
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Agency ID (field_web_agency_id)';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Agency Code (field_agency_code) */
  $handler->display->display_options['filters']['field_agency_code_value']['id'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['filters']['field_agency_code_value']['field'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_agency_code_value']['operator'] = 'not empty';

  /* Display: SSL Chart New */
  $handler = $view->new_display('block', 'SSL Chart New', 'block_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'google_chart_tools_views';
  $handler->display->display_options['style_options']['type'] = 'ColumnChart';
  $handler->display->display_options['style_options']['width'] = '600';
  $handler->display->display_options['style_options']['height'] = '400';
  $handler->display->display_options['style_options']['3d'] = 1;
  $handler->display->display_options['style_options']['isstacked'] = 0;
  $handler->display->display_options['style_options']['pointsize'] = '0';
  $handler->display->display_options['style_options']['colors'] = '#0071bc, #e31c3d, #00a6d2, #fdb81e, #48a463';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Agency Code */
  $handler->display->display_options['fields']['field_agency_code']['id'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['field'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['relationship'] = 'field_web_agency_id_nid';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: SSL Score (field_ssl_score)) */
  $handler->display->display_options['sorts']['field_ssl_score_value']['id'] = 'field_ssl_score_value';
  $handler->display->display_options['sorts']['field_ssl_score_value']['table'] = 'field_data_field_ssl_score';
  $handler->display->display_options['sorts']['field_ssl_score_value']['field'] = 'field_ssl_score_value';
  $handler->display->display_options['sorts']['field_ssl_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_ssl_score_value']['order'] = 'DESC';
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
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Agency ID (field_web_agency_id)';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Agency Code (field_agency_code) */
  $handler->display->display_options['filters']['field_agency_code_value']['id'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['filters']['field_agency_code_value']['field'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_agency_code_value']['operator'] = 'not empty';

  /* Display: SSL Chart TPL */
  $handler = $view->new_display('block', 'SSL Chart TPL', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Agency SSL Data';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Agency Code */
  $handler->display->display_options['fields']['field_agency_code']['id'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['field'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['relationship'] = 'field_web_agency_id_nid';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: SSL Score (field_ssl_score)) */
  $handler->display->display_options['sorts']['field_ssl_score_value']['id'] = 'field_ssl_score_value';
  $handler->display->display_options['sorts']['field_ssl_score_value']['table'] = 'field_data_field_ssl_score';
  $handler->display->display_options['sorts']['field_ssl_score_value']['field'] = 'field_ssl_score_value';
  $handler->display->display_options['sorts']['field_ssl_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_ssl_score_value']['order'] = 'DESC';
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
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Agency ID (field_web_agency_id)';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Agency Code (field_agency_code) */
  $handler->display->display_options['filters']['field_agency_code_value']['id'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['filters']['field_agency_code_value']['field'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_agency_code_value']['operator'] = 'not empty';

  /* Display: HTTPS Chart TPL */
  $handler = $view->new_display('block', 'HTTPS Chart TPL', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Agency HTTPS Data';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Agency Code */
  $handler->display->display_options['fields']['field_agency_code']['id'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['field'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['relationship'] = 'field_web_agency_id_nid';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: AVG(Content: HTTPS Score) */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: HTTPS Score (field_https_score)) */
  $handler->display->display_options['sorts']['field_https_score_value']['id'] = 'field_https_score_value';
  $handler->display->display_options['sorts']['field_https_score_value']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['sorts']['field_https_score_value']['field'] = 'field_https_score_value';
  $handler->display->display_options['sorts']['field_https_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_https_score_value']['order'] = 'DESC';
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
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Agency ID (field_web_agency_id)';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Agency Code (field_agency_code) */
  $handler->display->display_options['filters']['field_agency_code_value']['id'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['filters']['field_agency_code_value']['field'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_agency_code_value']['operator'] = 'not empty';

  /* Display: DAP Chart TPL */
  $handler = $view->new_display('block', 'DAP Chart TPL', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Agency DAP Data';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Agency Code */
  $handler->display->display_options['fields']['field_agency_code']['id'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['field'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['relationship'] = 'field_web_agency_id_nid';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: AVG(Content: DAP Score) */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: DAP Score (field_dap_score)) */
  $handler->display->display_options['sorts']['field_dap_score_value']['id'] = 'field_dap_score_value';
  $handler->display->display_options['sorts']['field_dap_score_value']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['sorts']['field_dap_score_value']['field'] = 'field_dap_score_value';
  $handler->display->display_options['sorts']['field_dap_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_dap_score_value']['order'] = 'DESC';
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
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Agency ID (field_web_agency_id)';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Agency Code (field_agency_code) */
  $handler->display->display_options['filters']['field_agency_code_value']['id'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['filters']['field_agency_code_value']['field'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_agency_code_value']['operator'] = 'not empty';

  /* Display: Mobile Chart TPL */
  $handler = $view->new_display('block', 'Mobile Chart TPL', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Agency Mobile Overall Data';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Agency Code */
  $handler->display->display_options['fields']['field_agency_code']['id'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['field'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['relationship'] = 'field_web_agency_id_nid';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: AVG(Content: Mobile Overall Score) */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: Mobile Overall Score (field_mobile_overall_score)) */
  $handler->display->display_options['sorts']['field_mobile_overall_score_value']['id'] = 'field_mobile_overall_score_value';
  $handler->display->display_options['sorts']['field_mobile_overall_score_value']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['sorts']['field_mobile_overall_score_value']['field'] = 'field_mobile_overall_score_value';
  $handler->display->display_options['sorts']['field_mobile_overall_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_mobile_overall_score_value']['order'] = 'DESC';
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
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Agency ID (field_web_agency_id)';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Agency Code (field_agency_code) */
  $handler->display->display_options['filters']['field_agency_code_value']['id'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['filters']['field_agency_code_value']['field'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_agency_code_value']['operator'] = 'not empty';

  /* Display: Mobile Performance TPL */
  $handler = $view->new_display('block', 'Mobile Performance TPL', 'block_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Agency Mobile Performance Data';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Agency Code */
  $handler->display->display_options['fields']['field_agency_code']['id'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['field'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['relationship'] = 'field_web_agency_id_nid';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: AVG(Content: Mobile Performance Score) */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: Mobile Performance Score (field_mobile_performance_score)) */
  $handler->display->display_options['sorts']['field_mobile_performance_score_value']['id'] = 'field_mobile_performance_score_value';
  $handler->display->display_options['sorts']['field_mobile_performance_score_value']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['sorts']['field_mobile_performance_score_value']['field'] = 'field_mobile_performance_score_value';
  $handler->display->display_options['sorts']['field_mobile_performance_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_mobile_performance_score_value']['order'] = 'DESC';
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
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Agency ID (field_web_agency_id)';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Agency Code (field_agency_code) */
  $handler->display->display_options['filters']['field_agency_code_value']['id'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['filters']['field_agency_code_value']['field'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_agency_code_value']['operator'] = 'not empty';

  /* Display: Mobile Friendly TPL */
  $handler = $view->new_display('block', 'Mobile Friendly TPL', 'block_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Agency Mobile Friendly Data';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_web_agency_id_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Agency Code */
  $handler->display->display_options['fields']['field_agency_code']['id'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['field'] = 'field_agency_code';
  $handler->display->display_options['fields']['field_agency_code']['relationship'] = 'field_web_agency_id_nid';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: AVG(Content: Mobile Usability Score) */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: Mobile Usability Score (field_mobile_usability_score)) */
  $handler->display->display_options['sorts']['field_mobile_usability_score_value']['id'] = 'field_mobile_usability_score_value';
  $handler->display->display_options['sorts']['field_mobile_usability_score_value']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['sorts']['field_mobile_usability_score_value']['field'] = 'field_mobile_usability_score_value';
  $handler->display->display_options['sorts']['field_mobile_usability_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_mobile_usability_score_value']['order'] = 'DESC';
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
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator_id'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Agency ID (field_web_agency_id)';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Agency Code (field_agency_code) */
  $handler->display->display_options['filters']['field_agency_code_value']['id'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['table'] = 'field_data_field_agency_code';
  $handler->display->display_options['filters']['field_agency_code_value']['field'] = 'field_agency_code_value';
  $handler->display->display_options['filters']['field_agency_code_value']['relationship'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_agency_code_value']['operator'] = 'not empty';

  /* Display: All Agency SSL Data */
  $handler = $view->new_display('page', 'All Agency SSL Data', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Agency SSL Data';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: SSL Score (field_ssl_score)) */
  $handler->display->display_options['sorts']['field_ssl_score_value']['id'] = 'field_ssl_score_value';
  $handler->display->display_options['sorts']['field_ssl_score_value']['table'] = 'field_data_field_ssl_score';
  $handler->display->display_options['sorts']['field_ssl_score_value']['field'] = 'field_ssl_score_value';
  $handler->display->display_options['sorts']['field_ssl_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_ssl_score_value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'agency/all/data/ssl';

  /* Display: All Agency HTTPS Data */
  $handler = $view->new_display('page', 'All Agency HTTPS Data', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Agency HTTPS Data';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: AVG(Content: HTTPS Score) */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: HTTPS Score (field_https_score)) */
  $handler->display->display_options['sorts']['field_https_score_value']['id'] = 'field_https_score_value';
  $handler->display->display_options['sorts']['field_https_score_value']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['sorts']['field_https_score_value']['field'] = 'field_https_score_value';
  $handler->display->display_options['sorts']['field_https_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_https_score_value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'agency/all/data/https';

  /* Display: All Agency DAP Data */
  $handler = $view->new_display('page', 'All Agency DAP Data', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Agency DAP Data';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: AVG(Content: DAP Score) */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: DAP Score (field_dap_score)) */
  $handler->display->display_options['sorts']['field_dap_score_value']['id'] = 'field_dap_score_value';
  $handler->display->display_options['sorts']['field_dap_score_value']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['sorts']['field_dap_score_value']['field'] = 'field_dap_score_value';
  $handler->display->display_options['sorts']['field_dap_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_dap_score_value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'agency/all/data/dap';

  /* Display: All Agency Mobile Data */
  $handler = $view->new_display('page', 'All Agency Mobile Data', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Agency Mobile Data';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: AVG(Content: Mobile Overall Score) */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: Mobile Performance Score) */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: AVG(Content: Mobile Usability Score) */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['group_type'] = 'avg';
  $handler->display->display_options['fields']['field_mobile_usability_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: AVG(Content: Mobile Overall Score (field_mobile_overall_score)) */
  $handler->display->display_options['sorts']['field_mobile_overall_score_value']['id'] = 'field_mobile_overall_score_value';
  $handler->display->display_options['sorts']['field_mobile_overall_score_value']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['sorts']['field_mobile_overall_score_value']['field'] = 'field_mobile_overall_score_value';
  $handler->display->display_options['sorts']['field_mobile_overall_score_value']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_mobile_overall_score_value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'agency/all/data/mobile';

  /* Display: Overall Compliance Report */
  $handler = $view->new_display('page', 'Overall Compliance Report', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Overall Compliance Report';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['path'] = 'overall/compliance';

  /* Display: Rating Overview */
  $handler = $view->new_display('block', 'Rating Overview', 'block_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Rating Overview';
  $handler->display->display_options['display_description'] = 'Rating Overview';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $export['all_agency_data'] = $view;

  $view = new view();
  $view->name = 'all_agency_top_508_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'All Website Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Agency Report';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
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
    'field_web_agency_id_nid' => array(
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
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'URL';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: SSL Score */
  $handler->display->display_options['fields']['field_ssl_score']['id'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['table'] = 'field_data_field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['field'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Overall Score */
  $handler->display->display_options['fields']['field_mobile_overall_score']['id'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['table'] = 'field_data_field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['field'] = 'field_mobile_overall_score';
  $handler->display->display_options['fields']['field_mobile_overall_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Performance Score */
  $handler->display->display_options['fields']['field_mobile_performance_score']['id'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['table'] = 'field_data_field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['field'] = 'field_mobile_performance_score';
  $handler->display->display_options['fields']['field_mobile_performance_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Mobile Usability Score */
  $handler->display->display_options['fields']['field_mobile_usability_score']['id'] = 'field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['table'] = 'field_data_field_mobile_usability_score';
  $handler->display->display_options['fields']['field_mobile_usability_score']['field'] = 'field_mobile_usability_score';
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
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['label'] = 'Agency';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['operator'] = 'field_web_agency_id_nid_op';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['identifier'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'website/all/reports';
  $export['all_agency_top_508_report'] = $view;

  $view = new view();
  $view->name = 'https';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'https scan';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['type'] = 'text_plain';
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
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
    'https_dap_scan_information' => 'https_dap_scan_information',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  /* Display: https scan chart */
  $handler = $view->new_display('page', 'https scan chart', 'page_1');
  $handler->display->display_options['display_description'] = 'https analytics';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['type'] = 'text_plain';
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = '';
  $handler->display->display_options['fields']['field_website_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_website_id']['settings'] = array(
    'alias' => 0,
    'absolute' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Website ID (field_website_id) */
  $handler->display->display_options['arguments']['field_website_id_nid']['id'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['arguments']['field_website_id_nid']['field'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'https/%';
  $export['https'] = $view;

  $view = new view();
  $view->name = 'website_information';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'website information';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'website information';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = '';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: IP Address */
  $handler->display->display_options['fields']['field_ip_address']['id'] = 'field_ip_address';
  $handler->display->display_options['fields']['field_ip_address']['table'] = 'field_data_field_ip_address';
  $handler->display->display_options['fields']['field_ip_address']['field'] = 'field_ip_address';
  $handler->display->display_options['fields']['field_ip_address']['label'] = 'IP';
  /* Field: Content: DNS Names */
  $handler->display->display_options['fields']['field_dns_names']['id'] = 'field_dns_names';
  $handler->display->display_options['fields']['field_dns_names']['table'] = 'field_data_field_dns_names';
  $handler->display->display_options['fields']['field_dns_names']['field'] = 'field_dns_names';
  $handler->display->display_options['fields']['field_dns_names']['label'] = 'DNS';
  /* Field: Content: CDN Provider name */
  $handler->display->display_options['fields']['field_cdn_provider_name']['id'] = 'field_cdn_provider_name';
  $handler->display->display_options['fields']['field_cdn_provider_name']['table'] = 'field_data_field_cdn_provider_name';
  $handler->display->display_options['fields']['field_cdn_provider_name']['field'] = 'field_cdn_provider_name';
  $handler->display->display_options['fields']['field_cdn_provider_name']['label'] = 'Hosted At';
  /* Field: Content: Cloud Provider */
  $handler->display->display_options['fields']['field_cloud_provider']['id'] = 'field_cloud_provider';
  $handler->display->display_options['fields']['field_cloud_provider']['table'] = 'field_data_field_cloud_provider';
  $handler->display->display_options['fields']['field_cloud_provider']['field'] = 'field_cloud_provider';
  $handler->display->display_options['fields']['field_cloud_provider']['label'] = '';
  $handler->display->display_options['fields']['field_cloud_provider']['element_label_colon'] = FALSE;
  /* Field: Content: Alexa ranking */
  $handler->display->display_options['fields']['field_alexa_ranking']['id'] = 'field_alexa_ranking';
  $handler->display->display_options['fields']['field_alexa_ranking']['table'] = 'field_data_field_alexa_ranking';
  $handler->display->display_options['fields']['field_alexa_ranking']['field'] = 'field_alexa_ranking';
  $handler->display->display_options['fields']['field_alexa_ranking']['label'] = 'Alexa Ranking';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Website ID (field_website_id) */
  $handler->display->display_options['arguments']['field_website_id_nid']['id'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['arguments']['field_website_id_nid']['field'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary_options']['items_per_page'] = '25';
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
    'domain_scan_information' => 'domain_scan_information',
  );

  /* Display: Website Information Page */
  $handler = $view->new_display('page', 'Website Information Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Website Information';
  $handler->display->display_options['display_description'] = 'Website Information Page';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Website ID (field_website_id) */
  $handler->display->display_options['arguments']['field_website_id_nid']['id'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['arguments']['field_website_id_nid']['field'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'website_information/%/%/show';

  /* Display: Website Information */
  $handler = $view->new_display('block', 'Website Information', 'block');
  $handler->display->display_options['display_description'] = 'Website Information';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Website ID (field_website_id) */
  $handler->display->display_options['arguments']['field_website_id_nid']['id'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['arguments']['field_website_id_nid']['field'] = 'field_website_id_nid';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_website_id_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_website_id_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Website Information';

  /* Display: Domain Information */
  $handler = $view->new_display('block', 'Domain Information', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Domain Information';
  $handler->display->display_options['display_description'] = 'Domain Information';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = '';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Common Name */
  $handler->display->display_options['fields']['field_dom_common_name']['id'] = 'field_dom_common_name';
  $handler->display->display_options['fields']['field_dom_common_name']['table'] = 'field_data_field_dom_common_name';
  $handler->display->display_options['fields']['field_dom_common_name']['field'] = 'field_dom_common_name';
  /* Field: Content: Subject Alternative Name */
  $handler->display->display_options['fields']['field_subject_alternative_name']['id'] = 'field_subject_alternative_name';
  $handler->display->display_options['fields']['field_subject_alternative_name']['table'] = 'field_data_field_subject_alternative_name';
  $handler->display->display_options['fields']['field_subject_alternative_name']['field'] = 'field_subject_alternative_name';
  $handler->display->display_options['fields']['field_subject_alternative_name']['label'] = 'SAN';
  /* Field: Content: SSL Certificate Valid from */
  $handler->display->display_options['fields']['field_ssl_certificate_valid_from']['id'] = 'field_ssl_certificate_valid_from';
  $handler->display->display_options['fields']['field_ssl_certificate_valid_from']['table'] = 'field_data_field_ssl_certificate_valid_from';
  $handler->display->display_options['fields']['field_ssl_certificate_valid_from']['field'] = 'field_ssl_certificate_valid_from';
  $handler->display->display_options['fields']['field_ssl_certificate_valid_from']['label'] = 'Valid From';
  /* Field: Content: SSL Certificate Expiry */
  $handler->display->display_options['fields']['field_ssl_certificate_expiry']['id'] = 'field_ssl_certificate_expiry';
  $handler->display->display_options['fields']['field_ssl_certificate_expiry']['table'] = 'field_data_field_ssl_certificate_expiry';
  $handler->display->display_options['fields']['field_ssl_certificate_expiry']['field'] = 'field_ssl_certificate_expiry';
  $handler->display->display_options['fields']['field_ssl_certificate_expiry']['label'] = 'Valid To';
  /* Field: Content: Certificate Issuer */
  $handler->display->display_options['fields']['field_certificate_issuer']['id'] = 'field_certificate_issuer';
  $handler->display->display_options['fields']['field_certificate_issuer']['table'] = 'field_data_field_certificate_issuer';
  $handler->display->display_options['fields']['field_certificate_issuer']['field'] = 'field_certificate_issuer';
  /* Field: Content: Certificate provider */
  $handler->display->display_options['fields']['field_certificate_provider']['id'] = 'field_certificate_provider';
  $handler->display->display_options['fields']['field_certificate_provider']['table'] = 'field_data_field_certificate_provider';
  $handler->display->display_options['fields']['field_certificate_provider']['field'] = 'field_certificate_provider';
  /* Field: Content: SSL Certificate Status */
  $handler->display->display_options['fields']['field_ssl_certificate_status']['id'] = 'field_ssl_certificate_status';
  $handler->display->display_options['fields']['field_ssl_certificate_status']['table'] = 'field_data_field_ssl_certificate_status';
  $handler->display->display_options['fields']['field_ssl_certificate_status']['field'] = 'field_ssl_certificate_status';
  $handler->display->display_options['fields']['field_ssl_certificate_status']['label'] = 'Certificate Status';
  /* Field: Content: SSL Certificate Chain */
  $handler->display->display_options['fields']['field_ssl_certificate_chain']['id'] = 'field_ssl_certificate_chain';
  $handler->display->display_options['fields']['field_ssl_certificate_chain']['table'] = 'field_data_field_ssl_certificate_chain';
  $handler->display->display_options['fields']['field_ssl_certificate_chain']['field'] = 'field_ssl_certificate_chain';
  $handler->display->display_options['fields']['field_ssl_certificate_chain']['label'] = 'Certificate Chain';
  $handler->display->display_options['block_description'] = 'Domain Information';

  /* Display: SSL Information */
  $handler = $view->new_display('block', 'SSL Information', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'SSL Information';
  $handler->display->display_options['display_description'] = 'SSL Information';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = '';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Downgrade Attacks */
  $handler->display->display_options['fields']['field_downgrade_attacks']['id'] = 'field_downgrade_attacks';
  $handler->display->display_options['fields']['field_downgrade_attacks']['table'] = 'field_data_field_downgrade_attacks';
  $handler->display->display_options['fields']['field_downgrade_attacks']['field'] = 'field_downgrade_attacks';
  $handler->display->display_options['fields']['field_downgrade_attacks']['label'] = 'Downgrade Attack';
  /* Field: Content: HTTP Public Key Pinning (HPKP) */
  $handler->display->display_options['fields']['field_http_public_hpkp']['id'] = 'field_http_public_hpkp';
  $handler->display->display_options['fields']['field_http_public_hpkp']['table'] = 'field_data_field_http_public_hpkp';
  $handler->display->display_options['fields']['field_http_public_hpkp']['field'] = 'field_http_public_hpkp';
  /* Field: Content: OpenSSL CCS Injection */
  $handler->display->display_options['fields']['field_openssl_ccs_injection']['id'] = 'field_openssl_ccs_injection';
  $handler->display->display_options['fields']['field_openssl_ccs_injection']['table'] = 'field_data_field_openssl_ccs_injection';
  $handler->display->display_options['fields']['field_openssl_ccs_injection']['field'] = 'field_openssl_ccs_injection';
  /* Field: Content: OpenSSL Heartbleed */
  $handler->display->display_options['fields']['field_openssl_heartbleed']['id'] = 'field_openssl_heartbleed';
  $handler->display->display_options['fields']['field_openssl_heartbleed']['table'] = 'field_data_field_openssl_heartbleed';
  $handler->display->display_options['fields']['field_openssl_heartbleed']['field'] = 'field_openssl_heartbleed';
  /* Field: Content: SSL Score */
  $handler->display->display_options['fields']['field_ssl_score']['id'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['table'] = 'field_data_field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['field'] = 'field_ssl_score';
  $handler->display->display_options['fields']['field_ssl_score']['type'] = 'text_default';
  /* Field: Content: SSL V2 Support */
  $handler->display->display_options['fields']['field_ssl_v2_support']['id'] = 'field_ssl_v2_support';
  $handler->display->display_options['fields']['field_ssl_v2_support']['table'] = 'field_data_field_ssl_v2_support';
  $handler->display->display_options['fields']['field_ssl_v2_support']['field'] = 'field_ssl_v2_support';
  /* Field: Content: SSL V3 Support */
  $handler->display->display_options['fields']['field_ssl_v3_support']['id'] = 'field_ssl_v3_support';
  $handler->display->display_options['fields']['field_ssl_v3_support']['table'] = 'field_data_field_ssl_v3_support';
  $handler->display->display_options['fields']['field_ssl_v3_support']['field'] = 'field_ssl_v3_support';
  /* Field: Content: TLS V1 Support */
  $handler->display->display_options['fields']['field_tls_v1_support']['id'] = 'field_tls_v1_support';
  $handler->display->display_options['fields']['field_tls_v1_support']['table'] = 'field_data_field_tls_v1_support';
  $handler->display->display_options['fields']['field_tls_v1_support']['field'] = 'field_tls_v1_support';
  /* Field: Content: TLS V1.1 Support */
  $handler->display->display_options['fields']['field_tls_v1_1_support']['id'] = 'field_tls_v1_1_support';
  $handler->display->display_options['fields']['field_tls_v1_1_support']['table'] = 'field_data_field_tls_v1_1_support';
  $handler->display->display_options['fields']['field_tls_v1_1_support']['field'] = 'field_tls_v1_1_support';
  /* Field: Content: TLS V1.2 Support */
  $handler->display->display_options['fields']['field_tls_v1_2_support']['id'] = 'field_tls_v1_2_support';
  $handler->display->display_options['fields']['field_tls_v1_2_support']['table'] = 'field_data_field_tls_v1_2_support';
  $handler->display->display_options['fields']['field_tls_v1_2_support']['field'] = 'field_tls_v1_2_support';
  $handler->display->display_options['block_description'] = 'SSL Information';

  /* Display: HTTPS Information */
  $handler = $view->new_display('block', 'HTTPS Information', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'HTTPS Information';
  $handler->display->display_options['display_description'] = 'HTTPS Information';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = '';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: Enforce HTTPS */
  $handler->display->display_options['fields']['field_enforce_https']['id'] = 'field_enforce_https';
  $handler->display->display_options['fields']['field_enforce_https']['table'] = 'field_data_field_enforce_https';
  $handler->display->display_options['fields']['field_enforce_https']['field'] = 'field_enforce_https';
  /* Field: Content: HSTS Status */
  $handler->display->display_options['fields']['field_hsts_status']['id'] = 'field_hsts_status';
  $handler->display->display_options['fields']['field_hsts_status']['table'] = 'field_data_field_hsts_status';
  $handler->display->display_options['fields']['field_hsts_status']['field'] = 'field_hsts_status';
  /* Field: Content: HTTPS Score */
  $handler->display->display_options['fields']['field_https_score']['id'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['table'] = 'field_data_field_https_score';
  $handler->display->display_options['fields']['field_https_score']['field'] = 'field_https_score';
  $handler->display->display_options['fields']['field_https_score']['type'] = 'text_default';
  /* Field: Content: HTTPS Status */
  $handler->display->display_options['fields']['field_https_status']['id'] = 'field_https_status';
  $handler->display->display_options['fields']['field_https_status']['table'] = 'field_data_field_https_status';
  $handler->display->display_options['fields']['field_https_status']['field'] = 'field_https_status';
  /* Field: Content: Preload Status */
  $handler->display->display_options['fields']['field_preload_status']['id'] = 'field_preload_status';
  $handler->display->display_options['fields']['field_preload_status']['table'] = 'field_data_field_preload_status';
  $handler->display->display_options['fields']['field_preload_status']['field'] = 'field_preload_status';
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
    'https_dap_scan_information' => 'https_dap_scan_information',
  );

  /* Display: DAP Information */
  $handler = $view->new_display('block', 'DAP Information', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'DAP Information';
  $handler->display->display_options['display_description'] = 'DAP Information';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = '';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_nid';
  /* Field: Content: DAP Score */
  $handler->display->display_options['fields']['field_dap_score']['id'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['table'] = 'field_data_field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['field'] = 'field_dap_score';
  $handler->display->display_options['fields']['field_dap_score']['type'] = 'text_default';
  /* Field: Content: DAP Status */
  $handler->display->display_options['fields']['field_dap_status']['id'] = 'field_dap_status';
  $handler->display->display_options['fields']['field_dap_status']['table'] = 'field_data_field_dap_status';
  $handler->display->display_options['fields']['field_dap_status']['field'] = 'field_dap_status';
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
    'https_dap_scan_information' => 'https_dap_scan_information',
  );

  /* Display: Web Agency Information */
  $handler = $view->new_display('block', 'Web Agency Information', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Agency Information';
  $handler->display->display_options['display_description'] = 'Web Agency Information';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_web_parent_agency']['id'] = 'field_web_parent_agency';
  $handler->display->display_options['fields']['field_web_parent_agency']['table'] = 'field_data_field_web_parent_agency';
  $handler->display->display_options['fields']['field_web_parent_agency']['field'] = 'field_web_parent_agency';
  $handler->display->display_options['fields']['field_web_parent_agency']['label'] = 'Parent Agency';
  /* Field: Content: Parent Agency Name */
  $handler->display->display_options['fields']['field_parent_agency_name']['id'] = 'field_parent_agency_name';
  $handler->display->display_options['fields']['field_parent_agency_name']['table'] = 'field_data_field_parent_agency_name';
  $handler->display->display_options['fields']['field_parent_agency_name']['field'] = 'field_parent_agency_name';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'URL';
  /* Field: Content: Agency Logo */
  $handler->display->display_options['fields']['field_agency_logo']['id'] = 'field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['table'] = 'field_data_field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['field'] = 'field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_agency_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Agency Website */
  $handler->display->display_options['fields']['field_agency_website']['id'] = 'field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['table'] = 'field_data_field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['field'] = 'field_agency_website';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Agency Logo */
  $handler->display->display_options['fields']['field_agency_logo']['id'] = 'field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['table'] = 'field_data_field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['field'] = 'field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['label'] = '';
  $handler->display->display_options['fields']['field_agency_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_agency_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Agency Website */
  $handler->display->display_options['fields']['field_agency_website']['id'] = 'field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['table'] = 'field_data_field_agency_website';
  $handler->display->display_options['fields']['field_agency_website']['field'] = 'field_agency_website';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['id'] = 'field_web_agency_id_nid';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_web_agency_id_nid']['validate']['type'] = 'node';
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
    'agency' => 'agency',
  );
  $handler->display->display_options['displays'] = array(
    'block_5' => 'block_5',
    'default' => 0,
    'page' => 0,
    'block' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'block_3' => 0,
    'block_4' => 0,
  );
  $export['website_information'] = $view;

  return $export;
}
