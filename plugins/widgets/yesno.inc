<?php
$plugin = array(
  'title' => t('Yes or no'),
  'description' => t('A simple answer'),
);

function analyse_yesno_widget(&$element, $settings) {
  $settings = array_merge(array(
    'type' => 'checkbox',
    'value' => isset($element['#value']) ? $element['#value'] : NULL,
    'theme' => NULL
  ), $settings);
  
  $element['#type'] = $settings['type'];
  $element['#default_value'] = $settings['value'];
  
  if ($settings['theme']) {
    $element['#theme'] = $settings['theme'];
  }
}