#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

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
                      KC_DEL,  LOWER,   KC_SPC,       KC_ENT,  RAISE,   KC_BSPC
  ),
  [_LOWER] = LAYOUT_split_3x5_3(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_CAPS, KC_HOME, KC_PGUP, KC_PGDN, KC_END,       KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_LCTL, KC_TILD, _______, _______, KC_LBRC,      KC_RBRC, KC_MINS, KC_EQL,  KC_PIPE, KC_DQT,
                      _______, _______, _______,      _______, _______, _______
  ),
  [_RAISE] = LAYOUT_split_3x5_3(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_TAB,  KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,      KC_PSCR, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, _______,      _______, _______, _______, KC_BSLS, KC_QUOT,
                      _______, _______, _______,      RM_TOGG, _______, RM_NEXT
  ),
  [_ADJUST] = LAYOUT_split_3x5_3(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12,  _______, _______, _______,      _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                      _______, _______, _______,      _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
