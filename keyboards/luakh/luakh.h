#pragma once
#include<quantum_keycodes.h>

// LAYERS ====================================================================
enum Layers
  { BASE = 0
  , QWERTY_2
  , SYMBOLS
  , MOVEMENT
  , ADJUST
  , SHIFT
  };

enum CustomKeyCodes {
  KC_DAUMEN_L = SAFE_RANGE,
  KC_DAUMEN_R,
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
#define KC_G_ENT RGUI_T(KC_ENT)
#define KC_CTL_or_SLSH RCTL_T(KC_SLSH)
#define KC_G_SPC RGUI_T(KC_SPC)
#define KC_BT1_DOWN MT(KC_A, KC_MS_BTN1)

//#define KC_C_DAUM_R LCTL_T(KC_ESC)
//#define KC_M_DAUM_L LALT_T(KC_ENT)

// Home row
#define LHYPR_T(kc) MT(MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI, kc)
#define RHYPR_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, kc)

#define KC_H_GUI    RGUI_T(KC_H)
#define KC_M_GUI    RGUI_T(KC_M)
#define KC_V_GUI    RGUI_T(KC_V)
#define KC_Z_GUI    LGUI_T(KC_Z)
#define KC_SLSH_GUI RGUI_T(KC_SLSH)
#define KC_J_CTL    RCTL_T(KC_J)
#define KC_K_ALT    LALT_T(KC_K)
#define KC_L_SFT    RSFT_T(KC_L)
#define KC_SCLN_HPR RHYPR_T(KC_SCLN)

#define KC_LANGL KC_NUBS
#define KC_RANGL S(KC_NUBS)

#define KC_G_GUI LGUI_T(KC_G)
#define KC_K_GUI LGUI_T(KC_K)
#define KC_D_GUI LGUI_T(KC_D)
#define KC_F_CTL LCTL_T(KC_F)
#define KC_D_ALT LALT_T(KC_D)
#define KC_S_SFT RSFT_T(KC_S)
#define KC_A_HPR LHYPR_T(KC_A)

// symbols and such
#define KC_MO_SYMBS MO(SYMBOLS)
#define KC_MO_MVMNT MO(MOVEMENT)
#define KC_MO_SHIFT MO(SHIFT)

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

#define KC_TEST5 LM(QWERTY_2, MOD_LCTL)

//#define KC_M_ENT_GUI ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_M_ENT)

// QWERTY LAYER ============================================================
#define LUAKH_QWERTY_1 \
                                 Q, W, E, R, T, /*|*/ Y, U,    I,   O,    P
#define LUAKH_QWERTY_2 \
                                 A, S, D, F, G, /*|*/ H, J, K, L, SCLN
#define LUAKH_QWERTY_3 \
                                 Z_GUI, X, C, V, B, /*|*/ N, M, COMM, DOT, SLSH_GUI
#define LUAKH_QWERTY_4 \
                          BSP_MOV, LSFT, C_ESC, /*|*/ M_ENT, SPC, MO_SYMBS

// QWERTY2 LAYER ============================================================
#define LUAKH_QWERTY_2_1 LUAKH_QWERTY_1
#define LUAKH_QWERTY_2_2 LUAKH_QWERTY_2
#define LUAKH_QWERTY_2_3 LUAKH_QWERTY_3
#define LUAKH_QWERTY_2_4 \
    BSP_MOV, SPC, C_ESC, /*|*/ M_ENT, RSFT, MO_SYMBS

// SYMBOL LAYER ============================================================
#define \
LUAKH_SYMBOLS_1 EXLM, AT , TAB, DOLLAR , PIPE , /*|*/ DEL , 7, 8, 9, MINS
#define \
LUAKH_SYMBOLS_2 LCBR, RCBR, QUOT, GRAVE , BSLS, /*|*/ BSPC, 4, 5, 6, EQL
#define \
LUAKH_SYMBOLS_3 LBRC, RBRC, LPRN, RPRN  , AMPR, /*|*/ 0   , 1, 2, 3, ENT
#define \
LUAKH_SYMBOLS_4                NO, LSFT, C_ESC, /*|*/ M_ENT, SPC, MO_SYMBS

// MOVEMENT LAYER ==========================================================
#define LUAKH_MOVEMENT_1 \
             HOME,  MB2, PGDN, PGUP, MB1 , /*|*/ DEL , MB1 , MB3 , MB2,  DEL
#define LUAKH_MOVEMENT_2 \
              END, LEFT, DOWN,   UP, RGHT, /*|*/ MS_L, MS_D, MS_U, MS_R, INS
#define LUAKH_MOVEMENT_3 \
             _F1  , _F2  , _F3 , _F4, _F5, /*|*/ WHL , WHD , WHU ,  WHR, CLR
#define LUAKH_MOVEMENT_4 \
                    MO_MVMNT, LSFT, C_ESC, /*|*/ M_ENT, RCTL, TG_ADJ

// ADJUST LAYER ============================================================
#define LUAKH_ADJUST_1 \
              NO, LMOD, NO, NO, LTOG, /*|*/ NO , NO , NO , NO,  NO
#define LUAKH_ADJUST_2 \
                NO, NO, NO,   NO, NO, /*|*/ NO, NO, NO, NO, NO
#define LUAKH_ADJUST_3 \
             NO  , NO  , NO , NO, NO, /*|*/ NO , NO , NO ,  NO, NO
#define LUAKH_ADJUST_4 \
                          NO, NO, NO, /*|*/ NO, NO, TG_ADJ

// SHIFT LAYER ================================================================

#define KC_SQ LSFT(KC_Q)
#define KC_SW LSFT(KC_W)
#define KC_SEE LSFT(KC_E)
#define KC_SR LSFT(KC_R)
#define KC_ST LSFT(KC_T)
#define KC_SY LSFT(KC_Y)
#define KC_SU LSFT(KC_U)
#define KC_SI LSFT(KC_I)
#define KC_SO LSFT(KC_O)
#define KC_SOO LSFT(KC_P)
#define KC_SA LSFT(KC_A)
#define KC_SS LSFT(KC_S)
#define KC_SD LSFT(KC_D)
#define KC_SF LSFT(KC_F)
#define KC_SG LSFT(KC_G)
#define KC_SH LSFT(KC_H)
#define KC_SJ LSFT(KC_J)
#define KC_SK LSFT(KC_K)
#define KC_SL LSFT(KC_L)
#define KC_SSCLN LSFT(KC_SCLN)
#define KC_SZ LSFT(KC_Z)
#define KC_SX LSFT(KC_X)
#define KC_SC LSFT(KC_C)
#define KC_SV LSFT(KC_V)
#define KC_SB LSFT(KC_B)
#define KC_SN LSFT(KC_N)
#define KC_SM LSFT(KC_M)
#define KC_SCOMM LSFT(KC_COMM)
#define KC_SDOT LSFT(KC_DOT)
#define KC_SSLSH LSFT(KC_SLSH)

#define LUAKH_SHIFT_1 \
                         SQ, SW, SEE, SR, ST, /*|*/ SY, SU, SI, SO, SOO
#define LUAKH_SHIFT_2 \
                          SA, SS, SD, SF, SG, /*|*/ SH, SJ, SK, SL, SSCLN
#define LUAKH_SHIFT_3 \
                          SZ, SX, SC, SV, SB, /*|*/ SN, SM, SCOMM, SDOT, SSLSH
#define LUAKH_SHIFT_4 \
                              NO, LSFT, LCTL, /*|*/ M_ENT, RCTL, MO_SYMBS

// GENERAL HELPING MACROS =====================================================
#define LUAKH_GET_NAME(NAME, ROW) \
                                  \
  LUAKH ## _ ## NAME ## _ ## ROW

#define LUAKH_APP(FUN, ...) FUN(__VA_ARGS__)

// LUXURY KEYS ================================================================
//
// symbol layer: < and > are not really needed

