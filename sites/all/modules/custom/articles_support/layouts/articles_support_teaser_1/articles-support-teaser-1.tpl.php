<?php

/**
 * @file
 * articles support v1 full node layout template.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="articles-support-1 <?php print $classes;?> clearfix">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <<?php print $teaser_all_wrapper ?> class="header-wrapper <?php print $teaser_all_classes;?>">
    <?php print $teaser_all; ?>
  </<?php print $teaser_all_wrapper ?>>

  <<?php print $teaser_narrow_up_wrapper ?> class="row-1-wrapper <?php print $teaser_narrow_up_classes;?>">
    <?php print $teaser_narrow_up; ?>
  </<?php print $teaser_narrow_up_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
