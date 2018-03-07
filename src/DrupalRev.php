<?php
/**
 * @file
 * Contains \DrupalRev.
 */

use RevAPI\Rev;

/**
 * Custom functionality for the Rev module.
 */
class DrupalRev {
  const MODE_DISABLED = 'disabled';
  const MODE_SANDBOX = 'sandbox';
  const MODE_PROD = 'prod';

  /**
   * Map our modes to the proper Rev.com hosts.
   *
   * @var array
   */
  protected static $hostmap = array(
    self::MODE_PROD => Rev::PRODUCTION_HOST,
    self::MODE_SANDBOX => Rev::SANDBOX_HOST,
  );

  /**
   * @var \RevAPI\Rev
   */
  protected $rev;

  /**
   * DrupalRev constructor.
   *
   * Create a connection to the Rev service based on the admin settings.
   */
  public function __construct() {
    // If no mode was supplied, get it from the admin settings.
    $mode = rev_get_mode();
    $client_key = rev_get_client_key($mode);
    $user_key = rev_get_user_key($mode);

    // @todo: Create tests and contingencies for bad creds and disabled API.

    if ($mode !== self::MODE_DISABLED) {
      $this->rev = new Rev($client_key, $user_key, self::$hostmap[$mode]);
    }
  }

  /**
   * Singleton loader to get a connection to the Rev API.
   *
   * @return static
   *   An instantiated object.
   */
  public static function connect() {
    static $instance;

    if (!$instance) {
      $instance = new static();
    }

    return $instance;
  }

  public function transcribeFile($file) {
    try {
      $input = $this->rev->uploadAudioUrl(file_create_url($file->uri), $file->filemime);
    }
    catch (Exception $e) {
      $no=0;
    }
  }

}
