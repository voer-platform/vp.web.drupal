<?php if ($page) : ?>
  <?php $metadata = ''; ?>

  <?php if (isset($content['field_voer_authors'][0]['author'])) : ?>
  <?php $metadata .= render($content['field_voer_authors'][0]['author']) . ' | '; ?>
  <?php endif; ?>

  <?php if (isset($content['field_voer_categories'][0])) : ?>
  <?php $metadata .= render($content['field_voer_categories'][0]) . ' | '; ?>
  <?php endif; ?>

  <?php if (isset($content['field_fivestar_rating'])) : ?>
    <?php $metadata .= ' | '.render($content['field_fivestar_rating']); ?>
  <?php endif; ?>

  <?php if (isset($content['links']['statistics'])) : ?>
    <?php $metadata .= ' | '.$content['links']['statistics']['#links']['statistics_counter']['title']; ?>
  <?php endif; ?>
<div id="voer-content-metadata">
  <?php echo $metadata; ?>
</div>
<?php endif; ?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page && $title): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($display_submitted): ?>
      <span class="submitted">
        <?php print $user_picture; ?>
        <?php print $submitted; ?>
      </span>
    <?php endif; ?>
  </header>

  <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    unset($content['links']['statistics']);
    hide($content['field_tags']);
    print render($content['body']);
  ?>

  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
      <?php print render($content['field_tags']); ?>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

</article> <!-- /.node -->
