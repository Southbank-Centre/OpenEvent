<?php
/**
 * @file
 * sc_style_guide.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function sc_style_guide_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-style-guide.
  $menus['menu-style-guide'] = array(
    'menu_name' => 'menu-style-guide',
    'title' => 'Style guide',
    'description' => 'Defines the structure of the Style guide menu. You can add section headings to the menu by setting the link for a menu item to <firstchild>, then adding Style guide pages as children of that item.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Defines the structure of the Style guide menu. You can add section headings to the menu by setting the link for a menu item to <firstchild>, then adding Style guide pages as children of that item.');
  t('Style guide');


  return $menus;
}
