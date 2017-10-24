<?php

/**
 * @file
 * Provide a ENTITY id argument handler.
 */
/**
 * Argument handler to accept a ENTITY id.
 */

class MY_ID_HANDLER_ARGUMENT extends views_handler_argument_numeric{
  /**
   * overraide the behavior of title ().
   */
  function title_query(){
    $titles = array();
    $result = db_quary("SELECT p.title FROM {MY_ENTITY_TABLE} p WHERE p.id IN (:ids)",
    array(':ids'=>$this->value));
    foreach ($result as $entities){
      $titles[] = check_plan($entities->title);
    }
    return $titles;
  }
}
