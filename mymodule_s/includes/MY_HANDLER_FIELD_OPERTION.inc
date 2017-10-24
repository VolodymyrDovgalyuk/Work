<?php

/**
 * @file
 * Contains the entity's operations field handler.
 */

/**
 * Field handler to present a entity's operations links.
 */
class MY_HANDLER_FIELD_OPERATIONS extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['id'] = 'id';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['add_destination'] = TRUE;
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['add_destination'] = array(
      '#type' => 'checkbox',
      '#title' => t('MY_TITLE.'),
      '#default_value' => $this->options['add_destination'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $id = $this->get_value($values, 'id');

    $links = array();

    $links['edit'] = array(
      'title' => t('Edit'),
      'href' => 'MY_PATH_TO_ENTITY/' . $id . '/edit',
      'html' => FALSE,
    );

    $links['delete'] = array(
      'title' => t('Delete'),
      'href' => 'MY_PATH_TO_ENTITY/' . $id . '/delete',
      'html' => FALSE,
    );

    if ($this->options['add_destination']) {
      $links['edit']['query'] = drupal_get_destination();
      $links['delete']['query'] = drupal_get_destination();
    }

    return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
  }
}
