<?php
/**
 * @file
 * oe_organization.features.field_base.inc
 */

function oe_organization_field_bases() {

  // field base: field_organization_address
  if (!field_info_field('field_organization_address')) {

    $field_organization_address = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_organization_address',
      'indexes' => array(),
      'locked' => 0,
      'module' => 'addressfield',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'addressfield',
    );

    field_create_field($field_organization_address);

  };

  // field base: field_organization_email
  if (!field_info_field('field_organization_email')) {

    $field_organization_email = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_organization_email',
      'indexes' => array(),
      'locked' => 0,
      'module' => 'email',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'email',
    );

    field_create_field($field_organization_email);

  };

  // field base: field_organization_legal_name
  if (!field_info_field('field_organization_legal_name')) {

    $field_organization_legal_name = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_organization_legal_name',
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    );

    field_create_field($field_organization_legal_name);

  };

  // field base: field_organization_logo
  if (!field_info_field('field_organization_logo')) {

    $field_organization_logo = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_organization_logo',
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => 0,
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => 0,
      'type' => 'image',
    );

    field_create_field($field_organization_logo);

  };

  // field base: field_organization_same_as
  if (!field_info_field('field_organization_same_as')) {

    $field_organization_same_as = array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_organization_same_as',
      'indexes' => array(),
      'locked' => 0,
      'module' => 'link',
      'settings' => array(
        'attributes' => array(
          'class' => '',
          'rel' => '',
          'target' => 'default',
        ),
        'display' => array(
          'url_cutoff' => 80,
        ),
        'enable_tokens' => 1,
        'title' => 'optional',
        'title_maxlength' => 128,
        'title_value' => '',
        'url' => 0,
      ),
      'translatable' => 0,
      'type' => 'link_field',
    );
    
    field_create_field($field_organization_same_as);

  };

}
