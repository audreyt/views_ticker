<?php
/**
 * @file
 * Views integration for ticker module.
 */

/**
 * Implements hook_views_plugin().
 */
function views_ticker_views_plugins() {
  $plugins['style']['views_ticker'] = array(
    'title' => t('Views Ticker'),
    'help' => t('Display links to items while scrolling through them.'),
    'handler' => 'views_ticker_style_plugin',
    'path' => drupal_get_path('module', 'views_ticker') . '/includes',
    'theme' => 'views_ticker_view',
    'theme path' => drupal_get_path('module', 'views_ticker') . '/includes',
    'uses row plugin' => TRUE,
    'uses options' => TRUE,
    'uses grouping' => FALSE,
    'type' => 'normal',
  );
  return $plugins;
}

function template_preprocess_views_ticker_view(&$variables) {

  $path = drupal_get_path('module', 'views_ticker');
  drupal_add_css($path .'/views.ticker.scroller.css');

  $view = $variables['view'];
  $options = $view->style_plugin->options;
  $variables['viewname'] = $view->name;
  $variables['field'] = $view->field['title']->field_alias;
  $variables['scroller_type'] = $options['scroller_type'];

  if ($options['scroller_type'] == 'vertical' ) {
    $variables['align'] = 'scroller-'. $options['scroller_type'];
    $variables['direction'] = 'jscroller2_'. $options['vscroller_direction'];
    $variables['speed'] = 'jscroller2_speed-'. $options['vscroller_speed'];
    $variables['jmouse'] = ($options['vscroller_mouseover'] ? 'jscroller2_mousemove' : '' );
    $variables['delay'] = ($options['vscroller_delay'] ? 'jscroller2_delay-'. $options['vscroller_delay'] : '' );
    $variables['bounce'] = ($options['vscroller_bounce'] ? 'jscroller2_alternate' : '' );
  }
  elseif ($options['scroller_type'] == 'horizontal') {
    $variables['align'] = 'scroller-'. $options['scroller_type'];
    $variables['direction'] = 'jscroller2_'. $options['hscroller_direction'];
    $variables['speed'] = 'jscroller2_speed-'. $options['hscroller_speed'];
    $variables['jmouse'] = ($options['hscroller_mouseover'] ? 'jscroller2_mousemove' : '' );
    $variables['delay'] = ($options['hscroller_delay'] ? 'jscroller2_delay-'. $options['hscroller_delay'] : '' );
    $variables['bounce'] = ($options['hscroller_bounce'] ? 'jscroller2_alternate' : '' );
  }
  else {
    $variables['align'] = 'fade-container';
  }

  if ($options['scroller_type'] == 'fade') {
    drupal_add_js($path .'/js/views.ticker.fade.js');
    drupal_add_js('(function($) { Drupal.behaviors.views_ticker = { attach: function (context) { $("#views-ticker-fade-' . $view->name . '").newsTicker(); } };})(jQuery);', 'inline');
  }
  elseif ($options['scroller_type'] == 'bbc') {
    drupal_add_js($path .'/js/views.ticker.bbc.js');
    drupal_add_js('(function($) { Drupal.behaviors.views_ticker = { attach: function (context) { var options = { newsList: "#views-ticker-fade-'. $view->name .'", startDelay: 10, placeHolder1: " |"}; $().newsTicker(options);}};})(jQuery);', 'inline');
  }
  else {
    drupal_add_js($path .'/js/views.ticker.scroller.js');
  }


}
