<?php
/**
 * @file
 * oe_relationship_location.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function oe_relationship_location_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_event_places'
  $field_bases['field_event_places'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_event_places',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'relation_add',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'relation_add',
  );

  return $field_bases;
}
