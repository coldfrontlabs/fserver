<?php

/**
 * @file
 * Entity type functions
 */

/**
 * Project type entities
 */

/**
 * Load a single project type by type
 */
function project_type_load($type = NULL) {
  // Replace dashes with underscores so this can be used as menu argument
  // loader too.
  $types = entity_load_multiple_by_name('project_type', isset($type) ? array(strtr($type, array('-' => '_'))) : FALSE);
  if (isset($type)) {
    return isset($types[$type]) ? $types[$type] : FALSE;
  }

  return $types;
}

/**
 * Access callback for project types
 */
function project_type_access($op, $entity, $account = NULL, $entity_type) {
  if (user_access('administer fserver', $account)) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Release type entities
 */

/**
 * Load a single project entity by type
 */
function release_type_load($type = NULL) {
  // Replace dashes with underscores so this can be used as menu argument
  // loader too.
  $types = entity_load_multiple_by_name('release_type', isset($type) ? array(strtr($type, array('-' => '_'))) : FALSE);
  if (isset($type)) {
    return isset($types[$type]) ? $types[$type] : FALSE;
  }

  return $types;
}

/**
 * Access callback for release types
 */
function release_type_access($op, $entity, $account = NULL, $entity_type) {
  if (user_access('administer fserver', $account)) {
    return TRUE;
  }

  return FALSE;
}