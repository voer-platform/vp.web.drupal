(function ($) {
  Drupal.behaviors.voer_field_content_collection = {
    attach: function(context, settings) {
      var all_categories = [
            {id: 1, name:"Business"},
            {id: 2, name:"Social Sciences"},
            {id: 3, name:"Science and Technology"},
            {id: 4, name:"Humanities"},
            {id: 5, name:"Arts"},
            {id: 6, name:"Mathematics and Statistics"}];
      var genre_template = Mustache.compile($.trim($("#genre_template").html()))
          ,$genre_container = $('#category_criteria')

      $.each(all_categories, function(i, g){
        $genre_container.append(genre_template({id: g.id, name: g.name}));
      });

      var all_type = [{id: 'voer_module', name:'Module'}, {id: 'voer_collection', name: 'Collection'}];
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

      $('#category_criteria :checkbox').prop('checked', true);
      $('#all_categories').on('click', function(e){
        $('#category_criteria :checkbox:gt(0)').prop('checked', $(this).is(':checked'));
        mf.filter();
      });

      $('#type_criteria :checkbox').prop('checked', true);
      $('#all_type').on('click', function(e){
        if ($(this).is(':checked')){
          $('#type_criteria :checkbox:gt(0)').prop('checked', false);
        }
        mf.filter();
      });

      $('#type_criteria :checkbox:gt(0)').on('click', function(e){

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
            type:   ['#type_criteria input:checkbox:gt(0) .EVENT.click .SELECT.:checked .TYPE.value_filter', 'type'],
            category:   ['#category_criteria input:checkbox:gt(0) .EVENT.click .SELECT.:checked .TYPE.value_filter', 'categories']
          },
          and_filter_on: true,
          callbacks: callbacks,
          filter_types:filter_type_functions,
          search: {input: '#searchbox'}
          // streaming: {
          //   // data_url: '/ajax/materials-all',
          //   // data_url: '/top_movies_data.json',
          //   stream_after: 1,
          //   batch_size: 50
          // }
        }

        var filter_type_functions = {
          value_filter: function(value, type){
            // console.log('Value = ' + value);
            // console.log('Value = ' + type);
            // alert('hi');
            if (value == 'all'){
              return true;
            }
            if (value == type){return true;}
          },
        };

        return FilterJS(data, "#materials", view, options);
      }
