<?php
/**
 * @file
 * oe_relationship_performer.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function oe_relationship_performer_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_event_performers'
  $field_bases['field_event_performers'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_event_performers',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'relation_add',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'relation_add',
  );

  // Exported field_base: 'field_organization_events'
  $field_bases['field_organization_events'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_organization_events',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'relation_add',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'relation_add',
  );

  // Exported field_base: 'field_person_events'
  $field_bases['field_person_events'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_person_events',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'relation_add',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'relation_add',
  );

  return $field_bases;
}
