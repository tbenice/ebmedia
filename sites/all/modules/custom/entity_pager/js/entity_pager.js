(function ($){
	Drupal.behaviors.nodePagerScroll = {
		attach: function(context, settings) {
			if($('div.node-pager-container').length < 1) {return false;}
			var remainingHeight = ($(document).height() - $(window).height());
			//show all node pagers not using the js scroll function
			for(var noJsSelector in settings.nodePagersNoJs) {
				$('#' + noJsSelector).toggleClass('node-pager-show').toggleClass('node-pager-js');
			}
			//if no scrollbar on page, show all pagers
			if(remainingHeight == 0) {
				$('div.node-pager-container').each().toggleClass('node-pager-show');
			}
			$(window).scroll(function() {
				//loop through all js-enabled node-pagers
				for(var selector in settings.nodePagers){
					var scrollPercent = settings.nodePagers[selector]['scrollPercent'];
					if(($(window).scrollTop() > ($(window).height() * (scrollPercent/100))) || ($(window).scrollTop() == ($(document).height() - $(window).height()))) {
						$('#' + selector).not('.node-pager-show').toggleClass('node-pager-show');
					}
					else {
						$('#' + selector).toggleClass('node-pager-show', false);					
					}
				}				
			});
		}
	};
}(jQuery));

