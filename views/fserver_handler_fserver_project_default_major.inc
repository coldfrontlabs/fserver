<?php

class fserver_handler_fserver_project_default_major_api extends views_handler_field {
/*
  function construct() {
    parent::construct();
  }

  function init(&$view, &$options) {
    parent::init($view, $options);
  }

  function option_definition() {
    return parent::option_definition();
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
*/
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

/*
  function pre_render(&$values) {
dpm('pre render');
    dpm($values);
  }
*/

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
/*
  function construct() {
    parent::construct();
  }

  function option_definition() {
    return parent::option_definition();
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
*/

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

  function pre_render(&$values) {
    //dpm($values);
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
  /**
   * Provide a list of all operators.
   *
  function fields_operator_options() {
    return array(
      '=' => t('Is equal to'),
      '<>' => t('Is not equal to'),
    );
  }
*/

  /* Prevent the default query from running. */
  function query() { }

  function post_execute(&$values) {
dpm($values);

  }
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
        $recommended_majors = $pwrapper->recommended_major->value();
        $api = $rwrapper->api->value();
        // Find the recommended major that corresponds to the release's API
        foreach ($recommended_majors as $rec_maj) {
          if ($rec_maj['api'] == $api) {
            if ($rec_maj['recommended_major'] != $rwrapper->version_major->value()) {
              unset($values[$key]);
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
