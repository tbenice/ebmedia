(function($) {
  Drupal.behaviors.vpop = {
    attach:  function(context, settings) {
	     //end if popup link element does not exist?
	    if((!$('.vpop-hover-ajax').length)&&(!$('.vpop-click-ajax').length)
	    	&&(!$('.vpop-hover-fade').length)&&(!$('.vpop-click-fade').length)
	    	&&(!$('.vpop-hover-slidein').length)&&(!$('.vpop-click-slidein').length)
	    	&&(!$('.vpop-hover-fadein').length)&&(!$('.vpop-click-fadein').length)) {
	      return;
	    }
	    /**
	     * attach hover ajax events
	     *
	     */
	    $('a.vpop-hover-ajax', context).live({
	    	mouseenter: function(){vpop_ajax($(this))},
	    	 	click: function(e) {
	    	    e.preventDefault();
	    	    return false;
	    	}
	    });
	    $('a.vpop-click-ajax', context).live({
	    	click: function(e) {
	    		vpop_ajax($(this));
	    		e.preventDefault();
	    		return false;
	    	}
	    });
	    $('a.vpop-hover-fade', context).live({
	    	mouseenter: function(){vpop_fade($(this))},
	    	click: function(e) {
	    	    e.preventDefault();
	    	    return false;
	    	}
	    });
	    $('a.vpop-click-fade', context).live({
	     	click: function(e) {
	     		vpop_fade($(this));
	     		e.preventDefault();
	    		return false;
	    	}
	    });
	    $('a.vpop-hover-slidein', context).live({
	    	mouseenter: function(){vpop_slidein($(this))},
	    	click: function(e) {
	    	    e.preventDefault();
	    	    return false;
	    	}
	    });
	    $('body', context).delegate('a.vpop-click-slidein', 'click', function(e){
	    	vpop_slidein($(this));
     		e.preventDefault();
    		return false;
	    });
	    $('a.vpop-hover-fadein', context).live({
	    	mouseenter: function(){vpop_fadein($(this))},
	    	click: function(e) {
	    	    e.preventDefault();
	    	    return false;
	    	}
	    });
	    $('body', context).delegate('a.vpop-click-fadein', 'click', function(e){
	    	vpop_fadein($(this));
     		e.preventDefault();
    		return false;
	    });

	    $('.vpop-click-slidein, .vpop-click-fadein').each(function() {
	    	$(this).data('linkText', $(this).html());
	    });
	    $('.views-slidein', context).once('views-slidein');
	    $('a.views-popup-close', context).live({
	    	click: function(e) {
	    		$('#views-popup-wrapper').hide();
	    		$('.views-popup').hide();
	    		e.preventDefault();
	    		return false;
	    	}
	    });
    }
  };

  function vpop_fadein(targ) {
		try {
			var target = '.' + getUrlVars(targ)['fadein_id'];
		}
		catch(err){
			alert('Vpop GET parameters not formed correctly (fadein_id).');
			return;
		}
		try {
			var effect = getUrlVars(targ)['effect'];
		}
		catch(err){
			alert('Vpop GET parameters not formed correctly (effect).');
			return;
		}
		try {
			var duration = getUrlVars(targ)['duration'];
		}
		catch(err){
			alert('Vpop GET parameters not formed correctly (duration).');
			return;
		}
		try {
			var text = decodeURI(getUrlVars(targ)['link_replace']);
		}
		catch(err){
			alert('Vpop GET parameters not formed correctly (link_replace).');
			return;
		}
		if(effect === undefined) {
			effect = 'linear';
		}
		if(duration === undefined) {
			duration = 'fast';
		}
		if(text === undefined) {
			text = 'Close';
		}
		if($('.views-popup-container ' + target).first().is(':hidden')) {
			$('.views-popup-container ' + target).first().show(duration, effect);
		}
		else {
			$('.views-popup-container ' + target).first().hide(duration, effect);
		}
		if (targ.html() == text) {
			targ.html(targ.data('linkText'));
		}
		else
		{
			targ.html(text);
		}
		$('.views-popup-container').trigger('vpopFadeinComplete');
	}

  function vpop_slidein(targ) {
		try {
			var target = '.' + getUrlVars(targ)['slide_id'];
		}
		catch(err){
			alert('Vpop GET parameters not formed correctly (slide_id).');
			return;
		}
		try {
			var text = decodeURI(getUrlVars(targ)['link_replace']);
		}
		catch(err){
			alert('Vpop GET parameters not formed correctly (link_replace).');
			return;
		}
		if(text === undefined) {
			text = 'Close';
		}
		//hide all views popup containers
		$('.views-popup-container ' + target).first().toggleClass('views-slidein-processed');
		if (targ.html() == text) {
			targ.html(targ.data('linkText'));
		}
		else
		{
			targ.html(text);
		}
		$('.views-popup-container').trigger('vpopSlideinComplete');
	}

  function vpop_fade(targ) {
		try {
			var args = getUrlVars(targ);
			var target = '.' + args['fade_id'];
			var position = 'left';
			if(!(args['position'] == undefined)) {
				position = args['position'];
			}
			var top = 0;
			if (!(args['top'] == undefined)) {
				top = parseInt(args['top']);
			}
			var left = 0;
			if (!(args['left'] == undefined)) {
				left = parseInt(args['left']);
			}
		}
		catch(err){
			alert('Vpop GET parameters not formed correctly.');
			return;
		}

		//hide all views popup containers
		$('.views-popup').hide();
		var $pu = $('.views-popup-container ' + target).first();

		$pu.fadeIn(300, 'linear');
		var liPos = targ.offset();
		var liWidth = targ.outerWidth();
		var liHeight = targ.outerHeight();

		top += liPos.top + parseInt(Drupal.settings.vpop.topNudge);

		left += liPos.left + parseInt(Drupal.settings.vpop.leftNudge);

		if((position == 'right') || (position == 'top-right')) {
		  left += liWidth;
		}
		else if((position == 'center') || (position == 'top-center')){
		  left += (liWidth/2);
		}

		if(!(position == 'none')) {
		  if(position == 'top') {
		   	$pu.offset({'top': top});
		  }
		  else if((position == 'top-right') || (position == 'top-left')) {
		   	$pu.offset({'top': top, 'left': left});
		  }
	  	  else if ((position == 'right') || (position == 'left')) {
		   	$pu.offset({'left': left});
	  	  }
		}
		$pu.trigger('vpopFadeComplete');
	}

  function vpop_ajax(targ) {
	  try {
		  var args = getUrlVars(targ);
		  var getParams = args['query'];
		  var position = 'left';
		  if(!(args['position'] === undefined)) {
			  position = args['position'];
		  }
		  var top = 0;
		  if (!(args['top'] == undefined)) {
			top = parseInt(args['top']);
		  }
		  var left = 0;
		  if (!(args['left'] == undefined)) {
			left = parseInt(args['left']);
		  }
		  var dom = 'none';
		  if (!(args['dom'] == undefined)) {
			  dom = args['dom'];
		  }
		  var throbber_pos = 'targ';
		  if (!(args['throbber_pos'] == undefined)) {
			  throbber_pos = args['throbber_pos'];
		  }
	  }
	  catch(err){
		  alert('Vpop GET parameters not formed correctly.');
		  return;
	  }

	  //get clicked target link position and width
	  var liPos = targ.offset();
      var liWidth = targ.outerWidth();

      if(dom == 'none') {
    	if(!($('#views-popup-wrapper').length == 0)) {
          $('#views-popup-wrapper').remove();
    	}
		$('#' + Drupal.settings.vpop.innerContainer).append('<div id="views-popup-wrapper"></div>');
		$('#views-popup-wrapper').prepend('<div id="views-popup-ajax-throbber-container"><img src="' + Drupal.settings.vpop.throbberPath + '" id="views-popup-ajax-throbber" /></div>');
      }
      else if(dom == 'static') {
		$('#views-popup-wrapper').prepend('<div id="views-popup-ajax-throbber-container"><img src="' + Drupal.settings.vpop.throbberPath + '" id="views-popup-ajax-throbber" /></div>');
		$('.views-popup').hide();
      }

	  //grab a throbber var
	  var $throbber = $('#views-popup-ajax-throbber-container');
	  var $pu = $('#views-popup-wrapper');

	  //if link specifies targ pos (default) for throbber, then pos next to the target
	  if (throbber_pos == 'targ') {
	      $throbber.offset({'top' : liPos.top, 'left' : liPos.left + liWidth});
	  }

	  $.ajax({
	    url: Drupal.settings.basePath + 'views-popup?' + getParams,
	    datatype: 'html',
	    success: function(data) {
		  //remove the throbber
		  $('#views-popup-ajax-throbber-container').remove();
	      //clear any existing popups before rendering the current one
	      var dataIndex = data.length -1;
	      var viewHtml = '<a href="#" class="views-popup-close">Close</a>' + data;
		  //set popup position based on clicked element and body coordinates
		  //insert popup hidden, unhide content
	      $pu.html(viewHtml);
	      $pu.find('.views-popup').show();
	      var liPos = targ.offset();
	      var liWidth = targ.outerWidth();
	      var liHeight = targ.outerHeight();

	      top += liPos.top + parseInt(Drupal.settings.vpop.topNudge);

		  left += liPos.left + parseInt(Drupal.settings.vpop.leftNudge);

		  if((position == 'right') || (position == 'top-right')) {
			left += liWidth;
		  }
		  else if((position == 'center') || (position == 'top-center')){
			left += (liWidth/2);
		  }

		  $pu.fadeIn(300, 'linear');

		  if(!(position == 'none')) {
		    if(position == 'top') {
		    	$pu.offset({'top': top});
		  	}
		  	else if((position == 'top-right') || (position == 'top-left')) {
		    	$pu.offset({'top': top, 'left': left});
		  	}
	  		else if ((position == 'right') || (position == 'left')) {
		    	$pu.offset({'left': left});
	  		}
		  }
		  //attach drupal behaviors to the ajaxed content
		  Drupal.attachBehaviors(jQuery('#views-popup-wrapper'));

		  $('#views-popup-wrapper').imagesLoaded(function() {
			  $('#views-popup-wrapper').trigger('vpopAjaxComplete');
		  });
	    },
	    error: function(data) {
	    	document.location = targ.attr('href');
	    }
	  });
  }

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
})(jQuery);
