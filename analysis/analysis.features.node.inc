<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _analysis_node_info() {
  $items = array(
    'analysis' => array(
      'name' => t('Analysis'),
      'module' => 'features',
      'description' => t('An analysis might bight conducted on multiple subjects. Every subjects are rated on a criteria set.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'analysis_subject' => array(
      'name' => t('Analysis subject'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
