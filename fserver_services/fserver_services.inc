<?php

/**
 * @file
 * Custom RESTServer classes
 */

class FeatureServerProjectXMLView extends RESTServerViewBuiltIn {
  public function render() {
    switch ($this->arguments['format']) {
      case 'xml':
      case 'x':
        return $this->render_xml($this->model);
    }
    return '';
  }

  private function render_xml($data) {
    $doc = new DOMDocument('1.0', 'utf-8');
    $root = $doc->createElement('project');
    $doc->appendChild($root);

    $this->xml_recurse($doc, $root, $data);

    return $doc->saveXML();
  }
}