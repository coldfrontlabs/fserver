<?php

/**
 * @file
 * Views integration
 */

/**
 * Implements hook_views_data_alter().
 */
function fserver_views_data_alter(&$data) {
  dpm($data['eck_project']);
}

