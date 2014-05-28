<?php

/**
 * @file
 * Provides Entity metadata integration.
 */

/**
 * Extend the defaults for provider types.
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
 * Extend the defaults for provider types.
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