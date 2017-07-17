<?php
/**
 * @file
 * theme_changes.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function theme_changes_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'footer';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer';
  $fe_block_boxes->body = '  <p><a href="https://gsa.gov" style="margin-right:15px"><img src="/sites/all/themes/dotgov/images/gsa-logo.png" alt="GSA.gov" title="GSA.gov" scale="0" /></a> </p>
';

  $export['footer'] = $fe_block_boxes;

  return $export;
}
