#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif
#include "pointing_device.h"
#ifdef GALLO_JOYSTICK
#include "joystick.h"
#endif

extern keymap_config_t keymap_config;
extern uint8_t is_master;
#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

#ifdef GALLO_JOYSTICK
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(B4, 0, 511, 1023), // 10 bit adc
    [1] = JOYSTICK_AXIS_IN(B5, 0, 504, 1023), // 10 bit adc
};
void pointing_device_task(void) {
  if (!is_master) return;
  report_mouse_t currentReport;
  currentReport = pointing_device_get_report();
  currentReport.x = -(int8_t)((joystick_status.axes[1] >> 4) & 0x00ff);
  currentReport.y = (int8_t)((joystick_status.axes[0] >> 4) & 0x00ff);
  pointing_device_set_report(currentReport);
  pointing_device_send();
}
#endif

#define _BASE 0
#define _SYMBS 1
#define _MVMNT 2
#define _ADJUST 3
#define LAYER_LAYER 4

enum custom_keycodes {
  BASE = SAFE_RANGE,
  SYMBS,
  MVMNT,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC___  KC_NO
#define KC_BASE BASE
#define KC_SYMBS SYMBS
#define KC_MVMNT MVMNT
#define KC_MVMNT MVMNT
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
// mouse wheel
#define KC_WHU  KC_MS_WH_UP
#define KC_WHD  KC_MS_WH_DOWN
#define KC_WHR  KC_MS_WH_RIGHT
#define KC_WHL  KC_MS_WH_LEFT
// Mouse keys
#define KC_MLCK KC_MS_BTN1
#define KC_MRCK KC_MS_BTN2
#define KC_MCCK KC_MS_BTN3
/* buttons */
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
#define KC_MB3 KC_MS_BTN3


#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)
#define KC_TO_MOVEMENT TO(_MVMNT)
#define KC_TO_BASE TO(_BASE)
#define KC_TO_ADJT TO(_ADJUST)
#define KC_TO_LYR TO(LAYER_LAYER)

// mod tabs
#define KC_C_ESC LCTL_T(KC_ESC)
#define KC_M_ENT LALT_T(KC_ENT)

#define TO_BASE KC_TO_BASE
#define KC_RST RESET
#define TO_MOVEMENT KC_TO_MOVEMENT
#define __ KC_NO

#define KC_RGBMF RGB_MODE_FORWARD



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_kc(
 ESC,         Q, W, E, R, T, /*|*/ Y, U,    I,   O,    P, BSPC,
 TAB,         A, S, D, F, G, /*|*/ H, J,    K,   L, SCLN, QUOT,
 TO_LYR, Z, X, C, V, B, /*|*/ N, M, COMM, DOT, SLSH,  ENT,
           LGUI, LSFT, C_ESC, /*|*/ M_ENT, SPC, SYMBS
),

[_SYMBS] = LAYOUT_kc(
ESC , EXLM, AT  , HASH, DOLLAR, PERCENT , /*|*/ CIRCUMFLEX, 7, 8, 9, ASTR, MINS,
LCTL, LCBR, RCBR, QUOT, GRAVE , PIPE    , /*|*/ BSPC      , 4, 5, 6, PLUS, PLUS,
LSFT, LBRC, RBRC, LPRN, RPRN  , AMPR    , /*|*/ 0         , 1, 2, 3, BSLS, EQL ,
                       LGUI, LSFT, C_ESC, /*|*/ M_ENT, SPC, SYMBS
),

[_MVMNT] = LAYOUT_kc(
TO_BASE, HOME,  MB2, PGDN, PGUP, MB1 , /*|*/  __ , MB1 , MB3 , MB2,  DEL, BSPC,
TO_ADJT,  END, LEFT, DOWN,   UP, RGHT, /*|*/ MS_L, MS_D, MS_U, MS_R, INS,   __,
TO_BASE, F1  , F2  , F3  , F4  , F5  , /*|*/ WHL , WHD , WHU ,  WHR, CLR, ENT ,
                      ESC, LSFT, LCTL, /*|*/ LALT,  SPC, SYMBS
),

[_ADJUST] = LAYOUT_kc(
TO_BASE, LRST,  __ ,   __ , __, RGBMF, /*|*/ __, __, __, __, __, __,
LTOG   , LHUI, LSAI,  LVAI, __,    __, /*|*/ __, __, __, __, __, LTOG,
LMOD   , LHUD, LSAD,  LVAD, __,    __, /*|*/ __, __, __, __, __, __,
                      ESC, SYMBS, SPC,  /*|*/ ENT, MVMNT, ALTKN
),

[LAYER_LAYER] = LAYOUT_kc(
TO_BASE    , __, __, __, __, __,  /*|*/   __, __, __, __, __, __,
TO_ADJT    , __, __, __, __, __,  /*|*/   __, __, __, __, __, __,
TO_MOVEMENT, __, __, __, __, RST, /*|*/ RST, __, __, __, __, __,
                     __, __, __,  /*|*/   __, __, __
),

};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}


//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void           pointing_device_send(void);
report_mouse_t pointing_device_get_report(void);
void           pointing_device_set_report(report_mouse_t);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}


void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  //set_keylog(joystick_status.axes[0], record);

  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_BASE);
      }
      return false;
    case SYMBS:
      if (record->event.pressed) {
        layer_on(_SYMBS);
        update_tri_layer_RGB(_SYMBS, _MVMNT, _ADJUST);
      } else {
        layer_off(_SYMBS);
        update_tri_layer_RGB(_SYMBS, _MVMNT, _ADJUST);
      }
      return false;
    case MVMNT:
      if (record->event.pressed) {
        layer_on(_MVMNT);
        update_tri_layer_RGB(_SYMBS, _MVMNT, _ADJUST);
      } else {
        layer_off(_MVMNT);
        update_tri_layer_RGB(_SYMBS, _MVMNT, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
