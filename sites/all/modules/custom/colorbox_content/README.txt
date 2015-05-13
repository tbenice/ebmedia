usage:
Create a link with class="colorbox-content" and having the following query args:

NODE:
type=node&node=[nid]&view_mode=[view_mode]&langcode=[langcode]
  Node and view_mode are required. Lancode will default to 'en' if not specified.
  
BLOCK:
type=block&module=[module that exposes the block]&delta=[the block delta]

VIEW:
type=view&view=[the view machine name]&display=[the display machine name]&[args= a list of args that will be passed to the view, each as a separage get param]
