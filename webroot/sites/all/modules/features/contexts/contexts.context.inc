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
  $context->name = 'all_agency_dashboard_report';
  $context->description = 'all ageny dashboard report';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'agency/all/reports' => 'agency/all/reports',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-all_agency_data-block_4' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_4',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-all_agency_data-block_5' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_5',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-all_agency_data-block_6' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_6',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-all_agency_data-block_7' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_7',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-all_agency_data-block_8' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_8',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-all_agency_data-block_9' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_9',
          'region' => 'content',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('all ageny dashboard report');
  $export['all_agency_dashboard_report'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'charts';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'charts' => 'charts',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-all_agency_data-block_3' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_3',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-all_agency_data-block_4' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_4',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['charts'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dap_overall';
  $context->description = 'DAP Overall';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'agency/all/data/dap' => 'agency/all/data/dap',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-all_agency_data-block_6' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_6',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('DAP Overall');
  $export['dap_overall'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'https_overall';
  $context->description = 'HTTPS overall';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'agency/all/data/https' => 'agency/all/data/https',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-all_agency_data-block_5' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_5',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('HTTPS overall');
  $export['https_overall'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mobile_overall';
  $context->description = 'Mobile overall';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'agency/all/data/mobile' => 'agency/all/data/mobile',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-all_agency_data-block_7' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_7',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-all_agency_data-block_8' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_8',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-all_agency_data-block_9' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_9',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Mobile overall');
  $export['mobile_overall'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ssl_overall';
  $context->description = 'SSL Overall';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'agency/all/data/ssl' => 'agency/all/data/ssl',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-all_agency_data-block_4' => array(
          'module' => 'views',
          'delta' => 'all_agency_data-block_4',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('SSL Overall');
  $export['ssl_overall'] = $context;

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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'website_search';
  $context->description = 'website_search';
  $context->tag = 'website_search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/website_search*' => 'search/website_search*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-bk0405OO60p6nQ17XVxOrSdKuDJaq0y5' => array(
          'module' => 'facetapi',
          'delta' => 'bk0405OO60p6nQ17XVxOrSdKuDJaq0y5',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-CLDYLyvTfoZKlHmTtdgIIQ1TlHczuoHL' => array(
          'module' => 'facetapi',
          'delta' => 'CLDYLyvTfoZKlHmTtdgIIQ1TlHczuoHL',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('website_search');
  $export['website_search'] = $context;

  return $export;
}
