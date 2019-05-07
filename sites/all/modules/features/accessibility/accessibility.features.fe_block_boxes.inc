<?php
/**
 * @file
 * accessibility.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function accessibility_default_fe_block_boxes() {
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
  $fe_block_boxes->info = 'disclaimer text';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'disclaimer_text';
  $fe_block_boxes->body = '<table border="0" style="background-color:#ffffff">
	<tbody>
		<tr>
			<td>
			<p><strong>By logging in, you agree and adhere to the following terms of use:</strong></p>

			<p>This is an Alpha version of the .Gov Dashboard. The results shown are preliminary only and should not be used, shared or referenced in any official or internal reports.&nbsp;</p>

			<p>&nbsp;</p>
			</td>
		</tr>
	</tbody>
</table>
';

  $export['disclaimer_text'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'footer';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer';
  $fe_block_boxes->body = '  <p><a href="https://gsa.gov"><img class="footer_logo" src="/sites/all/themes/dotgov/images/gsa-logo.png" alt="GSA.gov" title="GSA.gov" scale="0" /><span>Powered by<br/>GSA</span></a> </p>
';

  $export['footer'] = $fe_block_boxes;

  return $export;
}
