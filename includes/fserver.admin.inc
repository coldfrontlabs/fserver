<?php

/**
 * @file
 * Admin forms
 */

/**
 * Form settings for the Project entity
 */
function project_form(&$form, &$form_state) {
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

  # @todo add access check on form
}

/**
 * Form settings for the Release entity
 */
function release_form(&$form, &$form_state) {

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
}
