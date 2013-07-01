<div class="span4">
  <div class="vertical-shadow suggested-action">
    <div class="suggested-action-image-link cls_module" style="background-image: url('<?php echo drupal_get_path('module', 'voer_blocks') ?>/images/default_author.jpg');"><a href="/author/<?php print $id ?>">&nbsp;</a></div>
    <h2 class="pulls ellipsis suggested-action-title">
      <?php echo l($fullname, 'author/' . $id); ?>
    </h2>

    <h5>&nbsp;</h5>

    <?php if ($text) : ?>
      <p><?php print $text; ?></p>
    <?php endif; ?>

    <span class="caption"><?php echo $sub_title . ' (' . (int)$total_count . ')'; ?></span>
  </div>
</div>