(function ($) {
  var author_array = new Array();

  Drupal.behaviors.voer_content = {
    attach: function (context, settings) {
      var author_selected = jQuery('.voer-field-author-selected-text').val();

      if (author_selected) {
        author_array = author_selected.split(','); 
      }

      initAuthorDeleteBtn();

      $('.voer-field-author-search-btn', context).click(function () {
        var keyword = jQuery('.voer-field-author-search-text').val();
        searchAuthorByKeyword(keyword);
        return false;
      });

      $('#voer_person_search_result input.input-checkbox-item', context).live('click', function(){
        var author_id = $(this).val();

        if ($(this).is(':checked')) {
          if (author_array.indexOf(author_id) < 0) {
            $('.voer-field-author-picker').show();
            $('.voer-field-author-picker-list').show();
            var author_name = $(this).parent().text();
            author_array.push(author_id);
            $('<li class="voer-author-picker-'+author_id+'">'+author_name+'<span class="voer-author-delete" title="Delete author" rel="'+author_id+'"></span></li>').appendTo('.voer-field-author-picker-list');
            initAuthorDeleteBtn();
          }
        } else {
          $('.voer-field-author-picker-list').find('.voer-author-picker-' + author_id).remove();
          if ($('.voer-field-author-picker-list > li').length == 0) {
            $('.voer-field-author-picker').hide();
            $('.voer-field-author-picker-list').hide();
          }
          var index = author_array.indexOf(author_id);
          author_array.splice(index, 1);
        }

        $('.voer-field-author-selected-text', context).val(author_array.join(','));
      });

      function initAuthorDeleteBtn() {
        $('.voer-field-author-picker-list span.voer-author-delete').die('click');
        $('.voer-field-author-picker-list span.voer-author-delete').click(function(){
          var author_id = $(this).attr('rel');
          $(this).parent().remove();
          $('#voer_person_search_result').find('input[value="'+author_id+'"]').attr('checked', false);
          if ($('.voer-field-author-picker-list > li').length == 0) {
            $('.voer-field-author-picker').hide();
            $('.voer-field-author-picker-list').hide();
          }
          var index = author_array.indexOf(author_id);
          author_array.splice(index, 1);

          $('.voer-field-author-selected-text').val(author_array.join(','));
        });
      }
    }
  };
}(jQuery));

function showLoadingState(element) {
  if (element === undefined) {
    element = 'document';
    var coordinate = {top:0, left: 0};
    var loadingWidth = jQuery(window).width() - 2;
    var loadingHeight = jQuery(window).height() - 2;

  } else {
    var coordinate = jQuery(element).offset();
    var loadingWidth = jQuery(element).width() - 2;
    var loadingHeight = jQuery(element).height() - 2;
  }

  if (loadingWidth == -2) {
    loadingWidth = 350;
  }

  if (loadingHeight == -2) {
    loadingHeight = 32;
  }

  var div = jQuery(document.createElement('div'));
  var elementId = element.substring(1);

  div.attr('id', elementId + '-loading');
  div.attr('class', 'loading');
  if (coordinate) {
    div.css({
      width: loadingWidth,
      height: loadingHeight,
      position: element == 'document' ? 'fixed' : 'absolute',
      zIndex: element == 'document' ? '2' : '999999',
      top: coordinate.top + 1,
      left: element == 'document' ? (coordinate.left + 1) : (coordinate.left + 1 + parseInt(jQuery(element).css('padding-left')))
    });
  }

  var loadingMargin = Math.round((loadingHeight / 2) - 16);
  var content = '<div style="text-align:center;margin-top:' + loadingMargin + 'px">Đang tải dữ liệu...</div>';

  div.html(content);
  div.appendTo('body');
}

function removeLoadingState(element) {
  if (element === undefined) {
    element = '#document';
  } else {
    element = '#' + element.substring(1);
  }

  jQuery(element + '-loading').remove();
}

function searchAuthorByKeyword(keyword, page) {
  var author_list = jQuery('.voer-field-author-selected-text').val();

  if (page === undefined) {
    page = 1;
  }

  if (jQuery('#voer_person_search_result').length == 0) {
    jQuery('<div id="voer_person_search_result"></div>').appendTo('.edit-voer-field-author .fieldset-wrapper');
  }

  showLoadingState('#edit-field-voer-authors');

  jQuery.post('/person/search', {keyword: keyword, page: page, author_list: author_list}, function(data){
    removeLoadingState('#edit-field-voer-authors');
    jQuery('#voer_person_search_result').html(data);
  })
}

function loadAuthorSearchPage(ele) {
  var keyword = jQuery(ele).attr('keyword');
  var page = jQuery(ele).attr('page');
  searchAuthorByKeyword(keyword, page);
  return false;
}
