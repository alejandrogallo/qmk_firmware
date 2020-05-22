// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "config.h"

#define BASE 0
#define PROG_LAYER 1
#define MOVEMENT_LAYER 2
#define LAYER_LAYER 3
#define RGB_LAYER 4


#define KC_RST RESET
#define KC___  KC_NO
#define XX     KC_NO
/* mouse */
#define KC_WHL KC_MS_WH_LEFT
#define KC_WHD KC_MS_WH_DOWN
#define KC_WHU KC_MS_WH_UP
#define KC_WHR KC_MS_WH_RIGHT
  /* Acceleration */
#define KC_AC0 KC_MS_ACCEL0
#define KC_AC1 KC_MS_ACCEL1
#define KC_AC2 KC_MS_ACCEL2
/* buttons */
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
#define KC_MB3 KC_MS_BTN3

/* goto layers shortcuts */
#define KC_TO_BASE TO(BASE)
#define KC_TO_LYR TO(LAYER_LAYER)
#define KC_MO_PRG MO(PROG_LAYER)
#define KC_TO_MVM TO(MOVEMENT_LAYER)
#define KC_TO_RGB TO(RGB_LAYER)

#define KC_WWWB KC_WWW_BACK
#define KC_WWWF KC_WWW_FORWARD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* == BASE LAYER =========================================================== */
[BASE] = GLAYOUT_kc(

Q  , W  , E     , R   , T   ,       /*|*/       Y  , U     , I   , O   , P   ,
A  , S  , D     , F   , G   ,       /*|*/       H  , J     , K   , L   , SCLN,
Z  , X  , C     , V   , B   ,       /*|*/       N  , M     , COMM, DOT , SLSH,
ESC, TAB, TO_LYR, BSPC, LSFT, LCTL, /*|*/ LALT, SPC, MO_PRG, MINS, QUOT, ENT

),

/* == PROG LAYER =========================================================== */
[PROG_LAYER] = GLAYOUT_kc(

EXLM, AT  , HASH, DOLLAR, PERCENT,       /*|*/       CIRC, 7   , 8 , 9  , ASTR,
LCBR, RCBR, QUOT, GRAVE , PIPE   ,       /*|*/       BSPC, 4   , 5 , 6  , PLUS,
LBRC, RBRC, LPRN, RPRN  , AMPR   ,       /*|*/       0   , 1   , 2 , 3  , BSLS,
ESC , INS , LGUI, BSPC  , LSFT   , LCTL, /*|*/ LALT, SPC , TRNS, __, DOT, EQL

) ,

/* == MOVEMENT LAYER ======================================================= */
[MOVEMENT_LAYER] = GLAYOUT_kc(

HOME   , MB2 , PGDN, PGUP, MB1 ,       /*|*/       __  , MB1 , MB3 , MB2 , DEL,
END    , LEFT, DOWN, UP  , RGHT,       /*|*/       MS_L, MS_D, MS_U, MS_R, INS,
F1     , F2  , F3  , F4  , F5  ,       /*|*/       WHL , WHD , WHU , WHR , CLR,
TO_BASE, __  , LGUI, BSPC, LSFT, LCTL, /*|*/ LALT, AC0 , AC1 , AC2 , __  , ENT

),

/* == LAYER  LAYER ========================================================= */
[LAYER_LAYER] = GLAYOUT_kc(
__     , __, __    , TO_RGB, __  ,       /*|*/       __, __, __, __, __,
__     , __, __    , __    , __  ,       /*|*/       __, __, __, __, __,
__     , __, __    , __    , RST ,       /*|*/       __, __, __, __, __,
TO_BASE, __, TO_MVM, __    , LSFT, LCTL, /*|*/ LALT, __, __, __, __, __
) ,

[RGB_LAYER] = GLAYOUT(
RGB_TOG         , RGB_M_SW, XX, RGB_M_R, XX     ,          /*|*/          XX      , XX, XX     , XX, RGB_M_B,
RGB_MODE_FORWARD, RGB_SAI , XX, XX     , RGB_M_G,          /*|*/          RGB_HUI , XX, RGB_M_K, XX, XX,
XX              , RGB_M_X , XX, RGB_VAI, RGB_M_B,          /*|*/          RGB_M_SN, XX, XX     , XX, XX,
TO(BASE)        , XX      , XX, XX     , KC_LSFT, KC_LCTL, /*|*/ KC_LALT, XX      , XX, XX     , XX, XX
),


};
