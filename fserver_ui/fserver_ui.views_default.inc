<?php
/**
 * @file
 * fserver_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fserver_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'fserver_ui_projects';
  $view->description = 'List of projects';
  $view->tag = 'default';
  $view->base_table = 'eck_project';
  $view->human_name = 'Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No projects available.';
  /* Field: Project: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_project';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Project: Link */
  $handler->display->display_options['fields']['view_link']['id'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['table'] = 'eck_project';
  $handler->display->display_options['fields']['view_link']['field'] = 'view_link';
  /* Field: Project: Name */
  $handler->display->display_options['fields']['short_name']['id'] = 'short_name';
  $handler->display->display_options['fields']['short_name']['table'] = 'eck_project';
  $handler->display->display_options['fields']['short_name']['field'] = 'short_name';
  /* Field: Project: Project Status */
  $handler->display->display_options['fields']['project_status']['id'] = 'project_status';
  $handler->display->display_options['fields']['project_status']['table'] = 'eck_project';
  $handler->display->display_options['fields']['project_status']['field'] = 'project_status';
  /* Field: Project: project type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'eck_project';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Project: Recommended Major */
  $handler->display->display_options['fields']['recommended_major']['id'] = 'recommended_major';
  $handler->display->display_options['fields']['recommended_major']['table'] = 'eck_project';
  $handler->display->display_options['fields']['recommended_major']['field'] = 'recommended_major';
  /* Field: Project: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_project';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Sort criterion: Project: Name */
  $handler->display->display_options['sorts']['short_name']['id'] = 'short_name';
  $handler->display->display_options['sorts']['short_name']['table'] = 'eck_project';
  $handler->display->display_options['sorts']['short_name']['field'] = 'short_name';
  $handler->display->display_options['sorts']['short_name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['short_name']['expose']['label'] = 'Name';
  /* Sort criterion: Project: project type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'eck_project';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
  $handler->display->display_options['sorts']['type']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['type']['expose']['label'] = 'Type';
  /* Filter criterion: Project type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_project';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Project type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Project: Compatibility (field_compatibility) */
  $handler->display->display_options['filters']['field_compatibility_value']['id'] = 'field_compatibility_value';
  $handler->display->display_options['filters']['field_compatibility_value']['table'] = 'field_data_field_compatibility';
  $handler->display->display_options['filters']['field_compatibility_value']['field'] = 'field_compatibility_value';
  $handler->display->display_options['filters']['field_compatibility_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_compatibility_value']['expose']['operator_id'] = 'field_compatibility_value_op';
  $handler->display->display_options['filters']['field_compatibility_value']['expose']['label'] = 'Compatibility';
  $handler->display->display_options['filters']['field_compatibility_value']['expose']['operator'] = 'field_compatibility_value_op';
  $handler->display->display_options['filters']['field_compatibility_value']['expose']['identifier'] = 'field_compatibility_value';
  $handler->display->display_options['filters']['field_compatibility_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Projects Page */
  $handler = $view->new_display('page', 'Projects Page', 'fserver_ui_projects');
  $handler->display->display_options['path'] = 'fserver/project-list';
  $translatables['fserver_ui_projects'] = array(
    t('Master'),
    t('Projects'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No projects available.'),
    t('Id'),
    t('.'),
    t(','),
    t('Link'),
    t('Name'),
    t('Project Status'),
    t('project type'),
    t('Recommended Major'),
    t('Title'),
    t('Type'),
    t('Compatibility'),
    t('Projects Page'),
  );
  $export['fserver_ui_projects'] = $view;

  $view = new view();
  $view->name = 'fserver_ui_releases';
  $view->description = 'List of releases for a given project.';
  $view->tag = 'Fserver UI';
  $view->base_table = 'eck_release';
  $view->human_name = 'Releases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Releases';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'date' => 'date',
    'field_release_files' => 'field_release_files',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_release_files' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No releases available.';
  /* Field: Release: name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'eck_release';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Release: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'eck_release';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['date_format'] = 'short';
  /* Field: Release: File */
  $handler->display->display_options['fields']['field_release_files']['id'] = 'field_release_files';
  $handler->display->display_options['fields']['field_release_files']['table'] = 'field_data_field_release_files';
  $handler->display->display_options['fields']['field_release_files']['field'] = 'field_release_files';
  $handler->display->display_options['fields']['field_release_files']['label'] = '';
  $handler->display->display_options['fields']['field_release_files']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_release_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_release_files']['type'] = 'file_table';
  $handler->display->display_options['fields']['field_release_files']['delta_offset'] = '0';

  /* Display: Releases Bock */
  $handler = $view->new_display('block', 'Releases Bock', 'fserver_ui_block_releases');
  $handler->display->display_options['display_description'] = 'List of releases for a given project';
  $translatables['fserver_ui_releases'] = array(
    t('Master'),
    t('Releases'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No releases available.'),
    t('Releases Bock'),
    t('List of releases for a given project'),
  );
  $export['fserver_ui_releases'] = $view;

  return $export;
}