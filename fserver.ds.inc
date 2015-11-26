<?php
/**
 * @file
 * fserver.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function fserver_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'release|release|default';
  $ds_fieldsetting->entity_type = 'release';
  $ds_fieldsetting->bundle = 'release';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'release_date' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
    ),
  );
  $export['release|release|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function fserver_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'release_date';
  $ds_field->label = 'Release Date';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'release' => 'release',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[release:date:long]',
      'format' => 'markdown_full_html',
    ),
    'use_token' => 1,
  );
  $export['release_date'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function fserver_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'release|release|default';
  $ds_layout->entity_type = 'release';
  $ds_layout->bundle = 'release';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'release_date',
        1 => 'og_group_ref',
      ),
      'right' => array(
        2 => 'field_release_files',
      ),
      'footer' => array(
        3 => 'field_release_notes',
      ),
    ),
    'fields' => array(
      'release_date' => 'left',
      'og_group_ref' => 'left',
      'field_release_files' => 'right',
      'field_release_notes' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['release|release|default'] = $ds_layout;

  return $export;
}
