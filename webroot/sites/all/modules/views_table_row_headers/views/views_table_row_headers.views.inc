<?php
/**
 * @file
 * Announces our plugin to views
 */

/**
 * Implements hook_views_plugins().
 */
function views_table_row_headers_views_plugins() {
  $path = drupal_get_path('module', 'views_table_row_headers') . '/views';
  $plugins = array(
    'module' => 'views_table_row_headers',
    'style' => array(
      'table_row_headers' => array(
        'title' => t('Table with row headers'),
        'path' => $path . '/plugins',
        'help' => t('Display view as a table with row and column headers'),
        'handler' => 'views_table_row_headers_plugin_style_table',
        'theme' => 'views_table_row_headers',
        'theme path' => $path . '/theme',
        'theme file'      => 'views_table_row_headers.theme.inc',
        'uses row plugin' => FALSE,
        'uses row class' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
  return $plugins;
}
