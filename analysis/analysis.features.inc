<?php

/**
 * Implementation of hook_content_default_fields().
 */
function analysis_content_default_fields() {
  module_load_include('inc', 'analysis', 'analysis.defaults');
  $args = func_get_args();
  return call_user_func_array('_analysis_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function analysis_ctools_plugin_api() {
  module_load_include('inc', 'analysis', 'analysis.defaults');
  $args = func_get_args();
  return call_user_func_array('_analysis_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_node_info().
 */
function analysis_node_info() {
  module_load_include('inc', 'analysis', 'analysis.features.node');
  $args = func_get_args();
  return call_user_func_array('_analysis_node_info', $args);
}

/**
 * Implementation of hook_default_page_manager_handlers().
 */
function analysis_default_page_manager_handlers() {
  module_load_include('inc', 'analysis', 'analysis.defaults');
  $args = func_get_args();
  return call_user_func_array('_analysis_default_page_manager_handlers', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function analysis_strongarm() {
  module_load_include('inc', 'analysis', 'analysis.defaults');
  $args = func_get_args();
  return call_user_func_array('_analysis_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function analysis_views_default_views() {
  module_load_include('inc', 'analysis', 'analysis.features.views');
  $args = func_get_args();
  return call_user_func_array('_analysis_views_default_views', $args);
}
