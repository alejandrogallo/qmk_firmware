#pragma once

#include "config_common.h"

//#define MATRIX_ROW_PINS { D0, D1, D2, B6 }
//#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4 }


#define MATRIX_ROW_PINS { B6, D2, D1, D0 }
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes'
 * in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D3 // or D0, D1, D2, D3, E6

#define MASTER_LEFT

/*
 * RGB CONFIGURATION
 */
#define RGB_DI_PIN  F5
#define RGBLED_NUM  14
#define RGBLED_SPLIT { 7, 7 }
//#define RGBLIGHT_HUE_STEP 8
//#define RGBLIGHT_SAT_STEP 8
//#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_ANIMATIONS

#undef MANUFACTURER
#define MANUFACTURER    Alejandro Gallo
#undef PRODUCT
#define PRODUCT         atreus split keyboard
#undef DESCRIPTION
#define DESCRIPTION     what else do you need
