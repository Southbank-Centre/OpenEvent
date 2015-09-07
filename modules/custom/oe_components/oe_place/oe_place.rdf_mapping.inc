<?php
/**
 * @file
 * oe_place.rdf_mapping.inc
 */

/**
 * Implements hook_rdf_mapping().
 */
function oe_place_rdf_mapping() {
  return array(
    array(
      'type' => 'node',
      'bundle' => 'place',
      'mapping' => array(
        'rdftype' => array(
          0 => 'schema:Place',
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
        'field_place_address' => array(
          'predicates' => array(
            0 => 'schema:address',
          ),
        ),
        'url' => array(
          'predicates' => array(
            0 => 'schema:url',
          ),
          'type' => 'rel',
        ),
        'field_place_geolocation' => array(
          'predicates' => array(
            0 => 'schema:geo',
          ),
        ),
        'field_description' => array(
          'predicates' => array(
            0 => 'schema:description',
          ),
        ),
        'field_place_opening_hours' => array(
          'predicates' => array(
            0 => 'schema:openingHoursSpecification',
          ),
        ),
        'field_image' => array(
          'predicates' => array(
            0 => 'schema:image',
          ),
          'type' => 'rel',
        ),
        'field_place_parents' => array(
          'predicates' => array(
            0 => 'schema:containedIn',
          ),
        ),
      ),
    ),
    array (
      'type' => 'relation',
      'bundle' => 'place_is_contained_in_place',
      'mapping' => array(
        'source_bundles' => array(
          'predicates' => array(
            0 => 'schema:containedIn',
          ),
        ),
        'target_bundles' => array(
          'predicates' => array(),
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
