<?php
/**
 * @file
 * oe_place.user_permission.inc
 */

function oe_place_user_permissions(){
    $auth_permissions = array(
        'oe_place' => array(
          // permission automatically created by the restws module
          'access resource place',
          // permissions automatically created by the creation of content type
          'create place content',
          'delete any place content',
          'delete own place content',
          'edit any place content',
          'edit own place content'
        ),
    );
    oe_components_grant_permissions(DRUPAL_AUTHENTICATED_RID, $auth_permissions);

    $anon_permissions = array(
        'oe_place' => array(
          // permission automatically created by the restws module
          'access resource place'
        ),
    );
    oe_components_grant_permissions(DRUPAL_ANONYMOUS_RID, $anon_permissions);
}
