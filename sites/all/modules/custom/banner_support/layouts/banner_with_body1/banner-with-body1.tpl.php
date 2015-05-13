<?php

/**
 * @file
 * articles support v1 full node layout template.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="banner-with-body1 <?php print $classes;?> clearfix">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <<?php print $row1_wrapper ?> class="row-1-wrapper <?php print $row1_classes;?>">
    <?php print $row1; ?>
  </<?php print $row1_wrapper ?>>

  <<?php print $row2_wrapper ?> class="row-2-wrapper <?php print $row2_classes;?>">
     <?php print $row2; ?>
  </<?php print $row2_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
