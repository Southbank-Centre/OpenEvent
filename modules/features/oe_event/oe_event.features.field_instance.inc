<?php
/**
 * @file
 * oe_event.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function oe_event_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-event-field_description'
  $field_instances['node-event-field_description'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The full text information about the event. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.description</code></a>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'field_readonly' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
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
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'plain_text' => array(
              'weight' => 10,
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-event-field_event_age_range'
  $field_instances['node-event-field_event_age_range'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The suggested or required age range for an event. It should be specified as an age range, a minimum age, or a single age. For example, <i>5+</i> specifies ages 5 and above; <i>0-12</i> specifies ages 0 to 12; <i>16</i> specifies age 16 only. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.typicalAgeRange</code></a>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'field_readonly' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event_age_range',
    'label' => 'Age range',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'iframe_html' => 0,
          'limited_html' => 0,
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'iframe_html' => array(
              'weight' => 0,
            ),
            'limited_html' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-event-field_event_date_end'
  $field_instances['node-event-field_event_date_end'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => 'The end date and time for the event. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.endDate</code></a>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event_date_end',
    'label' => 'End date/time',
    'required' => 1,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 1,
        'increment' => 5,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-event-field_event_date_start'
  $field_instances['node-event-field_event_date_start'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => 'The start date and time for the event. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.startDate</code></a>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event_date_start',
    'label' => 'Start date/time',
    'required' => 1,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 1,
        'increment' => 5,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-event-field_event_door_time'
  $field_instances['node-event-field_event_door_time'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => 'The date and time that the venue can be accessed before the event starts. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.doorTime</code></a>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event_door_time',
    'label' => 'Door time',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 5,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'node-event-field_event_duration'
  $field_instances['node-event-field_event_duration'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The duration of the event in minutes. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.duration</code></a>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event_duration',
    'label' => 'Duration',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-event-field_event_parents'
  $field_instances['node-event-field_event_parents'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => '<p>This field allows you to determine which events this event is grouped within.</p>
<p>Events can be structured hierarchically, with events being \'parents\' of others events that may in turn be \'parents\' of other events, and so on. This makes it possible to structure events into groupings.</p>
<p>For example, a festival is an event that takes place often over a number of days. Within a festival is a series of shorter events. Once an Event has been created to represent the festival, it is then possible to group the events it contains by specifying the festival Event in their \'Event parents\' field.</p>
<p>Note that an event can be the child of multiple other events, but it cannot be the child of an event that lists it as a parent.</p>
<p>Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.superEvent</code></a></p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'relation_add',
        'settings' => array(),
        'type' => 'relation_add_endpoints_and_fields',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event_parents',
    'label' => 'Parents',
    'required' => 0,
    'settings' => array(
      'relation_target_bundles' => array(
        'node:event' => 'node:event',
      ),
      'relation_type' => array(
        'event_is_contained_in_event' => 'event_is_contained_in_event',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'relation_add',
      'settings' => array(
        'relation_endpoint_bundle_display' => 0,
        'relation_endpoint_custom_label' => 'Parent',
        'relation_endpoint_iso_language_codes' => 0,
        'relation_endpoint_label' => 'custom',
        'relation_endpoint_label_delta' => 0,
        'relation_endpoint_search_by_id' => 0,
      ),
      'type' => 'relation_add',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-event-field_event_places'
  $field_instances['node-event-field_event_places'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => 'The location or locations of the event. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.location</code></a>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'relation_add',
        'settings' => array(),
        'type' => 'relation_add_endpoints_and_fields',
        'weight' => 14,
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

  // Exported field_instance: 'node-event-field_image'
  $field_instances['node-event-field_image'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => 'Images from the event.<br/>
Maps to <a href="http://schema.org/image" target="_blank"><code>Event:image</code></a> in Schema.org.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '1 MB',
      'max_resolution' => '1280x720',
      'min_resolution' => '320x180',
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
            'reference' => 'reference',
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
            'autocomplete' => 1,
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'relation-event_is_contained_in_event-endpoints'
  $field_instances['relation-event_is_contained_in_event-endpoints'] = array(
    'bundle' => 'event_is_contained_in_event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'relation_endpoint',
        'settings' => array(
          'view_modes' => array(
            'file' => 'default',
            'node' => 'default',
            'paragraphs_item' => 'default',
            'relation' => 'default',
            'taxonomy_term' => 'default',
            'taxonomy_vocabulary' => 'default',
            'user' => 'default',
          ),
        ),
        'type' => 'relation_endpoint',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'relation',
    'field_name' => 'endpoints',
    'label' => 'endpoints',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'relation_endpoint',
      'settings' => array(),
      'type' => 'relation_endpoint',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>This field allows you to determine which events this event is grouped within.</p>
<p>Events can be structured hierarchically, with events being \'parents\' of others events that may in turn be \'parents\' of other events, and so on. This makes it possible to structure events into groupings.</p>
<p>For example, a festival is an event that takes place often over a number of days. Within a festival is a series of shorter events. Once an Event has been created to represent the festival, it is then possible to group the events it contains by specifying the festival Event in their \'Event parents\' field.</p>
<p>Note that an event can be the child of multiple other events, but it cannot be the child of an event that lists it as a parent.</p>
<p>Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.superEvent</code></a></p>');
  t('Age range');
  t('Description');
  t('Door time');
  t('Duration');
  t('End date/time');
  t('Image');
  t('Images from the event.<br/>
Maps to <a href="http://schema.org/image" target="_blank"><code>Event:image</code></a> in Schema.org.');
  t('Parents');
  t('Start date/time');
  t('The date and time that the venue can be accessed before the event starts. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.doorTime</code></a>');
  t('The duration of the event in minutes. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.duration</code></a>');
  t('The end date and time for the event. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.endDate</code></a>');
  t('The full text information about the event. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.description</code></a>');
  t('The location or locations of the event. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.location</code></a>');
  t('The start date and time for the event. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.startDate</code></a>');
  t('The suggested or required age range for an event. It should be specified as an age range, a minimum age, or a single age. For example, <i>5+</i> specifies ages 5 and above; <i>0-12</i> specifies ages 0 to 12; <i>16</i> specifies age 16 only. Maps to <a href="https://schema.org/Event" target="_blank">schema.org <code>Event.typicalAgeRange</code></a>');
  t('Venues');
  t('endpoints');

  return $field_instances;
}
