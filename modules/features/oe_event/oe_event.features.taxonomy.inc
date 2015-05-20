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
      'description' => 'Event classes categorise what form events will take, and help data consuming applications determine how to represent events.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'event_type' => array(
      'name' => 'Event type',
      'machine_name' => 'event_type',
      'description' => 'Event types are terms assigned to events to categorise their content so that users know what to expect if they were to attend.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
