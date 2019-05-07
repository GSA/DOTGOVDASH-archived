<?php
/**
 * @file
 * accessibility.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function accessibility_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'dotgov';
  $item->label = 'dotgov';
  $item->settings = array(
    'items' => array(),
    'advanced' => array(
      'empty_searches' => 0,
    ),
  );
  $export['dotgov'] = $item;

  return $export;
}
