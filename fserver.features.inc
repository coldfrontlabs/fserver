<?php
/**
 * @file
 * fserver.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fserver_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fserver_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function fserver_node_info() {
  $items = array(
    'fserver_project_page' => array(
      'name' => t('Project Page'),
      'base' => 'node_content',
      'description' => t('Create a project page for a new theme, distribution or module.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'fserver_release_page' => array(
      'name' => t('Release Page'),
      'base' => 'node_content',
      'description' => t('Create a release page to describe details of a given project release.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
