(function ($) {
  Drupal.behaviors.voer_field_content_collection = {
    attach: function(context, settings) {
      var all_categories = ["Business", "Social Sciences", "Science and Technology", "Humanities", "Arts",
            "Mathematics and Statistics"];
      var genre_template = Mustache.compile($.trim($("#genre_template").html()))
          ,$genre_container = $('#genre_criteria')

      $.each(all_categories, function(i, g){
        $genre_container.append(genre_template({id: i+1, name: g}));
      });

      var all_type = [{id: 1, name:'Module'}, {id: 2, name: 'Collection'}];
      var type_template = Mustache.compile($.trim($('#type_template').html()));
      var $type_container = $('#type_criteria');
      $.each(all_type, function(i, g){
        $type_container.append(type_template({type_id: g.id, type_name: g.name}));
      });

      // $("#runtime_slider").slider({
      //   min: 50,
      //   max: 250,
      //   values:[0, 250],
      //   step: 10,
      //   range:true,
      //   slide: function( event, ui ) {
      //     $("#runtime_range_label" ).html(ui.values[ 0 ] + ' mins. - ' + ui.values[ 1 ] + ' mins.');
      //     $('#runtime_filter').val(ui.values[0] + '-' + ui.values[1]).trigger('change');
      //   }
      // });

      $.each(Materials, function(i, m){ m.id = i+1; });
      window.mf = MovieFilter(Materials);

      $('#genre_criteria :checkbox').prop('checked', true);
      $('#all_categories').on('click', function(e){
        $('#genre_criteria :checkbox:gt(0)').prop('checked', $(this).is(':checked'));
        mf.filter();
      });

    }
  };
})(jQuery);

      var MovieFilter = function(data){
        var template = Mustache.compile(jQuery.trim(jQuery("#template").html()));

        var view = function(material){
          return template(material);
        };
        var callbacks = {
          after_filter: function(result){
            jQuery('#total_movies').text(result.length);
          },
          before_add: function(data){
            var offset = this.data.length;

            if (offset == 450) this.clearStreamingTimer();

            for(var i = 0, l = data.length; i < l; i++)
              data[i].id = offset + i + 1;
          },
          after_add: function(data){
            var percent = (this.data.length - 250)*100/250;
            jQuery('#stream_progress').text(percent + '%').attr('style', 'width: '+ percent +'%;');
            if (percent == 100) jQuery('#stream_progress').parent().fadeOut(1000);
          }
        };

        options = {
          filter_criteria: {
            // type:   ['#type_criteria input:checkbox:gt(0)', 'material_type'],
            category:   ['#genre_criteria input:checkbox:gt(0)', 'categories']
          },
          and_filter_on: true,
          callbacks: callbacks,
          search: {input: '#searchbox'}
          // streaming: {
          //   // data_url: '/ajax/materials-all',
          //   // data_url: '/top_movies_data.json',
          //   stream_after: 1,
          //   batch_size: 50
          // }
        }

        return FilterJS(data, "#materials", view, options);
      }
