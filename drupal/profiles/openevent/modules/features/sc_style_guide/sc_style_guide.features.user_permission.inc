<?php
/**
 * @file
 * sc_style_guide.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function sc_style_guide_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create style_guide_page content'.
  $permissions['create style_guide_page content'] = array(
    'name' => 'create style_guide_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any style_guide_page content'.
  $permissions['delete any style_guide_page content'] = array(
    'name' => 'delete any style_guide_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own style_guide_page content'.
  $permissions['delete own style_guide_page content'] = array(
    'name' => 'delete own style_guide_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any style_guide_page content'.
  $permissions['edit any style_guide_page content'] = array(
    'name' => 'edit any style_guide_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own style_guide_page content'.
  $permissions['edit own style_guide_page content'] = array(
    'name' => 'edit own style_guide_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'use text format style_guide_html'.
  $permissions['use text format style_guide_html'] = array(
    'name' => 'use text format style_guide_html',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
