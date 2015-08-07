<?php
/**
 * @file
 * fserver.ds.inc
 */

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
        0 => 'field_project_reference',
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
      'field_project_reference' => 'left',
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
