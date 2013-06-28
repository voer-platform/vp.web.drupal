<div class="span4">
  <div class="vertical-shadow suggested-action">
    <div class="suggested-action-image-link cls_module" style="background-image: url('<?php echo drupal_get_path('module', 'voer_blocks') ?>/images/default_image.jpg');"><a href="/module/c%C6%A1-s%E1%BB%9F-h%E1%BA%A3i-d%C6%B0%C6%A1ng-h%E1%BB%8Dc">&nbsp;</a></div>
    <h2 class="pulls ellipsis suggested-action-title">
      <?php echo l($title, 'module/' . $material_id); ?>
    </h2>

    <?php if (isset($category_name)) : ?>
    <h5><?php echo $category_name; ?></h5>
    <?php endif; ?>

    <?php if ($description) : ?>
      <p><?php print $description; ?></p>
    <?php endif; ?>

    <span class="caption"><?php echo $content_type . ' (' . (int)$total_count . ')'; ?></span>
  </div>
</div>