<?php

/**
 * @file
 * Contains the MY_ENTITY ID field handler
 */
/**
 * Field handler to provide simple rander that allows linking to entity.
 */

class MY_FIELD_HANDLER extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);

    // якщо вибрана опція : виводити у вигляді силки то дістаємо Entity ID.

  if (!empty($this->options['link_to_entity']))
    $this->additional_fields['id'] = array ('table' => 'MY_ENTITY_TABLE','field'=>'id');
  }
}
/**
 * оголошуємо налаштування для цього поля
 */
  function option_definition(){
    $options = parent::option_definition();
    $options['link_to_entity']=array ('default'=>'none');
    return $options;
  }
/**
 * форма з налаштуваннми
 */

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_entity'] = [
      '#title'         => t('MY_LINK_TITLE'),
      '#description'   => t('MY_LINK_FIELD_DESCRIPTION'),
      '#type'          => 'checkbox',
      '#default_value' => !empty($this->options['link_to_entity']),
    ];
    parent::options_form($form, $form_state);
  }
/**
 * виводимо поле у вигляді ссилки на entity
 */
  function render_link($data, $values){
    if (!empty($this->options['link_to_entity'])&&!empty($this->additional_fields['id'])){
      $id = $this->get_value($values, 'id');
      $this->options['alter']['make_link']= TRUE;
      $this->options['alter']['path']='MY_PATH_TO_ENTITY/'. 'id';
    }
    return $data;
  }
  /**
   * Виводимо поле
   */
  function render($values) {
    $value = $this->get_value($values);
    return $this ->render_link($this->santize_value($value), $values);
  }




