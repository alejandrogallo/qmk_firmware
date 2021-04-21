// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include <quantum.h>


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LUAKH_kc(QWERTY,
                     RST, NO, NO,          NO, NO, NO),

  [_SYMBS] = LUAKH_kc(SYMBOLS,
                      RST, NO, NO,          NO, NO, NO),

  [_MVMNT] = LUAKH_kc(MOVEMENT,
                      RST, NO, NO,          NO, NO, NO),

};
