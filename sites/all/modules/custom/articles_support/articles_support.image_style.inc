<?php
/**
 * @file articles_support.image_style.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function articles_support_default_image_style_assets() {
  $styles = array();

  // Exported image style: article-inline.
  $styles['article-inline'] = array(
    'name' => 'article-inline',
    'label' => 'article-inline',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: article-teaser-square.
  $styles['article-teaser-square'] = array(
    'name' => 'article-teaser-square',
    'label' => 'article-teaser-square',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: article_list_photo.
  $styles['article_list_photo'] = array(
    'name' => 'article_list_photo',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 240,
          'height' => 220,
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 240,
          'height' => 220,
        ),
        'weight' => -9,
      ),
      4 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 240,
          'height' => 220,
          'anchor' => 'center-top',
        ),
        'weight' => -8,
      ),
    ),
    'label' => 'article_list_photo',
  );

  // Exported image style: articles_teaser_square_switcher.
  $styles['articles_teaser_square_switcher'] = array(
    'name' => 'articles_teaser_square_switcher',
    'label' => 'articles_teaser_square_switcher',
    'effects' => array(
      12 => array(
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'articles_teaser_square_vert',
          'landscape' => 'article-teaser-square',
          'ratio_adjustment' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: articles_teaser_square_vert.
  $styles['articles_teaser_square_vert'] = array(
    'name' => 'articles_teaser_square_vert',
    'label' => 'articles_teaser_square_vert',
    'effects' => array(
      14 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 450,
        ),
        'weight' => -10,
      ),
      11 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 400,
          'height' => 300,
          'anchor' => 'center-top',
        ),
        'weight' => -9,
      ),
    ),
  );

  return $styles;
}

