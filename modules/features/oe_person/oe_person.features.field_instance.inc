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

  // Exported field_instance: 'node-person-field_description'
  $field_instances['node-person-field_description'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>A short description or biography of the person.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/description" target="_blank">description</a></code> Schema.org property.</p>',
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

  // Exported field_instance: 'node-person-field_person_awards'
  $field_instances['node-person-field_person_awards'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>Awards won by this person for his/her work. Enter one award per line.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/award" target="_blank">award</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_person_awards',
    'label' => 'Awards',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
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

  // Exported field_instance: 'node-person-field_person_email'
  $field_instances['node-person-field_person_email'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>The email address of the person.</p>
<p>Maps to the <code><a href="https://schema.org/Person" target="_blank">Person</a>.<a href="https://schema.org/email" target="_blank">email</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
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
    'field_name' => 'field_person_email',
    'label' => 'Email address',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 255,
      ),
      'type' => 'email_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-person-field_person_job'
  $field_instances['node-person-field_person_job'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>Job titles of the person. Multiple values can be entered, and should be separated by commas.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/jobTitle" target="_blank">jobTitle</a></code> Schema.org property.</p>',
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
    'field_name' => 'field_person_job',
    'label' => 'Job title',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
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
    'description' => '<p>An alias for the person.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/alternateName" target="_blank">alternateName</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
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
    'description' => '<p>Surname of a person.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/familyName" target="_blank">familyName</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_person_name_family',
    'label' => 'Family name',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
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
    'description' => '<p>First name of a person.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/givenName" target="_blank">givenName</a></code> Schema.org property.</p>',
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
    'field_name' => 'field_person_name_given',
    'label' => 'Given name',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
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
    'description' => '<p>A name between the given name and the family name.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/additionalName" target="_blank">additionalName</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_person_name_middle',
    'label' => 'Middle name',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
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
    'description' => '<p>Name title preceding the name.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/honorificPrefix" target="_blank">honorificPrefix</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
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
    'description' => '<p>An honorific suffix for a Person\'s name such as M.D./PhD/MSCSW. It follows a person\'s full name and provides additional information about the person. Post-nominal letters indicate that the individual holds a position, educational degree, accreditation, office, or honour.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/honorificSuffix" target="_blank">honorificSuffix</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_person_name_suffix',
    'label' => 'Suffix',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
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

  // Exported field_instance: 'node-person-field_person_same_as'
  $field_instances['node-person-field_person_same_as'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>URL of a reference web page that unambiguously indicates the person\'s identity. E.g. the URL of the person\'s Wikipedia page or official website. Multiple URLs can be provided.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/sameAs" target="_blank">sameAs</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
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
    'field_name' => 'field_person_same_as',
    'label' => 'Person links',
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
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>A name between the given name and the family name.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/additionalName" target="_blank">additionalName</a></code> Schema.org property.</p>');
  t('<p>A short description or biography of the person.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/description" target="_blank">description</a></code> Schema.org property.</p>');
  t('<p>An alias for the person.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/alternateName" target="_blank">alternateName</a></code> Schema.org property.</p>');
  t('<p>An honorific suffix for a Person\'s name such as M.D./PhD/MSCSW. It follows a person\'s full name and provides additional information about the person. Post-nominal letters indicate that the individual holds a position, educational degree, accreditation, office, or honour.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/honorificSuffix" target="_blank">honorificSuffix</a></code> Schema.org property.</p>');
  t('<p>Awards won by this person for his/her work. Enter one award per line.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/award" target="_blank">award</a></code> Schema.org property.</p>');
  t('<p>First name of a person.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/givenName" target="_blank">givenName</a></code> Schema.org property.</p>');
  t('<p>Job titles of the person. Multiple values can be entered, and should be separated by commas.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/jobTitle" target="_blank">jobTitle</a></code> Schema.org property.</p>');
  t('<p>Name title preceding the name.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/honorificPrefix" target="_blank">honorificPrefix</a></code> Schema.org property.</p>');
  t('<p>Surname of a person.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/familyName" target="_blank">familyName</a></code> Schema.org property.</p>');
  t('<p>The email address of the person.</p>
<p>Maps to the <code><a href="https://schema.org/Person" target="_blank">Person</a>.<a href="https://schema.org/email" target="_blank">email</a></code> Schema.org property.</p>');
  t('<p>URL of a reference web page that unambiguously indicates the person\'s identity. E.g. the URL of the person\'s Wikipedia page or official website. Multiple URLs can be provided.</p>
<p>Maps to the <code><a href="http://schema.org/Person" target="_blank">Person</a>.<a href="http://schema.org/sameAs" target="_blank">sameAs</a></code> Schema.org property.</p>');
  t('Alias');
  t('Awards');
  t('Description');
  t('Email address');
  t('Family name');
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
  t('Middle name');
  t('Person links');
  t('Prefix');
  t('Suffix');

  return $field_instances;
}
