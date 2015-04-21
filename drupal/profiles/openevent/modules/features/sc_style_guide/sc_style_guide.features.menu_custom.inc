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
    'description' => 'A menu for managing the ordering of style guide chapters',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('A menu for managing the ordering of style guide chapters');
  t('Style guide');


  return $menus;
}
