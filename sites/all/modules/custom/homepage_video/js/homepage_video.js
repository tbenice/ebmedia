/**
 * Loads the franti video as maximage.
 */
(function ($) {
	Drupal.behaviors.HomePageVideo = {
	  attach: function (context, settings) {
	    $("video").each(function () {
	        if ($(this).is(":hidden")) {
	            $("#mobile-splash").maximage({
	                cssBackgroundSize: false,
	                backgroundSize: "cover"
	            });
	            $(this)[0].pause();
	        } else {
	            $(this).maximage("maxcover");
	        }
	    });
	    $("#overlay").bind("click", function () {
	        $("video")[0].play();
	        return false;
	    });
	  }
	};
})(jQuery);
