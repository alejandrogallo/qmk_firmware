#pragma once

// LAYERS ====================================================================
enum Layers
  { BASE = 0
  , SYMBOLS
  , MOVEMENT
  , ADJUST
  };

// KEYS ====================================================================
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
#define KC_TO_BASE TO(BASE)
#define KC_TG_ADJ TG(ADJUST)

// mod tabs
#define KC_C_ESC LCTL_T(KC_ESC)
#define KC_M_ENT LALT_T(KC_ENT)
#define KC_CTL_or_SLSH RCTL_T(KC_SLSH)
#define KC_G_SPC KC_SPC
#define KC_BT1_DOWN MT(KC_A, KC_MS_BTN1)

// Home row
#define LHYPR_T(kc) MT(MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI, kc)
#define RHYPR_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, kc)

#define KC_H_GUI    RGUI_T(KC_H)
#define KC_M_GUI    RGUI_T(KC_M)
#define KC_V_GUI    RGUI_T(KC_V)
#define KC_J_CTL    RCTL_T(KC_J)
#define KC_K_ALT    LALT_T(KC_K)
#define KC_L_SFT    RSFT_T(KC_L)
#define KC_SCLN_HPR RHYPR_T(KC_SCLN)

#define KC_LANGL KC_NUBS
#define KC_RANGL S(KC_NUBS)

#define KC_G_GUI LGUI_T(KC_G)
#define KC_F_CTL LCTL_T(KC_F)
#define KC_D_ALT LALT_T(KC_D)
#define KC_S_SFT RSFT_T(KC_S)
#define KC_A_HPR LHYPR_T(KC_A)

// symbols and such
#define KC_MO_SYMBS MO(SYMBOLS)
#define KC_MO_MVMNT MO(MOVEMENT)

#define TO_BASE KC_TO_BASE
#define KC_RST RESET
#define TO_MOVEMENT KC_TO_MOVEMENT
#define __ KC_NO

#define KC_RGBMF RGB_MODE_FORWARD

#define KC_MO_HYPR MO(_HPR)
//#define KC_MO_SUPER MO(_SUPER)
#define KC_BSP_MOV LT(MOVEMENT, KC_BSPC)

#define KC__F1 KC_F1
#define KC__F2 KC_F2
#define KC__F3 KC_F3
#define KC__F4 KC_F4
#define KC__F5 KC_F5

//#define KC_M_ENT_GUI ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_M_ENT)

// BASIC LAYERS ============================================================
#define LUAKH_QWERTY_1 \
                                 Q, W, E, R, T, /*|*/ Y, U,    I,   O,    P
#define LUAKH_QWERTY_2 \
                            A, S, D_ALT, F_CTL, G, /*|*/ H, J_CTL, K_ALT, L, SCLN
#define LUAKH_QWERTY_3 \
                                Z, X, C, V_GUI, B, /*|*/ N, M_GUI, COMM, DOT, SLSH
#define LUAKH_QWERTY_4 \
                         BSP_MOV, LSFT, C_ESC, /*|*/ M_ENT, G_SPC, MO_SYMBS

#define \
LUAKH_SYMBOLS_1 EXLM, AT , TAB, DOLLAR , PIPE , /*|*/ DEL , 7, 8, 9, MINS
#define \
LUAKH_SYMBOLS_2 LCBR, RCBR, QUOT, GRAVE , BSLS, /*|*/ BSPC, 4, 5, 6, EQL
#define \
LUAKH_SYMBOLS_3 LBRC, RBRC, LPRN, RPRN  , AMPR, /*|*/ 0   , 1, 2, 3, ENT
#define \
LUAKH_SYMBOLS_4          NO, LSFT, C_ESC, /*|*/ M_ENT, G_SPC, MO_SYMBS


#define LUAKH_MOVEMENT_1 \
             HOME,  MB2, PGDN, PGUP, MB1 , /*|*/ DEL , MB1 , MB3 , MB2,  DEL
#define LUAKH_MOVEMENT_2 \
              END, LEFT, DOWN,   UP, RGHT, /*|*/ MS_L, MS_D, MS_U, MS_R, INS
#define LUAKH_MOVEMENT_3 \
             _F1  , _F2  , _F3 , _F4, _F5, /*|*/ WHL , WHD , WHU ,  WHR, CLR
#define LUAKH_MOVEMENT_4 \
                    MO_MVMNT, LSFT, C_ESC, /*|*/ M_ENT, RCTL, TG_ADJ

#define LUAKH_ADJUST_1 \
              NO, LMOD, NO, NO, LTOG, /*|*/ NO , NO , NO , NO,  NO
#define LUAKH_ADJUST_2 \
                NO, NO, NO,   NO, NO, /*|*/ NO, NO, NO, NO, NO
#define LUAKH_ADJUST_3 \
             NO  , NO  , NO , NO, NO, /*|*/ NO , NO , NO ,  NO, NO
#define LUAKH_ADJUST_4 \
                          NO, NO, NO, /*|*/ NO, NO, TG_ADJ

// GENERAL HELPING MACROS =====================================================
#define LUAKH_GET_NAME(NAME, ROW) \
                                  \
  LUAKH ## _ ## NAME ## _ ## ROW

#define LUAKH_APP(FUN, ...) FUN(__VA_ARGS__)

// LUXURY KEYS ================================================================
//
// symbol layer: < and > are not really needed

