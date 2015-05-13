(function ($) {
  Drupal.behaviors.ccSetLink = {
	attach: function(context, settings){

	  $('.clickable', context).live({
		click: function(e) {
			var linkTarg = $(this).find('a.clickable-select');
   		    if(!(linkTarg.css('display') == 'none')) {
   		    	var link = $(this).find('a.clickable-select').attr('href');
   		    }
			if(link == null || linkTarg.hasClass('clickable-select-prevent-reload')){
				return;
			}
		    window.location = link;
		},
  	mouseenter: function(e) {
  		var linkTarg = $(this).find('a.clickable-select');
  		if(!(linkTarg.css('display') == 'none')) {
  			$(this).toggleClass('clickable-hover', true);
  		}
  	},
		mouseleave: function(e) {
	  		var linkTarg = $(this).find('a.clickable-select');
	  		if(!(linkTarg.css('display') == 'none')) {
	  			$(this).toggleClass('clickable-hover', false);
	  		}
		}
	  });
	}
  };

}(jQuery));
