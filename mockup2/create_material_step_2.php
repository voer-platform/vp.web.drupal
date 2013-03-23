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
    
    <div id="create_material" title="Create a material - step 2">
      <label>Title</label>
      <input type="text" placeholder="Type something…">
      
      <label>Language</label>
      <select class="span2">
        <option>English</option>
        <option>Vietnamese</option>
      </select>
      
      <label>Keyword</label>
      <input type="text" placeholder="Type something…">
      
      <label>Sumary</label>
      <textarea rows="5" style="width: 40%;"></textarea><br>

      <a class="btn btn-primary" href="create_material.php">« Back</a>
      <a class="btn btn-primary" href="create_material_step_3.php">Next »</a>
    </div>

    <div class="container">
      <?php require_once 'includes/home_block.php'; ?>
      <?php require_once 'includes/categories.php'; ?>
    </div>

    <?php require_once 'includes/footer.php'; ?>
  </body>
</html>
