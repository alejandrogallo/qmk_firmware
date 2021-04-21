#include QMK_KEYBOARD_H
#include <quantum.h>


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LUAKH_kc(QWERTY,
                              NO,          NO,
                     RST, NO, NO,          NO, NO, NO),

  [_SYMBS] = LUAKH_kc(SYMBOLS,
                               NO,          NO,
                      RST, NO, NO,          NO, NO, NO),

  [_MVMNT] = LUAKH_kc(MOVEMENT,
                               NO,          NO,
                      RST, NO, NO,          NO, NO, NO),

};

