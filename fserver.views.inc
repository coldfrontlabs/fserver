<?php

/**
 * @file
 * Views integration
 */

/**
 * Implements hook_views_data_alter().
 */
function fserver_views_data_alter(&$data) {
  if (isset($data['fserver_release']['project_short_name'])) {
    // Add join info
    $data['eck_release']['table']['join'] = array(
        'eck_project' => array(
          'left_field' => 'short_name',
          'field' => 'project_short_name',
        ),
      );

    $data['fserver_release']['project_short_name']['relationship'] = array(
      'title' => t('Release project'),
      'help' => t('Add relationship to the project via shortname'),
      'handler' => 'views_handler_relationship',
      'base' => 'eck_project',
      'base field' => 'short_name',
      'label' => t('project'),
    );
  }
}

// @todo add custom sort plugin to sort releases
// @todo add custom grouping plugin to group releases