!function ($) {
  $(function(){
    // fix sub nav on scroll
    var $win = $(window)
    , $nav = $('.subnav')
    , navHeight = $('.navbar').first().height()
    , navTop = $('.subnav').length && $('.subnav').offset().top - navHeight
    , isFixed = 0
    processScroll()

    $win.on('scroll', processScroll)

    function processScroll() {
      var i, scrollTop = $win.scrollTop()
      if (scrollTop >= navTop && !isFixed) {
        isFixed = 1
        $nav.addClass('subnav-fixed')
      } else if (scrollTop <= navTop && isFixed) {
        isFixed = 0
        $nav.removeClass('subnav-fixed')
      }
    }

    var $window = $(window);

    // Disable certain links in docs
    $('section [href^=#]').click(function (e) {
      e.preventDefault()
    });

     // side bar
    $('.voer-sidenav').affix({
      offset: {
        top: function () { return $window.width() <= 980 ? 290 : 210 }
        , bottom: 270
      }
    });

    jQuery('.sign_in').click(function(){
      jQuery('.signin_form_wrapper').toggle();
    });

    $("#dialog").dialog({
			//autoOpen: true,
      modal: true,
      resizable: false,
      draggable: false,
      minWidth: 1070
		});
    
    $("#create_material").dialog({
			//autoOpen: true,
      modal: true,
      resizable: false,
      draggable: false,
      minWidth: 1070
		});

		// Link to open the dialog
		$(".dashboard").click(function( event ) {
			$("#dialog").dialog( "open" );
			event.preventDefault();
		});

    randomPictures('help');
    randomPictures('questionnaire');
    randomPictures('courseware');
    randomPictures('textbook');
    randomPictures('collection');
    randomPictures('module');
  })
}(window.jQuery);

function randomPictures(ele)
{
  var randomNumber = randomRange(1, 3);

  jQuery('.cls_' + ele).css('background-image', 'url(images/' + ele + randomNumber + '.jpg)');
}

function randomRange(min, max) {
  return ~~(Math.random() * (max - min + 1)) + min
}
