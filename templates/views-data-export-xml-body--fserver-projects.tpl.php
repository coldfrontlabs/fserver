<?php
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $rows: An array of row items. Each row is an array of content
 *   keyed by field ID.
 * - $header: an array of headers(labels) for fields.
 * - $themed_rows: a array of rows with themed fields.
 * @ingroup views_templates
 */
?>
<?php foreach ($themed_rows as $count => $row): ?>
  <<?php print $item_node; ?>>
  <?php foreach ($row as $field => $content): ?>
    <?php if (isset($field) and $field != 'view') : ?>
    <<?php print $xml_tag[$field]; ?>>
    <?php endif; ?>
    <?php print $content; ?>
    <?php if (isset($field) and $field != 'view') : ?>
    </<?php print $xml_tag[$field]; ?>>
    <?php endif?>
  <?php endforeach; ?>
  </<?php print $item_node; ?>>
<?php endforeach; ?>
