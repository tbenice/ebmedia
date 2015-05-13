/**
 * @file binds events to elements that bear
 * 	the contextual-messages-target class. These
 * 	events show contexutal-message containers.
 */
(function($){
	Drupal.behaviors.contextualMessages = {
		attach:	function(context, settings) {
			checkPageLoadMessages();
			$('body', context).delegate('.contextual-message-target-event-click', 'click', function(e) {
				toggleMessage($(this));
			});
			
			$('body', context).delegate('.contextual-message-target-event-hover', 'mouseover', function(e) {
				toggleMessage($(this));
			});
			
			$('body', context).delegate('a.contextual-message-close', 'click', function(e) {
				$(this).parent('.contextual-message-container').toggleClass('contextual-message-hide');
				return false;
			});

			$('body', context).delegate('a.contextual-message-dismiss', 'click', function(e) {
				$(this).parent('.contextual-message-container').toggleClass('contextual-message-hide');
				$.cookie($(this).parent().prev().attr('id'), 'dismissed');
				return false;
			});
			
			function checkPageLoadMessages() {
				$('.contextual-message-target-event-page-load').each(function(e) {
					if(elementInViewport($(this))) {
						toggleMessage($(this));
					}
				});
			}
			
			function toggleMessage(target) {
				if(!($.cookie(target.attr('id')) == 'dismissed')) {
					var message = target.next('.contextual-message-container');
					if(message.hasClass('contextual-message-hide')) {
					  	message.toggleClass('contextual-message-hide')
					}
				}
			}
			
			function elementInViewport(el) {
			  var pos = el.offset();
			  var top = pos.top;
			  var left = pos.left;
			  var width = el.width();
			  var height = el.height();

			  return (
			    top < (window.pageYOffset + window.innerHeight) &&
			    left < (window.pageXOffset + window.innerWidth) &&
			    (top + height) > window.pageYOffset &&
			    (left + width) > window.pageXOffset
			  );
			}

		}
	};
}(jQuery));
