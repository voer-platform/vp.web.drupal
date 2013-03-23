<!DOCTYPE html>
<html>
  <head>
    <title>Internet Technologies - Courseware | VOER</title>
    <?php require_once 'includes/header.php'; ?>
  </head>
  <body data-offset="80" data-target=".subnav" data-spy="scroll">
    <?php require_once 'includes/header_nav.php'; ?>

    <div class="container">
      <div class="row">
        <div class="span3">
          <div class="voer-sidenav1">
            <div class="well">
              <ul class="nav nav-list">
                <li class="nav-header">Language</li>
                <li class="active"><input type="checkbox" checked="checked" id="lang_english" class="category_check"><label for="lang_english" class="category_label">English</label></li>
                <li class="active"><input type="checkbox" id="lang_vietnamese" class="category_check"><label for="lang_vietnamese" class="category_label">Vietnamese</label></li>
              </ul>
            </div>

            <div class="well">             
              <ul class="nav nav-list">
                <li class="nav-header">Category</li>
                <li class="active"><input type="checkbox" checked="checked" id="art" class="category_check"><label for="art" class="category_label">Arts</label></li>
                <li class="active"><input type="checkbox" id="bus_manage" class="category_check"><label for="bus_manage" class="category_label">Business & Management</label></li>
                <li class="active"><input type="checkbox" checked="checked" id="computer" class="category_check"><label for="computer" class="category_label">Computer Science</label></li>
                <li class="active"><input type="checkbox" id="economic" class="category_check"><label for="economic" class="category_label">Economic & Finance</label></li>
                <li class="active"><input type="checkbox" id="energy" class="category_check"><label for="energy" class="category_label">Energy & Earth Sciences</label></li>
                <li class="active"><input type="checkbox" id="nutrition" class="category_check"><label for="nutrition" class="category_label">Food and Nutrition</label></li>
                <li class="active"><input type="checkbox" id="humanities" class="category_check"><label for="humanities" class="category_label">Humanities</label></li>
                <li class="active"><input type="checkbox" id="law" class="category_check"><label for="law" class="category_label">Law</label></li>
                <li class="active"><input type="checkbox" id="medicine" class="category_check"><label for="medicine" class="category_label">Medicine</label></li>
                <li class="active"><input type="checkbox" id="physics" class="category_check"><label for="physics" class="category_label">Physics</label></li>
                <li class="active"><input type="checkbox" id="statitics" class="category_check"><label for="statitics" class="category_label">Statitics and Data Analysis</label></li>
                <li class="active"><input type="checkbox" id="biology" class="category_check"><label for="biology" class="category_label">Biology & Life Sciences</label></li>
                <li class="active"><input type="checkbox" id="chemistry" class="category_check"><label for="chemistry" class="category_label">Chemistry</label></li>
                <li class="active"><input type="checkbox" id="education" class="category_check"><label for="education" class="category_label">Education</label></li>
                <li class="active"><input type="checkbox" id="engineering" class="category_check"><label for="engineering" class="category_label">Engineering</label></li>
                <li class="active"><input type="checkbox" id="society" class="category_check"><label for="society" class="category_label">Health & Society</label></li>
                <li class="active"><input type="checkbox" id="society" class="category_check"><label for="infomation" class="category_label">Infomation, Tech and Design</label></li>
                <li class="active"><input type="checkbox" id="mathematics" class="category_check"><label for="mathematics" class="category_label">Mathematics</label></li>
                <li class="active"><input type="checkbox" id="music" class="category_check"><label for="music" class="category_label">Music, Film and Audio</label></li>
                <li class="active"><input type="checkbox" id="social" class="category_check"><label for="social" class="category_label">Social Sciences</label></li>
              </ul>
            </div>
          </div>
        </div>
        <div id="search_result" class="span9">&nbsp;</div>
      </div>
    </div>

    <?php require_once 'includes/footer.php'; ?>
    <script>
      $(function(){
        $.post('category_list_ajax.php', function(res){
          $('#search_result').html(res);
        });

        $('input[type="checkbox"]').click(function(){
          $.post('category_list_ajax.php', function(res){
            $('#search_result').html(res);
          });
        });
      });
    </script>
  </body>
</html>
