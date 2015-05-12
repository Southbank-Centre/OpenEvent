<?php
/**
 * @file
 * oe_person.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oe_person_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access relations'.
  $permissions['access relations'] = array(
    'name' => 'access relations',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'relation',
  );

  // Exported permission: 'add terms in person_title'.
  $permissions['add terms in person_title'] = array(
    'name' => 'add terms in person_title',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'create person content'.
  $permissions['create person content'] = array(
    'name' => 'create person content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any person content'.
  $permissions['delete any person content'] = array(
    'name' => 'delete any person content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own person content'.
  $permissions['delete own person content'] = array(
    'name' => 'delete own person content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in person_title'.
  $permissions['delete terms in person_title'] = array(
    'name' => 'delete terms in person_title',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any person content'.
  $permissions['edit any person content'] = array(
    'name' => 'edit any person content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own person content'.
  $permissions['edit own person content'] = array(
    'name' => 'edit own person content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in person_title'.
  $permissions['edit terms in person_title'] = array(
    'name' => 'edit terms in person_title',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'view any unpublished person content'.
  $permissions['view any unpublished person content'] = array(
    'name' => 'view any unpublished person content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
