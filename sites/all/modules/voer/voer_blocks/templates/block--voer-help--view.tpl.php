<div class="span4">
  <div class="vertical-shadow suggested-action">
    <div class="suggested-action-image-link cls_module" style="background-image: url('<?php echo $image_path; ?>');"><a href="/m/<?php print $material_id ?>">&nbsp;</a></div>
    <h2 class="pulls ellipsis suggested-action-title">
      <?php echo l($title, 'm/' . $material_id); ?>
    </h2>

    <?php if (isset($category_name)) : ?>
    <h5><?php echo $category_name; ?></h5>
    <?php endif; ?>

    <?php if ($description) : ?>
      <?php if (strlen($description) > 100) $description = array_shift(explode('|||', wordwrap($description, 50, '|||'))) . '...'; ?>
      <p><?php print $description; ?></p>
    <?php endif; ?>

    <span class="caption"><?php echo $content_type ; ?></span>
  </div>
</div>
