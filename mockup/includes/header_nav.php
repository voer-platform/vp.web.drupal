<?php 
@session_start();
?>

<div class="navbar navbar-fixed-top">
  <div class="navbar-inner">
    <div class="container">
      <a id="logo" href="index.php"><img src="images/voer_logo.png" /></a>
      <ul class="nav hidden-phone">
        <li><a href="#">Learn</a></li>
        <li><a href="#">Contribute</a></li>
        <li><a href="aboutus.php">About us</a></li>
        <li><a href="#">Support</a></li>
      </ul>

      <ul class="nav pull-right">
        <?php if (is_null($_SESSION['visitor'])) : ?>
        <li class="dropdown">
          <a class="dropdown-toggle" data-toggle="dropdown" href="#">Sign in <strong class="caret"></strong></a>
          <div class="dropdown-menu" style="padding: 15px; padding-bottom: 0px;">
          <form method="post" action="login.php" accept-charset="UTF-8">
          <input style="margin-bottom: 15px;" type="text" placeholder="Username" id="username" name="username">
          <input style="margin-bottom: 15px;" type="password" placeholder="Password" id="password" name="password">
          <input style="float: left; margin-right: 10px;" type="checkbox" name="remember-me" id="remember-me" value="1">
          <label class="string optional" for="user_remember_me"> Remember me</label>
          <input class="btn btn-primary btn-block" type="submit" id="sign-in" value="Sign In">
          <label style="text-align:center;margin-top:5px">or</label>
          <input class="btn btn-primary btn-block" type="button" id="sign-in-google" value="Sign In with Google">
          <input class="btn btn-primary btn-block" type="button" id="sign-in-twitter" value="Sign In with Twitter">
          </form>
          </div>
        </li>
        <li><a class="signup" href="signup.php">Sign up</a></li>

        <?php else : ?>
        <li><a class="dashboard" href="#">Dashboard</a></li>
        <li><a href="logout.php">Sign out</a></li>
        <?php endif; ?>
      </ul>
    </div>
  </div>
</div>
