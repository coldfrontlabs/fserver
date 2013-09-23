<?php
/**
 * @file
 * fserver_ui.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fserver_ui_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fserver_ui_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function fserver_ui_node_info() {
  $items = array(
    'fserver_project_description' => array(
      'name' => t('Project Page'),
      'base' => 'node_content',
      'description' => t('Create a project page for a new theme, distribution or module.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
