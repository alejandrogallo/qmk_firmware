
#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define TAPPING_TERM 180
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#undef TAPPING_FORCE_HOLD

//#define USE_SERIAL_PD2

// #define TAPPING_FORCE_HOLD
// #define TAPPING_TERM 100

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
//#define RGB_MATRIX_ENABLE
#define RGBLED_NUM 54
#define RGBLED_SPLIT { 27, 27 }
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#ifndef RGBLIGHT_ENABLE
#  define RGBLIGHT_ENABLE
#endif


/*
 * OLED STUFF
 */
//#define SSD1306OLED
#undef SSD1306OLED
#define OLED_FONT_H "keyboards/crkbd/keymaps/gallo/glcdfont.c"
// #define OLED_FONT_WIDTH 5
// #define OLED_FONT_HEIGHT 7

#undef OLED_DISABLE_TIMEOUT

/*
 * JOYSTICK CONFIGURATION
 */
#define JOYSTICK_BUTTON_COUNT 0
#define JOYSTICK_AXES_COUNT 2

// mouse settings
#define MOUSEKEY_DELAY      10
#define MOUSEKEY_INTERVAL   30
#define MOUSEKEY_MAX_SPEED  10
#define MOUSEKEY_TIME_TO_MAX  10
#define MOUSEKEY_WHEEL_MAX_SPEED  1


// clang-format off
#define LAYOUT( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { KC_NO, KC_NO, KC_NO, L30, L31, L32 }, \
    { R05, R04, R03, R02, R01, R00 }, \
    { R15, R14, R13, R12, R11, R10 }, \
    { R25, R24, R23, R22, R21, R20 }, \
    { KC_NO, KC_NO, KC_NO, R32, R31, R30 } \
  }

#define LAYOUT_kc( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  LAYOUT( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05,                     KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15,                     KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25,                     KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
                                            KC_##L30, KC_##L31, KC_##L32, KC_##R30, KC_##R31, KC_##R32 \
  )

#define LAYOUT_kc_hyper( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  LAYOUT( \
    HYPR(KC_##L00), HYPR(KC_##L01), HYPR(KC_##L02), HYPR(KC_##L03), HYPR(KC_##L04), HYPR(KC_##L05),                     HYPR(KC_##R00), HYPR(KC_##R01), HYPR(KC_##R02), HYPR(KC_##R03), HYPR(KC_##R04), HYPR(KC_##R05), \
    HYPR(KC_##L10), HYPR(KC_##L11), HYPR(KC_##L12), HYPR(KC_##L13), HYPR(KC_##L14), HYPR(KC_##L15),                     HYPR(KC_##R10), HYPR(KC_##R11), HYPR(KC_##R12), HYPR(KC_##R13), HYPR(KC_##R14), HYPR(KC_##R15), \
    HYPR(KC_##L20), HYPR(KC_##L21), HYPR(KC_##L22), HYPR(KC_##L23), HYPR(KC_##L24), HYPR(KC_##L25),                     HYPR(KC_##R20), HYPR(KC_##R21), HYPR(KC_##R22), HYPR(KC_##R23), HYPR(KC_##R24), HYPR(KC_##R25), \
                                            KC_##L30, KC_##L31, KC_##L32, KC_##R30, KC_##R31, KC_##R32 \
  )

#define LAYOUT_kc_super( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  LAYOUT( \
    LGUI(KC_##L00), LGUI(KC_##L01), LGUI(KC_##L02), LGUI(KC_##L03), LGUI(KC_##L04), LGUI(KC_##L05),                     LGUI(KC_##R00), LGUI(KC_##R01), LGUI(KC_##R02), LGUI(KC_##R03), LGUI(KC_##R04), LGUI(KC_##R05), \
    LGUI(KC_##L10), LGUI(KC_##L11), LGUI(KC_##L12), LGUI(KC_##L13), LGUI(KC_##L14), LGUI(KC_##L15),                     LGUI(KC_##R10), LGUI(KC_##R11), LGUI(KC_##R12), LGUI(KC_##R13), LGUI(KC_##R14), LGUI(KC_##R15), \
    LGUI(KC_##L20), LGUI(KC_##L21), LGUI(KC_##L22), LGUI(KC_##L23), LGUI(KC_##L24), LGUI(KC_##L25),                     LGUI(KC_##R20), LGUI(KC_##R21), LGUI(KC_##R22), LGUI(KC_##R23), LGUI(KC_##R24), LGUI(KC_##R25), \
                                            KC_##L30, KC_##L31, KC_##L32, KC_##R30, KC_##R31, KC_##R32 \
  )
