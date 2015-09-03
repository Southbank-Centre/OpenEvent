<?php
/**
 * @file
 * oe_organization.user_permission.inc
 */

function oe_organization_user_permissions(){
    $auth_permissions = array(
        // module key
        'oe_organization' => array(
           // permissions in the module
          'access resource organization',
          'create organization content',
          'delete any organization content',
          'delete own organization content',
          'edit any organization content',
          'edit own organization content'
        ),
    );
    oe_grant_permissions(DRUPAL_AUTHENTICATED_RID, $auth_permissions);
    // user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, $permissions);

    $anon_permissions = array(
        // module key
        'oe_organization' => array(
           // permissions in the module
          'access resource organization'
        ),
    );
    oe_grant_permissions(DRUPAL_ANONYMOUS_RID, $anon_permissions);
}
