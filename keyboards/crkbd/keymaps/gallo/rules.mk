
# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \


MOUSEKEY_ENABLE = yes

TAP_DANCE_ENABLE = no

#ifdef GALLO_JOYSTICK
JOYSTICK_ENABLE = yes
POINTING_DEVICE_ENABLE = yes # Generic Pointer, not as big as mouse keys hopefully.
RGBLIGHT_ENABLE = yes
#endif

RGBLIGHT_ENABLE = yes
