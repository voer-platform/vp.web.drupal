<!DOCTYPE html>
<html>
  <head>
    <title>Create material - VOER</title>
    <?php require_once 'includes/header.php'; ?>
  </head>
  <body data-offset="80" data-target=".subnav" data-spy="scroll" style="height:1000px">
    <?php require_once 'includes/header_nav.php'; ?>

    <div class="container text-center">
      <form action="" method="post">
        <div class="input-append">
          <input type="text" class="input-xxlarge" placeholder="Please enter something...">
          <button type="submit" class="btn">Search</button>
        </div>
      </form>
    </div>
    
    <div id="create_material" title="Create a material - step 3">
      <label>Body</label>
      <textarea class="rich_text_editor span12" rows="5"></textarea>
      
      <div class="verticalslider" id="textExample">
        <ul class="verticalslider_tabs">
          <li><a href="#">Metadata</a></li>
          <li><a href="#">Authoring infomation</a></li>
          <li><a href="#">Third tab</a></li>
          <li><a href="#">Four tab</a></li>                        
        </ul>
        <ul class="verticalslider_contents">
          <li></li>
          <li></li>
          <li></li>
          <li></li>                        
        </ul>
      </div>
      <br>

      <a class="btn btn-primary" href="create_material_step_2.php">« Back</a>
      <a class="btn btn-primary" href="detail.html">Submit</a>
    </div>

    <div class="container">
      <?php require_once 'includes/home_block.php'; ?>
      <?php require_once 'includes/categories.php'; ?>
    </div>

    <?php require_once 'includes/footer.php'; ?>

    <script type="text/javascript" src="js/tinymce/jscripts/tiny_mce/tiny_mce.js"></script>
    <script language="javascript" type="text/javascript">
    tinyMCE.init({
      theme : "advanced",
      mode : "specific_textareas",
      editor_selector : /(rich_text_editor|mceRichText)/,
      keep_styles : false
    });
    </script>
    <script type="text/javascript" src="js/verticaltabs/js/verticaltabs.pack.js"></script>
    <link rel="stylesheet" href="js/verticaltabs/css/verticaltabs.css" />
    <script type="text/javascript">
      $(document).ready(function(){
        $("#textExample").verticaltabs({speed: 500,slideShow: false,activeIndex: 2});
      });
    </script>
  </body>
</html>
