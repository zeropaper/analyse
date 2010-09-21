<?php

function analyse_devel_overview() {
  $output = '';
  $widgets = analyse_analysis();
  $widget = array_pop($widgets);
  
  ctools_include('context');
  $context = ctools_context_create('node', node_load(1));
  $output = drupal_get_form($widget->name .'_analyse_form', $context);
  
  return $output;
}

function analyse_devel_widgets() {
  $output = '<dl>';
  $widgets = analyse_analysis();
  
  foreach ($widgets as $widget) {
    $details = '';
    $output .= '<dt>'. $widget->title .'</dt><dd><div class="summary">'. $widget->description .'</div><div class="details">'. $details .'</div></dd>';
  }
  
  return $output .'</dl>';
}