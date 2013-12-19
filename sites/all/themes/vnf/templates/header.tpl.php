<div id="top">
  <div class="main" id="header">
    <div class="logo">
      <a href="<?php echo $front_page; ?>">
        Logo
      </a>
    </div>
    <div id="main-menu">
    <ul class="main-menu-nav">
      <li>
        <a href="<?php echo $front_page; ?>">Home</a>
      </li>
      <li>
        <a href="/browse">Browser All</a>
      </li>
      <li>
        <a href="/discover">Discover</a>
      </li>
      <li>
        <a href="/about-us">About Us</a>
      </li>
    </ul>
    </div>
    <!--RIGHT TOP-->
    <div class="right" id="right-top-nav">
      <div class="block-top-language">
        <ul class="list-right-top page-content">
          <li>Language:</li>
          <li>
            <div class="collapse navbar-collapse bs-js-navbar-collapse">
            <ul class="nav navbar-nav">
              <li class="dropdown">
                <a data-toggle="dropdown" class="dropdown-toggle" role="button" id="drop-top-language">
                  English
                  <span class="caret"></span>
                </a>
                <div aria-labelledby="drop-category-pd" role="menu" class="dropdown-menu">
                  <ul class="dropdown-menu-language">
                    <li>
                      <a>Vietnamese</a>
                    </li>
                  </ul>
                </div>
              </li>
            </ul>
          </div>
          </li>

          <?php if (user_is_logged_in()) : ?>
            <?php
            global $user; //print_r($user);
            $user = user_load($user->uid);
            ?>
            <li>
              <div class="collapse navbar-collapse bs-js-navbar-collapse">
                <ul class="nav navbar-nav">
                  <li class="dropdown loged-top-user">
                    <a id="drop-top-language" role="button" class="dropdown-toggle" data-toggle="dropdown">
                      <span class="logo-user-right-top left">
                      <?php if ($user->picture) : ?>
                        <?php print theme('image_style', array( 'path' =>  $user->picture->uri, 'style_name' => 'thumbnail', 'attributes' => array('class' => 'thumb', 'width' => '31', 'height' => '31'))); ?>
                      <?php else : ?>
                        <img src="<?php print $base_path . $directory;?>/images/module_view/avatar-user.jpg">
                      <?php endif; ?>
                      </span>

                      <span><?php echo $user->name; ?></span>
                      <span class="caret"></span>
                    </a>
                    <div class="dropdown-menu" role="menu" aria-labelledby="drop-category-pd">
                      <ul class="dropdown-menu-language">
                        <li><?php echo l($user->name, 'user/'.$user->uid); ?></li>
                        <li><?php echo l('Logout', 'user/logout'); ?></li>
                      </ul>
                    </div>
                  </li>
                </ul>
              </div>
            </li>
          <?php else : ?>
            <li><?php echo l('Join', 'user/register'); ?></li>
            <li><a class="btn-top-login" data-toggle="modal" data-target="#modal-user-login"></a></li>
          <?php endif; ?>
        </ul>
    </div>
    </div>
    <!--END RIGHT TOP-->
  </div>
</div>

<?php if (!user_is_logged_in()) : ?>
<!-- Modal -->
<div class="modal fade" id="modal-user-login" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-login">
    <div class="modal-content">
      <?php $element = drupal_get_form('user_login'); ?>
      <?php echo drupal_render($element); ?>

      <div class="modal-footer">
        <?php echo l('Don\'t have an account? Sign up for VOER', 'user/register', array('attributes' => array('class' => array('btn-form-login-signup', 'left')))); ?>

        <div class="alert-modal-login left padding-content-10 hidden"><!-- Add class 'hidden' to hide alert -->
          <span class="left">The username or password is incorrect.</span>
        </div>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->
<?php endif; ?>