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
        foreach ($default_majors as $def_mjr) {
          $ret[] = $def_mjr['api'];
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
        foreach ($default_majors as $def_mjr) {
          if (empty($ret[$def_mjr['api']])) {
            $ret[$def_mjr['api']] = array($def_mjr['default_major']);
          }
          else {
            $ret[$def_mjr['api']][] = $def_mjr['default_major'];
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
  /* Prevent the recommended query from running. */
  function query() { }

  function get_value($values, $field = NULL) {
    // Find the project entity in the views values.
    foreach ($values->_field_data as $field_data_values) {
      if ($field_data_values['entity_type'] == 'project') {
        $wrapper = entity_metadata_wrapper('project', $field_data_values['entity']->id);
        $recommended_majors = $wrapper->recommended_major->value();
        $ret = array();
        foreach ($recommended_majors as $def_mjr) {
          $ret[] = $def_mjr['api'];
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

  /* Prevent the recommended query from running. */
  function query() { }

  function get_value($values, $field = NULL) {
    // Find the project entity in the views values.
    foreach ($values->_field_data as $field_data_values) {
      if ($field_data_values['entity_type'] == 'project') {
        $wrapper = entity_metadata_wrapper('project', $field_data_values['entity']->id);
        $recommended_majors = $wrapper->recommended_major->value();
        $ret = array();
        foreach ($recommended_majors as $def_mjr) {
          if (empty($ret[$def_mjr['api']])) {
            $ret[$def_mjr['api']] = array($def_mjr['recommended_major']);
          }
          else {
            $ret[$def_mjr['api']][] = $def_mjr['recommended_major'];
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
  /* Prevent the recommended query from running. */
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
