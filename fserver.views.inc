<?php

/**
 * @file
 * Views integration
 */

// @todo add custom sort plugin to sort releases
// @todo add custom grouping plugin to group releases

/**
 * Implements hook_views_handlers().
 *
function fserver_views_handlers() {
  $handlers = array(
    'info' => array(
      'path' => drupal_get_path('module', 'fserver') . '/views',
    ),
    'handlers' => array(
      'fserver_handler_fserver_project_default_major' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
  return $handlers;
}
*/

/**
 * Implements hook_views_data().
 *
function fserver_views_data() {
  $data = array();
  $data['fserver_project']['new_default_major'] = array(
    'title' => 'Fserver Project Handler FX',
    'help' => t('Custom views field handler for Fserver project entities.'),
    'field' => array(
      'handler' => 'fserver_handler_fserver_project_default_major',
    ),
  );
  return $data;
}
*/
function fserver_views_data_alter(&$data) {
  $data['views_entity_project']['default_major_api'] = array(
    'title' => 'Fserver Project Default Major - API',
    'help' => t('Custom views field handler for Fserver project default major API property.'),
    'field' => array(
      'handler' => 'fserver_handler_fserver_project_default_major_api',
    ),
  );
  $data['views_entity_project']['default_major_default_major'] = array(
    'title' => 'Fserver Project Default Major - Default Major',
    'help' => t('Custom views field handler for Fserver project default major property.'),
    'field' => array(
      'handler' => 'fserver_handler_fserver_project_default_major_default_major',
    ),
  );
/*
  $data['views_entity_project']['filter_default_major_releases'] = array(
    'title' => 'Fserver Project Default Major - API',
    'help' => t('Custom views field handler for Fserver project default major API property.'),
    'filter' => array(
      'handler' => 'fserver_handler_fserver_project_default_major_fields_compare',
    ),
  );
*/
  $data['views_entity_project']['recommended_major_api'] = array(
    'title' => 'Fserver Project Recommended Major - API',
    'help' => t('Custom views field handler for Fserver project recommended major API property.'),
    'field' => array(
      'handler' => 'fserver_handler_fserver_project_recommended_major_api',
    ),
  );
  $data['views_entity_project']['recommended_major_recommended_major'] = array(
    'title' => 'Fserver Project Recommended Major - Recommended Major',
    'help' => t('Custom views field handler for Fserver project recommended major property.'),
    'field' => array(
      'handler' => 'fserver_handler_fserver_project_recommended_major_recommended_major',
    ),
  );
  $data['views_entity_project']['filter_recommended_major_releases'] = array(
    'title' => 'Fserver Project Recommended Major - Release Filter',
    'help' => t('Custom views filter handler for Fserver project recommended major property.'),
    'filter' => array(
      'handler' => 'fserver_handler_filter_fserver_project_recommended_major',
    ),
  );
  $data['views_entity_project']['supported_majors_api'] = array(
    'title' => 'Fserver Project Supported Majors - API',
    'help' => t('Custom views field handler for Fserver project recommended major API property.'),
    'field' => array(
      'handler' => 'fserver_handler_fserver_project_supported_majors_api',
    ),
  );
  $data['views_entity_project']['supported_majors_supported_majors'] = array(
    'title' => 'Fserver Project Supported Majors - Supported Majors',
    'help' => t('Custom views field handler for Fserver project recommended major property.'),
    'field' => array(
      'handler' => 'fserver_handler_fserver_project_supported_majors_supported_majors',
    ),
  );
  $data['views_entity_project']['filter_supported_majors_releases'] = array(
    'title' => 'Fserver Project Supported Majors - Release Filter',
    'help' => t('Custom views filter handler for Fserver project supported majors property.'),
    'filter' => array(
      'handler' => 'fserver_handler_filter_fserver_project_supported_majors',
    ),
  );
}
