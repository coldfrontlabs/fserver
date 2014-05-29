<?php

/**
 * @file
 * Admin forms
 */

/**
 * Form settings for the Project entity
 */
function project_form($form, &$form_state, $project, $op = 'edit') {
  if (isset($form['title'])) {
    $form['title']['#weight'] = -10;
  }

  if (isset($form['field_compatibility'])) {
    $form['field_compatibility']['#weight'] = 0;
  }

  $form['short_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Project Short Name'),
    '#description' => t('Machine-name of the project for this release.'),
    '#size' => 40,
    '#maxlength' => 255,
    '#machine_name' => array(
      'exists' => 'fserver__project_exists',
      'source' => array('title'),
      'label' => t('Project short name'),
    ),
    '#weight' => -9,
    '#default_value' => isset($form['entity']['#value']->short_name) ? $form['entity']['#value']->short_name : '',
  );

  $form['project_status'] = array(
    '#type' => 'select',
    '#title' => t('Project Status'),
    '#multiple' => FALSE,
    '#description' => t('Status code for the project. Affects how updates are displayed by the Update module.'),
    '#options' => array(
      # @see https://api.drupal.org/api/drupal/modules%21update%21update.compare.inc/7
      'published' => t('Published'),
      'unpublished' => t('Unpublished'),
      'insecure' => t('Insecure'),
      'revoked' => t('Revoked'),
      'unsupported' => t('Unsupported'),
    ),
    '#default_value' => isset($form['entity']['#value']->project_status) ? $form['entity']['#value']->project_status : '',
  );


  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced'),
    '#description' => t('The following options are normally auto-detected based on your repository data. Please use caution when modifying the following.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );


  $form['advanced']['supported_majors'] = array(
    '#type' => 'textfield',
    '#title' => t('Supported Majors'),
    '#description' => t('Major versions which are supported.'),
    '#size' => 40,
    '#maxlength' => 255,
    // @todo limit based on available major versions
    '#weight' => 20,
    '#default_value' => isset($form['entity']['#value']->supported_majors) ? $form['entity']['#value']->supported_majors : '',
    // @todo add element validator
  );

  $form['advanced']['recommended_major'] = array(
    '#type' => 'numberfield',
    '#title' => t('Recommended Major'),
    '#description' => t('Major version which is recommended.'),
    '#size' => 40,
    '#maxlength' => 255,
    '#min' => 1,
    // @todo validate the major version exists
    '#weight' => 20,
    '#default_value' => isset($form['entity']['#value']->recommended_major) ? $form['entity']['#value']->recommended_major : '',
  );

  $form['advanced']['default_major'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Major'),
    '#description' => t('Default major branch.'),
    '#size' => 40,
    '#maxlength' => 255,
    '#weight' => 20,
    '#default_value' => isset($form['entity']['#value']->default_major) ? $form['entity']['#value']->default_major : '',
    // @todo add element validator
  );


  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  # @todo add access check on form
}

/**
 * Form settings for the Release entity
 */
function release_form($form, &$form_state, $release, $op = 'edit') {

  $form['api'] = array(
    '#type' => 'select',
    '#title' => t('API'),
    '#description' => t('API version (i.e. 7.x)'),
    '#default_value' => isset($form['entity']['#value']->api) ? $form['entity']['#value']->api : '7.x',
    '#required' => TRUE,
    '#multiple' => FALSE,
    '#options' => array(
      '5.x' => t('5.x'),
      '6.x' => t('6.x'),
      '7.x' => t('7.x'),
      '8.x' => t('8.x'),
    ),
  );

  $form['version_major'] = array(
    '#type' => 'numberfield',
    '#title' => t('Version Major'),
    '#size' => 15,
    '#min' => 1,
    '#maxlength' => 3,
    '#default_value' => isset($form['entity']['#value']->version_major) ? $form['entity']['#value']->version_major : '',
    '#required' => TRUE,
    // @todo add auto-detection based on project repo data
  );

  $form['version_extra'] = array(
    '#type' => 'textfield',
    '#title' => t('Version Extra'),
    '#description' => t('Ex: dev, alpha1'),
    '#size' => 15,
    '#maxlength' => 20,
    '#default_value' => isset($form['entity']['#value']->version_extra) ? $form['entity']['#value']->version_extra : '',
    // @todo add custom validator
    // @todo add auto-detection based on project repo data
  );

  $form['version_patch'] = array(
    '#type' => 'textfield',
    '#title' => t('Version Patch'),
    '#size' => 6,
    '#maxlength' => 4,
    '#default_value' => isset($form['entity']['#value']->version_patch) ? $form['entity']['#value']->version_patch : '',
    // @todo add custom validator
  );
  # @todo add access check on form

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
}

/**
 * Project type form
 */
function project_type_form($form, &$form_state, $project_type, $op = 'edit') {
  if ($op == 'clone') {
    $project_type->description .= ' (cloned)';
    // Save the original message type into form state so that the submit
    // handler can clone its field instances.
    $form_state['original_provider_type'] = menu_get_object('entity_object', 4);
  }

  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#description' => t('Describe the provider.'),
    '#default_value' => $project_type->description,
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['type'] = array(
    '#type' => 'machine_name',
    '#title' => t('Name'),
    '#description' => t('A unique machine-readable name for this provider type. It must only contain lowercase letters, numbers, and underscores.'),
    '#default_value' => isset($project_type->type) ? $project_type->type : '',
    '#size' => 40,
    '#disabled' => $project_type->hasStatus(ENTITY_IN_CODE),
    '#machine_name' => array(
      'exists' => 'project_type_load',
      'source' => array('description'),
    ),
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Validation callback for project_type
 */
function project_type_form_validate(&$form, &$form_state) {
  field_attach_form_validate('project_type', $form_state['project_type'], $form['project_type_fields'], $form_state);
}

/**
 * Submit callback for project_type
 */
function project_type_form_submit(&$form, &$form_state) {
  $project_type = entity_ui_form_submit_build_entity($form, $form_state);
  $project_type->save();

  // If this was a clone operation, clone the field instances as well.
  $op = $form_state['build_info']['args'][1];
  if ($op == 'clone') {
    $original_instances = field_info_instances('project_type', $form_state['original_project_type']->name);
    foreach ($original_instances as $instance) {
      $instance['bundle'] = $project_type->name;
      field_create_instance($instance);
    }
  }

  $form_state['redirect'] = 'admin/structure/project_types';
}

/**
 * Form API submit callback for the delete button.
 */
function project_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/project_types/manage/' . $form_state['project_type']->name . '/delete';
}

/**
 * Release type form
 */
function release_type_form($form, &$form_state, $release_type, $op = 'edit') {
  if ($op == 'clone') {
    $release_type->description .= ' (cloned)';
    // Save the original message type into form state so that the submit
    // handler can clone its field instances.
    $form_state['original_release_type'] = menu_get_object('entity_object', 4);
  }

  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#description' => t('Describe the release type.'),
    '#default_value' => $release_type->description,
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['type'] = array(
    '#type' => 'machine_name',
    '#title' => t('Name'),
    '#description' => t('A unique machine-readable name for this release type. It must only contain lowercase letters, numbers, and underscores.'),
    '#default_value' => isset($release_type->type) ? $release_type->type : '',
    '#size' => 40,
    '#disabled' => $release_type->hasStatus(ENTITY_IN_CODE),
    '#machine_name' => array(
      'exists' => 'release_type_loady',
      'source' => array('description'),
    ),
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );


  return $form;
}

/**
 * Validation callback for release_type
 */
function release_type_form_validate(&$form, &$form_state) {
  field_attach_form_validate('release_type', $form_state['release_type'], $form['release_type_fields'], $form_state);
}

/**
 * Submit callback for release_type
 */
function release_type_form_submit(&$form, &$form_state) {
  $release_type = entity_ui_form_submit_build_entity($form, $form_state);
  $release_type->save();

  // If this was a clone operation, clone the field instances as well.
  $op = $form_state['build_info']['args'][1];
  if ($op == 'clone') {
    $original_instances = field_info_instances('release_type', $form_state['original_release_type']->name);
    foreach ($original_instances as $instance) {
      $instance['bundle'] = $release_type->name;
      field_create_instance($instance);
    }
  }

  $form_state['redirect'] = 'admin/structure/release_types';
}

/**
 * Form API submit callback for the delete button.
 */
function release_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/release_types/manage/' . $form_state['release_type']->name . '/delete';
}
