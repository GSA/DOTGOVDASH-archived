<?php
/**
 * @file
 * theme_changes.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function theme_changes_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'agency_reports';
  $page->task = 'page';
  $page->admin_title = 'Agency Reports';
  $page->admin_description = '';
  $page->path = 'agency/all/reports-data';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_agency_reports__panel';
  $handler->task = 'page';
  $handler->subtask = 'agency_reports';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'pond';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'column3' => NULL,
      'secondarycolumn1' => NULL,
      'secondarycolumn2' => NULL,
      'secondarycolumn3' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'All Agencies Dashboard Reports';
  $display->uuid = '645a55d6-e8a9-4f5a-9d16-0200261a4546';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_agency_reports__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8e9451c1-b505-4311-b472-ce7b7185aaa3';
  $pane->panel = 'column1';
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
    'display' => 'block_4',
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
  $pane->uuid = '8e9451c1-b505-4311-b472-ce7b7185aaa3';
  $display->content['new-8e9451c1-b505-4311-b472-ce7b7185aaa3'] = $pane;
  $display->panels['column1'][0] = 'new-8e9451c1-b505-4311-b472-ce7b7185aaa3';
  $pane = new stdClass();
  $pane->pid = 'new-89e2d322-fb8a-4c64-af5e-4998c714f1e2';
  $pane->panel = 'column2';
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
    'display' => 'block_5',
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
  $pane->uuid = '89e2d322-fb8a-4c64-af5e-4998c714f1e2';
  $display->content['new-89e2d322-fb8a-4c64-af5e-4998c714f1e2'] = $pane;
  $display->panels['column2'][0] = 'new-89e2d322-fb8a-4c64-af5e-4998c714f1e2';
  $pane = new stdClass();
  $pane->pid = 'new-c4fd9e3b-2fa0-4270-8e63-21d2abb926a5';
  $pane->panel = 'column3';
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
    'display' => 'block_6',
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
  $pane->uuid = 'c4fd9e3b-2fa0-4270-8e63-21d2abb926a5';
  $display->content['new-c4fd9e3b-2fa0-4270-8e63-21d2abb926a5'] = $pane;
  $display->panels['column3'][0] = 'new-c4fd9e3b-2fa0-4270-8e63-21d2abb926a5';
  $pane = new stdClass();
  $pane->pid = 'new-54d85b6c-5d44-49f3-8661-8ee1c6d5d3dd';
  $pane->panel = 'secondarycolumn1';
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
    'display' => 'block_7',
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
  $pane->uuid = '54d85b6c-5d44-49f3-8661-8ee1c6d5d3dd';
  $display->content['new-54d85b6c-5d44-49f3-8661-8ee1c6d5d3dd'] = $pane;
  $display->panels['secondarycolumn1'][0] = 'new-54d85b6c-5d44-49f3-8661-8ee1c6d5d3dd';
  $pane = new stdClass();
  $pane->pid = 'new-e80b1d56-b842-4568-baff-42a75a4eb573';
  $pane->panel = 'secondarycolumn2';
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
    'display' => 'block_8',
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
  $pane->uuid = 'e80b1d56-b842-4568-baff-42a75a4eb573';
  $display->content['new-e80b1d56-b842-4568-baff-42a75a4eb573'] = $pane;
  $display->panels['secondarycolumn2'][0] = 'new-e80b1d56-b842-4568-baff-42a75a4eb573';
  $pane = new stdClass();
  $pane->pid = 'new-4deb793b-02cc-436d-b888-1b151a8983ae';
  $pane->panel = 'secondarycolumn3';
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
    'display' => 'block_9',
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
  $pane->uuid = '4deb793b-02cc-436d-b888-1b151a8983ae';
  $display->content['new-4deb793b-02cc-436d-b888-1b151a8983ae'] = $pane;
  $display->panels['secondarycolumn3'][0] = 'new-4deb793b-02cc-436d-b888-1b151a8983ae';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8e9451c1-b505-4311-b472-ce7b7185aaa3';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['agency_reports'] = $page;

  return $pages;

}
