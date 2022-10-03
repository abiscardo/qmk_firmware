#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

enum layer {
  _WORKMAN = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  // _QWERTY,
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
    bool       is_press_action;
    td_state_t state;
} td_tap_t;


// Tap Dance declarations
enum {
    // X_CTL,
    _ESC_CAPS,
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
    _BSLS_PIPE,
    _APOS_QUOT,
    _COM_LT,
    _PER_GT,
    _COM_GT,
    _OP_SQ,
    _CL_SQ,
    _EQL_PLUS,
    _GRV_TILDE,
    _MINS_UNDER,
    _SEMI_COL,
    _SLSH_QM,
    // PUT OTHER TAPDANCE INSTANCES HERE,
};


td_state_t cur_dance(qk_tap_dance_state_t *state);

// _ESC_CAPS
void _esc_finished(qk_tap_dance_state_t *state, void *user_data);
void _esc_reset(qk_tap_dance_state_t *state, void *user_data);
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
// - _ = +
void _me_finished(qk_tap_dance_state_t *state, void *user_data);
void _me_reset(qk_tap_dance_state_t *state, void *user_data);
// \ |
void _bsls_finished(qk_tap_dance_state_t *state, void *user_data);
void _bsls_reset(qk_tap_dance_state_t *state, void *user_data);

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [_ESC_CAPS]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _esc_finished, _esc_reset),
    [_1_F1]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _1_finished, _1_reset),
    [_2_F2]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _2_finished, _2_reset),
    [_3_F3]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _3_finished, _3_reset),
    [_4_F4]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _4_finished, _4_reset),
    [_5_F5]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _5_finished, _5_reset),
    [_6_F6]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _6_finished, _6_reset),
    [_7_F7]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _7_finished, _7_reset),
    [_8_F8]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _8_finished, _8_reset),
    [_9_F9]       = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _9_finished, _9_reset),
    [_10_F10]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _10_finished, _10_reset),
    [_11_F11]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _11_finished, _11_reset),
    [_12_F12]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _12_finished, _12_reset),
    [_MINS_EQL]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _me_finished, _me_reset),
    [_BSLS_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, _bsls_finished, _bsls_reset),
    [_APOS_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DOUBLE_QUOTE),
    [_COM_LT] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_LEFT_ANGLE_BRACKET),
    [_PER_GT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_RIGHT_ANGLE_BRACKET),
    [_OP_SQ] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_BRACKET, KC_LEFT_CURLY_BRACE),
    [_CL_SQ] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT_BRACKET, KC_RIGHT_CURLY_BRACE),
    [_CL_SQ] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT_BRACKET, KC_RIGHT_CURLY_BRACE),
    [_EQL_PLUS]  = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),
    [_GRV_TILDE]  = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILDE),
    [_MINS_UNDER]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [_SEMI_COL]  = ACTION_TAP_DANCE_DOUBLE(KC_SEMICOLON, KC_COLON),
    [_SLSH_QM]  = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_QUESTION),
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* WORKMAN
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  =   |   1  |   2  |   3  |   4  |   5  |      |      |      |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |  Q   |   D  |   R  |   W  |   B  |      |      |      |   J  |   F  |   U  |   P  |   ;  |   \  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  Esc |  A   |   S  |   H  |   T  |   G  | Home |      |  End |   Y  |   N  |   E  |   O  |   I  |  '   |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |LShft(|   Z  |   X  |   M  |   C  |   V  |      |      |      |   K  |   L  |   <  |   >  |   /  |RShft)|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   `  | Ctrl |  Win |  Alt | Bspc |    Space    |      |    Bspc     | Enter|  Tab |   [  |  ]   |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_WORKMAN] = LAYOUT_ortho_5x14(
    TD(_EQL_PLUS),  TD(_1_F1) ,   TD(_2_F2) ,   TD(_3_F3) ,   TD(_4_F4) ,   TD(_5_F5) ,   KC_NO   ,          KC_NO  ,   TD(_6_F6)  ,  TD(_7_F7)  ,  TD(_8_F8) ,  TD(_9_F9)  ,  TD(_10_F10),    TD(_MINS_EQL) ,
    KC_TAB,         KC_Q   ,      KC_D,         KC_R   ,      KC_W   ,      KC_B   ,      KC_NO   ,          KC_NO  ,   KC_J   ,      KC_F   ,      KC_U   ,      KC_P   ,      TD(_SEMI_COL),  TD(_BSLS_PIPE),
    TD(_ESC_CAPS),  KC_A   ,      KC_S,         KC_H   ,      KC_T   ,      KC_G   ,      KC_HOME ,          KC_END ,   KC_Y   ,      KC_N   ,      KC_E   ,      KC_O,         KC_I,           TD(_APOS_QUOT) ,
    KC_LSPO,        KC_Z   ,      KC_X   ,      KC_M,         KC_C   ,      KC_V   ,      KC_NO   ,          KC_NO  ,   KC_K   ,      KC_L,         TD(_COM_LT) , TD(_PER_GT),  TD(_SLSH_QM),   KC_RSPC ,
    TD(_GRV_TILDE), KC_LCTL,      KC_LEFT_GUI , KC_LALT,      KC_BSPC,      KC_SPACE,     KC_SPACE,          KC_BSPC ,  KC_BSPC,      KC_ENT,       KC_TAB  ,     TD(_OP_SQ),   TD(_CL_SQ),     MO(_LOWER)
  ),

/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |RGB_TOG|      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |RGB_MODE_FORWARD|RGB_VAD|RGB_VAI|RGB_HUD|RGB_HUI|RGB_TOG|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |xxxxxx|
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,
    RGB_TOG, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , RGB_MODE_FORWARD, RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_TOG,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_TRNS
  ),

/* Raise
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   -  |   =  |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |ISO # |ISO / |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , KC_NUHS, KC_NUBS, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE
  ),

  [_ADJUST] = LAYOUT_ortho_5x14(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, _______, QK_BOOT  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,  _______,
    _______, _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,     AG_SWAP, KC_NO,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  ),

  /* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  Ins |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   -  | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   =  | Esc  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Up| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  | Home | End  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Dn|Adjust| Ctrl | Alt  | GUI  |Lower |Space |      |Space |Raise | Left | Down |  Up  | Right|   \  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  // [_QWERTY] = LAYOUT_ortho_5x14(
  //   KC_INS,  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, KC_DEL ,
  //   KC_MINS, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,
  //   KC_EQL,  KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
  //   KC_PGUP, KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_HOME, KC_END ,
  //   KC_PGDN, _ADJUST, KC_LCTL, KC_LALT, KC_LGUI, _LOWER , KC_SPC ,     KC_SPC , _RAISE  ,KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_BSLS
  // ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
    case _LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case _RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case _ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    // case _QWERTY:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_QWERTY);
    //   }
    //   return false;
    //   break;
  }
  return true;
}



td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_TRIPLE_TAP;
        else
            return TD_TRIPLE_HOLD;
    } else
        return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
// static td_tap_t xtap_state = {
//     .is_press_action = true,
//     .state = TD_NONE
// };
static td_tap_t _esctap_state  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _1tap_state  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _2tap_state  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _3tap_state  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _4tap_state  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _5tap_state  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _6tap_state  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _7tap_state  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _8tap_state  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _9tap_state  = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _10tap_state = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _11tap_state = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _12tap_state = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _metap_state = {.is_press_action = true, .state = TD_NONE};
static td_tap_t _bsls_state = {.is_press_action = true, .state = TD_NONE};

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

void _esc_finished(qk_tap_dance_state_t *state, void *user_data) {
    _esctap_state.state = cur_dance(state);
    switch (_esctap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_ESC);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LCTL);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_CAPS);
            break;
        case TD_DOUBLE_HOLD:
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_ESC);
            register_code(KC_ESC);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_esctap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_ESC);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LCTL);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_CAPS);
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_ESC);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _esctap_state.state = TD_NONE;
}


void _1_finished(qk_tap_dance_state_t *state, void *user_data) {
    _1tap_state.state = cur_dance(state);
    switch (_1tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_1);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_1);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_1);
            unregister_code(KC_1);
            register_code(KC_1);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F1);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_1);
            register_code(KC_1);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _1_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_1tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_1);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_1);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_1);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F1);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_1);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _1tap_state.state = TD_NONE;
}

void _2_finished(qk_tap_dance_state_t *state, void *user_data) {
    _2tap_state.state = cur_dance(state);
    switch (_2tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_2);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_2);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_2);
            unregister_code(KC_2);
            register_code(KC_2);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F2);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_2);
            register_code(KC_2);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _2_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_2tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_2);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_2);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_2);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F2);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_2);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _2tap_state.state = TD_NONE;
}

void _3_finished(qk_tap_dance_state_t *state, void *user_data) {
    _3tap_state.state = cur_dance(state);
    switch (_3tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_3);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_3);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_3);
            unregister_code(KC_3);
            register_code(KC_3);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F3);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_3);
            register_code(KC_3);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _3_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_3tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_3);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_3);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_3);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F3);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_3);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _3tap_state.state = TD_NONE;
}

void _4_finished(qk_tap_dance_state_t *state, void *user_data) {
    _4tap_state.state = cur_dance(state);
    switch (_4tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_4);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_4);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_4);
            unregister_code(KC_4);
            register_code(KC_4);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F4);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_4);
            register_code(KC_4);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _4_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_4tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_4);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_4);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_4);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F4);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_4);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _4tap_state.state = TD_NONE;
}

void _5_finished(qk_tap_dance_state_t *state, void *user_data) {
    _5tap_state.state = cur_dance(state);
    switch (_5tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_5);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_5);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_5);
            unregister_code(KC_5);
            register_code(KC_5);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F5);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_5);
            register_code(KC_5);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _5_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_5tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_5);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_5);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_5);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F5);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_5);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _5tap_state.state = TD_NONE;
}

void _6_finished(qk_tap_dance_state_t *state, void *user_data) {
    _6tap_state.state = cur_dance(state);
    switch (_6tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_6);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_6);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_6);
            unregister_code(KC_6);
            register_code(KC_6);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F6);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_6);
            register_code(KC_6);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _6_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_6tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_6);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_6);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_6);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F6);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_6);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _6tap_state.state = TD_NONE;
}

void _7_finished(qk_tap_dance_state_t *state, void *user_data) {
    _7tap_state.state = cur_dance(state);
    switch (_7tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_7);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_7);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_7);
            unregister_code(KC_7);
            register_code(KC_7);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F7);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_7);
            register_code(KC_7);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _7_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_7tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_7);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_7);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_7);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F7);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_7);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _7tap_state.state = TD_NONE;
}

void _8_finished(qk_tap_dance_state_t *state, void *user_data) {
    _8tap_state.state = cur_dance(state);
    switch (_8tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_8);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_8);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_8);
            unregister_code(KC_8);
            register_code(KC_8);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F8);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_8);
            register_code(KC_8);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _8_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_8tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_8);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_8);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_8);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F8);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_8);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _8tap_state.state = TD_NONE;
}

void _9_finished(qk_tap_dance_state_t *state, void *user_data) {
    _9tap_state.state = cur_dance(state);
    switch (_9tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_9);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_9);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_9);
            unregister_code(KC_9);
            register_code(KC_9);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F9);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_9);
            register_code(KC_9);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _9_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_9tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_9);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_9);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_9);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F9);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_9);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _9tap_state.state = TD_NONE;
}

void _10_finished(qk_tap_dance_state_t *state, void *user_data) {
    _10tap_state.state = cur_dance(state);
    switch (_10tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_0);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_0);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_0);
            unregister_code(KC_0);
            register_code(KC_0);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F10);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_0);
            register_code(KC_0);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _10_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_10tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_0);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_0);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_0);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F10);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_0);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _1tap_state.state = TD_NONE;
}

void _11_finished(qk_tap_dance_state_t *state, void *user_data) {
    _11tap_state.state = cur_dance(state);
    switch (_11tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_MINS);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_MINS);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_MINS);
            unregister_code(KC_MINS);
            register_code(KC_MINS);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F11);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_MINS);
            register_code(KC_MINS);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _11_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_11tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_MINS);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_MINS);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_MINS);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F11);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_MINS);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _11tap_state.state = TD_NONE;
}

void _12_finished(qk_tap_dance_state_t *state, void *user_data) {
    _12tap_state.state = cur_dance(state);
    switch (_12tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_PEQL);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_PEQL);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_PEQL);
            unregister_code(KC_PEQL);
            register_code(KC_PEQL);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_F12);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_PEQL);
            register_code(KC_PEQL);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _12_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_12tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_PEQL);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_PEQL);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_PEQL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_F12);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_PEQL);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _12tap_state.state = TD_NONE;
}

void _me_finished(qk_tap_dance_state_t *state, void *user_data) {
    _metap_state.state = cur_dance(state);
    switch (_metap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_MINS);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_MINS);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_EQUAL);
            break; // unregister_code(KC_EQUAL); register_code(KC_EQUAL); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_EQUAL);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_MINS);
            register_code(KC_MINS);
        case TD_TRIPLE_TAP:
            register_code(KC_F11);
            break;
        case TD_TRIPLE_HOLD:
            register_code(KC_F12);
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _me_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_metap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_MINS);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_MINS);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_EQUAL);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_EQUAL);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_MINS);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_F11);
            break;
        case TD_TRIPLE_HOLD:
            unregister_code(KC_F12);
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _metap_state.state = TD_NONE;
}

void _bsls_finished(qk_tap_dance_state_t *state, void *user_data) {
    _bsls_state.state = cur_dance(state);
    switch (_bsls_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_BSLS);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_BSLS);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_F12);
            break; // unregister_code(KC_EQUAL); register_code(KC_EQUAL); break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LSHIFT);
            register_code(KC_EQUAL);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_BSLS);
            register_code(KC_BSLS);
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
}

void _bsls_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (_bsls_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_BSLS);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_BSLS);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_F12);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LSHIFT);
            unregister_code(KC_EQUAL);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_BSLS);
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_TRIPLE_HOLD:
            break;
        case TD_NONE:
            break;
        case TD_UNKNOWN:
            break;
    }
    _bsls_state.state = TD_NONE;
}