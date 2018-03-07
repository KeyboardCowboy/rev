<?php
/**
 * @file
 * Contains \DrupalRev.
 */

use RevAPI\Rev;

/**
 * Custom functionality for the Rev module.
 */
class DrupalRevMock extends DrupalRev {

  /**
   * {@inheritdoc}
   */
  public function __construct() {
    $mode = static::MODE_SANDBOX;
    $client_key = rev_get_client_key($mode);
    $user_key = rev_get_user_key($mode);
    $this->rev = new Rev($client_key, $user_key, static::$hostmap[$mode]);
  }

}
