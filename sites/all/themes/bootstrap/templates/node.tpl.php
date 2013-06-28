<?php if ($page) : ?>
<div class="btn-toolbar">
  <div class="btn-group">
  <a href="#" class="btn btn-inverse disabled"><i class="icon-white icon-thumbs-up"></i></a>
  <a href="#" class="btn btn-inverse disabled"><i class="icon-white icon-heart"></i></a>
  <a href="#" class="btn btn-inverse disabled"><i class="icon-white icon-download-alt"></i></a>
  <a href="#" class="btn btn-inverse disabled"><i class="icon-white icon-share-alt"></i></a>
  </div>
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
    hide($content['field_tags']);
    print render($content);
  ?>

  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
      <?php print render($content['field_tags']); ?>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

</article> <!-- /.node -->
