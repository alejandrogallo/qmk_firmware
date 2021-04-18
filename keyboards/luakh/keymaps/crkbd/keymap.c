#include QMK_KEYBOARD_H
#include <quantum.h>

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
#define LAYER_LAYER 3
#define _HPR 4
#define _SUPER 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LUAKH_kc(QWERTY,
                   ESC,          BSPC,
                   TAB,          QUOT,
                   NO,           ENT),

[_SYMBS] = LUAKH_kc(SYMBOLS,
                    ESC,          MINS,
                    LCTL,         PLUS,
                    LSFT,         EQL),

[_MVMNT] = LUAKH_kc(MOVEMENT,
                    ENT,         ENT,
                    ENT,         ENT,
                    ENT,         ENT),


/*[_SUPER] = LAYOUT_kc_super(*/
 /*ESC,         Q, W, E, R, T, [>|<] Y, U,    I,   O,    P, BSPC,*/
 /*TAB,         A, S, D, F, G, [>|<] H, J,    K,   L, SCLN, QUOT,*/
      /*NO, Z, X, C, V, B, [>|<] N, M, COMM, DOT, SLSH,  ENT,*/
           /*MO_SUPER, LSFT, C_ESC, [>|<] M_ENT, G_SPC, MO_HYPR*/
/*),*/

/*[_HPR] = LAYOUT_kc_hyper(*/
 /*ESC,         Q, W, E, R, T, [>|<] Y, U,    I,   O,    P, BSPC,*/
 /*TAB,         A, S, D, F, G, [>|<] H, J,    K,   L, SCLN, QUOT,*/
      /*NO, Z, X, C, V, B, [>|<] N, M, COMM, DOT, SLSH,  ENT,*/
           /*MO_HYPR, RST, C_ESC, [>|<] M_ENT, G_SPC, MO_HYPR*/
/*),*/


};
