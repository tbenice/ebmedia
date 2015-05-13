(function ($) {
  Drupal.behaviors.scoutContext = {
    attach:function (context, settings) {
      if(!Drupal.settings.scoutContext) return false;

      var auto_start = Drupal.settings.scoutContext.auto_start || 'undefined';
      if(auto_start == 'undefined' || auto_start == false) return false;

      var trail_content = Drupal.settings.scoutContext.trail_content || 'undefined';
      if(trail_content == 'undefined') return false;

      if ($('ol#scout-trail-content').length > 0) $('ol#scout-trail-content').remove();

      $('body', context).append(trail_content);

      var scout_options = {};

      var play_once = Drupal.settings.scoutContext.play_once || 'undefined';
      if(play_once == 'undefined' || play_once == false) {
        scout_options.cookieMonster = false;
      } else scout_options.cookieMonster = true;

      $('ol#scout-trail-content').joyride(scout_options);
    }
  };
}(jQuery));