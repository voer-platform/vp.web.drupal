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
function _voer_collection_creation_steps() {
  return array(
      1 => array(
        'form' => 'voer_collection_license_info',
      ),
      2 => array(
        'form' => 'voer_collection_metadata_info',
      ),
      3 => array(
        'form' => 'voer_collection_content',
      ),
    );
}

function voer_collection_creation_wizard($form, &$form_state, $entity) {

  // Initialize a description of the steps for the wizard.
  if (empty($form_state['step'])) {
    $form_state['step'] = 1;

    // This array contains the function to be called at each step to get the
    // relevant form elements. It will also store state information for each
    // step.
    $form_state['step_information'] = _voer_collection_creation_steps();
  }
  $step = &$form_state['step'];
  drupal_set_title(t('Create a collection: Step @step', array('@step' => $step)));

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
      '#submit' => array('voer_collection_creation_wizard_previous_submit'),
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
      '#submit' => array('voer_collection_creation_wizard_next_submit'),
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
      '#submit' => array('voer_collection_publish_submit'),
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
function voer_collection_creation_wizard_previous_submit($form, &$form_state) {
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
function voer_collection_creation_wizard_next_submit($form, &$form_state) {
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
function voer_collection_license_info($form, &$form_state, $entity) {
  $form = array();
  $form['voer_content_entity'] = array(
    '#type' => 'value',
    '#value' => $entity
  );
  $form['license_text'] = array(
    '#type' => 'textarea',
    '#value' => t('I recently played the role of Information Architect on a site remodel. We were charged with the task of doing a brand new build to replace an existing Flash site. One of the priorities of the client was to retain the elaborate Request for Quote form. There were many, many form fields that comprised this web form so I began to ponder if we should break the form up into a multiple step form, to improve the overall user experience. After careful consideration, I decided that we should definitely split the form up (for more on this matter check out Pagination in Web Forms | Evaluating the Effectiveness of Web Forms on UXmatter.com). Since there was no logic needed in the progression of the form, I felt that Javascript would be an acceptable solution, over using an actual server-side wizard. Thanks to Janko and his Turn any webform into a powerful wizard with jQuery blog, I found his JQuery plugin very easy to implement. This tutorial assumes that you have some basic working knowledge of the Webform module and how to create a custom module of your own.'),
    '#weight' => 0,
    '#rows' => 10,
    '#disabled' => TRUE,
    '#resizable' => FALSE,
    '#attributes' => array(
      'class' => array('license_text'),
    )
  );

  $form['accept_license'] = array(
    '#type' => 'checkbox',
    '#title' => t('I have read the above, and I agree to license this new work under its terms.'),
    '#required' => TRUE,
    '#default_value' => isset($form_state['values']['accept_license']) ? $form_state['values']['accept_license'] : 0,
  );

  return $form;
}

function voer_collection_license_info_validate($form, &$form_state){
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
function voer_collection_metadata_info($form, &$form_state, $entity) {
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
function voer_collection_metadata_info_validate($form, &$form_state) {
  // if ($form_state['values']['city'] == 'San Francisco') {
  //   form_set_error('city', t('You were warned not to enter "San Francisco"'));
  // }
}

/**
 * Returns form elements for the 'other info' page of the wizard. This is the
 * thid and last step of the example wizard.
 *
 * @ingroup form_example
 */
function voer_collection_content($form, &$form_state) {
  $form = array();

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
function voer_collection_creation_wizard_submit($form, &$form_state) {
  $module = save_module($form, $form_state);

  $form_state['redirect'] = 'node/' . $module->nid;

}

function voer_collection_publish_submit($form, &$form_state){
  $module = save_module($form, $form_state);
  $result = publish_module($module);
  if ($result === FALSE){
    drupal_set_message("The collection publish was not successful!");
  }
  $form_state['redirect'] = 'node/' . $module->nid;
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

  node_save($entity);

  return $entity;
}

function publish_module($module){
  module_load_include('inc', 'voer_api');
  try {
    $material_id = $module->field_voer_material_id[LANGUAGE_NONE][0]['value'];
  } catch (Exception $e) {
    $material_id = "";
  }

  $categories = "";
  $arr_cats = array();
  foreach ($module->field_voer_categories[LANGUAGE_NONE] as $val) {
    $arr_cats[] = $val['value'];
  }
  $categories = implode(",", $arr_cats);

  $params = array(
    "material_id" => $material_id,
    "text" => $module->body[LANGUAGE_NONE][0]['value'],
    "title" => $module->title,
    "material_type" => 1, //$module->field_voer_material_type[LANGUAGE_NONE][0]['value'],
    "version" => "1",
    "description" => $module->field_voer_description[LANGUAGE_NONE][0]['value'],
    "keywords" => $module->field_voer_keywords[LANGUAGE_NONE][0]['value'],
    "categories" => $categories,
    "authors" => "huyvq",
    "editor_id" => $module->uid,
    "license_id" => 1,
    "language" => "en",
  );

  try {
    if (empty($material_id)){
      return voer_api_create_material($params);
    }else{
      return voer_api_checkin_material($params);
    }
  } catch (Exception $e) {
    drupal_set_message("Error: " + $e->getMessage());
    return FALSE;
  }
}

/**
 * Provides a wrapper on the edit form to add a new entity.
 */
function voer_collection_creation() {
  // Create a basic entity structure to be used and passed to the validation
  // and submission functions.
  $node = new stdClass();
  $node->type = 'voer_collection';
  node_object_prepare($node);
  $node->title    = '';
  $node->language = LANGUAGE_NONE;
  return drupal_get_form('voer_collection_creation_wizard', $node);
}


