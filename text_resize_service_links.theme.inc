<?php
function theme_text_resize_increase_service_link($variables) {
  return _theme_text_resize_service_link('increase');
}

function theme_text_resize_decrease_service_link($variables) {
  return _theme_text_resize_service_link('decrease');
}

function _theme_text_resize_service_link($inc_dec) {
  // Add js, css, and library
  $content = array(
    '#attached' => array(
      'js' => array(
        array(
          'data' => "var text_resize_scope = " . drupal_json_encode(variable_get('text_resize_scope', 'main')) . ";
          var text_resize_minimum = " . drupal_json_encode(variable_get('text_resize_minimum', '12')) . ";
          var text_resize_maximum = " . drupal_json_encode(variable_get('text_resize_maximum', '25')) . ";
          var text_resize_line_height_allow = " . drupal_json_encode(variable_get('text_resize_line_height_allow', FALSE)) . ";
          var text_resize_line_height_min = " . drupal_json_encode(variable_get('text_resize_line_height_min', 16)) . ";
          var text_resize_line_height_max = " . drupal_json_encode(variable_get('text_resize_line_height_max', 36)) . ";",
          'type' => 'inline',
        ),
        array(
          'data' => drupal_get_path('module', 'text_resize') . '/text_resize.js',
          'type' => 'file',
        )
      ),
      'css' => array(
        // drupal_get_path('module', 'text_resize') . '/text_resize.css',
      ),
      'library' => array(
        array('system', 'jquery.cookie')
      ),
    ),
  );
  if ($inc_dec == 'increase') {
    $content['#markup'] = t('<a href="javascript:;" class="changer" id="text_resize_increase"><sup>+</sup>A</a>');
  }
  if ($inc_dec == 'decrease') {
    $content['#markup'] = t('<a href="javascript:;" class="changer" id="text_resize_decrease"><sup>-</sup>A</a>');
  }
  return render($content);
}