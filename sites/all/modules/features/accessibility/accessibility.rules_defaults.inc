<?php
/**
 * @file
 * accessibility.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function accessibility_default_rules_configuration() {
  $items = array();
  $items['rules_tfa_user_login_redirect_setup'] = entity_import('rules_config', '{ "rules_tfa_user_login_redirect_setup" : {
      "LABEL" : "User redirect to TFA setup on login",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [ { "NOT tfa_rules_user_has_tfa" : [] } ],
      "DO" : [
        { "drupal_message" : {
            "message" : "Two-factor authentication (TFA) is strongly recommended; please configure your account security.",
            "type" : "warning",
            "repeat" : "0"
          }
        },
        { "redirect" : { "url" : "\\/dotgovuser\\/[account:uid]\\/security\\/tfa" } }
      ]
    }
  }');
  return $items;
}
