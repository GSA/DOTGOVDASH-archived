<?php
/**
 * @file
 * contexts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'website_page';
  $context->description = 'website page';
  $context->tag = 'website';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'website_information/*/show' => 'website_information/*/show',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-website_information-block' => array(
          'module' => 'views',
          'delta' => 'website_information-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-website_information-block_1' => array(
          'module' => 'views',
          'delta' => 'website_information-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-website_information-block_2' => array(
          'module' => 'views',
          'delta' => 'website_information-block_2',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-website_information-block_3' => array(
          'module' => 'views',
          'delta' => 'website_information-block_3',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-website_information-block_4' => array(
          'module' => 'views',
          'delta' => 'website_information-block_4',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-website_information-block_5' => array(
          'module' => 'views',
          'delta' => 'website_information-block_5',
          'region' => 'content',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('website');
  t('website page');
  $export['website_page'] = $context;

  return $export;
}
