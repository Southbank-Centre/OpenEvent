<?php
/**
 * @file
 * oe_person.user_permission.inc
 */

function oe_person_user_permissions(){
    $auth_permissions = array(
        'oe_person' => array(
          // permission automatically created by the restws module
          'access resource person',
          // permissions automatically created by the creation of content type
          'create person content',
          'delete any person content',
          'delete own person content',
          'edit any person content',
          'edit own person content'
        ),
    );
    oe_components_grant_permissions(DRUPAL_AUTHENTICATED_RID, $auth_permissions);
    // user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, $permissions);

    $anon_permissions = array(
        'oe_person' => array(
          // permission automatically created by the restws module
          'access resource person'
        ),
    );
    oe_components_grant_permissions(DRUPAL_ANONYMOUS_RID, $anon_permissions);
}
