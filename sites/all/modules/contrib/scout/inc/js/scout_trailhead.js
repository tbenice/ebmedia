(function ($) {
  Drupal.behaviors.scoutManualTrigger = {
    attach:function (context, settings) {
      $('a.scout_trailhead').live('click', function(event) {
        event.preventDefault();

        var trail_content = Drupal.settings.scoutContext.trail_content || 'undefined';
        if (trail_content == 'undefined') return false;

        if($('ol#scout-trail-content').length > 0) $('ol#scout-trail-content').remove();

        $('body', context).append(trail_content);

        $('ol#scout-trail-content').joyride();

        return false;
      });
    }
  };
}(jQuery));