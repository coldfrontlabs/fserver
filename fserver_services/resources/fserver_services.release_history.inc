<?php

/**
 * @file
 * Release history resource
 */


/**
 * Generates release history for given project
 */
function _fserver_services_release_history($short_name, $api) {
  // Load project
  $project = fserver__project_load($short_name);

  if (FALSE === $project) {
    return $project;
  }

  // Load releases

  // Since the .x is removed by Services (which mistakenly assumes it is
  // a file extension) we must put it back
  $api .= '.x';

  $project = new fserverProjectRelease($project, $api);

  if (FALSE !== $project) {
    return $project->getProject();
  }

  return FALSE;
}