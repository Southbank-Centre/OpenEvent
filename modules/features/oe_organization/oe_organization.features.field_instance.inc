<?php
/**
 * @file
 * oe_organization.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function oe_organization_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-organization-field_description'
  $field_instances['node-organization-field_description'] = array(
    'bundle' => 'organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>A short description of the organization.</p>
<p>Maps to the <code><a href="http://schema.org/Organization" target="_blank">organization</a>.<a href="http://schema.org/description" target="_blank">description</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 0,
          'plain_text' => 0,
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'plain_text' => array(
              'weight' => -7,
            ),
          ),
        ),
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-organization-field_organization_events'
  $field_instances['node-organization-field_organization_events'] = array(
    'bundle' => 'organization',
    'deleted' => 0,
    'description' => '<p>Events in which this organization is a performer.</p>
<p>Maps to the <code><a href="http://schema.org/Organization" target="_blank">organization</a>.<a href="http://schema.org/performerIn" target="_blank">performerIn</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'relation_add',
        'settings' => array(),
        'type' => 'relation_add_endpoints_and_fields',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_organization_events',
    'label' => 'Events',
    'required' => 0,
    'settings' => array(
      'relation_target_bundles' => array(
        'node:event' => 'node:event',
      ),
      'relation_type' => array(
        'performer_performs_in_event' => 'performer_performs_in_event',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'relation_add',
      'settings' => array(
        'relation_endpoint_bundle_display' => 0,
        'relation_endpoint_custom_label' => 'Event ',
        'relation_endpoint_iso_language_codes' => 0,
        'relation_endpoint_label' => 'custom',
        'relation_endpoint_label_delta' => 0,
        'relation_endpoint_search_by_id' => 0,
      ),
      'type' => 'relation_add',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-organization-field_image'
  $field_instances['node-organization-field_image'] = array(
    'bundle' => 'organization',
    'deleted' => 0,
    'description' => '<p>Images that represent the organization. Multiple images are allowed.</p>
<p>Maps to the <code><a href="http://schema.org/Organization" target="_blank">organization</a>.<a href="http://schema.org/image" target="_blank">image</a></code> Schema.org property.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>A short description of the organization.</p>
<p>Maps to the <code><a href="http://schema.org/Organization" target="_blank">organization</a>.<a href="http://schema.org/description" target="_blank">description</a></code> Schema.org property.</p>');
  t('<p>Images that represent the organization. Multiple images are allowed.</p>
<p>Maps to the <code><a href="http://schema.org/Organization" target="_blank">organization</a>.<a href="http://schema.org/image" target="_blank">image</a></code> Schema.org property.');
  t('<p>Performers at the event—for example, a presenter, musician, musical group or actor.</p>
<p>Maps to the <code><a href="http://schema.org/Event" target="_blank">Event</a>.<a href="http://schema.org/performer" target="_blank">performer</a></code> Schema.org property.</p>');
  t('Description');
  t('Image');
  t('Performers');
  t('endpoints');

  return $field_instances;
}
