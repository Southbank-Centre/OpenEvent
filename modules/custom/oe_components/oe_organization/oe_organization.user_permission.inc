<?php
/**
 * @file
 * oe_organization.user_permission.inc
 */

function oe_organization_user_permissions(){
    $auth_permissions = array(
        'oe_organization' => array(
          // permission automatically created by the restws module
          'access resource organization',
          // permissions automatically created by the creation of content type
          'create organization content',
          'delete any organization content',
          'delete own organization content',
          'edit any organization content',
          'edit own organization content'
        ),
    );
    oe_components_grant_permissions(DRUPAL_AUTHENTICATED_RID, $auth_permissions);

    $anon_permissions = array(
        'oe_organization' => array(
          // permission automatically created by the restws module
          'access resource organization'
        ),
    );
    oe_components_grant_permissions(DRUPAL_ANONYMOUS_RID, $anon_permissions);
}
