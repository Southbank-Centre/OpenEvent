<?php
/**
 * @file
 * oe_person.relation_type_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function oe_person_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass();
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'performer_performs_in_event';
  $relation_type->label = 'Performer performs in Event';
  $relation_type->reverse_label = 'Event has performer';
  $relation_type->directional = 1;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $relation_type->source_bundles = array(
    0 => 'node:organization',
    1 => 'node:person',
  );
  $relation_type->target_bundles = array(
    0 => 'node:event',
  );
  $export['performer_performs_in_event'] = $relation_type;

  return $export;
}
