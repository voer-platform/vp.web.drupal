<div class="span4">
  <div class="vertical-shadow suggested-action">
    <div class="suggested-action-image-link cls_module" style="background-image: url('<?php echo drupal_get_path('module', 'voer_blocks') ?>/images/default_author.jpg');"><a href="/person/<?php print $author_id ?>">&nbsp;</a></div>
    <h2 class="pulls ellipsis suggested-action-title">
      <?php echo l($fullname, 'person/' . $author_id); ?>
    </h2>

    <h5><?php echo t('Module: ') . $material_count; ?></h5>

    <?php if (isset($text)) : ?>
      <p><?php print $text; ?></p>
    <?php endif; ?>

    <span class="caption"><?php echo $sub_title . ' (' . (int)$total_count . ')'; ?></span>
  </div>
</div>
