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
    'name_title' => array(
      'name' => 'Name title',
      'machine_name' => 'name_title',
      'description' => 'A title is a prefix or suffix added to someone\'s name in certain contexts.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
