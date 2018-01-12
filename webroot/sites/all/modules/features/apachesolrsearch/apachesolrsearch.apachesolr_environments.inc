<?php
/**
 * @file
 * apachesolrsearch.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function apachesolrsearch_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://localhost:8983/solr/drupal';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_access_always_add_grants' => 0,
    'apachesolr_direct_commit' => 0,
    'apachesolr_read_only' => '0',
    'apachesolr_search_facet_pages' => '',
    'apachesolr_soft_commit' => 0,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => '508_scan_information',
      1 => 'agency',
      2 => 'article',
      3 => 'broken_link_scan',
      4 => 'cookie_law_scan',
      5 => 'dnssec_ipv6_information',
      6 => 'domain_scan_information',
      7 => 'https_dap_scan_information',
      8 => 'mobile_scan_information',
      9 => 'page',
      10 => 'scans',
      11 => 'seo_scan_information',
      12 => 'site_speed_scan',
      13 => 'website',
      14 => 'website_scan_info',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
