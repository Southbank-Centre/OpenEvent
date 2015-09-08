<?php
/**
 * @file
 * oe_person.user_permission.inc
 */

/**
 * Grant user permissions for Persons.
 */
function oe_person_user_permissions() {
  $auth_permissions = array(
    'oe_person' => array(
          // Permission automatically created by the restws module.
      'access resource person',
          // Permissions automatically created by the creation of content type.
      'create person content',
      'delete any person content',
      'delete own person content',
      'edit any person content',
      'edit own person content',
    ),
  );
  oe_components_grant_permissions(DRUPAL_AUTHENTICATED_RID, $auth_permissions);

  $anon_permissions = array(
    'oe_person' => array(
          // Permission automatically created by the restws module.
      'access resource person',
    ),
  );
  oe_components_grant_permissions(DRUPAL_ANONYMOUS_RID, $anon_permissions);
}
