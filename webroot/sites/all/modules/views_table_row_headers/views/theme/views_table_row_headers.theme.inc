<?php
/**
 * @file
 * Preprocessing for views table row headers.
 */

/**
 * Template helper for views_table_row_headers.
 */
function template_preprocess_views_table_row_headers(&$vars) {
  // We build on the default preprocessing for views_view_table.php
  template_preprocess_views_view_table($vars);

  // Add the row header variable
  $view = $vars['view'];
  $options = $view->style_plugin->options;
  $vars['row_header'] = $options['row_header'];
}
