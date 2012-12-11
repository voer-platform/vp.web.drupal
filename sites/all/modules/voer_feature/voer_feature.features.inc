<?php
/**
 * @file
 * voer_feature.features.inc
 */

/**
 * Implements hook_node_info().
 */
function voer_feature_node_info() {
  $items = array(
    'voer_content' => array(
      'name' => t('VOER Content'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
