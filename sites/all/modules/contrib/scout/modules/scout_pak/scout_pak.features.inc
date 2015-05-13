<?php
/**
 * @file
 * scout_pak.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scout_pak_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_default_scout_tip().
 */
function scout_pak_default_scout_tip() {
  $items = array();
  $items['1'] = entity_import('scout_tip', '{
    "tip_id" : "1",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step One",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384728018",
    "changed" : "1384728018",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        { "value" : "description", "format" : null, "safe_value" : "description" }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Add a title for the tip.",
          "format" : null,
          "safe_value" : "Add a title for the tip."
        }
      ]
    }
  }');
  $items['2'] = entity_import('scout_tip', '{
    "tip_id" : "2",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step Two",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384742489",
    "changed" : "1384742489",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "field-name-field-scout-tip-text",
          "format" : null,
          "safe_value" : "field-name-field-scout-tip-text"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Then add the main text (that\\u0027s what this is).",
          "format" : null,
          "safe_value" : "Then add the main text (that\\u0026#039;s what this is)."
        }
      ]
    }
  }');
  $items['3'] = entity_import('scout_tip', '{
    "tip_id" : "3",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step Three",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384743115",
    "changed" : "1384743115",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        {
          "value" : "Don\\u0027t go in the basement!",
          "format" : null,
          "safe_value" : "Don\\u0026#039;t go in the basement!"
        }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "field-name-field-scout-tip-button-text",
          "format" : null,
          "safe_value" : "field-name-field-scout-tip-button-text"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Add the text for the \\u0022Next\\u0022 button.  It defaults to \\u0022Next\\u0022, but you can customize it!",
          "format" : null,
          "safe_value" : "Add the text for the \\u0026quot;Next\\u0026quot; button.  It defaults to \\u0026quot;Next\\u0026quot;, but you can customize it!"
        }
      ]
    }
  }');
  $items['4'] = entity_import('scout_tip', '{
    "tip_id" : "4",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step Four",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384743571",
    "changed" : "1384743571",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        { "value" : "Do it Now!", "format" : null, "safe_value" : "Do it Now!" }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "left" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "selected", "format" : null, "safe_value" : "selected" } ] },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Decide how you will anchor the Scout Tip to a page.  You can do it by Data ID (#) or Class (.) selectors.\\u000D\\u000A\\u000D\\u000AOr you can make a tip Modal, anchored to the entire page.\\u000D\\u000A\\u000D\\u000AThis tip is anchored to a class for the tabs at the left.\\u000D\\u000A\\u000D\\u000AOpen the \\u0022Scout Tip Location Attribute\\u0022 to see your options.",
          "format" : null,
          "safe_value" : "Decide how you will anchor the Scout Tip to a page.  You can do it by Data ID (#) or Class (.) selectors.\\u000D\\u000A\\u000D\\u000AOr you can make a tip Modal, anchored to the entire page.\\u000D\\u000A\\u000D\\u000AThis tip is anchored to a class for the tabs at the left.\\u000D\\u000A\\u000D\\u000AOpen the \\u0026quot;Scout Tip Location Attribute\\u0026quot; to see your options."
        }
      ]
    }
  }');
  $items['5'] = entity_import('scout_tip', '{
    "tip_id" : "5",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Learn About Scout Trails",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384757611",
    "changed" : "1396067139",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "No thanks", "format" : null, "safe_value" : "No thanks" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Now you can also create Scout Tips right in Scout Trails!\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000D\\u000A\\u000D\\u000A\\u003Ca href=\\u0022\\u002Fadmin\\u002Fcontent\\u002Fscout-trails\\u002Fadd\\u002Fscout_trail\\u002Ffast-track\\u0022\\u003EShow me a NEW TRAIL\\u003C\\u002Fa\\u003E\\u003Cbr \\u002F\\u003E\\u000D\\u000A\\u003Ca href=\\u0022\\u002Fadmin\\u002Fcontent\\u002Fscout-trails\\u002F6\\u002Fedit\\u002Ffast-track\\u0022\\u003EShow me an EXISTING TRAIL\\u003C\\u002Fa\\u003E",
          "format" : null,
          "safe_value" : "Now you can also create Scout Tips right in Scout Trails!\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000D\\u000A\\u000D\\u000A\\u0026lt;a href=\\u0026quot;\\u002Fadmin\\u002Fcontent\\u002Fscout-trails\\u002Fadd\\u002Fscout_trail\\u002Ffast-track\\u0026quot;\\u0026gt;Show me a NEW TRAIL\\u0026lt;\\u002Fa\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000D\\u000A\\u0026lt;a href=\\u0026quot;\\u002Fadmin\\u002Fcontent\\u002Fscout-trails\\u002F6\\u002Fedit\\u002Ffast-track\\u0026quot;\\u0026gt;Show me an EXISTING TRAIL\\u0026lt;\\u002Fa\\u0026gt;"
        }
      ]
    }
  }');
  $items['7'] = entity_import('scout_tip', '{
    "tip_id" : "7",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step Five",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384879746",
    "changed" : "1384879746",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Coolio", "format" : null, "safe_value" : "Coolio" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "left" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "selected", "format" : null, "safe_value" : "selected" } ] },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Add (optional) custom classes for custom style changes \\u002F additions to the Joyride style used by Scout Tips. ",
          "format" : null,
          "safe_value" : "Add (optional) custom classes for custom style changes \\u002F additions to the Joyride style used by Scout Tips. "
        }
      ]
    }
  }');
  $items['8'] = entity_import('scout_tip', '{
    "tip_id" : "8",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips - Step Six",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384880744",
    "changed" : "1384880744",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "1", "format" : null, "safe_value" : "1" } ] },
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "block-scout-scout-trailhead",
          "format" : null,
          "safe_value" : "block-scout-scout-trailhead"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Scout trails are added to pages using Context.  They can be started automatically, with an option to play only once.  Or this block can be added (also in Context) to appear in an available region (user bar not present in Admin theme) and alert user that an optional tour is available.",
          "format" : null,
          "safe_value" : "Scout trails are added to pages using Context.  They can be started automatically, with an option to play only once.  Or this block can be added (also in Context) to appear in an available region (user bar not present in Admin theme) and alert user that an optional tour is available."
        }
      ]
    }
  }');
  $items['9'] = entity_import('scout_tip', '{
    "tip_id" : "9",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips Admin \\u002F Creation",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384881275",
    "changed" : "1384881275",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "action-links",
          "format" : null,
          "safe_value" : "action-links"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "This page shows the collection of created Scout Tips, regardless of whether or not they are being used in any Scout Trails.  New Scout Tips are created by clicking this link.",
          "format" : null,
          "safe_value" : "This page shows the collection of created Scout Tips, regardless of whether or not they are being used in any Scout Trails.  New Scout Tips are created by clicking this link."
        }
      ]
    }
  }');
  $items['10'] = entity_import('scout_tip', '{
    "tip_id" : "10",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Tips Editing",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384882178",
    "changed" : "1384882178",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Got it!", "format" : null, "safe_value" : "Got it!" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "left" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "even", "format" : null, "safe_value" : "even" } ] },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Clicking any scout tip link takes you to its edit form.",
          "format" : null,
          "safe_value" : "Clicking any scout tip link takes you to its edit form."
        }
      ]
    }
  }');
  $items['11'] = entity_import('scout_tip', '{
    "tip_id" : "11",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Admin \\u002F Creation",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384882469",
    "changed" : "1384882469",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "action-links",
          "format" : null,
          "safe_value" : "action-links"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "This page shows the collection of created Scout Trails and any Scout Tips they\\u0027re composed of.  New Scout Trails are created by clicking this link.",
          "format" : null,
          "safe_value" : "This page shows the collection of created Scout Trails and any Scout Tips they\\u0026#039;re composed of.  New Scout Trails are created by clicking this link."
        }
      ]
    }
  }');
  $items['12'] = entity_import('scout_tip', '{
    "tip_id" : "12",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Editing",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384883065",
    "changed" : "1384883065",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Thanks", "format" : null, "safe_value" : "Thanks" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "left" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "even", "format" : null, "safe_value" : "even" } ] },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Clicking any scout trail link (or any trail tip link) takes you to its edit form.",
          "format" : null,
          "safe_value" : "Clicking any scout trail link (or any trail tip link) takes you to its edit form."
        }
      ]
    }
  }');
  $items['13'] = entity_import('scout_tip', '{
    "tip_id" : "13",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails - Trail Name",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384883321",
    "changed" : "1396047833",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "form-item-title\\u0022",
          "format" : null,
          "safe_value" : "form-item-title\\u0026quot;"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Enter a name for your Scout Trail.",
          "format" : null,
          "safe_value" : "Enter a name for your Scout Trail."
        }
      ]
    }
  }');
  $items['14'] = entity_import('scout_tip', '{
    "tip_id" : "14",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails - Description",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384883428",
    "changed" : "1396049745",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Yada-yada", "format" : null, "safe_value" : "Yada-yada" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "form-item-description",
          "format" : null,
          "safe_value" : "form-item-description"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "A description is only for admin purposes, but it\\u0027s also helpful if you have a lot of trail names that look similar.",
          "format" : null,
          "safe_value" : "A description is only for admin purposes, but it\\u0026#039;s also helpful if you have a lot of trail names that look similar."
        }
      ]
    }
  }');
  $items['15'] = entity_import('scout_tip', '{
    "tip_id" : "15",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails - Add Scout Tip",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384883859",
    "changed" : "1396049761",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        {
          "value" : "See how to add new ones",
          "format" : null,
          "safe_value" : "See how to add new ones"
        }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-field-scout-trail-tips-und-actions-ief-add-existing",
          "format" : null,
          "safe_value" : "edit-field-scout-trail-tips-und-actions-ief-add-existing"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Add existing scout tips to your trail with auto complete.",
          "format" : null,
          "safe_value" : "Add existing scout tips to your trail with auto complete."
        }
      ]
    }
  }');
  $items['16'] = entity_import('scout_tip', '{
    "tip_id" : "16",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384884812",
    "changed" : "1396050618",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "No thanks", "format" : null, "safe_value" : "No thanks" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Your trails won\\u0027t appear anywhere until you add them to Context.\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000A\\u003Ca href=\\u0022\\u002Fadmin\\u002Fstructure\\u002Fcontext\\u002Flist\\u002Fscout_trail_context\\u002Fedit\\u0022\\u003ESee how this is done\\u003C\\u002Fa\\u003E.",
          "format" : null,
          "safe_value" : "Your trails won\\u0026#039;t appear anywhere until you add them to Context.\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000A\\u0026lt;a href=\\u0026quot;\\u002Fadmin\\u002Fstructure\\u002Fcontext\\u002Flist\\u002Fscout_trail_context\\u002Fedit\\u0026quot;\\u0026gt;See how this is done\\u0026lt;\\u002Fa\\u0026gt;."
        }
      ]
    }
  }');
  $items['17'] = entity_import('scout_tip', '{
    "tip_id" : "17",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - Add Condition",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384885609",
    "changed" : "1384885609",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-conditions-plugins-path-values",
          "format" : null,
          "safe_value" : "edit-conditions-plugins-path-values"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Add the condition for the Scout Trail to appear.  In this case we\\u0027re using the path to the page we\\u0027re looking at now.",
          "format" : null,
          "safe_value" : "Add the condition for the Scout Trail to appear.  In this case we\\u0026#039;re using the path to the page we\\u0026#039;re looking at now."
        }
      ]
    }
  }');
  $items['18'] = entity_import('scout_tip', '{
    "tip_id" : "18",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - Add Trailhead Block",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384886288",
    "changed" : "1396081056",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "right" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "scout-scout_trailhead",
          "format" : null,
          "safe_value" : "scout-scout_trailhead"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "If you don\\u0027t want the Scout Tour to begin automatically, then add the Trailhead block to an appropriate region.\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000ASince this is an admin page, the block is in the content region.\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000AFor pages seen by your site visitors, you could style the block to appear in an out of the way place, such as a user bar, etc.",
          "format" : null,
          "safe_value" : "If you don\\u0026#039;t want the Scout Tour to begin automatically, then add the Trailhead block to an appropriate region.\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000ASince this is an admin page, the block is in the content region.\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000AFor pages seen by your site visitors, you could style the block to appear in an out of the way place, such as a user bar, etc."
        }
      ]
    }
  }');
  $items['19'] = entity_import('scout_tip', '{
    "tip_id" : "19",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - Select Scout Trail",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384886648",
    "changed" : "1384886648",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        { "value" : "Eazy peazy", "format" : null, "safe_value" : "Eazy peazy" }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "right" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-reactions-plugins-scout-trail-trail-content",
          "format" : null,
          "safe_value" : "edit-reactions-plugins-scout-trail-trail-content"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Select one of the available Scout Trails from the list.  The list will show the names of available trails and how many tips are on them.",
          "format" : null,
          "safe_value" : "Select one of the available Scout Trails from the list.  The list will show the names of available trails and how many tips are on them."
        }
      ]
    }
  }');
  $items['20'] = entity_import('scout_tip', '{
    "tip_id" : "20",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trail Review",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384887705",
    "changed" : "1396085620",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        {
          "value" : "Just Letting You Know",
          "format" : null,
          "safe_value" : "Just Letting You Know"
        }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Keep in mind that if you use Scout Trails on admin forms with fields hidden in fieldsets, you will have to do as we have done and add action tips for the user to open them before you can show them what\\u0027s inside. Otherwise, Scout Tips that are attached to selectors not available on page load will not know where to go, and will appear in the upper left corner of the screen. \\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000D\\u000ATo highlight required actions, you can wrap them in a simple span tag, with a class of \\u0022action\\u0022 and it will be colored green.\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000D\\u000AAn alternative is to make those tips modal (like this tip), but then they are not a precise as those tips that point to the area they are addressing.",
          "format" : null,
          "safe_value" : "Keep in mind that if you use Scout Trails on admin forms with fields hidden in fieldsets, you will have to do as we have done and add action tips for the user to open them before you can show them what\\u0026#039;s inside. Otherwise, Scout Tips that are attached to selectors not available on page load will not know where to go, and will appear in the upper left corner of the screen. \\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000D\\u000ATo highlight required actions, you can wrap them in a simple span tag, with a class of \\u0026quot;action\\u0026quot; and it will be colored green.\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000D\\u000AAn alternative is to make those tips modal (like this tip), but then they are not a precise as those tips that point to the area they are addressing."
        }
      ]
    }
  }');
  $items['21'] = entity_import('scout_tip', '{
    "tip_id" : "21",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails - Create New Tips Inline",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396034423",
    "changed" : "1396035996",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Awesome!", "format" : null, "safe_value" : "Awesome!" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-field-scout-trail-tips-und-actions-ief-add",
          "format" : null,
          "safe_value" : "edit-field-scout-trail-tips-und-actions-ief-add"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Use this to create new Scout Tips without leaving this form.",
          "format" : null,
          "safe_value" : "Use this to create new Scout Tips without leaving this form."
        }
      ]
    }
  }');
  $items['22'] = entity_import('scout_tip', '{
    "tip_id" : "22",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails - Saving Your Trail",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396034834",
    "changed" : "1396035928",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "fade" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Duh", "format" : null, "safe_value" : "Duh" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-trail--2",
          "format" : null,
          "safe_value" : "edit-trail--2"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Don\\u0027t forget to save your trail, especially if you added new tips here, because they won\\u0027t be saved until you save it all.",
          "format" : null,
          "safe_value" : "Don\\u0026#039;t forget to save your trail, especially if you added new tips here, because they won\\u0026#039;t be saved until you save it all."
        }
      ]
    }
  }');
  $items['23'] = entity_import('scout_tip', '{
    "tip_id" : "23",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails - Ordering Tips",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396035268",
    "changed" : "1396036893",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "fade" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Got it", "format" : null, "safe_value" : "Got it" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "tabledrag-toggle-weight-wrapper",
          "format" : null,
          "safe_value" : "tabledrag-toggle-weight-wrapper"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "This is the weight toggle.  If this says, \\u0022Show row weights,\\u0022 that means you can reorder the tips simply by dragging them.\\u000AIf this says, \\u0022Hide row weights,\\u0022 that means you\\u0027ll have to adjust the weights to change the order (lightest float to the top).\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000A(Yeah, and sometimes it\\u0027s just impossible to position a tip exactly where you want it ;)",
          "format" : null,
          "safe_value" : "This is the weight toggle.  If this says, \\u0026quot;Show row weights,\\u0026quot; that means you can reorder the tips simply by dragging them.\\u000AIf this says, \\u0026quot;Hide row weights,\\u0026quot; that means you\\u0026#039;ll have to adjust the weights to change the order (lightest float to the top).\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000A(Yeah, and sometimes it\\u0026#039;s just impossible to position a tip exactly where you want it ;)"
        }
      ]
    }
  }');
  $items['24'] = entity_import('scout_tip', '{
    "tip_id" : "24",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails - Create Scout Tip",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396049767",
    "changed" : "1396049863",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Far Out!", "format" : null, "safe_value" : "Far Out!" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-field-scout-trail-tips-und-actions-ief-add",
          "format" : null,
          "safe_value" : "edit-field-scout-trail-tips-und-actions-ief-add"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Now you can add new Scout Tips without leaving the trail form.",
          "format" : null,
          "safe_value" : "Now you can add new Scout Tips without leaving the trail form."
        }
      ]
    }
  }');
  $items['26'] = entity_import('scout_tip', '{
    "tip_id" : "26",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "SAVE YOUR TRAIL",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396050198",
    "changed" : "1396050496",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Duh", "format" : null, "safe_value" : "Duh" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-trail--2",
          "format" : null,
          "safe_value" : "edit-trail--2"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Don\\u0027t forget to save your trail.  New tips you created in this trail are also not saved until you save the entire form.",
          "format" : null,
          "safe_value" : "Don\\u0026#039;t forget to save your trail.  New tips you created in this trail are also not saved until you save the entire form."
        }
      ]
    }
  }');
  $items['27'] = entity_import('scout_tip', '{
    "tip_id" : "27",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Welcome to Scout Trails Context",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396054022",
    "changed" : "1396055609",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "We\\u0027re going to show you some tips.  This tutorial needs some help from you, to open some areas of the page we want to tell you about.\\u003Cbr \\u002F\\u003E\\u000D\\u000ARead the tips carefully for actions to take BEFORE you press Next.",
          "format" : null,
          "safe_value" : "We\\u0026#039;re going to show you some tips.  This tutorial needs some help from you, to open some areas of the page we want to tell you about.\\u0026lt;br \\u002F\\u0026gt;\\u000D\\u000ARead the tips carefully for actions to take BEFORE you press Next."
        }
      ]
    }
  }');
  $items['28'] = entity_import('scout_tip', '{
    "tip_id" : "28",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - Condition",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396054254",
    "changed" : "1396080939",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "context-plugin-title",
          "format" : null,
          "safe_value" : "context-plugin-title"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "For the next tip to appear in the right place,  \\u003Cspan class =\\u0022action\\u0022\\u003Eplease click where it says, \\u0022Path,\\u0022\\u003C\\u002Fspan\\u003E BEFORE you click the Next button.",
          "format" : null,
          "safe_value" : "For the next tip to appear in the right place,  \\u0026lt;span class =\\u0026quot;action\\u0026quot;\\u0026gt;please click where it says, \\u0026quot;Path,\\u0026quot;\\u0026lt;\\u002Fspan\\u0026gt; BEFORE you click the Next button."
        }
      ]
    }
  }');
  $items['29'] = entity_import('scout_tip', '{
    "tip_id" : "29",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - Reaction",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396054861",
    "changed" : "1396055134",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-reactions-selector",
          "format" : null,
          "safe_value" : "edit-reactions-selector"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Now we need you to open the Blocks condition, before pressing Next.",
          "format" : null,
          "safe_value" : "Now we need you to open the Blocks condition, before pressing Next."
        }
      ]
    }
  }');
  $items['30'] = entity_import('scout_tip', '{
    "tip_id" : "30",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - Reaction II",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396055703",
    "changed" : "1396083757",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "context-plugin-scout_trail",
          "format" : null,
          "safe_value" : "context-plugin-scout_trail"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Now \\u003Cspan class=\\u0022action\\u0022\\u003Eopen (click on) the Scout Trail\\u003C\\u002Fspan\\u003E context reaction.",
          "format" : null,
          "safe_value" : "Now \\u0026lt;span class=\\u0026quot;action\\u0026quot;\\u0026gt;open (click on) the Scout Trail\\u0026lt;\\u002Fspan\\u0026gt; context reaction."
        }
      ]
    }
  }');
  $items['31'] = entity_import('scout_tip', '{
    "tip_id" : "31",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Thanks for Installing Scout!",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396057915",
    "changed" : "1396061674",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        {
          "value" : "Thanks, but later",
          "format" : null,
          "safe_value" : "Thanks, but later"
        }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Don\\u0027t worry, this won\\u0027t keep appearring, but since you\\u0027ve just enabled Scout we thought you might want to see how it works.\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000D\\u000AYou can learn more \\u003Ca href = \\u0022\\u002Fadmin\\u002Fhelp\\u002Fscout\\u0022\\u003ENOW\\u003C\\u002Fa\\u003E or checkout your help pages later (admin\\u002Fhelp) and look for Scout.",
          "format" : null,
          "safe_value" : "Don\\u0026#039;t worry, this won\\u0026#039;t keep appearring, but since you\\u0026#039;ve just enabled Scout we thought you might want to see how it works.\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000D\\u000AYou can learn more \\u0026lt;a href = \\u0026quot;\\u002Fadmin\\u002Fhelp\\u002Fscout\\u0026quot;\\u0026gt;NOW\\u0026lt;\\u002Fa\\u0026gt; or checkout your help pages later (admin\\u002Fhelp) and look for Scout."
        }
      ]
    }
  }');
  $items['32'] = entity_import('scout_tip', '{
    "tip_id" : "32",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Learn More",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396058522",
    "changed" : "1396091523",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        {
          "value" : "Have a nice day",
          "format" : null,
          "safe_value" : "Have a nice day"
        }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "scout", "format" : null, "safe_value" : "scout" } ] },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "The page linked below has some useful tutorial information it.  Just thought you\\u0027d like to know.",
          "format" : null,
          "safe_value" : "The page linked below has some useful tutorial information it.  Just thought you\\u0026#039;d like to know."
        }
      ]
    }
  }');
  $items['33'] = entity_import('scout_tip', '{
    "tip_id" : "33",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "GET STARTED",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396062202",
    "changed" : "1396091571",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        {
          "value" : "Thanks, but later",
          "format" : null,
          "safe_value" : "Thanks, but later"
        }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Read this page and\\u002For \\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000A\\u003Ca href =\\u0022\\u002Fadmin\\u002Fcontent\\u002Fscout-trails\\u002Fscout-tips\\u002F1\\u002Fedit\\u002Ffast-track\\u0022\\u003EFAST TRACK HERE!\\u003C\\u002Fa\\u003E",
          "format" : null,
          "safe_value" : "Read this page and\\u002For \\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000A\\u0026lt;a href =\\u0026quot;\\u002Fadmin\\u002Fcontent\\u002Fscout-trails\\u002Fscout-tips\\u002F1\\u002Fedit\\u002Ffast-track\\u0026quot;\\u0026gt;FAST TRACK HERE!\\u0026lt;\\u002Fa\\u0026gt;"
        }
      ]
    }
  }');
  $items['34'] = entity_import('scout_tip', '{
    "tip_id" : "34",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "IMPORTANT",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396076524",
    "changed" : "1396080904",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        { "value" : "Understood", "format" : null, "safe_value" : "Understood" }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "This trail contains tips with \\u003Cspan class =\\u0022action\\u0022\\u003Eactions\\u003C\\u002Fspan\\u003E that are necessary to perform before clicking the Next button, otherwise the tips will be unable to point you in the right direction.",
          "format" : null,
          "safe_value" : "This trail contains tips with \\u0026lt;span class =\\u0026quot;action\\u0026quot;\\u0026gt;actions\\u0026lt;\\u002Fspan\\u0026gt; that are necessary to perform before clicking the Next button, otherwise the tips will be unable to point you in the right direction."
        }
      ]
    }
  }');
  $items['35'] = entity_import('scout_tip', '{
    "tip_id" : "35",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context Conditions",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396076855",
    "changed" : "1396077043",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "context-plugin-info",
          "format" : null,
          "safe_value" : "context-plugin-info"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "We\\u0027re going to look at a Context Condition.  Please click on \\u0022Path\\u0022 below, before hitting the next button.",
          "format" : null,
          "safe_value" : "We\\u0026#039;re going to look at a Context Condition.  Please click on \\u0026quot;Path\\u0026quot; below, before hitting the next button."
        }
      ]
    }
  }');
  $items['36'] = entity_import('scout_tip', '{
    "tip_id" : "36",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context Reactions",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396077207",
    "changed" : "1396083854",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "top" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : { "und" : [
        {
          "value" : "edit-reactions-selector",
          "format" : null,
          "safe_value" : "edit-reactions-selector"
        }
      ]
    },
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Data ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Next we\\u0027ll look at the Context Reactions that will activate Scout Trails.  Please \\u003Cspan class=\\u0022action\\u0022\\u003Eclick on \\u0022Blocks\\u0022\\u003C\\u002Fspan\\u003Ebefore hitting Next button.",
          "format" : null,
          "safe_value" : "Next we\\u0026#039;ll look at the Context Reactions that will activate Scout Trails.  Please \\u0026lt;span class=\\u0026quot;action\\u0026quot;\\u0026gt;click on \\u0026quot;Blocks\\u0026quot;\\u0026lt;\\u002Fspan\\u0026gt;before hitting Next button."
        }
      ]
    }
  }');
  $items['37'] = entity_import('scout_tip', '{
    "tip_id" : "37",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - Scout Trail",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396077932",
    "changed" : "1396078376",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "context-plugin-scout_trail",
          "format" : null,
          "safe_value" : "context-plugin-scout_trail"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Scout Trail is available as a Context reaction.  Please click on \\u0022Scout Trail\\u0022 below, before proceeding with the Next button.",
          "format" : null,
          "safe_value" : "Scout Trail is available as a Context reaction.  Please click on \\u0026quot;Scout Trail\\u0026quot; below, before proceeding with the Next button."
        }
      ]
    }
  }');
  $items['38'] = entity_import('scout_tip', '{
    "tip_id" : "38",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - Auto Start",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396084314",
    "changed" : "1396084951",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        {
          "value" : "Okay, thanks",
          "format" : null,
          "safe_value" : "Okay, thanks"
        }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "right" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "form-item-reactions-plugins-scout-trail-trail-auto-start",
          "format" : null,
          "safe_value" : "form-item-reactions-plugins-scout-trail-trail-auto-start"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Here is how you make a Scout Trail start automatically on a page.  You typically wouldn\\u0027t do this along with a Trailhead block.\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000AYou probably will want to use this sparingly, especially on pages with frequent visitors who already know how to use them. There are other tricks for showing them only sometimes on those pages.",
          "format" : null,
          "safe_value" : "Here is how you make a Scout Trail start automatically on a page.  You typically wouldn\\u0026#039;t do this along with a Trailhead block.\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000AYou probably will want to use this sparingly, especially on pages with frequent visitors who already know how to use them. There are other tricks for showing them only sometimes on those pages."
        }
      ]
    }
  }');
  $items['39'] = entity_import('scout_tip', '{
    "tip_id" : "39",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails Context - \\u0022Play Once\\u0022",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396084681",
    "changed" : "1396084930",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Next", "format" : null, "safe_value" : "Next" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : { "und" : [
        {
          "value" : "form-item-reactions-plugins-scout-trail-trail-play-once",
          "format" : null,
          "safe_value" : "form-item-reactions-plugins-scout-trail-trail-play-once"
        }
      ]
    },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "\\u0022Play trail only once\\u0022 is cookie-based, but it\\u0027s hard to test, so you may find little use for it.",
          "format" : null,
          "safe_value" : "\\u0026quot;Play trail only once\\u0026quot; is cookie-based, but it\\u0026#039;s hard to test, so you may find little use for it."
        }
      ]
    }
  }');
  $items['40'] = entity_import('scout_tip', '{
    "tip_id" : "40",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Context Tricks",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396085782",
    "changed" : "1396088258",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        { "value" : "Maybe later", "format" : null, "safe_value" : "Maybe later" }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "You wanna see a neat trick you can do with context?  This is how you can make common pages have autostart Scout Trails, but only under a certain condition.\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000D\\u000AIf you want to see it, \\u003Ca href=\\u0022\\u002Fadmin\\u002Fcontent\\u002Fcontext-trick\\u0022\\u003EClick This Trick\\u003C\\u002Fa\\u003E.",
          "format" : null,
          "safe_value" : "You wanna see a neat trick you can do with context?  This is how you can make common pages have autostart Scout Trails, but only under a certain condition.\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000D\\u000AIf you want to see it, \\u0026lt;a href=\\u0026quot;\\u002Fadmin\\u002Fcontent\\u002Fcontext-trick\\u0026quot;\\u0026gt;Click This Trick\\u0026lt;\\u002Fa\\u0026gt;."
        }
      ]
    }
  }');
  $items['41'] = entity_import('scout_tip', '{
    "tip_id" : "41",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Context Only URLs",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396086166",
    "changed" : "1396087471",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [
        {
          "value" : "Let Me Noodle on That",
          "format" : null,
          "safe_value" : "Let Me Noodle on That"
        }
      ]
    },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "Note the address above.  It\\u0027s \\u002Fadmin\\u002Fcontent\\u002Fcontext-trick, but there\\u0027s really no such page.  There\\u0027s only a Scout Trail context reaction for it, in autostart mode.\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000AThat\\u0027s enough to get a reaction out of Context and Scout, but since the page doesn\\u0027t actually exist, the fallback is to the left of the fake address (admin\\u002Fcontent), which is real.\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000AIf a user goes to that URL as usual, there won\\u0027t be any Scout Trails in their way.  Typically, the only way to get to the fake URL is the way we just did, via a direct link.",
          "format" : null,
          "safe_value" : "Note the address above.  It\\u0026#039;s \\u002Fadmin\\u002Fcontent\\u002Fcontext-trick, but there\\u0026#039;s really no such page.  There\\u0026#039;s only a Scout Trail context reaction for it, in autostart mode.\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000AThat\\u0026#039;s enough to get a reaction out of Context and Scout, but since the page doesn\\u0026#039;t actually exist, the fallback is to the left of the fake address (admin\\u002Fcontent), which is real.\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000AIf a user goes to that URL as usual, there won\\u0026#039;t be any Scout Trails in their way.  Typically, the only way to get to the fake URL is the way we just did, via a direct link."
        }
      ]
    }
  }');
  $items['42'] = entity_import('scout_tip', '{
    "tip_id" : "42",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Scout Trails in Content",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396086935",
    "changed" : "1396087237",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Got it", "format" : null, "safe_value" : "Got it" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "left" } ] },
    "field_scout_tip_selector_class" : { "und" : [ { "value" : "tabs", "format" : null, "safe_value" : "tabs" } ] },
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Class ID" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "While we\\u0027re here, we just wanted to show you that when Scout is enabled you can find your Scout Trails in the content administration tabs.",
          "format" : null,
          "safe_value" : "While we\\u0026#039;re here, we just wanted to show you that when Scout is enabled you can find your Scout Trails in the content administration tabs."
        }
      ]
    }
  }');
  $items['43'] = entity_import('scout_tip', '{
    "tip_id" : "43",
    "type" : "scout_tip",
    "language" : "und",
    "title" : "Go For It",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396087243",
    "changed" : "1396088530",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_tip_animation" : { "und" : [ { "value" : "pop" } ] },
    "field_scout_tip_button_text" : { "und" : [ { "value" : "Bubbye!", "format" : null, "safe_value" : "Bubbye!" } ] },
    "field_scout_tip_class" : { "und" : [
        {
          "value" : "custom-scout-tip",
          "format" : null,
          "safe_value" : "custom-scout-tip"
        }
      ]
    },
    "field_scout_tip_orientation" : { "und" : [ { "value" : "bottom" } ] },
    "field_scout_tip_selector_class" : [  ],
    "field_scout_tip_selector_id" : [  ],
    "field_scout_tip_selector_type" : { "und" : [ { "value" : "Modal" } ] },
    "field_scout_tip_text" : { "und" : [
        {
          "value" : "That wraps up our FastTrack tour of Scout and Scout Trails.  We\\u0027ll leave you now to dive in and start exploring and making your own Scout Trails.\\u003Cbr \\u002F\\u003E\\u003Cbr \\u002F\\u003E\\u000D\\u000AWhen you no longer need these tutorial Scout Trails, you can turn them off by disabling and uninstalling the Scout Pak feature.\\u000D\\u000AIf you\\u0027d like to take this tour again, \\u003Ca href=\\u0022\\u002Fadmin\\u002Fhelp\\u002Fscout\\u0022\\u003Ego back to the Scout help pages\\u003C\\u002Fa\\u003E.",
          "format" : null,
          "safe_value" : "That wraps up our FastTrack tour of Scout and Scout Trails.  We\\u0026#039;ll leave you now to dive in and start exploring and making your own Scout Trails.\\u0026lt;br \\u002F\\u0026gt;\\u0026lt;br \\u002F\\u0026gt;\\u000D\\u000AWhen you no longer need these tutorial Scout Trails, you can turn them off by disabling and uninstalling the Scout Pak feature.\\u000D\\u000AIf you\\u0026#039;d like to take this tour again, \\u0026lt;a href=\\u0026quot;\\u002Fadmin\\u002Fhelp\\u002Fscout\\u0026quot;\\u0026gt;go back to the Scout help pages\\u0026lt;\\u002Fa\\u0026gt;."
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_default_scout_trail().
 */
function scout_pak_default_scout_trail() {
  $items = array();
  $items['1'] = entity_import('scout_trail', '{
    "trail_id" : "1",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Tips",
    "description" : "Shows how to create Scout Tips",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384728030",
    "changed" : "1395967014",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_trail_tips" : { "und" : [
        { "target_id" : "1" },
        { "target_id" : "2" },
        { "target_id" : "3" },
        { "target_id" : "4" },
        { "target_id" : "7" },
        { "target_id" : "8" },
        { "target_id" : "5" }
      ]
    }
  }');
  $items['4'] = entity_import('scout_trail', '{
    "trail_id" : "4",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Tip Admin - Creation",
    "description" : "Shows where to find Scout Tips",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384881575",
    "changed" : "1384881575",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_trail_tips" : { "und" : [ { "target_id" : "9" }, { "target_id" : "10" } ] }
  }');
  $items['5'] = entity_import('scout_trail', '{
    "trail_id" : "5",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Trails Admin - Creation",
    "description" : "Shows where to find Scout Trails \\u0026 Tips",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384882702",
    "changed" : "1384882702",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_trail_tips" : { "und" : [ { "target_id" : "11" }, { "target_id" : "12" } ] }
  }');
  $items['6'] = entity_import('scout_trail', '{
    "trail_id" : "6",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Trails",
    "description" : "Shows how to create Scout Trails",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384883144",
    "changed" : "1396050854",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_trail_tips" : { "und" : [
        { "target_id" : "13" },
        { "target_id" : "14" },
        { "target_id" : "15" },
        { "target_id" : "24" },
        { "target_id" : "23" },
        { "target_id" : "26" },
        { "target_id" : "16" }
      ]
    }
  }');
  $items['7'] = entity_import('scout_trail', '{
    "trail_id" : "7",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Trails Context",
    "description" : "How to make Scout Trails appear",
    "uid" : "5",
    "tag" : "FastTrack",
    "created" : "1384885694",
    "changed" : "1396086022",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_trail_tips" : { "und" : [
        { "target_id" : "34" },
        { "target_id" : "28" },
        { "target_id" : "17" },
        { "target_id" : "36" },
        { "target_id" : "18" },
        { "target_id" : "30" },
        { "target_id" : "19" },
        { "target_id" : "38" },
        { "target_id" : "39" },
        { "target_id" : "20" },
        { "target_id" : "40" }
      ]
    }
  }');
  $items['8'] = entity_import('scout_trail', '{
    "trail_id" : "8",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Thanks for Installing Scout!",
    "description" : "First time Scout Trail",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396057826",
    "changed" : "1396058018",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_trail_tips" : { "und" : [ { "target_id" : "31" } ] }
  }');
  $items['12'] = entity_import('scout_trail', '{
    "trail_id" : "12",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Content and Context Trick",
    "description" : "Shows Scout Admin and a Context Trick",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396092321",
    "changed" : "1396097452",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_trail_tips" : { "und" : [ { "target_id" : "41" }, { "target_id" : "42" }, { "target_id" : "43" } ] }
  }');
  $items['13'] = entity_import('scout_trail', '{
    "trail_id" : "13",
    "type" : "scout_trail",
    "language" : "und",
    "title" : "Scout Trails FastTrack Help Page",
    "description" : "Invites User to FastTrack Tutorial",
    "uid" : "1",
    "tag" : "FastTrack",
    "created" : "1396092400",
    "changed" : "1396097066",
    "tnid" : "0",
    "translate" : "0",
    "status" : "2",
    "module" : "scout_pak",
    "field_scout_trail_tips" : { "und" : [ { "target_id" : "33" } ] }
  }');
  return $items;
}
