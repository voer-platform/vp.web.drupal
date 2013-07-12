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
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'voer_blocks-voer_modules_block' => array(
          'module' => 'voer_blocks',
          'delta' => 'voer_modules_block',
          'region' => 'header',
          'weight' => '-10',
        ),
        'voer_blocks-voer_collections_block' => array(
          'module' => 'voer_blocks',
          'delta' => 'voer_collections_block',
          'region' => 'header',
          'weight' => '-9',
        ),
        'voer_blocks-voer_courses_block' => array(
          'module' => 'voer_blocks',
          'delta' => 'voer_courses_block',
          'region' => 'header',
          'weight' => '-8',
        ),
        'voer_blocks-voer_questionaire_block' => array(
          'module' => 'voer_blocks',
          'delta' => 'voer_questionaire_block',
          'region' => 'header',
          'weight' => '-7',
        ),
        'voer_blocks-voer_help_support_block' => array(
          'module' => 'voer_blocks',
          'delta' => 'voer_help_support_block',
          'region' => 'header',
          'weight' => '-6',
        ),
        'voer_blocks-voer_featured_author_block' => array(
          'module' => 'voer_blocks',
          'delta' => 'voer_featured_author_block',
          'region' => 'header',
          'weight' => '-5',
        ),
        'voer_blocks-voer_categories_block' => array(
          'module' => 'voer_blocks',
          'delta' => 'voer_categories_block',
          'region' => 'header',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Page');
  $export['ctx_frontpage'] = $context;

  return $export;
}
