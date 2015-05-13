<?php
/**
 * @file tokens.api.inc
 * Api information.
 */

/**
 * React before a token is being assigned to a user.
 * When a token is assigned to a user, an 'ownership' object is
 * written to the cool_tokens_owner table. That
 * ownership object is passed to this funciton along with the
 * token being assigned.
 *
 * @param stdClass $ownership
 *   The ownership object to be written to the database.
 * @param stdClass $token
 *   The token being assigned.
 */
function hook_cool_token_preassign($ownership, $token) {
  
}

/**
 * React after a token has been assigned to a user.
 * See hook_cool_token_preassign($ownership, $token)
 * for more information.
 *
 * @param stdClass $ownership
 *   The ownership object that was written to the database.
 * @param stdClass $token
 *   The token that was assigned.
 */
function hook_cool_token_assigned($ownership, $token) {
  
}

/**
 * React before a token is being UNassigned from a user.
 * When a token is unassigned the 'ownership' object is
 * deleted from the database. That ownership object is passed 
 * to this funciton along with the token being assigned.
 *
 * @param stdClass $ownership
 *   The ownership object to be deleted from the database.
 * @param stdClass $token
 *   The token being unassigned.
 */
function hook_cool_token_preunassign($ownership, $token) {
  
}

/**
 * React after a token has been UNassigned from a user.
 * When a token is unassigned the 'ownership' object is
 * deleted from the database. That ownership object is passed 
 * to this funciton along with the token being assigned.
 *
 * @param stdClass $ownership
 *   The ownership object that was deleted from the database.
 * @param stdClass $token
 *   The token that was unassigned.
 */
function hook_cool_token_unassigned($ownership, $token) {
  
}

/**
 * React before a token is used by a user (owner).
 * When a token is used by an owner, the ownership object
 * is updated with an increment to the num_used column
 * and a token specific rule event is invoked. The $args
 * variable is passed to the rule event and can be used
 * by rules that react to it.
 *
 * @param stdClass $ownership
 *   The ownership that is using the token.
 * @param stdClass $token
 *   The token being used.
 * @param array $args
 *   Array of arguments being passed through to the
 *   token invoked rule event.
 */
function hook_cool_token_preuse($ownership, $token, $args) {
  
}

/**
 * React after a token was used by a user (owner).
 * See hook_cool_token_peruse for more info.
 *
 * @param stdClass $ownership
 *   The ownership that is using the token.
 * @param stdClass $token
 *   The token being used.
 * @param array $args
 *   Array of arguments being passed through to the
 *   token invoked rule event.
 */
function hook_cool_token_postuse($ownership, $token, $args) {
  
}

/**
 * Allows modules to alter an ownership object before it is written to the database.
 * Ownership objects are written to the database when a token is given/assigned
 * to a user. The object is what defines that assignment. Here modules
 * can alter the ownership object before it is written to the database.
 * It is especially useful for adding additional data into the data column
 * for an ownership.
 *
 * @param stdClass $ownership
 *   The ownership that is written to the db during token assignment.
 * @param stdClass $token
 *   The token being assigned.
 */
function hook_cool_token_preassign_ownership_alter(&$ownership, $token) {
  $ownership->data['my_data'] = array(
    'stuff' => 'the stuff',
  );
}

/**
 * Allows modules to alter an ownership before it is updated in the database.
 * This is similar to hook_cool_preassign_ownership_alter() except
 * that is is called prior to UPDATING an ownership, not before its insertion
 * into the db.
 *
 * @param stdClass $ownership
 *   The ownership object being updated.
 */
function hook_cool_token_ownership_update_alter(&$ownership) {
  
}

/**
 * Allows modules to alter the arguments that will be passed to token rule events.
 * Args are an array of data that is passed through to the token rule events
 * when a token is used. You can use this hook to add/remove/alter data in args
 * before they are passed to the events.
 *
 * @param array $args
 *   The args to alter
 * @param stdClass $ownership
 *   The ownership using the token
 * @param stdClass $token
 *   The token being used.
 */
function hook_cool_token_preuse_args_alter(&$args, $ownership, $token) {
  
}

/**
 * Allows modules to alter the token redemption uri.
 * The redemption uri is the link that allows users
 * to use tokens. The getUri method of the cool_token entity calls url()
 * to construct the redeem url, and passes the $uri elements.
 *
 * Cool Tokens provides a default uri that will
 * work, but modules may need to alter/add/delete aspects of the uri
 * for various implementations.
 *
 * This is especially useful when you need to add GET params to the query array
 * for redeem uris output by a custom token type.
 *
 * @param array $uri
 *   The uri to alter.
 * @param stdClass $token
 *   The token that is returning a redeem url via its getUri() method.
 */
function hook_cool_tokens_redeem_uri_alter(&$uri, $token) {
  
}
