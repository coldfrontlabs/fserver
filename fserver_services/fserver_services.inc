<?php

/**
 * @file
 * Custom RESTServer classes
 */

class FeatureServerProjectXMLView extends RESTServerView {
  public function render() {
    switch ($this->arguments['format']) {
      case 'x':
      case 'xml':
        return $this->render_xml($this->model);
    }
    return '';
  }

  private function render_xml($data) {
    $doc = new DOMDocument('1.0', 'utf-8');
    $root = $doc->createElement('project');
    $doc->appendChild($root);

    $this->fserver_xml_recurse($doc, $root, $data);

    return $doc->saveXML();
  }

  private function xml_recurse(&$doc, &$parent, $data) {
    if (is_object($data)) {
      $data = get_object_vars($data);
    }

    if (is_array($data)) {
      $assoc = FALSE || empty($data);
      foreach ($data as $key => $value) {
        if (is_numeric($key)) {
          $key = 'item';
        }
        else {
          $assoc = TRUE;
          $key = preg_replace('/[^A-Za-z0-9_]/', '_', $key);
          $key = preg_replace('/^([0-9]+)/', '_$1', $key);
        }
        $element = $doc->createElement($key);
        $parent->appendChild($element);
        $this->xml_recurse($doc, $element, $value);
      }

      if (!$assoc) {
        $parent->setAttribute('is_array', 'true');
      }
    }
    elseif ($data !== NULL) {
      $parent->appendChild($doc->createTextNode($data));
    }
  }

}