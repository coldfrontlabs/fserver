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
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'release')
    ->propertyCondition('api', $api)
    ->propertyCondition('version_extra', 'dev', '<>')
    ->propertyCondition('project_short_name', $short_name)
    ->propertyOrderBy('date', 'DESC')
    ->execute();

  $results = $query->execute();
  
  if (!empty($results)) {
    // Load all release entities for the given project
    $releases = entity_load('release', array_keys($results['release']));
  }

  // Load dev release
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'release')
    ->propertyCondition('api', $api)
    ->propertyCondition('version_extra', 'dev', '=')
    ->propertyCondition('project_short_name', $short_name)
    ->range(0, 1);

  $results = $query->execute();
  
  if (!empty($results)) {
    $dev = array_shift($results['release']);

    // Append to the end of the array
    $releases[] = entity_load_single('release', $dev->id);
  }
  
  // Combine it all together
}