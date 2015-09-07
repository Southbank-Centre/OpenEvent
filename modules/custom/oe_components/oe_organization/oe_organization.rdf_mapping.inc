<?php
/**
 * @file
 * oe_organization.rdf_mapping.inc
 */

/**
 * Implements hook_rdf_mapping().
 */
function oe_organization_rdf_mapping() {
  return array(
    array(
      'type' => 'node',
      'bundle' => 'organization',
      'mapping' => array(
        'rdftype' => array(
          0 => 'schema:Organization',
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
        'field_organization_logo' => array(
          'predicates' => array(
            0 => 'schema:logo',
          ),
          'type' => 'rel',
        ),
        'url' => array(
          'predicates' => array(
            0 => 'schema:url',
          ),
          'type' => 'rel',
        ),
        'field_description' => array(
          'predicates' => array(
            0 => 'schema:description',
          ),
        ),
        'field_organization_legal_name' => array(
          'predicates' => array(
            0 => 'schema:legalName',
          ),
        ),
        'field_organization_email' => array(
          'predicates' => array(
            0 => 'schema:email',
          ),
        ),
        'field_organization_address' => array(
          'predicates' => array(
            0 => 'schema:address',
          ),
        ),
        'field_organization_same_as' => array(
          'predicates' => array(
            0 => 'schema:sameAs',
          ),
        ),
        'field_image' => array(
          'predicates' => array(
            0 => 'schema:image',
          ),
          'type' => 'rel',
        ),
      ),
    ),
  );
}
