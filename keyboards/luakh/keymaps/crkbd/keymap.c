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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LUAKH_kc(QWERTY,
                  ESC,          BSPC,
                  TAB,          QUOT,
                  NO,           ENT),

[QWERTY_2] = LUAKH_kc(QWERTY_2,
                      ESC,          BSPC,
                      TAB,          QUOT,
                      NO,           ENT),

[SYMBOLS] = LUAKH_kc(SYMBOLS,
                     ESC,          MINS,
                     LCTL,         PLUS,
                     LSFT,         EQL),

[MOVEMENT] = LUAKH_kc(MOVEMENT,
                      ENT,         ENT,
                      ENT,         ENT,
                      ENT,         ENT),

[ADJUST] = LUAKH_kc(ADJUST,
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
