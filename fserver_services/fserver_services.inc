<?php

/**
 * @file
 * Custom RESTServer classes
 */

class FeatureServerProjectXMLFormatter extends ServicesFormatterInterface {
  public function render($data) {
    $doc = new DOMDocument('1.0', 'utf-8');
    $root = $doc->createElement('result');
    $doc->appendChild($root);

    $this->xml_recursive($doc, $root, $data);

    return $doc->saveXML();
  }

  private function xml_recursive(&$doc, &$parent, $data) {
    if (get_class($data) == 'SimpleXMLElement' || is_subclass_of($data, 'SimpleXMLElement')) {
      watchdog('fserver_services', 'loaded special case', array(), WATCHDOG_DEBUG);
      return $data->asXML();
    }
    else {
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
}
