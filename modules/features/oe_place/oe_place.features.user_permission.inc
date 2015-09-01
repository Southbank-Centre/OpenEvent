<?php
/**
 * @file
 * oe_place.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oe_place_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access resource place'.
  $permissions['access resource place'] = array(
    'name' => 'access resource place',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'restws',
  );

  // Exported permission: 'create place content'.
  $permissions['create place content'] = array(
    'name' => 'create place content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any place content'.
  $permissions['delete any place content'] = array(
    'name' => 'delete any place content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own place content'.
  $permissions['delete own place content'] = array(
    'name' => 'delete own place content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any place content'.
  $permissions['edit any place content'] = array(
    'name' => 'edit any place content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own place content'.
  $permissions['edit own place content'] = array(
    'name' => 'edit own place content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
