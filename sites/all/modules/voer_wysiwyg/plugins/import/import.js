// $Id$

(function ($) {

Drupal.wysiwyg.plugins['import'] = {

  /**
   * Return whether the passed node belongs to this plugin (note that "node" in this context is a JQuery node, not a Drupal node).
   *
   * We identify code managed by this FOO plugin by giving it the HTML class
   * 'wysiwyg_plugin_example-foo'.
   */
  isNode: function(node) {
    res = $(node).is('img.wysiwyg_plugin_example-foo');
    return ($(node).is('img.wysiwyg_plugin_example-foo'));
  },

  /**
   * Invoke is called when the toolbar button is clicked.
   */
  invoke: function(data, settings, instanceId) {
     // Typically, an icon might be added to the WYSIWYG, which HTML gets added
     // to the plain-text version.
     if (data.format == 'html') {
       var content = this._getPlaceholder(settings);
     }
     else {
       var content = '<!--wysiwyg_example_plugin-->';
     }
     if (typeof content != 'undefined') {
       Drupal.wysiwyg.instances[instanceId].insert(content);
     }
   },

  /**
   * Replace all <!--wysiwyg_example_plugin--> tags with the icon.
   */
  attach: function(content, settings, instanceId) {
    content = content.replace(/<!--wysiwyg_example_plugin-->/g, this._getPlaceholder(settings));
    return content;
  },

  /**
   * Replace the icons with <!--wysiwyg_example_plugin--> tags in content upon detaching editor.
   */
  detach: function(content, settings, instanceId) {
    var $content = $('<div>' + content + '</div>');
    $.each($('img.wysiwyg_plugin_example-foo', $content), function (i, elem) {
      elem.parentNode.insertBefore(document.createComment('wysiwyg_example_plugin'), elem);
      elem.parentNode.removeChild(elem);
    });
    return $content.html();
  },

  /**
   * Helper function to return a HTML placeholder.
   *
   * Here we provide an image to visually represent the hidden HTML in the Wysiwyg editor.
   */
  _getPlaceholder: function (settings) {
    return '<img src="' + settings.path + '/images/foo.content_icon.gif" alt="&lt;--wysiwyg_example_plugin-&gt;" title="&lt;--wysiwyg_example_plugin--&gt;" class="wysiwyg_plugin_example-foo drupal-content" />';
  }
};

})(jQuery);
