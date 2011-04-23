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
    $options['hscroller_speed'] = array('default' => 30);
    $options['hscroller_direction'] = array('default' => 'left');
    $options['hscroller_mouseover'] = array('default' => 0);
    $options['hscroller_delay'] = array('default' => 0);
    $options['hscroller_bounce'] = array('default' => 0);
    $options['vscroller_speed'] = array('default' => 30);
    $options['vscroller_direction'] = array('default' => 'up');
    $options['vscroller_mouseover'] = array('default' => 0);
    $options['vscroller_delay'] = array('default' => 0);
    $options['vscroller_bounce'] = array('default' => 0);
    
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
      ),
    );
    // horizontal
    $form['hscroller_speed'] = array(
      '#type' => 'select',
      '#title' => t('Horizontal scroller speed'),
      '#description' => t(''),
      '#default_value' => $this->options['hscroller_speed'],
      '#options' => array(
        '10' => t('Very slow'),
        '20' => t('Slow'),
        '30' => t('Normal'),
        '40' => t('Fast'),
        '50' => t('Very fast'),
      ),
    );
    $form['hscroller_direction'] = array(
      '#type' => 'select',
      '#title' => t('Horizontal scroller direction'),
      '#description' => t(''),
      '#default_value' => $this->options['hscroller_direction'],
      '#options' => array(
        'left' => t('Left'),
        'right' => t('Right'),
      ),
    );
    $form['hscroller_delay'] = array(
      '#type' => 'select',
      '#title' => t('Horizontal scroller delay'),
      '#description' => t(''),
      '#default_value' => $this->options['hscroller_delay'],
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
    $form['hscroller_mouseover'] = array(
      '#type' => 'checkbox',
      '#title' => t('Horizontal scroller mouseover'),
      '#description' => t(''),
      '#default_value' => $this->options['hscroller_mouseover'],
    );
    $form['hscroller_bounce'] = array(
      '#type' => 'checkbox',
      '#title' => t('Horizontal scroller bounce'),
      '#description' => t(''),
      '#default_value' => $this->options['hscroller_bounce'],
    );
    // vertical
    $form['vscroller_speed'] = array(
      '#type' => 'select',
      '#title' => t('Vertical scroller speed'),
      '#description' => t(''),
      '#default_value' => $this->options['vscroller_speed'],
      '#options' => array(
        '10' => t('Very slow'),
        '20' => t('Slow'),
        '30' => t('Normal'),
        '40' => t('Fast'),
        '50' => t('Very fast'),
      ),
    );
    $form['vscroller_direction'] = array(
      '#type' => 'select',
      '#title' => t('Vertical scroller direction'),
      '#description' => t(''),
      '#default_value' => $this->options['vscroller_direction'],
      '#options' => array(
        'up' => t('Up'),
        'down' => t('Down'),
      ),
    );
    $form['vscroller_delay'] = array(
      '#type' => 'select',
      '#title' => t('Vertical scroller delay'),
      '#description' => t(''),
      '#default_value' => $this->options['vscroller_delay'],
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
    $form['vscroller_mouseover'] = array(
      '#type' => 'checkbox',
      '#title' => t('Vertical scroller mouseover'),
      '#description' => t(''),
      '#default_value' => $this->options['vscroller_mouseover'],
    );
    $form['vscroller_bounce'] = array(
      '#type' => 'checkbox',
      '#title' => t('Vertical scroller bounce'),
      '#description' => t(''),
      '#default_value' => $this->options['vscroller_bounce'],
    );

  }

  function validate() {
    $errors = parent::validate();
    if ($this->display->handler->use_pager()) {
      $errors[] = t('The ticker style cannot be used with a pager. Disable the "Use pager" option for this display.');
    }
    return $errors;
  }

}
