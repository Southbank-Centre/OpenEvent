<?php
/**
 * @file
 * oe_event.user_permission.inc
 */

function oe_event_user_permissions(){
    $auth_permissions = array(
        // module key
        'oe_event' => array(
           // permissions in the module
          'access resource event',
          'create event content',
          'delete any event content',
          'delete own event content',
          'edit any event content',
          'edit own event content'
        ),
    );
    oe_grant_permissions(DRUPAL_AUTHENTICATED_RID, $auth_permissions);
    // user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, $permissions);

    $anon_permissions = array(
        // module key
        'oe_event' => array(
           // permissions in the module
          'access resource event'
        ),
    );
    oe_grant_permissions(DRUPAL_ANONYMOUS_RID, $anon_permissions);
}
