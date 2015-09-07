<?php
/**
 * @file
 * oe_event.user_permission.inc
 */

function oe_event_user_permissions(){
    $auth_permissions = array(
        'oe_event' => array(
          // permission automatically created by the restws module
          'access resource event',
          // permissions automatically created by creation of the content type
          'create event content',
          'delete any event content',
          'delete own event content',
          'edit any event content',
          'edit own event content'
        ),
    );
    oe_components_grant_permissions(DRUPAL_AUTHENTICATED_RID, $auth_permissions);
    // user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, $permissions);

    $anon_permissions = array(
        'oe_event' => array(
          // permission automatically created by the restws module
          'access resource event'
        ),
    );
    oe_components_grant_permissions(DRUPAL_ANONYMOUS_RID, $anon_permissions);
}
