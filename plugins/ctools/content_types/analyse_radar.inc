<?php
$plugin = array(
  'title' => t('Analysis widget'),
  'content types' => 'analyse_radar_content_types',
  'render callback' => 'analyse_radar_content_type_render',
  'admin title' => 'analyse_radar_content_type_admin_title',
  'admin info' => 'analyse_radar_content_type_admin_info',
  'category' => t('Analyse'),
);

function analyse_radar_content_types() {
  $content_types = array();
  $base = array(
    'category' => t('Analyse'),
    'render callback' => 'analyse_radar_content_type_render',
    'admin title' => 'analyse_radar_content_type_admin_title',
    'admin info' => 'analyse_radar_content_type_admin_info'
  );
  
  $content_types['node_analysis_widget'] = $base + array(
    'title' => t('Node analysis widget'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
  );
  $content_types['user_analysis_widget'] = $base + array(
    'title' => t('User analysis widget'),
    'required context' => new ctools_context_required(t('User'), 'user'),
  );
  $content_types['term_analysis_widget'] = $base + array(
    'title' => t('Term analysis widget'),
    'required context' => new ctools_context_required(t('Term'), 'term'),
  );
  return $content_types;
}

function analyse_radar_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  if (empty($context) || empty($context->data)) {
    return;
  }
  
  $block = new stdClass();
  
  $widgets = analyse_analysis();
  $widget = array_pop($widgets);
  $block->content = '@todo: '. __FUNCTION__;
  
  return $block;
}

function analyse_radar_content_type_admin_title($subtype, $conf, $context) {
  return t('"@identifier" analyse widget', array('@identifier' => $context->identifier));
}

function analyse_radar_content_type_admin_info($subtype, $conf, $contexts) {
  $context = $contexts[$conf['context']];
  $info = new stdClass();
  $info->title = t('Info');
  $info->content = t('Using "@identifier" as source.', array('@identifier' => $context->identifier));// .'<pre style="font-size:x-small">'. var_export($context, TRUE) .'</pre>';
  return $info;
}


/**
 * Returns an edit form for custom type settings.
 */
function analyse_analyse_radar_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
