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
  /* Field: ID (Hidden) */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_project';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['ui_name'] = 'ID (Hidden)';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Releases Placeholder (Hidden) */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['ui_name'] = 'Releases Placeholder (Hidden)';
  $handler->display->display_options['fields']['view']['label'] = 'Releases Placeholder';
  $handler->display->display_options['fields']['view']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['view']['view'] = 'fserver_releases';
  $handler->display->display_options['fields']['view']['display'] = 'fserver_releases_xml';
  $handler->display->display_options['fields']['view']['arguments'] = '[!id]';
  /* Field: Project: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_project';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Project: Name */
  $handler->display->display_options['fields']['short_name']['id'] = 'short_name';
  $handler->display->display_options['fields']['short_name']['table'] = 'eck_project';
  $handler->display->display_options['fields']['short_name']['field'] = 'short_name';
  $handler->display->display_options['fields']['short_name']['label'] = 'Short Name';
  $handler->display->display_options['fields']['short_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['short_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['short_name']['hide_empty'] = TRUE;
  /* Field: Project: API Version */
  $handler->display->display_options['fields']['api_version']['id'] = 'api_version';
  $handler->display->display_options['fields']['api_version']['table'] = 'eck_project';
  $handler->display->display_options['fields']['api_version']['field'] = 'api_version';
  $handler->display->display_options['fields']['api_version']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['api_version']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['api_version']['hide_empty'] = TRUE;
  /* Field: Project: Project Status */
  $handler->display->display_options['fields']['project_status']['id'] = 'project_status';
  $handler->display->display_options['fields']['project_status']['table'] = 'eck_project';
  $handler->display->display_options['fields']['project_status']['field'] = 'project_status';
  $handler->display->display_options['fields']['project_status']['label'] = 'project status';
  $handler->display->display_options['fields']['project_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['project_status']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['project_status']['hide_empty'] = TRUE;
  /* Field: Project: Supported Majors */
  $handler->display->display_options['fields']['supported_majors']['id'] = 'supported_majors';
  $handler->display->display_options['fields']['supported_majors']['table'] = 'eck_project';
  $handler->display->display_options['fields']['supported_majors']['field'] = 'supported_majors';
  $handler->display->display_options['fields']['supported_majors']['label'] = 'supported majors';
  $handler->display->display_options['fields']['supported_majors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['supported_majors']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['supported_majors']['hide_empty'] = TRUE;
  /* Field: Project: Recommended Major */
  $handler->display->display_options['fields']['recommended_major']['id'] = 'recommended_major';
  $handler->display->display_options['fields']['recommended_major']['table'] = 'eck_project';
  $handler->display->display_options['fields']['recommended_major']['field'] = 'recommended_major';
  $handler->display->display_options['fields']['recommended_major']['label'] = 'recommended major';
  $handler->display->display_options['fields']['recommended_major']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['recommended_major']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['recommended_major']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['recommended_major']['separator'] = '';
  /* Field: Releases Display */
  $handler->display->display_options['fields']['raw_xml']['id'] = 'raw_xml';
  $handler->display->display_options['fields']['raw_xml']['table'] = 'views_data_export_global';
  $handler->display->display_options['fields']['raw_xml']['field'] = 'raw_xml';
  $handler->display->display_options['fields']['raw_xml']['ui_name'] = 'Releases Display';
  $handler->display->display_options['fields']['raw_xml']['label'] = '';
  $handler->display->display_options['fields']['raw_xml']['alter']['text'] = '[view]';
  $handler->display->display_options['fields']['raw_xml']['element_label_colon'] = FALSE;
  /* Contextual filter: Project: Name */
  $handler->display->display_options['arguments']['short_name']['id'] = 'short_name';
  $handler->display->display_options['arguments']['short_name']['table'] = 'eck_project';
  $handler->display->display_options['arguments']['short_name']['field'] = 'short_name';
  $handler->display->display_options['arguments']['short_name']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['short_name']['exception']['value'] = 'project-list';
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
  $handler->display->display_options['style_options']['custom_root_node'] = 'projects';
  $handler->display->display_options['style_options']['custom_item_node'] = 'project';
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['transform_type'] = 'underline';
  $handler->display->display_options['style_options']['transform_case'] = 'lowercase';
  $handler->display->display_options['path'] = 'fserver/%/%';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['fserver_projects'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('.'),
    t('Releases Placeholder'),
    t('Title'),
    t('Short Name'),
    t('API Version'),
    t('project status'),
    t('supported majors'),
    t('recommended major'),
    t('[view]'),
    t('All'),
    t('Projects XML'),
  );
  $export['fserver_projects'] = $view;

  $view = new view();
  $view->name = 'fserver_releases';
  $view->description = 'Lists releases for a given project. This view is not meant to be consumed directly.';
  $view->tag = 'default';
  $view->base_table = 'eck_release';
  $view->human_name = 'Releases';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_release_files_2']['id'] = 'field_release_files_2';
  $handler->display->display_options['fields']['field_release_files_2']['table'] = 'field_data_field_release_files';
  $handler->display->display_options['fields']['field_release_files_2']['field'] = 'field_release_files';
  $handler->display->display_options['fields']['field_release_files_2']['ui_name'] = 'Release Files (Hidden)';
  $handler->display->display_options['fields']['field_release_files_2']['label'] = 'Files';
  $handler->display->display_options['fields']['field_release_files_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_release_files_2']['element_label_colon'] = FALSE;
  /* Field: Release: name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'eck_release';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Name';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Release: Version */
  $handler->display->display_options['fields']['version']['id'] = 'version';
  $handler->display->display_options['fields']['version']['table'] = 'eck_release';
  $handler->display->display_options['fields']['version']['field'] = 'version';
  $handler->display->display_options['fields']['version']['element_label_colon'] = FALSE;
  /* Field: Release: Version Major */
  $handler->display->display_options['fields']['version_major']['id'] = 'version_major';
  $handler->display->display_options['fields']['version_major']['table'] = 'eck_release';
  $handler->display->display_options['fields']['version_major']['field'] = 'version_major';
  $handler->display->display_options['fields']['version_major']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['version_major']['separator'] = '';
  /* Field: Release: Version Patch */
  $handler->display->display_options['fields']['version_patch']['id'] = 'version_patch';
  $handler->display->display_options['fields']['version_patch']['table'] = 'eck_release';
  $handler->display->display_options['fields']['version_patch']['field'] = 'version_patch';
  $handler->display->display_options['fields']['version_patch']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['version_patch']['separator'] = '';
  /* Field: Release: Version extra */
  $handler->display->display_options['fields']['version_extra']['id'] = 'version_extra';
  $handler->display->display_options['fields']['version_extra']['table'] = 'eck_release';
  $handler->display->display_options['fields']['version_extra']['field'] = 'version_extra';
  $handler->display->display_options['fields']['version_extra']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_release_files']['id'] = 'field_release_files';
  $handler->display->display_options['fields']['field_release_files']['table'] = 'field_data_field_release_files';
  $handler->display->display_options['fields']['field_release_files']['field'] = 'field_release_files';
  $handler->display->display_options['fields']['field_release_files']['label'] = 'Download Link';
  $handler->display->display_options['fields']['field_release_files']['element_label_colon'] = FALSE;
  /* Field: Release: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'eck_release';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['date']['timezone'] = 'UTC';
  /* Field: Release: Tag */
  $handler->display->display_options['fields']['tag']['id'] = 'tag';
  $handler->display->display_options['fields']['tag']['table'] = 'eck_release';
  $handler->display->display_options['fields']['tag']['field'] = 'tag';
  $handler->display->display_options['fields']['tag']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_release_files_1']['id'] = 'field_release_files_1';
  $handler->display->display_options['fields']['field_release_files_1']['table'] = 'field_data_field_release_files';
  $handler->display->display_options['fields']['field_release_files_1']['field'] = 'field_release_files';
  $handler->display->display_options['fields']['field_release_files_1']['ui_name'] = 'File Size';
  $handler->display->display_options['fields']['field_release_files_1']['label'] = 'Size';
  $handler->display->display_options['fields']['field_release_files_1']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_release_files_3']['id'] = 'field_release_files_3';
  $handler->display->display_options['fields']['field_release_files_3']['table'] = 'field_data_field_release_files';
  $handler->display->display_options['fields']['field_release_files_3']['field'] = 'field_release_files';
  $handler->display->display_options['fields']['field_release_files_3']['label'] = 'MDHash';
  $handler->display->display_options['fields']['field_release_files_3']['element_label_colon'] = FALSE;
  /* Field: Release Files Display */
  $handler->display->display_options['fields']['raw_xml']['id'] = 'raw_xml';
  $handler->display->display_options['fields']['raw_xml']['table'] = 'views_data_export_global';
  $handler->display->display_options['fields']['raw_xml']['field'] = 'raw_xml';
  $handler->display->display_options['fields']['raw_xml']['ui_name'] = 'Release Files Display';
  $handler->display->display_options['fields']['raw_xml']['label'] = 'Files';
  $handler->display->display_options['fields']['raw_xml']['alter']['text'] = '[field_release_files_2]';
  $handler->display->display_options['fields']['raw_xml']['element_label_colon'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_project_reference_target_id']['id'] = 'field_project_reference_target_id';
  $handler->display->display_options['arguments']['field_project_reference_target_id']['table'] = 'field_data_field_project_reference';
  $handler->display->display_options['arguments']['field_project_reference_target_id']['field'] = 'field_project_reference_target_id';
  $handler->display->display_options['arguments']['field_project_reference_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_reference_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_reference_target_id']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['field_project_reference_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_reference_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_reference_target_id']['summary_options']['items_per_page'] = '25';

  /* Display: Releases XML */
  $handler = $view->new_display('views_data_export', 'Releases XML', 'fserver_releases_xml');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['custom_root_node'] = 'releases';
  $handler->display->display_options['style_options']['custom_item_node'] = 'release';
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['transform_type'] = 'underline';
  $handler->display->display_options['style_options']['transform_case'] = 'lowercase';
  $handler->display->display_options['path'] = 'releases';
  $translatables['fserver_releases'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
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
    t('Files'),
    t('Name'),
    t('Version'),
    t('Version Major'),
    t('.'),
    t('Version Patch'),
    t('Version extra'),
    t('Download Link'),
    t('Date'),
    t('Tag'),
    t('Size'),
    t('MDHash'),
    t('[field_release_files_2]'),
    t('All'),
    t('Releases XML'),
  );
  $export['fserver_releases'] = $view;

  return $export;
}
