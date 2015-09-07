<?php
/**
 * @file
 * oe_organization.field_instance.inc
 */

/**
 * Create field instances for use by the Organization content type.
 */
function oe_organization_field_instances() {

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
      'weight' => 3,
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
      'max_filesize' => '1 MB',
      'max_resolution' => '1280x720',
      'min_resolution' => '360x180',
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

  // Exported field_instance: 'node-organization-field_organization_address'
  $field_instances['node-organization-field_organization_address'] = array(
    'bundle' => 'organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>The address of the organization.</p>
<p>Maps to the <code><a href="https://schema.org/Organization" target="_blank">Organization</a>.<a href="https://schema.org/address" target="_blank">address</a></code> Schema.org property.</p>',
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
    'field_name' => 'field_organization_address',
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
        'default_country' => 'site_default',
        'format_handlers' => array(
          'address' => 'address',
          'organisation' => 'organisation',
          'address-optional' => 'address-optional',
          'address-hide-postal-code' => 0,
          'address-hide-street' => 0,
          'address-hide-country' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-organization-field_organization_email'
  $field_instances['node-organization-field_organization_email'] = array(
    'bundle' => 'organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>The email address of the organization.</p>
<p>Maps to the <code><a href="https://schema.org/Organization" target="_blank">Organization</a>.<a href="https://schema.org/email" target="_blank">email</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
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
    'field_name' => 'field_organization_email',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-organization-field_organization_legal_name'
  $field_instances['node-organization-field_organization_legal_name'] = array(
    'bundle' => 'organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>The official name of the organization. E.g. the registered company name.</p>
<p>Maps to the <code><a href="https://schema.org/Organization" target="_blank">Organization</a>.<a href="https://schema.org/legalName" target="_blank">legalName</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_organization_legal_name',
    'label' => 'Legal name',
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
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 255,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-organization-field_organization_logo'
  $field_instances['node-organization-field_organization_logo'] = array(
    'bundle' => 'organization',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
    'field_name' => 'field_organization_logo',
    'label' => 'Logo',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '1 MB',
      'max_resolution' => '720x360',
      'min_resolution' => '180x90',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-organization-field_organization_same_as'
  $field_instances['node-organization-field_organization_same_as'] = array(
    'bundle' => 'organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>URL of a reference Web page that indicates the organization\'s identity. E.g. the URL of the organization\'s Wikipedia page or official website.</p>
<p>Maps to the <code><a href="http://schema.org/Organization" target="_blank">Organization</a>.<a href="http://schema.org/sameAs" target="_blank">sameAs</a></code> Schema.org property.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_organization_same_as',
    'label' => 'Organization links',
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
      'enable_tokens' => 1,
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

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>A short description of the organization.</p>
<p>Maps to the <code><a href="http://schema.org/Organization" target="_blank">organization</a>.<a href="http://schema.org/description" target="_blank">description</a></code> Schema.org property.</p>');
  t('<p>Images that represent the organization. Multiple images are allowed.</p>
<p>Maps to the <code><a href="http://schema.org/Organization" target="_blank">organization</a>.<a href="http://schema.org/image" target="_blank">image</a></code> Schema.org property.');
  t('<p>The address of the organization.</p>
<p>Maps to the <code><a href="https://schema.org/Organization" target="_blank">Organization</a>.<a href="https://schema.org/address" target="_blank">address</a></code> Schema.org property.</p>');
  t('<p>The email address of the organization.</p>
<p>Maps to the <code><a href="https://schema.org/Organization" target="_blank">Organization</a>.<a href="https://schema.org/email" target="_blank">email</a></code> Schema.org property.</p>');
  t('<p>The official name of the organization. E.g. the registered company name.</p>
<p>Maps to the <code><a href="https://schema.org/Organization" target="_blank">Organization</a>.<a href="https://schema.org/legalName" target="_blank">legalName</a></code> Schema.org property.</p>');
  t('<p>URL of a reference Web page that indicates the organization\'s identity. E.g. the URL of the organization\'s Wikipedia page or official website.</p>
<p>Maps to the <code><a href="http://schema.org/Organization" target="_blank">Organization</a>.<a href="http://schema.org/sameAs" target="_blank">sameAs</a></code> Schema.org property.</p>');
  t('Address');
  t('Description');
  t('Email address');
  t('Image');
  t('Legal name');
  t('Logo');
  t('Organization links');

  foreach ($field_instances as $field_instance) {
    field_create_instance($field_instance);
  }

}
