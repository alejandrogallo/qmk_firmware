// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "config.h"

#define BASE 0
#define PROGRAMMING_LAYER 1
#define MOVEMENT_LAYER 2
#define LAYER_LAYER 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
    +----+----+----+----+----+              +----+----+----+----+----+
    |    |    |    |    |    |              |    |    |    |    |    |
    +----+----+----+----+----+              +----+----+----+----+----+
    |    |    |    |    |    |              |    |    |    |    |    |
    +----+----+----+----+----+              +----+----+----+----+----+
    |    |    |    |    |    +----+    +----+    |    |    |    |    |
    +----+----+----+----+----+    |    |    +----+----+----+----+----+
    |    |    |    |    |    |    |    |    |    |    | '  |    |    |
    +----+----+----+----+----+----+    +----+----+----+----+----+----+
*/
  [BASE] = GLAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_TAB,  TO(LAYER_LAYER),  KC_BSPC,  KC_LSFT, KC_LCTL, KC_LALT, KC_SPC, MO(PROGRAMMING_LAYER), KC_MINS, KC_QUOT, KC_ENT
  ),

/*
    +----+----+----+----+----+              +----+----+----+----+----+
    | !  | @  | #  | $  | %  |              |    |    |    |    |    |
    +----+----+----+----+----+              +----+----+----+----+----+
    |    |    |    |    |    |              |    |    |    |    |    |
    +----+----+----+----+----+              +----+----+----+----+----+
    |    |    |    |    |    +----+    +----+    |    |    |    |    |
    +----+----+----+----+----+    |    |    +----+----+----+----+----+
    |    |    |    |    |    |    |    |    |    |    | '  |    |    |
    +----+----+----+----+----+----+    +----+----+----+----+----+----+
*/
  [PROGRAMMING_LAYER] = GLAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_HASH, KC_DOLLAR, KC_PERCENT,              KC_CIRCUMFLEX, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_LCBR, KC_RCBR, KC_QUOT, KC_GRAVE, KC_PIPE,                  KC_BSPC, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_0,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    KC_ESC, KC_INS,  KC_LGUI, KC_BSPC, KC_LSFT, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, TG(MOVEMENT_LAYER), KC_EQL  ),

/*
    +----+----+----+----+----+              +----+----+----+----+----+
    |    |    |    |    |    |              |    |    |    |    |    |
    +----+----+----+----+----+              +----+----+----+----+----+
    |    |    |    |    |    |              |    |    |    |    |    |
    +----+----+----+----+----+              +----+----+----+----+----+
    |    |    |    |    |    +----+    +----+    |    |    |    |    |
    +----+----+----+----+----+    |    |    +----+----+----+----+----+
    |    |    |    |    |    |    |    |    |    |    | '  |    |    |
    +----+----+----+----+----+----+    +----+----+----+----+----+----+
*/
  [MOVEMENT_LAYER] = GLAYOUT( /* [> LOWER <] */
    KC_VOLU,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_DEL,  KC_MS_WH_UP,  KC_MS_U,  KC_MS_WH_DOWN, KC_MS_BTN1,
    KC_VOLD,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_INS,  KC_MS_L,      KC_MS_D,  KC_MS_R,       KC_MS_BTN2,
    KC_NO,   KC_NO, KC_NO,   KC_NO,   RESET,                        KC_NO,   KC_MS_WH_LEFT,KC_NO,    KC_MS_WH_RIGHT,KC_MS_BTN3,
    TO(BASE),   KC_NO, KC_LGUI, KC_BSPC, KC_LSFT, KC_LCTL, KC_LALT, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO ),

  [LAYER_LAYER] = GLAYOUT(
    KC_NO,  KC_NO, KC_NO,   KC_NO,  KC_NO,                   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO,      KC_NO,        KC_NO,   KC_NO,
    KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,                     KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,
    TO(BASE), KC_NO, TO(MOVEMENT_LAYER), KC_NO, KC_NO, KC_LCTL, KC_LALT, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO ),
};
