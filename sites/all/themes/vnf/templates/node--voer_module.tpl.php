<?php if (isset($navigation)) : ?>
<ul class="pager">
  <?php if ($navigation['prev_url']) : ?>
  <li class="previous"><?php echo $navigation['prev_url']; ?></li>
  <?php else : ?>
  <li class="previous disabled"><a href="#">&larr; Prev</a></li>
  <?php endif; ?>

  <li><?php echo $navigation['home_url']; ?></li>

  <?php if ($navigation['next_url']) : ?>
  <li class="next"><?php echo $navigation['next_url']; ?></li>
  <?php else : ?>
  <li class="next disabled"><a href="#">Newer →</a></li>
  <?php endif; ?>
</ul>
<?php endif; ?>

<?php
  $current_path = isset($_GET['q']) ? $_GET['q'] : "";
  $params = explode("/", $current_path);
  $thefirst = $params[0];
?>

<?php if ($page) : ?>
  <?php $metadata = ''; ?>

  <?php if (isset($content['field_voer_authors'][0]['author'])) : ?>
  <?php $metadata .= render($content['field_voer_authors'][0]['author']) . ' | '; ?>
  <?php endif; ?>

  <?php if (isset($content['field_voer_categories'][0])) : ?>
  <?php //$metadata .= render($content['field_voer_categories'][0]) . ' | '; ?>
  <?php endif; ?>

  <?php
    $metadata .= "<div class='btn-group'>";
    $metadata .= "<a class='btn dropdown-toggle' data-toggle='dropdown' href='#'>Download";
    $metadata .= "<span class='caret'></span>";
    $metadata .= "</a>";
    $metadata .= "<ul class='dropdown-menu'>";
    $metadata .= "<!-- dropdown menu links -->";
    if ($thefirst == "collection"){
      $metadata .= sprintf('<li><a href="/node/%s/pdf" onclick="downloadPDF();">Collection as PDF</a></li>', $params[1]);
      $metadata .= "<li class='divider'></li>";
      $metadata .= sprintf('<li><a href="/node/%s/pdf" onclick="downloadPDF();">Module as PDF</a></li>', $node->nid);
    }else{
      $metadata .= sprintf('<li><a href="/node/%s/pdf" onclick="downloadPDF();"> Save PDF</a></li>', $node->nid);
    }
    $metadata .= "</ul>";
    $metadata .= "</div>";
  ?>

  <?php if (isset($content['field_fivestar_rating'])) : ?>
    <?php $metadata .= ' | '.render($content['field_fivestar_rating']); ?>
  <?php endif; ?>

  <?php if (isset($content['links']['statistics'])) : ?>
    <?php $metadata .= ' | '.$content['links']['statistics']['#links']['statistics_counter']['title']; ?>
  <?php endif; ?>
<?php endif; ?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <header>
    <?php if ($page): ?>
      <div class="module-view-title left padding-content-15">
        <span class="module-view-name left clear"><?php print $title; ?></span>
        <?php print render($content['field_voer_categories'][0]); ?>
      </div>
    <?php else: ?>
      <?php if ($title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
    <?php endif; ?>
  </header>

  <?php if ($page && $thefirst == 'collection'): ?>
  <h2 class='sub-title'><?php print $title; ?></h2>
  <?php endif; ?>
  <div class="module-view-content left padding-content-15">
    <?php print render($content['body']);?>
  </div>

  <?php print render($content['comments']); ?>

  <?php if (isset($voer_attachment)) : ?>
  <?php echo $voer_attachment; ?>
  <?php endif; ?>
</article> <!-- /.node -->
<div class="left-col right-row">
  <!-- AUTHOR NAME -->
  <div class="module-view-author padding-content-10 left">
    <a class="module-view-author-avatar left">
      <img src="images/module_view/avatar-big.jpg">
    </a>
    <ul class="module-view-author-name left padding-content-10">
      <li>
        <a>HiFlyer</a>
      </li>
      <li>
        <span class="text-italic">View my profile</span>
      </li>
    </ul>
  </div>
  <!-- END AUTHOR NAME -->
  <!-- AUTHOR STATUS -->
  <div class="module-view-author-status left">
    <span class="module-view-author-block left padding-content-5">
      <a class="clear left">10</a>
      <label class="clear left">Modules</label>
    </span>
    <span class="module-view-author-block left padding-content-5">
      <a class="clear left">3</a>
      <label class="clear left">Collections</label>
    </span>
    <span class="module-view-author-block left padding-content-5">
      <a class="clear left">11</a>
      <label class="clear left">Following</label>
    </span>
    <span class="module-view-author-block left padding-content-5">
      <a class="clear left">15</a>
      <label class="clear left">Followers</label>
    </span>
  </div>
  <!-- END AUTHOR STATUS -->
  <!-- REUSE -->
  <div class="module-block">
    <div class="module-block-header">
      <div class="icon-module icon-checkout"></div>
      <div class="tilte-module">
        <a href="<?php print sprintf('/node/%s/clone', $node->nid) ?>">Reuse</a>
      </div>
    </div>
  </div>
  <!-- END REUSE -->
  <!-- DOWNLOAD -->
  <div class="module-block">
    <div class="module-block-header">
      <div class="icon-module icon-download"></div>
      <div class="tilte-module">
        <a href="<?php print sprintf('/node/%s/pdf', $node->nid) ?>">Download</a>
      </div>
    </div>
  </div>
  <!-- END DOWNLOAD -->
  <!-- TAG -->
  <div class="module-block module-simple">
    <div class="module-block-header">
      <div class="icon-module"></div>
      <div class="tilte-module">Tag</div>
    </div>
    <div class="module-block-content">
      <a class="link-tag">Zen</a>
      <a class="link-tag">Book</a>
      <a class="link-tag">Khoa học</a>
      <a class="link-tag">Bản đồ</a>
      <a class="link-tag">Nghiên cứu</a>
      <a class="link-tag">Phát triển</a>
    </div>
  </div>
  <!-- END TAG -->
  <!-- OTHER FROM AUTHOR -->
  <div class="module-block module-simple">
    <div class="module-block-header">
      <div class="icon-module"></div>
      <div class="tilte-module">Other from Author</div>
    </div>
    <div class="module-block-content">
      <div class="other-module-author">
        <div class="other-author-img">
          <img src="images/module_view/other1.jpg">
        </div>
        <div class="other-author-title left padding-content-5">
          <a class="link-other-author-module left clear">Two-Dimensional Kinematics</a>
          <a class="link-other-author-collection left clear">College Physics</a>
        </div>
      </div>
      <div class="other-module-author">
        <div class="other-author-img">
          <img src="images/module_view/other2.jpg">
        </div>
        <div class="other-author-title left padding-content-5">
          <a class="link-other-author-module left clear">Dynamics: Force and Newton's ...</a>
          <a class="link-other-author-collection left clear">General Approach ...</a>
        </div>
      </div>
      <div class="other-module-author">
        <div class="other-author-img">
          <img src="images/module_view/other3.jpg">
        </div>
        <div class="other-author-title left padding-content-5">
          <a class="link-other-author-module left clear">Dynamics: Force and Newton's ...</a>
          <a class="link-other-author-collection left clear">General Approach ...</a>
        </div>
      </div>
      <div class="other-module-author">
        <div class="other-author-img">
          <img src="images/module_view/other4.jpg">
        </div>
        <div class="other-author-title left padding-content-5">
          <a class="link-other-author-module left clear">Two-Dimensional Kinematics</a>
          <a class="link-other-author-collection left clear">College Physics</a>
        </div>
      </div>

    </div>
  </div>
  <!-- END OTHER FROM AUTHOR -->

  <!-- OTHER FROM AUTHOR -->
  <div class="module-block module-simple">
    <div class="module-block-header">
      <div class="icon-module"></div>
      <div class="tilte-module">Similar item</div>
    </div>
    <div class="module-block-content">
      <div class="other-module-author">
        <div class="other-author-img">
          <img src="images/module_view/other3.jpg">
        </div>
        <div class="other-author-title left padding-content-5">
          <a class="link-other-author-module left clear">Dynamics: Force and Newton's ...</a>
          <a class="link-other-author-collection left clear">General Approach ...</a>
        </div>
      </div>
      <div class="other-module-author">
        <div class="other-author-img">
          <img src="images/module_view/other4.jpg">
        </div>
        <div class="other-author-title left padding-content-5">
          <a class="link-other-author-module left clear">Two-Dimensional Kinematics</a>
          <a class="link-other-author-collection left clear">College Physics</a>
        </div>
      </div>
      <div class="other-module-author">
        <div class="other-author-img">
          <img src="images/module_view/other2.jpg">
        </div>
        <div class="other-author-title left padding-content-5">
          <a class="link-other-author-module left clear">Dynamics: Force and Newton's ...</a>
          <a class="link-other-author-collection left clear">General Approach ...</a>
        </div>
      </div>
      <div class="other-module-author">
        <div class="other-author-img">
          <img src="images/module_view/other1.jpg">
        </div>
        <div class="other-author-title left padding-content-5">
          <a class="link-other-author-module left clear">Two-Dimensional Kinematics</a>
          <a class="link-other-author-collection left clear">College Physics</a>
        </div>
      </div>
    </div>
  </div>
  <!-- END OTHER FROM AUTHOR -->
</div>

<?php if (isset($navigation)) : ?>
<ul class="pager">
  <?php if ($navigation['prev_url']) : ?>
  <li class="previous"><?php echo $navigation['prev_url']; ?></li>
  <?php else : ?>
  <li class="previous disabled"><a href="#">&larr; Prev</a></li>
  <?php endif; ?>

  <li><?php echo $navigation['home_url']; ?></li>

  <?php if ($navigation['next_url']) : ?>
  <li class="next"><?php echo $navigation['next_url']; ?></li>
  <?php endif; ?>
</ul>
<?php endif; ?>
