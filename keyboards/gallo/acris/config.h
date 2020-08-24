#pragma once

#include "config_common.h"

#define MATRIX_ROW_PINS { D3, D2, D1, D0 }
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5, B6, F6, B2, B3, B1, F7 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/*
 * RGB CONFIGURATION
 */
#define RGB_DI_PIN  F5
#define RGBLED_NUM  10
//#define RGBLIGHT_HUE_STEP 8
//#define RGBLIGHT_SAT_STEP 8
//#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_ANIMATIONS

//#include "rgblight.h"

#undef MANUFACTURER
#define MANUFACTURER    Alejandro Gallo
#undef PRODUCT
#define PRODUCT         acris keyboard
#undef DESCRIPTION
#define DESCRIPTION     acris keyboard blahblahblah

/*
 * JOYSTICK CONFIGURATION
 */
#define JOYSTICK_BUTTON_COUNT 0
#define JOYSTICK_AXES_COUNT 2
