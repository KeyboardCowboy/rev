<?php
/**
 * @file
 * Contains \DrupalRevTest.
 */

use PHPUnit\Framework\TestCase;

require_once __DIR__ . '/DrupalRevMock.php';

/**
 * Unit tests for Rev module.
 */
class DrupalRevTest extends TestCase {

  /**
   * @var \DrupalRev
   */
  private $rev;

  /**
   * {@inheritdoc}
   */
  public function setUp() {
    parent::setUp();

    $this->rev = DrupalRevMock::connect();
  }

  /**
   * Test sending a file to Rev and getting a response.
   *
   * @todo: Find an audio file somewhere publicly on the web and replace the Drupal file.
   */
  public function testTranscribeFile() {
    $fid = 22;
    $file = file_load($fid);
    $response = $this->rev->transcribeFile($file);
  }

}
