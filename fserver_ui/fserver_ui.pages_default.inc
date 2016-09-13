<?php
/**
 * @file
 * fserver_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function fserver_ui_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Project Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'fserver_project_page' => 'fserver_project_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol_bricks';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '780d391b-f590-4adc-af91-fef90bfb9813';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b1e9c37f-b9c9-4b65-83ad-a3cfd07d1a78';
  $pane->panel = 'left_above';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b1e9c37f-b9c9-4b65-83ad-a3cfd07d1a78';
  $display->content['new-b1e9c37f-b9c9-4b65-83ad-a3cfd07d1a78'] = $pane;
  $display->panels['left_above'][0] = 'new-b1e9c37f-b9c9-4b65-83ad-a3cfd07d1a78';
  $pane = new stdClass();
  $pane->pid = 'new-8ee429c8-d54b-4676-9dca-a4d373e586f1';
  $pane->panel = 'middle';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'build_mode' => 'full',
    'identifier' => '',
    'link' => 0,
    'context' => 'argument_entity_id:node_1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8ee429c8-d54b-4676-9dca-a4d373e586f1';
  $display->content['new-8ee429c8-d54b-4676-9dca-a4d373e586f1'] = $pane;
  $display->panels['middle'][0] = 'new-8ee429c8-d54b-4676-9dca-a4d373e586f1';
  $pane = new stdClass();
  $pane->pid = 'new-e81e8f20-8570-4e79-bdf0-9d8717d8b92f';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'fserver_ui_releases';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'fserver_ui_block_releases',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e81e8f20-8570-4e79-bdf0-9d8717d8b92f';
  $display->content['new-e81e8f20-8570-4e79-bdf0-9d8717d8b92f'] = $pane;
  $display->panels['middle'][1] = 'new-e81e8f20-8570-4e79-bdf0-9d8717d8b92f';
  $pane = new stdClass();
  $pane->pid = 'new-9e3ed650-1549-4330-9533-db033cd27bde';
  $pane->panel = 'right_above';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_fserver_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'image_style' => 'medium',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9e3ed650-1549-4330-9533-db033cd27bde';
  $display->content['new-9e3ed650-1549-4330-9533-db033cd27bde'] = $pane;
  $display->panels['right_above'][0] = 'new-9e3ed650-1549-4330-9533-db033cd27bde';
  $pane = new stdClass();
  $pane->pid = 'new-74979d26-832a-4579-b702-94285a69ff2b';
  $pane->panel = 'right_above';
  $pane->type = 'node_updated';
  $pane->subtype = 'node_updated';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'format' => 'medium',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '74979d26-832a-4579-b702-94285a69ff2b';
  $display->content['new-74979d26-832a-4579-b702-94285a69ff2b'] = $pane;
  $display->panels['right_above'][1] = 'new-74979d26-832a-4579-b702-94285a69ff2b';
  $pane = new stdClass();
  $pane->pid = 'new-dd587ed1-da6e-4d38-bd1a-7789c431760d';
  $pane->panel = 'right_above';
  $pane->type = 'node_created';
  $pane->subtype = 'node_created';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'format' => 'medium',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'dd587ed1-da6e-4d38-bd1a-7789c431760d';
  $display->content['new-dd587ed1-da6e-4d38-bd1a-7789c431760d'] = $pane;
  $display->panels['right_above'][2] = 'new-dd587ed1-da6e-4d38-bd1a-7789c431760d';
  $pane = new stdClass();
  $pane->pid = 'new-9697c204-6996-4ceb-868e-db159b0a227c';
  $pane->panel = 'right_above';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_fserver_demo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'url_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '80',
      'nofollow' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '9697c204-6996-4ceb-868e-db159b0a227c';
  $display->content['new-9697c204-6996-4ceb-868e-db159b0a227c'] = $pane;
  $display->panels['right_above'][3] = 'new-9697c204-6996-4ceb-868e-db159b0a227c';
  $pane = new stdClass();
  $pane->pid = 'new-dbe74f10-4dfc-413d-8204-50b8cd0c767a';
  $pane->panel = 'right_above';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_fserver_documentation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'url_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '80',
      'nofollow' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'dbe74f10-4dfc-413d-8204-50b8cd0c767a';
  $display->content['new-dbe74f10-4dfc-413d-8204-50b8cd0c767a'] = $pane;
  $display->panels['right_above'][4] = 'new-dbe74f10-4dfc-413d-8204-50b8cd0c767a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b1e9c37f-b9c9-4b65-83ad-a3cfd07d1a78';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}
