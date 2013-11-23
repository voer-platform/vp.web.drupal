<div class="row">
<div class="sidebar span3">
  <div class="row">
    <h4 class="col-span-6"> Materials (<span id="total_movies">250</span>)</h4>
    <div class="col-span-6 progress">
      <div class="progress-bar" id="stream_progress" style="width: 0%">0 %</div>
    </div>
  </div>
  <div>
    <input type="text" id="searchbox" placeholder="Search...">
    <span class="glyphicon glyphicon-search search-icon"></span>
  </div>
  <div class="criteria" id="type_criteria">
    <h4>Type</h4>
    <div class="checkbox">
      <label>
        <input type="checkbox" value='All' id="all_type"> All
      </label>
    </div>
  </div>
  <div class="criteria" id="genre_criteria">
    <h4>Categories</h4>
    <div class="checkbox">
      <label>
        <input type="checkbox" value='All' id="all_categories"> All
      </label>
    </div>
  </div>
</div>
<div class="movies content span9">
  <div class="row-fluid show-grid" id="materials">
  </div>
</div>
<script id="template" type="text/html">
  <div class="span4 movie">
    <div class="thumbnail">
      <div class="caption">
        <h4><a href="/m/{{material_id}}">{{title}}</a></h4>
        <div class="detail">
          <dl>
            <dt>Author</dt>
            <dd>{{author}}</dd>
            <dt>Category</dt>
            <dd>{{categories}}</dt>
          </dl>
        </div>
      </div>
    </div>
  </div>
</script>
<script id="genre_template" type="text/html">
  <div class="checkbox">
    <label>
      <input type="checkbox" value="{{id}}"> {{name}}
    </label>
  </div>
</script>
<script id="type_template" type="text/html">
  <div class="checkbox">
    <label>
      <input type="checkbox" value="{{type_id}}"> {{type_name}}
    </label>
  </div>
</script>
