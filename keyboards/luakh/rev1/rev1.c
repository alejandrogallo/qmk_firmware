#include "luakh.h"
#include "pointing_device.h"
#include <quantum.h>

#define LUAKH_STATE(left, right) (0b ## left ## right) & (DAUMEN_STATE)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_GUI_SGUI] = ACTION_TAP_DANCE_DOUBLE(KC_RGUI, KC_RSFT),
  [TD_ENT_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_TAB),
  [TD_SPC_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_LALT),
};

static uint8_t DAUMEN_STATE = 0x00;
enum DaumenMask
  { DL0 = 0b100000
  , DL1 = 0b010000
  , DL2 = 0b001000
  , DR0 = 0b000100
  , DR1 = 0b000010
  , DR2 = 0b000001
  };

// LUAKH MACRO LIBRARY ========================================================
#ifdef USE_LUAKH_MACROS
typedef struct LuakhMacro {
  const uint16_t macro[LUAKH_MACRO_MAX_SIZE];
  const uint16_t value;
} LuakhMacro_t;

static struct {
  uint16_t lastKeyCode;
  LuakhMacro_t *where;
} LUAKH_MACRO_LAST;

static LuakhMacro_t LUAKH_MACROS[] =
  { { {KC_A, KC_B}
    , KC_ENT
    }
  };

static bool LUAKH_MACRO_LISTENING = false;

#ifndef LUAKH_MACRO_KEY
#  error LUAKH_MACRO_KEY not defined
#endif

#endif // USE_LUAKH_MACROS

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {

#ifdef USE_LUAKH_MACROS
  LUAKH_MACRO_LAST.lastKeyCode = KC_A;

  // toggle listening of the macro
  if (keycode == LUAKH_MACRO_KEY && record->pressed)
    LUAKH_MACRO_LISTENING ^= true;

  if (LUAKH_MACRO_LISTENING && keycode == LUAKH_MACRO_KEY) {
    if (record->pressed) {
    }
  }
#endif

  return true;


  /*
  if ((keycode >= KC_DR2) && (keycode <= KC_DL0)) {

    SEND_STRING("echo ");
    if (DL0 & DAUMEN_STATE) {
      SEND_STRING("DL0 ");
    } if (DL1 & DAUMEN_STATE) {
      SEND_STRING("DL1 ");
    } if (DL2 & DAUMEN_STATE) {
      SEND_STRING("DL2 ");
    } if (DR0 & DAUMEN_STATE) {
      SEND_STRING("DR0 ");
    } if (DR1 & DAUMEN_STATE) {
      SEND_STRING("DR1 ");
    } if (DR2 & DAUMEN_STATE) {
      SEND_STRING("DR2 ");
    } if ((DL0 | DR0) ==  DAUMEN_STATE) {
      SEND_STRING("DL0+DR0 ");
    }
    SEND_STRING("\n");

  }
  */

  if ((keycode >= KC_DR2) && (keycode <= KC_DL0)) {

    switch (DAUMEN_STATE) {
      case DR2:
        SEND_STRING("echo DR2\n");
        break;
      case DR1:
        SEND_STRING("echo DR1\n");
        break;
      case DR0:
        if (record->event.pressed) {
          register_mods(KC_LALT);
        } else {
          unregister_mods(KC_LALT);
        }
        break;
      case DL2:
        SEND_STRING("echo DL2\n");
        break;
      case DL1:
        SEND_STRING("echo DL1\n");
        break;
      case DL0:
        SEND_STRING("echo DL0\n");
        break;
      case (DL0 | DL1):
        SEND_STRING("echo 000 110\n");
        break;
      default:
        break;
    }

    if ((keycode >= KC_DR2) && (keycode <= KC_DL0)) {
      // layer_on
      // update_tri_layer

      const uint8_t mask = 1 << (keycode - SAFE_RANGE);

      if (record->event.pressed) {
        DAUMEN_STATE |= mask;
      } else {
        DAUMEN_STATE ^= mask;
      }

    }

    /*
    if ((DL0 | DL1) == DAUMEN_STATE) {
      SEND_STRING("echo 000 110\n");
    } else if (DR2 == DAUMEN_STATE) {
      SEND_STRING("echo DR2\n");
    } else if (DR1 == DAUMEN_STATE) {
      SEND_STRING("echo DR1\n");
    } else if (DAUMEN_STATE == DR0) {
      if (record->event.pressed) {
          add_mods(KC_LALT);
      } else {
          del_mods(KC_LALT);
      }
    } else if (DL2 == DAUMEN_STATE) {
      SEND_STRING("echo DL2\n");
    } else if (DL1 == DAUMEN_STATE) {
      SEND_STRING("echo DL1\n");
    } else if (DL0 == DAUMEN_STATE) {
      SEND_STRING("echo DL0\n");
    }
    */

  }


  return true;
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LGUI_T(KC_Z):
    case RGUI_T(KC_SLSH):
      return TAPPING_TERM + 60;
    case LT(SYMBOLS, KC_SPC):
      return TAPPING_TERM + 00;
    default:
      return TAPPING_TERM;
  }
}

// COMBOS ================================================================={{{1
enum {
      ENTER_COMBO = 0,
      ESC_COMBO,
      TAB_COMBO,
      ALT_COMBO,
      CTL_COMBO
};
const uint16_t PROGMEM enter_combo[]  = {KC_COMM, KC_M, COMBO_END};
const uint16_t PROGMEM esc_combo[]  = {KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM tab_combo[]  = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM alt_combo[]  = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM ctl_combo[]  = {KC_FN29, KC_FN28, COMBO_END};
combo_t key_combos[COMBO_COUNT]
  = { COMBO(enter_combo, KC_ENT)
    , COMBO(esc_combo, KC_ESC)
    , COMBO(tab_combo, KC_TAB)
    };

/*
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case ALT_COMBO:
      if (pressed) {
        tap_code16(KC_LALT);
      }
      break;
  }
}
*/
