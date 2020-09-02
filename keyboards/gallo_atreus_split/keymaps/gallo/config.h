// mouse settings
#define MOUSEKEY_DELAY           10
#define MOUSEKEY_INTERVAL        30
#define MOUSEKEY_MAX_SPEED       10
#define MOUSEKEY_TIME_TO_MAX     10
#define MOUSEKEY_WHEEL_MAX_SPEED  1

#define GLAYOUT( \
  L00, L01, L02, L03, L04,           R00, R01, R02, R03, R04, \
  L05, L06, L07, L08, L09,           R05, R06, R07, R08, R09, \
  L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
  L16, L17, L18, L19, L20, L21, R16, R17, R18, R19, R20, R21  \
) \
{ \
  { L04, L03, L02, L01, L00, KC_NO }, \
  { L09, L08, L07, L06, L05, KC_NO }, \
  { L14, L13, L12, L11, L10, L15   }, \
  { L20, L19, L18, L17, L16, L21   }, \
{ R00  , R01, R02, R03, R04  ,KC_NO}, \
{ R05  , R06, R07, R08, R09  ,KC_NO}, \
{  R11, R12, R13, R14, R15   ,R10  }, \
{  R17, R18, R19, R20, R21   ,R16  }, \
}

#define GLAYOUT_kc( \
  L00, L01, L02, L03, L04,           R00, R01, R02, R03, R04, \
  L05, L06, L07, L08, L09,           R05, R06, R07, R08, R09, \
  L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
  L16, L17, L18, L19, L20, L21, R16, R17, R18, R19, R20, R21  \
) \
GLAYOUT( \
  KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04,                     KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, \
  KC_##L05, KC_##L06, KC_##L07, KC_##L08, KC_##L09,                     KC_##R05, KC_##R06, KC_##R07, KC_##R08, KC_##R09, \
  KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
  KC_##L16, KC_##L17, KC_##L18, KC_##L19, KC_##L20, KC_##L21, KC_##R16, KC_##R17, KC_##R18, KC_##R19, KC_##R20, KC_##R21  \
)

/*
{ L00  , L01, L02, L03, L04, KC_NO }, \
{ L05  , L06, L07, L08, L09, KC_NO }, \
{ L10  , L11, L12, L13, L14, L15   }, \
{ L16  , L17, L18, L19, L20, L21   }, \
{ KC_NO, R04, R03, R02, R01, R00   }, \
{ KC_NO, R09, R08, R07, R06, R05   }, \
{ R15  , R14, R13, R12, R11, R10   }, \
{ R21  , R20, R19, R18, R17, R16   }  \
*/
