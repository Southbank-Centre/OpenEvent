<?php
/**
 * @file
 * oe_relationship_performer.field_instance.inc
 */

function oe_relationship_performer_field_instances() {
  
  $field_instances = array();

  // Exported field_instance: 'node-event-field_event_performers'
  $field_instances['node-event-field_event_performers'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => '<p>Performers at the event—for example, a presenter, musician, musical group, actor or organization.</p>
<p>Maps to the <code><a href="http://schema.org/Event" target="_blank">Event</a>.<a href="http://schema.org/performer" target="_blank">performer</a></code> Schema.org property.</p>',
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
    'field_name' => 'field_event_performers',
    'label' => 'Performers',
    'required' => 0,
    'settings' => array(
      'relation_target_bundles' => array(
        'node:organization' => 'node:organization',
        'node:person' => 'node:person',
      ),
      'relation_type' => array(
        'performer_performs_in_event:reverse' => 'performer_performs_in_event:reverse',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'relation_add',
      'settings' => array(
        'relation_endpoint_bundle_display' => 0,
        'relation_endpoint_custom_label' => 'Performer',
        'relation_endpoint_iso_language_codes' => 0,
        'relation_endpoint_label' => 'custom',
        'relation_endpoint_label_delta' => 0,
        'relation_endpoint_search_by_id' => 0,
      ),
      'type' => 'relation_add',
      'weight' => 7,
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

  // Exported field_instance: 'node-person-field_person_events'
  $field_instances['node-person-field_person_events'] = array(
    'bundle' => 'person',
    'deleted' => 0,
    'description' => '<p>Events in which this person is a performer.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/performerIn" target="_blank">performerIn</a></code> Schema.org property.</p>',
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
    'field_name' => 'field_person_events',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>Events in which this organization is a performer.</p>
<p>Maps to the <code><a href="http://schema.org/Organization" target="_blank">organization</a>.<a href="http://schema.org/performerIn" target="_blank">performerIn</a></code> Schema.org property.</p>');
  t('<p>Events in which this person is a performer.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/performerIn" target="_blank">performerIn</a></code> Schema.org property.</p>');
  t('<p>Performers at the event—for example, a presenter, musician, musical group, actor or organization.</p>
<p>Maps to the <code><a href="http://schema.org/Event" target="_blank">Event</a>.<a href="http://schema.org/performer" target="_blank">performer</a></code> Schema.org property.</p>');
  t('Events');
  t('Performers');

  foreach($field_instances as $field_instance) {
    field_create_instance($field_instance);
  }
  
}
