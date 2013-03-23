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

    <div id="create_material" title="Create a material - step 1">
      <textarea rows="10" class="disabled" disabled="disabled" style="width: 99%;">Lorem ipsum dolor sit amet,  Nulla nec tortor. Donec id elit quis purus consectetur consequat. Nam congue semper tellus. Sed erat dolor, dapibus sit amet, venenatis ornare, ultrices ut, nisi. Aliquam ante. Suspendisse scelerisque dui nec velit. Duis augue augue, gravida euismod, vulputate ac, facilisis id, sem. Morbi in orci. Nulla purus lacus, pulvinar vel, malesuada ac, mattis nec, quam. Nam molestie scelerisque quam. Nullam feugiat cursus lacus.orem ipsum dolor sit amet, consectetur adipiscing elit. Donec libero risus, commodo vitae, pharetra mollis, posuere eu, pede. Nulla nec tortor. Donec id elit quis purus consectetur consequat. Nam congue semper tellus. Sed erat dolor, dapibus sit amet, venenatis ornare, ultrices ut, nisi. Aliquam ante. Suspendisse scelerisque dui nec velit. Duis augue augue, gravida euismod, vulputate ac, facilisis id, sem. Morbi in orci. Nulla purus lacus, pulvinar vel, malesuada ac, mattis nec, quam. Nam molestie scelerisque quam. Nullam feugiat cursus lacus.orem ipsum dolor sit amet, consectetur adipiscing elit. Donec libero risus, commodo vitae, pharetra mollis, posuere eu, pede. Nulla nec tortor. Donec id elit quis purus consectetur consequat. Nam congue semper tellus. Sed erat dolor, dapibus sit amet, venenatis ornare, ultrices ut, nisi. Aliquam ante. Suspendisse scelerisque dui nec velit. Duis augue augue, gravida euismod, vulputate ac, facilisis id, sem. Morbi in orci. Nulla purus lacus, pulvinar vel, malesuada ac, mattis nec, quam. Nam molestie scelerisque quam. Nullam feugiat cursus lacus.orem ipsum dolor sit amet, consectetur adipiscing elit. Donec libero risus, commodo vitae, pharetra mollis, posuere eu, pede. Nulla nec tortor. Donec id elit quis purus consectetur consequat. Nam congue semper tellus. Sed erat dolor, dapibus sit amet, venenatis ornare, ultrices ut, nisi.</textarea>
      <label class="checkbox">
        <input type="checkbox"> I have read above, and I agree to license this new word under this terms. <span style="color: red;">*</span>
      </label>
      <a class="btn btn-primary" href="create_material_step_2.php">Next »</a>
    </div>

    <div class="container">
      <?php require_once 'includes/home_block.php'; ?>
      <?php require_once 'includes/categories.php'; ?>
    </div>

    <?php require_once 'includes/footer.php'; ?>
  </body>
</html>
