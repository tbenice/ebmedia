/**
 * 
 */
(function($) {
	Drupal.behaviors.inlineEditing = {
		attach: function(context, settings) {
			$('body', context).delegate('a.inline-editing-show', 'click', function(e){
				if($(this).hasClass('inline-editing-processed')) {
					$(this)
						.toggleClass('inline-editing-processed')
						.html('[edit]');
					$(this).parent().next().find('div.inline-editing-form-wrapper').hide();						
				}
				else {
					$(this)
						.toggleClass('inline-editing-processed')
						.html('[close]');
					$(this).parent().next().find('div.inline-editing-form-wrapper').show();
				}
				e.preventDefault();
			});
			$('form.inline-editing div.form-actions .form-submit', context).click(function(){
				$(this).parents('div.inline-editing-form-wrapper').hide();
			});
		}	
	};
}(jQuery));
