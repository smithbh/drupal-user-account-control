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

  $form = array();
  $form['display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configure Registration Options'),
    );

  $form['display']['registration_email_configuration_level'] = array(
    '#type' => 'radios',
    '#default_value' => $registration_email_configuration_level_default_value,
    '#options' => array(
      'disabled' => t('Disabled'),
      'basic' => t('Basic'),
      'advanced' => t('Advanced')
    ),
  );

  $form['display']['registration_email_allowed_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Restrict registration to the following domain (<em>basic</em>):'),
    '#description' => t('Examples:').'<ul><li>example.com</li><li>subdomain.example.com</li>',
    '#maxlength' => 1024,
    '#default_value' => variable_get('registration_email_allowed_domain'),
  );

  $form['display']['registration_email_advanced_expression'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom regular expression for domain restriction (<em>advanced</em>):'),
    '#description' => t('Examples: ') . '<ul><li>/(example\.com)$/</li><li>/(\.edu)$/</li>',
    '#default_value' => variable_get('registration_email_advanced_expression'),
  );

  $form['display']['registration_email_error_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom error message to display upon invalid registration (<em>optional</em>):'),
    '#description' => '<em>' . t('Note: HTML markup is not supported.') . '</em>',
    '#default_value' => variable_get('registration_email_error_message'),
  );

  return system_settings_form($form);
}