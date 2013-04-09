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
  return array(
    "api" => "3.0",
    "template path" => drupal_get_path('module', 'fserver') . "/templates",
  );
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
  'release_alpha' => array(
  'machine_name' => 'release_alpha',
  'entity_type' => 'release',
  'name' => 'alpha',
  'label' => 'Alpha',
),
  'release_beta' => array(
  'machine_name' => 'release_beta',
  'entity_type' => 'release',
  'name' => 'beta',
  'label' => 'Beta',
),
  'release_dev' => array(
  'machine_name' => 'release_dev',
  'entity_type' => 'release',
  'name' => 'dev',
  'label' => 'Development',
),
  'release_full' => array(
  'machine_name' => 'release_full',
  'entity_type' => 'release',
  'name' => 'full',
  'label' => 'Full',
),
  'release_rc' => array(
  'machine_name' => 'release_rc',
  'entity_type' => 'release',
  'name' => 'rc',
  'label' => 'Release Candidate',
),
  'release_unstable' => array(
  'machine_name' => 'release_unstable',
  'entity_type' => 'release',
  'name' => 'unstable',
  'label' => 'Unstable',
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
