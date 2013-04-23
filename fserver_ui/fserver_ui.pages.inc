<?php

/**
 * @file
 * Pages for Feature Server
 */

/**
 * Form settings for the Project entity
 */
function fserver_ui_project_form(&$form, &$form_state) {
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
    '#weight' => 20,
  );
  
  $form['recommended_major'] = array(
    '#type' => 'textfield',
    '#title' => t('Recommended Major'),
    '#description' => t('Major version which is recommended.'),
    '#size' => 40,
    '#maxlength' => 255,
    // @todo set to number field
    // @todo validate the major version exists
    '#weight' => 20,
  );
  
  $form['supported_majors'] = array(
    '#type' => 'textfield',
    '#title' => t('Supported Majors'),
    '#description' => t('Major versions which are supported.'),
    '#size' => 40,
    '#maxlength' => 255,
    // @todo limit based on available major versions
    '#weight' => 20,
  );
  
  $form['default_major'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Major'),
    '#description' => t('Default major branch.'),
    '#size' => 40,
    '#maxlength' => 255,
    // @todo set to number field
    '#weight' => 20,
  );
  
  $form['project_status'] = array(
    '#type' => 'select',
    '#title' => t('Project Status'),
    '#multiple' => FALSE,
    '#description' => t('Status code for the project. Affects how updates are displayed by the Update module.'),
    '#options' => array(
      'published' => t('Published'),
      // @todo add the rest of the status codes
    ),
    '#default_value' => -1,
    '#weight' => 20,
  );
}



/**
 * Form settings for the Release entity
 */
function fserver_ui_release_form(&$form, &$form_state) {
  $form['project_short_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Project Short Name'),
    '#description' => t('Machine-name of the project for this release.'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => $form['entity']->project_short_name,
  );

  $form['api'] = array(
    '#type' => 'textfield',
    '#title' => t('API'),
    '#description' => t('API version (i.e. 7.x)'),
    '#size' => 5,
    '#maxlength' => 4,
    // @todo add element validator
  );

  $form['version_major'] = array(
    '#type' => 'textfield',
    '#title' => t('Version Major'),
    '#size' => 3,
    '#maxlength' => 3,
    // @todo change to numberfield
  );

  $form['version_patch'] = array(
    '#type' => 'textfield',
    '#title' => t('Version Patch'),
    '#size' => 6,
    '#maxlength' => 4,
  );
  
  $form['version_extra'] = array(
    '#type' => 'textfield',
    '#title' => t('Version Extra'),
    '#description' => t('Ex: dev, alpha1'),
    '#size' => 40,
    '#maxlength' => 255,
  );  
  
  // Disable the title field
  $form['name']['#disabled'] = TRUE;
}