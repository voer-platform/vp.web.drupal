<?php if ($fields["nid"]->content) : ?>
  <?php $link = url('node/' . $fields["nid"]->content); ?>

  <div style="background-image: url('<?php echo $fields["field_image"]->content; ?>');" class="suggested-action-image-link cls_module"><a href="<?php echo $link; ?>">&nbsp;</a></div>
  <?php echo $fields["title_1"]->content; ?>  
  <h5><?php echo $fields["field_category"]->content; ?></h5>  
  <?php echo $fields["body"]->content; ?>
  <span class="caption"><?php echo $fields["type"]->content; ?></span>
<?php endif; ?>