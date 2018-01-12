<?php
/**
 * @file
 * settings.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function settings_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'marketplace';
  $content->admin_title = 'marketplace';
  $content->admin_description = '';
  $content->category = '';
  $content->settings = array(
    'admin_title' => 'marketplace',
    'title' => 'Marketplace',
    'title_heading' => 'h2',
    'body' => '<ul>
	<li>Domain Renewal</li>
	<li>Certificate Renewal</li>
	<li>SITES Platform</li>
	<li>Pulse Dashboard</li>
	<li>Integrate Search.digitalGov in your site</li>
	<li>Domain Management Lifecycle</li>
	<li>DAP Dashboard</li>
</ul>
',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['marketplace'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'reports_block_1';
  $content->admin_title = 'reports_block_1';
  $content->admin_description = '';
  $content->category = '';
  $content->settings = array(
    'admin_title' => 'reports_block_1',
    'title' => 'Sites Missing HTTPS Compliance',
    'title_heading' => 'h2',
    'body' => '<a href=\'https://ftp.drupal.org/files/projects/wysiwyg-7.x-2.4.tar.gz\'>Click here</a> to view all sites missing HTTPS compliance.',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['reports_block_1'] = $content;

  return $export;
}
