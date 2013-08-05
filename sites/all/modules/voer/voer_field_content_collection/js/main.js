(function ($) {
Drupal.behaviors.voer_field_content_collection = {
    attach: function(context, settings) {
        $("#collection-outline").jstree({
            "plugins" : [
                "themes","json_data","ui","crrm","cookies","dnd","search","types","hotkeys","contextmenu"
            ],
            "json_data" : {
                "data" : [
                ]
            },
            "types" : {
                // I set both options to -2, as I do not need depth and children count checking
                // Those two checks may slow jstree a lot, so use only when needed
                "max_depth" : -2,
                "max_children" : -2,
                "valid_children" : [ "bundle", "module" ],
                "types": {
                    "module" : {
                        "valid_children" : "none"
                    },
                    "bundle" : {
                        "valid_children" : [ "module", "bundle" ]
                    }
                }
            }
        })
        .bind("create.jstree", function (e, data) {
            var jsonData = $("#collection-outline").jstree('get_json', -1);
            var jsonStr =  JSON.stringify(jsonData);
            $('#voer-outline-wrapper .voer-outline-text').val(jsonStr);
        })
        .bind("remove.jstree", function (e, data) {
            var jsonData = $("#collection-outline").jstree('get_json', -1);
            var jsonStr =  JSON.stringify(jsonData);
            $('#voer-outline-wrapper .voer-outline-text').val(jsonStr);
        })
        .bind("rename.jstree", function (e, data) {
            var jsonData = $("#collection-outline").jstree('get_json', -1);
            var jsonStr =  JSON.stringify(jsonData);
            $('#voer-outline-wrapper .voer-outline-text').val(jsonStr);
        })
        .bind("move_node.jstree", function (e, data) {
            var jsonData = $("#collection-outline").jstree('get_json', -1);
            var jsonStr =  JSON.stringify(jsonData);
            $('#voer-outline-wrapper .voer-outline-text').val(jsonStr);
        });

        $("div#outline-actions input").click(function () {
            switch(this.id) {
                case "add_default":
                    $("#voer_module_search_result input[type=checkbox]:checked").map(function(){
                        var id = $(this).val();
                        var title = $(this).parent().text().trim();
                        var parentNode = -1;
                        if ($("#collection-outline").jstree("get_selected")){
                            parentNode = null;
                        }
                        $("#collection-outline").jstree("create", parentNode, "last", { "data": title, "attr" : { "id": id, "rel" : "module" } });
                    });
                    break;
                case "add_folder":
                    var parentNode = -1;
                    if ($("#collection-outline").jstree("get_selected")){
                        parentNode = null;
                    }
                    $("#collection-outline").jstree("create", parentNode, "last", { "data": "Chapter", "attr" : { "rel" : "bundle" } });
                    break;
                case "search":
                    $("#collection-outline").jstree("search", document.getElementById("text").value);
                    break;
                case "info":
                    var jsonData = $("#collection-outline").jstree('get_json', -1);
                    var jsonStr =  JSON.stringify(jsonData);
                    console.log(jsonStr);
                    break;
                default:
                    $("#collection-outline").jstree(this.id);
                    break;
            }

            var jsonData = $("#collection-outline").jstree('get_json', -1);
            var jsonStr =  JSON.stringify(jsonData);
            $('#voer-outline-wrapper .voer-outline-text').val(jsonStr);

            return false;
        });

        $('.voer-module-search-btn', context).click(function () {
            var keyword = jQuery('.voer-module-search-text').val();
            searchModuleByKeyword(keyword);
            return false;
        });
    }
};
})(jQuery);

function searchModuleByKeyword(keyword, page) {
  if (page === undefined) {
    page = 1;
  }

  if (jQuery('#voer_module_search_result').length == 0) {
    jQuery('<div id="voer_module_search_result"></div>').appendTo('#voer-outline-wrapper');
  }

  //showLoadingState('#edit-field-voer-authors');

  jQuery.post('/ajax/s/m', {keyword: keyword, page: page}, function(data){
    // removeLoadingState('#edit-field-voer-authors');
    jQuery('#voer_module_search_result').html(data);
  })
}

function loadModuleSearchPage(ele) {
  var keyword = jQuery(ele).attr('keyword');
  var page = jQuery(ele).attr('page');
  searchModuleByKeyword(keyword, page);
  return false;
}

