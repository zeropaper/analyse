<?php
$plugin = array(
  'single' => TRUE,
  'title' => t('Add subject'),
  'render callback' => 'analysis_add_subject_content_type_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'admin title' => 'analysis_add_subject_content_type_admin_title',
  'admin info' => 'analysis_add_subject_content_type_admin_info',
  'category' => t('Analysis'),
);

function analysis_add_subject_content_type_render($subtype, $conf, $args, $context, $incoming_content) {
  if (empty($context) || empty($context->data)) {
    return;
  }
  
  $block = new stdClass();
  
  $block->content = l(t('Add a subject'), 'node/add/analysis-subject', array(
    'query' => 'edit[field_analysis][nid][nid]='. $context->data->nid
  ));
  
  return $block;
}

function analysis_add_subject_content_type_admin_title($subtype, $conf, $context) {
  return t('"@identifier" analyse widget', array('@identifier' => $context->identifier));
}

function analysis_add_subject_content_type_admin_info($subtype, $conf, $contexts) {
  $context = $contexts[$conf['context']];
  $info = new stdClass();
  $info->title = t('Info');
  $info->content = t('Using "@identifier" as source.', array('@identifier' => $context->identifier));// .'<pre style="font-size:x-small">'. var_export($context, TRUE) .'</pre>';
  return $info;
}


/**
 * Returns an edit form for custom type settings.
 */
function analysis_analysis_add_subject_content_type_edit_form(&$form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
}
