<?php
/**
 * @file
 * fantorrent_base.default_video_embed_styles.inc
 */

/**
 * Implements hook_default_video_embed_styles().
 */
function fantorrent_base_default_video_embed_styles() {
  $export = array();

  $video_embed_style = new stdClass();
  $video_embed_style->disabled = FALSE; /* Edit this to true to make a default video_embed_style disabled initially */
  $video_embed_style->api_version = 1;
  $video_embed_style->name = 'mobile';
  $video_embed_style->data = array(
    'youtube' => array(
      'width' => '300',
      'height' => '170',
      'theme' => 'dark',
      'autoplay' => 0,
      'hd' => 1,
      'rel' => 0,
      'showinfo' => 1,
      'autohide' => '2',
    ),
    'vimeo' => array(
      'width' => '300',
      'height' => '170',
      'color' => '00adef',
      'autoplay' => 0,
    ),
    'data__active_tab' => 'edit-data-vimeo',
  );
  $export['mobile'] = $video_embed_style;

  $video_embed_style = new stdClass();
  $video_embed_style->disabled = FALSE; /* Edit this to true to make a default video_embed_style disabled initially */
  $video_embed_style->api_version = 1;
  $video_embed_style->name = 'narrow';
  $video_embed_style->data = array(
    'youtube' => array(
      'width' => '420',
      'height' => '252',
      'theme' => 'dark',
      'autoplay' => 0,
      'hd' => 1,
      'rel' => 0,
      'showinfo' => 1,
      'modestbranding' => 0,
      'iv_load_policy' => '1',
      'autohide' => '2',
    ),
    'vimeo' => array(
      'width' => '420',
      'height' => '252',
      'color' => '00adef',
      'portrait' => 1,
      'title' => 1,
      'byline' => 1,
      'autoplay' => 0,
      'loop' => 0,
    ),
    'data__active_tab' => 'edit-data-vimeo',
  );
  $export['narrow'] = $video_embed_style;

  $video_embed_style = new stdClass();
  $video_embed_style->disabled = FALSE; /* Edit this to true to make a default video_embed_style disabled initially */
  $video_embed_style->api_version = 1;
  $video_embed_style->name = 'wide';
  $video_embed_style->data = array(
    'youtube' => array(
      'width' => '710',
      'height' => '426',
      'theme' => 'dark',
      'autoplay' => 0,
      'hd' => 1,
      'rel' => 0,
      'showinfo' => 1,
      'modestbranding' => 0,
      'iv_load_policy' => '1',
      'autohide' => '2',
    ),
    'vimeo' => array(
      'width' => '710',
      'height' => '426',
      'color' => '00adef',
      'portrait' => 1,
      'title' => 1,
      'byline' => 1,
      'autoplay' => 0,
      'loop' => 0,
    ),
    'data__active_tab' => 'edit-data-youtube',
  );
  $export['wide'] = $video_embed_style;

  return $export;
}
