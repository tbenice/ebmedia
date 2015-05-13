<?php
/**
 * @file campaign_api_campaign_page.tpl.php
 */

?>

<div id="-campaigns-campaign-page-<?php print render($content['name']); ?>">
  <?php hide($content['name']); ?>
  <?php print render($content); ?>
</div>