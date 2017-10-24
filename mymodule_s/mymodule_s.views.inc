<?php
/**
 * Implements hook_views_data().
 */

  function mymodule_s_views_data() {
    $data = [];

    $data['mymodule_s']['table']['group'] = t('my_groupe');

    // таблиця з якої беремо дані
    $data ['mymodule']['table']['base'] = [
      'field' => 'id',
      'title' => t('entity_label'),
    ];
    $data['mymodule_s']['table']['entity type'] = 'my entity';
    // поле id
    $data['mymodule_s']['id'] = [
      'title'    => t('my_id_label'),
      'help'     => t('my_id_description'),
      'field'    => [
        'handler'        => 'MY_FIELD_HANDLER',
        'click sortable' => TRUE,
      ],
      'argument' => [
        'handler'       => 'MY_ID_HANDLER_ARGUMENT',
        'name field'    => 'id',
        'numeric'       => TRUE,
        'validate type' => 'id',
      ],
      'filter'   => [
        'handler' => 'views_handler_filter_numeric',
      ],
      'sort'     => [
        'handler' => 'views_handler_sort'
      ],
    ];
    // поле заголовок
    $data['mymodule_s']['title'] = [
      'title'    => t('my_title_label'),
      'help'     => t('my_title_description'),
      'field'    => [
        'field'                   => 'title',
        'group'                   => t('my_group'),
        'handler'                 => 'my_field_handler',
        'click sortable'          => TRUE,
        // посилання на сутність
        'link_to_product_default' => TRUE,
      ],
      'argument' => [
        'handler' => 'views_handler_argument_string',
      ],
      'filter'   => [
        'handler' => 'views_handler_filter_string',
      ],
      'sort'     => [
        'handler' => 'views_handler_sort',
      ],
    ];
    // поле з доступними операціями на нашою entity
    $data['mymodule_s']['operations'] = [
      'field' => [
        'title'   => t('operations_link'),
        'help'    => t('operations_description'),
        'handler' => 'MY_HANDLER_ID_OPERATIONS',
      ],
    ];
    return $data;
  }



