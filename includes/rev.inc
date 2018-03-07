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
  return variable_get('rev_mode', DrupalRev::MODE_SANDBOX);
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
function rev_get_client_key($mode) {
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
function rev_get_user_key($mode) {
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

/**
 * Place an order to transcribe a file by it's file id.
 *
 * @param int $fid
 *   A managed file id.
 */
function rev_transcribe_file($fid) {
  // Load file.
  if ($file = file_load($fid)) {
    DrupalRev::connect()->transcribeFile($file);
    // Generate package to sent to Rev.
    // @todo: Submit order to rev.
    // Store response id.

  }
  else {
    // @todo: Report failure.
  }
}
