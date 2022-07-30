#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

enum layer_number {
    _WORKMAN = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _QWERTY,
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

    [TD_1_F1]     = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [TD_2_F2]     = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [TD_3_F3]     = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [TD_4_F4]     = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [TD_5_F5]     = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
    [TD_6_F6]     = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
    [TD_7_F7]     = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
    [TD_8_F8]     = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
    [TD_9_F9]     = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
    [TD_0_F10]    = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
    [TD_MINS_F11] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_F11),
    [TD_EQL_F12]  = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_F12),
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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* WORKMAN
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   | 1_F1 | 2_F2 | 3_F3 | 4_F4 | 5_F5 |                    | 6_F6 | 7_F7 | 8_F8 | 9_F9 | 0_F10|  -=  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   D  |   R  |   W  |   B  |                    |   J  |   F  |   U  |   P  |   ;  |  \   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |Esc/Ctrl| A  |   S  |   H  |   T  |   G  |-------.    ,-------|   Y  |   N  |   E  |   O  |   I  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShft(|   Z  |   X  |   M  |   C  |   V  |-------|    |-------|   K  |   L  |   ,  |   .  |   /  |RShft)|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |RAISE |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_WORKMAN] = LAYOUT(

        KC_GRV, TD(_1_F1), TD(_2_F2), TD(_3_F3), TD(_4_F4), TD(_5_F5), TD(_6_F6), TD(_7_F7), TD(_8_F8), TD(_9_F9), TD(_10_F10), TD(_MINS_EQL),

        KC_TAB, KC_Q, KC_D, KC_R, KC_W, KC_B, KC_J, KC_F, KC_U, KC_P, KC_SCLN, KC_BSLS,

        LCTL(TD(TD_ESC_CAPS)), KC_A, KC_S, KC_H, KC_T, KC_G, KC_Y, KC_N, KC_E, KC_O, KC_I, KC_QUOT,

        KC_LSPO, KC_Z, KC_X, KC_M, KC_C, KC_V, KC_LBRC, KC_RBRC, KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,

        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_BSPC, LT(_RAISE, KC_ENT), KC_BSPC, KC_RGUI),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_LOWER] = LAYOUT(

        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,

        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,

        _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,

        _______, _______, _______, _______, _______, _______, _______, _______

        ),
    /* RAISE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_RAISE] = LAYOUT(

        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,

        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX,

        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, KC_PLUS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,

        _______, _______, _______, _______, _______, _______, _______, _______

        ),
    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |RGB ON| HUE+ | SAT+ | VAL+ |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|RMODE | MODE | HUE- | SAT- | VAL- |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------`
     *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_ADJUST] = LAYOUT(

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,

        XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______

        ),
    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RGUI),
};

// TODO
// int RGB_current_mode;

// void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3){
//   if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2))
//   {
//     layer_on(layer3);
//   } else {
//     layer_off(layer3);
//   }
// }

// void matrix_init_user(void) {
//   #ifdef RGBLIGHT_ENABLE
//   RGB_current_mode = rgblight_config.mode;
//   #endif
// }

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
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