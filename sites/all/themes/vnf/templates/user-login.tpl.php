<div class="modal-header padding-content-15">
  <h4 class="modal-title" id="myModalLabel"><?php echo t('Login to VOER'); ?></h4>
</div>
<div class="modal-body padding-content-15">
  <?php print drupal_render_children($form); ?>

  <ul class="list-user-login-tools clearfix">
    <li class="right">
      <?php echo l('Forgot your password?', 'user/password'); ?>
    </li>
  </ul>
</div>
