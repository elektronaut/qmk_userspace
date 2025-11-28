// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"

// Layers
enum layers { _COLEMAK_DH = 0, _QWERTY, _EXT, _SYM, _NUMP };

#define COLEMAK DF(_COLEMAK_DH)
#define QWERTY DF(_QWERTY)
#define EXT MO(_EXT)
#define SYM MO(_SYM)
#define NUMP MO(_NUMP)

// Custom keycodes
#define TAB_NUMP LT(_NUMP, KC_TAB)
#define ENT_NUMP LT(_NUMP, KC_ENT)

enum custom_keycodes {
    DIRED = SAFE_RANGE,
    HM_INDIC,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH-NO
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |CapsLock|   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   Å  |   Æ    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  LCtrl |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |   Ø    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |LayLok|QWRTY |  |      |      |   K  |   H  |   ,  |   .  |  -   |   ¨    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LAlt | LGUI | Ext  | Space|Tab/  |  |Enter/| Bksp | Sym  | RGUI | RAlt |
 *                        |      |      |      |      | Nump |  | Nump |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT_elora_hlc(
      KC_ESC,  KC_1,         KC_2,         KC_3,         KC_4,         KC_5,                                       KC_6, KC_7,         KC_8,         KC_9,         KC_0,         XXXXXXX,
      KC_CAPS, KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                                       KC_J, KC_L,         KC_U,         KC_Y,         NO_ARNG,      NO_AE,
      KC_LCTL, LALT_T(KC_A), LGUI_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,                                       KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RGUI_T(KC_I), RALT_T(KC_O), NO_OSTR,
      KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_D,         KC_V, QK_LLCK, QWERTY,   XXXXXXX,  XXXXXXX, KC_K, KC_H,         KC_COMM,      KC_DOT,       NO_MINS,      NO_DIAE,
                                           KC_LALT,      KC_LGUI,      EXT,  KC_SPC,  TAB_NUMP, ENT_NUMP, KC_BSPC, SYM,  KC_RGUI,      KC_RALT,
      KC_MUTE, KC_NO,        KC_NO,        KC_NO,        KC_NO,                                                          KC_MUTE,      KC_NO,        KC_NO,        KC_NO,        KC_NO
    ),

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |CapsLock|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  LCtrl |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ø  |   Æ    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |LayLok|CMKDH |  |      |      |   N  |   M  |   ,  |   .  |  -   |   ¨    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LAlt | LGUI | Ext  | Space|Tab/  |  |Enter/| Bksp | Sym  | RGUI | RAlt |
 *                        |      |      |      |      | Nump |  | Nump |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_QWERTY] = LAYOUT_elora_hlc(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
      KC_CAPS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    NO_ARNG,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    NO_OSTR, NO_AE,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    QK_LLCK, COLEMAK, XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_MINS, NO_DIAE,
                                 KC_LALT, KC_LGUI, EXT,     KC_SPC,  TAB_NUMP,ENT_NUMP,KC_BSPC, SYM,     KC_RGUI, KC_RALT,
      KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                         KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

/*
 * Extend Layer: Navigation, media, underglow
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | CapsWrd|      |M Prev|M Play|M Next| VolUp|                              | PgUp | Home |   ↑  | End  |Insert| PrtSc  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LAlt | LGUI | LCtrl|LShift| VolDn|                              | PgDn |  ←   |   ↓  |   →  |Delete| ScLck  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |VolMut|      |      |  |      |      |      |      | dired|      |  F12 | Pause  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_EXT] = LAYOUT_elora_hlc(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      CW_TOGG, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  KC_PSCR,
      XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, KC_VOLD,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_SCRL,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, _______, _______, _______, _______, XXXXXXX, XXXXXXX, DIRED,   XXXXXXX, KC_F12,  KC_PAUSE,
                                 _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______,
      _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  ~   |  <   |  (   |  $   |  \   |                              |   `  |  '   |  #   |  ?   |  ^   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   §    |  [   |  {   |  >   |  )   |  &   |                              |   *  |  "   |  /   |  =   |  %   |   `    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   £    |  €   |  ]   |  }   |  |   |  !   |      |      |  |      |      |   +  |  @   |  ;   |  :   |  _   |   ´    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | RGB  |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_SYM] = LAYOUT_elora_hlc(
      _______,    _______,    _______,    _______,    _______,    _______,                                           _______,    _______, _______, _______, _______, _______,
      XXXXXXX,    NO_TILD,    KC_GRV,     NO_LPRN,    S(NO_4),    S(ALGR(NO_7)),                                     NO_ACUT,    KC_NUBS, NO_HASH, NO_QUES, NO_CIRC, XXXXXXX,
      S(KC_NUBS), NO_LBRC,    S(NO_LBRC), S(KC_GRV),  NO_RPRN,    S(NO_6),                                           S(KC_NUHS), NO_DQUO, NO_SLSH, NO_EQL,  NO_PERC, NO_BSLS,
      ALGR(NO_3), ALGR(NO_4), NO_RBRC,    S(NO_RBRC), ALGR(NO_7), NO_EXLM,       _______, _______, _______, _______, NO_PLUS,    KC_NUHS, NO_SCLN, NO_COLN, NO_UNDS, NO_GRV,
                              _______,    _______,    XXXXXXX,    NO_UNDS,       _______, _______, _______, _______, _______,    _______,
      _______,    _______,    _______,    _______,    _______,                                                                   _______, _______, _______, _______, _______
    ),


/*
 * Numpad Layer: Numpad and function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  | F5   |                              | NLock|   7  |   8  |   9  |   =  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  | F10  |                              |   /  |   4  |   5  |   6  |   +  | Enter  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | F11  | F12  | F13  | F14  | F15  |      |      |  |      | HRow |   *  |   1  |   2  |   3  |   -  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |   ,  |   .  |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              | RGB  |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NUMP] = LAYOUT_elora_hlc(
      _______, _______,       _______,       _______,       _______,       _______,                                      _______, _______,      _______,      _______,      _______,         _______,
      _______, KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,                                        KC_NUM,  KC_7,         KC_8,         KC_9,         KC_PEQL,         XXXXXXX,
      _______, LALT_T(KC_F6), LGUI_T(KC_F7), LCTL_T(KC_F8), LSFT_T(KC_F9), KC_F10,                                       KC_PSLS, RSFT_T(KC_4), RCTL_T(KC_5), RGUI_T(KC_6), RALT_T(KC_PPLS), KC_PENT,
      _______, KC_F11,        KC_F12,        KC_F13,        KC_F14,        KC_F15,  _______, _______, _______, HM_INDIC, KC_PAST, KC_1,         KC_2,         KC_3,         KC_PMNS,         XXXXXXX,
                                             _______,       _______,       _______, _______, _______, _______, _______,  KC_0,    KC_PCMM,      KC_PDOT,
      RM_TOGG, _______,       _______,       _______,       _______,                                                              RM_TOGG,      _______,      _______,      _______,         _______
    ),
};


#if defined(ENCODER_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state = get_mods();

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _NUMP:
            // RGB Control
            if (mods_state & MOD_MASK_ALT) {
                clockwise ? rgb_matrix_step() : rgb_matrix_step_reverse();
            } else if (mods_state & MOD_MASK_GUI) {
                clockwise ? rgb_matrix_increase_speed() : rgb_matrix_decrease_speed();
            } else if (mods_state & MOD_MASK_CTRL) {
                clockwise ? rgb_matrix_increase_sat() : rgb_matrix_decrease_sat();
            } else if (mods_state & MOD_MASK_SHIFT) {
                clockwise ? rgb_matrix_increase_hue() : rgb_matrix_decrease_hue();
            } else {
                clockwise ? rgb_matrix_increase_val() : rgb_matrix_decrease_val();
            }
            break;

        /*
        case _NUMP:
            if (mods_state & MOD_MASK_CTRL) {
                clockwise ? tap_code(KC_BRIU) : tap_code(KC_BRID);
            } else if (mods_state & MOD_MASK_SHIFT) {
                clockwise ? tap_code(KC_MNXT) : tap_code(KC_MPRV);
            } else {
                clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
            }
            break;
        */

        case _EXT:
            clockwise ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
            break;

        default: {
            clockwise ? tap_code(MS_WHLU) : tap_code(MS_WHLD);
        }
    }

    return true;
}
#endif

/*
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU)  },
    [1] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [2] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [3] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [4] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
};
#endif
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DIRED:
            if (record->event.pressed) {
                // Send Ctrl+X, Ctrl+J for dired-jump
                SEND_STRING(SS_LCTL("x") SS_LCTL("j"));
            }
            return false;
        case HM_INDIC:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CUSTOM_home_row_indicators);
            }
            return false;
    }
    return true;
}
