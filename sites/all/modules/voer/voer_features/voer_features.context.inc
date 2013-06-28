<?php
/**
 * @file
 * voer_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function voer_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ctx_frontpage';
  $context->description = '';
  $context->tag = 'Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Page');
  $export['ctx_frontpage'] = $context;

  return $export;
}
