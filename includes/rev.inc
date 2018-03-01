<?php
/**
 * @file
 * Custom functionality for Rev module.
 */

/**
 * Get the current mode we're running in.
 *
 * @return string
 *   The current rev mode: sandbox | prod
 */
function rev_get_mode() {
  return variable_get('rev_mode', REV_MODE_SANDBOX);
}

/**
 * Get the Client API key for a given mode.
 *
 * @param string $mode
 *   The mode whose key to retrieve.
 *
 * @return string
 *   The client API key or an empty string if it's not set.
 */
function rev_get_client_api($mode) {
  return variable_get('rev_' . $mode . '_client_api_key', '');
}

/**
 * Get the User API Key for a given mode.
 *
 * @param string $mode
 *   The mode whose key to retrieve.
 *
 * @return string
 *   The User API Key.
 */
function rev_get_user_api($mode) {
  return variable_get('rev_' . $mode . '_user_api_key', '');
}

/**
 * Get the email address for a given mode.
 *
 * @param string $mode
 *   The mode whose email address to retrieve.
 *
 * @return string
 *   The email address.
 */
function rev_get_email_address($mode) {
  return variable_get('rev_' . $mode . '_email_address', '');
}