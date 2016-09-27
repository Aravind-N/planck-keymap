#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP(
  ESC,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,   BSPC,
  TAB,  A,    S,    D,    F,    G,    H,    J,    K,    L,    ENT,
  LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT, RSFT,
  FN1, LCTL, LALT, LGUI,  SPC,  SPC,  RGUI,  RALT,  RCTL, FN2 ),
[1] = KEYMAP(
  GRV,     1,      2,     3,   4,   5,   6,    7,   8,   9,    0,  BSLS,
  CAPS,   F1,     F2,    F3,  F4,  F5,  F6, MINS, EQL,   LBRC,    SCLN,
  LSHIFT, F7,     F8,    F9,  F10, F11, F12,TRNS, TRNS,  SLSH, RSHIFT,
  TRNS,   MPRV,  MPLY, MNXT, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS ),
[2] = KEYMAP(
  TRNS,   TRNS, UP,   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, BSLS,
  TRNS,   LEFT, DOWN, RIGHT,TRNS, TRNS, INS,  HOME, PGUP, RBRC, QUOT,
  LSHIFT, VOLD, VOLU, MUTE, TRNS, TRNS, DEL,  END,  PGDN, TRNS, TRNS,
  TRNS,   FN29, FN30, FN31, TRNS, TRNS, TRNS, TRNS, PAUS, TRNS ),
};



const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),  // FN1
    [2] = ACTION_LAYER_MOMENTARY(2),  // FN2

    [10] = ACTION_MODS_KEY(MOD_LSFT, KC_1), // !
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_2), // @
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_3), // #
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_4), // $
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_5), // %
    [15] = ACTION_MODS_KEY(MOD_LSFT, KC_6), // ^
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_7), // &
    [17] = ACTION_MODS_KEY(MOD_LSFT, KC_8), // *
    [18] = ACTION_MODS_KEY(MOD_LSFT, KC_9), // (
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_0), // )
    
    [20] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS), // _
    [21] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL), // +
    [22] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV), // ~
    [23] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC), // {
    [24] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC), // }
    [25] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS), // |

    [26] = ACTION_MODS_KEY(MOD_LSFT | MOD_RSFT, KC_PAUSE),
    
    
    [29] = ACTION_BACKLIGHT_TOGGLE(),
    [30] = ACTION_BACKLIGHT_INCREASE(),
    [31] = ACTION_BACKLIGHT_DECREASE()
    
};
