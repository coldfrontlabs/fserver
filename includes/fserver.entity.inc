<?php

/**
 * @file
 * Entity functions
 */

/**
 * Project entities
 */

/**
 * Load a single project entity by id
 */
function project_load($id) {
  return entity_load_single('project', $id);
}

/**
 * Load a single project entity by id
 */
function project_load_multiple(array $ids) {
  return entity_load('project', $ids);
}

/**
 * Save a single project entity
 */
function project_save($project) {
  if (empty($project->created)) {
    $project->created = time();
  }
  $project->changed = time();
  return entity_save('project', $project);
}

/**
 * Delete a single project entity
 */
function project_delete($id) {
  entity_delete('project', $id);
}

/**
 * Delete multiple project entities
 */
function project_delete_multiple(array $ids) {
  entity_delete_multiple('project', $ids);
}

/**
 * Default access callback for project entities
 */
function project_access($op, $entity, $account = NULL, $entity_type) {
  if (user_access('administer fserver', $account)) {
    return TRUE;
  }

  global $user;
  if (!isset($account->uid)) {
    $account = $user;
  }

  list(, , $bundle) = entity_extract_ids($entity_type, $entity);
  // Check for their own stuff
  if ($op != 'create') {
    if (isset($entity->uid) and $entity->uid == $account->uid) {
      if (user_access($op . ' own fserver ' . $bundle . ' projects', $account)) {
        return TRUE;
      }
    }

    return user_access($op . ' any fserver ' . $bundle . ' projects', $account);
  }
  else {
    return user_access($op . ' fserver ' . $bundle . ' projects', $account);
  }
}

/**
 * URI Callback
 */
function project_uri($entity) {
  return array(
    'path' => 'admin/content/projects/' . $entity->id,
  );
}

/**
 * Release entities
 */

/**
 * Load a single release entity by id
 */
function release_load($id) {
  return entity_load_single('release', $id);
}

/**
 * Load a multple release entity by id
 */
function release_load_multiple(array $ids) {
  return entity_load('release', $ids);
}

/**
 * Save a single release entity
 */
function release_save($release) {
  if (empty($release->date)) {
    $release->date = time();
  }
  return entity_save('release', $project);
}

/**
 * Delete a single release entity
 */
function release_delete($id) {
  entity_delete('release', $id);
}

/**
 * Delete multiple release entities
 */
function release_delete_multiple(array $ids) {
  entity_delete_multiple('release', $ids);
}

/**
 * Access callback for release entities
 */
function release_access($op, $entity, $account = NULL, $entity_type) {
  if (user_access('administer fserver', $account)) {
    return TRUE;
  }

  global $user;
  if (!isset($account->uid)) {
    $account = $user;
  }

  list(, , $bundle) = entity_extract_ids($entity_type, $entity);
  // Check for their own stuff
  if ($op != 'create') {
    if (isset($entity->uid) and $entity->uid == $account->uid) {
      if (user_access($op . ' own fserver ' . $bundle . ' releases', $account)) {
        return TRUE;
      }
    }

    return user_access($op . ' any fserver ' . $bundle . ' releases', $account);
  }
  else {
    return user_access($op . ' fserver ' . $bundle . ' releases', $account);
  }
}

/**
 * URI Callback
 */
function release_uri($entity) {
  return array(
    'path' => 'admin/content/releases/' . $entity->id,
  );
}

/**
 * Options list callback for the supported_majors property
 */
function _fserver_project_property_supported_majors_options() {
  // @todo make this intelligent by looking at the attached releases
  // @todo
  return array(
    '5.x' => t('5.x'),
    '6.x' => t('6.x'),
    '7.x' => t('7.x'),
    '8.x' => t('8.x'),
    '9.x' => t('9.x'),
  );
}

/**
 * Options list callback for the recommended_majors property
 */
function _fserver_project_property_recommended_majors_options() {
  // @todo make this intelligent by looking at the attached releases
  return array(
    1 => 1,
    2 => 2,
    3 => 3,
    4 => 4,
  );
}

/**
 * Base class for Project entities
 */
class FserverProject extends Entity {
  public function __construct($values = array()) {
    // @todo add constructor validation
    parent::__construct($values, 'project');
  }

  public function next_version($api, $release_type = NULL) {
    // retrieve existing releases for this project
    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'release')
                     ->fieldCondition('field_project_reference', 'target_id', $this->id)
                     ->propertyCondition('api', $api)
                     //->propertyCondition('version_extra', $release_type, 'STARTS_WITH')
                     ->propertyOrderBy('date', 'DESC')
                     ->execute();

    if (!empty($results['release'])) {
      $reltypes = array('dev', 'alpha', 'beta', 'rc', 'full');
      $tag = '';
      // First, we find the latest non-dev release created for this project.
      $latest_non_dev = array_reduce($results['release'], function($carry, $item) {
        $release = entity_load_single('release', $item->id);
        if ($release->version_extra != 'dev') {
          if (!isset($carry)) {
            return $release;
          }
          else {
            $carry_dt = new DateObject($carry->date);
            $rel_dt = new DateObject($release->date);
            if ($carry_dt->difference($rel_dt, 'seconds', FALSE) > 0) {
              return $release;
            }
            else {
              return $carry;
            }
          }
        }
        return $carry;
      });

      $latest_extra_type = !empty($latest_non_dev->version_extra) ? drupal_substr($latest_non_dev->version_extra, 0, drupal_strlen($latest_non_dev->version_extra)-1) : '';
      // Next, check release logic and build & return the tag
      if (!$latest_non_dev) {
        // latest release is a dev release.  Next release will drop the .x (for patch version) and simply be .1
        $latest_dev = array_reduce($results['release'], function($carry, $item) {
          $release = entity_load_single('release', $item->id);
          if ($release->version_extra == 'dev') {
            if (!isset($carry)) {
              return $release;
            }
            else {
              $carry_dt = new DateObject($carry->date);
              $rel_dt = new DateObject($release->date);
              if ($carry_dt->difference($rel_dt, 'seconds', FALSE) > 0) {
                return $release;
              }
              else {
                return $carry;
              }
            }
          }
          return $carry;
        });

        $tag = $latest_dev->api . '-' . $latest_dev->version_major . '.0';
        if (isset($release_type) && $release_type != 'full') {
          $tag .= '-' . $release_type . '1';
        }
        return $tag;
      }
      else if (isset($release_type) && !empty($release_type)) {
        if ('full' == $release_type) {
          if (empty($latest_non_dev->version_extra)) {
            // latest version is a full version, next full will increment minor/patch version
            $tag = $latest_non_dev->api . '-' . $latest_non_dev->version_major . '.' . (intval($latest_non_dev->version_patch) + 1);
          }
          else {
            // latest release is alpha/beta/rc, next full will drop the extra and simply be the api-major.minor version
            $tag = $latest_non_dev->api . '-' . $latest_non_dev->version_major . '.' . intval($latest_non_dev->version_patch);
          }
        }
        else {
          if (empty($latest_extra_type)   // latest release is a full release, but requested tag is earlier in cycle
              || array_search($release_type, $reltypes) < array_search($latest_extra_type, $reltypes)) {
            // requesting a tag earlier in the release cycle than the most recent release, fail
            return FALSE;
          }
          else if (array_search($release_type, $reltypes) > array_search($latest_extra_type, $reltypes)) {
            // moving to a later phase in the release cycle, set extra version back to 1
            $extra_version = 1;
          }
          else {
            // moving one version later in the same release phase, increment extra version
            $extra_version = intval(drupal_substr($latest_non_dev->version_extra, drupal_strlen($latest_non_dev->version_extra)-1)) + 1;
          }
          $tag = $latest_non_dev->api . '-' . $latest_non_dev->version_major . '.' . $latest_non_dev->version_patch . '-' . $release_type . $extra_version;
        }
      }
      else {
        // no release type specified, just increment in current release phase
        if (!empty($latest_extra_type)) {
          $extra_version = intval(drupal_substr($latest_non_dev->version_extra, drupal_strlen($latest_non_dev->version_extra)-1)) + 1;
          $tag = $latest_non_dev->api . '-' . $latest_non_dev->version_major . '.' . $latest_non_dev->version_patch . '-' . $latest_extra_type . $extra_version;
        }
        else {
          // latest version is a full version, next full will increment minor/patch version
          $tag = $latest_non_dev->api . '-' . $latest_non_dev->version_major . '.' . (intval($latest_non_dev->version_patch) + 1);
        }
      }
      return $tag;
    }
    // Did something go wrong?  Why are we here?  Maybe there are no existing releases...
    return FALSE;
  }
}

/**
 * Controller class for Project entities
 */
class FserverProjectController extends EntityAPIController {
  public function delete($ids, DatabaseTransaction $transaction = NULL) {

    $entities = $ids ? $this->load($ids) : FALSE;
    if (!$entities) {
      // Do nothing, in case invalid or no ids have been passed.
      return;
    }
    else {
      foreach ($entities as $entity) {
        $query = new EntityFieldQuery();
        $releases = $query
          ->entityCondition('entity_type', 'release')
          ->fieldCondition("field_project_reference", "target_id", $entity->id)
          ->execute();
        if (isset($releases['release'])) {
          entity_delete_multiple('release', array_keys($releases['release']));
        }
      }
    }
    parent::delete($ids, $transaction);
  }
}

/**
 * Base class for Release entities
 */
class FserverRelease extends Entity {
  public function __construct($values = array()) {
    // @todo add release validation
    parent::__construct($values, 'release');

    $this->generateReleaseName($values);
  }

  /**
   * Generate release name
   *
   * Pattern: <project_name> <api_version>-<release_version>
   * Ex: views 7.x-1.x-dev
   *
   * @param array $args [optional]
   *  List of arguments passed into the constructor. Used to determine
   *  how the release object is being created.
   */
  public function generateReleaseName($args = array()) {

    if (isset($args['is_new']) and $args['is_new'] == TRUE) {
      // For now we do basic detection on new objects. But we
      // should instead detect if the values for the name field
      // are set.
      // @todo
    }
    else {
      if (!empty($this->version_patch) || ($this->version_patch == 0 && $this->version_extra != 'dev')) {
        $this->tag = $this->api . '-' . $this->version_major . '.' . $this->version_patch;
        $this->version = $this->tag;
      }
      else {
        $this->tag = $this->api . '-' . $this->version_major . '.x';
        $this->version = $this->tag;
      }
      if (!empty($this->version_extra)) {
        $this->version .= '-' . $this->version_extra;
      }

      $this->name = $this->project_short_name . ' ' . $this->version;
    }
  }
}

/**
 * Controller class for Release entities
 */
class FserverReleaseController extends EntityAPIController {
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $entity->date = time();
    $entity->generateReleaseName();
    parent::save($entity, $transaction);
  }
}

/**
 * Project and releases in one object.
 *
 * Used to generate the update XML for a given project.
 */
class FserverProjectRelease {
  protected $project;

  /**
   * Build a FserverProjectRelease object
   */
  public function __construct($project, $api) {
    if (is_object($project) and get_class($project) == 'FserverProject') {
      $this->project = $project;
      $this->prepareReleases($api);
      $this->prepareProject($api);
      $this->alterReleaseData();
    }
    else {
      $this->project = FALSE;
    }
  }

  public function getProject() {
    return $this->project;
  }

  protected function prepareReleases($api) {
    $releases = fserver__release_load_by_project($this->project->short_name, $api);

    if (is_array($releases)) {
      foreach ($releases as &$release) {
        unset($release->id);
        unset($release->type);
        unset($release->project_short_name);
        unset($release->uid);

        // Build files array
        $files = array();
        foreach ($release->field_release_files[LANGUAGE_NONE] as $key => $file) {
          $files[$key] = _fserver_release_file_format($file);
        }
        $release->files = $files;

        // Clean out file fields
        unset($release->field_release_files);
        unset($release->field_release_notes);

        // Copy the first files entry into the main release XML as the default
        // download
        $release->download_link = $release->files[0]['url'];
        $release->mdhash = $release->files[0]['md5'];
        $release->filesize = $release->files[0]['size'];
        $release->status = "published";
      }
    }
    $this->project->releases = $releases;
  }

  /**
   * Prepare the project object
   */
  private function prepareProject($api) {
    // Change some of the project data to match the XML requirements
    unset($this->project->id);
    unset($this->project->field_compatibility);
    $this->project->api_version = $api;
    $this->project->type = 'project_' . $this->project->type;
  }

  /**
   * Allow other modules to alter the release data
   */
  private function alterReleaseData() {
    $project = $this->project;
    drupal_alter('fserver__project_release_data', $project);
    $this->project = $project;
  }
}

class FserverEntityInlineEntityFormController extends EntityInlineEntityFormController {

}

class FserverProjectEntityInlineEntityFormController extends FserverEntityInlineEntityFormController {
  /**
   * Override method entityForm().
   *
   * Load the workflow and return the workflow form to be used for the inline entity form.
   */
  public function entityForm($form, &$form_state) {
    $form = parent::entityForm($form, $form_state);
    $form_state['project'] = $form['#entity'];
    module_load_include('inc', 'fserver', 'includes/fserver.admin');
    $form = project_form($form, $form_state);
    unset($form['actions']);
    return $form;
  }

  /**
   * Override method entityFormSubmit(&$entity_form, &$form_state)
   */
  function entityFormSubmit(&$entity_form, &$form_state) {
    parent::entityFormSubmit($entity_form, $form_state);
    $project = $entity_form['#entity'];
    // Properties part of a field group won't be set unless we place those
    // properties directly at the root of the project entity.
    if (isset($project->advanced) and !empty($project->advanced)) {
      foreach ($project->advanced as $property => $value) {
        $project->$property = $value;
      }
    }
    if (empty($project->created)) {
      $project->created = time();
    }
    $project->changed = time();
  }
}

class FserverReleaseEntityInlineEntityFormController extends FserverEntityInlineEntityFormController {
  /**
   * Override method entityForm().
   *
   * Load the workflow and return the workflow form to be used for the inline entity form.
   */
  public function entityForm($form, &$form_state) {
    $form = parent::entityForm($form, $form_state);
    $form_state['release'] = $form['#entity'];
    module_load_include('inc', 'fserver', 'includes/fserver.admin');
    $form = release_form($form, $form_state);
    unset($form['save']);
    return $form;

  }
}
