<?php
/**
 * @file
 * sc_components.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function sc_components_paragraphs_info() {
  $items = array(
    'flickr_embed' => array(
      'name' => 'Flickr embed',
      'bundle' => 'flickr_embed',
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
    'soundcloud_embed' => array(
      'name' => 'SoundCloud embed',
      'bundle' => 'soundcloud_embed',
      'locked' => '1',
    ),
    'storify_embed' => array(
      'name' => 'Storify embed',
      'bundle' => 'storify_embed',
      'locked' => '1',
    ),
    'youtube_embed' => array(
      'name' => 'YouTube embed',
      'bundle' => 'youtube_embed',
      'locked' => '1',
    ),
  );
  return $items;
}
