
#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define TAPPING_TERM 220
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
