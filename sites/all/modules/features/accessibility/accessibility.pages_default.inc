<?php
/**
 * @file
 * accessibility.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function accessibility_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = '_government_wide_accessibility_report';
  $page->task = 'page';
  $page->admin_title = ' Government Wide Accessibility Report';
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
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Government Wide accessibility report';
  $display->uuid = 'c7b50fe9-abf3-4bb1-a26f-c01731065f7d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page__government_wide_accessibility_report__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-12a5162b-0ff8-4696-ba2d-c882bb768197';
  $pane->panel = 'left_above';
  $pane->type = 'views';
  $pane->subtype = 'accessibility_report';
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
    'display' => 'attachment_5',
    'override_title' => 1,
    'override_title_text' => 'Accessibility Breakdown by Type of Errors',
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
  $pane->uuid = '12a5162b-0ff8-4696-ba2d-c882bb768197';
  $display->content['new-12a5162b-0ff8-4696-ba2d-c882bb768197'] = $pane;
  $display->panels['left_above'][0] = 'new-12a5162b-0ff8-4696-ba2d-c882bb768197';
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
    'override_title_text' => 'Top 10 Agencies with Accessibility Errors',
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
  $pane->uuid = '6f005a17-1cd6-4795-9225-26eec42f1508';
  $display->content['new-6f005a17-1cd6-4795-9225-26eec42f1508'] = $pane;
  $display->panels['left_above'][1] = 'new-6f005a17-1cd6-4795-9225-26eec42f1508';
  $pane = new stdClass();
  $pane->pid = 'new-ea0102d3-9551-4dd7-82ef-19e16927270d';
  $pane->panel = 'left_above';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'ea0102d3-9551-4dd7-82ef-19e16927270d';
  $display->content['new-ea0102d3-9551-4dd7-82ef-19e16927270d'] = $pane;
  $display->panels['left_above'][2] = 'new-ea0102d3-9551-4dd7-82ef-19e16927270d';
  $pane = new stdClass();
  $pane->pid = 'new-054c18a7-d9d7-41c9-a586-6d88bc0c2493';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'accessibility_report';
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
    'display' => 'attachment_1',
    'override_title' => 1,
    'override_title_text' => 'Accessibility Error Breakdown of top 5 sites',
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
  $pane->uuid = '054c18a7-d9d7-41c9-a586-6d88bc0c2493';
  $display->content['new-054c18a7-d9d7-41c9-a586-6d88bc0c2493'] = $pane;
  $display->panels['middle'][0] = 'new-054c18a7-d9d7-41c9-a586-6d88bc0c2493';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '74e3ec8f-f14a-45a9-82cc-407187982cd5';
  $display->content['new-74e3ec8f-f14a-45a9-82cc-407187982cd5'] = $pane;
  $display->panels['middle'][1] = 'new-74e3ec8f-f14a-45a9-82cc-407187982cd5';
  $pane = new stdClass();
  $pane->pid = 'new-acaf5984-f12d-4e5e-a817-983b9990f872';
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
    'display' => 'attachment_2',
    'override_title' => 1,
    'override_title_text' => 'Top 10 Sites with Accessibility Error',
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
  $pane->uuid = 'acaf5984-f12d-4e5e-a817-983b9990f872';
  $display->content['new-acaf5984-f12d-4e5e-a817-983b9990f872'] = $pane;
  $display->panels['right_above'][0] = 'new-acaf5984-f12d-4e5e-a817-983b9990f872';
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
    'override_title_text' => 'Top Accessibility Compliant Agencies',
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
  $pane->uuid = '073ce5d4-49f0-42a3-8455-764ae4934274';
  $display->content['new-073ce5d4-49f0-42a3-8455-764ae4934274'] = $pane;
  $display->panels['right_above'][1] = 'new-073ce5d4-49f0-42a3-8455-764ae4934274';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-12a5162b-0ff8-4696-ba2d-c882bb768197';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['_government_wide_accessibility_report'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'access_denied_login';
  $page->task = 'page';
  $page->admin_title = 'access_denied_login';
  $page->admin_description = 'access_denied_login';
  $page->path = 'access_denied_login';
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
  $handler->name = 'page_access_denied_login__panel';
  $handler->task = 'page';
  $handler->subtask = 'access_denied_login';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'You don\'t have access to this content',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      11 => NULL,
      12 => NULL,
      13 => NULL,
      21 => NULL,
      22 => NULL,
      23 => NULL,
      31 => NULL,
      32 => NULL,
      33 => NULL,
      41 => NULL,
      42 => NULL,
      43 => NULL,
      44 => NULL,
      51 => NULL,
      52 => NULL,
      53 => NULL,
      54 => NULL,
      61 => NULL,
      62 => NULL,
      63 => NULL,
      64 => NULL,
      71 => NULL,
      72 => NULL,
      73 => NULL,
      74 => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '461e9f7e-c7d4-476c-a17a-2f2a2bce6be8';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_access_denied_login__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c23035ae-d5e1-4a0a-91fe-1ec27877d6a2';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Access Denied',
    'title_heading' => 'h2',
    'body' => '<h3>You currently do not have access to the content. <a href="mailto: dotgovdashboard@gsa.gov">Click Here to Contact the Digital Dashboard Administrator</a></h3>
<p><strong>By logging in, you agree and adhere to the following terms of use:</strong></p>

			<p>This is an Alpha version of the .Gov Dashboard. The results shown are preliminary only and should not be used, shared or referenced in any official or internal reports.&nbsp;</p>

',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c23035ae-d5e1-4a0a-91fe-1ec27877d6a2';
  $display->content['new-c23035ae-d5e1-4a0a-91fe-1ec27877d6a2'] = $pane;
  $display->panels['middle'][0] = 'new-c23035ae-d5e1-4a0a-91fe-1ec27877d6a2';
  $pane = new stdClass();
  $pane->pid = 'new-49e3fcc9-53dd-42ed-b565-40bde00a2514';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '49e3fcc9-53dd-42ed-b565-40bde00a2514';
  $display->content['new-49e3fcc9-53dd-42ed-b565-40bde00a2514'] = $pane;
  $display->panels['middle'][1] = 'new-49e3fcc9-53dd-42ed-b565-40bde00a2514';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-49e3fcc9-53dd-42ed-b565-40bde00a2514';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['access_denied_login'] = $page;

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
    'style' => 'default',
  );
  $display->cache = array();
  $display->title = 'Top Compliant Agencies';
  $display->uuid = '645a55d6-e8a9-4f5a-9d16-0200261a4546';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_agency_reports__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-89e2d322-fb8a-4c64-af5e-4998c714f1e2';
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
    'display' => 'block_5',
    'override_title' => 1,
    'override_title_text' => 'Government-Wide HTTPS Report',
    'override_title_heading' => 'h3',
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
  $display->panels['column1'][0] = 'new-89e2d322-fb8a-4c64-af5e-4998c714f1e2';
  $pane = new stdClass();
  $pane->pid = 'new-c4fd9e3b-2fa0-4270-8e63-21d2abb926a5';
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
    'display' => 'block_6',
    'override_title' => 1,
    'override_title_text' => 'Government-Wide DAP Report',
    'override_title_heading' => 'h3',
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
  $display->panels['column2'][0] = 'new-c4fd9e3b-2fa0-4270-8e63-21d2abb926a5';
  $pane = new stdClass();
  $pane->pid = 'new-54d85b6c-5d44-49f3-8661-8ee1c6d5d3dd';
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
    'display' => 'block_7',
    'override_title' => 1,
    'override_title_text' => 'Government-Wide Mobile Overall Report',
    'override_title_heading' => 'h3',
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
  $display->panels['column3'][0] = 'new-54d85b6c-5d44-49f3-8661-8ee1c6d5d3dd';
  $pane = new stdClass();
  $pane->pid = 'new-e80b1d56-b842-4568-baff-42a75a4eb573';
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
    'display' => 'block_8',
    'override_title' => 1,
    'override_title_text' => 'Government-Wide Mobile Performance Report',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e80b1d56-b842-4568-baff-42a75a4eb573';
  $display->content['new-e80b1d56-b842-4568-baff-42a75a4eb573'] = $pane;
  $display->panels['secondarycolumn1'][0] = 'new-e80b1d56-b842-4568-baff-42a75a4eb573';
  $pane = new stdClass();
  $pane->pid = 'new-6f27cabc-ec8a-4818-ad7d-9de8dbb3fa0e';
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
    'display' => 'block_11',
    'override_title' => 1,
    'override_title_text' => 'Government-Wide IPv6 Report',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'clearfix panel-seperator',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6f27cabc-ec8a-4818-ad7d-9de8dbb3fa0e';
  $display->content['new-6f27cabc-ec8a-4818-ad7d-9de8dbb3fa0e'] = $pane;
  $display->panels['secondarycolumn1'][1] = 'new-6f27cabc-ec8a-4818-ad7d-9de8dbb3fa0e';
  $pane = new stdClass();
  $pane->pid = 'new-4deb793b-02cc-436d-b888-1b151a8983ae';
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
    'display' => 'block_9',
    'override_title' => 1,
    'override_title_text' => 'Government-Wide Mobile Friendly Report',
    'override_title_heading' => 'h3',
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
  $display->panels['secondarycolumn2'][0] = 'new-4deb793b-02cc-436d-b888-1b151a8983ae';
  $pane = new stdClass();
  $pane->pid = 'new-811fd461-5453-49ad-b800-2af4d26916ae';
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
    'display' => 'block_14',
    'override_title' => 1,
    'override_title_text' => 'Government-Wide Site Speed Report',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '811fd461-5453-49ad-b800-2af4d26916ae';
  $display->content['new-811fd461-5453-49ad-b800-2af4d26916ae'] = $pane;
  $display->panels['secondarycolumn2'][1] = 'new-811fd461-5453-49ad-b800-2af4d26916ae';
  $pane = new stdClass();
  $pane->pid = 'new-9a33f7f2-1b97-453a-b2b3-bbf74cfde158';
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
    'display' => 'block_12',
    'override_title' => 1,
    'override_title_text' => 'Government-Wide DNSSEC Report',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9a33f7f2-1b97-453a-b2b3-bbf74cfde158';
  $display->content['new-9a33f7f2-1b97-453a-b2b3-bbf74cfde158'] = $pane;
  $display->panels['secondarycolumn3'][0] = 'new-9a33f7f2-1b97-453a-b2b3-bbf74cfde158';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['agency_reports'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dap_data';
  $page->task = 'page';
  $page->admin_title = 'dap_data';
  $page->admin_description = '';
  $page->path = 'agency/all/dap_data';
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
  $handler->name = 'page_dap_data__panel_context_43903ea0-5e63-40ce-8f64-7f092d932bd3';
  $handler->task = 'page';
  $handler->subtask = 'dap_data';
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
  $display->title = 'Government-Wide  DAP Report';
  $display->uuid = '6737efc9-61a2-4b80-afbb-69ff4bb3396c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dap_data__panel_context_43903ea0-5e63-40ce-8f64-7f092d932bd3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-57006794-2c2e-4102-9881-b9d77a9f6dc6';
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
    'display' => 'page_3',
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
  $pane->uuid = '57006794-2c2e-4102-9881-b9d77a9f6dc6';
  $display->content['new-57006794-2c2e-4102-9881-b9d77a9f6dc6'] = $pane;
  $display->panels['bottom_above'][0] = 'new-57006794-2c2e-4102-9881-b9d77a9f6dc6';
  $pane = new stdClass();
  $pane->pid = 'new-a2098bdf-36a0-4124-9e2c-187ac9515947';
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
    'display' => 'block_6',
    'override_title' => 1,
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
  $pane->uuid = 'a2098bdf-36a0-4124-9e2c-187ac9515947';
  $display->content['new-a2098bdf-36a0-4124-9e2c-187ac9515947'] = $pane;
  $display->panels['middle'][0] = 'new-a2098bdf-36a0-4124-9e2c-187ac9515947';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['dap_data'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dashboard';
  $page->task = 'page';
  $page->admin_title = 'Dashboard';
  $page->admin_description = '';
  $page->path = 'website/%node/information';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
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
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dashboard__panel_context_0f860371-e55f-49f9-b683-1c7bd7a0f794';
  $handler->task = 'page';
  $handler->subtask = 'dashboard';
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
      'middle' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'column3' => NULL,
      'secondarycolumn1' => NULL,
      'secondarycolumn2' => NULL,
      'secondarycolumn3' => NULL,
      'footer' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1a8d5b03-ba7c-442a-83eb-0fd5402192ae';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dashboard__panel_context_0f860371-e55f-49f9-b683-1c7bd7a0f794';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ffbc4cd5-cd86-421b-a81f-ad5965ecf2da';
  $pane->panel = 'column1';
  $pane->type = 'views';
  $pane->subtype = 'website_information';
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
    'display' => 'block',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'website-information',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ffbc4cd5-cd86-421b-a81f-ad5965ecf2da';
  $display->content['new-ffbc4cd5-cd86-421b-a81f-ad5965ecf2da'] = $pane;
  $display->panels['column1'][0] = 'new-ffbc4cd5-cd86-421b-a81f-ad5965ecf2da';
  $pane = new stdClass();
  $pane->pid = 'new-670eef5c-71d6-420d-95a9-c4bf0219637b';
  $pane->panel = 'column2';
  $pane->type = 'views';
  $pane->subtype = 'website_information';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
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
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'domain-information',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '670eef5c-71d6-420d-95a9-c4bf0219637b';
  $display->content['new-670eef5c-71d6-420d-95a9-c4bf0219637b'] = $pane;
  $display->panels['column2'][0] = 'new-670eef5c-71d6-420d-95a9-c4bf0219637b';
  $pane = new stdClass();
  $pane->pid = 'new-9a4885e9-8c94-4734-878a-91df19574492';
  $pane->panel = 'column3';
  $pane->type = 'block';
  $pane->subtype = 'dotgov_common-technology_stack';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'marketplace',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9a4885e9-8c94-4734-878a-91df19574492';
  $display->content['new-9a4885e9-8c94-4734-878a-91df19574492'] = $pane;
  $display->panels['column3'][0] = 'new-9a4885e9-8c94-4734-878a-91df19574492';
  $pane = new stdClass();
  $pane->pid = 'new-d8887055-beaa-4124-a4c4-0927304e5924';
  $pane->panel = 'header';
  $pane->type = 'views';
  $pane->subtype = 'website_information';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_5',
    'context' => array(
      0 => '',
    ),
    'override_title' => 1,
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
  $pane->uuid = 'd8887055-beaa-4124-a4c4-0927304e5924';
  $display->content['new-d8887055-beaa-4124-a4c4-0927304e5924'] = $pane;
  $display->panels['header'][0] = 'new-d8887055-beaa-4124-a4c4-0927304e5924';
  $pane = new stdClass();
  $pane->pid = 'new-58053895-a9de-4f10-838f-9b5816257fe2';
  $pane->panel = 'secondarycolumn1';
  $pane->type = 'views';
  $pane->subtype = 'website_information';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_2',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = '58053895-a9de-4f10-838f-9b5816257fe2';
  $display->content['new-58053895-a9de-4f10-838f-9b5816257fe2'] = $pane;
  $display->panels['secondarycolumn1'][0] = 'new-58053895-a9de-4f10-838f-9b5816257fe2';
  $pane = new stdClass();
  $pane->pid = 'new-dfdd1695-ed88-4e77-a3df-73664aaa62bb';
  $pane->panel = 'secondarycolumn1';
  $pane->type = 'views';
  $pane->subtype = 'website_information';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_6',
    'context' => array(
      0 => '',
    ),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dfdd1695-ed88-4e77-a3df-73664aaa62bb';
  $display->content['new-dfdd1695-ed88-4e77-a3df-73664aaa62bb'] = $pane;
  $display->panels['secondarycolumn1'][1] = 'new-dfdd1695-ed88-4e77-a3df-73664aaa62bb';
  $pane = new stdClass();
  $pane->pid = 'new-c50ec242-37ee-47af-b426-2c470210a469';
  $pane->panel = 'secondarycolumn2';
  $pane->type = 'views';
  $pane->subtype = 'website_information';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_3',
    'context' => array(
      0 => 'argument_entity_id:node_1.field_website_id',
    ),
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
  $pane->uuid = 'c50ec242-37ee-47af-b426-2c470210a469';
  $display->content['new-c50ec242-37ee-47af-b426-2c470210a469'] = $pane;
  $display->panels['secondarycolumn2'][0] = 'new-c50ec242-37ee-47af-b426-2c470210a469';
  $pane = new stdClass();
  $pane->pid = 'new-0eea6ab9-38d5-41b7-ae5a-dcc20a4ecd43';
  $pane->panel = 'secondarycolumn2';
  $pane->type = 'views';
  $pane->subtype = 'website_information';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
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
    'context' => array(
      0 => '',
    ),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0eea6ab9-38d5-41b7-ae5a-dcc20a4ecd43';
  $display->content['new-0eea6ab9-38d5-41b7-ae5a-dcc20a4ecd43'] = $pane;
  $display->panels['secondarycolumn2'][1] = 'new-0eea6ab9-38d5-41b7-ae5a-dcc20a4ecd43';
  $pane = new stdClass();
  $pane->pid = 'new-7ccc5976-5abf-4d58-80ff-3c4a254a487c';
  $pane->panel = 'secondarycolumn3';
  $pane->type = 'views';
  $pane->subtype = 'website_information';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '10',
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
  $pane->uuid = '7ccc5976-5abf-4d58-80ff-3c4a254a487c';
  $display->content['new-7ccc5976-5abf-4d58-80ff-3c4a254a487c'] = $pane;
  $display->panels['secondarycolumn3'][0] = 'new-7ccc5976-5abf-4d58-80ff-3c4a254a487c';
  $pane = new stdClass();
  $pane->pid = 'new-3a8fd3dd-cffa-4f19-a6ba-4b9df684dd59';
  $pane->panel = 'secondarycolumn3';
  $pane->type = 'views';
  $pane->subtype = 'website_information';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_8',
    'context' => array(
      0 => '',
    ),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3a8fd3dd-cffa-4f19-a6ba-4b9df684dd59';
  $display->content['new-3a8fd3dd-cffa-4f19-a6ba-4b9df684dd59'] = $pane;
  $display->panels['secondarycolumn3'][1] = 'new-3a8fd3dd-cffa-4f19-a6ba-4b9df684dd59';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['dashboard'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dnssec_data';
  $page->task = 'page';
  $page->admin_title = 'dnssec_data';
  $page->admin_description = '';
  $page->path = 'agency/all/dnssec_data';
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
  $handler->name = 'page_dnssec_data__panel_context_bd013082-8467-42c8-8b21-b9616646c362';
  $handler->task = 'page';
  $handler->subtask = 'dnssec_data';
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
  $display->title = 'Government-Wide  DNSSEC Report';
  $display->uuid = '6737efc9-61a2-4b80-afbb-69ff4bb3396c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_dnssec_data__panel_context_bd013082-8467-42c8-8b21-b9616646c362';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fae67b58-bd2e-413f-83ea-6b27767f1d96';
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
    'display' => 'page_8',
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
  $pane->uuid = 'fae67b58-bd2e-413f-83ea-6b27767f1d96';
  $display->content['new-fae67b58-bd2e-413f-83ea-6b27767f1d96'] = $pane;
  $display->panels['bottom_above'][0] = 'new-fae67b58-bd2e-413f-83ea-6b27767f1d96';
  $pane = new stdClass();
  $pane->pid = 'new-fba99077-f3a0-4de5-bf1b-2e6395f19820';
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
    'display' => 'block_12',
    'override_title' => 1,
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
  $pane->uuid = 'fba99077-f3a0-4de5-bf1b-2e6395f19820';
  $display->content['new-fba99077-f3a0-4de5-bf1b-2e6395f19820'] = $pane;
  $display->panels['middle'][0] = 'new-fba99077-f3a0-4de5-bf1b-2e6395f19820';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['dnssec_data'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'home';
  $page->admin_description = '';
  $page->path = 'home';
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
  $handler->name = 'page_home__panel_context_76fb44eb-e89f-4226-8be5-f301778407a2';
  $handler->task = 'page';
  $handler->subtask = 'home';
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
    'name' => '',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Welcome to Dotgov Performace Dashboard';
  $display->uuid = 'b12b9a65-a6c5-41d7-85d1-afeccd05a8bd';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home__panel_context_76fb44eb-e89f-4226-8be5-f301778407a2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1129c6cd-b650-4be0-abc8-1882e9fab0cd';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam ac ante tellus. Maecenas dictum elit id elementum vestibulum. Quisque eu dictum nisl. Fusce nunc nibh, faucibus et odio vitae, condimentum varius velit. Integer placerat massa massa, ac sodales justo feugiat id. Maecenas nunc arcu, consequat ac sodales non, luctus vel magna. Nam vel nibh tincidunt, fringilla neque sit amet, pellentesque sem. Vivamus hendrerit interdum nunc in porta. Morbi mollis tincidunt felis quis mattis. Etiam rutrum dapibus imperdiet. Maecenas scelerisque justo quis mauris tincidunt placerat. Vestibulum tellus justo, venenatis eu velit viverra, maximus gravida lectus.',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1129c6cd-b650-4be0-abc8-1882e9fab0cd';
  $display->content['new-1129c6cd-b650-4be0-abc8-1882e9fab0cd'] = $pane;
  $display->panels['middle'][0] = 'new-1129c6cd-b650-4be0-abc8-1882e9fab0cd';
  $pane = new stdClass();
  $pane->pid = 'new-cd91d57e-d7d0-45ef-bbd9-3f58c92bddcd';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'homepage';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'white-back',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'cd91d57e-d7d0-45ef-bbd9-3f58c92bddcd';
  $display->content['new-cd91d57e-d7d0-45ef-bbd9-3f58c92bddcd'] = $pane;
  $display->panels['middle'][1] = 'new-cd91d57e-d7d0-45ef-bbd9-3f58c92bddcd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cd91d57e-d7d0-45ef-bbd9-3f58c92bddcd';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home_page';
  $page->task = 'page';
  $page->admin_title = 'Home Page';
  $page->admin_description = '';
  $page->path = 'homepage';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
            1 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
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
  $handler->name = 'page_home_page__panel_context_a5af261a-25c4-4533-908a-0781009dc82e';
  $handler->task = 'page';
  $handler->subtask = 'home_page';
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
      'middle' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'column3' => NULL,
      'secondarycolumn1' => NULL,
      'secondarycolumn2' => NULL,
      'secondarycolumn3' => NULL,
      'footer' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1a8d5b03-ba7c-442a-83eb-0fd5402192ae';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home_page__panel_context_a5af261a-25c4-4533-908a-0781009dc82e';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b02dc041-1069-4aab-ba63-9566fbf99f4f';
  $pane->panel = 'column1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Government-Wide Reports',
    'title' => '<a href=\'/overall/gov-wide-compliance?field_web_agency_id_nid=All\'>Government-Wide Reports</a>',
    'title_heading' => 'h2',
    'body' => '<p>Government-wide compliance with OMB directives and conformance to best practices and industry standards.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'domain-information',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b02dc041-1069-4aab-ba63-9566fbf99f4f';
  $display->content['new-b02dc041-1069-4aab-ba63-9566fbf99f4f'] = $pane;
  $display->panels['column1'][0] = 'new-b02dc041-1069-4aab-ba63-9566fbf99f4f';
  $pane = new stdClass();
  $pane->pid = 'new-e47023a6-8d22-45ac-a22c-97ffc25c93e4';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Agency-Wide Reports',
    'title' => '<a href=\'/agency/all/data#overlay-context=overall/compliance%3Ffield_web_agency_id_nid%3DAll\'>Agency-Wide Reports</a>',
    'title_heading' => 'h2',
    'body' => '<p>View Agency-Wide compliance summary report for all websites belonging to an agency.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'web-compliance',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e47023a6-8d22-45ac-a22c-97ffc25c93e4';
  $display->content['new-e47023a6-8d22-45ac-a22c-97ffc25c93e4'] = $pane;
  $display->panels['column2'][0] = 'new-e47023a6-8d22-45ac-a22c-97ffc25c93e4';
  $pane = new stdClass();
  $pane->pid = 'new-e267e7a8-b151-4dea-94e1-ed30ee2ab6ec';
  $pane->panel = 'column3';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Domain-Wide Reports',
    'title' => '<a href=\'/website/all/reports\'>Domain-Specific Reports</a>',
    'title_heading' => 'h2',
    'body' => '<p>Get a detailed overview of various compliance and statistics for a particular website.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'agency-complaince',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e267e7a8-b151-4dea-94e1-ed30ee2ab6ec';
  $display->content['new-e267e7a8-b151-4dea-94e1-ed30ee2ab6ec'] = $pane;
  $display->panels['column3'][0] = 'new-e267e7a8-b151-4dea-94e1-ed30ee2ab6ec';
  $pane = new stdClass();
  $pane->pid = 'new-781657b9-8707-4af5-a7d2-444fc83fa38d';
  $pane->panel = 'secondarycolumn1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Top Performing Agencies ',
    'title' => '<a href=\'/agency/all/reports-data\'>Top Performing Agencies</a>',
    'title_heading' => 'h2',
    'body' => '<p>View a summary of Top Compliant executive branch agencies across the various OMB directives , Industry Standards and Best practices for websites.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'website-information',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '781657b9-8707-4af5-a7d2-444fc83fa38d';
  $display->content['new-781657b9-8707-4af5-a7d2-444fc83fa38d'] = $pane;
  $display->panels['secondarycolumn1'][0] = 'new-781657b9-8707-4af5-a7d2-444fc83fa38d';
  $pane = new stdClass();
  $pane->pid = 'new-3c5e13d2-7cd7-4a37-a820-5fa93a44273f';
  $pane->panel = 'secondarycolumn2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Technology-stack',
    'title' => '<a href=\'/technology-overview\'>Technology Stack</a>',
    'title_heading' => 'h2',
    'body' => '<p>An advanced faceted search mechanism allows to search websites according to various criteria. Bookmark these findings in your browser to create your own custom report.</p>
',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'search-reports',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3c5e13d2-7cd7-4a37-a820-5fa93a44273f';
  $display->content['new-3c5e13d2-7cd7-4a37-a820-5fa93a44273f'] = $pane;
  $display->panels['secondarycolumn2'][0] = 'new-3c5e13d2-7cd7-4a37-a820-5fa93a44273f';
  $pane = new stdClass();
  $pane->pid = 'new-35b43834-fd9a-4296-a1ce-53147aad7184';
  $pane->panel = 'secondarycolumn3';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Data Discovery',
    'title' => '<a href=\'/search/site/%2A\'>Data Discovery</a>',
    'title_heading' => 'h2',
    'body' => '<p>Conduct ad-hoc analysis, find data with agency website information to find and discover further insights</p>
',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'marketplace',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '35b43834-fd9a-4296-a1ce-53147aad7184';
  $display->content['new-35b43834-fd9a-4296-a1ce-53147aad7184'] = $pane;
  $display->panels['secondarycolumn3'][0] = 'new-35b43834-fd9a-4296-a1ce-53147aad7184';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'https_data';
  $page->task = 'page';
  $page->admin_title = 'https_data';
  $page->admin_description = '';
  $page->path = 'agency/all/https_data';
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
  $handler->name = 'page_https_data__panel_context_5afdcb0c-7706-4b9f-89a5-8a94ab90b31c';
  $handler->task = 'page';
  $handler->subtask = 'https_data';
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
  $display->title = 'Government-Wide  HTTPS Report';
  $display->uuid = '6737efc9-61a2-4b80-afbb-69ff4bb3396c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_https_data__panel_context_5afdcb0c-7706-4b9f-89a5-8a94ab90b31c';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-eb0a1688-38c6-42e1-84f3-f3cb1584dc1e';
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
    'display' => 'page_2',
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
  $pane->uuid = 'eb0a1688-38c6-42e1-84f3-f3cb1584dc1e';
  $display->content['new-eb0a1688-38c6-42e1-84f3-f3cb1584dc1e'] = $pane;
  $display->panels['bottom_above'][0] = 'new-eb0a1688-38c6-42e1-84f3-f3cb1584dc1e';
  $pane = new stdClass();
  $pane->pid = 'new-eff560b8-eee3-4871-bb11-7a870afa32c0';
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
    'display' => 'block_5',
    'override_title' => 1,
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
  $pane->uuid = 'eff560b8-eee3-4871-bb11-7a870afa32c0';
  $display->content['new-eff560b8-eee3-4871-bb11-7a870afa32c0'] = $pane;
  $display->panels['middle'][0] = 'new-eff560b8-eee3-4871-bb11-7a870afa32c0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['https_data'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ipv6_data';
  $page->task = 'page';
  $page->admin_title = 'ipv6_data';
  $page->admin_description = '';
  $page->path = 'agency/all/ipv6_data';
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
  $handler->name = 'page_ipv6_data__panel_context_8faea861-e965-4871-98fe-3fa44bcd12fe';
  $handler->task = 'page';
  $handler->subtask = 'ipv6_data';
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
  $display->title = 'Government-Wide  IPv6 Report';
  $display->uuid = '6737efc9-61a2-4b80-afbb-69ff4bb3396c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_ipv6_data__panel_context_8faea861-e965-4871-98fe-3fa44bcd12fe';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-79e32376-e2b7-4ac1-a030-bf7602206b5b';
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
    'display' => 'page_7',
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
  $pane->uuid = '79e32376-e2b7-4ac1-a030-bf7602206b5b';
  $display->content['new-79e32376-e2b7-4ac1-a030-bf7602206b5b'] = $pane;
  $display->panels['bottom_above'][0] = 'new-79e32376-e2b7-4ac1-a030-bf7602206b5b';
  $pane = new stdClass();
  $pane->pid = 'new-8d909648-fa8b-47d8-81a4-790edd838547';
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
    'display' => 'block_11',
    'override_title' => 1,
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
  $pane->uuid = '8d909648-fa8b-47d8-81a4-790edd838547';
  $display->content['new-8d909648-fa8b-47d8-81a4-790edd838547'] = $pane;
  $display->panels['middle'][0] = 'new-8d909648-fa8b-47d8-81a4-790edd838547';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ipv6_data'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'mobile_data';
  $page->task = 'page';
  $page->admin_title = 'mobile_data';
  $page->admin_description = '';
  $page->path = 'agency/all/mobile_data';
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

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'my_agency';
  $page->task = 'page';
  $page->admin_title = 'My Agency';
  $page->admin_description = 'My Agency';
  $page->path = 'myagency';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 12,
            1 => 14,
            2 => 15,
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
  $handler->name = 'page_my_agency__panel_context_2ad58b04-3bf9-4758-b7ed-7372427e8af6';
  $handler->task = 'page';
  $handler->subtask = 'my_agency';
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
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'My Agency';
  $display->uuid = '81094fde-63a4-4080-a08d-3c62106a6b53';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_my_agency__panel_context_2ad58b04-3bf9-4758-b7ed-7372427e8af6';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-326c88ae-d7b9-468a-9ff3-ae79c25d5ae2';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'agency_page';
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
    'display' => 'block_2',
    'override_title' => 1,
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
  $pane->uuid = '326c88ae-d7b9-468a-9ff3-ae79c25d5ae2';
  $display->content['new-326c88ae-d7b9-468a-9ff3-ae79c25d5ae2'] = $pane;
  $display->panels['middle'][0] = 'new-326c88ae-d7b9-468a-9ff3-ae79c25d5ae2';
  $pane = new stdClass();
  $pane->pid = 'new-f66bc168-0855-45ed-a36c-555f5a879870';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'agency_page';
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
    'override_title_text' => 'Average Score',
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
  $pane->uuid = 'f66bc168-0855-45ed-a36c-555f5a879870';
  $display->content['new-f66bc168-0855-45ed-a36c-555f5a879870'] = $pane;
  $display->panels['middle'][1] = 'new-f66bc168-0855-45ed-a36c-555f5a879870';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-f66bc168-0855-45ed-a36c-555f5a879870';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['my_agency'] = $page;

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

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'reports';
  $page->task = 'page';
  $page->admin_title = 'Reports';
  $page->admin_description = '';
  $page->path = 'reports';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
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
  $handler->name = 'page_reports__panel';
  $handler->task = 'page';
  $handler->subtask = 'reports';
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
      'header' => array(
        'corner_location' => 'pane',
      ),
      'column2' => array(
        'corner_location' => 'pane',
      ),
      'column3' => array(
        'corner_location' => 'pane',
      ),
      'secondarycolumn1' => array(
        'corner_location' => 'pane',
      ),
      'secondarycolumn2' => array(
        'corner_location' => 'pane',
      ),
      'secondarycolumn3' => array(
        'corner_location' => 'pane',
      ),
      'footer' => NULL,
      'column1' => array(
        'corner_location' => 'pane',
      ),
    ),
    'column1' => array(
      'style' => 'rounded_corners',
    ),
    'column2' => array(
      'style' => 'rounded_corners',
    ),
    'header' => array(
      'style' => 'rounded_corners',
    ),
    'column3' => array(
      'style' => 'rounded_corners',
    ),
    'secondarycolumn1' => array(
      'style' => 'rounded_corners',
    ),
    'secondarycolumn2' => array(
      'style' => 'rounded_corners',
    ),
    'secondarycolumn3' => array(
      'style' => 'rounded_corners',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '30312948-b68f-4a5e-b1ff-e957023fd1cb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_reports__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c39ecb8b-834c-4e4e-98dc-76d847dad6f2';
  $pane->panel = 'column1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Sites using CDN ',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3><a href="/search/site?f[0]=sm_field_cdn_provider_name%3Aakamai&amp;f[1]=sm_field_cdn_provider_name%3Acloudfront">Sites Using CDN</a></h3>

<p>View all sites using Content Delivery Networks (CDN) such as Akamai or CloudFront.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c39ecb8b-834c-4e4e-98dc-76d847dad6f2';
  $display->content['new-c39ecb8b-834c-4e4e-98dc-76d847dad6f2'] = $pane;
  $display->panels['column1'][0] = 'new-c39ecb8b-834c-4e4e-98dc-76d847dad6f2';
  $pane = new stdClass();
  $pane->pid = 'new-f7dd260a-c321-4631-b298-3dda41bc2283';
  $pane->panel = 'column1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Robots.txt non usage',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3><a href="/search/site?f[0]=bm_field_uses_robots_txt%3Afalse">Sites Not Using Robots.txt </a></h3>

<p>Determine which sites do not use robots.txt.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f7dd260a-c321-4631-b298-3dda41bc2283';
  $display->content['new-f7dd260a-c321-4631-b298-3dda41bc2283'] = $pane;
  $display->panels['column1'][1] = 'new-f7dd260a-c321-4631-b298-3dda41bc2283';
  $pane = new stdClass();
  $pane->pid = 'new-5f0f7954-a838-4673-97bf-f4b61bbeaa73';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Mobile Compliant Sites',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3><a href="/search/site?f[0]=im_field_website_tags%3A28">Mobile Compliant Sites</a></h3>

<p>View all sites that pass the mobile compatibility test.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5f0f7954-a838-4673-97bf-f4b61bbeaa73';
  $display->content['new-5f0f7954-a838-4673-97bf-f4b61bbeaa73'] = $pane;
  $display->panels['column2'][0] = 'new-5f0f7954-a838-4673-97bf-f4b61bbeaa73';
  $pane = new stdClass();
  $pane->pid = 'new-01caab07-d110-47d3-ba5a-94374ce25afd';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Insecure HTTPS Protocols',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3><a href="/search/site?f[0]=im_field_website_tags%3A25&amp;f[1]=im_field_website_tags%3A21&amp;f[2]=im_field_website_tags%3A24">Sites with Insecure HTTPS protocols</a></h3>

<p>View sites with insecure HTTPS protocols, such as, SSLv2,SSLv3 and TLSV1.0</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '01caab07-d110-47d3-ba5a-94374ce25afd';
  $display->content['new-01caab07-d110-47d3-ba5a-94374ce25afd'] = $pane;
  $display->panels['column2'][1] = 'new-01caab07-d110-47d3-ba5a-94374ce25afd';
  $pane = new stdClass();
  $pane->pid = 'new-a909d883-0ac2-48cb-a6e6-e17c394b36c6';
  $pane->panel = 'column3';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Hosted on GovCloud',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3><a href="/search/site?f[0]=sm_field_cloud_provider%3AAmazon%20GovCloud">Sites Hosted on GovCloud</a></h3>

<p>View all sites hosted on GovCloud.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a909d883-0ac2-48cb-a6e6-e17c394b36c6';
  $display->content['new-a909d883-0ac2-48cb-a6e6-e17c394b36c6'] = $pane;
  $display->panels['column3'][0] = 'new-a909d883-0ac2-48cb-a6e6-e17c394b36c6';
  $pane = new stdClass();
  $pane->pid = 'new-b61e116a-7404-463e-a705-bfd472600509';
  $pane->panel = 'column3';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Sites using Cookies',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3><a href="/search/site?f[0]=bm_field_uses_cookies%3Atrue">Sites Using Cookies</a></h3>

<p>Determine which sites use cookies.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b61e116a-7404-463e-a705-bfd472600509';
  $display->content['new-b61e116a-7404-463e-a705-bfd472600509'] = $pane;
  $display->panels['column3'][1] = 'new-b61e116a-7404-463e-a705-bfd472600509';
  $pane = new stdClass();
  $pane->pid = 'new-713856b6-90f6-49ab-a4bd-9875ae378999';
  $pane->panel = 'secondarycolumn1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Sites having Redirect',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3><a href="/search/site?f[0]=sm_field_redirect%3AYes">Website Redirects</a></h3>

<p>View website redirects.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '713856b6-90f6-49ab-a4bd-9875ae378999';
  $display->content['new-713856b6-90f6-49ab-a4bd-9875ae378999'] = $pane;
  $display->panels['secondarycolumn1'][0] = 'new-713856b6-90f6-49ab-a4bd-9875ae378999';
  $pane = new stdClass();
  $pane->pid = 'new-96a1b6e2-d708-4aed-b8a7-a1b2004ffb3c';
  $pane->panel = 'secondarycolumn1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Sites with GeoTrust certs',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3><a href="/search/site?f[0]=sm_field_certificate_provider%3AGeoTrust%20SSL%20CA-%20G3&amp;f[1]=sm_field_certificate_provider%3AGeoTrust%20DV%20SSL%20CA-%20G3&amp;f[2]=sm_field_certificate_provider%3AGeoTrust%20EV%20SSL%20CA-%20G4">Sites Using GeoTrust Certificates</a></h3>

<p>View all sites using GeoTrust Certificates.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '96a1b6e2-d708-4aed-b8a7-a1b2004ffb3c';
  $display->content['new-96a1b6e2-d708-4aed-b8a7-a1b2004ffb3c'] = $pane;
  $display->panels['secondarycolumn1'][1] = 'new-96a1b6e2-d708-4aed-b8a7-a1b2004ffb3c';
  $pane = new stdClass();
  $pane->pid = 'new-f40aef40-b213-454b-b0e3-ae4d98afe8d4';
  $pane->panel = 'secondarycolumn2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Vulnerable Sites',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3><a href="/search/site?f[0]=im_field_website_tags%3A26">Sites Vulnerable to OpenSSL Attacks</a></h3>

<p>View all sites vulnerable to OpenSSL CCS injection, OpenSSL Heartbleed, or OpenSSL Downgrade (man in the middle) attacks.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f40aef40-b213-454b-b0e3-ae4d98afe8d4';
  $display->content['new-f40aef40-b213-454b-b0e3-ae4d98afe8d4'] = $pane;
  $display->panels['secondarycolumn2'][0] = 'new-f40aef40-b213-454b-b0e3-ae4d98afe8d4';
  $pane = new stdClass();
  $pane->pid = 'new-579ca497-b200-411e-b3cc-6975de6948a2';
  $pane->panel = 'secondarycolumn2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'GSA sites with Akamai',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3><a href="/search/site?f[0]=im_field_web_agency_id%3A1&amp;f[1]=sm_field_cdn_provider_name%3Aakamai">GSA Websites using Akamai CDN</a></h3>

<p>View all sites using Akamai CDN within GSA.</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '579ca497-b200-411e-b3cc-6975de6948a2';
  $display->content['new-579ca497-b200-411e-b3cc-6975de6948a2'] = $pane;
  $display->panels['secondarycolumn2'][1] = 'new-579ca497-b200-411e-b3cc-6975de6948a2';
  $pane = new stdClass();
  $pane->pid = 'new-52e81b9d-f7fb-45f0-a071-cefaa1c45e77';
  $pane->panel = 'secondarycolumn3';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '',
    'format' => 'filtered_html',
    'substitute' => TRUE,
    'name' => 'reports_block_1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'report1',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '52e81b9d-f7fb-45f0-a071-cefaa1c45e77';
  $display->content['new-52e81b9d-f7fb-45f0-a071-cefaa1c45e77'] = $pane;
  $display->panels['secondarycolumn3'][0] = 'new-52e81b9d-f7fb-45f0-a071-cefaa1c45e77';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-52e81b9d-f7fb-45f0-a071-cefaa1c45e77';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['reports'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'sitespeed_data';
  $page->task = 'page';
  $page->admin_title = 'sitespeed_data';
  $page->admin_description = '';
  $page->path = 'agency/all/sitespeed_data';
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
  $handler->name = 'page_sitespeed_data__panel_context_00d2870b-32b4-460e-bf96-8121a78b7e4c';
  $handler->task = 'page';
  $handler->subtask = 'sitespeed_data';
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
  $display->title = 'Government-Wide  Site Speed Score';
  $display->uuid = '6737efc9-61a2-4b80-afbb-69ff4bb3396c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_sitespeed_data__panel_context_00d2870b-32b4-460e-bf96-8121a78b7e4c';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-597a8067-d317-4301-83a4-406157a0299a';
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
    'display' => 'page_9',
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
  $pane->uuid = '597a8067-d317-4301-83a4-406157a0299a';
  $display->content['new-597a8067-d317-4301-83a4-406157a0299a'] = $pane;
  $display->panels['bottom_above'][0] = 'new-597a8067-d317-4301-83a4-406157a0299a';
  $pane = new stdClass();
  $pane->pid = 'new-7ee866a4-5c01-41fb-b19c-bd431c5cd99e';
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
    'display' => 'block_14',
    'override_title' => 1,
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
  $pane->uuid = '7ee866a4-5c01-41fb-b19c-bd431c5cd99e';
  $display->content['new-7ee866a4-5c01-41fb-b19c-bd431c5cd99e'] = $pane;
  $display->panels['middle'][0] = 'new-7ee866a4-5c01-41fb-b19c-bd431c5cd99e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['sitespeed_data'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ssl_data';
  $page->task = 'page';
  $page->admin_title = 'ssl_data';
  $page->admin_description = '';
  $page->path = 'agency/all/ssl_data';
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
  $handler->name = 'page_ssl_data__panel';
  $handler->task = 'page';
  $handler->subtask = 'ssl_data';
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
    'name' => 'panel',
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
  $display->title = 'All Agency SSL Compliance';
  $display->uuid = '6737efc9-61a2-4b80-afbb-69ff4bb3396c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_ssl_data__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-04a91527-c436-4773-a67b-5d2770b6b5c7';
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
    'display' => 'page_1',
    'override_title' => 1,
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
  $pane->uuid = '04a91527-c436-4773-a67b-5d2770b6b5c7';
  $display->content['new-04a91527-c436-4773-a67b-5d2770b6b5c7'] = $pane;
  $display->panels['bottom_above'][0] = 'new-04a91527-c436-4773-a67b-5d2770b6b5c7';
  $pane = new stdClass();
  $pane->pid = 'new-8f932fa6-e818-45e9-92b0-0fc3a5d71cd9';
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
    'display' => 'block_4',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'clearfix',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8f932fa6-e818-45e9-92b0-0fc3a5d71cd9';
  $display->content['new-8f932fa6-e818-45e9-92b0-0fc3a5d71cd9'] = $pane;
  $display->panels['middle'][0] = 'new-8f932fa6-e818-45e9-92b0-0fc3a5d71cd9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8f932fa6-e818-45e9-92b0-0fc3a5d71cd9';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ssl_data'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'top_technology_stack_usage';
  $page->task = 'page';
  $page->admin_title = 'Top Technology Stack Usage';
  $page->admin_description = 'Top Technology Stack Usage';
  $page->path = 'top_technology_usage';
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
  $handler->name = 'page_top_technology_stack_usage__panel_context_a61df791-0623-4751-8dea-73394f608859';
  $handler->task = 'page';
  $handler->subtask = 'top_technology_stack_usage';
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
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'four_three_adaptive';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      11 => NULL,
      12 => NULL,
      13 => NULL,
      14 => NULL,
      21 => NULL,
      22 => NULL,
      23 => NULL,
      24 => NULL,
      31 => NULL,
      32 => NULL,
      33 => NULL,
      34 => NULL,
      41 => NULL,
      42 => NULL,
      43 => NULL,
      44 => NULL,
      51 => NULL,
      52 => NULL,
      53 => NULL,
      61 => NULL,
      62 => NULL,
      63 => NULL,
      71 => NULL,
      72 => NULL,
      73 => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Top Technology Stack Usage';
  $display->uuid = '06277e97-d819-41bc-bf40-59d8126fe179';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_top_technology_stack_usage__panel_context_a61df791-0623-4751-8dea-73394f608859';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-36725f7a-7fd8-4645-8db7-6194372aaffe';
  $pane->panel = '11';
  $pane->type = 'views';
  $pane->subtype = 'web_servers';
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
    'display' => 'block',
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
  $pane->uuid = '36725f7a-7fd8-4645-8db7-6194372aaffe';
  $display->content['new-36725f7a-7fd8-4645-8db7-6194372aaffe'] = $pane;
  $display->panels['11'][0] = 'new-36725f7a-7fd8-4645-8db7-6194372aaffe';
  $pane = new stdClass();
  $pane->pid = 'new-096a6e80-777a-4787-b841-a1f77977915b';
  $pane->panel = '12';
  $pane->type = 'views';
  $pane->subtype = 'web_servers';
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
    'display' => 'block_2',
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
  $pane->uuid = '096a6e80-777a-4787-b841-a1f77977915b';
  $display->content['new-096a6e80-777a-4787-b841-a1f77977915b'] = $pane;
  $display->panels['12'][0] = 'new-096a6e80-777a-4787-b841-a1f77977915b';
  $pane = new stdClass();
  $pane->pid = 'new-32c06de9-0eb3-4da4-8512-95b92fd1e376';
  $pane->panel = '13';
  $pane->type = 'views';
  $pane->subtype = 'web_servers';
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
    'display' => 'block_3',
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
  $pane->uuid = '32c06de9-0eb3-4da4-8512-95b92fd1e376';
  $display->content['new-32c06de9-0eb3-4da4-8512-95b92fd1e376'] = $pane;
  $display->panels['13'][0] = 'new-32c06de9-0eb3-4da4-8512-95b92fd1e376';
  $pane = new stdClass();
  $pane->pid = 'new-9e8a49d8-eb79-4d78-96c6-efd51d8830da';
  $pane->panel = '14';
  $pane->type = 'views';
  $pane->subtype = 'web_servers';
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
  $pane->uuid = '9e8a49d8-eb79-4d78-96c6-efd51d8830da';
  $display->content['new-9e8a49d8-eb79-4d78-96c6-efd51d8830da'] = $pane;
  $display->panels['14'][0] = 'new-9e8a49d8-eb79-4d78-96c6-efd51d8830da';
  $pane = new stdClass();
  $pane->pid = 'new-d04e48c1-a056-4adf-9053-e3a942580ff2';
  $pane->panel = '21';
  $pane->type = 'views';
  $pane->subtype = 'web_servers';
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
  $pane->uuid = 'd04e48c1-a056-4adf-9053-e3a942580ff2';
  $display->content['new-d04e48c1-a056-4adf-9053-e3a942580ff2'] = $pane;
  $display->panels['21'][0] = 'new-d04e48c1-a056-4adf-9053-e3a942580ff2';
  $pane = new stdClass();
  $pane->pid = 'new-20dd129e-ccd7-46dd-98af-0f0509d7a9cd';
  $pane->panel = '22';
  $pane->type = 'views';
  $pane->subtype = 'web_servers';
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
  $pane->uuid = '20dd129e-ccd7-46dd-98af-0f0509d7a9cd';
  $display->content['new-20dd129e-ccd7-46dd-98af-0f0509d7a9cd'] = $pane;
  $display->panels['22'][0] = 'new-20dd129e-ccd7-46dd-98af-0f0509d7a9cd';
  $pane = new stdClass();
  $pane->pid = 'new-a780baa1-d2e0-4e33-bdea-ed1208c27fc1';
  $pane->panel = '23';
  $pane->type = 'views';
  $pane->subtype = 'web_servers';
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
  $pane->uuid = 'a780baa1-d2e0-4e33-bdea-ed1208c27fc1';
  $display->content['new-a780baa1-d2e0-4e33-bdea-ed1208c27fc1'] = $pane;
  $display->panels['23'][0] = 'new-a780baa1-d2e0-4e33-bdea-ed1208c27fc1';
  $pane = new stdClass();
  $pane->pid = 'new-f57437fa-53f9-4e08-9882-4fc35dd5e945';
  $pane->panel = '24';
  $pane->type = 'views';
  $pane->subtype = 'web_servers';
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
  $pane->uuid = 'f57437fa-53f9-4e08-9882-4fc35dd5e945';
  $display->content['new-f57437fa-53f9-4e08-9882-4fc35dd5e945'] = $pane;
  $display->panels['24'][0] = 'new-f57437fa-53f9-4e08-9882-4fc35dd5e945';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-36725f7a-7fd8-4645-8db7-6194372aaffe';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['top_technology_stack_usage'] = $page;

  return $pages;

}
