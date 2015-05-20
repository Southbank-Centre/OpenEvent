<?php
/**
 * @file
 * sc_style_guide.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function sc_style_guide_user_default_roles() {
  $roles = array();

  // Exported role: designer.
  $roles['designer'] = array(
    'name' => 'designer',
    'weight' => 3,
  );

  return $roles;
}
