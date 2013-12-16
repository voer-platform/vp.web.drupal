<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>
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
        <ul class="list-right-top">
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
          <li><a href="<?php print $base_path; ?>user/register">Join</a></li>
          <li><a class="btn-top-login"></a></li>
        </ul>
    </div>
    </div>
    <!--END RIGHT TOP-->
  </div>
</div>

<?php if ($is_front) : ?>
<div class="slide1" id="slider" style="background-image: url('<?php print $base_path . $directory;?>/images/bg-slide1.jpg');">
  <!--<div class="hfslidebg">
    <div class="slidebg active" style="display:block;">
      <div id="bg_slide1"></div>
    </div>
    <div class="slidebg" style="display:none;">
      <div id="bg_slide2"></div>
    </div>
    <div class="slidebg" style="display:none;">
      <div id="bg_slide3"></div>
    </div>
  </div>-->
  <div class="slider-content main">
    <div class="slider-content-left left">
      <div class="text-header-slider-left left clear">Take the world's best documents, online, for free.</div>
      <div class="div-input-search left clear">
        <input type="text" class="input-search-top">
      </div>
      <div class="text-slider-left clear">
        Join 21598 modules, 502 collections from 2052 authors
      </div>
    </div>
  <div class="hfslide right">



  <div style="display: block;" class="slide active" id="slide2">
      <div class="box"></div>
      <div class="icon1"></div>
      <div class="icon2"></div>
      <div class="icon3"></div>
      <div class="icon4"></div>
      <div class="icon5"></div>
      <div class="icon6"></div>
      <div class="icon7"></div>
      <div class="icon8"></div>
    </div><div style="display: none;" class="slide" id="slide3">
      <div class="macbook"></div>
      <div class="group-icon1"></div>
      <div class="group-icon2"></div>
      <div class="group-icon3"></div>
      <div class="group-icon4"></div>
      <div class="group-icon5"></div>
      <div class="group-icon6"></div>
      <div class="group-icon7"></div>
    </div><div style="display: none;" class="slide" id="generic">
      <div class="book"></div>
      <div class="cloud1"></div>
      <div class="cloud2"></div>
      <div class="tree1"></div>
      <div class="tree2"></div>
      <div class="tree3"></div>
    </div></div>
  </div>
</div>
<?php endif; ?>

<div id="mainpage" class="main">
  <div class="container">
    <div class="row">
      <?php print $messages; ?>
      <?php if (!empty($page['header'])): ?>
        <?php print render($page['header']); ?>
        <div class="mainpage-browser left">
          <a class="btn-browser-all left clear">Browser All</a>
          <div class="mainpage-browser-content left">
            <ul class="list-mainpage-browser left">
              <li>
                <div class="browser-author-img left clear">
                  <img src="images/author1.jpg">
                </div>
                <div class="browser-author-details left clear">
                  <div class="icon-browser-author"></div>
                  <div class="browser-author-name left clear">
                    <a>Đỗ Trọng Kiên</a>
                  </div>
                  <div class="browser-author-add left clear">GT.TS ĐH Kiến Trúc Hà Nội</div>
                </div>
              </li>
              <li>
                <div class="browser-author-img left clear">
                  <img src="images/author2.jpg">
                </div>
                <div class="browser-author-details left clear">
                  <div class="icon-browser-author"></div>
                  <div class="browser-author-name left clear">
                    <a>Hồ Ngọc Đại</a>
                  </div>
                  <div class="browser-author-add left clear">Trung tâm Công nghệ giáo dục</div>
                </div>
              </li>
              <li>
                <div class="browser-author-img left clear">
                  <img src="images/author3.jpg">
                </div>
                <div class="browser-author-details left clear">
                  <div class="icon-browser-author"></div>
                  <div class="browser-author-name left clear">
                    <a>Lê Văn Lan</a>
                  </div>
                  <div class="browser-author-add left clear">Giáo sư Sử học</div>
                </div>
              </li>
              <li>
                <div class="browser-author-img left clear">
                  <img src="images/author4.jpg">
                </div>
                <div class="browser-author-details left clear">
                  <div class="icon-browser-author"></div>
                  <div class="browser-author-name left clear">
                    <a>Lê Văn Lan</a>
                  </div>
                  <div class="browser-author-add left clear">Giáo sư Sử học</div>
                </div>
              </li>
              <li>
                <div class="browser-author-img left clear">
                  <img src="images/author1.jpg">
                </div>
                <div class="browser-author-details left clear">
                  <div class="icon-browser-author"></div>
                  <div class="browser-author-name left clear">
                    <a>Đỗ Trọng Kiên</a>
                  </div>
                  <div class="browser-author-add left clear">GT.TS ĐH Kiến Trúc Hà Nội</div>
                </div>
              </li>
            </ul>
          </div>
        </div>
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
        <?php if (!empty($title) && !isset($node)): ?>
          <div class="module-view-title left padding-content-15">
            <span class="module-view-name left clear"><?php print $title; ?></span>
          </div>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php if (!empty($tabs)): ?>
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

      <div class="footer left">
        <div class="logo-footer left">
        </div>
        <ul class="list-menu-footer left">
          <li>
            <a>About</a>
          </li>
          <li>
            <a>Careers</a>
          </li>
          <li>
            <a>Team</a>
          </li>
          <li>
            <a>Store</a>
          </li>
          <li>
            <a>Contact</a>
          </li>
          <li>
            <a>Press</a>
          </li>
          <li>
            <a>Terms</a>
          </li>
        </ul>
        <ul class="list-footer-social right">
          <li><a>Facebook</a></li>
          <li><a>Google+</a></li>
          <li><a>Twitter</a></li>
        </ul>
      </div>
    </div>
  </div>
</div>

