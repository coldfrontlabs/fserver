<?php
/**
 * @file
 * fserver.features.inc
 */

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
  'release_release' => array(
  'machine_name' => 'release_release',
  'entity_type' => 'release',
  'name' => 'release',
  'label' => 'Release',
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
    'created' => array(
      'label' => 'Created',
      'type' => 'integer',
      'behavior' => 'created',
    ),
    'changed' => array(
      'label' => 'Changed',
      'type' => 'integer',
      'behavior' => 'changed',
    ),
  ),
),
       'release' => array(
  'name' => 'release',
  'label' => 'Release',
  'properties' => array(
    'title' => array(
      'label' => 'Title',
      'type' => 'text',
      'behavior' => 'title',
    ),
    'created' => array(
      'label' => 'Created',
      'type' => 'integer',
      'behavior' => 'created',
    ),
  ),
),
  );
  return $items;
}
