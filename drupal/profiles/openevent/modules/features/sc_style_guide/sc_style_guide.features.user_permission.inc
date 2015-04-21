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

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
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

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'designer' => 'designer',
    ),
    'module' => 'system',
  );

  return $permissions;
}
