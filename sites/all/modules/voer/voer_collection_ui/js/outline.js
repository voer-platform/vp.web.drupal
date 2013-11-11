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
                    el.parent().addClass('open');
                }
                el = el.parent();
            }
        }
    });
    jQuery('ul#outline-collection li.folder > a').click(function() {
        $(this).parent().find('div').slideToggle("quick", function(){
            $(this).parent().toggleClass('open', $(this).is(':visible'));
        });
        return false;
    });
})(jQuery);
