(function ($) {
    Drupal.behaviors.voer_batch_import = {
        attach:function(context, settings) {
            $('#file_upload').uploadify({
                'auto'     : false,
                'removeCompleted' : false,
                'formData' : {'uid': Drupal.settings.voer_import.uid},
                'fileTypeDesc' : 'Document Files',
                'fileTypeExts' : '*.doc; *.docx',
                'swf'      : '/sites/all/modules/voer/voer_batch_import/uploadify/uploadify.swf',
                'uploader' : '/import/handler'
            });
        }
    };
})(jQuery);
