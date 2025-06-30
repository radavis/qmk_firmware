#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    // _ADJUST,
};

// tap-toggle layers
#define RAISE TT(_RAISE)
#define LOWER TT(_LOWER)

// home-row mods
#define MT_A MT(MOD_LGUI, KC_A)
#define MT_S MT(MOD_LALT, KC_S)
#define MT_D MT(MOD_LSFT, KC_D)
#define MT_F MT(MOD_LCTL, KC_F)

#define MT_J MT(MOD_RCTL, KC_J)
#define MT_K MT(MOD_RSFT, KC_K)
#define MT_L MT(MOD_LALT, KC_L)
#define MT_SCLN MT(MOD_RGUI, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    MT_A,    MT_S,    MT_D,    MT_F,    KC_G,         KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                      KC_LGUI, LOWER,   KC_SPC,       KC_ENT,  RAISE,   KC_BSPC
  ),
  [_LOWER] = LAYOUT_split_3x5_3(
    KC_TAB,  KC_F7,   KC_F8,   KC_F9,   KC_F12,       KC_HASH, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN,
    KC_CAPS, KC_F4,   KC_F5,   KC_F6,   KC_F11,       KC_EQL,  KC_MINS, KC_UNDS, KC_DQUO, KC_QUOT,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F10,       _______, _______, _______, _______, KC_BSLS,
                      _______, _______, _______,      _______, _______, KC_DEL
  ),
  [_RAISE] = LAYOUT_split_3x5_3(
    KC_GRV,  KC_7,    KC_8,    KC_9,    KC_ASTR,      KC_PSCR, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_CAPS, KC_4,    KC_5,    KC_6,    KC_PLUS,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
    CW_TOGG, KC_1,    KC_2,    KC_3,    KC_MINS,      _______, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO,
                      _______, _______, KC_0,         _______, _______, _______
  ),
  // [_ADJUST] = LAYOUT_split_3x5_3(
  //   _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
  //                     _______, _______, _______,      _______, _______, _______
  // ),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }
