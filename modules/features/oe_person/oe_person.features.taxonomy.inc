<?php
/**
 * @file
 * oe_person.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function oe_person_taxonomy_default_vocabularies() {
  return array(
    'person_title' => array(
      'name' => 'Person title',
      'machine_name' => 'person_title',
      'description' => 'A title is a prefix or suffix added to someone\'s name in certain contexts.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
