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
  $view->tag = 'Fserver UI';
  $view->base_table = 'fserver_project';
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
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'project_status' => 'project_status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'project_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['summary'] = 'List of projects available through Feature Server';
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Footer: Global: Link */
  $handler->display->display_options['footer']['link']['id'] = 'link';
  $handler->display->display_options['footer']['link']['table'] = 'views';
  $handler->display->display_options['footer']['link']['field'] = 'link';
  $handler->display->display_options['footer']['link']['label'] = 'Create Project';
  $handler->display->display_options['footer']['link']['empty'] = TRUE;
  $handler->display->display_options['footer']['link']['text'] = 'Create Project';
  $handler->display->display_options['footer']['link']['path'] = 'node/add/fserver-project-page';
  $handler->display->display_options['footer']['link']['querystring'] = 'destination=fserver_ui/project-list';
  $handler->display->display_options['footer']['link']['class'] = 'button';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No projects available.';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_project_reference_node']['id'] = 'reverse_field_project_reference_node';
  $handler->display->display_options['relationships']['reverse_field_project_reference_node']['table'] = 'fserver_project';
  $handler->display->display_options['relationships']['reverse_field_project_reference_node']['field'] = 'reverse_field_project_reference_node';
  $handler->display->display_options['relationships']['reverse_field_project_reference_node']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_project_reference_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Project: Label */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'fserver_project';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Project: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'fserver_project';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Project: Compatibility */
  $handler->display->display_options['fields']['field_compatibility']['id'] = 'field_compatibility';
  $handler->display->display_options['fields']['field_compatibility']['table'] = 'field_data_field_compatibility';
  $handler->display->display_options['fields']['field_compatibility']['field'] = 'field_compatibility';
  $handler->display->display_options['fields']['field_compatibility']['delta_offset'] = '0';
  /* Field: Project: Project_status */
  $handler->display->display_options['fields']['project_status']['id'] = 'project_status';
  $handler->display->display_options['fields']['project_status']['table'] = 'fserver_project';
  $handler->display->display_options['fields']['project_status']['field'] = 'project_status';
  $handler->display->display_options['fields']['project_status']['label'] = 'Status';
  /* Field: Project: Link */
  $handler->display->display_options['fields']['link']['id'] = 'link';
  $handler->display->display_options['fields']['link']['table'] = 'fserver_project';
  $handler->display->display_options['fields']['link']['field'] = 'link';
  /* Sort criterion: Project: Short_name */
  $handler->display->display_options['sorts']['short_name']['id'] = 'short_name';
  $handler->display->display_options['sorts']['short_name']['table'] = 'fserver_project';
  $handler->display->display_options['sorts']['short_name']['field'] = 'short_name';
  $handler->display->display_options['sorts']['short_name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['short_name']['expose']['label'] = 'Name';
  /* Sort criterion: Project: Type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'fserver_project';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
  $handler->display->display_options['sorts']['type']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['type']['expose']['label'] = 'Type';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Text Filter';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'textfilter';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Project type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'fserver_project';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Project type';
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_compatibility_value']['group'] = 1;
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
  $handler->display->display_options['path'] = 'fserver_ui/project-list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Feature Server';
  $handler->display->display_options['menu']['description'] = 'Default interface to Feature Server';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Projects Block */
  $handler = $view->new_display('block', 'Projects Block', 'block_1');
  $handler->display->display_options['display_description'] = 'List projects in a block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $export['fserver_ui_projects'] = $view;

  $view = new view();
  $view->name = 'fserver_ui_releases';
  $view->description = 'List of releases for a given project.';
  $view->tag = 'Fserver UI';
  $view->base_table = 'fserver_release';
  $view->human_name = 'Releases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Releases';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
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
  /* Field: Release: Version */
  $handler->display->display_options['fields']['version']['id'] = 'version';
  $handler->display->display_options['fields']['version']['table'] = 'fserver_release';
  $handler->display->display_options['fields']['version']['field'] = 'version';
  $handler->display->display_options['fields']['version']['element_label_colon'] = FALSE;
  /* Field: Release: File */
  $handler->display->display_options['fields']['field_release_files']['id'] = 'field_release_files';
  $handler->display->display_options['fields']['field_release_files']['table'] = 'field_data_field_release_files';
  $handler->display->display_options['fields']['field_release_files']['field'] = 'field_release_files';
  $handler->display->display_options['fields']['field_release_files']['label'] = 'Downloads';
  $handler->display->display_options['fields']['field_release_files']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_release_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_release_files']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_release_files']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_release_files']['separator'] = ' |  ';
  /* Field: Release: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'fserver_release';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'Y-M-d';

  /* Display: Releases Bock */
  $handler = $view->new_display('block', 'Releases Bock', 'fserver_ui_block_releases');
  $handler->display->display_options['display_description'] = 'List of releases for a given project';
  $export['fserver_ui_releases'] = $view;

  return $export;
}
