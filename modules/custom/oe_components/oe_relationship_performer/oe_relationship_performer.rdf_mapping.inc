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
      'bundle' => 'performer_performs_in_event',
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
