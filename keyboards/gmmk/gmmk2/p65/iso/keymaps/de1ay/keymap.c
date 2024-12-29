/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
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
#include "keymap_dvorak_programmer.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum custom_layers {
    _QL,
    _QFL,
    _DPL,
    _DPSL,
    _DPFL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _QL: Qwerty Layer (Default Layer)
   */
[_QL] = LAYOUT_65_iso_blocker(
  KC_GRAVE, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_PGUP,
  KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,   KC_PGDN,
  KC_LSFT,  KC_BSPC,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_RCTL,
  KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(_QFL), KC_LEFT,  KC_DOWN,  KC_RGHT),

  /* Keymap _QFL: Qwerty Function Layer
   */
[_QFL] = LAYOUT_65_iso_blocker(
  PDF(_DPL), KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,   KC_F12,    _______,  KC_INS,
  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   KC_PSCR,  KC_SCRL,  KC_PAUS,             _______,
  KC_CAPS,   _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  _______,  _______,  _______,   _______,  _______,
  _______,   _______,  RM_HUEU,  RM_HUED,  RM_SPDD,  RM_SPDU,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,   KC_MPLY,  KC_MNXT,  _______,   RM_VALU,  _______,
  _______,   _______,  _______,                                QK_BOOT,                                 _______,  _______,  RM_PREV,   RM_VALD,  RM_NEXT),

  /* Keymap _DPL: Dvorak Programmer Layer
   */
[_DPL] = LAYOUT_65_iso_blocker(
  KC_DLR,    KC_PLUS,  KC_LBRC,  KC_LCBR,  KC_LPRN,  KC_AMPR,  KC_EQL,   KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_ASTR,  KC_EXLM,   KC_HASH,   KC_BSPC,  KC_DEL,
  KC_TAB,    KC_SCLN,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,   KC_AT,               KC_PGUP,
  KC_ESC,    KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,   KC_BSLS,   KC_ENT,   KC_PGDN,
  MO(_DPSL), KC_BSPC,  KC_QUOT,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,      MO(_DPSL), KC_UP,    KC_RCTL,
  KC_LCTL,   KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(_DPFL), KC_LEFT,   KC_DOWN,  KC_RGHT),

  /* Keymap _DPL: Dvorak Programmer Shift Layer
   */
[_DPSL] = LAYOUT_65_iso_blocker(
  KC_TILD,    KC_1,        KC_2,        KC_3,       KC_4,      KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_PERC,     KC_GRV,      _______,  _______,
  S(KC_TAB),  S(KC_SCLN),  S(KC_COMM),  S(KC_DOT),  S(KC_P),   S(KC_Y),  S(KC_F),  S(KC_G),  S(KC_C),  S(KC_R),  S(KC_L),  S(KC_SLSH),  KC_CIRC,               _______,
  _______,    S(KC_A),     S(KC_O),     S(KC_E),    S(KC_U),   S(KC_I),  S(KC_D),  S(KC_H),  S(KC_T),  S(KC_N),  S(KC_S),  S(KC_MINS),  S(KC_BSLS),  _______,  _______,
  _______,    _______,     S(KC_QUOT),  S(KC_Q),    S(KC_J),   S(KC_K),  S(KC_X),  S(KC_B),  S(KC_M),  S(KC_W),  S(KC_V),  S(KC_Z),     _______,     _______,  _______,
  _______,    _______,     _______,                                      _______,                                _______,  _______,     _______,     _______,  _______),

  /* Keymap _DPFL: Dvorak Programmer Function Layer
   */
[_DPFL] = LAYOUT_65_iso_blocker(
  PDF(_QL),  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    _______,  KC_INS,
  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  KC_SCRL,  KC_PAUS,             _______,
  TG(_DPSL), _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,
  _______,   _______,  RM_HUEU,  RM_HUED,  RM_SPDD,  RM_SPDU,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,   RM_VALU,  _______,
  _______,   _______,  _______,                                QK_BOOT,                                _______,  _______,  RM_PREV,   RM_VALD,  RM_NEXT)
};

