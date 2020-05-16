<?php

/**
 * @file
 * File for administrative functions.
 */

/**
 * Form to add custom table in table information table.
 */
function view_custom_table_add_custom_table_to_view_form($form, &$form_state) {
  if (!empty($form_state['page_num']) && $form_state['page_num'] == 2) {
    return view_custom_table_add_custom_table_column_relationship_form($form, $form_state);
  }

  // Display table name form if not set yet.
  $form_state['page_num'] = 1;

  $form['table_name'] = array(
    '#title' => t('Table Name'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#description' => t('Don not enter drupal core tables. it will create conflict.'),
  );
  $form['table_description'] = array(
    '#title' => t('Description'),
    '#type' => 'textarea',
    '#rows' => 5,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['next'] = array(
    '#type' => 'submit',
    '#value' => t('Next >>'),
    '#validate' => array('view_custom_table_add_custom_table_to_view_form_validate'),
    '#submit' => array('view_custom_table_add_custom_table_to_view_form_submit'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/structure/views/custom_table'),
  );
  return $form;
}

/**
 * Validate add_custom_table_to_view_form.
 */
function view_custom_table_add_custom_table_to_view_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  if (isset($values['table_name'])) {
    if (!db_table_exists($values['table_name'])) {
      form_set_error('table_name', t('Table "@table" do not exist in database.', array('@table' => $values['table_name'])));
    }
    if (db_table_exists('custom_table_view_data')) {
      $query = db_select('custom_table_view_data', 'ctvd')
        ->fields('ctvd', array('id'))
        ->condition('table_name', $values['table_name']);
      $custom_table_id = $query->execute()->fetchField();
      if ($custom_table_id) {
        form_set_error('table_name', t('@table is already available in views.', array('@table' => $values['table_name'])));
      }
    }
    else {
      drupal_set_message(t('"Views Custom Table" module is not installed properly, Please reinstall install it and try again.'), 'error');
    }
  }
}

/**
 * Submit and save add_custom_table_to_view_form.
 */
function view_custom_table_add_custom_table_to_view_form_submit($form, &$form_state) {

  // Save table name to form state.
  // to carry forward to subsequent pages in the form.
  $form_state['table_name'] = $form_state['values']['table_name'];
  $form_state['table_description'] = $form_state['values']['table_description'];

  // If we have table name rebuild form and show table settings form.
  $form_state['page_num'] = 2;
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Add columns relationship for @table.', array('@table' => $form_state['values']['table_name'])));
}

/**
 * Form to add table's column relationship with drupal tables.
 */
function view_custom_table_add_custom_table_column_relationship_form($form, &$form_state) {
  $form = array();
  $table_name = $form_state['table_name'];

  $all_entities = entity_get_info();
  $entities[''] = t('--None--');
  foreach ($all_entities as $entity_name => $all_entities_item) {
    $entities[$entity_name] = $all_entities_item['label'];
  }

  $form['columns'] = array(
    '#type' => 'fieldset',
    '#title' => t('"@table" Int Type Columns', array('@table' => $table_name)),
    '#tree' => TRUE,
  );

  $int_types = array('tinyint', 'smallint', 'mediumint', 'int', 'bigint');
  $text_query = format_string('DESCRIBE { @table_name }', array('@table_name' => $table_name));
  $query = db_query($text_query);
  foreach ($query as $row) {
    $row_type = explode('(', $row->Type);
    if (in_array($row_type[0], $int_types)) {
      $form['columns']['column_' . $row->Field] = array(
        '#type' => 'fieldset',
        '#title' => t('Relation of "@field_name" with', array('@field_name' => ucfirst($row->Field))),
        '#tree' => TRUE,
        '#attributes' => array('class' => array('container-inline')),
      );
      $form['columns']['column_' . $row->Field]['entity'] = array(
        '#type' => 'select',
        '#title' => t('Entity'),
        '#options' => $entities,
      );
      $form['columns']['column_' . $row->Field]['field'] = array(
        '#type' => 'hidden',
        '#value' => $row->Field,
      );
    }
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('view_custom_table_add_custom_table_column_relationship_form_submit'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/structure/views/custom_table'),
  );
  return $form;
}

/**
 * Submit and save add_custom_table_column_relationship_form.
 */
function view_custom_table_add_custom_table_column_relationship_form_submit($form, &$form_state) {
  global $user;
  $values = $form_state['values']['columns'];
  $relations = array();
  foreach ($values as $column) {
    if ($column['entity'] != '') {
      $relations[$column['field']] = $column['entity'];
    }
  }

  $serialize_relations = serialize($relations);
  if (db_table_exists('custom_table_view_data')) {
    if (isset($form_state['table_name'])) {
      $query = db_select('custom_table_view_data', 'ctvd')
        ->fields('ctvd', array('id'))
        ->condition('table_name', $form_state['table_name']);
      $custom_table_id = $query->execute()->fetchField();
      if ($custom_table_id) {
        $query = db_update('custom_table_view_data')
          ->fields(array(
            'column_relations' => $serialize_relations,
          ))
          ->condition('id', $custom_table_id)
          ->execute();
        drupal_set_message(t('Relations for "@table" are updated', array('@table' => $form_state['table_name'])));
      }
      else {
        $query = db_insert('custom_table_view_data')
          ->fields(array(
            'table_name' => $form_state['table_name'],
            'description' => $form_state['table_description'],
            'column_relations' => $serialize_relations,
            'created_by' => $user->uid,
          ))
          ->execute();
        drupal_set_message(t('Table "@table"s data is available in view now.', array('@table' => $form_state['table_name'])));
      }
      cache_clear_all();
    }
    drupal_set_message(t("Please clear all cache to start working."));
  }
  else {
    drupal_set_message(t('"Views Custom Table" module is not installed properly, Please reinstall install it and try again.'), 'error');
  }
  $form_state['redirect'] = 'admin/structure/views/custom_table';
}

/**
 * Function to edit custom table description.
 */
function view_custom_table_edit_custom_table_form($form, &$form_state, $table_id = NULL) {
  $table_info = view_custom_table_load_table($table_id);
  $form['table_name'] = array(
    '#title' => t('Table Name'),
    '#type' => 'textfield',
    '#disabled' => TRUE,
    '#default_value' => $table_info->table_name,
    '#description' => t('Don not enter drupal core tables. it will create conflict.'),
  );
  $form['table_description'] = array(
    '#title' => t('Description'),
    '#type' => 'textarea',
    '#rows' => 5,
    '#default_value' => $table_info->description,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#validate' => array('view_custom_table_edit_custom_table_form_validate'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/structure/views/custom_table'),
  );
  return $form;
}

/**
 * Function to validate custom table description.
 */
function view_custom_table_edit_custom_table_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  if (isset($values['table_name'])) {
    if (!db_table_exists($values['table_name'])) {
      form_set_error('table_name', t('Table "@table" do not exist in database.', array('@table' => $values['table_name'])));
    }
    if (db_table_exists('custom_table_view_data')) {
      if (strlen($values['table_description']) > 255) {
        form_set_error('table_description', t('Description can not be longer then 255.'));
      }
    }
    else {
      drupal_set_message(t('"Views Custom Table" module is not installed properly, Please reinstall install it and try again.'), 'error');
    }
  }
}

/**
 * Submit handler of view_custom_table_edit_custom_table_form()
 */
function view_custom_table_edit_custom_table_form_submit($form, &$form_state) {
  $query = db_update('custom_table_view_data')
    ->fields(array(
      'description' => $form_state['values']['table_description'],
    ))
    ->condition('table_name', $form_state['values']['table_name']);
  $result = $query->execute();
  if ($result) {
    drupal_set_message(t('@table_name has been updated.', array('@table_name' => $form_state['values']['table_name'])));
  }
  else {
    drupal_set_message(t('Could not update @table_name. Please check error log for more information.', array('@table_name' => $form_state['values']['table_name'])), 'error');
  }
  $form_state['redirect'] = 'admin/structure/views/custom_table';
}

/**
 * Function to update custom table relations.
 */
function view_custom_table_custom_table_update_relations_form($form, &$form_state, $table_id = NULL) {
  $table_info = view_custom_table_load_table($table_id);
  $table_name = $table_info->table_name;
  $form_state['table_name'] = $table_name;
  $table_relations = unserialize($table_info->column_relations);
  $views_info = view_custom_table_load_custom_table_views($table_info->table_name);
  if (!empty($views_info)) {
    drupal_set_message(t('views are using @table_name as base table, so presaved values can not be changed.', array('@table_name' => $table_info->table_name)), 'warning');
  }

  $all_entities = entity_get_info();
  $entities[''] = t('--None--');
  foreach ($all_entities as $entity_name => $all_entities_item) {
    $entities[$entity_name] = $all_entities_item['label'];
  }

  $form['columns'] = array(
    '#type' => 'fieldset',
    '#title' => t('"@table" Int Type Columns', array('@table' => $table_name)),
    '#tree' => TRUE,
  );

  $int_types = array('tinyint', 'smallint', 'mediumint', 'int', 'bigint');
  $text_query = format_string('DESCRIBE { @table_name }', array('@table_name' => $table_name));
  $query = db_query($text_query);
  foreach ($query as $row) {
    $row_type = explode('(', $row->Type);
    if (in_array($row_type[0], $int_types)) {
      $form['columns']['column_' . $row->Field] = array(
        '#type' => 'fieldset',
        '#title' => t('Relation of "@field_name" with', array('@field_name' => ucfirst($row->Field))),
        '#tree' => TRUE,
        '#attributes' => array('class' => array('container-inline')),
      );
      $form['columns']['column_' . $row->Field]['entity'] = array(
        '#type' => 'select',
        '#title' => t('Entity'),
        '#options' => $entities,
        '#default_value' => ($table_relations[$row->Field] != NULL) ? $table_relations[$row->Field] : '',
      );
      if (!empty($views_info) && isset($table_relations[$row->Field]) && $table_relations[$row->Field] != NULL) {
        $form['columns']['column_' . $row->Field]['entity']['#disabled'] = TRUE;
      }
      $form['columns']['column_' . $row->Field]['field'] = array(
        '#type' => 'hidden',
        '#value' => $row->Field,
      );
    }
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/structure/views/custom_table'),
  );
  return $form;
}

/**
 * Submit handler for view_custom_table_custom_table_update_relations_form()
 */
function view_custom_table_custom_table_update_relations_form_submit($form, &$form_state) {
  $values = $form_state['values']['columns'];
  $relations = array();
  foreach ($values as $column) {
    if ($column['entity'] != '') {
      $relations[$column['field']] = $column['entity'];
    }
  }

  $serialize_relations = serialize($relations);
  if (db_table_exists('custom_table_view_data')) {
    if (isset($form_state['table_name'])) {
      $query = db_update('custom_table_view_data')
        ->fields(array(
          'column_relations' => $serialize_relations,
        ))
        ->condition('table_name', $form_state['table_name'])
        ->execute();
      drupal_set_message(t('Relations for "@table" are updated', array('@table' => $form_state['table_name'])));
    }
    drupal_set_message(t("Please clear all cache to start working."));
  }
  else {
    drupal_set_message(t('"Views Custom Table" module is not installed properly, Please reinstall install it and try again.'), 'error');
  }
  $form_state['redirect'] = 'admin/structure/views/custom_table';
}

/**
 * Function to list all available custom tables for views.
 */
function view_custom_table_available_custom_tables_for_views() {
  global $user;
  if (db_table_exists('custom_table_view_data')) {
    drupal_add_css(drupal_get_path('module', 'views') . '/css/views-admin.seven.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'weight' => 10));
    drupal_add_css(drupal_get_path('module', 'views') . '/css/views-admin.ctools.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'weight' => 10));
    $query = db_select('custom_table_view_data', 'ctvd');
    $query->leftJoin('users', 'u', 'u.uid = ctvd.created_by');
    $query->fields('ctvd', array('table_name', 'description', 'id'));
    $query->fields('u', array('name', 'uid'));
    $query->condition('ctvd.created_by', $user->uid);
    $query->orderBy('ctvd.table_name');
    $all_custom_tables = $query->execute()->fetchAll();
    if (!empty($all_custom_tables)) {
      foreach ($all_custom_tables as $key => $custom_table) {
        $links = array(
          array('title' => t('Edit'), 'href' => 'admin/structure/views/custom_table/' . $custom_table->id . '/edit'),
          array('title' => t('Views'), 'href' => 'admin/structure/views/custom_table/' . $custom_table->id . '/views'),
          array('title' => t('Relations'), 'href' => 'admin/structure/views/custom_table/' . $custom_table->id . '/relations'),
          array('title' => t('Delete'), 'href' => 'admin/structure/views/custom_table/' . $custom_table->id . '/delete'),
        );
        $rows[] = array(
          $key,
          $custom_table->table_name,
          $custom_table->description,
          l(t('@user_name', array("@user_name" => $custom_table->name)), 'user/' . $custom_table->uid),
          theme('links__ctools_dropbutton', array('links' => $links)),
        );
      }
      $headers = array(
        '#',
        t('Table Name'),
        t('Description'),
        t('Created By'),
        t('Oprations'),
      );
      $output = theme('table', array('header' => $headers, 'rows' => $rows));
    }
    else {
      $output = "<h2 style='text-align:center;'>" . t('No Tables Available.') . "</h2>";
    }
  }
  else {
    $output = "";
    drupal_set_message(t('"Views Custom Table" module is not installed properly, Please reinstall install it and try again.'), 'error');
  }
  return $output;
}

/**
 * Function to list all available custom tables for views.
 */
function view_custom_table_all_available_custom_tables_for_views() {
  if (db_table_exists('custom_table_view_data')) {
    drupal_add_css(drupal_get_path('module', 'views') . '/css/views-admin.seven.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'weight' => 10));
    drupal_add_css(drupal_get_path('module', 'views') . '/css/views-admin.ctools.css', array('group' => CSS_THEME, 'every_page' => TRUE, 'weight' => 10));
    $query = db_select('custom_table_view_data', 'ctvd');
    $query->leftJoin('users', 'u', 'u.uid = ctvd.created_by');
    $query->fields('ctvd', array('table_name', 'description', 'id'));
    $query->fields('u', array('name', 'uid'));
    $query->orderBy('ctvd.table_name');
    $all_custom_tables = $query->execute()->fetchAll();
    if (!empty($all_custom_tables)) {
      foreach ($all_custom_tables as $key => $custom_table) {
        $links = array(
          array('title' => t('Edit'), 'href' => 'admin/structure/views/custom_table/' . $custom_table->id . '/edit'),
          array('title' => t('Views'), 'href' => 'admin/structure/views/custom_table/' . $custom_table->id . '/views'),
          array('title' => t('Relations'), 'href' => 'admin/structure/views/custom_table/' . $custom_table->id . '/relations'),
          array('title' => t('Delete'), 'href' => 'admin/structure/views/custom_table/' . $custom_table->id . '/delete'),
        );
        $rows[] = array(
          $key,
          $custom_table->table_name,
          $custom_table->description,
          l(t('@user_name', array("@user_name" => $custom_table->name)), 'user/' . $custom_table->uid),
          theme('links__ctools_dropbutton', array('links' => $links)),
        );
      }
      $headers = array(
        '#',
        t('Table Name'),
        t('Description'),
        t('Created By'),
        t('Oprations'),
      );
      $output = theme('table', array('header' => $headers, 'rows' => $rows));
    }
    else {
      $output = "<h2 style='text-align:center;'>No Tables Available.</h2>";
    }
  }
  else {
    $output = "";
    drupal_set_message(t('"Views Custom Table" module is not installed properly, Please reinstall install it and try again.'), 'error');
  }
  return $output;
}

/**
 * Function to display all views used by a custom table.
 */
function view_custom_table_custom_tables_views($table_id = NULL) {
  $table_info = view_custom_table_load_table($table_id);
  $views_info = view_custom_table_load_custom_table_views($table_info->table_name);
  if (!empty($views_info)) {
    foreach ($views_info as $item) {
      $rows[] = array(
        'id' => $item->vid,
        'name' => $item->human_name . '(' . $item->name . ')',
        'description' => $item->description,
        'link' => l(t('View'), 'admin/structure/views/view/' . $item->name . '/edit'),
      );
    }
    $headers = array(
      "Id",
      "Name",
      "Description",
      "Link",
    );
    $output = l(t('Return to list'), 'admin/structure/views/custom_table');
    $output .= '<p></p>';
    $output .= theme('table', array('header' => $headers, 'rows' => $rows));
    return $output;
  }
  else {
    $output = '<h3>' . t('No views created by using @table_name.', array('@table_name' => $table_info->table_name)) . '</h3>';
    return $output;
  }
}

/**
 * Function to delete a custom table form views.
 */
function view_custom_table_delete_custom_table_to_view_callback($table_id) {
  if ($table_id == NULL) {
    return "<h3 style='text-align: center;'>Table id not found in records.</h3>";
  }
  $query = db_select('custom_table_view_data', 'ctvd')
    ->fields('ctvd', array('table_name'))
    ->condition('id', $table_id);
  $table_name = $query->execute()->fetchField();
  if ($table_name == NULL) {
    return "<h3 style='text-align: center;'>Table id not found in records.</h3>";
  }
  else {
    $query = db_select('views_view', 'v')
      ->fields('v', array('vid', 'human_name', 'name'))
      ->condition('base_table', $table_name);
    $views_in_uses = $query->execute()->fetchAll();
    if (!empty($views_in_uses)) {
      foreach ($views_in_uses as $view_info) {
        $rows[] = array(
          $view_info->vid,
          $view_info->human_name,
          l(t('View'), 'admin/structure/views/view/' . $view_info->name . '/edit'),
        );
      }
      $headers = array(
        "Vid",
        "Name",
        "View",
      );
      drupal_set_message(t('Can not delete "@tablename". Following views are using "@tablename".', array('@tablename' => $table_name)), 'error');
      $output = l(t('Return to list'), 'admin/structure/views/custom_table');
      $output .= '<p></p>';
      $output .= theme('table', array('header' => $headers, 'rows' => $rows));
      return $output;
    }
    else {
      $delete_form = drupal_get_form('view_custom_table_delete_custom_table_to_view_form', $table_name);
      return render($delete_form);
    }
  }
}

/**
 * Function to implement delete custom table form.
 */
function view_custom_table_delete_custom_table_to_view_form($form, &$form_state, $table_name) {
  $form = array();
  $form['message'] = array(
    '#markup' => '<p>' . t('Do you want to delete custom view table "@table_name" ?', array('@table_name' => $table_name)) . '</p>',
  );
  $form_state['table_name'] = $table_name;
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );
  $form['actions']['cancel'] = array(
    '#markup' => l(t('Cancel'), 'admin/structure/views/custom_table'),
  );
  return $form;
}

/**
 * Submit for delete_custom_table_to_view_form().
 */
function view_custom_table_delete_custom_table_to_view_form_submit($form, $form_state) {
  if (isset($form_state['table_name'])) {
    db_delete('custom_table_view_data')
      ->condition('table_name', $form_state['table_name'])
      ->execute();
    drupal_set_message(t('@table_name has been deleted.', array('@table_name' => $form_state['table_name'])));
  }
}
