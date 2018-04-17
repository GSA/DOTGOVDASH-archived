<?php
/**
 * @file
 * accessibility.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function accessibility_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'agency_wide_report';
  $context->description = 'agency_wide_report';
  $context->tag = 'agency_wide_report';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'overall/compliance' => 'overall/compliance',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-all_agency_data-block_16' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_16',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('agency_wide_report');
  $export['agency_wide_report'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'govwide-report';
  $context->description = 'govwide report';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'overall/gov-wide-compliance' => 'overall/gov-wide-compliance',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-all_agency_data-block_15' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_15',
          'region' => 'content',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('govwide report');
  $export['govwide-report'] = $context;

  return $export;
}
