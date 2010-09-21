<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Analysis widget'),
  'render callback' => 'analysis_radar_content_type_render',
  'admin title' => 'analysis_radar_content_type_admin_title',
  'admin info' => 'analysis_radar_content_type_admin_info',
  'category' => t('Analysis'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

function analysis_radar_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  if (empty($context) || empty($context->data)) {
    return;
  }
  
  $block = new stdClass();
  
  $widgets = analyse_analysis();
  $widget = array_pop($widgets);
  $values = analysis_get_values($context->data);
  $colors = array();
  foreach ($values as $criteria) {
    $value = array_pop($criteria);
    $colors[$value['color']] = substr($value['color'], 1);
  }
  $radar = analyse_radar_render(array(
    'values' => $values,
    'single' => FALSE,
    'widget' => $widget,
    'colors' => $colors,
  ));
  $block->content = $radar;
  
  return $block;
}

function analysis_radar_content_type_admin_title($subtype, $conf, $context) {
  return t('"@identifier" analysis radar', array('@identifier' => $context->identifier));
}

function analysis_radar_content_type_admin_info($subtype, $conf, $contexts) {
  $context = $contexts[$conf['context']];
  $info = new stdClass();
  $info->title = t('Info');
  $info->content = t('Using "@identifier" as source.', array('@identifier' => $context->identifier));// .'<pre style="font-size:x-small">'. var_export($context, TRUE) .'</pre>';
  return $info;
}


/**
 * Returns an edit form for custom type settings.
 */
function analysis_analysis_radar_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
