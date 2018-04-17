<?php
/**
 * @file
 * accessibility_new.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function accessibility_new_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'accessibility_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Accessibility Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Accessibility Report';
  $handler->display->display_options['css_class'] = 'white-back';
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
    'nid' => 'nid',
    'title' => 'title',
    'field_accessible_group_colorcont' => 'field_accessible_group_colorcont',
    'field_accessible_group_htmlattri' => 'field_accessible_group_htmlattri',
    'field_accessible_group_missingim' => 'field_accessible_group_missingim',
    'php' => 'php',
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
    'field_accessible_group_colorcont' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_accessible_group_htmlattri' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_accessible_group_missingim' => array(
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
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Accessibility Group Color Contrast */
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['id'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['table'] = 'field_data_field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['field'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute */
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['id'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['field'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group Missing Image */
  $handler->display->display_options['fields']['field_accessible_group_missingim']['id'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['table'] = 'field_data_field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['field'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Total Findings';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$toterror = $data->field_field_accessible_group_colorcont[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_htmlattri[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_missingim[\'0\'][\'raw\'][\'value\'];
print $toterror;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
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
    '508_scan_information' => '508_scan_information',
  );

  /* Display: All Domains Accessibility Report */
  $handler = $view->new_display('page', 'All Domains Accessibility Report', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Domain Level Accessibility Report';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = 'Domain';
  $handler->display->display_options['fields']['field_website_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Domain';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_website_id]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Accessibility Group Color Contrast */
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['id'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['table'] = 'field_data_field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['field'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['label'] = 'Color Contrast Findings';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute */
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['id'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['field'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['label'] = 'HTML Attribute Findings';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group Missing Image */
  $handler->display->display_options['fields']['field_accessible_group_missingim']['id'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['table'] = 'field_data_field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['field'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['label'] = 'Missing Image Description Findings';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Total Findings';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$toterror = $data->field_field_accessible_group_colorcont[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_htmlattri[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_missingim[\'0\'][\'raw\'][\'value\'];
print $toterror;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Accessibility Group HTML Attribute (field_accessible_group_htmlattri) */
  $handler->display->display_options['sorts']['field_accessible_group_htmlattri_value']['id'] = 'field_accessible_group_htmlattri_value';
  $handler->display->display_options['sorts']['field_accessible_group_htmlattri_value']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['sorts']['field_accessible_group_htmlattri_value']['field'] = 'field_accessible_group_htmlattri_value';
  $handler->display->display_options['sorts']['field_accessible_group_htmlattri_value']['order'] = 'DESC';
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
    '508_scan_information' => '508_scan_information',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Domain';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['path'] = 'accessibilityreportalldomains';

  /* Display: My Agency Accessibility */
  $handler = $view->new_display('block', 'My Agency Accessibility', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Agency Accessibility Report';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Accessibility Group Color Contrast */
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['id'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['table'] = 'field_data_field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['field'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute */
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['id'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['field'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group Missing Image */
  $handler->display->display_options['fields']['field_accessible_group_missingim']['id'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['table'] = 'field_data_field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['field'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['label'] = 'Missing Image Description';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Total Errors';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$toterror = $data->field_field_accessible_group_colorcont[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_htmlattri[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_missingim[\'0\'][\'raw\'][\'value\'];
print $toterror;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
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

  /* Display: Gov-wide Accessibility Chart */
  $handler = $view->new_display('block', 'Gov-wide Accessibility Chart', 'block_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['title'] = 'Government Wide Accessibility Chart';
  $handler->display->display_options['style_options']['label_field'] = 'title';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_accessible_group_colorcont' => 'field_accessible_group_colorcont',
    'field_accessible_group_htmlattri' => 'field_accessible_group_htmlattri',
    'field_accessible_group_missingim' => 'field_accessible_group_missingim',
    'title' => 0,
    'php' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'title' => '#2f7ed8',
    'field_accessible_group_colorcont' => '#0d233a',
    'field_accessible_group_htmlattri' => '#8bbc21',
    'field_accessible_group_missingim' => '#910000',
    'php' => '#1aadce',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Accessibility Group Color Contrast */
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['id'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['table'] = 'field_data_field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['field'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute */
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['id'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['field'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group Missing Image */
  $handler->display->display_options['fields']['field_accessible_group_missingim']['id'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['table'] = 'field_data_field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['field'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['label'] = 'Missing Image Description';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Total Findings';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$toterror = $data->field_field_accessible_group_colorcont[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_htmlattri[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_missingim[\'0\'][\'raw\'][\'value\'];
print $toterror;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'column';
  $handler->display->display_options['style_options']['title'] = 'Government Wide Accessibility Chart with Most Errors';
  $handler->display->display_options['style_options']['label_field'] = 'title';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_accessible_group_colorcont' => 'field_accessible_group_colorcont',
    'field_accessible_group_htmlattri' => 'field_accessible_group_htmlattri',
    'field_accessible_group_missingim' => 'field_accessible_group_missingim',
    'php' => 'php',
    'nid' => 0,
    'title' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'nid' => '#2f7ed8',
    'title' => '#2f7ed8',
    'field_accessible_group_colorcont' => '#0d233a',
    'field_accessible_group_htmlattri' => '#8bbc21',
    'field_accessible_group_missingim' => '#910000',
    'php' => '#1aadce',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Accessibility Group Color Contrast */
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['id'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['table'] = 'field_data_field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['field'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute */
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['id'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['field'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group Missing Image */
  $handler->display->display_options['fields']['field_accessible_group_missingim']['id'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['table'] = 'field_data_field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['field'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['label'] = 'Missing Image Description';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Total Findings';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$toterror = $data->field_field_accessible_group_colorcont[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_htmlattri[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_missingim[\'0\'][\'raw\'][\'value\'];
print $toterror;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: PHP */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
  );

  /* Display: Sites with most Accessibility Findings */
  $handler = $view->new_display('attachment', 'Sites with most Accessibility Findings', 'attachment_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Domains with most Accessibility Findings';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['label_field'] = 'title';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_accessibility_total_errors' => 'field_accessibility_total_errors',
    'title' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'title' => '#2f7ed8',
    'field_accessibility_total_errors' => '#ffa8a8',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Accessibility Total Errors */
  $handler->display->display_options['fields']['field_accessibility_total_errors']['id'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['field'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['label'] = 'Accessibility Total Findings';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Accessibility Total Errors (field_accessibility_total_errors) */
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['id'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['field'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['order'] = 'DESC';
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
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
  );

  /* Display: Attachment 3 */
  $handler = $view->new_display('attachment', 'Attachment 3', 'attachment_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['label_field'] = 'title';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'title' => 'title',
    'field_accessible_group_colorcont' => 'field_accessible_group_colorcont',
    'field_accessible_group_htmlattri' => 'field_accessible_group_htmlattri',
    'field_accessible_group_missingim' => 'field_accessible_group_missingim',
    'php' => 'php',
    'nid' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'nid' => '#2f7ed8',
    'title' => '#0d233a',
    'field_accessible_group_colorcont' => '#8bbc21',
    'field_accessible_group_htmlattri' => '#910000',
    'field_accessible_group_missingim' => '#1aadce',
    'php' => '#492970',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Accessibility Group Color Contrast */
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['id'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['table'] = 'field_data_field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['field'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute */
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['id'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['field'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group Missing Image */
  $handler->display->display_options['fields']['field_accessible_group_missingim']['id'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['table'] = 'field_data_field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['field'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['label'] = 'Missing Image Description';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Total Errors';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$toterror = $data->field_field_accessible_group_colorcont[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_htmlattri[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_missingim[\'0\'][\'raw\'][\'value\'];
print $toterror;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = '';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['element_label_colon'] = FALSE;
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

  /* Display: Attachment 2 */
  $handler = $view->new_display('attachment', 'Attachment 2', 'attachment_4');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['label_field'] = 'title';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_accessibility_total_errors' => 'field_accessibility_total_errors',
    'title' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'title' => '#2f7ed8',
    'field_accessibility_total_errors' => '#0d233a',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Accessibility Total Errors */
  $handler->display->display_options['fields']['field_accessibility_total_errors']['id'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['field'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Accessibility Total Errors (field_accessibility_total_errors) */
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['id'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['field'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['order'] = 'DESC';
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
  $handler->display->display_options['displays'] = array(
    'block_1' => 'block_1',
    'default' => 0,
    'page' => 0,
    'block_2' => 0,
  );

  /* Display: Gov-Wide Accessibility Findings Bar Chart */
  $handler = $view->new_display('attachment', 'Gov-Wide Accessibility Findings Bar Chart', 'attachment_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gov-Wide Accessibility Findings Bar Chart';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['xaxis_title'] = 'Accessibility Finding Type';
  $handler->display->display_options['style_options']['yaxis_title'] = 'Accessibility Finding  Count';
  $handler->display->display_options['style_options']['label_field'] = '';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_accessible_group_colorcont' => 'field_accessible_group_colorcont',
    'field_accessible_group_htmlattri' => 'field_accessible_group_htmlattri',
    'field_accessible_group_missingim' => 'field_accessible_group_missingim',
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_accessible_group_colorcont' => '#2f7ed8',
    'field_accessible_group_htmlattri' => '#0d233a',
    'field_accessible_group_missingim' => '#8bbc21',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<br><br>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Accessibility Group Color Contrast */
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['id'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['table'] = 'field_data_field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['field'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['label'] = 'Total Color Contrast Findings';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute */
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['id'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['field'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['label'] = 'Total HTML Attribute Findings';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group Missing Image */
  $handler->display->display_options['fields']['field_accessible_group_missingim']['id'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['table'] = 'field_data_field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['field'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['label'] = 'Total Missing Image Description Findings';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'block_5' => 'block_5',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'page_1' => 0,
    'block_3' => 0,
    'block_4' => 0,
  );

  /* Display: Agencies with most Findings */
  $handler = $view->new_display('attachment', 'Agencies with most Findings', 'attachment_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Agencies with most Accessibility Findings';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['label_field'] = 'field_web_agency_id';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_web_agency_id' => 'field_web_agency_id',
    'field_accessibility_total_errors' => 'field_accessibility_total_errors',
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_web_agency_id' => '#2f7ed8',
    'field_accessibility_total_errors' => '#ff8040',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency Name';
  /* Field: Content: Accessibility Total Errors */
  $handler->display->display_options['fields']['field_accessibility_total_errors']['id'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['field'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['label'] = 'Accessibility Total Findings';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Accessibility Total Errors (field_accessibility_total_errors) */
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['id'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['field'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['group_type'] = 'sum';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['order'] = 'DESC';
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
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
  );

  /* Display: Good Agency Breakdown */
  $handler = $view->new_display('attachment', 'Good Agency Breakdown', 'attachment_7');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['label_field'] = 'field_web_agency_id';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_web_agency_id' => 'field_web_agency_id',
    'field_accessibility_total_errors' => 'field_accessibility_total_errors',
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_web_agency_id' => '#2f7ed8',
    'field_accessibility_total_errors' => '#0080c0',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency Name';
  /* Field: Content: Accessibility Total Errors */
  $handler->display->display_options['fields']['field_accessibility_total_errors']['id'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['field'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['label'] = 'Accessibility Total Findings';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Accessibility Total Errors (field_accessibility_total_errors) */
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['id'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['field'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['group_type'] = 'sum';
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
  /* Filter criterion: Content: Accessibility Total Errors (field_accessibility_total_errors) */
  $handler->display->display_options['filters']['field_accessibility_total_errors_value']['id'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['filters']['field_accessibility_total_errors_value']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['filters']['field_accessibility_total_errors_value']['field'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['filters']['field_accessibility_total_errors_value']['group_type'] = 'sum';
  $handler->display->display_options['filters']['field_accessibility_total_errors_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_accessibility_total_errors_value']['value']['value'] = '0';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
  );

  /* Display: Agency Accessibility */
  $handler = $view->new_display('attachment', 'Agency Accessibility', 'attachment_8');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_web_agency_id' => 'field_web_agency_id',
    'field_accessibility_total_errors' => 'field_accessibility_total_errors',
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
    'field_accessibility_total_errors' => array(
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency Name';
  /* Field: Content: Accessibility Total Errors */
  $handler->display->display_options['fields']['field_accessibility_total_errors']['id'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['field'] = 'field_accessibility_total_errors';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessibility_total_errors']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Accessibility Total Errors (field_accessibility_total_errors) */
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['id'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['table'] = 'field_data_field_accessibility_total_errors';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['field'] = 'field_accessibility_total_errors_value';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['group_type'] = 'sum';
  $handler->display->display_options['sorts']['field_accessibility_total_errors_value']['order'] = 'DESC';
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
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
    'page_1' => 0,
    'block_3' => 0,
    'block_4' => 0,
    'block_5' => 0,
  );
  $handler->display->display_options['inherit_pager'] = TRUE;
  $handler->display->display_options['render_pager'] = TRUE;

  /* Display: Gov-wide Accessibility Report */
  $handler = $view->new_display('page', 'Gov-wide Accessibility Report', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gov-wide Accessibility Report';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_web_agency_id' => 'field_web_agency_id',
    'field_accessible_group_colorcont' => 'field_accessible_group_colorcont',
    'field_accessible_group_htmlattri' => 'field_accessible_group_htmlattri',
    'field_accessible_group_missingim' => 'field_accessible_group_missingim',
    'php' => 'php',
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
    'field_accessible_group_colorcont' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_accessible_group_htmlattri' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_accessible_group_missingim' => array(
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  /* Field: Content: Accessibility Group Color Contrast */
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['id'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['table'] = 'field_data_field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['field'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute */
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['id'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['field'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group Missing Image */
  $handler->display->display_options['fields']['field_accessible_group_missingim']['id'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['table'] = 'field_data_field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['field'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['label'] = 'Missing Image Description';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['group_type'] = 'sum';
  $handler->display->display_options['fields']['php']['label'] = 'Total Findings';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$toterror = $data->field_field_accessible_group_colorcont[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_htmlattri[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_missingim[\'0\'][\'raw\'][\'value\'];
print $toterror;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
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
    '508_scan_information' => '508_scan_information',
  );
  /* Filter criterion: Agency ID (field_web_agency_id) (selective) */
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['id'] = 'field_web_agency_id_nid_selective';
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['field'] = 'field_web_agency_id_nid_selective';
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['ui_name'] = 'Agency ID (field_web_agency_id) (selective)';
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['expose']['label'] = 'Agency ID (field_web_agency_id) (selective)';
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['expose']['identifier'] = 'field_web_agency_id_nid_selective';
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['selective_display_field'] = 'field_web_agency_id';
  $handler->display->display_options['filters']['field_web_agency_id_nid_selective']['selective_items_limit'] = '100';
  $handler->display->display_options['path'] = 'accessibility-report-all-domains1';

  /* Display: Agency wide Accessibility Findings */
  $handler = $view->new_display('block', 'Agency wide Accessibility Findings', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Agency-wide Accessibility Findings';
  $handler->display->display_options['display_description'] = 'Agency wide Accessibility Findings';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_web_agency_id' => 'field_web_agency_id',
    'field_agac_color_contrast_aver' => 'field_agac_color_contrast_aver',
    'field_agac_html_attribute_avrg' => 'field_agac_html_attribute_avrg',
    'field_agac_missing_image_avrg' => 'field_agac_missing_image_avrg',
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
    'field_web_agency_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agac_color_contrast_aver' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agac_html_attribute_avrg' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agac_missing_image_avrg' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  /* Field: Content: Agency Color Contrast Average */
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['id'] = 'field_agac_color_contrast_aver';
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['table'] = 'field_data_field_agac_color_contrast_aver';
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['field'] = 'field_agac_color_contrast_aver';
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['label'] = 'Average Color Contrast Findings';
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Agency HTML Attribute - Initial Findings Average */
  $handler->display->display_options['fields']['field_agac_html_attribute_avrg']['id'] = 'field_agac_html_attribute_avrg';
  $handler->display->display_options['fields']['field_agac_html_attribute_avrg']['table'] = 'field_data_field_agac_html_attribute_avrg';
  $handler->display->display_options['fields']['field_agac_html_attribute_avrg']['field'] = 'field_agac_html_attribute_avrg';
  $handler->display->display_options['fields']['field_agac_html_attribute_avrg']['label'] = 'Average HTML Attribute Findings';
  $handler->display->display_options['fields']['field_agac_html_attribute_avrg']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Agency Missing Image Descriptions Average */
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['id'] = 'field_agac_missing_image_avrg';
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['table'] = 'field_data_field_agac_missing_image_avrg';
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['field'] = 'field_agac_missing_image_avrg';
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['label'] = 'Average Missing Image Descriptions';
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
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
    'accessibility_agency_scan_inform' => 'accessibility_agency_scan_inform',
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
    4 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
  );

  /* Display: Accessibility Agency Chart */
  $handler = $view->new_display('block', 'Accessibility Agency Chart', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Agency-wide Accessibility Issue Findings Chart';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'google_chart_tools_views';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['haxis_title'] = 'Number of Findings';
  $handler->display->display_options['style_options']['vaxis_title'] = 'Agency Name';
  $handler->display->display_options['style_options']['type'] = 'BarChart';
  $handler->display->display_options['style_options']['width'] = '100%';
  $handler->display->display_options['style_options']['height'] = '1600';
  $handler->display->display_options['style_options']['curve'] = 1;
  $handler->display->display_options['style_options']['3d'] = 1;
  $handler->display->display_options['style_options']['isstacked'] = 1;
  $handler->display->display_options['style_options']['pointsize'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: Agency Color Contrast Average */
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['id'] = 'field_agac_color_contrast_aver';
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['table'] = 'field_data_field_agac_color_contrast_aver';
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['field'] = 'field_agac_color_contrast_aver';
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['label'] = 'Color Contrast Findings';
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Agency HTML Attribute - Initial Findings Average */
  $handler->display->display_options['fields']['field_agac_html_attribute_avrg']['id'] = 'field_agac_html_attribute_avrg';
  $handler->display->display_options['fields']['field_agac_html_attribute_avrg']['table'] = 'field_data_field_agac_html_attribute_avrg';
  $handler->display->display_options['fields']['field_agac_html_attribute_avrg']['field'] = 'field_agac_html_attribute_avrg';
  $handler->display->display_options['fields']['field_agac_html_attribute_avrg']['label'] = 'HTML Attribute Findings';
  $handler->display->display_options['fields']['field_agac_html_attribute_avrg']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Agency Missing Image Descriptions Average */
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['id'] = 'field_agac_missing_image_avrg';
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['table'] = 'field_data_field_agac_missing_image_avrg';
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['field'] = 'field_agac_missing_image_avrg';
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['label'] = 'Missing Image Findings';
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Average Errors per Page (field_agac_average_errors_page) */
  $handler->display->display_options['sorts']['field_agac_average_errors_page_value']['id'] = 'field_agac_average_errors_page_value';
  $handler->display->display_options['sorts']['field_agac_average_errors_page_value']['table'] = 'field_data_field_agac_average_errors_page';
  $handler->display->display_options['sorts']['field_agac_average_errors_page_value']['field'] = 'field_agac_average_errors_page_value';
  $handler->display->display_options['sorts']['field_agac_average_errors_page_value']['order'] = 'DESC';
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
    'accessibility_agency_scan_inform' => 'accessibility_agency_scan_inform',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Government-Wide Accessibility Findings Summary Table */
  $handler = $view->new_display('block', 'Government-Wide Accessibility Findings Summary Table', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Government-Wide Accessibility Findings Summary';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/website/all/reports" id="link-all-reports">View Full Report</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Accessibility Group Color Contrast */
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['id'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['table'] = 'field_data_field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['field'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['label'] = 'Total Color Contrast Findings';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute */
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['id'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['field'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['label'] = 'Total HTML Attribute Findings';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group Missing Image */
  $handler->display->display_options['fields']['field_accessible_group_missingim']['id'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['table'] = 'field_data_field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['field'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['label'] = 'Total Missing Image Description Findings';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;

  /* Display: All Domains Accessibility Report */
  $handler = $view->new_display('block', 'All Domains Accessibility Report', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Domains Accessibility Report';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_website_id' => 'field_website_id',
    'field_accessible_group_colorcont' => 'field_accessible_group_colorcont',
    'field_accessible_group_htmlattri' => 'field_accessible_group_htmlattri',
    'field_accessible_group_missingim' => 'field_accessible_group_missingim',
    'php' => 'php',
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
    'field_website_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_accessible_group_colorcont' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_accessible_group_htmlattri' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_accessible_group_missingim' => array(
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
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Website ID */
  $handler->display->display_options['fields']['field_website_id']['id'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['table'] = 'field_data_field_website_id';
  $handler->display->display_options['fields']['field_website_id']['field'] = 'field_website_id';
  $handler->display->display_options['fields']['field_website_id']['label'] = 'Domain';
  $handler->display->display_options['fields']['field_website_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_website_id']['alter']['text'] = '<a href=\'/node/[nid]\'>[field_website_id]</a>';
  $handler->display->display_options['fields']['field_website_id']['type'] = 'node_reference_plain';
  /* Field: Content: Accessibility Group Color Contrast */
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['id'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['table'] = 'field_data_field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['field'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['label'] = 'Color Contrast Findings';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute */
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['id'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['field'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['label'] = 'HTML Attribute Findings';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group Missing Image */
  $handler->display->display_options['fields']['field_accessible_group_missingim']['id'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['table'] = 'field_data_field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['field'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['label'] = 'Missing Image Description Findings';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Total Findings';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$toterror = $data->field_field_accessible_group_colorcont[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_htmlattri[\'0\'][\'raw\'][\'value\']+$data->field_field_accessible_group_missingim[\'0\'][\'raw\'][\'value\'];
print $toterror;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Accessibility Group HTML Attribute (field_accessible_group_htmlattri) */
  $handler->display->display_options['sorts']['field_accessible_group_htmlattri_value']['id'] = 'field_accessible_group_htmlattri_value';
  $handler->display->display_options['sorts']['field_accessible_group_htmlattri_value']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['sorts']['field_accessible_group_htmlattri_value']['field'] = 'field_accessible_group_htmlattri_value';
  $handler->display->display_options['sorts']['field_accessible_group_htmlattri_value']['order'] = 'DESC';
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
    '508_scan_information' => '508_scan_information',
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
    4 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    7 => 0,
    8 => 0,
    10 => 0,
    11 => 0,
  );

  /* Display: Gov wide error Pie chart */
  $handler = $view->new_display('block', 'Gov wide error Pie chart', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gov wide error Pie chart';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'bar';
  $handler->display->display_options['style_options']['label_field'] = '';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_accessible_group_colorcont' => 'field_accessible_group_colorcont',
    'field_accessible_group_htmlattri' => 'field_accessible_group_htmlattri',
    'field_accessible_group_missingim' => 'field_accessible_group_missingim',
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_accessible_group_colorcont' => '#2f7ed8',
    'field_accessible_group_htmlattri' => '#0d233a',
    'field_accessible_group_missingim' => '#8bbc21',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Accessibility Group Color Contrast */
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['id'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['table'] = 'field_data_field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['field'] = 'field_accessible_group_colorcont';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['label'] = 'Color Contrast Findings';
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute */
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['id'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['table'] = 'field_data_field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['field'] = 'field_accessible_group_htmlattri';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['label'] = 'HTML Attribute Findings';
  $handler->display->display_options['fields']['field_accessible_group_htmlattri']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group Missing Image */
  $handler->display->display_options['fields']['field_accessible_group_missingim']['id'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['table'] = 'field_data_field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['field'] = 'field_accessible_group_missingim';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['label'] = 'Missing Image Description Findings';
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $export['accessibility_report'] = $view;

  return $export;
}
