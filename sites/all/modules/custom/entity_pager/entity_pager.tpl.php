<?php
/**
 * @file template for themeing the entity pager output
 * 
 * entity Pager Variables Available:
 * 
 * $delta: the block delta (machine name) for the current pager
 * $content: array of renderable content arrays
 *   -previous_link: the link to the previous item, if any
 *   -next_link: the link to the next item, if any
 *   -link: the back to river link, if any
 */
?>

<div id="<?php print $delta ?>" class="entity-pager-container entity-pager-js">
  
  <?php if(isset($content['previous_link'])) :?>
  	<div id="<?php print $delta; ?>-item-previous" class="entity-pager-item">
  		<?php print render($content['previous_link']); ?>
  	</div> <!-- entity-pager-item-previous -->
  <?php endif; ?>

  <?php if(isset($content['link'])) : ?>
    <div id="<?php print $delta; ?>-back-to-river-link-container" class="back-to-river-link-container">
      <?php print render($content['link']); ?>
    </div><!-- back-to-river-link-container -->
  <?php endif; ?>
  
  <?php if(isset($content['next_link'])) :?>
  	<div id="<?php print $delta; ?>-item-next" class="entity-pager-item">
  		<?php print render($content['next_link']); ?>
  	</div> <!-- entity-pager-item-next -->
  <?php endif; ?>
  
</div><!-- entity-pager -->