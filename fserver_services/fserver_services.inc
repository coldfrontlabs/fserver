<?php

/**
 * @file
 * Custom RESTServer classes
 */

class FeatureServerProjectXMLView extends RESTServerViewBuiltIn {
  private function render_xml($data) {
    $doc = new DOMDocument('1.0', 'utf-8');
    $root = $doc->createElement('project');
    $doc->appendChild($root);

    $this->xml_recurse($doc, $root, $data);

    return $doc->saveXML();
  }
}