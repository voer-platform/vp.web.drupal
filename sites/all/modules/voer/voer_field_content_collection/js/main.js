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
                "valid_children" : [ "folder", "default" ],
                "types": {
                    "default" : {
                        "valid_children" : "none"
                    },
                    "folder" : {
                        "valid_children" : [ "default", "folder" ]
                    }
                }
            }
        });

        $("div#outline-actions input").click(function () {
            switch(this.id) {
                case "add_default":

                case "add_folder":
                    $("#collection-outline").jstree("create", -1, "last", { "data": "Chapter", "attr" : { "rel" : this.id.toString().replace("add_", "") } });
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
    jQuery('<div id="voer_module_search_result"></div>').appendTo('.edit-voer-field-author .fieldset-wrapper');
  }

  //showLoadingState('#edit-field-voer-authors');

  jQuery.post('/ajax/s/m', {keyword: keyword, page: page}, function(data){
    // removeLoadingState('#edit-field-voer-authors');
    jQuery('#voer_module_search_result').html(data);
  })
}

