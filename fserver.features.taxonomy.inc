<?php
/**
 * @file
 * fserver.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function fserver_taxonomy_default_vocabularies() {
  return array(
    'development_status' => array(
      'name' => 'Development status',
      'machine_name' => 'development_status',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'maintenance_status' => array(
      'name' => 'Maintenance status',
      'machine_name' => 'maintenance_status',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'release_type' => array(
      'name' => 'Release Type',
      'machine_name' => 'release_type',
      'description' => 'Types of releases',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
