<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <ul class="nav nav-list">
  <?php if ($title): ?>
    <li class="nav-header"><?php print $title; ?></li>
    <li class="divider"></li>
  <?php endif;?>

    <?php print $content ?>
  </ul>
</section> <!-- /.block -->
