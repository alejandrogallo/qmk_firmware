#include QMK_KEYBOARD_H

#ifdef GALLO_JOYSTICK
#include "pointing_device.h"
#include "joystick.h"

extern uint8_t is_master;
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
#define _HPR 5
#define _SUPER 6


enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC___  KC_NO
#define KC_RST   RESET
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
#define KC_CTL_or_SLSH RCTL_T(KC_SLSH)
#define KC_G_SPC KC_SPC
#define KC_BT1_DOWN MT(KC_A, KC_MS_BTN1)

// symbols and such
#define KC_MO_SYMBS MO(_SYMBS)
#define KC_MO_MVMNT MO(_MVMNT)

#define TO_BASE KC_TO_BASE
#define KC_RST RESET
#define TO_MOVEMENT KC_TO_MOVEMENT
#define __ KC_NO

#define KC_RGBMF RGB_MODE_FORWARD


#define KC_MO_HYPR MO(_HPR)
#define KC_MO_SUPER MO(_SUPER)
#define KC_BSP_MOV LT(_MVMNT, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_kc(
 ESC,         Q, W, E, R, T, /*|*/ Y, U,    I,   O,    P, BSPC,
 TAB,         A, S, D, F, G, /*|*/ H, J,    K,   L, SCLN, QUOT,
      TO_LYR, Z, X, C, V, B, /*|*/ N, M, COMM, DOT, SLSH,  ENT,
           BSP_MOV, LSFT, C_ESC, /*|*/ M_ENT, G_SPC, MO_SYMBS
),

[_SYMBS] = LAYOUT_kc(
ESC , TAB, __, TO_LYR, LEFT, RIGHT,        /*|*/ DEL    , 7, 8, 9, MINS, MINS,
LCTL, LCBR, RCBR, QUOT, GRAVE , BSLS   ,   /*|*/ BSPC   , 4, 5, 6, EQL, PLUS,
LSFT, LBRC, RBRC, LPRN, RPRN  , AMPR    , /*|*/ 0      , 1, 2, 3, ENT, EQL ,
                    MO_SUPER, LSFT, C_ESC, /*|*/ M_ENT, G_SPC, MO_SYMBS
),

[_SUPER] = LAYOUT_kc_super(
 ESC,         Q, W, E, R, T, /*|*/ Y, U,    I,   O,    P, BSPC,
 TAB,         A, S, D, F, G, /*|*/ H, J,    K,   L, SCLN, QUOT,
      TO_LYR, Z, X, C, V, B, /*|*/ N, M, COMM, DOT, SLSH,  ENT,
           MO_SUPER, LSFT, C_ESC, /*|*/ M_ENT, G_SPC, MO_HYPR
),

[_HPR] = LAYOUT_kc_hyper(
 ESC,         Q, W, E, R, T, /*|*/ Y, U,    I,   O,    P, BSPC,
 TAB,         A, S, D, F, G, /*|*/ H, J,    K,   L, SCLN, QUOT,
      TO_LYR, Z, X, C, V, B, /*|*/ N, M, COMM, DOT, SLSH,  ENT,
           MO_HYPR, RST, C_ESC, /*|*/ M_ENT, G_SPC, MO_HYPR
),

[_MVMNT] = LAYOUT_kc(
TO_BASE, HOME,  MB2, PGDN, PGUP, MB1 , /*|*/ TO_BASE, MB1 , MB3 , MB2,  DEL, BSPC,
TO_ADJT,  END, LEFT, DOWN,   UP, RGHT, /*|*/ MS_L, MS_D, MS_U, MS_R, INS,   __,
TO_BASE, F1  , F2  , F3  , F4  , F5  , /*|*/ WHL , WHD , WHU ,  WHR, CLR, ENT ,
                MO_MVMNT, LSFT, C_ESC, /*|*/ M_ENT, RCTL, RSFT
),

[_ADJUST] = LAYOUT_kc(
TO_BASE, __,  __ ,   __ , __, RGBMF, /*|*/ __, __, __, __, __, __,
LTOG   , LHUI, LSAI,  LVAI, __,    __, /*|*/ __, __, __, __, __, LTOG,
LMOD   , LHUD, LSAD,  LVAD, __,    __, /*|*/ __, __, __, __, __, __,
                MO_MVMNT, LSFT, C_ESC, /*|*/ M_ENT, G_SPC, MO_SYMBS
),

[LAYER_LAYER] = LAYOUT_kc(
TO_BASE    , TO_BASE, __, __, __, __,  /*|*/   TO_MOVEMENT, __, __, __, __, __,
TO_ADJT    , __, __, __, __, __,  /*|*/   TO_ADJT, __, __, __, __, __,
TO_MOVEMENT, __, __, __, __, RST, /*|*/ RST, __, __, __, __, __,
                     __, __, __,  /*|*/   __, __, __
),

};
