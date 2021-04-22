#include "luakh.h"
#include "pointing_device.h"
#include <quantum.h>

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LCTL(KC_H):
    case RCTL(KC_H):
      clear_mods();
      register_code(KC_E);
      register_code(KC_O);
      return true;
    /*case KC_H:*/
      /*if (record->event.pressed) {*/
        /*SEND_STRING("Hello world!");*/
        /*return true;*/
      /*}*/
  }
  return true;
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LGUI_T(KC_V):
    case RGUI_T(KC_M):
      return TAPPING_TERM + 50;
    case KC_K_ALT:
    case KC_D_ALT:
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}
