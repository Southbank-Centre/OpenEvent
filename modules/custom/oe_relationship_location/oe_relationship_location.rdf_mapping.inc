<?php
/**
 * @file
 * oe_relationship_location.rdf_mapping.inc
 */

/**
 * Implements hook_rdf_mapping().
 */
function oe_relationship_location_rdf_mapping() {
  return array(
    array(
      'type' => 'relation',
      'bundle' => 'event_is_located_in_place',
      'mapping' => array(
        'source_bundles' => array(
          'predicates' => array(
            0 => 'schema:location',
          ),
        ),
        'target_bundles' => array(
          'predicates' => array(
            0 => 'schema:event',
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
