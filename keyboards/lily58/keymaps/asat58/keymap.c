 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
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


extern uint8_t is_master;

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                             KC_LGUI, KC_LALT,LOWER, KC_SPC,   KC_ENT,   RAISE,   KC_BSPC, KC_RALT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |KC_GRV|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |PrScr |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | F11  | F12  |      |      |      |                    |DELETE|  HOME|END   |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|  Left| Down | Up   |Right |   {  |  }   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|  INS |PGUP  |PGDOWN|      |   |  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_PSCR,
  _______, KC_F11,  KC_F12,  _______, _______, _______,                   KC_DELETE,KC_HOME,  KC_END,  XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______,                   KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT, KC_LCBR, KC_RCBR,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_INS ,  KC_PGDOWN,KC_PGUP, XXXXXXX, KC_PIPE, KC_BSLS,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |KC_GRV|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |PrScr |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | F11  | F12  |      |      |      |                    |DELETE|  HOME|END   |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------.    ,-------|  Left| Down | Up   |Right |   {  |  }   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |      |      |      |      |      |-------|    |-------|  INS |PGUP  |PGDOWN|      |   |  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_PSCR,
  _______, KC_F11,  KC_F12,  _______, _______, _______,                     KC_DELETE,KC_HOME,  KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, 
  _______, _______, _______, _______, _______, _______,                     KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT, KC_LCBR, KC_RCBR,
  _______, _______, _______, _______, _______, _______,  _______, _______,  KC_INS ,  KC_PGDOWN,KC_PGUP, XXXXXXX, KC_PIPE, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CAPS  |      |      |      |      |      |-------.    ,-------|      |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   0  |   +  |Enter |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P7,  KC_P8,  KC_P9,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P4,  KC_P5,  KC_P6,  XXXXXXX, XXXXXXX,
  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P1,  KC_P2,  KC_P3,  XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0, KC_PPLS, KC_ENT, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, _______, _______, _______
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

#include "bongo.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
}


void render_layer_state(void) {
    static const char PROGMEM raise [] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0xb8, 0xb8, 0x7c, 0x7c, 0xfe, 0xfe, 0xff, 
        0xff, 0xfe, 0xfe, 0x7c, 0x7c, 0xb8, 0xb8, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x2a, 0x2a, 0x44, 0x44, 0x88, 0x88, 0x11, 
        0x11, 0x88, 0x88, 0x44, 0x44, 0x2a, 0x2a, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    };

    static const char PROGMEM default_layer [] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0xa8, 0xa8, 0xc4, 0xc4, 0x82, 0x82, 0x01, 
        0x01, 0x82, 0x82, 0xc4, 0xc4, 0xa8, 0xa8, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x2b, 0x2b, 0x47, 0x47, 0x8f, 0x8f, 0x1f, 
        0x1f, 0x8f, 0x8f, 0x47, 0x47, 0x2b, 0x2b, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    static const char PROGMEM lower [] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0xa8, 0xa8, 0x44, 0x44, 0x82, 0x82, 0x01, 
        0x01, 0x82, 0x82, 0x44, 0x44, 0xa8, 0xa8, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x3a, 0x3a, 0x7c, 0x7c, 0xf8, 0xf8, 0xf1, 
        0xf1, 0xf8, 0xf8, 0x7c, 0x7c, 0x3a, 0x3a, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    static const char PROGMEM adj [] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0xb8, 0xb8, 0x7c, 0x7c, 0xfe, 0xfe, 0xff, 
        0xff, 0xfe, 0xfe, 0x7c, 0x7c, 0xb8, 0xb8, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x3b, 0x3b, 0x77, 0x77, 0xee, 0xee, 0xdd, 
        0xdd, 0xee, 0xee, 0x77, 0x77, 0x3b, 0x3b, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    };

    static const char PROGMEM undef [] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0xa8, 0xa8, 0x44, 0x44, 0x82, 0x82, 0x01, 
        0x01, 0x82, 0x82, 0x44, 0x44, 0xa8, 0xa8, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x2a, 0x2a, 0x44, 0x44, 0x88, 0x88, 0x11, 
        0x11, 0x88, 0x88, 0x44, 0x44, 0x2a, 0x2a, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_raw_P(default_layer, sizeof(default_layer));
            break;
        case _LOWER:
            oled_write_raw_P(lower, sizeof(lower));
            break;
        case _RAISE:
            oled_write_raw_P(raise, sizeof(raise));
            break;
        case _ADJUST:
            oled_write_raw_P(adj, sizeof(adj));
            break;
        default:
            oled_write_raw_P(undef, sizeof(undef));
    }
}

void render_mod_status(uint8_t modifiers, bool caps_state) {
    oled_write_P(PSTR("^"), caps_state);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_space(void) {
    oled_write_ln_P(PSTR(""), false);
}

void render_status_main(void) {
    // Show keyboard layout
    render_space();
    render_mod_status(get_mods(), host_keyboard_led_state().caps_lock);
    render_space();
    render_layer_state();
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status_main(); 
  } else {
    render_bongo_cat();
  }
    return false;
}

#endif // OLED_ENABLE
