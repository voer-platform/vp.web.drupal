<?php

/*
 * Returns the general document upload form.
 * This form is shown before an document has been uploaded,
 * afterwards it is replaced by the document details form
 */
function voer_wysiwyg_import_form(&$form_state,$form_id) {
  $form_id = check_plain($form_id);
  jquery_ui_dialog_child_js();
  drupal_set_title(t('Import document'));
  $form = array();
  $form['#attributes'] = array('enctype' => "multipart/form-data");
  $form['document_import'] = array(
    '#type' => 'fieldset',
    '#title'=> t('Import document'),
    '#prefix' => '<div id="document_import_group">',
    '#suffix' => '</div>');
  _voer_wysiwyg_import_form_add_uploadfields($form,$form_id);

  return $form;
}


/*
 * Returning the form elements for the document upload
 */
function _voer_wysiwyg_import_form_add_uploadfields(&$form, $form_id) {
  $form['document_import']['wysiwyg_import_file'] = array(
    '#type' => 'file',
    '#title' => t('Select a document to upload'),
    '#size' => 40,
  );
  $form['document_import']['start_import'] = array(
    '#type' => 'submit',
    '#value' => t('Upload document'),
    '#name' => 'attach',
    '#ahah' => array(
      'path' => "ajax/voer_wysiwyg/import/$form_id",
      'wrapper' => 'document_import_group',
      'progress' => array('type' => 'bar', 'message' => t('Please wait...'))
    )
  );
}


/*
 * Uploading a image and calling the file_insert hooks.
 * @return: Returns the uploaded file as an object
 */
function _voer_wysiwyg_import_file() {
  global $user;

  $dest = file_directory_path();
  $validators = array(
    'file_validate_is_image' => array()
    // TODO: Implement a administration interface for filesize settings
    // 'file_validate_size' => array($limits['file_size'], $limits['user_size']),
  );
  $file = NULL;
  if (user_access('use wysiwyg image upload') && $file = file_save_upload('voer_wysiwyg_import_file', $validators, $dest,FILE_EXISTS_RENAME)) {
    foreach (module_implements('file_insert') as $module) {
      $function =  $module .'_file_insert';
      $function($file);
    }

    $file->list = 0;  // do not list the images
    $file->description = $file->filename;
    $file->weight = 0;
    $file->new = TRUE;

    if (!@chmod($file->filepath, 0664)) {
      watchdog('voer_wysiwyg', 'Could not set permissons on destination file: %file', array('%file' => $file->filepath));
    }
  }

  return (object)$file;
}
