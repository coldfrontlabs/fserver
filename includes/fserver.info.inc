<?php

/**
 * @file
 * Provides Entity metadata integration.
 */

/**
 * Extend the defaults for project types.
 */
class FserverProjectTypeMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['type'] = array(
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
      'description' => t('The project type.'),
    ) + $properties['type'];

    return $info;
  }
}

/**
 * Extend the defaults for release types.
 */
class FserverReleaseTypeMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['type'] = array(
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
      'description' => t('The release type.'),
    ) + $properties['type'];

    return $info;
  }
}

/**
 * Property info for the default_major struct
 *
 * @return array
 * @see hook_entity_property_info().
 */
function fserver_project_default_major_property_info() {
  return array(
    'api' => array(
      'type' => 'text',
      'label' => t('API Version'),
      'description' => t('Drupal API version (e.g. 7.x).'),
    ),
    'default_major' => array(
      'type' => 'int',
      'label' => t('Default major'),
      'description' => t('Default major for this API version of Drupal.'),
    ),
  );
}

/**
 * Property info for the default_major struct
 *
 * @return array
 * @see hook_entity_property_info().
 */
function fserver_project_recommended_major_property_info() {
  return array(
    'api' => array(
      'type' => 'text',
      'label' => t('API Version'),
      'description' => t('Drupal API version (e.g. 7.x).'),
    ),
    'recommended_major' => array(
      'type' => 'int',
      'label' => t('Recommended major'),
      'description' => t('Recommended major for this API version of Drupal.'),
    ),
  );
}

/**
 * Property info for the supported_majors struct
 *
 * @return array
 * @see hook_entity_property_info().
 */
function fserver_project_supported_majors_property_info() {
  return array(
    'api' => array(
      'type' => 'text',
      'label' => t('API Version'),
      'description' => t('Drupal API version (e.g. 7.x).'),
    ),
    'supported_majors' => array(
      'type' => 'list<integer>',
      'label' => t('Supported majors'),
      'description' => t('Supported majors for this API version of Drupal.'),
    ),
  );
}

/**
 * Extend the defaults for the project entities.
 */
class FserverProjectMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $default_major_properties = fserver_project_default_major_property_info();
    $recommended_major_properties = fserver_project_recommended_major_property_info();
    $supported_majors_properties = fserver_project_supported_majors_property_info();

    $properties = &$info[$this->type]['properties'];

    $properties['type'] = array(
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
      'description' => t('The project type.'),
      'type' => 'project_type',
    ) + $properties['type'];

    $properties['short_name'] = array(
      'required' => TRUE,
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('Project machine name.'),
      'type' => 'token',
    ) + $properties['short_name'];

    $properties['name'] = array(
      'schema field' => 'short_name',
    ) + $properties['short_name'];

    $properties['title'] = array(
      'required' => TRUE,
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('Human readable name of a project.'),
    ) + $properties['title'];

    $properties['default_major'] = array(
      'type' => 'list',
      'getter callback' => 'fserver__property_serialized_get',
      'setter callback' => 'fserver__property_serialized_set',
      'validation callback' => 'fserver_project_property_default_major_validate',
      'queryable' => FALSE,
      'required' => FALSE,
      'label' => t('Default major'),
      'property info' => $default_major_properties,
    ) + $properties['default_major'];

    $properties['recommended_major'] = array(
      'type' => 'list<struct>',
      'getter callback' => 'fserver__property_serialized_get',
      'setter callback' => 'fserver__property_serialized_set',
      'validation callback' => 'fserver_project_property_recommended_major_validate',
      'queryable' => FALSE,
      'required' => FALSE,
      'description' => t('Recommended major version'),
      'property info' => $recommended_major_properties,
    ) + $properties['recommended_major'];

    $properties['supported_majors'] = array(
      'type' => 'list<struct>',
      'getter callback' => 'fserver__property_serialized_get',
      'setter callback' => 'fserver__property_serialized_set',
      'validation callback' => 'fserver_project_property_supported_majors_validate',
      'queryable' => FALSE,
      'required' => FALSE,
      'property info' => $supported_majors_properties,
    ) + $properties['supported_majors'];

    $properties['project_status'] = array(
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('Project status code'),
    ) + $properties['project_status'];

    $properties['created'] = array(
      'type' => 'date',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('The time the project was created.'),
    ) + $properties['created'];

    $properties['changed'] = array(
      'type' => 'date',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('The time the project was modified/changed.'),
    ) + $properties['changed'];

    $properties['link'] = array(
      'type' => 'uri',
      'setter callback' => 'entity_property_verbatim_set',
      'getter callback' => 'entity_property_verbatim_get',
    ) + $properties['link'];

    return $info;
  }
}

/**
 * Extend the defaults for the project entities.
 */
class FserverReleaseMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['type'] = array(
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
      'description' => t('The project type.'),
      'type' => 'release_type',
    ) + $properties['type'];

    $properties['name'] = array(
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('Name of a release.'),
      'required' => TRUE,
    ) + $properties['name'];

    $properties['version'] = array(
      'description' => 'Version',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
    ) + $properties['version'];

    $properties['project_short_name'] = array(
      'description' => 'Project short name',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
    ) + $properties['project_short_name'];

    $properties['tag'] = array(
      'description' => 'Tag',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
    ) + $properties['tag'];

    $properties['version_major'] = array(
      'type' => 'integer',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('Version major'),
    ) + $properties['version_major'];

    $properties['version_patch'] = array(
      'type' => 'integer',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('Version patch'),
    ) + $properties['version_patch'];

    $properties['version_extra'] = array(
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('Project status code'),
    ) + $properties['version_extra'];

    $properties['date'] = array(
      'type' => 'date',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('The date the release was created.'),
    ) + $properties['date'];

    $properties['api'] = array(
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('API version'),
    ) + $properties['api'];

    return $info;
  }
}
