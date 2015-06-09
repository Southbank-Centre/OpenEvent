<?php
/**
 * @file
 * oe_place.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function oe_place_field_default_field_instances() {
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
        'weight' => 3,
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-place-field_description'
  $field_instances['node-place-field_description'] = array(
    'bundle' => 'place',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>The full text information about the place.</p>
<p>Maps to the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/description" target="_blank">description</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-place-field_image'
  $field_instances['node-place-field_image'] = array(
    'bundle' => 'place',
    'deleted' => 0,
    'description' => 'An image that represents the place. Maps to <a href="https://schema.org/Place" target="_blank">schema.org <code>Place.image</code></a> as an ImageObject where:<br />
<ul>
<li>Image maps to ImageObject.<a href="https://schema.org/contentUrl">contentUrl</a></li>
<li>Alternate Text maps to ImageObject.<a href="https://schema.org/alternateName">alternateName</a></li>
<li>Title maps to ImageObject.<a href="https://schema.org/caption">caption</a></li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-place-field_place_address'
  $field_instances['node-place-field_place_address'] = array(
    'bundle' => 'place',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>The address of the place.</p>
<p>Maps to the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/address" target="_blank">address</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_place_address',
    'label' => 'Address',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'default_country' => 'GB',
        'format_handlers' => array(
          'address' => 'address',
          'address-optional' => 'address-optional',
          'address-hide-postal-code' => 0,
          'address-hide-street' => 0,
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-place-field_place_geolocation'
  $field_instances['node-place-field_place_geolocation'] = array(
    'bundle' => 'place',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>The location of the place.</p>
<p>Maps to the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/geo" target="_blank">geo</a></code> Schema.org property.</p>
<p>If this field is populated, the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/hasMap" target="_blank">hasMap</a></code> Schema.org property is populated with an <a href="http://http://www.openstreetmap.org/" target="_blank">OpenStreetMap</a> link to a map centered at the given coordinates.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'geolocation',
        'settings' => array(),
        'type' => 'geolocation_text',
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
    'field_name' => 'field_place_geolocation',
    'label' => 'Geolocation',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'geolocation_googlemaps',
      'settings' => array(
        'marker_draggable' => 1,
        'scrollwheel' => 0,
      ),
      'type' => 'geolocation_googlemap',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-place-field_place_opening_hours'
  $field_instances['node-place-field_place_opening_hours'] = array(
    'bundle' => 'place',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The opening hours of the place. Leave field blank when there are no opening hours for a particular day. <p>Maps to <a href="https://schema.org/Place" target="_blank">schema.org <code>Place.openingHoursSpecification</code></a></p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'office_hours',
        'settings' => array(
          'closedformat' => 'Closed',
          'compress' => FALSE,
          'current_status' => array(
            'closed_text' => 'Currently closed',
            'open_text' => 'Currently open!',
            'position' => 'hide',
          ),
          'date_first_day' => 1,
          'daysformat' => 'long',
          'grouped' => 0,
          'hoursformat' => 0,
          'separator_day_hours' => ': ',
          'separator_days' => '<br />',
          'separator_grouped_days' => ' - ',
          'separator_hours_hours' => '-',
          'separator_more_hours' => ', ',
          'showclosed' => 'all',
          'timezone_field' => '',
        ),
        'type' => 'office_hours',
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
    'field_name' => 'field_place_opening_hours',
    'label' => 'Opening hours',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'office_hours',
      'settings' => array(),
      'type' => 'office_hours',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-place-field_place_parents'
  $field_instances['node-place-field_place_parents'] = array(
    'bundle' => 'place',
    'deleted' => 0,
    'description' => '<p>This field allows you to determine which places this place is located within.</p>
<p>Places can be structured hierarchically, with places being \'parents\' of others places that may in turn be \'parents\' of other places, and so on.</p>
<p>For example, a rooms are situated within a building. Once an Place has been created to represent the building, it is then possible to group the rooms it contains by specifying the building Places in their \'Parents\' field.</p>
<p>Note that an place can be the child of multiple other place, but it cannot be the child of an place that lists it as a parent.</p>
<p>Maps to the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/containedIn" target="_blank">containedIn</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'relation_add',
        'settings' => array(),
        'type' => 'relation_add_endpoints_and_fields',
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
    'field_name' => 'field_place_parents',
    'label' => 'Place parents',
    'required' => 0,
    'settings' => array(
      'relation_target_bundles' => array(
        'node:place' => 'node:place',
      ),
      'relation_type' => array(
        'place_is_contained_in_place' => 'place_is_contained_in_place',
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
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>Images that represent the place. Multiple images are allowed.</p>
<p>Maps to the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/image" target="_blank">image</a></code> Schema.org property.</p>');
  t('<p>The address of the place.</p>
<p>Maps to the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/address" target="_blank">address</a></code> Schema.org property.</p>');
  t('<p>The full text information about the place.</p>
<p>Maps to the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/description" target="_blank">description</a></code> Schema.org property.</p>');
  t('<p>The location of the place.</p>
<p>Maps to the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/geo" target="_blank">geo</a></code> Schema.org property.</p>
<p>If this field is populated, the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/hasMap" target="_blank">hasMap</a></code> Schema.org property is populated with an <a href="http://http://www.openstreetmap.org/" target="_blank">OpenStreetMap</a> link to a map centered at the given coordinates.</p>');
  t('<p>The location or locations of the event.</p>
<p>Maps to the <code><a href="https://schema.org/Event" target="_blank">Event</a>.<a href="https://schema.org/location" target="_blank">location</a></code> Schema.org property.</p>');
  t('<p>The opening hours of the place. Leave field blank when there are no opening hours for a particular day.</p>
<p>Maps to the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/openingHoursSpecification" target="_blank">openingHoursSpecification</a></code> Schema.org property.</p>');
  t('<p>This field allows you to determine which places this place is located within.</p>
<p>Places can be structured hierarchically, with places being \'parents\' of others places that may in turn be \'parents\' of other places, and so on.</p>
<p>For example, a rooms are situated within a building. Once an Place has been created to represent the building, it is then possible to group the rooms it contains by specifying the building Places in their \'Parents\' field.</p>
<p>Note that an place can be the child of multiple other place, but it cannot be the child of an place that lists it as a parent.</p>
<p>Maps to the <code><a href="https://schema.org/Place" target="_blank">Place</a>.<a href="https://schema.org/containedIn" target="_blank">containedIn</a></code> Schema.org property.</p>');
  t('Address');
  t('An image that represents the place. Maps to <a href="https://schema.org/Place" target="_blank">schema.org <code>Place.image</code></a> as an ImageObject where:<br />
<ul>
<li>Image maps to ImageObject.<a href="https://schema.org/contentUrl">contentUrl</a></li>
<li>Alternate Text maps to ImageObject.<a href="https://schema.org/alternateName">alternateName</a></li>
<li>Title maps to ImageObject.<a href="https://schema.org/caption">caption</a></li>
</ul>');
  t('Description');
  t('Geolocation');
  t('Image');
  t('Opening hours');
  t('Place parents');
  t('Venues');

  return $field_instances;
}
