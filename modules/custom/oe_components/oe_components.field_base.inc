<?php
/**
 * @file
 * oe_components.field_base.inc
 */

function oe_components_field_bases() {

  // field base: field_description
  if (!field_info_field('field_description')) {

    $field_description = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_description',
      'indexes' => array(
        'format' => array(
          0 => 'format',
          ),
        ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'text_long',
    );
    field_create_field($field_description);

  };

  // field base: field_image
  if (!field_info_field('field_image')) {

    $field_image = array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_image',
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
    field_create_field($field_image);

  };

  // field base: field_file_image_alt_text'
  if (!field_info_field('field_file_image_alt_text')) {

    $field_file_image_alt_text = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_file_image_alt_text',
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
    field_create_field($field_file_image_alt_text);

  };

  // field base: field_file_image_title_text'
  if (!field_info_field('field_file_image_title_text')) {

    $field_file_image_title_text = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_file_image_title_text',
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
    field_create_field($field_file_image_title_text);

  };

}
