<?php
/**
 * @file
 * oe_relationship_performer.rdf_mapping.inc
 */

/**
 * Implements hook_rdf_mapping().
 */
function oe_relationship_performer_rdf_mapping() {
  return array(
    array(
      'type' => 'relation',
      'bundle' => 'event_is_located_in_place',
      'mapping' => array(
        'source_bundles' => array(
          'predicates' => array(
            0 => 'schema:performerIn',
          ),
        ),
        'target_bundles' => array(
          'predicates' => array(
            0 => 'schema:performer',
          ),
        ),
        'url' => array(
          'predicates' => array(
            0 => 'schema:url',
          ),
          'type' => 'rel',
        ),
      ),
    ),
  );
}
