<?php
/**
 * @file
 * accessibility.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function accessibility_taxonomy_default_vocabularies() {
  return array(
    'accessibility_error_group' => array(
      'name' => 'Accessibility Error Group',
      'machine_name' => 'accessibility_error_group',
      'description' => 'Accessibility Error Group',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'accessibility_errors' => array(
      'name' => 'Accessibility Errors',
      'machine_name' => 'accessibility_errors',
      'description' => 'Accessibility Errors',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
