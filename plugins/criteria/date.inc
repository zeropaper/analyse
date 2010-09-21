<?php

$plugin = array(
  'title' => t('Date'),
  'description' => t('Provides a date criterion.'),
  
//  'label' => t('Date'), // this should be overriden by analyse_date_criteria_label_render()
  
);

/**
 * Renders a date (or a set of 2 dates, begining - end).
 * 
 * @param int $tag
 *  A UNIX timestamp
 * @param array $plugin
 *  Should be the $plugin array at the very begining of this file
 * @todo solve the timezone question
 * @todo provide formatting options (use the date module possibilities)
 * @todo if not exists, a formatting like "tue, 14:00 - 15:00"
 */
function analyse_date_criterion_label_render($tag, $plugin) {
  $dates = array_map('trim', explode('-', $tag));
  $first = array_pop($dates);
  $second = count($dates) ? array_pop($dates) : NULL;
  
  $output = '<span class="date'. ($second ? ' first' : '') .'">'. date('Y-m-d H:i', $first) .'</span>';
  if ($second) {
    $output .= ' <span class="separator">-</span> ';
    $output .= '<span class="date second">'. date('Y-m-d H:i', $second) .'</span>';
  }
  
  return '<span class="dates">'. $output .'</span>';
}