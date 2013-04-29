<?php

/**
 * @file
 * Resources
 */

/**
 * Callback to retrieve a project
 */
function _fserver_services_retrieve_project($short_name, $api) {
  // Load project
  $project = fserver__project_load($short_name);

  if (FALSE === $project) {
    return $project;
  }

  // Load releases
  
  // Since the .x is removed by Services (which mistakenly assumes it is
  // a file extension) we must put it back
  $api .= '.x';

  $releases = fserver__release_load_by_project($short_name, $api);

  // Build return object
  $project->releases = _fserver_services_clean_releases($releases);
  
  // Clean uncessearry data
  unset($project->id);
  
  // Removing fields
  if (isset($project->field_compatibility)) {
    unset($project->field_compatibility);
  }

  // Allow other modules to modify the XML before rendering
  drupal_alter('fserver_services_xml', $project);

  return $project;
}

/**
 * Remove unwanted data from release objects
 */
function _fserver_services_clean_releases(&$releases) {
  foreach ($releases as &$release) {
    unset($release['id']);
  }
}