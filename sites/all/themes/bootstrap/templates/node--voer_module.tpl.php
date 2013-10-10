<script>
  function downloadPDF(){
    // alert('hi');
    return false;
  }

  function getPDF(){
    $.ajax({
      url: url,
      complete: function (jqxhr, txt_status) {
        console.log ("Complete: [ " + txt_status + " ] " + jqxhr);
        // if (response code is 301) {
        console.log ("Location: " + jqxhr.getResponseHeader("Location"));
        // }
      }
    });
  }
</script>
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
  <?php $metadata .= render($content['field_voer_categories'][0]) . ' | '; ?>
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
<div id="voer-content-metadata">
  <?php echo $metadata; ?>
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

  <?php if ($page && $thefirst == 'collection'): ?>
  <h2 class='sub-title'><?php print $title; ?></h2>
  <?php endif; ?>

  <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
    unset($content['links']['statistics']);
    print render($content['body']);
  ?>

  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
      <?php print render($content['field_tags']); ?>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <?php if (isset($voer_attachment)) : ?>
  <?php echo $voer_attachment; ?>
  <?php endif; ?>
</article> <!-- /.node -->

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
