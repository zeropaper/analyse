<?php


function analyse_get_criterion($name) {
  static $criteria;
  if (empty($criteria)) {
    $criteria = analyse_get_criteria();
  }
  return $criteria[$name];
}


function analyse_get_criteria() {
  return ctools_get_plugins('analyse', 'criteria');
}

function analyse_criterion_widget(&$element, $edit, $form_state, $complete_form) {
  if (!is_array($element['#criterion'])) {
    return;
  }
  
  $plugin = $element['#criterion'];
  
  $standard = $plugin['module'] .'_'. $plugin['name'] .'_criterion_widget';
  if ($function = ctools_plugin_get_function($plugin, 'widget')) {
    $function($element, $edit, $form_state, $complete_form);
  }
  elseif (function_exists($standard)) {
    $standard($element, $edit, $form_state, $complete_form);
  }
  
}

/**
 * Renders a criterion label.
 * 
 * Note that if your plugin has a function like 
 * MYMODULE_PLUGINNAME_criteria_label_render(), you do not need to
 * declare it in the $plugin definition.
 * 
 * @param mixed $plugin
 *  Can be either the name of a criterion or a criterion
 *  plugin definition array.
 * @param string $criterion_tag
 *  The "tag" used for a vote in votingapi
 * @param array $options
 *  
 * @return string
 *  A nicely formatted HTML string for the label...
 */
function analyse_criterion_label_render($plugin, $criterion_tag, $options = array()) {
  
  if (is_string($plugin)) {
    $plugin = analyse_get_criterion($plugin);
  }
  
  if (!is_array($plugin)) {
    return '';
  }
  
  $standard = $plugin['module'] .'_'. $plugin['name'] .'_criterion_label_render';
  if ($function = ctools_plugin_get_function($plugin, 'label render')) {
    return $function($criterion_tag, $plugin, $options);
  }
  elseif (function_exists($standard)) {
    return $standard($criterion_tag, $plugin, $options);
  }
  return check_plain($criterion_tag);
}