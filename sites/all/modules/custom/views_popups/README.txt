OVERVIEW:

This module allows for the easy creation of trigger links that can  ajax load and
popup views displays, or fade-in any container that is already on the page. With 
a few simple steps you can create a view that provides popup links and popup displays
to nodes, users, or any other entity that can be revealed in views.

The information below is in-depth and assumes that you know how to create views in 
Drupal (views 7.x-3.x). The in-depth nature of this readme does not mean that the
usage of this module is complicated. Quite the contrary- I just wanted to provide a 
good documentation with a solid usage instruction for beginning to intermediate users.
If you are advanced, then just read this over and look at the included example view 
to see how the module works with views. 

Installation: Just navigate to admin/modules and enable the module. 

Configuration: Navigate to admin/config/vpop. 
  1) Enter the outer and inner container ids that will be used to calculate positioning 
  of the popup elements relative to the target links. The defaults should work for most cases.
  
  Special config is especially needed if your theme sets positioning on one or
  more wrapper elements to accommodate central page position or other effects. You
  may need to play with these settings to get the positioning to work correctly. If
  all else fails, you can add positioning to the the 'views-popup' class and 
  'views-popup-wrapper' id elements in your own css.
  
  2) Enter any popup left and top nudge you wish. This will add some top and left positioning
  to all popups on the site.

To create links and popup targets you need to know how to use views and/or manipulate 
themes to generate the needed markup. This module does not create any markup on its 
own. It provides a centralized jQuery engine to popup content via ajax or fade in, but
you must provide the target links and views and/or markup yourself.


BACKGROUND INFORMATION:


Link Parameters:
The GET parameters of the trigger link url and the link's class specify what will 
be popped up.  

The trigger link GET parameters that can be used are:

vid:     the machine name (id) of the view to call
did:     the machine name (id) of the display within the view (vid) to call
args:    You can add view args to the query to be passed to contextual filters
         in an ajax type popup. These must follow after 'did' and before any
         further get params.
fade_id: if the view popup display will not be ajax loaded but instead will be 
         already in the DOM and simply faded in, then this is the selector for
         the display to be faded in. Since views (7.x-3.x) does not currently  
         allow you to specify an id for each row in a view, this must be the
         class on the views row. See more below about how to set up a fade-in 
         popup view.
slide_id:   this is similar to fade_id but targets the class of an element to be 
            'slid' into place. This does not imply a jquery effect to 'slide' but
            rather that the mechanism used is not to hide/show, but to move the
            absolutely positioned element in from off of the page (left:-10000px).
            Slide will manifest the targeted element in it's normal place within
            the html document flow.
fadein_id:  similar to slide_id but uses animate to show the targeted element.
            This is different from fade_id in that the targeted element will
            not be a 'popup' but will 'fade in' in it's place within the html
            document flow.       
            
position: this argument tells the script where the place the popup relative to the
          target anchor that triggered it to show. The allowed values are:
          left, top-left, center, right, top-right, none. None will let the element 
          be positioned in its normal flow.
          
top/left: these arguements tell the script to nudge the popup by top or left number
          of pixels. The format should just be an integer with no 'px' at the end.
          e.g. top=10. 

////these last 2 only apply to the ajax type popup
throbber_pos: tells the script where to position the throbber. 
              'targ' = position throbber next to the link that calls the popup
              'none' = do not position the throbber
              
dom: tells the script whether or not you have placed the popup wrapper yourself.
     'static' = you placed the wrapper in the dom yourself, so don't remove it
                with each call.
     'none' = you're letting the script append the dom to put the wrapper in.            
            
The following only applies to slidein and fadein styles:
link_replace: The text that should replace the clicked trigger link text
              when the triggered action is done (either a slidein or a
              fadein). This will represent a close function. 
              For Example, this could be "Hide Element".
              Defaults to 'Close'.

The following only applies to the fadein style:
effect: The effect to use to animate in the targeted element. Defaults to 'linear'.
duration: The duration to use to animate the tarted element. Defaults to 'fast'.
              


Popup Styles:
The popups can be triggered off of the trigger link by either the 'hover' (mouseenter)
or 'click' javascript event, and can take place by either ajax loading the view display
or by fading in a container (probably a views row) that is already on the page. The  
choice of 'popup style' is specified by the class of the trigger link.

The recognized trigger link classes are:

vpop-hover-ajax: ajax load a view display when the mouse moves over the link
vpop-click-ajax: ajax load a view display when the user clicks the link
vpop-hover-fade: fade in an already existing dom element when the mouse moves over the link
vpop-click-fade: fade in an already existing dom element when the user clicks the link
vpop-hover-slidein: move an already existing and displayed dom element when the mouse moves over the link
vpop-click-slidein: move an already existing and displayed dom element when the user clicks the link
vpop-hover-fadein: fade in an already existing and displayed dom element when the mouse moves over the link
vpop-click-fadein: fade an already existing and displayed dom element when the user clicks the link

Example 1: trigger link html (hover ajax): 
<a class="vpop-hover-ajax" href="node/123?vid=my_popup_view&did=my_popup_display&arg1=777">node 777</a>
  This will popup views display my_popup_display in view my_popup_view and pass it argument 777. 
  The name of the arguments (in this case "arg1") can be anything, it is not important.
  
Example 2: trigger link html (click fade):
<a class="vpop-click-fade" href="node/123?fadeid=nid-777">node 777</a>
  This will popup an element with class 'nid-777' that is contained by an element with 
  class 'views-popup-container'. The containing element is there to help prevent multiple
  elements from popping up.
 

BASIC USAGE:

1) Create a view and popups ATTACHMENT display:

   A) Using the views ui (or advanced method) create a view that pulls the desired content from the database.
   Create the view showing nodes (Content) displaying fields. Do not create either a page or a block. 
   [Note the machine name for your new view. This will be the vid in your trigger link in step 2.
   For this example, we'll use MY_VIEW]
   
   B) Create a new ATTACHMENT display by adding it with the views ui.
   [Note the machine name for the attachment display in your new view. You can find this under
   'Machine Name' in the 'Advanced' area of the view ui. For this example we'll use POPUP_DISPLAY]
      
   C) Add fields to your new popup display
   
   Common fields
   are 'title' and 'body'. Any combination of fields can be used.
    
   Since the popup does not automatically hide at any time you should add a close link field to any
   fade-in style popup display. To do this:
   
       i) add a 'Global: Custom Text' field to the display. I usually put it at the top of the field order.
       ii) Rewrite the output as a link with path '#' and 'Link class' = 'views-popup-close'.
    
   
   D) Configure the display for views popups.
   Consider whether you will use ajax or fade-in popup style. In my opinion, the main consideration
   is the number of potential popup rows to be on the page. Ajax can be slow and resource 
   intensive on the server so fade-in is usually the best choice for a limited number
   of potential popup display rows. However, if there will be many rows (>30) or an undetermined
   number of rows (think site users page that pops up photos) then ajax is best.
   
   For a fade-in style:
     Add the class 'views-popup-container' to the view display. This can be done in the 'CSS class' setting
     of the 'OTHER' group in the 'Advanced' settings of the views ui.
     Add the class 'views-popup' to the row format settings for the display. This can be done in the
     'settings' link under 'FORMAT' group in the views ui.
     
   For a slidein style:
     Add the class 'views-popup-container' to the view display. Add the class 'views-slidein' to the row
     format settings.
     
   For a fadein style:
     Add the class 'views-popup-container' to the view display. Add the class 'views-fadein' to the row
     format settings.
     
   For an ajax style:
     Add a contextual filter for 'nid' and select 'hide view' if the filter is not present. This will let
     the trigger link select which node to display in the popup. You do not need the views-popup-container'
     class or the 'views-popup' class for an ajax display, but they will not hurt anything.
     [NOTE: Alternatively, you can set the filter to show all if the filter is missing, and use the same 
      popup display for either fade or ajax style popups. This is how the example view is configured.]
     
   E) Season the popup display to taste by changing other configurations.
     
2) Create a links display:
   
   A) Add a block display to the view. For this example, the links will point to the node page of the popup. 
   This will allow graceful degradation in the unlikely event that the user's browser has javascript disabled.
   
   B) Configure the display for views popup links.
   Override and remove the 'views-popup' and 'views-popup-container' classes from the row format and
   view display settings. Otherwise, you will popup and hide the links display!!
   
   For fade-in style:
    Go back to the POPUP_DISPLAY attachment display you created in 1 and set it to attach after your new 
    links display. You can do this in the 'ATTACHMENT SETTINGS' group of the views ui.
    [NOTE: for the fade-in popup style be sure to leave the sort order as default. The popups on the page will
    need to be sorted in the same order as the links you are creating here.]
   
   For ajax style:
    Leave the POPUP_DISPLAY unattached to your new links display - it will be loaded via ajax.
   
   C) Set the link field for the display. 
   
   The fields you will need are:
   
   For fade-in display:
     'Global: View result counter'
     'Content: Nid'
     'Content: Title'  
     [NOTE: be sure that the fields are listed in this order in the 'FIELDS' set]
      
     Rewrite the output of the 'title' field as a link with the following href:
     node/[nid]?fade_id=views-row-[counter]
     [NOTE: be sure to uncheck the default 'Link this field to the original piece of content'.
      If set, this setting will override the content link rewrite we just did.]
        
     Set the class of the rewritten link to 'vpop-hover-fade' if you want the hover link style 
     vpop-click-fade' if you want the click link style.
        
   For ajax display:
     'Content: Nid'
     'Content: Title'
     [NOTE: be sure that the fields are listed in this order in the 'FIELDS' set]
      
     Rewrite the output of the 'title' field as a link with the following href:
     node/[nid]?vid=MY_VIEW&did=POPUP_DISPLAY&nid=[nid]
     [NOTE: of course MY_VIEW and POPUP_DISPLAY should be substituted with your own view id and 
      display id respectively.]
     [NOTE: be sure to uncheck the default 'Link this field to the original piece of content'.
      If set, this setting will override the link overwrite we just did.]
        
     Set the class of the rewritten link to 'vpop-hover-ajax' if you want the hover link style 
     'vpop-click-ajax' if you want the click link style.
              
3) Now just add the links block view to the page wherever you want it using the block ui or context module.    
       
EXAMPLE VIEW: 
  For an example, look at the vpop view supplied with this module. It contains both a fade and ajax view. Both are
  set to the hover style, and pull basic page nodes sorted by post date. Everything except the configurations
  described above the settings are default.
        
     
