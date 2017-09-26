<?php
/**
 * @file
 * settings.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function settings_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'agency_logo';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'agency_logo';
  $fe_block_boxes->body = '<h1 class="page-header">Overall Compliance Report</h1>
<div class="white-back" style="width:390px;margin:0 auto;text-align:center; margin-bottom:20px;"><h3>General Services Administration </h3>
<a href="https://gsa.gov" style ="display:inline-block"><img class="footer_logo" src="/sites/all/themes/dotgov/images/gsa-logo.png" alt="GSA.gov" title="GSA.gov" scale="0">
</div>';

  $export['agency_logo'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'footer';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer';
  $fe_block_boxes->body = '  <p><a href="https://gsa.gov"><img class="footer_logo" src="/sites/all/themes/dotgov/images/gsa-logo.png" alt="GSA.gov" title="GSA.gov" scale="0" /><span>Powered by<br/>GSA</span></a> </p>
';

  $export['footer'] = $fe_block_boxes;

  return $export;
}
