<?php
/**
 * @file
 * oe_components.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oe_components_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function oe_components_paragraphs_info() {
  $items = array(
    'flickr' => array(
      'name' => 'Flickr',
      'bundle' => 'flickr',
      'locked' => '1',
    ),
    'heading' => array(
      'name' => 'Heading',
      'bundle' => 'heading',
      'locked' => '1',
    ),
    'html' => array(
      'name' => 'HTML',
      'bundle' => 'html',
      'locked' => '1',
    ),
    'image' => array(
      'name' => 'Image',
      'bundle' => 'image',
      'locked' => '1',
    ),
    'link' => array(
      'name' => 'Link',
      'bundle' => 'link',
      'locked' => '1',
    ),
    'long_text' => array(
      'name' => 'Long text',
      'bundle' => 'long_text',
      'locked' => '1',
    ),
    'quote' => array(
      'name' => 'Quote',
      'bundle' => 'quote',
      'locked' => '1',
    ),
    'soundcloud' => array(
      'name' => 'SoundCloud',
      'bundle' => 'soundcloud',
      'locked' => '1',
    ),
    'storify' => array(
      'name' => 'Storify',
      'bundle' => 'storify',
      'locked' => '1',
    ),
    'youtube' => array(
      'name' => 'YouTube',
      'bundle' => 'youtube',
      'locked' => '1',
    ),
  );
  return $items;
}
