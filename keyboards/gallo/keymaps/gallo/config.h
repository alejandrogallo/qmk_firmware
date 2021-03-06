// mouse settings
#define MOUSEKEY_DELAY      10
#define MOUSEKEY_INTERVAL   30
#define MOUSEKEY_MAX_SPEED  4
#define MOUSEKEY_TIME_TO_MAX  10

#define MOUSEKEY_WHEEL_MAX_SPEED  1

#define GLAYOUT( \
  k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
  k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, \
  k20, k21, k22, k23, k24,           k25, k26, k27, k28, k29, \
  k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
{ \
{ k09, k08, k07, k06, k05, KC_NO, k04, k03, k02, k01, k00 }, \
{ k19, k18, k17, k16, k15, KC_NO, k14, k13, k12, k11, k10 }, \
{ k29, k28, k27, k26, k25, k36,   k24, k23, k22, k21, k20 }, \
{ k3b, k3a, k39, k38, k37, k35,   k34, k33, k32, k31, k30 } \
}

