<?php
/**
 * @file
 * oe_person.rdf_mapping.inc
 */

/**
 * Implements hook_rdf_mapping().
 */
function oe_person_rdf_mapping() {
  return array(
    array(
      'type' => 'node',
      'bundle' => 'person',
      'mapping' => array(
        'rdftype' => array(
          0 => 'schema:Person',
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
        'field_person_name_prefix' => array(
          'predicates' => array(
            0 => 'schema:honorificPrefix',
          ),
          'type' => 'rel',
        ),
        'field_person_name_given' => array(
          'predicates' => array(
            0 => 'schema:givenName',
          ),
        ),
        'field_person_name_middle' => array(
          'predicates' => array(
            0 => 'schema:additionalName',
          ),
        ),
        'field_person_name_family' => array(
          'predicates' => array(
            0 => 'schema:familyName',
          ),
        ),
        'field_person_name_suffix' => array(
          'predicates' => array(
            0 => 'schema:honorificSuffix',
          ),
        ),
        'field_person_name_alias' => array(
          'predicates' => array(
            0 => 'schema:alternateName',
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
        'field_person_job' => array(
          'predicates' => array(
            0 => 'schema:jobTitle',
          ),
        ),
        'field_person_awards' => array(
          'predicates' => array(
            0 => 'schema:award',
          ),
        ),
        'field_person_urls' => array(
          'predicates' => array(
            0 => 'schema:sameAs',
          ),
        ),
        'field_person_same_as' => array(
          'predicates' => array(
            0 => 'schema:sameAs',
          ),
        ),
      ),
    ),
  );
}
