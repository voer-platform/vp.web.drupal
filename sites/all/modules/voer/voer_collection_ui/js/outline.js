(function ($) {
    var currentURL = document.URL;

    jQuery('ul#outline-collection li > div').hide();
    jQuery('ul#outline-collection li:has(div)').addClass("folder");
    jQuery('ul#outline-collection li > a').each(function(index, e){
        var href = $(this).attr('href');
        if (currentURL.indexOf(href) != -1){
            $(this).addClass("active");
            var el = $(this).parent();
            while(el.attr('id') != 'outline-collection' ){
                if (el.is('div')){
                    el.show();
                }
                el = el.parent();
            }
        }
    });
    jQuery('ul#outline-collection li.folder > a').click(function() {
        $(this).parent().find('div').slideToggle();
        return false;
    });
})(jQuery);
