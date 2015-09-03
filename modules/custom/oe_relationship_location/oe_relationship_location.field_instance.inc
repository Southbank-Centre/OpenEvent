<?php
/**
 * @file
 * oe_relationship_location.features.field_instance.inc
 */

function oe_relationship_location_field_instances() {
  
  $field_instances = array();

  // Exported field_instance: 'node-event-field_event_places'
  $field_instances['node-event-field_event_places'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => '<p>The location or locations of the event.</p>
<p>Maps to the <code><a href="https://schema.org/Event" target="_blank">Event</a>.<a href="https://schema.org/location" target="_blank">location</a></code> Schema.org property.</p>',
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
    'field_name' => 'field_event_places',
    'label' => 'Venues',
    'required' => 0,
    'settings' => array(
      'relation_target_bundles' => array(
        'node:place' => 'node:place',
      ),
      'relation_type' => array(
        'event_is_located_in_place' => 'event_is_located_in_place',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'relation_add',
      'settings' => array(
        'relation_endpoint_bundle_display' => 0,
        'relation_endpoint_custom_label' => 'Venue',
        'relation_endpoint_iso_language_codes' => 0,
        'relation_endpoint_label' => 'custom',
        'relation_endpoint_label_delta' => 0,
        'relation_endpoint_search_by_id' => 0,
      ),
      'type' => 'relation_add',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>The location or locations of the event.</p>
<p>Maps to the <code><a href="https://schema.org/Event" target="_blank">Event</a>.<a href="https://schema.org/location" target="_blank">location</a></code> Schema.org property.</p>');
  t('Venues');

  foreach($field_instances as $field_instance) {
    field_create_instance($field_instance);
  }

}
