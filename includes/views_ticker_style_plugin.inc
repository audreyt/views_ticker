<?php

/**
 * @file
 * Contains the views ticker style plugin.
 */

/**
 * Style plugin to render each item in an ordered or unordered list.
 *
 * @ingroup views_style_plugins
 */
class views_ticker_style_plugin extends views_plugin_style {
  function option_definition() {
	$options = parent::option_definition();
	
	$options['scroller_type'] = array('default' => 'horizontal');

	$options['hscroller_Options']['default']=array (
	'hscroller_speed' => 30,
	'hscroller_direction' => 'left',
	'hscroller_mouseover' => 0,
	'hscroller_delay' => 0,
	'hscroller_bounce' => 0,
	);
	
	$options['vscroller_Options']['default']=array (
	'vscroller_speed' => 30,
	'vscroller_direction' => 'up',
	'vscroller_mouseover' => 0,
	'vscroller_delay' => 0,
	'vscroller_bounce' => 0,
	);
	
	$options['vTicker_Options']['default']=array (
	'vTicker_mouseover' => 0,
	'vTicker_speed' => 500,
	'vTicker_pause' => 1000,
	'vTicker_items' => 5,
	'vTicker_direction' => 'up',
	);
	
	return $options;
  }

  function options_form(&$form, &$form_state) {
	parent::options_form($form, $form_state);

	$form['scroller_type'] = array(
		'#type' => 'select',
		'#title' => t('Scroller type'),
		'#description' => t(''),
		'#default_value' => $this->options['scroller_type'],
		'#options' => array(
		'horizontal' => t('Horizontal'),
		'vertical' => t('Vertical'),
		'fade' => t('Fade'),
		'bbc' => t('BBC'),
		'vTicker' => t('vTicker'), #http://www.htmldrive.net/items/show/266/jquery-vticker-vertical-news-ticker.html
	  ),
	);
	
//####### horizontal Options ########
	// horizontal
	
	$form['hscroller_Options'] = array(
		'#type' => 'fieldset',
		'#title' => t('Horizontal Options'),
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
	);
	
	$form['hscroller_Options']['hscroller_speed'] = array(
		'#type' => 'select',
		'#title' => t('Horizontal scroller speed'),
		'#description' => t(''),
		'#default_value' => $this->options['hscroller_Options']['hscroller_speed'],
		'#options' => array(
		'10' => t('Very slow'),
		'20' => t('Slow'),
		'30' => t('Normal'),
		'40' => t('Fast'),
		'50' => t('Very fast'),
	  ),
	);
	
	$form['hscroller_Options']['hscroller_direction'] = array(
		'#type' => 'select',
		'#title' => t('Horizontal scroller direction'),
		'#description' => t(''),
		'#default_value' => $this->options['hscroller_Options']['hscroller_direction'],
		'#options' => array(
		'left' => t('Left'),
		'right' => t('Right'),
	  ),
	);
	
	$form['hscroller_Options']['hscroller_delay'] = array(
		'#type' => 'select',
		'#title' => t('Horizontal scroller delay'),
		'#description' => t(''),
		'#default_value' => $this->options['hscroller_Options']['hscroller_delay'],
		'#options' => array(
		'0' => t('None'),
		'1' => t('One second'),
		'2' => t('Two seconds'),
		'3' => t('Three seconds'),
		'4' => t('Four seconds'),
		'5' => t('Five seconds'),
		'10' => t('Ten seconds'),
	  ),
	);
	
	$form['hscroller_Options']['hscroller_mouseover'] = array(
		'#type' => 'checkbox',
		'#title' => t('Horizontal scroller mouseover'),
		'#description' => t(''),
		'#default_value' => $this->options['hscroller_Options']['hscroller_mouseover'],
	);
	
	$form['hscroller_Options']['hscroller_bounce'] = array(
		'#type' => 'checkbox',
		'#title' => t('Horizontal scroller bounce'),
		'#description' => t(''),
		'#default_value' => $this->options['hscroller_Options']['hscroller_bounce'],
	);


//####### vertical Options ########
	// vertical
	$form['vscroller_Options'] = array(
		'#type' => 'fieldset',
		'#title' => t('Vertical Options'),
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
	);

	$form['vscroller_Options']['vscroller_speed'] = array(
		'#type' => 'select',
		'#title' => t('Vertical scroller speed'),
		'#description' => t(''),
		'#default_value' => $this->options['vscroller_Options']['vscroller_speed'],
		'#options' => array(
		'10' => t('Very slow'),
		'20' => t('Slow'),
		'30' => t('Normal'),
		'40' => t('Fast'),
		'50' => t('Very fast'),
	  ),
	);
	
	$form['vscroller_Options']['vscroller_direction'] = array(
		'#type' => 'select',
		'#title' => t('Vertical scroller direction'),
		'#description' => t(''),
		'#default_value' => $this->options['vscroller_Options']['vscroller_direction'],
		'#options' => array(
		'up' => t('Up'),
		'down' => t('Down'),
	  ),
	);
	
	$form['vscroller_Options']['vscroller_delay'] = array(
		'#type' => 'select',
		'#title' => t('Vertical scroller delay'),
		'#description' => t(''),
		'#default_value' => $this->options['vscroller_Options']['vscroller_delay'],
		'#options' => array(
		'0' => t('None'),
		'1' => t('One second'),
		'2' => t('Two seconds'),
		'3' => t('Three seconds'),
		'4' => t('Four seconds'),
		'5' => t('Five seconds'),
		'10' => t('Ten seconds'),
	  ),
	);
	
	$form['vscroller_Options']['vscroller_mouseover'] = array(
		'#type' => 'checkbox',
		'#title' => t('Vertical scroller mouseover'),
		'#description' => t(''),
		'#default_value' => $this->options['vscroller_Options']['vscroller_mouseover'],
	);
	
	$form['vscroller_Options']['vscroller_bounce'] = array(
		'#type' => 'checkbox',
		'#title' => t('Vertical scroller bounce'),
		'#description' => t(''),
		'#default_value' => $this->options['vscroller_Options']['vscroller_bounce'],
	);

//####### vTicker Options ########

	$form['vTicker_Options'] = array(
	  '#type' => 'fieldset',
	  '#title' => t('vTicker Options'),
	  '#collapsible' => TRUE,
	  '#collapsed' => TRUE,
	);

	$form['vTicker_Options']['vTicker_items'] = array(
	  '#type' => 'textfield',
	  '#title' => t('vTicker number of items'),
	  '#description' => t('Number of items to display at a time'),
	  '#default_value' => $this->options['vTicker_Options']['vTicker_items'],
	  '#element_validate' => array('vTicker_numeric_element_validate'),
	);

	$form['vTicker_Options']['vTicker_mouseover'] = array(
	  '#type' => 'checkbox',
	  '#title' => t('vTicker scroller mouseover'),
	  '#description' => t(''),
	  '#default_value' => $this->options['vTicker_Options']['vTicker_mouseover'],
	);
	
	$form['vTicker_Options']['vTicker_pause'] = array(
	  '#type' => 'select',
	  '#title' => t('vTicker scroller pause'),
	  '#description' => t(''),
	  '#default_value' => $this->options['vTicker_Options']['vTicker_pause'],
	  '#options' => array(
		500 => t('500 millisecond'),
		1000 => t('One second'),
		2000 => t('Two seconds'),
		3000 => t('Three seconds'),
		4000 => t('Four seconds'),
		5000 => t('Five seconds'),
	  ),
	);
	
	$form['vTicker_Options']['vTicker_speed'] = array(
	  '#type' => 'select',
	  '#title' => t('vTicker scroller speed'),
	  '#description' => t(''),
	  '#default_value' => $this->options['vTicker_Options']['vTicker_speed'],
	  '#options' => array(
		1000 => t('Very slow'),
		700 => t('Slow'),
		500 => t('Normal'),
		300 => t('Fast'),
		150 => t('Very fast'),
	  ),
	);

	$form['vTicker_Options']['vTicker_direction'] = array(
		'#type' => 'select',
		'#title' => t('vTicker scroller direction'),
		'#description' => t(''),
		'#default_value' => $this->options['vTicker_Options']['vTicker_direction'],
		'#options' => array(
		  'up' => t('Up'),
		  'down' => t('Down'),
		),
	);
  }

  function validate() 
  {
	$errors = parent::validate();
	if ($this->display->handler->use_pager()) 
	{
	  $errors[] = t('The ticker style cannot be used with a pager. Disable the "Use pager" option for this display.');
	}
	return $errors;
  }

}

function vTicker_numeric_element_validate($element, &$form_state) 
{
   if (!is_numeric($element['#value']) || $element['#value']<=0 ) 
   {
	 form_error($element, t('Enter a positive number'));
   }
}
