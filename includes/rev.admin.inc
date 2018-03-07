<?php
/**
 * @file
 * Rev administration forms.
 */

/**
 * Rev settings form.
 */
function rev_settings_form($form, &$form_state) {
  // Display an informative message if no data has been provided.
  if (empty(rev_get_client_key(DrupalRev::MODE_SANDBOX)) && empty(rev_get_client_key(DrupalRev::MODE_PROD))) {
    drupal_set_message(t('In order to get Rev.com transcriptions, you must sign up for an API account at <a href="https://www.rev.com/api" target="_blank">https://www.rev.com/api</a>.'), 'warning');
  }

  // Choose between sandbox mode or production mode, or turn it off completely.
  $form['rev_mode'] = array(
    '#type' => 'radios',
    '#title' => t("Mode"),
    '#options' => array(
      'disabled' => t("Disabled"),
      'sandbox' => t("Sandbox"),
      'prod' => t("Production"),
    ),
    '#default_value' => rev_get_mode(),
  );

  // Get the sandbox settings.
  $form['sandbox'] = array(
    '#type' => 'fieldset',
    '#title' => t("Sandbox Settings"),
    '#collapsible' => TRUE,
    '#collapsed' => (rev_get_mode() !== DrupalRev::MODE_SANDBOX),
  );
  $form['sandbox']['rev_sandbox_client_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t("Sandbox Client API Key"),
    '#size' => 40,
    '#default_value' => rev_get_client_key(DrupalRev::MODE_SANDBOX),
  );
  $form['sandbox']['rev_sandbox_user_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t("Sandbox User API Key"),
    '#size' => 40,
    '#default_value' => rev_get_user_key(DrupalRev::MODE_SANDBOX),
  );
  $form['sandbox']['rev_sandbox_email'] = array(
    '#type' => 'textfield',
    '#title' => t("Sandbox Email Address"),
    '#size' => 40,
    '#default_value' => rev_get_email_address(DrupalRev::MODE_SANDBOX),
  );
  // $form['sandbox']['rev_sandbox_password'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t("Sandbox Password"),
  //   '#size' => 40,
  //   '#default_value' => rev_get_password(DrupalRev::MODE_SANDBOX),
  // );

  // Get the production settings.
  $form['prod'] = array(
    '#type' => 'fieldset',
    '#title' => t("Production Settings"),
    '#collapsible' => TRUE,
    '#collapsed' => (rev_get_mode() !== DrupalRev::MODE_PROD),
  );
  $form['prod']['rev_prod_client_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t("Production Client API Key"),
    '#size' => 40,
    '#default_value' => rev_get_client_key(DrupalRev::MODE_PROD),
  );
  $form['prod']['rev_prod_user_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t("Production User API Key"),
    '#size' => 40,
    '#default_value' => rev_get_user_key(DrupalRev::MODE_PROD),
  );
  $form['prod']['rev_prod_email'] = array(
    '#type' => 'textfield',
    '#title' => t("Production Email Address"),
    '#size' => 40,
    '#default_value' => rev_get_email_address(DrupalRev::MODE_PROD),
  );
  // $form['prod']['rev_prod_password'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t("Production Password"),
  //   '#size' => 40,
  //   '#default_value' => rev_get_password(DrupalRev::MODE_PROD),
  // );

  return system_settings_form($form);
}
