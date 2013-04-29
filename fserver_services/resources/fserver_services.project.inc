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
  $releases = fserver__release_load_by_project($short_name, $api);
  
  // Build return object
  $project->releases = $releases;
  
  return $project;
}