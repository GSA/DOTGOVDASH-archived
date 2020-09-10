<?php

/**
 * @file
 * new_mobile_changes.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function new_mobile_changes_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'mobile_data';
  $page->task = 'page';
  $page->admin_title = 'mobile_data';
  $page->admin_description = '';
  $page->path = 'agency/all/mobile_data';
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
  $handler->name = 'page_mobile_data__panel_context_105216fe-5afc-4908-ad37-8d1a99b80196';
  $handler->task = 'page';
  $handler->subtask = 'mobile_data';
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
  $display->layout = 'pond';
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
      'column1' => NULL,
      'column2' => NULL,
      'column3' => NULL,
      'secondarycolumn1' => NULL,
      'secondarycolumn2' => NULL,
      'secondarycolumn3' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Government-Wide  Mobile Report';
  $display->uuid = '6737efc9-61a2-4b80-afbb-69ff4bb3396c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_mobile_data__panel_context_105216fe-5afc-4908-ad37-8d1a99b80196';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b0ab34a3-9f32-4a8a-9764-d485dde39f79';
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
    'display' => 'block_7',
    'override_title' => 1,
    'override_title_text' => 'Government-Wide Mobile Overall Report',
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
  $pane->uuid = 'b0ab34a3-9f32-4a8a-9764-d485dde39f79';
  $display->content['new-b0ab34a3-9f32-4a8a-9764-d485dde39f79'] = $pane;
  $display->panels['column1'][0] = 'new-b0ab34a3-9f32-4a8a-9764-d485dde39f79';
  $pane = new stdClass();
  $pane->pid = 'new-3ba00497-0022-4b04-81a7-94fb40e1eb6f';
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
    'display' => 'block_8',
    'override_title' => 1,
    'override_title_text' => 'Government-Wide Mobile Performance Report',
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
  $pane->uuid = '3ba00497-0022-4b04-81a7-94fb40e1eb6f';
  $display->content['new-3ba00497-0022-4b04-81a7-94fb40e1eb6f'] = $pane;
  $display->panels['column2'][0] = 'new-3ba00497-0022-4b04-81a7-94fb40e1eb6f';
  $pane = new stdClass();
  $pane->pid = 'new-7ab6206b-e71f-4510-b1b2-52632a1e0e94';
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
    'display' => 'block_9',
    'override_title' => 1,
    'override_title_text' => 'Government-Wide Mobile Friendly Report',
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
  $pane->uuid = '7ab6206b-e71f-4510-b1b2-52632a1e0e94';
  $display->content['new-7ab6206b-e71f-4510-b1b2-52632a1e0e94'] = $pane;
  $display->panels['column3'][0] = 'new-7ab6206b-e71f-4510-b1b2-52632a1e0e94';
  $pane = new stdClass();
  $pane->pid = 'new-649c2732-7015-4cde-af4c-1e1be29442bf';
  $pane->panel = 'footer';
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
    'display' => 'page_4',
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
  $pane->uuid = '649c2732-7015-4cde-af4c-1e1be29442bf';
  $display->content['new-649c2732-7015-4cde-af4c-1e1be29442bf'] = $pane;
  $display->panels['footer'][0] = 'new-649c2732-7015-4cde-af4c-1e1be29442bf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['mobile_data'] = $page;

  return $pages;

}
