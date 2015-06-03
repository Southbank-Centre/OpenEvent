<?php
/**
 * @file
 * oe_person.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function oe_person_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-event-field_event_performers'
  $field_instances['node-event-field_event_performers'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => 'Performers at the event—for example, a presenter, musician, musical group or actor.<br/>
Maps to <a href="http://schema.org/performer" target="_blank"><code>Event:performer</code></a> in Schema.org.',
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
    'field_name' => 'field_event_performers',
    'label' => 'Performers',
    'required' => 0,
    'settings' => array(
      'relation_target_bundles' => array(
        'node:person' => 'node:person',
      ),
      'relation_type' => array(
        'performs_in:reverse' => 'performs_in:reverse',
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
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-person-field_description'
  $field_instances['node-person-field_description'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A short description of the person.<br/>
Maps to <a href="http://schema.org/description" target="_blank"><code>Person:description</code></a> in Schema.org.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 0,
          'iframe_html' => 0,
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
            'iframe_html' => array(
              'weight' => -8,
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-person-field_image'
  $field_instances['node-person-field_image'] = array(
    'bundle' => 'person',
    'deleted' => 0,
    'description' => 'Image or photo from the person. Multiple images are allowed.<br/>
Maps to <a href="http://schema.org/image" target="_blank"><code>Person:image</code></a> in Schema.org as an ImageObject where:<br />
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-person-field_person_awards'
  $field_instances['node-person-field_person_awards'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Awards won by this person or his/her creative work. One award per line.<br/>
Maps to <a href="http://schema.org/award" target="_blank"><code>Person:award</code></a> in Schema.org.',
    'display' => array(
      'default' => array(
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
    'field_name' => 'field_person_awards',
    'label' => 'Awards',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'iframe_html' => 'iframe_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'iframe_html' => array(
              'weight' => -8,
            ),
            'plain_text' => array(
              'weight' => -7,
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-person-field_person_events'
  $field_instances['node-person-field_person_events'] = array(
    'bundle' => 'person',
    'deleted' => 0,
    'description' => 'Events in which this person is a performer.<br/>
Maps to <a href="http://schema.org/performerIn" target="_blank"><code>Person:performerIn</code></a> in Schema.org.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'relation_add',
        'settings' => array(),
        'type' => 'relation_add_endpoints_and_fields',
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
    'field_name' => 'field_person_events',
    'label' => 'Events',
    'required' => 0,
    'settings' => array(
      'relation_target_bundles' => array(
        'node:event' => 'node:event',
      ),
      'relation_type' => array(
        'performs_in' => 'performs_in',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-person-field_person_job'
  $field_instances['node-person-field_person_job'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Job titles of the person.<br/>
Multiple values separated by commas. Maps to <a href="http://schema.org/jobTitle" target="_blank"><code>Person:jobTitle</code></a> in Schema.org.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_person_job',
    'label' => 'Job title',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'iframe_html' => 'iframe_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'iframe_html' => array(
              'weight' => -8,
            ),
            'plain_text' => array(
              'weight' => -7,
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-person-field_person_name_alias'
  $field_instances['node-person-field_person_name_alias'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'An alias for the person.<br/>
Maps to <a href="http://schema.org/alternateName" target="_blank"><code>Person:alternateName</code></a> in Schema.org.',
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
    'field_name' => 'field_person_name_alias',
    'label' => 'Alias',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'iframe_html' => 'iframe_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'iframe_html' => array(
              'weight' => -8,
            ),
            'plain_text' => array(
              'weight' => -7,
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
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-person-field_person_name_family'
  $field_instances['node-person-field_person_name_family'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Surname of a person.<br/>
Maps to <a href="http://schema.org/familyName" target="_blank"><code>Person:familyName</code></a> in Schema.org.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_person_name_family',
    'label' => 'Family name',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'iframe_html' => 'iframe_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'iframe_html' => array(
              'weight' => -8,
            ),
            'plain_text' => array(
              'weight' => -7,
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-person-field_person_name_given'
  $field_instances['node-person-field_person_name_given'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'First name of a person.<br/>
Maps to <a href="http://schema.org/givenName" target="_blank"><code>Person:givenName</code></a> in Schema.org.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_person_name_given',
    'label' => 'Given name',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'iframe_html' => 'iframe_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'iframe_html' => array(
              'weight' => -8,
            ),
            'plain_text' => array(
              'weight' => -7,
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-person-field_person_name_middle'
  $field_instances['node-person-field_person_name_middle'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A name between the given name and the family name.<br/>
Maps to <a href="http://schema.org/additionalName" target="_blank"><code>Person:additionalName</code></a> in Schema.org.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_person_name_middle',
    'label' => 'Middle name',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'iframe_html' => 'iframe_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'iframe_html' => array(
              'weight' => -8,
            ),
            'plain_text' => array(
              'weight' => -7,
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-person-field_person_name_prefix'
  $field_instances['node-person-field_person_name_prefix'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Name title preceding the name.<br/>
Maps to <a href="http://schema.org/honorificPrefix" target="_blank"><code>Person:honorificPrefix</code></a> in Schema.org.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_person_name_prefix',
    'label' => 'Prefix',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-person-field_person_name_suffix'
  $field_instances['node-person-field_person_name_suffix'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'An honorific suffix for a Person\'s name such as M.D./PhD/MSCSW. It follows a person\'s full name and provides additional information about the person. Post-nominal letters indicate that the individual holds a position, educational degree, accreditation, office, or honour.<br/>
Maps to <a href="http://schema.org/honorificSuffix" target="_blank"><code>Person:honorificSuffix</code></a> in Schema.org.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_person_name_suffix',
    'label' => 'Suffix',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'iframe_html' => 'iframe_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -10,
            ),
            'full_html' => array(
              'weight' => -9,
            ),
            'iframe_html' => array(
              'weight' => -8,
            ),
            'plain_text' => array(
              'weight' => -7,
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-person-field_person_urls'
  $field_instances['node-person-field_person_urls'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'URL of a reference Web page that unambiguously indicates the person\'s identity. E.g. the URL of the person\'s Wikipedia page or official website. Multiple URLs can be provided.<br/>
Maps to <a href="http://schema.org/sameAs" target="_blank"><code>Person:sameAs</code></a> in Schema.org.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_person_urls',
    'label' => 'Person urls',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'relation-performs_in-endpoints'
  $field_instances['relation-performs_in-endpoints'] = array(
    'bundle' => 'performs_in',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'relation_endpoint',
        'settings' => array(
          'view_modes' => array(
            'cer' => 'default',
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
  t('A name between the given name and the family name.<br/>
Maps to <a href="http://schema.org/additionalName" target="_blank"><code>Person:additionalName</code></a> in Schema.org.');
  t('A short description of the person.<br/>
Maps to <a href="http://schema.org/description" target="_blank"><code>Person:description</code></a> in Schema.org.');
  t('Alias');
  t('An alias for the person.<br/>
Maps to <a href="http://schema.org/alternateName" target="_blank"><code>Person:alternateName</code></a> in Schema.org.');
  t('An honorific suffix for a Person\'s name such as M.D./PhD/MSCSW. It follows a person\'s full name and provides additional information about the person. Post-nominal letters indicate that the individual holds a position, educational degree, accreditation, office, or honour.<br/>
Maps to <a href="http://schema.org/honorificSuffix" target="_blank"><code>Person:honorificSuffix</code></a> in Schema.org.');
  t('Awards');
  t('Awards won by this person or his/her creative work. One award per line.<br/>
Maps to <a href="http://schema.org/award" target="_blank"><code>Person:award</code></a> in Schema.org.');
  t('Description');
  t('Events');
  t('Events in which this person is a performer.<br/>
Maps to <a href="http://schema.org/performerIn" target="_blank"><code>Person:performerIn</code></a> in Schema.org.');
  t('Family name');
  t('First name of a person.<br/>
Maps to <a href="http://schema.org/givenName" target="_blank"><code>Person:givenName</code></a> in Schema.org.');
  t('Given name');
  t('Image');
  t('Image or photo from the person. Multiple images are allowed.<br/>
Maps to <a href="http://schema.org/image" target="_blank"><code>Person:image</code></a> in Schema.org as an ImageObject where:<br />
<ul>
<li>Image maps to ImageObject.<a href="https://schema.org/contentUrl">contentUrl</a></li>
<li>Alternate Text maps to ImageObject.<a href="https://schema.org/alternateName">alternateName</a></li>
<li>Title maps to ImageObject.<a href="https://schema.org/caption">caption</a></li>
</ul>');
  t('Job title');
  t('Job titles of the person.<br/>
Multiple values separated by commas. Maps to <a href="http://schema.org/jobTitle" target="_blank"><code>Person:jobTitle</code></a> in Schema.org.');
  t('Middle name');
  t('Name title preceding the name.<br/>
Maps to <a href="http://schema.org/honorificPrefix" target="_blank"><code>Person:honorificPrefix</code></a> in Schema.org.');
  t('Performers');
  t('Performers at the event—for example, a presenter, musician, musical group or actor.<br/>
Maps to <a href="http://schema.org/performer" target="_blank"><code>Event:performer</code></a> in Schema.org.');
  t('Person urls');
  t('Prefix');
  t('Suffix');
  t('Surname of a person.<br/>
Maps to <a href="http://schema.org/familyName" target="_blank"><code>Person:familyName</code></a> in Schema.org.');
  t('URL of a reference Web page that unambiguously indicates the person\'s identity. E.g. the URL of the person\'s Wikipedia page or official website. Multiple URLs can be provided.<br/>
Maps to <a href="http://schema.org/sameAs" target="_blank"><code>Person:sameAs</code></a> in Schema.org.');
  t('endpoints');

  return $field_instances;
}
