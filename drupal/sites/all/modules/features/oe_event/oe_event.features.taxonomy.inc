<?php
/**
 * @file
 * oe_event.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function oe_event_taxonomy_default_vocabularies() {
  return array(
    'event_class' => array(
      'name' => 'Event class',
      'machine_name' => 'event_class',
      'description' => 'An event class is a term assigned to an event to categorise its form, e.g. Festival, Series, Performance, etc.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'event_type' => array(
      'name' => 'Event type',
      'machine_name' => 'event_type',
      'description' => 'Event types are terms assigned to an event to categorise its content, e.g. Classical, Dance, Comedy, etc.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
