<?php
/**
 * @file mc-group-display.tpl.php
 * template for the MailChimp Groups block display
 * 
 * @see template_preprocess_mailchimp_extras
 */
?>
<?php if(user_access('administer mailchimp')){?>
<div id="mc-mailing-list-group-info">
  
    <h2>Current MailChimp Groups</h2>
    
    <div id="mc-groups-list">
        <?php if (isset($content['mc_groups'])) {
          print $content['mc_groups'];
        };?>
    </div>

</div>
<?php } else {};?>