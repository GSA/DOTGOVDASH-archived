<?php

/**
 * @file
 * uswds_settings.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function uswds_settings_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'uswds';
  $page->task = 'page';
  $page->admin_title = 'uswds';
  $page->admin_description = '';
  $page->path = 'agency/all/uswds';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 13,
            2 => 16,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_uswds__panel_context_33f6e905-4173-4390-b560-54e148a8472c';
  $handler->task = 'page';
  $handler->subtask = 'uswds';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'threecol_42_29_29_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'footer' => NULL,
      'middle' => NULL,
      'bottom_above' => NULL,
      'bottom_below' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Government-Wide USWDS Report';
  $display->uuid = '6737efc9-61a2-4b80-afbb-69ff4bb3396c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_uswds__panel_context_33f6e905-4173-4390-b560-54e148a8472c';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a0c650c3-e83e-4d3d-a8d5-60ebad59dab6';
  $pane->panel = 'bottom_above';
  $pane->type = 'views';
  $pane->subtype = 'all_agency_data';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '12',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'page_11',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a0c650c3-e83e-4d3d-a8d5-60ebad59dab6';
  $display->content['new-a0c650c3-e83e-4d3d-a8d5-60ebad59dab6'] = $pane;
  $display->panels['bottom_above'][0] = 'new-a0c650c3-e83e-4d3d-a8d5-60ebad59dab6';
  $pane = new stdClass();
  $pane->pid = 'new-18249b7c-e15b-48b0-b812-f52c0cbb9420';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'all_agency_data';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_19',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '18249b7c-e15b-48b0-b812-f52c0cbb9420';
  $display->content['new-18249b7c-e15b-48b0-b812-f52c0cbb9420'] = $pane;
  $display->panels['middle'][0] = 'new-18249b7c-e15b-48b0-b812-f52c0cbb9420';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['uswds'] = $page;

  return $pages;

}
