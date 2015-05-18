<?php
/**
 * @file
 * sc_components.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sc_components_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access resource paragraphs_item'.
  $permissions['access resource paragraphs_item'] = array(
    'name' => 'access resource paragraphs_item',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'restws',
  );

  // Exported permission: 'use text format iframe_html'.
  $permissions['use text format iframe_html'] = array(
    'name' => 'use text format iframe_html',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
