<?php

/**
 * @file
 * Custom RESTServer classes
 */

class FeatureServerProjectXMLFormatter implements ServicesFormatterInterface {
  public function render($data) {
    if (get_class($data) == 'SimpleXMLElement' || is_subclass_of($data, 'SimpleXMLElement')) {
      return $data->asXML();
    }
    else {
      $doc = new DOMDocument('1.0', 'utf-8');
      $root = $doc->createElement('project');
      $doc->appendChild($root);
      $root->setAttributeNS('http://www.w3.org/2000/xmlns/', 'xmlns:dc', 'http://purl.org/dc/elements/1.1/');
      $this->xml_recursive($doc, $root, $data);

      return $doc->saveXML();
    }
  }

  private function xml_recursive(&$doc, &$parent, $data) {
    if (is_object($data)) {
      $data = get_object_vars($data);
    }

    if (is_array($data)) {
      $assoc = FALSE || empty($data);
      foreach ($data as $key => $value) {
        if ($parent->tagName == 'releases') {
          $key = 'release';
          $assoc = TRUE;
        }
        elseif ($parent->tagName == 'files') {
          $key = 'file';
          $assoc = TRUE;
        }
        elseif (is_numeric($key)) {
          $key = 'item';
        }
        else {
          $assoc = TRUE;
          $key = preg_replace('/[^A-Za-z0-9_]/', '_', $key);
          $key = preg_replace('/^([0-9]+)/', '_$1', $key);
        }
        $element = $doc->createElement($key);
        $parent->appendChild($element);
        $this->xml_recursive($doc, $element, $value);
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
