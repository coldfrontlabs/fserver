<?php
/**
 * @file
 * fserver.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fserver_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'fserver_projects';
  $view->description = 'List of projects and their release information';
  $view->tag = 'default';
  $view->base_table = 'eck_project';
  $view->human_name = 'Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Project: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_project';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Project: Name */
  $handler->display->display_options['fields']['short_name']['id'] = 'short_name';
  $handler->display->display_options['fields']['short_name']['table'] = 'eck_project';
  $handler->display->display_options['fields']['short_name']['field'] = 'short_name';
  $handler->display->display_options['fields']['short_name']['label'] = '';
  $handler->display->display_options['fields']['short_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['short_name']['hide_empty'] = TRUE;
  /* Field: Project: API Version */
  $handler->display->display_options['fields']['api_version']['id'] = 'api_version';
  $handler->display->display_options['fields']['api_version']['table'] = 'eck_project';
  $handler->display->display_options['fields']['api_version']['field'] = 'api_version';
  $handler->display->display_options['fields']['api_version']['label'] = '';
  $handler->display->display_options['fields']['api_version']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['api_version']['hide_empty'] = TRUE;
  /* Field: Project: Project Status */
  $handler->display->display_options['fields']['project_status']['id'] = 'project_status';
  $handler->display->display_options['fields']['project_status']['table'] = 'eck_project';
  $handler->display->display_options['fields']['project_status']['field'] = 'project_status';
  $handler->display->display_options['fields']['project_status']['label'] = '';
  $handler->display->display_options['fields']['project_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['project_status']['hide_empty'] = TRUE;
  /* Field: Project: project type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'eck_project';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['hide_empty'] = TRUE;
  /* Field: Project: Supported Majors */
  $handler->display->display_options['fields']['supported_majors']['id'] = 'supported_majors';
  $handler->display->display_options['fields']['supported_majors']['table'] = 'eck_project';
  $handler->display->display_options['fields']['supported_majors']['field'] = 'supported_majors';
  $handler->display->display_options['fields']['supported_majors']['label'] = '';
  $handler->display->display_options['fields']['supported_majors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['supported_majors']['hide_empty'] = TRUE;
  /* Field: Project: Recommended Major */
  $handler->display->display_options['fields']['recommended_major']['id'] = 'recommended_major';
  $handler->display->display_options['fields']['recommended_major']['table'] = 'eck_project';
  $handler->display->display_options['fields']['recommended_major']['field'] = 'recommended_major';
  $handler->display->display_options['fields']['recommended_major']['label'] = '';
  $handler->display->display_options['fields']['recommended_major']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['recommended_major']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['recommended_major']['separator'] = '';
  /* Field: Project: Releases */
  $handler->display->display_options['fields']['field_project_releases']['id'] = 'field_project_releases';
  $handler->display->display_options['fields']['field_project_releases']['table'] = 'field_data_field_project_releases';
  $handler->display->display_options['fields']['field_project_releases']['field'] = 'field_project_releases';
  $handler->display->display_options['fields']['field_project_releases']['label'] = '';
  $handler->display->display_options['fields']['field_project_releases']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_releases']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_project_releases']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_project_releases']['delta_offset'] = '0';
  /* Contextual filter: Project: Name */
  $handler->display->display_options['arguments']['short_name']['id'] = 'short_name';
  $handler->display->display_options['arguments']['short_name']['table'] = 'eck_project';
  $handler->display->display_options['arguments']['short_name']['field'] = 'short_name';
  $handler->display->display_options['arguments']['short_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['short_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['short_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['short_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['short_name']['limit'] = '0';
  /* Contextual filter: Project: API Version */
  $handler->display->display_options['arguments']['api_version']['id'] = 'api_version';
  $handler->display->display_options['arguments']['api_version']['table'] = 'eck_project';
  $handler->display->display_options['arguments']['api_version']['field'] = 'api_version';
  $handler->display->display_options['arguments']['api_version']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['api_version']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['api_version']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['api_version']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['api_version']['limit'] = '0';

  /* Display: Projects XML */
  $handler = $view->new_display('views_data_export', 'Projects XML', 'fserver_projects_xml');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['transform_type'] = 'underline';
  $handler->display->display_options['path'] = 'fserver/%/%';
  $handler->display->display_options['use_batch'] = 'batch';
  $translatables['fserver_projects'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('.'),
    t('All'),
    t('Projects XML'),
  );
  $export['fserver_projects'] = $view;

  return $export;
}
