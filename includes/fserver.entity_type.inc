<?php

/**
 * @file
 * Entity type functions
 */

/**
 * Project type entities
 */

/**
 * Load a single project type by id
 */
function project_type_load($id) {
  return entity_load_single('project', $id);
}

/**
 * Release type entities
 */

/**
 * Load a single project entity by id
 */
function release_type_load($id) {
  return entity_load_single('project', $id);
}
