<?php

/**
 * @file
 * uswds_settings.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function uswds_settings_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'uswds_search_facets';
  $mini->category = '';
  $mini->admin_title = 'USWDS Search Facets';
  $mini->admin_description = 'USWDS Search Facets';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->title = 'USWDS';
  $display->uuid = '0370d6d2-442e-42b1-94c7-a003c11b3218';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'uswds_search_facets';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9c70ca70-972e-45f0-b428-ab6d112ad1f3';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-Jm0nudvscZjwxIsbLNz9aCOpbOyJsBzQ';
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
  $pane->uuid = '9c70ca70-972e-45f0-b428-ab6d112ad1f3';
  $display->content['new-9c70ca70-972e-45f0-b428-ab6d112ad1f3'] = $pane;
  $display->panels['middle'][0] = 'new-9c70ca70-972e-45f0-b428-ab6d112ad1f3';
  $pane = new stdClass();
  $pane->pid = 'new-b4e4dd12-ad03-428c-936d-25144b847c8a';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-nPJlJIkvEz5FzIq40hrJxUXWiG0CjfIu';
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
  $pane->uuid = 'b4e4dd12-ad03-428c-936d-25144b847c8a';
  $display->content['new-b4e4dd12-ad03-428c-936d-25144b847c8a'] = $pane;
  $display->panels['middle'][1] = 'new-b4e4dd12-ad03-428c-936d-25144b847c8a';
  $pane = new stdClass();
  $pane->pid = 'new-e6a1bfed-e805-4596-8fc6-3b5265e008ef';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-7aDOrQM1QjK49aq3ikKS9qRVtnn4uZM5';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e6a1bfed-e805-4596-8fc6-3b5265e008ef';
  $display->content['new-e6a1bfed-e805-4596-8fc6-3b5265e008ef'] = $pane;
  $display->panels['middle'][2] = 'new-e6a1bfed-e805-4596-8fc6-3b5265e008ef';
  $pane = new stdClass();
  $pane->pid = 'new-a32791ca-36dc-495e-a325-c9e073d6d4d2';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-1zkrU00wqmNjE1lxL80GzrcV0LwAFYK9';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'a32791ca-36dc-495e-a325-c9e073d6d4d2';
  $display->content['new-a32791ca-36dc-495e-a325-c9e073d6d4d2'] = $pane;
  $display->panels['middle'][3] = 'new-a32791ca-36dc-495e-a325-c9e073d6d4d2';
  $pane = new stdClass();
  $pane->pid = 'new-eb84b8d9-2d25-49f9-84df-516b445ec136';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-ZLA8QXnOOLyjJ5lvVhvF1hXp07X6tFvk';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'eb84b8d9-2d25-49f9-84df-516b445ec136';
  $display->content['new-eb84b8d9-2d25-49f9-84df-516b445ec136'] = $pane;
  $display->panels['middle'][4] = 'new-eb84b8d9-2d25-49f9-84df-516b445ec136';
  $pane = new stdClass();
  $pane->pid = 'new-4347c9e7-7b01-4816-aed6-7e9044864056';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-jIfHrhSTOdJRs7d2VxTwOty1NgsO4w21';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '4347c9e7-7b01-4816-aed6-7e9044864056';
  $display->content['new-4347c9e7-7b01-4816-aed6-7e9044864056'] = $pane;
  $display->panels['middle'][5] = 'new-4347c9e7-7b01-4816-aed6-7e9044864056';
  $pane = new stdClass();
  $pane->pid = 'new-5d970d84-6fcf-46fd-9aed-0e52f05bd02f';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-TeQmklSiwcz465RIzGdv45roPNuE0ean';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '5d970d84-6fcf-46fd-9aed-0e52f05bd02f';
  $display->content['new-5d970d84-6fcf-46fd-9aed-0e52f05bd02f'] = $pane;
  $display->panels['middle'][6] = 'new-5d970d84-6fcf-46fd-9aed-0e52f05bd02f';
  $pane = new stdClass();
  $pane->pid = 'new-9d43b550-ec87-462b-bcd2-ba24255b556f';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-1N1jjU1ibGMgfOWa4u8pOwTCpHRrop10';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '9d43b550-ec87-462b-bcd2-ba24255b556f';
  $display->content['new-9d43b550-ec87-462b-bcd2-ba24255b556f'] = $pane;
  $display->panels['middle'][7] = 'new-9d43b550-ec87-462b-bcd2-ba24255b556f';
  $pane = new stdClass();
  $pane->pid = 'new-2902d010-84b2-45ad-9146-c4b04911f12d';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-cHYMgZkhnabLSJ08pkDyIvYRpSoHSipJ';
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '2902d010-84b2-45ad-9146-c4b04911f12d';
  $display->content['new-2902d010-84b2-45ad-9146-c4b04911f12d'] = $pane;
  $display->panels['middle'][8] = 'new-2902d010-84b2-45ad-9146-c4b04911f12d';
  $pane = new stdClass();
  $pane->pid = 'new-1c0e0d65-6ce1-4e34-b989-c431d9d20fbc';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-1szZl7LRpkLoHqfVNJ11khU780tV7IZf';
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '1c0e0d65-6ce1-4e34-b989-c431d9d20fbc';
  $display->content['new-1c0e0d65-6ce1-4e34-b989-c431d9d20fbc'] = $pane;
  $display->panels['middle'][9] = 'new-1c0e0d65-6ce1-4e34-b989-c431d9d20fbc';
  $pane = new stdClass();
  $pane->pid = 'new-afe735fc-e720-4e75-aa72-fd3cd0de59fe';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-zbAsYHMvXMtWZgnz2hSSJecFz0Kgrd3M';
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
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = 'afe735fc-e720-4e75-aa72-fd3cd0de59fe';
  $display->content['new-afe735fc-e720-4e75-aa72-fd3cd0de59fe'] = $pane;
  $display->panels['middle'][10] = 'new-afe735fc-e720-4e75-aa72-fd3cd0de59fe';
  $pane = new stdClass();
  $pane->pid = 'new-5155ee3a-da49-4275-b146-3672a75d20d5';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-pMhkC11V0SxJzglcNo7wjkR6AFToA31D';
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
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '5155ee3a-da49-4275-b146-3672a75d20d5';
  $display->content['new-5155ee3a-da49-4275-b146-3672a75d20d5'] = $pane;
  $display->panels['middle'][11] = 'new-5155ee3a-da49-4275-b146-3672a75d20d5';
  $pane = new stdClass();
  $pane->pid = 'new-89e510e8-b2c3-46ce-84f8-3d49bf46c951';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-wt432Z7yoz0p4fEJ5uUjMonW07Ldt3TV';
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
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = '89e510e8-b2c3-46ce-84f8-3d49bf46c951';
  $display->content['new-89e510e8-b2c3-46ce-84f8-3d49bf46c951'] = $pane;
  $display->panels['middle'][12] = 'new-89e510e8-b2c3-46ce-84f8-3d49bf46c951';
  $pane = new stdClass();
  $pane->pid = 'new-1ab2398b-7af4-44c3-b59b-945fd995e874';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-380NqOb0VbbHWCubpIM1QlJyVb5JRI6z';
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
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = '1ab2398b-7af4-44c3-b59b-945fd995e874';
  $display->content['new-1ab2398b-7af4-44c3-b59b-945fd995e874'] = $pane;
  $display->panels['middle'][13] = 'new-1ab2398b-7af4-44c3-b59b-945fd995e874';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b4e4dd12-ad03-428c-936d-25144b847c8a';
  $mini->display = $display;
  $export['uswds_search_facets'] = $mini;

  return $export;
}
