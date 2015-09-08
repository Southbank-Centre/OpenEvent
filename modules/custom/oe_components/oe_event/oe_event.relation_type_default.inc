<?php
/**
 * @file
 * oe_event.relation_type_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function oe_event_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass();
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'event_is_contained_in_event';
  $relation_type->label = 'Event is contained in Event';
  $relation_type->reverse_label = 'Event contains Event';
  $relation_type->directional = 1;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $relation_type->source_bundles = array(
    0 => 'node:event',
  );
  $relation_type->target_bundles = array(
    0 => 'node:event',
  );
  $export['event_is_contained_in_event'] = $relation_type;

  return $export;
}
