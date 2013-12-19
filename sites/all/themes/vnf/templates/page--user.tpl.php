<?php require_once 'header.tpl.php'; ?>

<div id="mainpage" class="main <?php if (user_is_logged_in()): ?>mainpage-content<?php endif; ?>">
  <div class="container">
    <div class="row">
      <?php if ($messages) : ?>
        <?php print $messages; ?>
      <?php endif; ?>

      <?php if (!empty($page['sidebar_first'])): ?>
        <aside class="col-sm-3" role="complementary">
          <?php print render($page['sidebar_first']); ?>
        </aside>  <!-- /#sidebar-first -->
      <?php endif; ?>

      <?php if (!$is_front): ?>
      <section<?php print $content_column_class; ?>>
        <?php if (!empty($page['highlighted'])): ?>
          <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
        <?php endif; ?>
        <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if (!empty($title) && !isset($node) && user_is_logged_in()): ?>
          <div class="module-view-title left padding-content-15">
            <span class="module-view-name left clear"><?php print $title; ?></span>
          </div>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php if (!empty($tabs) && user_is_logged_in()): ?>
          <?php print render($tabs); ?>
        <?php endif; ?>
        <?php if (!empty($page['help'])): ?>
          <?php print render($page['help']); ?>
        <?php endif; ?>
        <?php if (!empty($action_links)): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php print render($page['content']); ?>
      </section>
      <?php endif; ?>

      <?php if (!empty($page['sidebar_second'])): ?>
        <aside class="col-sm-3" role="complementary">
          <?php print render($page['sidebar_second']); ?>
        </aside>  <!-- /#sidebar-second -->
      <?php endif; ?>

      <?php require_once 'footer.tpl.php'; ?>
    </div>
  </div>
</div>

