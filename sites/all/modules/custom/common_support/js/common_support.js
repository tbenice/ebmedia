(function ($) {
    Drupal.behaviors.removeEmptyNodes = {
        attach: function(context, settings) {
            // Remove any .row-container nodes that have no content.
            $list = $('div, section, article, aside').not('.always-include').not('.page-admin div').not('.page-admin section').not('.page-admin article').not('.page-admin aside');
            $list.each(function() {
                if (!$.trim($(this).html())) {
                    $(this).remove();
                }
            });
        }
    };
    Drupal.behaviors.itemHideShow = {
        attach:  function(context, settings) {
            $('a.show-link', context)
                .each(function(){
                    var q = ft_getUrlVars($(this));
                    $(this).html(decodeURI(q['moreText']));
                    //hide the link if the show text is not taller
                    //than the css height

                    //briefly append the show-hide contents to check it's height
                    //in case it is display:none (height=0)
                    //var $checkElement = $(this).prev('.item-hide', context).children().first().clone().appendTo('body');
                    var $targ = $(this).parent().prev('.item-hide', context).first();
                    if(!$targ.is(':visible')) {
                        var $checkElement = $targ.clone().appendTo('body').css({'height':'auto'});
                        var actualHeight = $checkElement[0].scrollHeight;
                        setHeight = (q['height'] == undefined) ? $checkElement.height() : q['height'];
                        $checkElement.remove();
                    }
                    else {
                        var actualHeight = $targ[0].scrollHeight;
                        setHeight = (q['height'] == undefined) ? $targ.height() : q['height'];
                    }
                    if(actualHeight <= setHeight) {
                        $targ.css({'height' : 'auto'});
                        $(this).remove();
                    }
                });
            $('body', context).delegate('a.show-link', 'click', function(e){
                var query = ft_getUrlVars($(this));
                if($(this).hasClass('show-processed')) {
                    $(this).parent().prev('.item-shown').toggleClass('item-hide').toggleClass('item-shown');
                    $(this).toggleClass('show-processed');
                    $(this).html(unescape(query['moreText']));
                    $(this).parent().prev('.item-hide', context).first().trigger('showHideHideComplete');
                }
                else {
                    $(this).parent().prev('.item-hide').toggleClass('item-hide').toggleClass('item-shown');
                    $(this).toggleClass('show-processed');
                    $(this).html(unescape(query['lessText']));
                    $(this).parent().prev('.item-shown', context).first().trigger('showHideShowComplete');
                }
                e.preventDefault();
            });
        }
    };

    /**
     * provide extraction of get param from url
     * @return array of ['var']=>value
     */
    function ft_getUrlVars(element){
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
}(jQuery));
