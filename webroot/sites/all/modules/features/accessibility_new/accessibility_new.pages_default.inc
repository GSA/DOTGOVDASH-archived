<?php
/**
 * @file
 * accessibility_new.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function accessibility_new_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = '_government_wide_accessibility_report';
  $page->task = 'page';
  $page->admin_title = 'Accessibility Report';
  $page->admin_description = ' Government Wide Accessibility Report';
  $page->path = 'gov-wide-accessibility';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page__government_wide_accessibility_report__panel';
  $handler->task = 'page';
  $handler->subtask = '_government_wide_accessibility_report';
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
  );
  $display = new panels_display();
  $display->layout = 'twocol_bricks';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => array(
        'corner_location' => 'pane',
      ),
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
    ),
    'top' => array(
      'style' => 'rounded_corners',
    ),
  );
  $display->cache = array();
  $display->title = 'Accessibility Report<a href="content/accessibility-guidance" style="color:red;">*</a>';
  $display->uuid = 'c7b50fe9-abf3-4bb1-a26f-c01731065f7d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page__government_wide_accessibility_report__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6f005a17-1cd6-4795-9225-26eec42f1508';
  $pane->panel = 'left_above';
  $pane->type = 'views';
  $pane->subtype = 'accessibility_report';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'attachment_6',
    'override_title' => 1,
    'override_title_text' => 'Agencies with Most Accessibility Findings',
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
  $pane->uuid = '6f005a17-1cd6-4795-9225-26eec42f1508';
  $display->content['new-6f005a17-1cd6-4795-9225-26eec42f1508'] = $pane;
  $display->panels['left_above'][0] = 'new-6f005a17-1cd6-4795-9225-26eec42f1508';
  $pane = new stdClass();
  $pane->pid = 'new-acaf5984-f12d-4e5e-a817-983b9990f872';
  $pane->panel = 'left_above';
  $pane->type = 'views';
  $pane->subtype = 'accessibility_report';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'attachment_2',
    'override_title' => 1,
    'override_title_text' => 'Domains with Most Accessibility Findings',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'acaf5984-f12d-4e5e-a817-983b9990f872';
  $display->content['new-acaf5984-f12d-4e5e-a817-983b9990f872'] = $pane;
  $display->panels['left_above'][1] = 'new-acaf5984-f12d-4e5e-a817-983b9990f872';
  $pane = new stdClass();
  $pane->pid = 'new-74e3ec8f-f14a-45a9-82cc-407187982cd5';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'accessibility_report';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'page',
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
  $pane->uuid = '74e3ec8f-f14a-45a9-82cc-407187982cd5';
  $display->content['new-74e3ec8f-f14a-45a9-82cc-407187982cd5'] = $pane;
  $display->panels['middle'][0] = 'new-74e3ec8f-f14a-45a9-82cc-407187982cd5';
  $pane = new stdClass();
  $pane->pid = 'new-073ce5d4-49f0-42a3-8455-764ae4934274';
  $pane->panel = 'right_above';
  $pane->type = 'views';
  $pane->subtype = 'accessibility_report';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'attachment_7',
    'override_title' => 1,
    'override_title_text' => 'Agencies with Least Accessibility Findings',
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
  $pane->uuid = '073ce5d4-49f0-42a3-8455-764ae4934274';
  $display->content['new-073ce5d4-49f0-42a3-8455-764ae4934274'] = $pane;
  $display->panels['right_above'][0] = 'new-073ce5d4-49f0-42a3-8455-764ae4934274';
  $pane = new stdClass();
  $pane->pid = 'new-ad669e59-de98-4c31-ae38-e75addd7680e';
  $pane->panel = 'right_above';
  $pane->type = 'views';
  $pane->subtype = 'accessibility_report';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
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
    'override_title_text' => 'Government-Wide Accessibility chart',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ad669e59-de98-4c31-ae38-e75addd7680e';
  $display->content['new-ad669e59-de98-4c31-ae38-e75addd7680e'] = $pane;
  $display->panels['right_above'][1] = 'new-ad669e59-de98-4c31-ae38-e75addd7680e';
  $pane = new stdClass();
  $pane->pid = 'new-81e3eff4-550e-4d1d-924e-55ae5a1d1f6e';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'block-4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '81e3eff4-550e-4d1d-924e-55ae5a1d1f6e';
  $display->content['new-81e3eff4-550e-4d1d-924e-55ae5a1d1f6e'] = $pane;
  $display->panels['top'][0] = 'new-81e3eff4-550e-4d1d-924e-55ae5a1d1f6e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['_government_wide_accessibility_report'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'my_agency_accessibility_page';
  $page->task = 'page';
  $page->admin_title = 'My Agency Accessibility page';
  $page->admin_description = 'My Agency Accessibility page';
  $page->path = 'my-agency-accessibility';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_my_agency_accessibility_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'my_agency_accessibility_page';
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
  );
  $display = new panels_display();
  $display->layout = 'sutro';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8787a157-ea09-4fc5-a1ca-496fc38346c8';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_my_agency_accessibility_page__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cfde5a91-a0a3-454a-a2a8-88b7767bd5d0';
  $pane->panel = 'column1';
  $pane->type = 'views';
  $pane->subtype = 'accessibility_report';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'attachment_3',
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
  $pane->uuid = 'cfde5a91-a0a3-454a-a2a8-88b7767bd5d0';
  $display->content['new-cfde5a91-a0a3-454a-a2a8-88b7767bd5d0'] = $pane;
  $display->panels['column1'][0] = 'new-cfde5a91-a0a3-454a-a2a8-88b7767bd5d0';
  $pane = new stdClass();
  $pane->pid = 'new-888f4a2b-832f-4b12-a2d9-30969a6026a9';
  $pane->panel = 'column2';
  $pane->type = 'views';
  $pane->subtype = 'accessibility_report';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'attachment_4',
    'override_title' => 1,
    'override_title_text' => 'Top Websites with Accessibility Errors',
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
  $pane->uuid = '888f4a2b-832f-4b12-a2d9-30969a6026a9';
  $display->content['new-888f4a2b-832f-4b12-a2d9-30969a6026a9'] = $pane;
  $display->panels['column2'][0] = 'new-888f4a2b-832f-4b12-a2d9-30969a6026a9';
  $pane = new stdClass();
  $pane->pid = 'new-b4601698-75c4-44ee-bfbb-455ea5b70228';
  $pane->panel = 'footer';
  $pane->type = 'views';
  $pane->subtype = 'accessibility_report';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
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
  $pane->uuid = 'b4601698-75c4-44ee-bfbb-455ea5b70228';
  $display->content['new-b4601698-75c4-44ee-bfbb-455ea5b70228'] = $pane;
  $display->panels['footer'][0] = 'new-b4601698-75c4-44ee-bfbb-455ea5b70228';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cfde5a91-a0a3-454a-a2a8-88b7767bd5d0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['my_agency_accessibility_page'] = $page;

  return $pages;

}
