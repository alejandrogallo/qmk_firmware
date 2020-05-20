/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "gallo.h"
#include "pointing_device.h"
#include "joystick.h"

joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(D4, 0, 511, 1023), // 10 bit adc
    [1] = JOYSTICK_AXIS_IN(F4, 0, 504, 1023), // 10 bit adc
};
void pointing_device_task(void) {
  report_mouse_t currentReport;
  currentReport = pointing_device_get_report();
  currentReport.x = (int8_t)((joystick_status.axes[1] >> 4) & 0x00ff);
  currentReport.y = -(int8_t)((joystick_status.axes[0] >> 4) & 0x00ff);
  pointing_device_set_report(currentReport);
  pointing_device_send();
}
