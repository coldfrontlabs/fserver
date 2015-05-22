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
  return array(
    'api' => '3.0',
    'path' => drupal_get_path('module', 'fserver'),
  );
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

/**
 * Implements hook_default_project_type().
 */
function fserver_default_project_type() {
  $items = array();

  $items['module'] = entity_import('project_type', '{
    "type" : "module",
    "description" : "Drupal module project type.",
    "uuid": "826d8e65-196d-4e4c-9ddc-847e0b41cf05"
  }');

  $items['theme'] = entity_import('project_type', '{
    "type" : "theme",
    "description" : "Drupal theme project type.",
    "uuid": "30a5b10d-1cdf-4637-8201-696e289bb9b5"
  }');
  $items['distribution'] = entity_import('project_type', '{
    "type" : "distribution",
    "description" : "Drupal distribution project.",
    "uuid": "091075b9-7999-40ba-a56f-10fac06a5d63"
  }');

  $items['installprofile'] = entity_import('project_type', '{
    "type" : "installprofile",
    "description" : "Drupal installation profile project type.",
    "uuid": "9be5ea44-1d0e-4162-bfbd-e1fa114a33d5"
  }');

  return $items;
}

/**
 * Implements hook_default_project_type().
 */
function fserver_default_release_type() {
  $items = array();

  $items['release'] = entity_import('release_type', '{
    "type" : "release",
    "description" : "Standard project release type.",
    "uuid": "24bb28de-8cc0-4fa4-8f8c-04c7b3cbf715"
  }');

  return $items;
}
