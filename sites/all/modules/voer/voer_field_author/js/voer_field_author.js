(function ($) {
  var author_roles = new Array();
  author_roles[0] = 'author';
  author_roles[1] = 'editor';
  author_roles[2] = 'licensor';
  author_roles[3] = 'maintainer';
  author_roles[4] = 'translator';
  author_roles[5] = 'contributor';

  Drupal.behaviors.voer_content = {
    attach: function (context, settings) {
      initAuthorDeleteBtn();

      $('.voer-field-author-search-btn', context).click(function () {
        var keyword = jQuery('.voer-field-author-search-text').val();
        searchAuthorByKeyword(keyword);
        return false;
      });

      $('#voer-author-table-list span.voer-add-authors', context).live('click', function(){
        var spanAddEle = $(this);
        var author_id = spanAddEle.attr('rel');

        showLoadingState('#voer_person_search_result');
        $.getJSON('/person/info', {author_id: author_id}, function(data){
          if (data) {
            removeLoadingState('#voer_person_search_result');
            spanAddEle.parent().fadeOut();

            var rowEle = '<td><a target="_blank" href="/person/'+data.id+'">'+data.fullname+'</a></td>';
            rowEle += '<td><a target="_blank" href="/person/'+data.id+'">'+data.user_id+'</a></td>';

            for (var i=0;i<author_roles.length;i++) {
              rowEle += '<td class="member-role-'+author_roles[i]+'"><input type="checkbox" class="member-roles roles-'+author_roles[i]+'-'+data.id+'" value="'+data.id+'" role="'+author_roles[i]+'"></td>';
            }
            rowEle += '<td><span class="voer-author-delete" title="Delete author" rel="'+data.id+'"></span></td>';

            if ($('#voer-node-table tbody tr > td').hasClass('empty')) {
              $('#voer-node-table tbody').empty();
            }

            $('#voer-node-table tbody').append('<tr>'+rowEle+'</tr>');
            $('.voer-field-author-picker-list').show();

            resetTableAuthorPicker();
            initAuthorDeleteBtn();
          } else {
            alert('Author is not exists.');
          }
        });
      });

      function initAuthorDeleteBtn() {
        $('#voer-node-table td span.voer-author-delete').die('click');
        $('#voer-node-table td span.voer-author-delete').click(function(){
          var author_id = $(this).attr('rel');
          $(this).parents('tr').remove();
          $('#voer-author-table-list').find('span[rel="'+author_id+'"]').parent().removeClass('display_none').css('display', '');
          if ($('#voer-node-table tbody > tr').length == 0) {
            $('.voer-field-author-picker-list').hide();
          }

          for (var i=0;i<author_roles.length;i++) {
            var author_selected_tmp = $('.voer-field-author-selected-'+author_roles[i]).val();
            var author_selected_array = new Array();

            if (author_selected_tmp) {
              author_selected_array = author_selected_tmp.split(',');
            }

            var index = author_selected_array.indexOf(author_id);
            author_selected_array.splice(index, 1);

            $('.voer-field-author-selected-'+author_roles[i]).val(author_selected_array.join(','));
          }

          resetTableAuthorPicker();
        });

        $('input[class^="member-roles"]').die('click');
        $('input[class^="member-roles"]').click(function(){
          var role_name = jQuery(this).attr('role');
          var author_id = jQuery(this).val();
          var author_selected_tmp = $('.voer-field-author-selected-'+role_name).val();
          var author_selected_array = new Array();

          if (author_selected_tmp) {
            author_selected_array = author_selected_tmp.split(',');
          }

          if ($(this).is(':checked')) {
            if (author_selected_array.indexOf(author_id) < 0) {
              author_selected_array.push(author_id);
            }
          } else {
            var index = author_selected_array.indexOf(author_id);
            author_selected_array.splice(index, 1);
          }

          $('.voer-field-author-selected-'+role_name).val(author_selected_array.join(','));
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
  var author_array = new Array();
  jQuery('input[role="author"]').each(function(){
    author_array.push(jQuery(this).val());
  });

  if (page === undefined) {
    page = 1;
  }

  if (jQuery('#voer_person_search_result').length == 0) {
    jQuery('<div id="voer_person_search_result"></div>').appendTo('.edit-voer-field-author .fieldset-wrapper');
  }

  showLoadingState('#edit-field-voer-authors');
  jQuery.post('/person/search', {keyword: keyword, page: page, author_list: author_array.join(',')}, function(data){
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

function resetTableAuthorPicker() {
  jQuery('#voer-node-table tbody tr').each(function(index){
    jQuery(this).removeAttr('class');
  });

  jQuery('#voer-node-table tbody tr:odd').addClass('even');
  jQuery('#voer-node-table tbody tr:even').addClass('odd');
}
