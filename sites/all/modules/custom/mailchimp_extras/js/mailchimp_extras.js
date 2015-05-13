(function($) {
  Drupal.behaviors.idMailinglistLink = {
    attach: function(context, settings) {
	    $('.mailchimp-extras-mailing-list-subscribe-link', context).bind('click', function(e) {
	      var id = '#mailing-list-mailchimp-subscribe-form';
		  $.colorbox({href:id, inline:true, innerWidth: 500, innerHeight:350});
		  e.preventDefault();
	    });	 
	}
  };
})(jQuery);



