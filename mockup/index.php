<!DOCTYPE html>
<html>
  <head>
    <title>VOER mockup</title>
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

    <?php require_once 'includes/dashboard_block.php'; ?>  

    <div class="container">
      <?php require_once 'includes/home_block.php'; ?>
      <?php require_once 'includes/categories.php'; ?>
    </div>

    <?php require_once 'includes/footer.php'; ?>
    <script>
      $(function(){
        if ($('.dashboard').size() > 0) {
          $("#dialog").dialog( "open" );
        }
      });
    </script>
  </body>
</html>
