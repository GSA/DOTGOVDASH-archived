<?php
/**
 * @file
 * accessibility.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function accessibility_default_ctools_custom_content() {
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
    'title' => '.Gov Marketplace',
    'title_heading' => 'h2',
    'body' => '<ul>
	<li><a href="https://www.dotgov.gov/"><span style="color:#FFFFFF">Domain Renewal</span></a></li>
	<li><a href="https://https.app.cloud.gov/certificates/"><span style="color:#FFFFFF">Certificate Renewal</span></a></li>
	<li><a href="http://pulse.cio.gov"><span style="color:#FFFFFF">Pulse Dashboard</span></a></li>
	<li><a href="https://www.digitalgov.gov/services/dap/"><span style="color:#FFFFFF">DAP Dashboard</span></a></li>
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
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3><a href="/search/site?f[0]=sm_field_https_status%3ANo">HTTPS Compliant Sites</a></h3>

<p>View all sites missing HTTPS compliance.</p>
',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $export['reports_block_1'] = $content;

  return $export;
}
