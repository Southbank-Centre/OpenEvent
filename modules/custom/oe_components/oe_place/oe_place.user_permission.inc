<?php
/**
 * @file
 * oe_place.user_permission.inc
 */

function oe_place_user_permissions(){
    $auth_permissions = array(
        // module key
        'oe_place' => array(
           // permissions in the module
          'access resource place',
          'create place content',
          'delete any place content',
          'delete own place content',
          'edit any place content',
          'edit own place content'
        ),
    );
    oe_components_grant_permissions(DRUPAL_AUTHENTICATED_RID, $auth_permissions);
    // user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, $permissions);

    $anon_permissions = array(
        // module key
        'oe_place' => array(
           // permissions in the module
          'access resource place'
        ),
    );
    oe_components_grant_permissions(DRUPAL_ANONYMOUS_RID, $anon_permissions);
}
