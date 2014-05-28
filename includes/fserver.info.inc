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
 * Extend the defaults for the project entities.
 */
class FserverProjectMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['type'] = array(
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
      'description' => t('The project type.'),
      'type' => 'project_type',
    ) + $properties['type'];

    $properties['title'] = array(
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('Human readable name of a project.'),
    ) + $properties['title'];

    $properties['recommended_major'] = array(
      'type' => 'integer',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'description' => t('Recommended major version'),
      ) + $properties['recommended_major'];

    $properties['supported_majors'] = array(
      'description' => 'Supported major projects.',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
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
      'getter callback' => '_fserver_project_property_link_get',
      'computed' => TRUE,
    );

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
    ) + $properties['name'];

    $properties['version'] = array(
      'description' => 'Version',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
    ) + $properties['version'];

    $properties['project_short_name'] = array(
      'description' => 'Project short name',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
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