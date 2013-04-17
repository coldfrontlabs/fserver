<?php
/**
 * @file
 * fserver.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fserver_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fserver_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function fserver_eck_bundle_info() {
  $items = array(
  'project_distribution' => array(
  'machine_name' => 'project_distribution',
  'entity_type' => 'project',
  'name' => 'distribution',
  'label' => 'Distribution',
),
  'project_module' => array(
  'machine_name' => 'project_module',
  'entity_type' => 'project',
  'name' => 'module',
  'label' => 'Module',
),
  'project_theme' => array(
  'machine_name' => 'project_theme',
  'entity_type' => 'project',
  'name' => 'theme',
  'label' => 'Theme',
),
  'release_release' => array(
  'machine_name' => 'release_release',
  'entity_type' => 'release',
  'name' => 'release',
  'label' => 'Release',
),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function fserver_eck_entity_type_info() {
$items = array(
       'project' => array(
  'name' => 'project',
  'label' => 'Project',
  'properties' => array(
    'title' => array(
      'label' => 'Title',
      'type' => 'text',
      'behavior' => 'title',
    ),
    'short_name' => array(
      'label' => 'Name',
      'type' => 'text',
      'behavior' => '',
    ),
    'api_version' => array(
      'label' => 'API Version',
      'type' => 'text',
      'behavior' => '',
    ),
    'recommended_major' => array(
      'label' => 'Recommended Major',
      'type' => 'positive_integer',
      'behavior' => '',
    ),
    'supported_majors' => array(
      'label' => 'Supported Majors',
      'type' => 'text',
      'behavior' => '',
    ),
    'link' => array(
      'label' => 'Link',
      'type' => 'text',
      'behavior' => '',
    ),
    'project_status' => array(
      'label' => 'Project Status',
      'type' => 'text',
      'behavior' => '',
    ),
  ),
),
       'release' => array(
  'name' => 'release',
  'label' => 'Release',
  'properties' => array(
    'name' => array(
      'label' => 'name',
      'type' => 'text',
      'behavior' => 'title',
    ),
    'version' => array(
      'label' => 'Version',
      'type' => 'text',
      'behavior' => '',
    ),
    'tag' => array(
      'label' => 'Tag',
      'type' => 'text',
      'behavior' => '',
    ),
    'version_major' => array(
      'label' => 'Version Major',
      'type' => 'integer',
      'behavior' => '',
    ),
    'version_patch' => array(
      'label' => 'Version Patch',
      'type' => 'integer',
      'behavior' => '',
    ),
    'version_extra' => array(
      'label' => 'Version extra',
      'type' => 'text',
      'behavior' => '',
    ),
    'date' => array(
      'label' => 'Date',
      'type' => 'positive_integer',
      'behavior' => 'created',
    ),
    'project_short_name' => array(
      'label' => 'Project Short Name',
      'type' => 'text',
      'behavior' => '',
    ),
  ),
),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function fserver_node_info() {
  $items = array(
    'project_info' => array(
      'name' => t('Project Info'),
      'base' => 'node_content',
      'description' => t('Project information and description'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'release_info' => array(
      'name' => t('Release Info'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
