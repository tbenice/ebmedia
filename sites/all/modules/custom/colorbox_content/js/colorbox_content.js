/**
 * @file colorbox_content.js
 */

(function ($) {
	Drupal.behaviors.ColorboxContent = {
		attach: function(context, settings) {
			$('body').delegate('a.colorbox-content', 'click', function(e) {
				var args = getUrlVars($(this));
				var query = args['query'];
				var url = settings.basePath + 'colorbox-content-load?' + query;
				$.colorbox({href:url});
				e.preventDefault();
			});

            /* Colorbox resize function */
            var resizeTimer;
            function resizeColorBox()
            {
                if (resizeTimer) clearTimeout(resizeTimer);
                resizeTimer = setTimeout(function() {
                    if (jQuery('.cart-popup-container').is(':visible')) {
                        jQuery.colorbox.resize({width:'75%'});
                        $('#cart-popup-item-message').css("margin-bottom", "20px");
                    }
                }, 100)
            }

            // Resize Colorbox when ready, resizing window, or changing mobile device orientation
            $(window).ready(resizeColorBox);
            $(window).resize(resizeColorBox);
            window.addEventListener("orientationchange", resizeColorBox, false);

			/**
			  * provide extraction of get param from url
			  */
			function getUrlVars(element){
			  var vars = [], hash;
			  //if element is there use it
			  //otherwise use window
			   if(!(element == null)) {
			       var hashes = element.attr('href').slice(element.attr('href').indexOf('?') + 1).split('&');
			   }
			   else {
			       var hashes = window.location.href.slice(window.location.href.indexOf('?') + 1).split('&');
			   }
			   for(var i = 0; i < hashes.length; i++)
			   {
			     hash = hashes[i].split('=');
			     vars.push(hash[0]);
			     vars[hash[0]] = hash[1];
			   }
			   vars.push('query');
			   vars['query'] = hashes.join('&');
			   return vars;
			 }	
		}	
	};
})(jQuery);