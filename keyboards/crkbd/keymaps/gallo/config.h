
#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SSD1306OLED

#define USE_SERIAL_PD2

// #define TAPPING_FORCE_HOLD
// #define TAPPING_TERM 100

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define OLED_FONT_H "keyboards/crkbd/keymaps/gallo/glcdfont.c"
// #define OLED_FONT_WIDTH 5
// #define OLED_FONT_HEIGHT 7

#define OLED_DISABLE_TIMEOUT


#define JOYSTICK_BUTTON_COUNT 0
#define JOYSTICK_AXES_COUNT 2
