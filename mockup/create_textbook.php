<!DOCTYPE html>
<html>
  <head>
    <title>Create textbook - VOER</title>
    <?php require_once 'includes/header.php'; ?>
    <link href="css/sitemap.css" rel="stylesheet" media="screen">
    <script src="js/hs_dragable.js"></script>
  </head>
  <body data-offset="80" data-target=".subnav" data-spy="scroll">
    <?php require_once 'includes/header_nav.php'; ?>

    <div class="container">
      <div class="page-header">
        <h3>Create textbook</h3>
      </div>

      <div class="row-fluid">
        <div class="span9">
          <ul id="sitemap">
            <li>
              <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                <dt><a class="sm2_title" href="#">Home</a></dt>
                <dd class="sm2_actions">
                  <strong>Actions:</strong> 
                  <span class="sm2_move" title="Move">Move</span>
                  <span class="sm2_delete" title="Delete">Delete</span>
                  <a href="#" class="sm2_addChild" title="Add Child">Add Child</a>
                </dd>
                <dd class="sm2_status">
                  <strong>Status:</strong> 
                  <span class="sm2_unpub" title="Published">Published</span>
                  <span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
              </dl>
            </li>
            <li class="sm2_liOpen">
              <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                <dt><a class="sm2_title" href="#">About us</a></dt>
                <dd class="sm2_actions"><strong>Actions:</strong> <span class="sm2_move" title="Move">Move</span><span class="sm2_delete" title="Delete">Delete</span><a href="#" class="sm2_addChild" title="Add Child">Add Child</a></dd>
                <dd class="sm2_status"><strong>Status:</strong> <span class="sm2_pub" title="Published">Published</span><span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
              </dl>
              <ul>
                <li class="sm2_liOpen">
                  <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                    <dt><a class="sm2_title" href="#">Things we do</a></dt>
                    <dd class="sm2_actions"><strong>Actions:</strong> <span class="sm2_move" title="Move">Move</span><span class="sm2_delete" title="Delete">Delete</span><a href="#" class="sm2_addChild" title="Add Child">Add Child</a></dd>
                    <dd class="sm2_status"><strong>Status:</strong> <span class="sm2_pub" title="Published">Published</span><span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
                  </dl>
                  <ul>
                    <li>
                      <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                        <dt><a class="sm2_title" href="#">Our projects</a></dt>
                        <dd class="sm2_actions"><strong>Actions:</strong> <span class="sm2_move" title="Move">Move</span><span class="sm2_delete" title="Delete">Delete</span><a href="#" class="sm2_addChild" title="Add Child">Add Child</a></dd>
                        <dd class="sm2_status"><strong>Status:</strong> <span class="sm2_unpub" title="Published">Published</span><span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
                      </dl>
                    </li>
                    <li>
                      <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                        <dt><a class="sm2_title" href="#">Our goals</a><a href="#"class="sm2_expander">&nbsp;</a></dt>
                        <dd class="sm2_actions"><strong>Actions:</strong> <span class="sm2_move" title="Move">Move</span><span class="sm2_delete" title="Delete">Delete</span><a href="#" class="sm2_addChild" title="Add Child">Add Child</a></dd>
                        <dd class="sm2_status"><strong>Status:</strong> <span class="sm2_unpub" title="Published">Published</span><span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
                      </dl>
                    </li>
                    <li>
                      <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                        <dt><a class="sm2_title" href="#">Our people</a></dt>
                        <dd class="sm2_actions"><strong>Actions:</strong> <span class="sm2_move" title="Move">Move</span><span class="sm2_delete" title="Delete">Delete</span><a href="#" class="sm2_addChild" title="Add Child">Add Child</a></dd>
                        <dd class="sm2_status"><strong>Status:</strong> <span class="sm2_unpub" title="Published">Published</span><span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
                      </dl>
                    </li>
                  </ul>
                </li>
                <li>
                  <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                    <dt><a class="sm2_title" href="#">Our Mission</a></dt>
                    <dd class="sm2_actions"><strong>Actions:</strong> <span class="sm2_move" title="Move">Move</span><span class="sm2_delete" title="Delete">Delete</span><a href="#" class="sm2_addChild" title="Add Child">Add Child</a></dd>
                    <dd class="sm2_status"><strong>Status:</strong> <span class="sm2_pub" title="Published">Published</span><span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
                  </dl>
                </li>
                <li>
                  <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                    <dt><a class="sm2_title" href="#">Contact us</a></dt>
                    <dd class="sm2_actions"><strong>Actions:</strong> <span class="sm2_move" title="Move">Move</span><span class="sm2_delete" title="Delete">Delete</span><a href="#" class="sm2_addChild" title="Add Child">Add Child</a></dd>
                    <dd class="sm2_status"><strong>Status:</strong> <span class="sm2_unpub" title="Published">Published</span><span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
                  </dl>
                </li>
              </ul>
            </li>
            <li class="sm2_liOpen">
              <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                <dt><a class="sm2_title" href="#">Case studies</a></dt>
                <dd class="sm2_actions"><strong>Actions:</strong> <span class="sm2_move" title="Move">Move</span><span class="sm2_delete" title="Delete">Delete</span><a href="#" class="sm2_addChild" title="Add Child">Add Child</a></dd>
                <dd class="sm2_status"><strong>Status:</strong> <span class="sm2_pub" title="Published">Published</span><span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
              </dl>
              <ul>
                <li>
                  <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                    <dt><a class="sm2_title" href="#">Case study 1</a></dt>
                    <dd class="sm2_actions"><strong>Actions:</strong> <span class="sm2_move" title="Move">Move</span><span class="sm2_delete" title="Delete">Delete</span><a href="#" class="sm2_addChild" title="Add Child">Add Child</a></dd>
                    <dd class="sm2_status"><strong>Status:</strong> <span class="sm2_unpub" title="Published">Published</span><span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
                  </dl>
                </li>
                <li>
                  <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                    <dt><a class="sm2_title" href="#">Case study 2</a></dt>
                    <dd class="sm2_actions"><strong>Actions:</strong> <span class="sm2_move" title="Move">Move</span><span class="sm2_delete" title="Delete">Delete</span><a href="#" class="sm2_addChild" title="Add Child">Add Child</a></dd>
                    <dd class="sm2_status"><strong>Status:</strong> <span class="sm2_unpub" title="Published">Published</span><span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
                  </dl>
                </li>
                <li>
                  <dl class="sm2_s_published"><a href="#"class="sm2_expander">&nbsp;</a>
                    <dt><a class="sm2_title" href="#">Case study 3</a></dt>
                    <dd class="sm2_actions"><strong>Actions:</strong> <span class="sm2_move" title="Move">Move</span><span class="sm2_delete" title="Delete">Delete</span><a href="#" class="sm2_addChild" title="Add Child">Add Child</a></dd>
                    <dd class="sm2_status"><strong>Status:</strong> <span class="sm2_unpub" title="Published">Published</span><span class="sm2_workFlow" title="Draft Exists">Draft Exists</span></dd>
                  </dl>
                </li>
              </ul>
            </li>
          </ul>
          <p>&nbsp;</p><p><em>Hint: Use Ctrl+z to undo a mistake!</em></p>
        </div>
      </div>
    </div>

    <?php require_once 'includes/footer.php'; ?>
  </body>
</html>
