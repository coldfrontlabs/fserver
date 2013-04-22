<?php

/**
 * @file
 * Views integration
 */

/**
 * Implements hook_views_data_alter().
 */
function fserver_views_data_alter(&$data) {
  if (isset($data['eck_project']['short_name'])) {
    $data['eck_project']['short_name']['relationship'] = array(
      'title' => t('Project release'),
      'help' => t('Add relationship to release via shortname'),
      'handler' => 'views_handler_relationship',
      'base' => 'eck_release',
      'field' => 'project_short_name',
      'label' => t('release'),
    );
  }

  if (isset($data['eck_release']['project_short_name'])) {
    $data['eck_project']['short_name']['relationship'] = array(
      'title' => t('Release project'),
      'help' => t('Add relationship to the project via shortname'),
      'handler' => 'views_handler_relationship',
      'base' => 'eck_project',
      'field' => 'short_name',
      'label' => t('project'),
    );
  }
}

