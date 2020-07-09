<?php

/**
 * @file
 * apachesolrsearch.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function apachesolrsearch_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_page';
  $context->description = 'Search Page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/site' => 'search/site',
        'search/site/*' => 'search/site/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'favorites-0' => array(
          'module' => 'favorites',
          'delta' => '0',
          'region' => 'content',
          'weight' => '-10',
        ),
        'panels_mini-websites_and_scans' => array(
          'module' => 'panels_mini',
          'delta' => 'websites_and_scans',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'panels_mini-agencies' => array(
          'module' => 'panels_mini',
          'delta' => 'agencies',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'panels_mini-security' => array(
          'module' => 'panels_mini',
          'delta' => 'security',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'panels_mini-frameworks' => array(
          'module' => 'panels_mini',
          'delta' => 'frameworks',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'panels_mini-technologies' => array(
          'module' => 'panels_mini',
          'delta' => 'technologies',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'panels_mini-applications' => array(
          'module' => 'panels_mini',
          'delta' => 'applications',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'panels_mini-seo_social_media' => array(
          'module' => 'panels_mini',
          'delta' => 'seo_social_media',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'panels_mini-misc' => array(
          'module' => 'panels_mini',
          'delta' => 'misc',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'panels_mini-uswds_search_facets' => array(
          'module' => 'panels_mini',
          'delta' => 'uswds_search_facets',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search Page');
  $export['search_page'] = $context;

  return $export;
}
