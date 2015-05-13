<div class="scout-trails-help-page">
  <style type="text/css">
    .scout-trails-help-page ol li { list-style : decimal inside; margin-left: 10px;}
  </style>
  <h1 style="font-size: 16px;">Scout Trails help index</h1>
  <br />

  <div class="row">
    <div class="twelve columns">
      <h2 style="font-size: 14px;">Contents of this document</h2>
      <br />
      <ol>
        <li>Enable Scout Pak to Explore Tutorial Scout Tips & Trails (and Context).</li>
        <li>Create a Scout Tip.</li>
        <li>Add your Scout Tip to a Scout Trail.</li>
        <li>Add your Scout Trail to a page, using Context.</li>
        <li>If you don't see your Scout Trail...</li>
        <li>For more information about Joyride.</li>
      </ol>
      <hr>
    </div>
  </div>

  <br />

  <div class="row">
    <div class="twelve columns">
      <h2 style="font-size: 14px;">1. Enable Scout Pak to Explore Tutorial Scout Tips & Trails (and Context).</h2>
      <p>The Scout Pak feature includes some exported scout trails and context that will give you some idea of how to create Scout Tips & Trails, and how they behave.</p>
      <p>If you have successfully installed scout, scout_trails and scout_pak (and all the dependencies), there should be some trails available in content administration.</p>
      <p><strong>If you have enabled the Scout Pak feature (scout_pak), you should see a modal Scout tip hovering over this page, inviting you to take the FastTrack tour.</strong></p>
      <br />
      <ol>
        <li>Navigate to <a href="http:/admin/content" target="_blank">admin/content</a> and you should see a tab labeled "Scout Trails." </li>
        <li>Click that tab to go to <a href="http:/admin/content/scout-trails" target="_blank">/admin/content/scout-trails</a>.</li>
        <li>There is a trail called "Scout Tips" (don't click).  It includes 7 tips.</li>
        <li>Click on the first tip, <a href="http:/admin/content/scout-trails/scout-tips/1/edit" target="_blank">Scout Tips - Step One</a>.</li>
        <li>There should be a block called "Scout Trail" somewhere in the content region (results vary by admin theme). This is the Scout Trailhead. Click the "Scout" link to start the trail tour.</li>
      </ol>
      <p><stong>Note 1:</strong> Scout Tips should point very closely to the content they are anchored to, but results can vary depending on themes and admin toolbars used.  These tips on admin pages were built for the Seven theme and Drupal's core admin menu + shortcuts.  For use with other themes, you may need to make style adjustments to css.  The default css is included in the Joyride library files.</p>
      <p><stong>Note 2:</strong>These examples of Scout Tips in the scout tip creation forms include tips anchored to selectors inside field-sets.  This is generally not a great idea, because the tip cannot be properly anchored unless the fieldset is opened.  If you need to do this, you might consider adding tips instructing the user to open a fieldset before proceeding to the next tip.  I just don't follow my own advice.</p>

      <hr>
    </div>
  </div>

  <br />

  <div class="row">
    <div class="twelve columns">
      <h2 style="font-size: 14px;">2. Create a Scout Tip.</h2>
      <br />
      <ol>
        <li>Navigate to the <a href="/admin/content/scout-trails/scout-tips" target="_blank">Scout Tips</a> admin page.</li>
        <li>Click the "add scout tip" link and complete the form.</li>
        <li>Add text for the label (title), the body of the tip, and the "Next" button (or leave the default).</li>
        <li>Location Attributes control how your tip is anchored to a page.  You can use a class or data selector, or make the tip modal.</li>
        <li>Options includes only a custom style class, if you want to add one for your own style changes to the tips themselves.</li>
        <li>Save your Scout Tip.</li>
      </ol>
      <p><stong>Note: </strong>Selectors on a given page must be unique or the tip will be anchored to the first occurance found on that page.</p>
      <hr>
    </div>
  </div>

  <br />

  <div class="row">
    <div class="twelve columns">
      <h2 style="font-size: 14px;">3. Add your Scout Tip to a Scout Trail.</h2>
      <br />
      <ol>
        <li>Navigate to the <a href="/admin/content/scout-trails" target="_blank">Scout Trails</a> admin page.</li>
        <li>Click the "add scout trail" link and complete the form.</li>
        <li>Add text for the label (trail name) and a brief description.</li>
        <li>Select the tip you create by typing its name in the autocomplete field.  If you know its id, you can type that in parens. Like, (23).</li>
        <li><strong>New Feature: Now you can also add new Scout Tips without leaving the trail form.</strong></li>
        <li>Save your Scout Trail*.</li>
      </ol>
      <hr>
    </div>
  </div>

  <br />

  <div class="row">
    <div class="twelve columns">
      <h2 style="font-size: 14px;">4. Add your Scout Trail to a page, using Context.</h2>
      <br />
      <ol>
        <li>Navigate to <a href="/admin/structure/context" target="_blank">Context</a> and click "Add."</li>
        <li>Give your context a unique machine name.  It's also helpful to tag them and give them descriptions.</li>
        <li>Add a condition. For the sake of example, it's easiest to use a path condition and add the path to your page.</li>
        <li>Under Reactions, select "Scout Trail".</li>
        <li>Use the pulldown list to find your trail.  It will tell you the name and how many tips are on it.</li>
        <li>If you want the trail to start automatically, check the appropriate box.</li>
        <li>If not, you must also add the trailhead block to a visible region on the page, so it can be started with a click.</li>
        <li>Save your context.</li>
      </ol>
      <hr>
    </div>
  </div>

  <br />

  <div class="row">
    <div class="twelve columns">
      <h2 style="font-size: 14px;">5. If you don't see your Scout Trail...</h2>
      <br />
      <ol>
        <li>... make sure you have <a href="/admin/people/permissions#module-scout_trails" target="_blank">permissions</a> to view trails.</li>
        <li>... try starting it automatically if you did not already use that option.</li>
        <li>... double-check the path you used in your context.</li>
        <li>... make sure your tip was included in the trail you added to your context.</li>
        <li>... make sure your tip is anchored to a unique class or data id on the page. Unanchored tips can appear, but float to the top of the page.</li>
        <li>... try editing the tip and making it modal, so that it does not need to be anchored.</li>
        <li>... review the help info for <a href="/admin/help/scout" target="_blank">Scout</a> and make sure your Joyride library is properly installed.</li>
       </ol>
      <hr>
    </div>
  </div>

  <br />

  <div class="row">
    <div class="twelve columns">
      <h2 id="create-tips-content" style="font-size: 14px;">6. For more information about Joyride.</h2>
      <br />
      <ol>
        <li>If you would like to learn more about the configuration options for the Joyride plugin library, check out the <a href="http://www.zurb.com/playground/jquery-joyride-feature-tour-plugin" target="_blank">Zurb.Com documentation</a> to see a complete list of options and features.</li>
      </ol>
      <hr>
    </div>
  </div>

  <br />

</div>
