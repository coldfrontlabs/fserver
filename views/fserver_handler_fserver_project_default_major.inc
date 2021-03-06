<?php

class fserver_handler_fserver_project_default_major_api extends views_handler_field {
  /* Prevent the default query from running. */
  function query() { }

  function get_value($values, $field = NULL) {
    // Find the project entity in the views values.
    foreach ($values->_field_data as $field_data_values) {
      if ($field_data_values['entity_type'] == 'project') {
        $wrapper = entity_metadata_wrapper('project', $field_data_values['entity']->id);
        $default_majors = $wrapper->default_major->value();
        $ret = array();
        foreach ($default_majors as $def_maj) {
          $ret[] = $def_maj['api'];
        }
        return $ret;
      }
    }
  }

  function render($values) {
    $items = $this->get_value($values);
    $render = array(
      'items' => $items,
      'title' => '',
      'type' => 'ul',
      'attributes' => array(),
    );

    $output = theme_item_list($render);
    return $output;
  }
}

class fserver_handler_fserver_project_default_major_default_major extends views_handler_field {
  /* Prevent the default query from running. */
  function query() { }

  function get_value($values, $field = NULL) {
    // Find the project entity in the views values.
    foreach ($values->_field_data as $field_data_values) {
      if ($field_data_values['entity_type'] == 'project') {
        $wrapper = entity_metadata_wrapper('project', $field_data_values['entity']->id);
        $default_majors = $wrapper->default_major->value();
        $ret = array();
        foreach ($default_majors as $def_maj) {
          if (empty($ret[$def_maj['api']])) {
            $ret[$def_maj['api']] = array($def_maj['default_major']);
          }
          else {
            $ret[$def_maj['api']][] = $def_maj['default_major'];
          }
        }
        return $ret;
      }
    }
  }

  function render($values) {
    $items = $this->get_value($values);
    $render = array(
      'items' => $items,
      'title' => '',
      'type' => 'ul',
      'attributes' => array(),
    );

    $output = theme_item_list($render);
    return $output;
  }
}

class fserver_handler_fserver_project_default_major_fields_compare extends views_handler_filter {
  /* Prevent the default query from running. */
  function query() { }
}

class fserver_handler_fserver_project_recommended_major_api extends views_handler_field {
  /* Prevent the default query from running. */
  function query() { }

  function get_value($values, $field = NULL) {
    // Find the project entity in the views values.
    foreach ($values->_field_data as $field_data_values) {
      if ($field_data_values['entity_type'] == 'project') {
        $wrapper = entity_metadata_wrapper('project', $field_data_values['entity']->id);
        $recommended_majors = $wrapper->recommended_major->value();
        $ret = array();
        foreach ($recommended_majors as $rec_maj) {
          $ret[] = $rec_maj['api'];
        }
        return $ret;
      }
    }
  }

  function render($values) {
    $items = $this->get_value($values);
    $render = array(
      'items' => $items,
      'title' => '',
      'type' => 'ul',
      'attributes' => array(),
    );

    $output = theme_item_list($render);
    return $output;
  }
}

class fserver_handler_fserver_project_recommended_major_recommended_major extends views_handler_field {

  /* Prevent the default query from running. */
  function query() { }

  function get_value($values, $field = NULL) {
    // Find the project entity in the views values.
    foreach ($values->_field_data as $field_data_values) {
      if ($field_data_values['entity_type'] == 'project') {
        $wrapper = entity_metadata_wrapper('project', $field_data_values['entity']->id);
        $recommended_majors = $wrapper->recommended_major->value();
        $ret = array();
        foreach ($recommended_majors as $rec_maj) {
          if (empty($ret[$rec_maj['api']])) {
            $ret[$rec_maj['api']] = array($rec_maj['recommended_major']);
          }
          else {
            $ret[$rec_maj['api']][] = $rec_maj['recommended_major'];
          }
        }
        return $ret;
      }
    }
  }

  function render($values) {
    $items = $this->get_value($values);
    $render = array(
      'items' => $items,
      'title' => '',
      'type' => 'ul',
      'attributes' => array(),
    );

    $output = theme_item_list($render);
    return $output;
  }
}

class fserver_handler_filter_fserver_project_recommended_major extends views_handler_filter {
  /* Prevent the default query from running. */
  function query() { }

  /**
   * override post_execute().
   *
   * This method will do a couple things: first, it will ensure
   * only releases whose version_major matches the project's
   * recommended major will be included, second: only one release
   * per API will be kept (this logic assumes the releases are
   * sorted by most recent to oldest).
   */
  function post_execute(&$values) {
    $apis_already_included = array();
    foreach ($values as $key => $value) {
      $release = NULL;
      $project = NULL;
      foreach ($value->_field_data as $field_data_item) {
        if ($field_data_item['entity_type'] == 'release') {
          $release = $field_data_item['entity'];
        }
        elseif ($field_data_item['entity_type'] == 'project') {
          $project = $field_data_item['entity'];
        }
      }
      if (!empty($release) and !empty($project)) {
        $pwrapper = entity_metadata_wrapper('project', $project);
        $rwrapper = entity_metadata_wrapper('release', $release);
        $recommended_majors = $pwrapper->recommended_major->value();
        $api = $rwrapper->api->value();
        // Find the recommended major that corresponds to the release's API
        foreach ($recommended_majors as $rec_maj) {
          if ($rec_maj['api'] == $api) {
            if (in_array($api, $api_already_included) or ($rec_maj['recommended_major'] != $rwrapper->version_major->value())) {
              unset($values[$key]);
            }
            else {
              $api_already_included[] = $api;
            }
            break;
          }
        }
      }
    }
  }
}

class fserver_handler_fserver_project_supported_majors_api extends views_handler_field {
  /* Prevent the default query from running. */
  function query() { }

  function get_value($values, $field = NULL) {
    // Find the project entity in the views values.
    foreach ($values->_field_data as $field_data_values) {
      if ($field_data_values['entity_type'] == 'project') {
        $wrapper = entity_metadata_wrapper('project', $field_data_values['entity']->id);
        $supported_majors = $wrapper->supported_majors->value();
        $ret = array();
        foreach ($supported_majors as $sup_maj) {
          $ret[] = $sup_maj['api'];
        }
        return $ret;
      }
    }
  }

  function render($values) {
    $items = $this->get_value($values);
    $render = array(
      'items' => $items,
      'title' => '',
      'type' => 'ul',
      'attributes' => array(),
    );

    $output = theme_item_list($render);
    return $output;
  }
}

class fserver_handler_fserver_project_supported_majors_supported_majors extends views_handler_field {

  /* Prevent the default query from running. */
  function query() { }

  function get_value($values, $field = NULL) {
    // Find the project entity in the views values.
    foreach ($values->_field_data as $field_data_values) {
      if ($field_data_values['entity_type'] == 'project') {
        $wrapper = entity_metadata_wrapper('project', $field_data_values['entity']->id);
        $supported_majors = $wrapper->supported_majors->value();
        $ret = array();
        foreach ($supported_majors as $sup_maj) {
          if (empty($ret[$sup_maj['api']])) {
            $ret[$sup_maj['api']] = array($sup_maj['api'], 'children' => $sup_maj['supported_majors']);
          }
          else {
            $ret[$sup_maj['api']]['children'] = $sup_maj['supported_majors'];
          }
        }
        return $ret;
      }
    }
  }

  function render($values) {
    $items = $this->get_value($values);
    $render = array(
      'items' => $items,
      'title' => '',
      'type' => 'ul',
      'attributes' => array(),
    );

    $output = theme_item_list($render);
    return $output;
  }
}

class fserver_handler_filter_fserver_project_supported_majors extends views_handler_filter {
  /* Prevent the default query from running. */
  function query() { }

  function post_execute(&$values) {
    foreach ($values as $key => $value) {
      $release = NULL;
      $project = NULL;
      foreach ($value->_field_data as $field_data_item) {
        if ($field_data_item['entity_type'] == 'release') {
          $release = $field_data_item['entity'];
        }
        elseif ($field_data_item['entity_type'] == 'project') {
          $project = $field_data_item['entity'];
        }
      }
      if (!empty($release) and !empty($project)) {
        $pwrapper = entity_metadata_wrapper('project', $project);
        $rwrapper = entity_metadata_wrapper('release', $release);
        $supported_majors = $pwrapper->supported_majors->value();
        $api = $rwrapper->api->value();
        $exclude = TRUE;
        // Find the recommended major that corresponds to the release's API
        foreach ($supported_majors as $sup_maj) {
          if ($sup_maj['api'] == $api) {
            // Supported majors contain multiple values, loop through and determine
            // if the release's major version is supported.
            foreach ($sup_maj['supported_majors'] as $maj) {
              if ($maj == $rwrapper->version_major->value()) {
                $exclude = FALSE;
                break;
              }
            }
            break;
          }
        }
        if ($exclude) {
          unset($values[$key]);
        }
      }
    }
  }
}

class fserver_handler_filter_fserver_project_other_releases extends views_handler_filter {
  /* Prevent the default query from running. */
  function query() { }

  /**
   * override post_execute().
   *
   * This method reverses the logic of recommended releases,
   * acting as a set exclude leaving all other releases.
   * Use this filter in conjunction with the supported majors
   * filter to obtain all valid, supported other (non-recommended)
   * releases. 
   */
  function post_execute(&$values) {
    $apis_already_excluded = array();
    foreach ($values as $key => $value) {
      $release = NULL;
      $project = NULL;
      foreach ($value->_field_data as $field_data_item) {
        if ($field_data_item['entity_type'] == 'release') {
          $release = $field_data_item['entity'];
        }
        elseif ($field_data_item['entity_type'] == 'project') {
          $project = $field_data_item['entity'];
        }
      }
      if (!empty($release) and !empty($project)) {
        $pwrapper = entity_metadata_wrapper('project', $project);
        $rwrapper = entity_metadata_wrapper('release', $release);
        $recommended_majors = $pwrapper->recommended_major->value();
        $api = $rwrapper->api->value();
        // Find the recommended major that corresponds to the release's API
        foreach ($recommended_majors as $rec_maj) {
          if ($rec_maj['api'] == $api) {
            if (!in_array($api, $api_already_excluded) and ($rec_maj['recommended_major'] == $rwrapper->version_major->value())) {
              unset($values[$key]);
              $api_already_excluded[] = $api;
            }
            break;
          }
        }
      }
    }
  }
}

