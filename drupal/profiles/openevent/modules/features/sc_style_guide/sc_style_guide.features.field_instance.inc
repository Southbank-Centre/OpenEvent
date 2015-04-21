<?php
/**
 * @file
 * sc_style_guide.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function sc_style_guide_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-style_guide_page-field_components'
  $field_instances['node-style_guide_page-field_components'] = array(
    'bundle' => 'style_guide_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The blocks of components that make up the content of this page. To create an anchor link at the top of a style guide page, create a <strong>Heading</strong> paragraph with a <em>Heading level</em> set to <em>Heading 2</em>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
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
    'field_name' => 'field_components',
    'label' => 'Components',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'flickr' => -1,
        'heading' => 'heading',
        'html' => 'html',
        'link' => -1,
        'long_text' => 'long_text',
        'page_element_spec' => 'page_element_spec',
        'quote' => -1,
        'soundcloud' => -1,
        'storify' => -1,
        'youtube' => -1,
      ),
      'bundle_weights' => array(
        'flickr' => 2,
        'heading' => 3,
        'html' => 4,
        'link' => 5,
        'long_text' => 6,
        'page_element_spec' => 7,
        'quote' => 8,
        'soundcloud' => 9,
        'storify' => 10,
        'youtube' => -10,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-page_element_spec-field_css_properties'
  $field_instances['paragraphs_item-page_element_spec-field_css_properties'] = array(
    'bundle' => 'page_element_spec',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'CSS properties and their values. Although not necessary, it is best to use actual CSS property names here, as the content of this field could be used to generate actual CSS.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'double_field',
        'settings' => array(
          'first' => array(
            'format' => '_none',
            'hidden' => 0,
            'prefix' => '',
            'suffix' => ':&nbsp;',
          ),
          'second' => array(
            'format' => '_none',
            'hidden' => 0,
            'prefix' => '',
            'suffix' => '',
          ),
          'style' => 'inline',
        ),
        'type' => 'double_field_unformatted_list',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_css_properties',
    'label' => 'CSS Properties',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'double_field',
      'settings' => array(
        'first' => array(
          'general' => array(
            'prefix' => '',
            'required' => 1,
            'suffix' => '',
          ),
          'textfield' => array(
            'placeholder' => 'Property name',
            'size' => 60,
          ),
        ),
        'inline' => 0,
        'second' => array(
          'general' => array(
            'prefix' => '',
            'required' => 1,
            'suffix' => '',
          ),
          'textfield' => array(
            'placeholder' => 'Property value',
            'size' => 60,
          ),
        ),
      ),
      'type' => 'textfield_&_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'paragraphs_item-page_element_spec-field_description'
  $field_instances['paragraphs_item-page_element_spec-field_description'] = array(
    'bundle' => 'page_element_spec',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 0,
          'iframe_html' => 0,
          'limited_html' => 0,
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

  // Exported field_instance: 'paragraphs_item-page_element_spec-field_html'
  $field_instances['paragraphs_item-page_element_spec-field_html'] = array(
    'bundle' => 'page_element_spec',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The HTML that constitutes the page element. The content of this field may also be used to generate a preview of the element on the page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_html',
    'label' => 'HTML',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 0,
          'full_html' => 'full_html',
          'iframe_html' => 0,
          'limited_html' => 0,
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
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('CSS Properties');
  t('CSS properties and their values. Although not necessary, it is best to use actual CSS property names here, as the content of this field could be used to generate actual CSS.');
  t('Components');
  t('Description');
  t('HTML');
  t('The HTML that constitutes the page element. The content of this field may also be used to generate a preview of the element on the page.');
  t('The blocks of components that make up the content of this page. To create an anchor link at the top of a style guide page, create a <strong>Heading</strong> paragraph with a <em>Heading level</em> set to <em>Heading 2</em>.');

  return $field_instances;
}
