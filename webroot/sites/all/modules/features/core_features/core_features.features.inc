<?php
/**
 * @file
 * core_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function core_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function core_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function core_features_node_info() {
  $items = array(
    '508_scan_information' => array(
      'name' => t('508 Scan Information'),
      'base' => 'node_content',
      'description' => t('508 Scan Information'),
      'has_title' => '1',
      'title_label' => t('508 Scan title'),
      'help' => '',
    ),
    'agency' => array(
      'name' => t('Agency'),
      'base' => 'node_content',
      'description' => t('All agency information'),
      'has_title' => '1',
      'title_label' => t('Agency Name'),
      'help' => '',
    ),
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'broken_link_scan' => array(
      'name' => t('Broken Link Scan'),
      'base' => 'node_content',
      'description' => t('Broken Link Scan Information'),
      'has_title' => '1',
      'title_label' => t('Broken Link Scan Title'),
      'help' => '',
    ),
    'cookie_law_scan' => array(
      'name' => t('Cookie Law Scan'),
      'base' => 'node_content',
      'description' => t('Cookie Law Scan Information'),
      'has_title' => '1',
      'title_label' => t('Cookielaw Title'),
      'help' => '',
    ),
    'dnssec_ipv6_information' => array(
      'name' => t('DNSSEC/IPV6 Information'),
      'base' => 'node_content',
      'description' => t('DNSSEC/IPV6 Information'),
      'has_title' => '1',
      'title_label' => t('DNSSEC/IPV6 Title'),
      'help' => '',
    ),
    'domain_scan_information' => array(
      'name' => t('Domain Scan Information'),
      'base' => 'node_content',
      'description' => t('Domain Scan Information'),
      'has_title' => '1',
      'title_label' => t('Domain scan Title'),
      'help' => '',
    ),
    'https_dap_scan_information' => array(
      'name' => t('HTTPS/DAP Scan Information'),
      'base' => 'node_content',
      'description' => t('HTTPS/DAP Scan Information'),
      'has_title' => '1',
      'title_label' => t('HTTPS/DAP Scan Title'),
      'help' => '',
    ),
    'mobile_scan_information' => array(
      'name' => t('Mobile Scan Information'),
      'base' => 'node_content',
      'description' => t('Mobile Scan Information'),
      'has_title' => '1',
      'title_label' => t('Mobile Scan Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'scans' => array(
      'name' => t('Scans'),
      'base' => 'node_content',
      'description' => t('Tracks all Scans run by the system'),
      'has_title' => '1',
      'title_label' => t('Scan Title'),
      'help' => '',
    ),
    'seo_scan_information' => array(
      'name' => t('SEO Scan Information'),
      'base' => 'node_content',
      'description' => t('SEO Scan Information'),
      'has_title' => '1',
      'title_label' => t('SEO Scan Title'),
      'help' => '',
    ),
    'site_speed_scan' => array(
      'name' => t('Site Speed Scan'),
      'base' => 'node_content',
      'description' => t('Site Speed Scan Information'),
      'has_title' => '1',
      'title_label' => t('Sitespeed Title'),
      'help' => '',
    ),
    'website' => array(
      'name' => t('Website'),
      'base' => 'node_content',
      'description' => t('All Websites Listing'),
      'has_title' => '1',
      'title_label' => t('Website Domain Name'),
      'help' => '',
    ),
    'website_scan_info' => array(
      'name' => t('Website Scan Info'),
      'base' => 'node_content',
      'description' => t('Website Scan Info'),
      'has_title' => '1',
      'title_label' => t('Scan Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_themekey_features_rule_chain().
 */
function core_features_themekey_features_rule_chain() {
if (!defined('THEMEKEY_PAGECACHE_UNSUPPORTED')) {
    define('THEMEKEY_PAGECACHE_UNSUPPORTED', 0);
    define('THEMEKEY_PAGECACHE_SUPPORTED', 1);
    define('THEMEKEY_PAGECACHE_TIMEBASED', 2);
  }
$rules = array(
  0 => array(
    'rule' => array(
      'property' => 'user:role',
      'operator' => '=',
      'value' => 'Super User',
      'theme' => 'dotgov',
      'enabled' => 1,
      'wildcards' => 'a:0:{}',
      'module' => 'core_features',
    ),
    'string' => '"user:role = Super User >>> dotgov"',
    'childs' => array(),
  ),
  1 => array(
    'rule' => array(
      'property' => 'user:role',
      'operator' => '=',
      'value' => 'Agency User',
      'theme' => 'dotgov',
      'enabled' => 1,
      'wildcards' => 'a:0:{}',
      'module' => 'core_features',
    ),
    'string' => '"user:role = Agency User >>> dotgov"',
    'childs' => array(),
  ),
  2 => array(
    'rule' => array(
      'property' => 'user:role',
      'operator' => '=',
      'value' => 'Agency Admin User',
      'theme' => 'dotgov',
      'enabled' => 1,
      'wildcards' => 'a:0:{}',
      'module' => 'core_features',
    ),
    'string' => '"user:role = Agency Admin User >>> dotgov"',
    'childs' => array(),
  ),
);

return $rules;
}
