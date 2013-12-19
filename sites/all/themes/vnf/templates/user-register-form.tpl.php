<div class="signup-form">
  <div class="header-signup-form"><?php echo t('Join VOER. Take Creative Control.'); ?></div>
  <div class="social-signup-form">
    <a class="link-fb-signup left"></a>
    <a class="link-tw-signup left"></a>
    <a class="link-gg-signup left"></a>
    <a class="link-in-signup left"></a>
  </div>
  <div class="content-signup-form">
    <div class="title-signup-email">
      <span><?php echo t('or sign up using your email'); ?></span>
    </div>
    <?php print drupal_render_children($form); ?>

    <!-- <input type="text" class="form-control" placeholder="Your email Address">
    <input type="password" class="form-control passwordsg" placeholder="Choose a Password">
    <div class="block-showpassword">
      <label id="checkbox-showpassword" class="checkbox checkbox-user-tool checkbox-showpassword">
      <span class="icons">
        <span class="first-icon fui-checkbox-unchecked"></span>
        <span class="second-icon fui-checkbox-checked"></span>
      </span>
      <input type="checkbox" data-toggle="checkbox">
      Show password
    </label>
    </div>
     -->

    <!-- <span class="left clear">
      By registering you are agreeing to our <a class="link-blue">Terms of Use</a> and <a class="link-blue">Privacy Policy</a>.
    </span>
     -->
  </div>
</div>
