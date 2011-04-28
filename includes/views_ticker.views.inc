<?php

/**
 * @file
 * Views integration for ticker module.
 */

/**
 * Implements hook_views_plugin().
 */
function views_ticker_views_plugins()
{
	$plugins['style']['views_ticker'] = array('title' => t('Views Ticker'), 'help' => t('Display links to items while scrolling through them.'), 'handler' => 'views_ticker_style_plugin', 'path' => drupal_get_path('module', 'views_ticker') . '/includes', 'theme' => 'views_ticker_view', 'theme path' => drupal_get_path('module', 'views_ticker') . '/includes', 'uses row plugin' => true, 'uses options' => true, 'uses grouping' => false, 'type' => 'normal', );
	return $plugins;
}

function template_preprocess_views_ticker_view(&$variables)
{
	$path = drupal_get_path('module', 'views_ticker');
	drupal_add_css($path . '/views.ticker.scroller.css');
	
	$view = $variables['view'];
	$options = $view->style_plugin->options;
	$variables['viewname'] = $view->name;
	$variables['field'] = $view->field['title']->field_alias;
	$variables['scroller_type'] = $options['scroller_type'];
	
	if ($options['scroller_type'] == 'vertical')
	{
		$variables['align'] = 'scroller-' . $options['scroller_type'];
		
		$variables['direction'] = 'jscroller2_' . $options['vscroller_Options']['vscroller_direction'];
		$variables['speed'] = 'jscroller2_speed-' . $options['vscroller_Options']['vscroller_speed'];
		$variables['jmouse'] = ($options['vscroller_Options']['vscroller_mouseover'] ? 'jscroller2_mousemove' : '');
		$variables['delay'] = ($options['vscroller_Options']['vscroller_delay'] ? 'jscroller2_delay-' . $options['vscroller_delay'] : '');
		$variables['bounce'] = ($options['vscroller_Options']['vscroller_bounce'] ? 'jscroller2_alternate' : '');
	}
	elseif ($options['scroller_type'] == 'horizontal')
	{
		$variables['align'] = 'scroller-' . $options['scroller_type'];
		
		$variables['direction'] = 'jscroller2_' . $options['hscroller_Options']['hscroller_direction'];
		$variables['speed'] = 'jscroller2_speed-' . $options['hscroller_Options']['hscroller_speed'];
		$variables['jmouse'] = ($options['hscroller_Options']['hscroller_mouseover'] ? 'jscroller2_mousemove' : '');
		$variables['delay'] = ($options['hscroller_Options']['hscroller_delay'] ? 'jscroller2_delay-' . $options['hscroller_delay'] : '');
		$variables['bounce'] = ($options['hscroller_Options']['hscroller_bounce'] ? 'jscroller2_alternate' : '');
	}
	elseif ($options['scroller_type'] == 'vTicker')
	{
		$vTickerOpts = $options['vTicker_Options']['vTicker_mouseover'] ? 'mousePause: true' : 'mousePause: false';
		$vTickerOpts .= ' , speed:' . $options['vTicker_Options']['vTicker_speed'];
		$vTickerOpts .= ' , pause:' . $options['vTicker_Options']['vTicker_pause'];
		$vTickerOpts .= ' , showItems:' . $options['vTicker_Options']['vTicker_items'];
		$vTickerOpts .= ' , direction: "' . $options['vTicker_Options']['vTicker_direction'] . '"';
	}
	else
	{
		$variables['align'] = 'fade-container';
	}
	
	if ($options['scroller_type'] == 'fade')
	{
		drupal_add_js($path . '/js/views.ticker.fade.js');
		drupal_add_js('(function($) { Drupal.behaviors.views_ticker1 = { attach: function (context) { $("#views-ticker-fade-' . $view->name . '").newsTickerFade(); } };})(jQuery);', 'inline');
	}
	elseif ($options['scroller_type'] == 'bbc')
	{
		drupal_add_js($path . '/js/views.ticker.bbc.js');
		drupal_add_js('(function($) { Drupal.behaviors.views_ticker2 = { attach: function (context) { var options = { newsList: "#views-ticker-bbc-' . $view->name . '", startDelay: 10, placeHolder1: " |"}; $().newsTicker(options);}};})(jQuery);', 'inline');
	}
	elseif ($options['scroller_type'] == 'vTicker')
	{
		drupal_add_js($path . '/js/jquery.vticker-min.js');
		drupal_add_js('(function($) { Drupal.behaviors.views_ticker = { attach: function (context) { $("#views-ticker-vTicker-' . $view->name . '").vTicker({' . $vTickerOpts . '}); } };})(jQuery);', 'inline');
	}
	else
	{
		drupal_add_js($path . '/js/views.ticker.scroller.js');
	}
}
