<?php
/**
 * @file
 * accessibility.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function accessibility_views_default_views() {
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
    'title' => 'title',
    'field_accessibility_total_errors' => 'field_accessibility_total_errors',
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
    'field_accessibility_total_errors' => array(
      'sortable' => 0,
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
  /* Field: Content: Accessibility Group HTML Attribute  */
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
  $handler->display->display_options['fields']['php']['label'] = 'Total Errors';
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

  /* Display: Gov-wide Accessibility Report */
  $handler = $view->new_display('page', 'Gov-wide Accessibility Report', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gov-wide Accessibility Report';
  $handler->display->display_options['path'] = 'accessibility-report-all-domains';

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
  /* Field: Content: Accessibility Group HTML Attribute  */
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

  /* Display: Attachment 2 */
  $handler = $view->new_display('attachment', 'Attachment 2', 'attachment_2');
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
  /* Field: Content: Accessibility Group HTML Attribute  */
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

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_5');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
  $handler->display->display_options['fields']['field_accessible_group_colorcont']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Accessibility Group HTML Attribute  */
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
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
  );

  /* Display: Agency Breakdown */
  $handler = $view->new_display('attachment', 'Agency Breakdown', 'attachment_6');
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
    'field_accessibility_total_errors' => '#0d233a',
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
  );

  /* Display: Good Agency Breakdown */
  $handler = $view->new_display('attachment', 'Good Agency Breakdown', 'attachment_7');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'column';
  $handler->display->display_options['style_options']['label_field'] = 'field_web_agency_id';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_web_agency_id' => 'field_web_agency_id',
    'field_accessibility_total_errors' => 'field_accessibility_total_errors',
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_web_agency_id' => '#2f7ed8',
    'field_accessibility_total_errors' => '#0d233a',
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
    'page' => 'page',
    'default' => 0,
    'block_1' => 0,
    'block_2' => 0,
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
  /* Field: Content: Accessibility Group HTML Attribute  */
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
  $handler->display->display_options['fields']['field_accessible_group_missingim']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['group_type'] = 'sum';
  $handler->display->display_options['fields']['php']['label'] = 'Total Errors';
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

  /* Display: Block 3 */
  $handler = $view->new_display('block', 'Block 3', 'block_3');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_agac_color_contrast_aver' => 'field_agac_color_contrast_aver',
    'field_agac_html_attribute_avrg' => 'field_agac_html_attribute_avrg',
    'field_agac_missing_image_avrg' => 'field_agac_missing_image_avrg',
    'field_agac_agency_pages_cnt' => 'field_agac_agency_pages_cnt',
    'field_agac_average_errors_page' => 'field_agac_average_errors_page',
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
    'field_agac_agency_pages_cnt' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agac_average_errors_page' => array(
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
  /* Field: Content: Agency Color Contrast Average */
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['id'] = 'field_agac_color_contrast_aver';
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['table'] = 'field_data_field_agac_color_contrast_aver';
  $handler->display->display_options['fields']['field_agac_color_contrast_aver']['field'] = 'field_agac_color_contrast_aver';
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
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Agency Pages Count */
  $handler->display->display_options['fields']['field_agac_agency_pages_cnt']['id'] = 'field_agac_agency_pages_cnt';
  $handler->display->display_options['fields']['field_agac_agency_pages_cnt']['table'] = 'field_data_field_agac_agency_pages_cnt';
  $handler->display->display_options['fields']['field_agac_agency_pages_cnt']['field'] = 'field_agac_agency_pages_cnt';
  $handler->display->display_options['fields']['field_agac_agency_pages_cnt']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Average Errors per Page */
  $handler->display->display_options['fields']['field_agac_average_errors_page']['id'] = 'field_agac_average_errors_page';
  $handler->display->display_options['fields']['field_agac_average_errors_page']['table'] = 'field_data_field_agac_average_errors_page';
  $handler->display->display_options['fields']['field_agac_average_errors_page']['field'] = 'field_agac_average_errors_page';
  $handler->display->display_options['fields']['field_agac_average_errors_page']['settings'] = array(
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

  /* Display: Accessibility Agency Chart */
  $handler = $view->new_display('block', 'Accessibility Agency Chart', 'block_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'google_chart_tools_views';
  $handler->display->display_options['style_options']['haxis_title'] = 'Number of Errors';
  $handler->display->display_options['style_options']['vaxis_title'] = 'Agency Name';
  $handler->display->display_options['style_options']['type'] = 'BarChart';
  $handler->display->display_options['style_options']['width'] = '1500';
  $handler->display->display_options['style_options']['height'] = '2000';
  $handler->display->display_options['style_options']['curve'] = 1;
  $handler->display->display_options['style_options']['3d'] = 1;
  $handler->display->display_options['style_options']['isstacked'] = 1;
  $handler->display->display_options['style_options']['pointsize'] = '0';
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
  $handler->display->display_options['fields']['field_agac_missing_image_avrg']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
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
  $export['accessibility_report'] = $view;

  $view = new view();
  $view->name = 'agency_logo';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'agency-logo';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'white-back col-xs-2 col-xs-offset-5 clearfix';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Agency Logo */
  $handler->display->display_options['fields']['field_agency_logo']['id'] = 'field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['table'] = 'field_data_field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['field'] = 'field_agency_logo';
  $handler->display->display_options['fields']['field_agency_logo']['label'] = '';
  $handler->display->display_options['fields']['field_agency_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_logo']['empty'] = '<img src="/sites/all/themes/dotgov/images/placeholder.png" width=200 class="center-block" />';
  $handler->display->display_options['fields']['field_agency_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_agency_logo']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_agency_logo']['settings'] = array(
    'colorbox_node_style' => 'thumbnail',
    'colorbox_node_style_first' => 'large',
    'colorbox_image_style' => '',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return $_GET["field_web_agency_id_nid"];';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'agency-logo';
  $export['agency_logo'] = $view;

  $view = new view();
  $view->name = 'clone_of_website_information';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Clone of website information';
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
  $export['clone_of_website_information'] = $view;

  $view = new view();
  $view->name = 'homepage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'homepage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'col-lg-2';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'text-center col-lg-12 clearfix home-button';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: COUNT(Content: Type) */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['type_1']['label'] = '';
  $handler->display->display_options['fields']['type_1']['element_type'] = 'strong';
  $handler->display->display_options['fields']['type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type_1']['element_wrapper_class'] = 'lead';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_class'] = '[type]';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
    'website' => 'website',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['homepage'] = $view;

  $view = new view();
  $view->name = 'technology_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'technology overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Technology Stack Reports';
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_web_agency_id' => 'field_web_agency_id',
    'field_operating_systems' => 'field_operating_systems',
    'field_web_server' => 'field_web_server',
    'field_programming_languages' => 'field_programming_languages',
    'field_cms_applications' => 'field_cms_applications',
    'field_web_frameworks' => 'field_web_frameworks',
    'field_cdn_applications' => 'field_cdn_applications',
    'field_javascript_frameworks' => 'field_javascript_frameworks',
    'field_analytics_applications' => 'field_analytics_applications',
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
    'field_operating_systems' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_web_server' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programming_languages' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cms_applications' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_web_frameworks' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cdn_applications' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_javascript_frameworks' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_analytics_applications' => array(
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Website Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '/website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency Name';
  /* Field: Content: Operating Systems */
  $handler->display->display_options['fields']['field_operating_systems']['id'] = 'field_operating_systems';
  $handler->display->display_options['fields']['field_operating_systems']['table'] = 'field_data_field_operating_systems';
  $handler->display->display_options['fields']['field_operating_systems']['field'] = 'field_operating_systems';
  $handler->display->display_options['fields']['field_operating_systems']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_operating_systems']['delta_offset'] = '0';
  /* Field: Content: Web Server */
  $handler->display->display_options['fields']['field_web_server']['id'] = 'field_web_server';
  $handler->display->display_options['fields']['field_web_server']['table'] = 'field_data_field_web_server';
  $handler->display->display_options['fields']['field_web_server']['field'] = 'field_web_server';
  $handler->display->display_options['fields']['field_web_server']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_web_server']['delta_offset'] = '0';
  /* Field: Content: Programming Languages */
  $handler->display->display_options['fields']['field_programming_languages']['id'] = 'field_programming_languages';
  $handler->display->display_options['fields']['field_programming_languages']['table'] = 'field_data_field_programming_languages';
  $handler->display->display_options['fields']['field_programming_languages']['field'] = 'field_programming_languages';
  $handler->display->display_options['fields']['field_programming_languages']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_programming_languages']['delta_offset'] = '0';
  /* Field: Content: CMS Applications */
  $handler->display->display_options['fields']['field_cms_applications']['id'] = 'field_cms_applications';
  $handler->display->display_options['fields']['field_cms_applications']['table'] = 'field_data_field_cms_applications';
  $handler->display->display_options['fields']['field_cms_applications']['field'] = 'field_cms_applications';
  $handler->display->display_options['fields']['field_cms_applications']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_cms_applications']['delta_offset'] = '0';
  /* Field: Content: Web Frameworks */
  $handler->display->display_options['fields']['field_web_frameworks']['id'] = 'field_web_frameworks';
  $handler->display->display_options['fields']['field_web_frameworks']['table'] = 'field_data_field_web_frameworks';
  $handler->display->display_options['fields']['field_web_frameworks']['field'] = 'field_web_frameworks';
  $handler->display->display_options['fields']['field_web_frameworks']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_web_frameworks']['delta_offset'] = '0';
  /* Field: Content: CDN applications */
  $handler->display->display_options['fields']['field_cdn_applications']['id'] = 'field_cdn_applications';
  $handler->display->display_options['fields']['field_cdn_applications']['table'] = 'field_data_field_cdn_applications';
  $handler->display->display_options['fields']['field_cdn_applications']['field'] = 'field_cdn_applications';
  $handler->display->display_options['fields']['field_cdn_applications']['label'] = 'CDN';
  $handler->display->display_options['fields']['field_cdn_applications']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_cdn_applications']['delta_offset'] = '0';
  /* Field: Content: Javascript Frameworks */
  $handler->display->display_options['fields']['field_javascript_frameworks']['id'] = 'field_javascript_frameworks';
  $handler->display->display_options['fields']['field_javascript_frameworks']['table'] = 'field_data_field_javascript_frameworks';
  $handler->display->display_options['fields']['field_javascript_frameworks']['field'] = 'field_javascript_frameworks';
  $handler->display->display_options['fields']['field_javascript_frameworks']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_javascript_frameworks']['delta_offset'] = '0';
  /* Field: Content: Analytics Applications */
  $handler->display->display_options['fields']['field_analytics_applications']['id'] = 'field_analytics_applications';
  $handler->display->display_options['fields']['field_analytics_applications']['table'] = 'field_data_field_analytics_applications';
  $handler->display->display_options['fields']['field_analytics_applications']['field'] = 'field_analytics_applications';
  $handler->display->display_options['fields']['field_analytics_applications']['label'] = 'Analytics Apps';
  $handler->display->display_options['fields']['field_analytics_applications']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_analytics_applications']['delta_offset'] = '0';
  /* Field: Content: Widget Applications */
  $handler->display->display_options['fields']['field_widget_applications']['id'] = 'field_widget_applications';
  $handler->display->display_options['fields']['field_widget_applications']['table'] = 'field_data_field_widget_applications';
  $handler->display->display_options['fields']['field_widget_applications']['field'] = 'field_widget_applications';
  $handler->display->display_options['fields']['field_widget_applications']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Operating Systems (field_operating_systems) */
  $handler->display->display_options['sorts']['field_operating_systems_tid']['id'] = 'field_operating_systems_tid';
  $handler->display->display_options['sorts']['field_operating_systems_tid']['table'] = 'field_data_field_operating_systems';
  $handler->display->display_options['sorts']['field_operating_systems_tid']['field'] = 'field_operating_systems_tid';
  $handler->display->display_options['sorts']['field_operating_systems_tid']['order'] = 'DESC';
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
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Operating Systems (field_operating_systems) (selective) */
  $handler->display->display_options['filters']['field_operating_systems_tid_selective']['id'] = 'field_operating_systems_tid_selective';
  $handler->display->display_options['filters']['field_operating_systems_tid_selective']['table'] = 'field_data_field_operating_systems';
  $handler->display->display_options['filters']['field_operating_systems_tid_selective']['field'] = 'field_operating_systems_tid_selective';
  $handler->display->display_options['filters']['field_operating_systems_tid_selective']['ui_name'] = 'Operating Systems (field_operating_systems) (selective)';
  $handler->display->display_options['filters']['field_operating_systems_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_operating_systems_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_operating_systems_tid_selective']['expose']['label'] = 'Operating Systems ';
  $handler->display->display_options['filters']['field_operating_systems_tid_selective']['expose']['identifier'] = 'field_operating_systems_tid_selective';
  $handler->display->display_options['filters']['field_operating_systems_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_operating_systems_tid_selective']['selective_display_field'] = 'field_operating_systems';
  $handler->display->display_options['filters']['field_operating_systems_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Programming Languages (field_programming_languages) (selective) */
  $handler->display->display_options['filters']['field_programming_languages_tid_selective']['id'] = 'field_programming_languages_tid_selective';
  $handler->display->display_options['filters']['field_programming_languages_tid_selective']['table'] = 'field_data_field_programming_languages';
  $handler->display->display_options['filters']['field_programming_languages_tid_selective']['field'] = 'field_programming_languages_tid_selective';
  $handler->display->display_options['filters']['field_programming_languages_tid_selective']['ui_name'] = 'Programming Languages (field_programming_languages) (selective)';
  $handler->display->display_options['filters']['field_programming_languages_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programming_languages_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_programming_languages_tid_selective']['expose']['label'] = 'Programming Languages';
  $handler->display->display_options['filters']['field_programming_languages_tid_selective']['expose']['identifier'] = 'field_programming_languages_tid_selective';
  $handler->display->display_options['filters']['field_programming_languages_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_programming_languages_tid_selective']['selective_display_field'] = 'field_programming_languages';
  $handler->display->display_options['filters']['field_programming_languages_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Web Server (field_web_server) (selective) */
  $handler->display->display_options['filters']['field_web_server_tid_selective']['id'] = 'field_web_server_tid_selective';
  $handler->display->display_options['filters']['field_web_server_tid_selective']['table'] = 'field_data_field_web_server';
  $handler->display->display_options['filters']['field_web_server_tid_selective']['field'] = 'field_web_server_tid_selective';
  $handler->display->display_options['filters']['field_web_server_tid_selective']['ui_name'] = 'Web Server (field_web_server) (selective)';
  $handler->display->display_options['filters']['field_web_server_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_web_server_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_web_server_tid_selective']['expose']['label'] = 'Web Server';
  $handler->display->display_options['filters']['field_web_server_tid_selective']['expose']['identifier'] = 'field_web_server_tid_selective';
  $handler->display->display_options['filters']['field_web_server_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_web_server_tid_selective']['selective_display_field'] = 'field_web_server';
  $handler->display->display_options['filters']['field_web_server_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: CMS Applications (field_cms_applications) (selective) */
  $handler->display->display_options['filters']['field_cms_applications_tid_selective']['id'] = 'field_cms_applications_tid_selective';
  $handler->display->display_options['filters']['field_cms_applications_tid_selective']['table'] = 'field_data_field_cms_applications';
  $handler->display->display_options['filters']['field_cms_applications_tid_selective']['field'] = 'field_cms_applications_tid_selective';
  $handler->display->display_options['filters']['field_cms_applications_tid_selective']['ui_name'] = 'CMS Applications (field_cms_applications) (selective)';
  $handler->display->display_options['filters']['field_cms_applications_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cms_applications_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_cms_applications_tid_selective']['expose']['label'] = 'CMS';
  $handler->display->display_options['filters']['field_cms_applications_tid_selective']['expose']['identifier'] = 'field_cms_applications_tid_selective';
  $handler->display->display_options['filters']['field_cms_applications_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_cms_applications_tid_selective']['selective_display_field'] = 'field_cms_applications';
  $handler->display->display_options['filters']['field_cms_applications_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: CDN applications (field_cdn_applications) (selective) */
  $handler->display->display_options['filters']['field_cdn_applications_tid_selective']['id'] = 'field_cdn_applications_tid_selective';
  $handler->display->display_options['filters']['field_cdn_applications_tid_selective']['table'] = 'field_data_field_cdn_applications';
  $handler->display->display_options['filters']['field_cdn_applications_tid_selective']['field'] = 'field_cdn_applications_tid_selective';
  $handler->display->display_options['filters']['field_cdn_applications_tid_selective']['ui_name'] = 'CDN applications (field_cdn_applications) (selective)';
  $handler->display->display_options['filters']['field_cdn_applications_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cdn_applications_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_cdn_applications_tid_selective']['expose']['label'] = 'CDN';
  $handler->display->display_options['filters']['field_cdn_applications_tid_selective']['expose']['identifier'] = 'field_cdn_applications_tid_selective';
  $handler->display->display_options['filters']['field_cdn_applications_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_cdn_applications_tid_selective']['selective_display_field'] = 'field_cdn_applications';
  $handler->display->display_options['filters']['field_cdn_applications_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Javascript Frameworks (field_javascript_frameworks) (selective) */
  $handler->display->display_options['filters']['field_javascript_frameworks_tid_selective']['id'] = 'field_javascript_frameworks_tid_selective';
  $handler->display->display_options['filters']['field_javascript_frameworks_tid_selective']['table'] = 'field_data_field_javascript_frameworks';
  $handler->display->display_options['filters']['field_javascript_frameworks_tid_selective']['field'] = 'field_javascript_frameworks_tid_selective';
  $handler->display->display_options['filters']['field_javascript_frameworks_tid_selective']['ui_name'] = 'Javascript Frameworks (field_javascript_frameworks) (selective)';
  $handler->display->display_options['filters']['field_javascript_frameworks_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_javascript_frameworks_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_javascript_frameworks_tid_selective']['expose']['label'] = 'Javascript Frameworks';
  $handler->display->display_options['filters']['field_javascript_frameworks_tid_selective']['expose']['identifier'] = 'field_javascript_frameworks_tid_selective';
  $handler->display->display_options['filters']['field_javascript_frameworks_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_javascript_frameworks_tid_selective']['selective_display_field'] = 'field_javascript_frameworks';
  $handler->display->display_options['filters']['field_javascript_frameworks_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Analytics Applications (field_analytics_applications) (selective) */
  $handler->display->display_options['filters']['field_analytics_applications_tid_selective']['id'] = 'field_analytics_applications_tid_selective';
  $handler->display->display_options['filters']['field_analytics_applications_tid_selective']['table'] = 'field_data_field_analytics_applications';
  $handler->display->display_options['filters']['field_analytics_applications_tid_selective']['field'] = 'field_analytics_applications_tid_selective';
  $handler->display->display_options['filters']['field_analytics_applications_tid_selective']['ui_name'] = 'Analytics Applications (field_analytics_applications) (selective)';
  $handler->display->display_options['filters']['field_analytics_applications_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_analytics_applications_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_analytics_applications_tid_selective']['expose']['label'] = 'Analytics';
  $handler->display->display_options['filters']['field_analytics_applications_tid_selective']['expose']['identifier'] = 'field_analytics_applications_tid_selective';
  $handler->display->display_options['filters']['field_analytics_applications_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_analytics_applications_tid_selective']['selective_display_field'] = 'field_analytics_applications';
  $handler->display->display_options['filters']['field_analytics_applications_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Widget Applications (field_widget_applications) (selective) */
  $handler->display->display_options['filters']['field_widget_applications_tid_selective']['id'] = 'field_widget_applications_tid_selective';
  $handler->display->display_options['filters']['field_widget_applications_tid_selective']['table'] = 'field_data_field_widget_applications';
  $handler->display->display_options['filters']['field_widget_applications_tid_selective']['field'] = 'field_widget_applications_tid_selective';
  $handler->display->display_options['filters']['field_widget_applications_tid_selective']['ui_name'] = 'Widget Applications (field_widget_applications) (selective)';
  $handler->display->display_options['filters']['field_widget_applications_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_widget_applications_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_widget_applications_tid_selective']['expose']['label'] = 'Widgets';
  $handler->display->display_options['filters']['field_widget_applications_tid_selective']['expose']['identifier'] = 'field_widget_applications_tid_selective';
  $handler->display->display_options['filters']['field_widget_applications_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_widget_applications_tid_selective']['selective_display_field'] = 'field_widget_applications';
  $handler->display->display_options['filters']['field_widget_applications_tid_selective']['selective_items_limit'] = '100';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'white-back';
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
  $handler->display->display_options['fields']['title']['label'] = 'Website Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '/website/[nid]/information';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Agency ID */
  $handler->display->display_options['fields']['field_web_agency_id']['id'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['table'] = 'field_data_field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['field'] = 'field_web_agency_id';
  $handler->display->display_options['fields']['field_web_agency_id']['label'] = 'Agency Name';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['text'] = '[field_web_agency_id]';
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_web_agency_id']['alter']['path'] = '/overall/compliance?field_web_agency_id_nid=[field_web_agency_id-nid]';
  $handler->display->display_options['fields']['field_web_agency_id']['type'] = 'node_reference_plain';
  /* Field: Content: Operating Systems */
  $handler->display->display_options['fields']['field_operating_systems']['id'] = 'field_operating_systems';
  $handler->display->display_options['fields']['field_operating_systems']['table'] = 'field_data_field_operating_systems';
  $handler->display->display_options['fields']['field_operating_systems']['field'] = 'field_operating_systems';
  $handler->display->display_options['fields']['field_operating_systems']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_operating_systems']['delta_offset'] = '0';
  /* Field: Content: Web Server */
  $handler->display->display_options['fields']['field_web_server']['id'] = 'field_web_server';
  $handler->display->display_options['fields']['field_web_server']['table'] = 'field_data_field_web_server';
  $handler->display->display_options['fields']['field_web_server']['field'] = 'field_web_server';
  $handler->display->display_options['fields']['field_web_server']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_web_server']['delta_offset'] = '0';
  /* Field: Content: Programming Languages */
  $handler->display->display_options['fields']['field_programming_languages']['id'] = 'field_programming_languages';
  $handler->display->display_options['fields']['field_programming_languages']['table'] = 'field_data_field_programming_languages';
  $handler->display->display_options['fields']['field_programming_languages']['field'] = 'field_programming_languages';
  $handler->display->display_options['fields']['field_programming_languages']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_programming_languages']['delta_offset'] = '0';
  /* Field: Content: CMS Applications */
  $handler->display->display_options['fields']['field_cms_applications']['id'] = 'field_cms_applications';
  $handler->display->display_options['fields']['field_cms_applications']['table'] = 'field_data_field_cms_applications';
  $handler->display->display_options['fields']['field_cms_applications']['field'] = 'field_cms_applications';
  $handler->display->display_options['fields']['field_cms_applications']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_cms_applications']['delta_offset'] = '0';
  /* Field: Content: Web Frameworks */
  $handler->display->display_options['fields']['field_web_frameworks']['id'] = 'field_web_frameworks';
  $handler->display->display_options['fields']['field_web_frameworks']['table'] = 'field_data_field_web_frameworks';
  $handler->display->display_options['fields']['field_web_frameworks']['field'] = 'field_web_frameworks';
  $handler->display->display_options['fields']['field_web_frameworks']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_web_frameworks']['delta_offset'] = '0';
  /* Field: Content: CDN applications */
  $handler->display->display_options['fields']['field_cdn_applications']['id'] = 'field_cdn_applications';
  $handler->display->display_options['fields']['field_cdn_applications']['table'] = 'field_data_field_cdn_applications';
  $handler->display->display_options['fields']['field_cdn_applications']['field'] = 'field_cdn_applications';
  $handler->display->display_options['fields']['field_cdn_applications']['label'] = 'CDN';
  $handler->display->display_options['fields']['field_cdn_applications']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_cdn_applications']['delta_offset'] = '0';
  /* Field: Content: Javascript Frameworks */
  $handler->display->display_options['fields']['field_javascript_frameworks']['id'] = 'field_javascript_frameworks';
  $handler->display->display_options['fields']['field_javascript_frameworks']['table'] = 'field_data_field_javascript_frameworks';
  $handler->display->display_options['fields']['field_javascript_frameworks']['field'] = 'field_javascript_frameworks';
  $handler->display->display_options['fields']['field_javascript_frameworks']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_javascript_frameworks']['delta_offset'] = '0';
  /* Field: Content: Analytics Applications */
  $handler->display->display_options['fields']['field_analytics_applications']['id'] = 'field_analytics_applications';
  $handler->display->display_options['fields']['field_analytics_applications']['table'] = 'field_data_field_analytics_applications';
  $handler->display->display_options['fields']['field_analytics_applications']['field'] = 'field_analytics_applications';
  $handler->display->display_options['fields']['field_analytics_applications']['label'] = 'Analytics Apps';
  $handler->display->display_options['fields']['field_analytics_applications']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_analytics_applications']['delta_offset'] = '0';
  /* Field: Content: Widget Applications */
  $handler->display->display_options['fields']['field_widget_applications']['id'] = 'field_widget_applications';
  $handler->display->display_options['fields']['field_widget_applications']['table'] = 'field_data_field_widget_applications';
  $handler->display->display_options['fields']['field_widget_applications']['field'] = 'field_widget_applications';
  $handler->display->display_options['fields']['field_widget_applications']['delta_offset'] = '0';
  $handler->display->display_options['path'] = 'technology-overview';
  $export['technology_overview'] = $view;

  $view = new view();
  $view->name = 'web_servers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'web servers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'web servers';
  $handler->display->display_options['css_class'] = 'white-back';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['label_field'] = 'field_web_server';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_web_server_1' => 'field_web_server_1',
    'field_web_server' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_web_server' => '#2f7ed8',
    'field_web_server_1' => '#0d233a',
  );
  /* Field: Content: Web Server */
  $handler->display->display_options['fields']['field_web_server']['id'] = 'field_web_server';
  $handler->display->display_options['fields']['field_web_server']['table'] = 'field_data_field_web_server';
  $handler->display->display_options['fields']['field_web_server']['field'] = 'field_web_server';
  $handler->display->display_options['fields']['field_web_server']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_web_server']['delta_offset'] = '0';
  /* Field: COUNT(Content: Web Server) */
  $handler->display->display_options['fields']['field_web_server_1']['id'] = 'field_web_server_1';
  $handler->display->display_options['fields']['field_web_server_1']['table'] = 'field_data_field_web_server';
  $handler->display->display_options['fields']['field_web_server_1']['field'] = 'field_web_server';
  $handler->display->display_options['fields']['field_web_server_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_web_server_1']['separator'] = ', ';
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

  /* Display: Web Servers */
  $handler = $view->new_display('block', 'Web Servers', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Web Servers';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['label_field'] = 'field_web_server';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_web_server_1' => 'field_web_server_1',
    'field_web_server' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_web_server' => '#2f7ed8',
    'field_web_server_1' => '#0d233a',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Web Server */
  $handler->display->display_options['fields']['field_web_server']['id'] = 'field_web_server';
  $handler->display->display_options['fields']['field_web_server']['table'] = 'field_data_field_web_server';
  $handler->display->display_options['fields']['field_web_server']['field'] = 'field_web_server';
  $handler->display->display_options['fields']['field_web_server']['label'] = 'Web Servers';
  $handler->display->display_options['fields']['field_web_server']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_web_server']['delta_offset'] = '0';
  /* Field: COUNT(Content: Web Server) */
  $handler->display->display_options['fields']['field_web_server_1']['id'] = 'field_web_server_1';
  $handler->display->display_options['fields']['field_web_server_1']['table'] = 'field_data_field_web_server';
  $handler->display->display_options['fields']['field_web_server_1']['field'] = 'field_web_server';
  $handler->display->display_options['fields']['field_web_server_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_web_server_1']['label'] = 'Web Servers';
  $handler->display->display_options['fields']['field_web_server_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: COUNT(Content: Web Server (field_web_server)) */
  $handler->display->display_options['sorts']['field_web_server_tid']['id'] = 'field_web_server_tid';
  $handler->display->display_options['sorts']['field_web_server_tid']['table'] = 'field_data_field_web_server';
  $handler->display->display_options['sorts']['field_web_server_tid']['field'] = 'field_web_server_tid';
  $handler->display->display_options['sorts']['field_web_server_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_web_server_tid']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'chart1';

  /* Display: Programming Languages */
  $handler = $view->new_display('block', 'Programming Languages', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Programming Languages';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['label_field'] = 'field_programming_languages';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_programming_languages_1' => 'field_programming_languages_1',
    'field_programming_languages' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_programming_languages' => '#2f7ed8',
    'field_programming_languages_1' => '#0d233a',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Programming Languages */
  $handler->display->display_options['fields']['field_programming_languages']['id'] = 'field_programming_languages';
  $handler->display->display_options['fields']['field_programming_languages']['table'] = 'field_data_field_programming_languages';
  $handler->display->display_options['fields']['field_programming_languages']['field'] = 'field_programming_languages';
  $handler->display->display_options['fields']['field_programming_languages']['delta_offset'] = '0';
  /* Field: COUNT(Content: Programming Languages) */
  $handler->display->display_options['fields']['field_programming_languages_1']['id'] = 'field_programming_languages_1';
  $handler->display->display_options['fields']['field_programming_languages_1']['table'] = 'field_data_field_programming_languages';
  $handler->display->display_options['fields']['field_programming_languages_1']['field'] = 'field_programming_languages';
  $handler->display->display_options['fields']['field_programming_languages_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_programming_languages_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: COUNT(Content: Programming Languages (field_programming_languages)) */
  $handler->display->display_options['sorts']['field_programming_languages_tid']['id'] = 'field_programming_languages_tid';
  $handler->display->display_options['sorts']['field_programming_languages_tid']['table'] = 'field_data_field_programming_languages';
  $handler->display->display_options['sorts']['field_programming_languages_tid']['field'] = 'field_programming_languages_tid';
  $handler->display->display_options['sorts']['field_programming_languages_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_programming_languages_tid']['order'] = 'DESC';

  /* Display: Operating Systems */
  $handler = $view->new_display('block', 'Operating Systems', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Operating Systems';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['label_field'] = 'field_operating_systems';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_operating_systems_1' => 'field_operating_systems_1',
    'field_operating_systems' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_operating_systems' => '#2f7ed8',
    'field_operating_systems_1' => '#0d233a',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Operating Systems */
  $handler->display->display_options['fields']['field_operating_systems']['id'] = 'field_operating_systems';
  $handler->display->display_options['fields']['field_operating_systems']['table'] = 'field_data_field_operating_systems';
  $handler->display->display_options['fields']['field_operating_systems']['field'] = 'field_operating_systems';
  $handler->display->display_options['fields']['field_operating_systems']['delta_offset'] = '0';
  /* Field: COUNT(Content: Operating Systems) */
  $handler->display->display_options['fields']['field_operating_systems_1']['id'] = 'field_operating_systems_1';
  $handler->display->display_options['fields']['field_operating_systems_1']['table'] = 'field_data_field_operating_systems';
  $handler->display->display_options['fields']['field_operating_systems_1']['field'] = 'field_operating_systems';
  $handler->display->display_options['fields']['field_operating_systems_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_operating_systems_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: COUNT(Content: Operating Systems (field_operating_systems)) */
  $handler->display->display_options['sorts']['field_operating_systems_tid']['id'] = 'field_operating_systems_tid';
  $handler->display->display_options['sorts']['field_operating_systems_tid']['table'] = 'field_data_field_operating_systems';
  $handler->display->display_options['sorts']['field_operating_systems_tid']['field'] = 'field_operating_systems_tid';
  $handler->display->display_options['sorts']['field_operating_systems_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_operating_systems_tid']['order'] = 'DESC';

  /* Display: CMS Applications */
  $handler = $view->new_display('block', 'CMS Applications', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'CMS Applications';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['label_field'] = 'field_cms_applications';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_cms_applications_1' => 'field_cms_applications_1',
    'field_cms_applications' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_cms_applications' => '#2f7ed8',
    'field_cms_applications_1' => '#0d233a',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: CMS Applications */
  $handler->display->display_options['fields']['field_cms_applications']['id'] = 'field_cms_applications';
  $handler->display->display_options['fields']['field_cms_applications']['table'] = 'field_data_field_cms_applications';
  $handler->display->display_options['fields']['field_cms_applications']['field'] = 'field_cms_applications';
  $handler->display->display_options['fields']['field_cms_applications']['delta_offset'] = '0';
  /* Field: COUNT(Content: CMS Applications) */
  $handler->display->display_options['fields']['field_cms_applications_1']['id'] = 'field_cms_applications_1';
  $handler->display->display_options['fields']['field_cms_applications_1']['table'] = 'field_data_field_cms_applications';
  $handler->display->display_options['fields']['field_cms_applications_1']['field'] = 'field_cms_applications';
  $handler->display->display_options['fields']['field_cms_applications_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_cms_applications_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: COUNT(Content: CMS Applications (field_cms_applications)) */
  $handler->display->display_options['sorts']['field_cms_applications_tid']['id'] = 'field_cms_applications_tid';
  $handler->display->display_options['sorts']['field_cms_applications_tid']['table'] = 'field_data_field_cms_applications';
  $handler->display->display_options['sorts']['field_cms_applications_tid']['field'] = 'field_cms_applications_tid';
  $handler->display->display_options['sorts']['field_cms_applications_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_cms_applications_tid']['order'] = 'DESC';

  /* Display: CDN Applications */
  $handler = $view->new_display('block', 'CDN Applications', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'CDN Applications';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['label_field'] = 'field_cdn_applications';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_cdn_applications_1' => 'field_cdn_applications_1',
    'field_cdn_applications' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_cdn_applications' => '#2f7ed8',
    'field_cdn_applications_1' => '#0d233a',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: CDN applications */
  $handler->display->display_options['fields']['field_cdn_applications']['id'] = 'field_cdn_applications';
  $handler->display->display_options['fields']['field_cdn_applications']['table'] = 'field_data_field_cdn_applications';
  $handler->display->display_options['fields']['field_cdn_applications']['field'] = 'field_cdn_applications';
  $handler->display->display_options['fields']['field_cdn_applications']['delta_offset'] = '0';
  /* Field: COUNT(Content: CDN applications) */
  $handler->display->display_options['fields']['field_cdn_applications_1']['id'] = 'field_cdn_applications_1';
  $handler->display->display_options['fields']['field_cdn_applications_1']['table'] = 'field_data_field_cdn_applications';
  $handler->display->display_options['fields']['field_cdn_applications_1']['field'] = 'field_cdn_applications';
  $handler->display->display_options['fields']['field_cdn_applications_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_cdn_applications_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: AVG(Content: CDN applications (field_cdn_applications)) */
  $handler->display->display_options['sorts']['field_cdn_applications_tid']['id'] = 'field_cdn_applications_tid';
  $handler->display->display_options['sorts']['field_cdn_applications_tid']['table'] = 'field_data_field_cdn_applications';
  $handler->display->display_options['sorts']['field_cdn_applications_tid']['field'] = 'field_cdn_applications_tid';
  $handler->display->display_options['sorts']['field_cdn_applications_tid']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_cdn_applications_tid']['order'] = 'DESC';

  /* Display: Javascript Frameworks */
  $handler = $view->new_display('block', 'Javascript Frameworks', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Javascript Frameworks';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['label_field'] = 'field_javascript_frameworks';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_javascript_frameworks_1' => 'field_javascript_frameworks_1',
    'field_javascript_frameworks' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_javascript_frameworks' => '#8bbc21',
    'field_javascript_frameworks_1' => '#910000',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Javascript Frameworks */
  $handler->display->display_options['fields']['field_javascript_frameworks']['id'] = 'field_javascript_frameworks';
  $handler->display->display_options['fields']['field_javascript_frameworks']['table'] = 'field_data_field_javascript_frameworks';
  $handler->display->display_options['fields']['field_javascript_frameworks']['field'] = 'field_javascript_frameworks';
  $handler->display->display_options['fields']['field_javascript_frameworks']['delta_offset'] = '0';
  /* Field: COUNT(Content: Javascript Frameworks) */
  $handler->display->display_options['fields']['field_javascript_frameworks_1']['id'] = 'field_javascript_frameworks_1';
  $handler->display->display_options['fields']['field_javascript_frameworks_1']['table'] = 'field_data_field_javascript_frameworks';
  $handler->display->display_options['fields']['field_javascript_frameworks_1']['field'] = 'field_javascript_frameworks';
  $handler->display->display_options['fields']['field_javascript_frameworks_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_javascript_frameworks_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: AVG(Content: Javascript Frameworks (field_javascript_frameworks)) */
  $handler->display->display_options['sorts']['field_javascript_frameworks_tid']['id'] = 'field_javascript_frameworks_tid';
  $handler->display->display_options['sorts']['field_javascript_frameworks_tid']['table'] = 'field_data_field_javascript_frameworks';
  $handler->display->display_options['sorts']['field_javascript_frameworks_tid']['field'] = 'field_javascript_frameworks_tid';
  $handler->display->display_options['sorts']['field_javascript_frameworks_tid']['group_type'] = 'avg';
  $handler->display->display_options['sorts']['field_javascript_frameworks_tid']['order'] = 'DESC';

  /* Display: Analytics Apps */
  $handler = $view->new_display('block', 'Analytics Apps', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Analytics Apps';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['label_field'] = 'field_analytics_applications';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_analytics_applications_1' => 'field_analytics_applications_1',
    'field_analytics_applications' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_analytics_applications' => '#2f7ed8',
    'field_analytics_applications_1' => '#0d233a',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Analytics Applications */
  $handler->display->display_options['fields']['field_analytics_applications']['id'] = 'field_analytics_applications';
  $handler->display->display_options['fields']['field_analytics_applications']['table'] = 'field_data_field_analytics_applications';
  $handler->display->display_options['fields']['field_analytics_applications']['field'] = 'field_analytics_applications';
  $handler->display->display_options['fields']['field_analytics_applications']['delta_offset'] = '0';
  /* Field: COUNT(Content: Analytics Applications) */
  $handler->display->display_options['fields']['field_analytics_applications_1']['id'] = 'field_analytics_applications_1';
  $handler->display->display_options['fields']['field_analytics_applications_1']['table'] = 'field_data_field_analytics_applications';
  $handler->display->display_options['fields']['field_analytics_applications_1']['field'] = 'field_analytics_applications';
  $handler->display->display_options['fields']['field_analytics_applications_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_analytics_applications_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: COUNT(Content: Analytics Applications (field_analytics_applications)) */
  $handler->display->display_options['sorts']['field_analytics_applications_tid']['id'] = 'field_analytics_applications_tid';
  $handler->display->display_options['sorts']['field_analytics_applications_tid']['table'] = 'field_data_field_analytics_applications';
  $handler->display->display_options['sorts']['field_analytics_applications_tid']['field'] = 'field_analytics_applications_tid';
  $handler->display->display_options['sorts']['field_analytics_applications_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_analytics_applications_tid']['order'] = 'DESC';

  /* Display: Web Frameworks */
  $handler = $view->new_display('block', 'Web Frameworks', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Web Frameworks';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['legend_position'] = 'bottom';
  $handler->display->display_options['style_options']['label_field'] = 'field_web_frameworks';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_web_frameworks_1' => 'field_web_frameworks_1',
    'field_web_frameworks' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_web_frameworks' => '#2f7ed8',
    'field_web_frameworks_1' => '#0d233a',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Web Frameworks */
  $handler->display->display_options['fields']['field_web_frameworks']['id'] = 'field_web_frameworks';
  $handler->display->display_options['fields']['field_web_frameworks']['table'] = 'field_data_field_web_frameworks';
  $handler->display->display_options['fields']['field_web_frameworks']['field'] = 'field_web_frameworks';
  $handler->display->display_options['fields']['field_web_frameworks']['delta_offset'] = '0';
  /* Field: COUNT(Content: Web Frameworks) */
  $handler->display->display_options['fields']['field_web_frameworks_1']['id'] = 'field_web_frameworks_1';
  $handler->display->display_options['fields']['field_web_frameworks_1']['table'] = 'field_data_field_web_frameworks';
  $handler->display->display_options['fields']['field_web_frameworks_1']['field'] = 'field_web_frameworks';
  $handler->display->display_options['fields']['field_web_frameworks_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_web_frameworks_1']['separator'] = ', ';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: COUNT(Content: Web Frameworks (field_web_frameworks)) */
  $handler->display->display_options['sorts']['field_web_frameworks_tid']['id'] = 'field_web_frameworks_tid';
  $handler->display->display_options['sorts']['field_web_frameworks_tid']['table'] = 'field_data_field_web_frameworks';
  $handler->display->display_options['sorts']['field_web_frameworks_tid']['field'] = 'field_web_frameworks_tid';
  $handler->display->display_options['sorts']['field_web_frameworks_tid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['field_web_frameworks_tid']['order'] = 'DESC';
  $export['web_servers'] = $view;

  return $export;
}
