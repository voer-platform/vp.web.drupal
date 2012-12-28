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

  })
}(window.jQuery);
