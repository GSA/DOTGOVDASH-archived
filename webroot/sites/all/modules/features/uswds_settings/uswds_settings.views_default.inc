<?php

/**
 * @file
 * uswds_settings.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uswds_settings_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'uswds_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'USWDS Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'USWDS Report';
  $handler->display->display_options['css_class'] = 'white-back';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    13 => '13',
    14 => '14',
    12 => '12',
    16 => '16',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
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
    'title' => array(
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
    'field_website_id' => 'field_website_id',
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'field_uswds_api_scan_time' => 'field_uswds_api_scan_time',
    'field_uswds_api_url' => 'field_uswds_api_url',
    'field_uswds_detected' => 'field_uswds_detected',
    'field_uswds_flag_detected' => 'field_uswds_flag_detected',
    'field_uswds_flagin_css_detected' => 'field_uswds_flagin_css_detected',
    'field_uswds_incss_detected' => 'field_uswds_incss_detected',
    'field_uswds_marriweather_font_de' => 'field_uswds_marriweather_font_de',
    'field_uswds_public_sans_font_det' => 'field_uswds_public_sans_font_det',
    'field_uswds_scan_web_status_code' => 'field_uswds_scan_web_status_code',
    'field_uswds_score' => 'field_uswds_score',
    'field_uswds_source_san_font_det' => 'field_uswds_source_san_font_det',
    'field_uswds_status' => 'field_uswds_status',
    'field_uswds_tables' => 'field_uswds_tables',
    'field_uswds_total_custom_score' => 'field_uswds_total_custom_score',
    'field_uswds_usa_classes_detected' => 'field_uswds_usa_classes_detected',
    'field_uswds_usa_detected' => 'field_uswds_usa_detected',
    'field_uswds_version' => 'field_uswds_version',
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
    'field_uswds_api_scan_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_api_url' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_detected' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_flag_detected' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_flagin_css_detected' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_incss_detected' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_marriweather_font_de' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_public_sans_font_det' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_scan_web_status_code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_source_san_font_det' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_tables' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_total_custom_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_usa_classes_detected' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_usa_detected' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uswds_version' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div align="left">USWDS is toolkit of design principles, user experience guidance, and code. Agencies can—and should—adopt USWDS incrementally. <br>Use of USWDS is not binary so we can\'t definitively say whether a site does or does not use USWDS.<br>The USWDS scan checks each domain for the use of&nbsp;<a href="https://designsystem.digital.gov/" rel="nofollow">U.S. Web Design System (USWDS)</a>&nbsp;code and the code version. <br> To know more about USWDS, check this link&nbsp;<a href="https://designsystem.digital.gov/maturity-model/">https://designsystem.digital.gov/maturity-model/</a>&nbsp;.<br></div><br>
<div align="right"><p>Download USWDS Reports: <a href="/uswds/download/csv"> csv </a> | <a href="/uswds/download/xls">xls</a></p></div><br>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = 'Website';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Link to Scan';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Raw Scan Link';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  /* Field: Content: USWDS API Scan Time */
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['id'] = 'field_uswds_api_scan_time';
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['table'] = 'field_data_field_uswds_api_scan_time';
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['field'] = 'field_uswds_api_scan_time';
  /* Field: Content: USWDS API Url */
  $handler->display->display_options['fields']['field_uswds_api_url']['id'] = 'field_uswds_api_url';
  $handler->display->display_options['fields']['field_uswds_api_url']['table'] = 'field_data_field_uswds_api_url';
  $handler->display->display_options['fields']['field_uswds_api_url']['field'] = 'field_uswds_api_url';
  /* Field: Content: USWDS detected */
  $handler->display->display_options['fields']['field_uswds_detected']['id'] = 'field_uswds_detected';
  $handler->display->display_options['fields']['field_uswds_detected']['table'] = 'field_data_field_uswds_detected';
  $handler->display->display_options['fields']['field_uswds_detected']['field'] = 'field_uswds_detected';
  /* Field: Content: USWDS Flag Detected */
  $handler->display->display_options['fields']['field_uswds_flag_detected']['id'] = 'field_uswds_flag_detected';
  $handler->display->display_options['fields']['field_uswds_flag_detected']['table'] = 'field_data_field_uswds_flag_detected';
  $handler->display->display_options['fields']['field_uswds_flag_detected']['field'] = 'field_uswds_flag_detected';
  /* Field: Content: USWDS Flagin CSS detected */
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['id'] = 'field_uswds_flagin_css_detected';
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['table'] = 'field_data_field_uswds_flagin_css_detected';
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['field'] = 'field_uswds_flagin_css_detected';
  /* Field: Content: USWDS Incss detected */
  $handler->display->display_options['fields']['field_uswds_incss_detected']['id'] = 'field_uswds_incss_detected';
  $handler->display->display_options['fields']['field_uswds_incss_detected']['table'] = 'field_data_field_uswds_incss_detected';
  $handler->display->display_options['fields']['field_uswds_incss_detected']['field'] = 'field_uswds_incss_detected';
  /* Field: Content: USWDS Marriweather font detetcted */
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['id'] = 'field_uswds_marriweather_font_de';
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['table'] = 'field_data_field_uswds_marriweather_font_de';
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['field'] = 'field_uswds_marriweather_font_de';
  /* Field: Content: USWDS Public Sans Font detected */
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['id'] = 'field_uswds_public_sans_font_det';
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['table'] = 'field_data_field_uswds_public_sans_font_det';
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['field'] = 'field_uswds_public_sans_font_det';
  /* Field: Content: USWDS Scan Website Status Code */
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['id'] = 'field_uswds_scan_web_status_code';
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['table'] = 'field_data_field_uswds_scan_web_status_code';
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['field'] = 'field_uswds_scan_web_status_code';
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USWDS Source SAN Font_det */
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['id'] = 'field_uswds_source_san_font_det';
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['table'] = 'field_data_field_uswds_source_san_font_det';
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['field'] = 'field_uswds_source_san_font_det';
  /* Field: Content: USWDS status */
  $handler->display->display_options['fields']['field_uswds_status']['id'] = 'field_uswds_status';
  $handler->display->display_options['fields']['field_uswds_status']['table'] = 'field_data_field_uswds_status';
  $handler->display->display_options['fields']['field_uswds_status']['field'] = 'field_uswds_status';
  /* Field: Content: USWDS Tables */
  $handler->display->display_options['fields']['field_uswds_tables']['id'] = 'field_uswds_tables';
  $handler->display->display_options['fields']['field_uswds_tables']['table'] = 'field_data_field_uswds_tables';
  $handler->display->display_options['fields']['field_uswds_tables']['field'] = 'field_uswds_tables';
  /* Field: Content: USWDS Total Custom Score */
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['id'] = 'field_uswds_total_custom_score';
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['table'] = 'field_data_field_uswds_total_custom_score';
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['field'] = 'field_uswds_total_custom_score';
  /* Field: Content: USWDS USA classes detected */
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['id'] = 'field_uswds_usa_classes_detected';
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['table'] = 'field_data_field_uswds_usa_classes_detected';
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['field'] = 'field_uswds_usa_classes_detected';
  /* Field: Content: USWDS USA detected */
  $handler->display->display_options['fields']['field_uswds_usa_detected']['id'] = 'field_uswds_usa_detected';
  $handler->display->display_options['fields']['field_uswds_usa_detected']['table'] = 'field_data_field_uswds_usa_detected';
  $handler->display->display_options['fields']['field_uswds_usa_detected']['field'] = 'field_uswds_usa_detected';
  /* Field: Content: USWDS Version */
  $handler->display->display_options['fields']['field_uswds_version']['id'] = 'field_uswds_version';
  $handler->display->display_options['fields']['field_uswds_version']['table'] = 'field_data_field_uswds_version';
  $handler->display->display_options['fields']['field_uswds_version']['field'] = 'field_uswds_version';
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uswds_scan' => 'uswds_scan',
  );
  /* Filter criterion: Field: Agency ID (field_web_agency_id) */
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['id'] = 'field_web_agency_id_nid_1';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['field'] = 'field_web_agency_id_nid';
  $handler->display->display_options['filters']['field_web_agency_id_nid_1']['operator'] = 'not empty';
  /* Filter criterion: Content: Website ID (field_website_id) */
  $handler->display->display_options['filters']['field_website_id_nid']['id'] = 'field_website_id_nid';
  $handler->display->display_options['filters']['field_website_id_nid']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['filters']['field_website_id_nid']['field'] = 'field_website_id_nid';
  $handler->display->display_options['filters']['field_website_id_nid']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'USWDS Code Usage Report';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="white-back" align="middle" >USWDS is toolkit of design principles, user experience guidance, and code. Agencies can—and should—adopt USWDS incrementally. <br>Use of USWDS is not binary so we can\'t definitively say whether a site does or does not use USWDS.<br>The USWDS scan checks each domain for the use of&nbsp;<a href="https://designsystem.digital.gov/" rel="nofollow">U.S. Web Design System (USWDS)</a>&nbsp;code and the code version. <br> To know more about USWDS, check this link&nbsp;<a href="https://designsystem.digital.gov/maturity-model/">https://designsystem.digital.gov/maturity-model/</a>&nbsp;.<br></div><br>
<div align="right"><p>Download USWDS Reports: <a href="/uswds/download/csv"> csv </a> | <a href="/uswds/download/xls">xls</a></p></div><br>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = 'Website';
  $handler->display->display_options['fields']['field_website_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['alter']['path'] = 'website/[field_website_id-nid]/information';
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Link to Scan';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Raw Scan Link';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = 'agency_home/[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: USWDS API Scan Time */
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['id'] = 'field_uswds_api_scan_time';
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['table'] = 'field_data_field_uswds_api_scan_time';
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['field'] = 'field_uswds_api_scan_time';
  /* Field: Content: USWDS API Url */
  $handler->display->display_options['fields']['field_uswds_api_url']['id'] = 'field_uswds_api_url';
  $handler->display->display_options['fields']['field_uswds_api_url']['table'] = 'field_data_field_uswds_api_url';
  $handler->display->display_options['fields']['field_uswds_api_url']['field'] = 'field_uswds_api_url';
  /* Field: Content: USWDS detected */
  $handler->display->display_options['fields']['field_uswds_detected']['id'] = 'field_uswds_detected';
  $handler->display->display_options['fields']['field_uswds_detected']['table'] = 'field_data_field_uswds_detected';
  $handler->display->display_options['fields']['field_uswds_detected']['field'] = 'field_uswds_detected';
  /* Field: Content: USWDS Flag Detected */
  $handler->display->display_options['fields']['field_uswds_flag_detected']['id'] = 'field_uswds_flag_detected';
  $handler->display->display_options['fields']['field_uswds_flag_detected']['table'] = 'field_data_field_uswds_flag_detected';
  $handler->display->display_options['fields']['field_uswds_flag_detected']['field'] = 'field_uswds_flag_detected';
  /* Field: Content: USWDS Flagin CSS detected */
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['id'] = 'field_uswds_flagin_css_detected';
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['table'] = 'field_data_field_uswds_flagin_css_detected';
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['field'] = 'field_uswds_flagin_css_detected';
  /* Field: Content: USWDS Incss detected */
  $handler->display->display_options['fields']['field_uswds_incss_detected']['id'] = 'field_uswds_incss_detected';
  $handler->display->display_options['fields']['field_uswds_incss_detected']['table'] = 'field_data_field_uswds_incss_detected';
  $handler->display->display_options['fields']['field_uswds_incss_detected']['field'] = 'field_uswds_incss_detected';
  /* Field: Content: USWDS Marriweather font detetcted */
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['id'] = 'field_uswds_marriweather_font_de';
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['table'] = 'field_data_field_uswds_marriweather_font_de';
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['field'] = 'field_uswds_marriweather_font_de';
  /* Field: Content: USWDS Public Sans Font detected */
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['id'] = 'field_uswds_public_sans_font_det';
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['table'] = 'field_data_field_uswds_public_sans_font_det';
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['field'] = 'field_uswds_public_sans_font_det';
  /* Field: Content: USWDS Scan Website Status Code */
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['id'] = 'field_uswds_scan_web_status_code';
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['table'] = 'field_data_field_uswds_scan_web_status_code';
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['field'] = 'field_uswds_scan_web_status_code';
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USWDS Source SAN Font_det */
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['id'] = 'field_uswds_source_san_font_det';
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['table'] = 'field_data_field_uswds_source_san_font_det';
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['field'] = 'field_uswds_source_san_font_det';
  /* Field: Content: USWDS status */
  $handler->display->display_options['fields']['field_uswds_status']['id'] = 'field_uswds_status';
  $handler->display->display_options['fields']['field_uswds_status']['table'] = 'field_data_field_uswds_status';
  $handler->display->display_options['fields']['field_uswds_status']['field'] = 'field_uswds_status';
  /* Field: Content: USWDS Tables */
  $handler->display->display_options['fields']['field_uswds_tables']['id'] = 'field_uswds_tables';
  $handler->display->display_options['fields']['field_uswds_tables']['table'] = 'field_data_field_uswds_tables';
  $handler->display->display_options['fields']['field_uswds_tables']['field'] = 'field_uswds_tables';
  /* Field: Content: USWDS Total Custom Score */
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['id'] = 'field_uswds_total_custom_score';
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['table'] = 'field_data_field_uswds_total_custom_score';
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['field'] = 'field_uswds_total_custom_score';
  /* Field: Content: USWDS USA classes detected */
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['id'] = 'field_uswds_usa_classes_detected';
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['table'] = 'field_data_field_uswds_usa_classes_detected';
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['field'] = 'field_uswds_usa_classes_detected';
  /* Field: Content: USWDS USA detected */
  $handler->display->display_options['fields']['field_uswds_usa_detected']['id'] = 'field_uswds_usa_detected';
  $handler->display->display_options['fields']['field_uswds_usa_detected']['table'] = 'field_data_field_uswds_usa_detected';
  $handler->display->display_options['fields']['field_uswds_usa_detected']['field'] = 'field_uswds_usa_detected';
  /* Field: Content: USWDS Version */
  $handler->display->display_options['fields']['field_uswds_version']['id'] = 'field_uswds_version';
  $handler->display->display_options['fields']['field_uswds_version']['table'] = 'field_data_field_uswds_version';
  $handler->display->display_options['fields']['field_uswds_version']['field'] = 'field_uswds_version';
  $handler->display->display_options['path'] = 'website/all/uswds';

  /* Display: CSV Data export */
  $handler = $view->new_display('views_data_export', 'CSV Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'uswds_data.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = 'Website';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Link to Scan';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Raw Scan Link';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  /* Field: Content: USWDS API Scan Time */
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['id'] = 'field_uswds_api_scan_time';
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['table'] = 'field_data_field_uswds_api_scan_time';
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['field'] = 'field_uswds_api_scan_time';
  /* Field: Content: USWDS API Url */
  $handler->display->display_options['fields']['field_uswds_api_url']['id'] = 'field_uswds_api_url';
  $handler->display->display_options['fields']['field_uswds_api_url']['table'] = 'field_data_field_uswds_api_url';
  $handler->display->display_options['fields']['field_uswds_api_url']['field'] = 'field_uswds_api_url';
  /* Field: Content: USWDS detected */
  $handler->display->display_options['fields']['field_uswds_detected']['id'] = 'field_uswds_detected';
  $handler->display->display_options['fields']['field_uswds_detected']['table'] = 'field_data_field_uswds_detected';
  $handler->display->display_options['fields']['field_uswds_detected']['field'] = 'field_uswds_detected';
  /* Field: Content: USWDS Flag Detected */
  $handler->display->display_options['fields']['field_uswds_flag_detected']['id'] = 'field_uswds_flag_detected';
  $handler->display->display_options['fields']['field_uswds_flag_detected']['table'] = 'field_data_field_uswds_flag_detected';
  $handler->display->display_options['fields']['field_uswds_flag_detected']['field'] = 'field_uswds_flag_detected';
  /* Field: Content: USWDS Flagin CSS detected */
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['id'] = 'field_uswds_flagin_css_detected';
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['table'] = 'field_data_field_uswds_flagin_css_detected';
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['field'] = 'field_uswds_flagin_css_detected';
  /* Field: Content: USWDS Incss detected */
  $handler->display->display_options['fields']['field_uswds_incss_detected']['id'] = 'field_uswds_incss_detected';
  $handler->display->display_options['fields']['field_uswds_incss_detected']['table'] = 'field_data_field_uswds_incss_detected';
  $handler->display->display_options['fields']['field_uswds_incss_detected']['field'] = 'field_uswds_incss_detected';
  /* Field: Content: USWDS Marriweather font detetcted */
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['id'] = 'field_uswds_marriweather_font_de';
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['table'] = 'field_data_field_uswds_marriweather_font_de';
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['field'] = 'field_uswds_marriweather_font_de';
  /* Field: Content: USWDS Public Sans Font detected */
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['id'] = 'field_uswds_public_sans_font_det';
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['table'] = 'field_data_field_uswds_public_sans_font_det';
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['field'] = 'field_uswds_public_sans_font_det';
  /* Field: Content: USWDS Scan Website Status Code */
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['id'] = 'field_uswds_scan_web_status_code';
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['table'] = 'field_data_field_uswds_scan_web_status_code';
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['field'] = 'field_uswds_scan_web_status_code';
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USWDS Source SAN Font_det */
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['id'] = 'field_uswds_source_san_font_det';
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['table'] = 'field_data_field_uswds_source_san_font_det';
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['field'] = 'field_uswds_source_san_font_det';
  /* Field: Content: USWDS status */
  $handler->display->display_options['fields']['field_uswds_status']['id'] = 'field_uswds_status';
  $handler->display->display_options['fields']['field_uswds_status']['table'] = 'field_data_field_uswds_status';
  $handler->display->display_options['fields']['field_uswds_status']['field'] = 'field_uswds_status';
  /* Field: Content: USWDS Tables */
  $handler->display->display_options['fields']['field_uswds_tables']['id'] = 'field_uswds_tables';
  $handler->display->display_options['fields']['field_uswds_tables']['table'] = 'field_data_field_uswds_tables';
  $handler->display->display_options['fields']['field_uswds_tables']['field'] = 'field_uswds_tables';
  /* Field: Content: USWDS Total Custom Score */
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['id'] = 'field_uswds_total_custom_score';
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['table'] = 'field_data_field_uswds_total_custom_score';
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['field'] = 'field_uswds_total_custom_score';
  /* Field: Content: USWDS USA classes detected */
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['id'] = 'field_uswds_usa_classes_detected';
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['table'] = 'field_data_field_uswds_usa_classes_detected';
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['field'] = 'field_uswds_usa_classes_detected';
  /* Field: Content: USWDS USA detected */
  $handler->display->display_options['fields']['field_uswds_usa_detected']['id'] = 'field_uswds_usa_detected';
  $handler->display->display_options['fields']['field_uswds_usa_detected']['table'] = 'field_data_field_uswds_usa_detected';
  $handler->display->display_options['fields']['field_uswds_usa_detected']['field'] = 'field_uswds_usa_detected';
  /* Field: Content: USWDS Version */
  $handler->display->display_options['fields']['field_uswds_version']['id'] = 'field_uswds_version';
  $handler->display->display_options['fields']['field_uswds_version']['table'] = 'field_data_field_uswds_version';
  $handler->display->display_options['fields']['field_uswds_version']['field'] = 'field_uswds_version';
  $handler->display->display_options['path'] = 'uswds/download/csv';

  /* Display: XLS Data export */
  $handler = $view->new_display('views_data_export', 'XLS Data export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'uswds_data.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = 'Website';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Link to Scan';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Raw Scan Link';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  /* Field: Content: USWDS API Scan Time */
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['id'] = 'field_uswds_api_scan_time';
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['table'] = 'field_data_field_uswds_api_scan_time';
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['field'] = 'field_uswds_api_scan_time';
  /* Field: Content: USWDS API Url */
  $handler->display->display_options['fields']['field_uswds_api_url']['id'] = 'field_uswds_api_url';
  $handler->display->display_options['fields']['field_uswds_api_url']['table'] = 'field_data_field_uswds_api_url';
  $handler->display->display_options['fields']['field_uswds_api_url']['field'] = 'field_uswds_api_url';
  /* Field: Content: USWDS detected */
  $handler->display->display_options['fields']['field_uswds_detected']['id'] = 'field_uswds_detected';
  $handler->display->display_options['fields']['field_uswds_detected']['table'] = 'field_data_field_uswds_detected';
  $handler->display->display_options['fields']['field_uswds_detected']['field'] = 'field_uswds_detected';
  /* Field: Content: USWDS Flag Detected */
  $handler->display->display_options['fields']['field_uswds_flag_detected']['id'] = 'field_uswds_flag_detected';
  $handler->display->display_options['fields']['field_uswds_flag_detected']['table'] = 'field_data_field_uswds_flag_detected';
  $handler->display->display_options['fields']['field_uswds_flag_detected']['field'] = 'field_uswds_flag_detected';
  /* Field: Content: USWDS Flagin CSS detected */
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['id'] = 'field_uswds_flagin_css_detected';
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['table'] = 'field_data_field_uswds_flagin_css_detected';
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['field'] = 'field_uswds_flagin_css_detected';
  /* Field: Content: USWDS Incss detected */
  $handler->display->display_options['fields']['field_uswds_incss_detected']['id'] = 'field_uswds_incss_detected';
  $handler->display->display_options['fields']['field_uswds_incss_detected']['table'] = 'field_data_field_uswds_incss_detected';
  $handler->display->display_options['fields']['field_uswds_incss_detected']['field'] = 'field_uswds_incss_detected';
  /* Field: Content: USWDS Marriweather font detetcted */
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['id'] = 'field_uswds_marriweather_font_de';
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['table'] = 'field_data_field_uswds_marriweather_font_de';
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['field'] = 'field_uswds_marriweather_font_de';
  /* Field: Content: USWDS Public Sans Font detected */
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['id'] = 'field_uswds_public_sans_font_det';
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['table'] = 'field_data_field_uswds_public_sans_font_det';
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['field'] = 'field_uswds_public_sans_font_det';
  /* Field: Content: USWDS Scan Website Status Code */
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['id'] = 'field_uswds_scan_web_status_code';
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['table'] = 'field_data_field_uswds_scan_web_status_code';
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['field'] = 'field_uswds_scan_web_status_code';
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USWDS Source SAN Font_det */
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['id'] = 'field_uswds_source_san_font_det';
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['table'] = 'field_data_field_uswds_source_san_font_det';
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['field'] = 'field_uswds_source_san_font_det';
  /* Field: Content: USWDS status */
  $handler->display->display_options['fields']['field_uswds_status']['id'] = 'field_uswds_status';
  $handler->display->display_options['fields']['field_uswds_status']['table'] = 'field_data_field_uswds_status';
  $handler->display->display_options['fields']['field_uswds_status']['field'] = 'field_uswds_status';
  /* Field: Content: USWDS Tables */
  $handler->display->display_options['fields']['field_uswds_tables']['id'] = 'field_uswds_tables';
  $handler->display->display_options['fields']['field_uswds_tables']['table'] = 'field_data_field_uswds_tables';
  $handler->display->display_options['fields']['field_uswds_tables']['field'] = 'field_uswds_tables';
  /* Field: Content: USWDS Total Custom Score */
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['id'] = 'field_uswds_total_custom_score';
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['table'] = 'field_data_field_uswds_total_custom_score';
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['field'] = 'field_uswds_total_custom_score';
  /* Field: Content: USWDS USA classes detected */
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['id'] = 'field_uswds_usa_classes_detected';
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['table'] = 'field_data_field_uswds_usa_classes_detected';
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['field'] = 'field_uswds_usa_classes_detected';
  /* Field: Content: USWDS USA detected */
  $handler->display->display_options['fields']['field_uswds_usa_detected']['id'] = 'field_uswds_usa_detected';
  $handler->display->display_options['fields']['field_uswds_usa_detected']['table'] = 'field_data_field_uswds_usa_detected';
  $handler->display->display_options['fields']['field_uswds_usa_detected']['field'] = 'field_uswds_usa_detected';
  /* Field: Content: USWDS Version */
  $handler->display->display_options['fields']['field_uswds_version']['id'] = 'field_uswds_version';
  $handler->display->display_options['fields']['field_uswds_version']['table'] = 'field_data_field_uswds_version';
  $handler->display->display_options['fields']['field_uswds_version']['field'] = 'field_uswds_version';
  $handler->display->display_options['path'] = 'uswds/download/xls';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: MyAgency USWDS Page */
  $handler = $view->new_display('page', 'MyAgency USWDS Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Agency USWDS Code Usage Report';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="white-back" align="middle">USWDS is toolkit of design principles, user experience guidance, and code. Agencies can—and should—adopt USWDS incrementally. <br>Use of USWDS is not binary so we can\'t definitively say whether a site does or does not use USWDS.<br>The USWDS scan checks each domain for the use of&nbsp;<a href="https://designsystem.digital.gov/" rel="nofollow">U.S. Web Design System (USWDS)</a>&nbsp;code and the code version. <br> To know more about USWDS, check this link&nbsp;<a href="https://designsystem.digital.gov/maturity-model/">https://designsystem.digital.gov/maturity-model/</a>&nbsp;.<br></div><br>
<div align="right"><p>Download USWDS Reports: <a href="/myagency/uswds/download/csv"> csv </a> | <a href="/myagency/uswds/download/xls">xls</a></p></div><br>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = 'Website';
  $handler->display->display_options['fields']['field_website_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['alter']['path'] = 'website/[field_website_id-nid]/information';
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Link to Scan';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Raw Scan Link';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = 'agency_home/[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: USWDS API Scan Time */
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['id'] = 'field_uswds_api_scan_time';
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['table'] = 'field_data_field_uswds_api_scan_time';
  $handler->display->display_options['fields']['field_uswds_api_scan_time']['field'] = 'field_uswds_api_scan_time';
  /* Field: Content: USWDS API Url */
  $handler->display->display_options['fields']['field_uswds_api_url']['id'] = 'field_uswds_api_url';
  $handler->display->display_options['fields']['field_uswds_api_url']['table'] = 'field_data_field_uswds_api_url';
  $handler->display->display_options['fields']['field_uswds_api_url']['field'] = 'field_uswds_api_url';
  /* Field: Content: USWDS detected */
  $handler->display->display_options['fields']['field_uswds_detected']['id'] = 'field_uswds_detected';
  $handler->display->display_options['fields']['field_uswds_detected']['table'] = 'field_data_field_uswds_detected';
  $handler->display->display_options['fields']['field_uswds_detected']['field'] = 'field_uswds_detected';
  /* Field: Content: USWDS Flag Detected */
  $handler->display->display_options['fields']['field_uswds_flag_detected']['id'] = 'field_uswds_flag_detected';
  $handler->display->display_options['fields']['field_uswds_flag_detected']['table'] = 'field_data_field_uswds_flag_detected';
  $handler->display->display_options['fields']['field_uswds_flag_detected']['field'] = 'field_uswds_flag_detected';
  /* Field: Content: USWDS Flagin CSS detected */
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['id'] = 'field_uswds_flagin_css_detected';
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['table'] = 'field_data_field_uswds_flagin_css_detected';
  $handler->display->display_options['fields']['field_uswds_flagin_css_detected']['field'] = 'field_uswds_flagin_css_detected';
  /* Field: Content: USWDS Incss detected */
  $handler->display->display_options['fields']['field_uswds_incss_detected']['id'] = 'field_uswds_incss_detected';
  $handler->display->display_options['fields']['field_uswds_incss_detected']['table'] = 'field_data_field_uswds_incss_detected';
  $handler->display->display_options['fields']['field_uswds_incss_detected']['field'] = 'field_uswds_incss_detected';
  /* Field: Content: USWDS Marriweather font detetcted */
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['id'] = 'field_uswds_marriweather_font_de';
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['table'] = 'field_data_field_uswds_marriweather_font_de';
  $handler->display->display_options['fields']['field_uswds_marriweather_font_de']['field'] = 'field_uswds_marriweather_font_de';
  /* Field: Content: USWDS Public Sans Font detected */
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['id'] = 'field_uswds_public_sans_font_det';
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['table'] = 'field_data_field_uswds_public_sans_font_det';
  $handler->display->display_options['fields']['field_uswds_public_sans_font_det']['field'] = 'field_uswds_public_sans_font_det';
  /* Field: Content: USWDS Scan Website Status Code */
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['id'] = 'field_uswds_scan_web_status_code';
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['table'] = 'field_data_field_uswds_scan_web_status_code';
  $handler->display->display_options['fields']['field_uswds_scan_web_status_code']['field'] = 'field_uswds_scan_web_status_code';
  /* Field: Content: USWDS Score */
  $handler->display->display_options['fields']['field_uswds_score']['id'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['table'] = 'field_data_field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['field'] = 'field_uswds_score';
  $handler->display->display_options['fields']['field_uswds_score']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uswds_score']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USWDS Source SAN Font_det */
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['id'] = 'field_uswds_source_san_font_det';
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['table'] = 'field_data_field_uswds_source_san_font_det';
  $handler->display->display_options['fields']['field_uswds_source_san_font_det']['field'] = 'field_uswds_source_san_font_det';
  /* Field: Content: USWDS status */
  $handler->display->display_options['fields']['field_uswds_status']['id'] = 'field_uswds_status';
  $handler->display->display_options['fields']['field_uswds_status']['table'] = 'field_data_field_uswds_status';
  $handler->display->display_options['fields']['field_uswds_status']['field'] = 'field_uswds_status';
  /* Field: Content: USWDS Tables */
  $handler->display->display_options['fields']['field_uswds_tables']['id'] = 'field_uswds_tables';
  $handler->display->display_options['fields']['field_uswds_tables']['table'] = 'field_data_field_uswds_tables';
  $handler->display->display_options['fields']['field_uswds_tables']['field'] = 'field_uswds_tables';
  /* Field: Content: USWDS Total Custom Score */
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['id'] = 'field_uswds_total_custom_score';
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['table'] = 'field_data_field_uswds_total_custom_score';
  $handler->display->display_options['fields']['field_uswds_total_custom_score']['field'] = 'field_uswds_total_custom_score';
  /* Field: Content: USWDS USA classes detected */
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['id'] = 'field_uswds_usa_classes_detected';
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['table'] = 'field_data_field_uswds_usa_classes_detected';
  $handler->display->display_options['fields']['field_uswds_usa_classes_detected']['field'] = 'field_uswds_usa_classes_detected';
  /* Field: Content: USWDS USA detected */
  $handler->display->display_options['fields']['field_uswds_usa_detected']['id'] = 'field_uswds_usa_detected';
  $handler->display->display_options['fields']['field_uswds_usa_detected']['table'] = 'field_data_field_uswds_usa_detected';
  $handler->display->display_options['fields']['field_uswds_usa_detected']['field'] = 'field_uswds_usa_detected';
  /* Field: Content: USWDS Version */
  $handler->display->display_options['fields']['field_uswds_version']['id'] = 'field_uswds_version';
  $handler->display->display_options['fields']['field_uswds_version']['table'] = 'field_data_field_uswds_version';
  $handler->display->display_options['fields']['field_uswds_version']['field'] = 'field_uswds_version';
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uswds_scan' => 'uswds_scan',
  );
  /* Filter criterion: Content: Website ID (field_website_id) */
  $handler->display->display_options['filters']['field_website_id_nid']['id'] = 'field_website_id_nid';
  $handler->display->display_options['filters']['field_website_id_nid']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['filters']['field_website_id_nid']['field'] = 'field_website_id_nid';
  $handler->display->display_options['filters']['field_website_id_nid']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'myagency/uswds/reports';

  /* Display: MyAgency USWDS CSV */
  $handler = $view->new_display('views_data_export', 'MyAgency USWDS CSV', 'views_data_export_3');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'myagency_uswds.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
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
    'uswds_scan' => 'uswds_scan',
  );
  /* Filter criterion: Content: Website ID (field_website_id) */
  $handler->display->display_options['filters']['field_website_id_nid']['id'] = 'field_website_id_nid';
  $handler->display->display_options['filters']['field_website_id_nid']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['filters']['field_website_id_nid']['field'] = 'field_website_id_nid';
  $handler->display->display_options['filters']['field_website_id_nid']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'myagency/uswds/download/csv';

  /* Display: MyAgency USWDS XLS */
  $handler = $view->new_display('views_data_export', 'MyAgency USWDS XLS', 'views_data_export_4');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'myagency_uswds.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
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
    'uswds_scan' => 'uswds_scan',
  );
  /* Filter criterion: Content: Website ID (field_website_id) */
  $handler->display->display_options['filters']['field_website_id_nid']['id'] = 'field_website_id_nid';
  $handler->display->display_options['filters']['field_website_id_nid']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['filters']['field_website_id_nid']['field'] = 'field_website_id_nid';
  $handler->display->display_options['filters']['field_website_id_nid']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'myagency/uswds/download/xls';
  $export['uswds_data'] = $view;

  return $export;
}
