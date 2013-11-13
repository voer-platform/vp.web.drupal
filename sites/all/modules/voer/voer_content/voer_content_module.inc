<?php

/**
 * @file
 * Extensible wizard form example.
 */

/**
 * Extensible wizard form example.
 *
 * This is an example of a multistep form using a wizard style. It will include
 * the 'Previous' and 'Next' buttons when required, and a 'Finish' button at the
 * last stage of the form submission.
 *
 * This example is an extensible skeleton that can include (even
 * programatically) more steps. The demonstration form includes three steps,
 * each step having its own validation functions.
 *
 * How to extend this example:
 * - Steps are defined in the _form_example_steps() function. Include or alter
 *   the steps as you require.
 * - For each step, implement the corresponding 'form' function (see
 *   'form_example_wizard_personal_info' for the first step in this example.)
 *   Each step is a regular form, and the wizard collects all the values of the
 *   included forms.
 * - Optionally, you may include custom validation functions using the regular
 *   validation hook (formname_validate). The wizard uses these validation
 *   functions for each step.
 * - The most important customization step is to change the submit handler and
 *   do whatever you want with the collected information. In this case, the
 *   example just shows the collected values in the various steps.
 * @ingroup form_example
 */

/**
 * Returns the list of steps and their associated forms. This has been separated
 * to clarify and easy the understanding of this example. You should edit this
 * function to include the steps your wizard/multistep form requires.
 *
 * @return $array
 *
 * @ingroup form_example
 */
function _voer_module_creation_steps() {
  return array(
      1 => array(
        'form' => 'voer_module_license_info',
      ),
      2 => array(
        'form' => 'voer_module_metadata_info',
      ),
      3 => array(
        'form' => 'voer_module_content',
      ),
    );
}

/**
 * The primary formbuilder function for the wizard form. This is the form that
 * you should call with drupal_get_form() from your code, and it will include
 * the rest of the step forms defined. You are not required to change this
 * function, as this will handle all the step actions for you.
 *
 * This form has two defined submit handlers to process the different steps:
 *  - Previous: handles the way to get back one step in the wizard.
 *  - Next:     handles each step form submission,
 *
 * The third handler, the finish button handler, is the default form _submit
 * handler used to process the information.
 *
 * You are not required to change the next or previous handlers, but you must
 * change the form_example_wizard_sbumit handler to perform the operations you
 * need on the collected information.
 *
 * @ingroup form_example
 */
function voer_module_creation_wizard($form, &$form_state, $entity) {

  // Initialize a description of the steps for the wizard.
  if (empty($form_state['step'])) {
    $form_state['step'] = 1;

    // This array contains the function to be called at each step to get the
    // relevant form elements. It will also store state information for each
    // step.
    $form_state['step_information'] = _voer_module_creation_steps();
  }
  $step = &$form_state['step'];
  $step_count = count(_voer_module_creation_steps());
  drupal_set_title(t('Create a module: Step @step/@step_count', array('@step' => $step, '@step_count' => $step_count)));

  // Call the function named in $form_state['step_information'] to get the
  // form elements to display for this step.
  $form = $form_state['step_information'][$step]['form']($form, $form_state, $entity);

  // Show the 'previous' button if appropriate. Note that #submit is set to
  // a special submit handler, and that we use #limit_validation_errors to
  // skip all complaints about validation when using the back button. The
  // values entered will be discarded, but they will not be validated, which
  // would be annoying in a "back" button.
  if ($step > 1) {
    $form['prev'] = array(
      '#type' => 'submit',
      '#weight' => 999,
      '#value' => t('Previous'),
      '#name' => 'prev',
      '#submit' => array('voer_module_creation_wizard_previous_submit'),
      '#limit_validation_errors' => array(),
    );
  }

  // Show the Next button only if there are more steps defined.
  if ($step < count($form_state['step_information'])) {
    // The Next button should be included on every step
    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Next'),
      '#weight' => 1000,
      '#name' => 'next',
      '#submit' => array('voer_module_creation_wizard_next_submit'),
    );
  }
  else {
    // Just in case there are no more steps, we use the default submit handler
    // of the form wizard. Call this button Finish, Submit, or whatever you
    // want to show. When this button is clicked, the
    // form_example_wizard_submit handler will be called.
    $form['finish'] = array(
      '#type' => 'submit',
      '#value' => t('Save'),
      '#weight' => 1001,
    );
    $form['publish'] = array(
      '#type' => 'submit',
      '#value' => t('Publish'),
      '#weight' => 1002,
      '#submit' => array('voer_module_publish_submit'),
    );
  }

  // Include each validation function defined for the different steps.
  if (function_exists($form_state['step_information'][$step]['form'] . '_validate')) {
    $form['next']['#validate'] = array($form_state['step_information'][$step]['form'] . '_validate');
  }

  return $form;
}

/**
 * Submit handler for the "previous" button.
 * - Stores away $form_state['values']
 * - Decrements the step counter
 * - Replaces $form_state['values'] with the values from the previous state.
 * - Forces form rebuild.
 *
 * You are not required to change this function.
 *
 * @ingroup form_example
 */
function voer_module_creation_wizard_previous_submit($form, &$form_state) {
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];
  if ($current_step > 1) {
    $current_step--;
    $form_state['values'] = $form_state['step_information'][$current_step]['stored_values'];
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the 'next' button.
 * - Saves away $form_state['values']
 * - Increments the step count.
 * - Replace $form_state['values'] from the last time we were at this page
 *   or with array() if we haven't been here before.
 * - Force form rebuild.
 *
 * You are not required to change this function.
 *
 * @param $form
 * @param $form_state
 *
 * @ingroup form_example
 */
function voer_module_creation_wizard_next_submit($form, &$form_state) {
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];

  if ($current_step < count($form_state['step_information'])) {
    $current_step++;
    if (!empty($form_state['step_information'][$current_step]['stored_values'])) {
      $form_state['values'] = $form_state['step_information'][$current_step]['stored_values'];
    }
    else {
      $form_state['values'] = array();
    }
    $form_state['rebuild'] = TRUE;  // Force rebuild with next step.
    return;
  }
}

/**
 * The previous code was a 'skeleton' of a multistep wizard form. You are not
 * required to change a line on the previous code (apart from defining your own
 * steps in the _form_example_steps() function.
 *
 * All the code included from here is the content of the wizard, the steps of
 * the form.
 *
 * First, let's show the defined steps for the wizard example.
 * @ingroup form_example
 */

/**
 * Returns form elements for the 'personal info' page of the wizard. This is the
 * first step of the wizard, asking for two textfields: first name and last
 * name.
 *
 * @ingroup form_example
 */
function voer_module_license_info($form, &$form_state, $entity) {
  drupal_set_title(t('Create a module: Step 1/3 - License agreement'));

  $form = array();
  $form['voer_content_entity'] = array(
    '#type' => 'value',
    '#value' => $entity
  );

  $license = variable_get('voer_api_license_text', array('value' => '', 'format' => NULL));

  $form['license_text'] = array(
    '#markup' => check_markup($license['value'], $license['format']),
  );

  $form['accept_license'] = array(
    '#type' => 'checkbox',
    '#title' => t('I have read the above, and I agree to license this new work under its terms.'),
    '#required' => TRUE,
    '#default_value' => isset($form_state['values']['accept_license']) ? $form_state['values']['accept_license'] : 0,
  );

  return $form;
}

function voer_module_license_info_validate($form, &$form_state){
  if (!$form_state['values']['accept_license']){
    form_set_error('accept_license', t('You must accept this license for go ahead!'));
  }
}
/**
 * Returns form elements for the 'location info' page of the wizard. This is the
 * second step of the wizard. This step asks for a textfield value: a City. This
 * step also includes a validation declared later.
 *
 * @ingroup form_example
 */
function voer_module_metadata_info($form, &$form_state, $entity) {
  drupal_set_title(t('Create a module: Step 2/3 - Metadata'));

  $form = array();
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => isset($entity->title) ? $entity->title : "",
  );

  field_attach_form('node', $entity, $form, $form_state);

  $form_state['storage']['body'] = $form['body'];

  hiden_fields($form);

  return $form;
}

function hiden_fields(&$form){
  $fields = array('body', 'field_voer_file', 'field_voer_material_id', 'field_voer_material_type', 'field_voer_material_version');
  foreach ($fields as $value) {
    unset($form[$value]);
  }
}

/**
 * Custom validation form for the 'location info' page of the wizard.
 *
 * This is the validation function for the second step of the wizard.
 * The city cannot be empty or be "San Francisco".
 *
 * @ingroup form_example
 */
function voer_module_metadata_info_validate($form, &$form_state) {
  // if ($form_state['values']['city'] == 'San Francisco') {
  //   form_set_error('city', t('You were warned not to enter "San Francisco"'));
  // }
}

function voer_module_import_content($form, &$form_state){
  $form = array();

  $form['import_file'] = array(
    '#type' => 'file',
    '#title' => t('Document for import'),
    '#description' => t('Upload a file, allowed extensions: doc, docx, odt'),
  );

  return $form;
}

function voer_module_import_content_validate($form, &$form_state){
  $file = file_save_upload('import_file', array(
    // 'file_validate_is_image' => array(), // Validates file is really an image.
    'file_validate_extensions' => array('doc docx odt'), // Validate extensions.
  ));
  // If the file passed validation:
  if ($file) {
    // Move the file, into the Drupal file system
    if ($file = file_move($file, 'public://')) {

      // Gui noi dung file cho phan vp.transporter
      module_load_include('inc', 'voer_api');
      $realpath = drupal_realpath($file->uri);
      $zipContent = voer_api_import($realpath);
      // Luu ra thu muc import-result
      $uniqueFilename = md5($file->filename . microtime());
      $zipFile = file_unmanaged_save_data($zipContent, "public://import-result/" . $uniqueFilename . ".zip", FILE_EXISTS_RENAME);

      //Unzip it
      $realZipFile = drupal_realpath($zipFile);
      $parentDir = dirname($realZipFile);
      // drupal_set_message('Zip file: '. $realZipFile);
      // drupal_set_message('Dir path: '. $parentDir);
      $unzipDir = $parentDir . "/" . $uniqueFilename;
      // drupal_set_message('Dir path: '. $unzipDir);
      $zip = new ZipArchive;
      $res = $zip->open($realZipFile);
      if ($res === TRUE) {
          $zip->extractTo($unzipDir);
          $zip->close();
      }

      if (file_exists($unzipDir . '/index.html')){
          $importContent = file_get_contents($unzipDir . '/index.html');
          $importContent = preg_replace('/<img src="([^"]*)"/', '<img src="/sites/default/files/import-result/' . $uniqueFilename . '/$1"', $importContent);
          $form_state['input']['body'][LANGUAGE_NONE][0]['value'] = $importContent;
      }
    }
    else {
      form_set_error('file', t('Failed to write the uploaded file to the site\'s file folder.'));
    }
  }
}

/**
 * Returns form elements for the 'other info' page of the wizard. This is the
 * thid and last step of the example wizard.
 *
 * @ingroup form_example
 */
function voer_module_content($form, &$form_state) {
  drupal_set_title(t('Create a module: Step 3/3 - Content'));

  $form = array();

  $form['import_file'] = array(
    '#type' => 'file',
    '#title' => t('Document for import'),
    '#description' => t('Upload a file, allowed extensions: doc, docx, odt'),
    '#weight' => 0,
  );

  $form['upload_file'] = array(
    '#type' => 'button',
    '#weight' => 5,
    '#value' => t('Import'),
    '#validate' => array('voer_module_import_content_validate'),
  );

  $form['body'] = $form_state['storage']['body'];
  $form['body']['#weight'] = 10;

  return $form;
}

// And now comes the magic of the wizard, the function that should handle all the
// inputs from the user on each different step.
/**
 * Wizard form submit handler.
 * - Saves away $form_state['values']
 * - Process all the form values.
 *
 * This demonstration handler just do a drupal_set_message() with the information
 * collected on each different step of the wizard.
 *
 * @param $form
 * @param $form_state
 *
 * @ingroup form_example
 */
function voer_module_creation_wizard_submit($form, &$form_state) {
  $module = save_module($form, $form_state);

  $form_state['redirect'] = 'node/' . $module->nid;

}

function voer_module_publish_submit($form, &$form_state){
  module_load_include('inc', 'voer_content');

  $node = save_module($form, $form_state);
  $result = publish_module($node);
  // dpm($module);
  if ($result === FALSE){
    drupal_set_message("The module publish was not successful!", 'error');
  }else{
    drupal_set_message(t("The module publish was successful!"));
    $node->field_voer_material_id[LANGUAGE_NONE][0]['value'] = $result->material_id;
    $node->field_voer_material_version[LANGUAGE_NONE][0]['value'] = $result->version;
    node_save($node);
    drupal_goto("node/" . $node->nid);
  }
}

/**
 * Save module to WEB DB
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 * @return [type]             [description]
 */
function save_module($form, &$form_state){
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];

  $entity = $form_state['step_information'][1]['stored_values']['voer_content_entity'];
  $entity->title = $form_state['step_information'][2]['stored_values']['title'];

  foreach ($form_state['step_information'] as $index => $value){
    $form_tmp_state = array();
    $form_tmp_state['values'] = array();
    $form_tmp = array();
    $form_tmp['#parents'] = array();
    $form_tmp_state['values'] = $value['stored_values'];
    field_attach_submit('node', $entity, $form_tmp, $form_tmp_state);
  }
  //clear comment tags
  $body = $entity->body[LANGUAGE_NONE][0]['value'];
  $body = preg_replace('/<!--(.*?)-->/is', '', $body);

  $entity->body[LANGUAGE_NONE][0]['value'] = $body;

  $entity->status = TRUE; //unpublish

  node_save($entity);

  return $entity;
}


/**
 * Provides a wrapper on the edit form to add a new entity.
 */
function voer_module_creation() {
  // Create a basic entity structure to be used and passed to the validation
  // and submission functions.
  $node = new stdClass();
  $node->type = 'voer_module';
  node_object_prepare($node);
  $node->title    = '';
  $node->language = LANGUAGE_NONE;
  $node->status = FALSE;
  // $entity = entity_get_controller('voer_content')->create('voer_module');
  // $node->field_voer_material_version[$node->language][0]['value'] = "1";
  $node->field_voer_material_type[$node->language][0]['value'] = "1";
  return drupal_get_form('voer_module_creation_wizard', $node);
}


