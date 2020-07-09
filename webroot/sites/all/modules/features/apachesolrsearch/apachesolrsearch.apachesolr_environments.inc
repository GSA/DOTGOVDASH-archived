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
  $environment->url = 'http://159.142.67.12:8983/solr/drupal';
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
      1 => 'accessibility_agency_scan_inform',
      2 => 'agency',
      3 => 'article',
      4 => 'broken_link_scan',
      5 => 'cookie_law_scan',
      6 => 'dnssec_ipv6_information',
      7 => 'domain_scan_information',
      8 => 'https_dap_scan_information',
      9 => 'mobile_scan_information',
      10 => 'page',
      11 => 'scans',
      12 => 'seo_scan_information',
      13 => 'site_speed_scan',
      14 => 'uswds_scan',
      15 => 'website',
      16 => 'website_scan_info',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
