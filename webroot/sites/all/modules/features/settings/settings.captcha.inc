<?php
/**
 * @file
 * settings.captcha.inc
 */

/**
 * Implements hook_captcha_default_points().
 */
function settings_captcha_default_points() {
  $export = array();

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_508_scan_information_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_508_scan_information_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_agency_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_agency_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_article_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_article_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_broken_link_scan_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_broken_link_scan_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_cookie_law_scan_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_cookie_law_scan_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_dnssec_ipv6_information_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_dnssec_ipv6_information_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_domain_scan_information_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_domain_scan_information_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_https_dap_scan_information_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_https_dap_scan_information_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_mobile_scan_information_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_mobile_scan_information_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_page_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_page_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_panel_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_panel_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_scans_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_scans_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_seo_scan_information_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_seo_scan_information_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_site_speed_scan_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_site_speed_scan_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_website_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_website_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'comment_node_website_scan_info_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['comment_node_website_scan_info_form'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_login';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['user_login'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_login_block';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['user_login_block'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_pass';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['user_pass'] = $captcha;

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_register_form';
  $captcha->module = 'image_captcha';
  $captcha->captcha_type = 'Image';
  $export['user_register_form'] = $captcha;

  return $export;
}
