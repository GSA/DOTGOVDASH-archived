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
        'facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu' => array(
          'module' => 'facetapi',
          'delta' => 'GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-CLDYLyvTfoZKlHmTtdgIIQ1TlHczuoHL' => array(
          'module' => 'facetapi',
          'delta' => 'CLDYLyvTfoZKlHmTtdgIIQ1TlHczuoHL',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-bk0405OO60p6nQ17XVxOrSdKuDJaq0y5' => array(
          'module' => 'facetapi',
          'delta' => 'bk0405OO60p6nQ17XVxOrSdKuDJaq0y5',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-UmFvLEl20H8GQHgQiwOt6N4wjBBWtMAm' => array(
          'module' => 'facetapi',
          'delta' => 'UmFvLEl20H8GQHgQiwOt6N4wjBBWtMAm',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-1DMFCEtrNh3vA7DxeyOmMYTqsOgdqlTi' => array(
          'module' => 'facetapi',
          'delta' => '1DMFCEtrNh3vA7DxeyOmMYTqsOgdqlTi',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-iTpca1eeOcSBAw307FoDam6od2ru3gOR' => array(
          'module' => 'facetapi',
          'delta' => 'iTpca1eeOcSBAw307FoDam6od2ru3gOR',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-BmDqb1FEjNIyOT8kT4uwdBo6KWdLvyeP' => array(
          'module' => 'facetapi',
          'delta' => 'BmDqb1FEjNIyOT8kT4uwdBo6KWdLvyeP',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-1WE2DybvBMgmBO9SI5FDAJde1QdgK8FD' => array(
          'module' => 'facetapi',
          'delta' => '1WE2DybvBMgmBO9SI5FDAJde1QdgK8FD',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-ZMl1bubISwSPpHEPFKSoUBi0nVZpVvDB' => array(
          'module' => 'facetapi',
          'delta' => 'ZMl1bubISwSPpHEPFKSoUBi0nVZpVvDB',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'facetapi-A9GklYgmXStkY97SEqG1Z0e89yrzYAKO' => array(
          'module' => 'facetapi',
          'delta' => 'A9GklYgmXStkY97SEqG1Z0e89yrzYAKO',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
        'facetapi-5wGfx9PaRUAlSkfsf3Rg47pXy1ljqOXi' => array(
          'module' => 'facetapi',
          'delta' => '5wGfx9PaRUAlSkfsf3Rg47pXy1ljqOXi',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-osRUpMUI017Nm06J22kxWEywmGCC0e5M' => array(
          'module' => 'facetapi',
          'delta' => 'osRUpMUI017Nm06J22kxWEywmGCC0e5M',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-DLETk9UypJr2wwnUlOxC311oVZGpE9Re' => array(
          'module' => 'facetapi',
          'delta' => 'DLETk9UypJr2wwnUlOxC311oVZGpE9Re',
          'region' => 'sidebar_first',
          'weight' => '2',
        ),
        'facetapi-BTl1CDVWSWMTl6EskNHpX9l0vaRRNFUI' => array(
          'module' => 'facetapi',
          'delta' => 'BTl1CDVWSWMTl6EskNHpX9l0vaRRNFUI',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
        'facetapi-6xYmKQ8vLL2wVseCqvdGE8oA1nZ8MCrV' => array(
          'module' => 'facetapi',
          'delta' => '6xYmKQ8vLL2wVseCqvdGE8oA1nZ8MCrV',
          'region' => 'sidebar_first',
          'weight' => '4',
        ),
        'facetapi-puGASfwGBgxqw2OLjupootf0hh1j0Vov' => array(
          'module' => 'facetapi',
          'delta' => 'puGASfwGBgxqw2OLjupootf0hh1j0Vov',
          'region' => 'sidebar_first',
          'weight' => '5',
        ),
        'facetapi-RT8QSIFGgAE8E3WpCrFq1xUouhSyw5l0' => array(
          'module' => 'facetapi',
          'delta' => 'RT8QSIFGgAE8E3WpCrFq1xUouhSyw5l0',
          'region' => 'sidebar_first',
          'weight' => '6',
        ),
        'facetapi-UtK0707P0MZIRNgUyu7jlqVwryCbPjI7' => array(
          'module' => 'facetapi',
          'delta' => 'UtK0707P0MZIRNgUyu7jlqVwryCbPjI7',
          'region' => 'sidebar_first',
          'weight' => '7',
        ),
        'facetapi-kvPlNPRcztUlILywblxC9Kj14ZYJ7Dnw' => array(
          'module' => 'facetapi',
          'delta' => 'kvPlNPRcztUlILywblxC9Kj14ZYJ7Dnw',
          'region' => 'sidebar_first',
          'weight' => '8',
        ),
        'facetapi-2YjC0jkpLuDo83J5vKUePxYbVuECKyqJ' => array(
          'module' => 'facetapi',
          'delta' => '2YjC0jkpLuDo83J5vKUePxYbVuECKyqJ',
          'region' => 'sidebar_first',
          'weight' => '9',
        ),
        'facetapi-6Zgnx9y3rxoyWwk7wgFl1W7QgIt31GY5' => array(
          'module' => 'facetapi',
          'delta' => '6Zgnx9y3rxoyWwk7wgFl1W7QgIt31GY5',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-OJ2GqhOef1qXuX0bmR9TINWSVF6iy8O0' => array(
          'module' => 'facetapi',
          'delta' => 'OJ2GqhOef1qXuX0bmR9TINWSVF6iy8O0',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-QV0C3iB8f4Sp8nZiEl7xfMdy6yODwvaq' => array(
          'module' => 'facetapi',
          'delta' => 'QV0C3iB8f4Sp8nZiEl7xfMdy6yODwvaq',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-TvhfpJzMXiIfTQiyBbsn17wY3UrhJWi8' => array(
          'module' => 'facetapi',
          'delta' => 'TvhfpJzMXiIfTQiyBbsn17wY3UrhJWi8',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-BbjS6DaqUrTwWSS88HinJ5WdY8zb7S1Q' => array(
          'module' => 'facetapi',
          'delta' => 'BbjS6DaqUrTwWSS88HinJ5WdY8zb7S1Q',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-cxDmV0KFBCNFhOf5G9IBJcyur6oq9wBi' => array(
          'module' => 'facetapi',
          'delta' => 'cxDmV0KFBCNFhOf5G9IBJcyur6oq9wBi',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-tVKFqsX0tXFjqNAOn0dm9TFOe3zmCnEB' => array(
          'module' => 'facetapi',
          'delta' => 'tVKFqsX0tXFjqNAOn0dm9TFOe3zmCnEB',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-kWuYTykBrOHHbkZVhzzX8571AjjYDq0s' => array(
          'module' => 'facetapi',
          'delta' => 'kWuYTykBrOHHbkZVhzzX8571AjjYDq0s',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-KJhRd1mKJ3hzygJSdEnFJ6kF1C9FEnm2' => array(
          'module' => 'facetapi',
          'delta' => 'KJhRd1mKJ3hzygJSdEnFJ6kF1C9FEnm2',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-ERANgcaU9Ge2jq9bXroQtqAyFktX7z4O' => array(
          'module' => 'facetapi',
          'delta' => 'ERANgcaU9Ge2jq9bXroQtqAyFktX7z4O',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-DkAnvF8PqBB9HDgxzTDAw1zxxOFdVOBZ' => array(
          'module' => 'facetapi',
          'delta' => 'DkAnvF8PqBB9HDgxzTDAw1zxxOFdVOBZ',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-D911TBQtmzdrE1djmeYc16CLNnP3mgbb' => array(
          'module' => 'facetapi',
          'delta' => 'D911TBQtmzdrE1djmeYc16CLNnP3mgbb',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-fJbI51MTlK4s09i1fDIKtcVbBvlnyK72' => array(
          'module' => 'facetapi',
          'delta' => 'fJbI51MTlK4s09i1fDIKtcVbBvlnyK72',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-ukU3gG46bAP0T0Lp3IZbZg5glHHJA0h7' => array(
          'module' => 'facetapi',
          'delta' => 'ukU3gG46bAP0T0Lp3IZbZg5glHHJA0h7',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-Avjzj8RoxfiAWjKueVObMUvzr5BsH2AE' => array(
          'module' => 'facetapi',
          'delta' => 'Avjzj8RoxfiAWjKueVObMUvzr5BsH2AE',
          'region' => 'sidebar_first',
          'weight' => '10',
        ),
        'facetapi-7lm9Bk6IKPvVHcAMaKV9ddvVy7XVPKbG' => array(
          'module' => 'facetapi',
          'delta' => '7lm9Bk6IKPvVHcAMaKV9ddvVy7XVPKbG',
          'region' => 'sidebar_first',
          'weight' => '10',
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
