<?php

/**
 * @file
 * Views integration
 */

/*
 * Implements hook_views_plugins().
 *
 * This function annnounces the style plugin for flexslider views.
 */
function fserver_views_plugins() {
  return array(
    'style' => array(
      'fserver_xml_style' => array(
        'even empty' => FALSE,
        'help' => t('Display the results in an XML feed. Typically used to provide updates regarding Drupal projects.'),
        'handler' => 'fserver_views_plugin_style_fserver_xml',
        'theme' => 'fserver_xml_style',
        'theme file' => 'fserver.theme.inc',
        'theme path' => drupal_get_path('module', 'fserver') . '/theme',
        'title' => t('Feature Server XML'),
        'type' => 'normal',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses options' => FALSE,
        'uses grouping' => FALSE,
      ),
    ),
  );
}

/**
 * Implements hook_views_data_alter().
 */
function fserver_views_data_alter(&$data) {
  if (isset($data['eck_project']['short_name'])) {
    // Add join info
    $data['eck_project']['table']['join'] = array(
        'eck_release' => array(
          'left_field' => 'project_short_name',
          'field' => 'short_name',
        ),
      );

    $data['eck_project']['short_name']['relationship'] = array(
      'title' => t('Project release'),
      'help' => t('Add relationship to release via shortname'),
      'handler' => 'views_handler_relationship',
      'base' => 'eck_release',
      'base field' => 'project_short_name',
      'label' => t('release'),
    );
  }

  if (isset($data['eck_release']['project_short_name'])) {
    // Add join info
    $data['eck_release']['table']['join'] = array(
        'eck_project' => array(
          'left_field' => 'short_name',
          'field' => 'project_short_name',
        ),
      );

    $data['eck_release']['project_short_name']['relationship'] = array(
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