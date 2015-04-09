<?php
/**
 * @file
 * oe_event.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function oe_event_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'event_parent';
  $view->description = 'Determines which events can be selected as parents, preventing circular references';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Event Parent';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Parents (field_event_parents) */
  $handler->display->display_options['arguments']['field_event_parents_target_id']['id'] = 'field_event_parents_target_id';
  $handler->display->display_options['arguments']['field_event_parents_target_id']['table'] = 'field_data_field_event_parents';
  $handler->display->display_options['arguments']['field_event_parents_target_id']['field'] = 'field_event_parents_target_id';
  $handler->display->display_options['arguments']['field_event_parents_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_event_parents_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_event_parents_target_id']['default_argument_options']['code'] = '$args = arg();
if (isset($args[6])) {
  return $args[6];
} else {
  return true;
}';
  $handler->display->display_options['arguments']['field_event_parents_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_event_parents_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_event_parents_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_event_parents_target_id']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['field_event_parents_target_id']['not'] = TRUE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = '$args = arg();
if (isset($args[6])) {
  return $args[6];
} else {
  return true;
}';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['event_parent'] = $view;

  return $export;
}
