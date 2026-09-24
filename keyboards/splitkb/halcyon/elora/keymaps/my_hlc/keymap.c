#include QMK_KEYBOARD_H

enum layers {
    _DVORAK = 0,
    _QWERTY,
    _NAV,
    _SYM,
    _NUM,
    _FUNCTION,
    _ADJUST,
};

#define QWERTY   DF(_QWERTY)
#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NUM      MO(_NUM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

// My keys actual meaning
#define MKC_MINUS KC_SLSH
#define MKC_AA KC_LBRC
#define MKC_OE KC_QUOTE
#define MKC_AE KC_SCLN
#define MKC_DOT_COL KC_DOT
#define MKC_COM_SCL KC_COMMA
#define MKC_QUES S(KC_MINUS)
#define MKC_EXCL S(KC_1)
#define MKC_HASH S(KC_3)
#define MKC_AT ALGR(KC_2)
#define MKC_STAR S(KC_NUHS)
#define MKC_PERC S(KC_5)
#define MKC_AND S(KC_6)
#define MKC_PLUS KC_MINUS
#define MKC_EQ S(KC_0)
#define MKC_PIPE ALGR(KC_NUBS)
#define MKC_DOLLAR ALGR(KC_4)
#define MKC_EURO ALGR(KC_5)
#define MKC_POUND ALGR(KC_3)
// Need arrow keys

enum custom_keycodes {
    MKC_QUOTE = SAFE_RANGE,
    MKC_PAREN,
    MKC_BSPC,
    MKC_SQBR,
    MKC_CUBR,
    MKC_ANBR,
    MKC_SLSH,
    MKC_BKTK,
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
     KC_TAB , MKC_QUOTE, MKC_COM_SCL, MKC_DOT_COL,   KC_P,   KC_Y   ,                                KC_F   ,   KC_G ,  KC_C ,   KC_R ,  KC_L , MKC_BSPC,
     CTL_ESC, KC_A   ,  KC_O   ,  KC_E  ,   KC_U ,   KC_I,                                       KC_D   ,   KC_H ,  KC_T ,   KC_N ,  KC_S , KC_MCTL,
     KC_LSFT, MKC_MINUS,  KC_Q   ,  KC_J  ,   KC_K ,   KC_X, _______, _______,  _______, _______, KC_B   ,   KC_M ,  KC_W ,   KC_V ,  KC_Z , KC_RSFT,
                                 ADJUST, _______, KC_LGUI, KC_SPC , KC_ENT ,  NUM      , SYM    , KC_RGUI,   _______, KC_APP // KC_APP is essentially a right click but triggerable via keyboard
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
      _______, _______, MKC_HASH, MKC_SLSH, MKC_EXCL, MKC_AND,                                  MKC_BKTK, MKC_STAR, MKC_PERC, MKC_EQ, MKC_PLUS, _______,
      _______, MKC_AT , MKC_AE , MKC_OE , MKC_AA , MKC_QUES,                                    MKC_PIPE, MKC_PAREN, MKC_SQBR, MKC_CUBR, MKC_ANBR, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, MKC_SLSH, MKC_STAR, MKC_MINUS, MKC_PLUS, _______,                                     _______, MKC_EQ, _______, _______, _______, _______,
      _______,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , _______,
      _______, _______, MKC_POUND, MKC_DOLLAR, MKC_EURO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
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

bool process_custom_key(keyrecord_t* record, uint16_t normal_kc, uint16_t shift_kc) {
    if (record->event.pressed) {
        uint8_t mods = get_mods();
        uint8_t osm = get_oneshot_mods();
        bool is_shifted = (mods | osm) & MOD_MASK_SHIFT;

        uint16_t kc_to_register = is_shifted ? shift_kc : normal_kc;

        del_mods(MOD_MASK_SHIFT);
        // Consume oneshot shift mod if it was the cause of the shift being applied
        if (osm & MOD_MASK_SHIFT) {
            del_oneshot_mods(MOD_MASK_SHIFT);
        }

        register_code16(kc_to_register);

        // Restore mods
        set_mods(mods);
    } else {
        unregister_code16(normal_kc);
        unregister_code16(shift_kc);
    }

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MKC_BSPC:
            return process_custom_key(record, KC_BSPC, KC_DEL);
        case MKC_QUOTE:
            return process_custom_key(record, KC_BSLS, S(KC_2));
        case MKC_PAREN:
            return process_custom_key(record, S(KC_8), S(KC_9));
        case MKC_SQBR:
            return process_custom_key(record, ALGR(KC_8), ALGR(KC_9));
        case MKC_CUBR:
            return process_custom_key(record, ALGR(KC_7), ALGR(KC_0));
        case MKC_ANBR:
            return process_custom_key(record, KC_NUBS, S(KC_NUBS));
        case MKC_SLSH:
            return process_custom_key(record, S(KC_7), ALGR(KC_NUBS));
        case MKC_BKTK:
            // This is a back tick.
            // Since back tick is a dead key on a Danish keyboard,
            // you must press space afterwards to get the actualy key
            if (record->event.pressed) {
                tap_code16(S(KC_EQL));
                tap_code(KC_SPC);
            }
            return false;

        default:
            return true; // Let QMK handle all other keys normally
    }
}
