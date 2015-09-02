<?php
/**
 * @file
 * oe_event.features.user_permission.inc
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
    oe_event_grant_permissions(DRUPAL_AUTHENTICATED_RID, $auth_permissions);
    // user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, $permissions);

    $anon_permissions = array(
        // module key
        'oe_event' => array(
           // permissions in the module
          'access resource event'
        ),
    );
    oe_event_grant_permissions(DRUPAL_ANONYMOUS_RID, $anon_permissions);
}


// function oe_event_user_permissions() {

//   user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array(
//     // 'access resource event'
//     'view own unpublished content'
//   ));
//   user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array(
//     // 'access resource event',
//     'create event content',
//     'delete any event content',
//     'delete own event content',
//     'edit any event content',
//     'edit own event content'
//   ));

// }
