<section style="overflow: hidden;">
  <?php if ($avatar) : ?>
  <img src="<?php echo sprintf('http://%s:%s/%s%s/avatar/', VOER_API_URL, VOER_API_PORT, VOER_API_COMMAND_AUTHOR, $author_id); ?>" width="120" style="float: right" />
  <?php else : ?>
  <img src="<?php echo base_path() . drupal_get_path('module', 'voer_person') . '/images/author.png'; ?>" width="120" style="float: right" />
  <?php endif; ?>

  <?php if (isset($title) && $title) : ?>
    <h2><?php print $title . ' ' . $fullname; ?></h2>
  <?php else : ?>
    <h2><?php print $fullname; ?></h2>
  <?php endif; ?>

  <div class="field-persons">
    <?php if (isset($material_count)) : ?>
    <div class="field-person-item">
      <div class="field-person-item-label"><?php echo t('Module'); ?>:</div>
      <div class="field-person-item-content"><?php echo $material_count; ?></div>
    </div>
    <?php endif; ?>

    <?php if (isset($homepage) && $homepage) : ?>
    <div class="field-person-item">
      <div class="field-person-item-label"><?php echo t('Homepage'); ?>:</div>
      <div class="field-person-item-content">
        <a href="<?php echo $homepage; ?>" target="_blank"><?php echo $homepage; ?></a>
      </div>
    </div>
    <?php endif; ?>

    <?php if (isset($affiliation) && $affiliation) : ?>
    <div class="field-person-item">
      <div class="field-person-item-label"><?php echo t('Affifiation'); ?>:</div>
      <div class="field-person-item-content"><?php echo $affiliation; ?></div>
    </div>
    <?php endif; ?>

    <?php if (isset($affiliation_url) && $affiliation_url) : ?>
    <div class="field-person-item">
      <div class="field-person-item-label"><?php echo t('Affifiation URL'); ?>:</div>
      <div class="field-person-item-content">
        <a href="<?php echo $affiliation_url; ?>" target="_blank"><?php echo $affiliation_url; ?></a>
      </div>
    </div>
    <?php endif; ?>

    <?php if (isset($national) && $national) : ?>
    <div class="field-person-item">
      <div class="field-person-item-label"><?php echo t('Nationality'); ?>:</div>
      <div class="field-person-item-content"><?php echo $national; ?></div>
    </div>
    <?php endif; ?>

    <?php if (isset($biography) && $biography) : ?>
    <div class="field-person-item">
      <div class="field-person-item-label"><?php echo t('Biography'); ?>:</div>
      <div class="field-person-item-content"><?php echo $biography; ?></div>
    </div>
    <?php endif; ?>
  </div>
</section>
