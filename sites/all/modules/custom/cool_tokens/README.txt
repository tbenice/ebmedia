README.txt
==========

This module allows admins to create token types and tokens to be used in the Cool install profile.  These tokens can then be assigned to users via the user edit form or Rules actions.  Each token can be set to have a configurable numer of uses or be unlimited, and have a specified duration.  Each token has its own Rules event, that allows admins to specify what action will be taken on the token's use.  Tokens may be redeemed either through a URL in a new view block created by the module, or through a general URL provided by an integration module.

Usage:
 1) Download and enable the module as usual.
 2) Navigate to /admin/structure/ft-tokens-types/add to add a new token type.
   a) Provide descriptives that define the name, description, and default image.
 3) Navigate to /admin/structure/ft-tokens/add to add a new token.
   a) Provide descriptives that define the name, description, type, number of uses, token's active state, and expiry information.
 4) Once the token is created, navigate to /admin/config/workflow/rules to create new rules that utilize the token.
      

AUTHOR/MAINTAINER
======================
-Adam Murray <adam at ideaden DOT com>