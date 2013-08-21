<div class="row-fluid library-section visited-no-recolor">
<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="section-separator">
      <h2<?php print $title_attributes; ?>><span class="section-separator-text"><?php print $title; ?></span></h2>
      <hr>
    </div>
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <?php print $content ?>

</section> <!-- /.block -->
</div>