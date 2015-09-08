<?php
/**
 * @file
 * oe_event.rdf_mapping.inc
 */

/**
 * Implements hook_rdf_mapping().
 */
function oe_event_rdf_mapping() {
  return array(
    array(
      'type' => 'node',
      'bundle' => 'event',
      'mapping' => array(
        'rdftype' => array(
          0 => 'schema:Event',
          1 => 'sioc:Item',
          2 => 'foaf:Document',
        ),
        'title' => array(
          'predicates' => array(
            0 => 'schema:name',
          ),
        ),
        'created' => array(
          'predicates' => array(
            0 => 'dc:date',
            1 => 'dc:created',
          ),
          'datatype' => 'xsd:dateTime',
          'callback' => 'date_iso8601',
        ),
        'changed' => array(
          'predicates' => array(
            0 => 'dc:modified',
          ),
          'datatype' => 'xsd:dateTime',
          'callback' => 'date_iso8601',
        ),
        'body' => array(
          'predicates' => array(
            0 => 'content:encoded',
          ),
        ),
        'uid' => array(
          'predicates' => array(
            0 => 'sioc:has_creator',
          ),
          'type' => 'rel',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'schema:name',
          ),
        ),
        'comment_count' => array(
          'predicates' => array(
            0 => 'sioc:num_replies',
          ),
          'datatype' => 'xsd:integer',
        ),
        'last_activity' => array(
          'predicates' => array(
            0 => 'sioc:last_activity_date',
          ),
          'datatype' => 'xsd:dateTime',
          'callback' => 'date_iso8601',
        ),
        'url' => array(
          'predicates' => array(
            0 => 'schema:url',
          ),
          'type' => 'rel',
        ),
        'field_event_date_start' => array(
          'predicates' => array(
            0 => 'schema:startDate',
          ),
        ),
        'field_event_date_end' => array(
          'predicates' => array(
            0 => 'schema:endDate',
          ),
        ),
        'field_description' => array(
          'predicates' => array(
            0 => 'schema:description',
          ),
        ),
        'field_image' => array(
          'predicates' => array(
            0 => 'schema:image',
          ),
          'type' => 'rel',
        ),
        'field_event_parents' => array(
          'predicates' => array(
            0 => 'schema:superEvent',
          ),
        ),
        'field_event_duration' => array(
          'predicates' => array(
            0 => 'schema:duration',
          ),
        ),
        'field_event_door_time' => array(
          'predicates' => array(
            0 => 'schema:doorTime',
          ),
        ),
        'field_event_age_range' => array(
          'predicates' => array(
            0 => 'schema:typicalAgeRange',
          ),
        ),
      ),
    ),
    array(
      'type' => 'relation',
      'bundle' => 'event_is_contained_in_event',
      'mapping' => array(
        'source_bundles' => array(
          'predicates' => array(
            0 => 'schema:superEvent',
          ),
        ),
        'target_bundles' => array(
          'predicates' => array(
            0 => 'schema:subEvent',
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
