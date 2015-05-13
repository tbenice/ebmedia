<?php

/**
 * @file
 * articles support v1 full node layout template.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="articles-support-quote-1 <?php print $classes;?> clearfix">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <span class="quote-start quote">&#8220;</span>
  <?php print $quote_body; ?>
  <span class="quote-end quote">&#8221;</span>

  <?php print $quote_author; ?>

  <?php print $quote_url; ?>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
