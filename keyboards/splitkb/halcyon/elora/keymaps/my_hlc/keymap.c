#include QMK_KEYBOARD_H

enum layers {
    _DVORAK = 0,
    _QWERTY,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

#define QWERTY   DF(_QWERTY)
#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

// My keys actual meaning
#define MKC_MINUS KC_SLSH
#define MKC_AA KC_LBRC
#define MKC_OE KC_QUOTE
#define MKC_AE KC_SCLN

enum custom_keycodes {
    MKC_QUOTE = SAFE_RANGE,
    MKC_PAREN,
    MKC_BSPC,
    MKC_DOT_COL,
    MKC_COM_SCL,
};

// Special
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DVORAK] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                                      _______,   _______,   _______,   _______,  _______, _______ ,
     KC_TAB , MKC_AE ,  MKC_OE ,  MKC_AA ,   KC_P   ,   KC_Y   ,                                KC_F   ,   KC_G ,  KC_C ,   KC_R ,  KC_L , MKC_BSPC,
     CTL_ESC, KC_A   ,  KC_O   ,  KC_E  ,   KC_U ,   KC_I ,                                       KC_D   ,   KC_H ,  KC_T ,   KC_N ,  KC_S , CTL_MINS,
     KC_LSFT, _______,  KC_Q   ,  KC_J  ,   KC_K ,   KC_X , KC_LBRC, KC_CAPS,  FKEYS   , KC_RBRC, KC_B   ,   KC_M ,  KC_W ,   KC_V ,  KC_Z , KC_RSFT,
                                 ADJUST, _______, KC_LGUI, KC_SPC , KC_ENT ,  _______ , SYM    , KC_RGUI,   _______, KC_APP // KC_APP is essentially a right click but triggerable via keyboard
    ),

    [_QWERTY] = LAYOUT(
     KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,                                        KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , KC_BSPC,
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , MKC_AA ,
     CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,MKC_AE, MKC_OE,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                ADJUST , KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
    ),

    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
      _______, _______, _______, MKC_COM_SCL, MKC_DOT_COL, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                    _______, _______, _______, _______, _______, _______,
      _______, _______, _______, QWERTY , _______, _______,                                    _______, _______, _______, _______, _______, _______,
      _______, _______, _______, DVORAK , _______, _______,                                    RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

//// Layer template
//
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
//
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [1] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [2] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [3] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [4] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [5] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [6] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
};
#endif

// Unused with display and trackpad
#if defined (HALCYON_ENABLE)
const uint16_t left_halcyon_buttons[10][5] = {
    [_QWERTY] =     { KC_MUTE, _______, _______, _______, _______ },
    [_DVORAK] =     { _______, _______, _______, _______, _______ },
    [_NAV] =        { _______, _______, _______, _______, _______ },
    [_SYM] =        { _______, _______, _______, _______, _______ },
    [_FUNCTION] =   { _______, _______, _______, _______, _______ },
    [_ADJUST] =     { _______, _______, _______, _______, _______ }
};

const uint16_t right_halcyon_buttons[10][5] = {
    [_QWERTY] =     { KC_MUTE, _______, _______, _______, _______ },
    [_DVORAK] =     { _______, _______, _______, _______, _______ },
    [_NAV] =        { _______, _______, _______, _______, _______ },
    [_SYM] =        { _______, _______, _______, _______, _______ },
    [_FUNCTION] =   { _______, _______, _______, _______, _______ },
    [_ADJUST] =     { _______, _______, _______, _______, _______ }
};
#endif

void tap_key(uint16_t key) {
    tap_code16(key);
}

bool key_with_shift(keyrecord_t* record, uint16_t key, bool key_is_shifted, uint16_t shift_key, bool shift_key_is_shifted) {
    if (record->event.pressed) {
        // If a shift key is currently held down
        if (get_mods() & MOD_MASK_SHIFT) {
            if (shift_key_is_shifted) {
                tap_key(shift_key);
            } else {
                uint8_t current_mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                register_code16(shift_key);
                set_mods(current_mods);
            }
        } else {
            if (key_is_shifted) {
                register_code16(S(key));
            } else {
                register_code16(key);
            }
        }
    } else {
        unregister_code16(key);
    }

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MKC_BSPC:
            return key_with_shift(record, KC_BSPC, false, KC_DEL, false);
        case MKC_PAREN:
            return key_with_shift(record, KC_8, true, KC_9, true);
        case MKC_QUOTE:
            return key_with_shift(record, KC_BSLS, false, KC_2, true);
        case MKC_DOT_COL:
            return key_with_shift(record, KC_DOT, false, KC_SCLN, true);
        case MKC_COM_SCL:
            return key_with_shift(record, KC_COMMA, false, KC_SCLN, false);

        default:
            return true; // Let QMK handle all other keys normally
    }
}
