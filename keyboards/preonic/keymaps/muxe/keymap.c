 /* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,\
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE
};

enum {
  TD_SHIFT_CAPS,
  TD_LALT_HANDSWAP,
  TD_RALT_HANDSWAP,
};

#define FN MO(_FUNCTION)
#define KC_VDR LCTL(LGUI(KC_RIGHT))
#define KC_VDL LCTL(LGUI(KC_LEFT))
#define MY_LALT TD(TD_LALT_HANDSWAP)
#define MY_RALT TD(TD_RALT_HANDSWAP)
#define MY_LSFT TD(TD_SHIFT_CAPS)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Menu | Win  | Alt  |Lower |  FN  | Space|Raise | AltG |  Del |  `   |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,   \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,   \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT ,\
  KC_LCTL, KC_APP,  KC_LGUI, KC_LALT, LOWER,   FN,      KC_SPC,  RAISE,   KC_RALT, KC_DEL,  KC_GRV,  KC_ENT     \
),

[_LOWER] = LAYOUT_preonic_grid( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_MPLY, KC_MUTE,  KC_BRID, KC_BRIU, KC_SLEP, KC_WAKE, _______,
  _______, KC_MINS, KC_4,    KC_5,    KC_6,    KC_MPRV, KC_MNXT,  KC_MINS, KC_EQL,  KC_MPLY, KC_MUTE, KC_BSLS,
  _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_VOLD, KC_VOLU,  KC_PIPE, KC_HASH, KC_PIPE, KC_BSLS, _______,
  _______, _______, _______, _______, _______, _______, KC_ENT,   _______, _______, KC_VOLD, KC_VOLU, _______
),

[_RAISE] = LAYOUT_preonic_grid( \
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F12,
  _______, KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_QUOT, KC_6,    KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, _______,
  _______, KC_DEL,  KC_BSPC, KC_LPRN, KC_RPRN, KC_DQT,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_RBRC, KC_GRV,
  _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_GRV,  KC_END,  KC_HASH, KC_VDL,  KC_VDR,  KC_PGDN, _______,
  _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, KC_VOLD, KC_VOLU, _______
),

[_FUNCTION] = LAYOUT_preonic_grid( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_TAB,  KC_CALC,KC_COMM, KC_DEL, KC_BSPC,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F13,  KC_F14,  KC_P7,   KC_P8,  KC_P9,   KC_PPLS, KC_BSPC,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F15,  KC_F16,  KC_P4,   KC_P5,  KC_P6,   KC_PMNS, KC_BSLS,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F17,  KC_F18,  KC_P1,   KC_P2,  KC_P3,   KC_PAST, _______,
  _______, _______, _______, _______, _______, _______, KC_NLCK, KC_P0,   KC_P0,  KC_PDOT, KC_PSLS, _______
),

[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, QWERTY,  _______, _______, _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};
