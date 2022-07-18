/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _WORKMAN,
  _QWERTY,
  _L1,
  _L2,
  _ADJUST
};

enum preonic_keycodes {
  WORKMAN = SAFE_RANGE,
  QWERTY,
  L1,
  L2,
  BACKLIT
};


typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
    TD_MINS_EQL,
    TD_1_F1,
    TD_2_F2,
    TD_3_F3,
    TD_4_F4,
    TD_5_F5,
    TD_6_F6,
    TD_7_F7,
    TD_8_F8,
    TD_9_F9,
    TD_0_F10,
    TD_MINS_F11,
    TD_EQL_F12,
    // X_CTL,
    _1_F1,
    _2_F2,
    _3_F3,
    _4_F4,
    _5_F5,
    _6_F6,
    _7_F7,
    _8_F8,
    _9_F9,
    _10_F10,
    _11_F11,
    _12_F12,
    _MINS_EQL,
    // PUT OTHER TAPDANCE INSTANCES HERE,
};

td_state_t cur_dance(qk_tap_dance_state_t *state);


// ENCODER
bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
bool is_alt_shift_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.
// ---


// For the x tap dance. Put it here so it can be used in any keymap
// void x_finished(qk_tap_dance_state_t *state, void *user_data);
// void x_reset(qk_tap_dance_state_t *state, void *user_data);

// _1_F1
void _1_finished(qk_tap_dance_state_t *state, void *user_data);
void _1_reset(qk_tap_dance_state_t *state, void *user_data);
// _2_F2
void _2_finished(qk_tap_dance_state_t *state, void *user_data);
void _2_reset(qk_tap_dance_state_t *state, void *user_data);
// _3_F3
void _3_finished(qk_tap_dance_state_t *state, void *user_data);
void _3_reset(qk_tap_dance_state_t *state, void *user_data);
// _4_F4
void _4_finished(qk_tap_dance_state_t *state, void *user_data);
void _4_reset(qk_tap_dance_state_t *state, void *user_data);
// _5_F5
void _5_finished(qk_tap_dance_state_t *state, void *user_data);
void _5_reset(qk_tap_dance_state_t *state, void *user_data);
// _6_F6
void _6_finished(qk_tap_dance_state_t *state, void *user_data);
void _6_reset(qk_tap_dance_state_t *state, void *user_data);
// _7_F7
void _7_finished(qk_tap_dance_state_t *state, void *user_data);
void _7_reset(qk_tap_dance_state_t *state, void *user_data);
// _8_F8
void _8_finished(qk_tap_dance_state_t *state, void *user_data);
void _8_reset(qk_tap_dance_state_t *state, void *user_data);
// _9_F9
void _9_finished(qk_tap_dance_state_t *state, void *user_data);
void _9_reset(qk_tap_dance_state_t *state, void *user_data);
// _10_F10
void _10_finished(qk_tap_dance_state_t *state, void *user_data);
void _10_reset(qk_tap_dance_state_t *state, void *user_data);
// _11_F11
void _11_finished(qk_tap_dance_state_t *state, void *user_data);
void _11_reset(qk_tap_dance_state_t *state, void *user_data);
// _12_F12
void _12_finished(qk_tap_dance_state_t *state, void *user_data);
void _12_reset(qk_tap_dance_state_t *state, void *user_data);
// - =
void _me_finished(qk_tap_dance_state_t *state, void *user_data);
void _me_reset(qk_tap_dance_state_t *state, void *user_data);

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_MINS_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),

    [TD_1_F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [TD_2_F2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [TD_3_F3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [TD_4_F4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [TD_5_F5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
    [TD_6_F6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
    [TD_7_F7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
    [TD_8_F8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
    [TD_9_F9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
    [TD_0_F10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
    [TD_MINS_F11] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_F11),
    [TD_EQL_F12] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_F12),
    [_1_F1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _1_finished, _1_reset),
    [_2_F2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _2_finished, _2_reset),
    [_3_F3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _3_finished, _3_reset),
    [_4_F4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _4_finished, _4_reset),
    [_5_F5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _5_finished, _5_reset),
    [_6_F6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _6_finished, _6_reset),
    [_7_F7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _7_finished, _7_reset),
    [_8_F8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _8_finished, _8_reset),
    [_9_F9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _9_finished, _9_reset),
    [_10_F10] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _10_finished, _10_reset),
    [_11_F11] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _11_finished, _11_reset),
    [_12_F12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _12_finished, _12_reset),
    [_MINS_EQL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _me_finished, _me_reset),
};

// Add tap dance item to your keymap in place of a keycode
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     // ...
//     TD(TD_ESC_CAPS)
//     TD(TD_)
//     // ...
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Workman
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  1F1 |  2F2 |  3F3 |  4F4 |  5F5 |  6F6 |  7F7 |  8F8 |  9F9 |  0F10|  -+   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |EscCps|   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LSft:(|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |RSft:)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  [   |LGui:]| Alt  |L1:Tab| Space| Bksp |L2:Ent| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMAN] = LAYOUT_preonic_grid(
  KC_GRV,          TD(_1_F1),    TD(_2_F2),       TD(_3_F3),   TD(_4_F4),          TD(_5_F5),   TD(_6_F6),   TD(_7_F7),   TD(_8_F8),      TD(_9_F9), TD(_10_F10),TD(_MINS_EQL),
  KC_TAB,          KC_Q,         KC_D,            KC_R,        KC_W,               KC_B,        KC_J,        KC_F,        KC_U,           KC_P,        KC_SCLN,      KC_BSLS,
  TD(TD_ESC_CAPS), KC_A,         KC_S,            KC_H,        KC_T,               KC_G,        KC_Y,        KC_N,        KC_E,           KC_O,        KC_I,         KC_QUOT,
  KC_LSPO,         KC_Z,         KC_X,            KC_M,        KC_C,               KC_V,        KC_K,        KC_L,        KC_COMM,        KC_DOT,      KC_SLSH,      KC_RSPC,
  KC_LCTL,         KC_LBRC,      LGUI_T(KC_RBRC), KC_LALT,     LT(_L1,KC_TAB),     KC_SPC,      KC_BSPC,     LT(_L2,KC_ENT), KC_LEFT,     KC_DOWN,     KC_UP,        KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,   KC_SPC,  KC_SPC,  KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* L1
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |Num_Lk|  /   |  *   |  -   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Prev | Next |      |      |      |  7   |  8   |  9   |  +   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Mute | Play |      |      |      |  4   |  5   |  6   |  ,   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Vol- | Vol+ |      |      |      |  1   |  2   |  3   |  =   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  0   |  .   | Entr |      |
 * `-----------------------------------------------------------------------------------'
 */
[_L1] = LAYOUT_preonic_grid(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, TD(_12_F12),
  KC_NO,   KC_NO,   KC_MRWD, KC_MFFD,KC_NO,   KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,
  KC_NO,   KC_NO,   KC_MUTE, KC_MPLY,KC_NO,   KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PCMM, KC_NO,
  KC_NO,   KC_NO,   KC_VOLD, KC_VOLU,KC_NO,   KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P0,   KC_PDOT, KC_PENT, KC_NO
),

/* L2
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      | M_U  |      |      |      |      |Insert|Delete|      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | M_L  | M_D  | M_R  |      |      |      | Home | End  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | PgUp |PgDwn |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | M_Cl | M_RCl|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_L2] = LAYOUT_preonic_grid(
  RESET,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_MS_U,  KC_NO,    KC_NO,    KC_NO,    KC_INS,   KC_DEL,   KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,    KC_NO,    KC_HOME,  KC_END,   KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PGUP,  KC_PGDN,  KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_BTN1,  KC_BTN2,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  KC_NO, KC_NO,  _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    return encoder_update_user(index, clockwise);
}

// #ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
  // FIXME -- add platform recognition
  switch(get_highest_layer(layer_state))
  {
    case _WORKMAN:
      if (clockwise)
      {
        if(!is_alt_tab_active)
        {
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
      }
      else
      {
        if(!is_alt_tab_active)
        {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(S(KC_TAB));
      }
      break;
    case _L1:
      clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
      break;
    case _L2:
      // <>
      break;
    default:
      break;
  }
  
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case WORKMAN:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_WORKMAN);
          }
          return false;
          break;
        case L1:
          if (record->event.pressed) {
            layer_on(_L1);
            update_tri_layer(_L1, _L2, _ADJUST);
          }
          else{
            layer_off(_L1);
            update_tri_layer(_L1, _L2, _ADJUST);
          }
          break;
        case L2:
          if (record->event.pressed) {
            layer_on(_L2);
            update_tri_layer(_L1, _L2, _ADJUST);
          }
          else{
            layer_off(_L2);
            update_tri_layer(_L1, _L2, _ADJUST);
          }
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;


bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      unregister_code(KC_LSHIFT);
      is_alt_tab_active = false;
      is_alt_shift_tab_active = false;
    }
  }
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    default:
      return true;
  }
}


// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_tap_dance.md
/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */

// ----------
// Determine the tapdance state to return
// td_state_t cur_dance(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         else return TD_SINGLE_HOLD;
//     }

//     if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
//     else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
// }
// ----------

td_state_t cur_dance(qk_tap_dance_state_t *state)
{
    if (state->count == 1)
    {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    }
    else if (state->count == 2)
    {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3)
    {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
// static td_tap_t xtap_state = {
//     .is_press_action = true,
//     .state = TD_NONE
// };
static td_tap_t _1tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _2tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _3tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _4tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _5tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _6tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _7tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _8tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _9tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _10tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _11tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _12tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t _metap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// void x_finished(qk_tap_dance_state_t *state, void *user_data) {
//     xtap_state.state = cur_dance(state);
//     switch (xtap_state.state) {
//         case TD_SINGLE_TAP: register_code(KC_X); break;
//         case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
//         case TD_DOUBLE_TAP: register_code(KC_ESC); break;
//         // case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
//         // Last case is for fast typing. Assuming your key is `f`:
//         // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
//         // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
//         case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
//     }
// }
void _1_finished(qk_tap_dance_state_t *state, void *user_data) {
    _1tap_state.state = cur_dance(state);
    switch (_1tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_1); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_1); break;
        case TD_DOUBLE_TAP: register_code(KC_1); unregister_code(KC_1); register_code(KC_1); break;
        case TD_DOUBLE_HOLD: register_code(KC_F1); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_1); register_code(KC_1);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _1_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_1tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_1); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_1); break;
        case TD_DOUBLE_TAP: unregister_code(KC_1); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F1); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_1); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _1tap_state.state = TD_NONE;
}

void _2_finished(qk_tap_dance_state_t *state, void *user_data) {
    _2tap_state.state = cur_dance(state);
    switch (_2tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_2); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_2); break;
        case TD_DOUBLE_TAP: register_code(KC_2); unregister_code(KC_2); register_code(KC_2); break;
        case TD_DOUBLE_HOLD: register_code(KC_F2); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_2); register_code(KC_2);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _2_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_2tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_2); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_2); break;
        case TD_DOUBLE_TAP: unregister_code(KC_2); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F2); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_2); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _2tap_state.state = TD_NONE;
}

void _3_finished(qk_tap_dance_state_t *state, void *user_data) {
    _3tap_state.state = cur_dance(state);
    switch (_3tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_3); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_3); break;
        case TD_DOUBLE_TAP: register_code(KC_3); unregister_code(KC_3); register_code(KC_3); break;
        case TD_DOUBLE_HOLD: register_code(KC_F3); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_3); register_code(KC_3);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _3_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_3tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_3); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_3); break;
        case TD_DOUBLE_TAP: unregister_code(KC_3); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F3); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_3); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _3tap_state.state = TD_NONE;
}

void _4_finished(qk_tap_dance_state_t *state, void *user_data) {
    _4tap_state.state = cur_dance(state);
    switch (_4tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_4); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_4); break;
        case TD_DOUBLE_TAP: register_code(KC_4); unregister_code(KC_4); register_code(KC_4); break;
        case TD_DOUBLE_HOLD: register_code(KC_F4); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_4); register_code(KC_4);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _4_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_4tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_4); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_4); break;
        case TD_DOUBLE_TAP: unregister_code(KC_4); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F4); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_4); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _4tap_state.state = TD_NONE;
}

void _5_finished(qk_tap_dance_state_t *state, void *user_data) {
    _5tap_state.state = cur_dance(state);
    switch (_5tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_5); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_5); break;
        case TD_DOUBLE_TAP: register_code(KC_5); unregister_code(KC_5); register_code(KC_5); break;
        case TD_DOUBLE_HOLD: register_code(KC_F5); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_5); register_code(KC_5);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _5_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_5tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_5); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_5); break;
        case TD_DOUBLE_TAP: unregister_code(KC_5); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F5); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_5); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _5tap_state.state = TD_NONE;
}

void _6_finished(qk_tap_dance_state_t *state, void *user_data) {
    _6tap_state.state = cur_dance(state);
    switch (_6tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_6); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_6); break;
        case TD_DOUBLE_TAP: register_code(KC_6); unregister_code(KC_6); register_code(KC_6); break;
        case TD_DOUBLE_HOLD: register_code(KC_F6); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_6); register_code(KC_6);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _6_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_6tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_6); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_6); break;
        case TD_DOUBLE_TAP: unregister_code(KC_6); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F6); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_6); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _6tap_state.state = TD_NONE;
}

void _7_finished(qk_tap_dance_state_t *state, void *user_data) {
    _7tap_state.state = cur_dance(state);
    switch (_7tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_7); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_7); break;
        case TD_DOUBLE_TAP: register_code(KC_7); unregister_code(KC_7); register_code(KC_7); break;
        case TD_DOUBLE_HOLD: register_code(KC_F7); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_7); register_code(KC_7);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _7_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_7tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_7); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_7); break;
        case TD_DOUBLE_TAP: unregister_code(KC_7); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F7); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_7); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _7tap_state.state = TD_NONE;
}

void _8_finished(qk_tap_dance_state_t *state, void *user_data) {
    _8tap_state.state = cur_dance(state);
    switch (_8tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_8); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_8); break;
        case TD_DOUBLE_TAP: register_code(KC_8); unregister_code(KC_8); register_code(KC_8); break;
        case TD_DOUBLE_HOLD: register_code(KC_F8); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_8); register_code(KC_8);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _8_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_8tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_8); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_8); break;
        case TD_DOUBLE_TAP: unregister_code(KC_8); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F8); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_8); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _8tap_state.state = TD_NONE;
}

void _9_finished(qk_tap_dance_state_t *state, void *user_data) {
    _9tap_state.state = cur_dance(state);
    switch (_9tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_9); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_9); break;
        case TD_DOUBLE_TAP: register_code(KC_9); unregister_code(KC_9); register_code(KC_9); break;
        case TD_DOUBLE_HOLD: register_code(KC_F9); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_9); register_code(KC_9);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _9_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_9tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_9); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_9); break;
        case TD_DOUBLE_TAP: unregister_code(KC_9); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F9); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_9); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _9tap_state.state = TD_NONE;
}

void _10_finished(qk_tap_dance_state_t *state, void *user_data) {
    _10tap_state.state = cur_dance(state);
    switch (_10tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_0); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_0); break;
        case TD_DOUBLE_TAP: register_code(KC_0); unregister_code(KC_0); register_code(KC_0); break;
        case TD_DOUBLE_HOLD: register_code(KC_F10); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_0); register_code(KC_0);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _10_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_10tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_0); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_0); break;
        case TD_DOUBLE_TAP: unregister_code(KC_0); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F10); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_0); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _1tap_state.state = TD_NONE;
}

void _11_finished(qk_tap_dance_state_t *state, void *user_data) {
    _11tap_state.state = cur_dance(state);
    switch (_11tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_MINS); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_MINS); break;
        case TD_DOUBLE_TAP: register_code(KC_MINS); unregister_code(KC_MINS); register_code(KC_MINS); break;
        case TD_DOUBLE_HOLD: register_code(KC_F11); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_MINS); register_code(KC_MINS);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _11_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_11tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_MINS); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_MINS); break;
        case TD_DOUBLE_TAP: unregister_code(KC_MINS); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F11); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_MINS); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _11tap_state.state = TD_NONE;
}

void _12_finished(qk_tap_dance_state_t *state, void *user_data) {
    _12tap_state.state = cur_dance(state);
    switch (_12tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_PEQL); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_PEQL); break;
        case TD_DOUBLE_TAP: register_code(KC_PEQL); unregister_code(KC_PEQL); register_code(KC_PEQL); break;
        case TD_DOUBLE_HOLD: register_code(KC_F12); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_PEQL); register_code(KC_PEQL);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _12_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_12tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_PEQL); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_PEQL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_PEQL); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F12); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_PEQL); break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _12tap_state.state = TD_NONE;
}

void _me_finished(qk_tap_dance_state_t *state, void *user_data) {
    _metap_state.state = cur_dance(state);
    switch (_metap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_MINS); break;
        case TD_SINGLE_HOLD: register_code(KC_LSHIFT); register_code(KC_MINS); break;
        case TD_DOUBLE_TAP: register_code(KC_EQUAL); break;//unregister_code(KC_EQUAL); register_code(KC_EQUAL); break;
        case TD_DOUBLE_HOLD: register_code(KC_LSHIFT); register_code(KC_EQUAL); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_MINS); register_code(KC_MINS);
        case TD_TRIPLE_TAP: register_code(KC_F11); break;
        case TD_TRIPLE_HOLD: register_code(KC_F12); break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
}

void _me_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_metap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_MINS); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_MINS); break;
        case TD_DOUBLE_TAP: unregister_code(KC_EQUAL); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LSHIFT); unregister_code(KC_EQUAL); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_MINS); break;
        case TD_TRIPLE_TAP: unregister_code(KC_F11); break;
        case TD_TRIPLE_HOLD: unregister_code(KC_F12); break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    _metap_state.state = TD_NONE;
}

