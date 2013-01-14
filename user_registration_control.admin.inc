<?php

/**
 * @file
 * Administration pages provided by User Registration Control module.
 */

/**
 * Menu callback for admin/config/people/user_registration_control.
 * @return type system_settings_form($form).
 */
function user_registration_control_admin_settings() {
  $registration_email_configuration_level_default_value = variable_get('registration_email_configuration_level');
  $registration_email_configuration_level_default_value = (is_null($registration_email_configuration_level_default_value)) ? 'disabled' : $registration_email_configuration_level_default_value;
  $collapsed_state_basic = ($registration_email_configuration_level_default_value === 'basic') ? FALSE : TRUE;
  $collapsed_state_advanced = ($registration_email_configuration_level_default_value === 'advanced') ? FALSE : TRUE;


  $form = array();
  $form['display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configure Registration Options (<a href="/admin/help/user_registration_control">help</a>)'),
    );

  $form['display']['registration_email_configuration_level'] = array(
    '#type' => 'radios',
    '#default_value' => $registration_email_configuration_level_default_value,
    '#options' => array(
      'disabled' => t('Disabled (<em>default</em>)'),
      'basic' => t('Basic'),
      'advanced' => t('Advanced')
    ),
  );

  $form['basic'] = array(
    '#type' => 'fieldset',
    '#title' => 'Basic Options',
    '#collapsible' => TRUE,
    '#collapsed' => $collapsed_state_basic,
  );

  $form['basic']['registration_email_allowed_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Restrict registration to the following domain:'),
    '#description' => t('Examples:<em><ul><li>example.com</li><li>subdomain.example.com</li></em>'),
    '#maxlength' => 1024,
    '#default_value' => variable_get('registration_email_allowed_domain'),
  );

  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => 'Advanced Options',
    '#collapsible' => TRUE,
    '#collapsed' => $collapsed_state_advanced,
  );

  $form['advanced']['registration_email_advanced_expression'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom regular expression for domain restriction (<em>PCRE Syntax</em>):'),
    '#description' => t('Examples:<em><ul><li>/(example\.com)$/</li><li>/(\.edu)$/</li></em>'),
    '#default_value' => variable_get('registration_email_advanced_expression'),
  );

  $form['error_message'] = array(
    '#type' => 'fieldset',
    '#title' => 'Error Message',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['error_message']['registration_email_error_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom error message to display upon invalid registration (<em>optional</em>):'),
    '#description' => t('<em>Note: Markup and tokens are currently not supported.</em>'),
    '#default_value' => variable_get('registration_email_error_message'),
  );

  return system_settings_form($form);
}