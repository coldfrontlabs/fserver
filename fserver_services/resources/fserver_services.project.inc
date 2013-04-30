<?php

/**
 * @file
 * Resources
 */

/**
 * Callback to retrieve a project
 */
function _fserver_services_retrieve_project($short_name) {
  return fserver__project_load($short_name);
}