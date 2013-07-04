<div class="span4">
  <div class="vertical-shadow suggested-action">
    <div class="suggested-action-image-link cls_module" style="background-image: url('<?php echo $image_path; ?>');"><a href="/module/<?php print $material_id ?>">&nbsp;</a></div>
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
