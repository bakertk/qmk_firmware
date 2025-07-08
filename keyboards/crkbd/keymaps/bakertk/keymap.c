/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, erither version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum layers {
    _MAIN = 0,
    _NAVNUM,
    _SYMBOLS,
    _GAMECHOICE,
    // _Splitgate,
    // _Destiny2,
    // _RocketLeague,
    // _Spiderheck,
    _Minecraft,
    // _Undefined,
};

enum custom_keycodes {
    WORKPROD = SAFE_RANGE,
    WORKNONPROD,
    GAMINGPC,
    ALT_TAB,
    SWITCHCPU,
     //ALT_SHIFT_TAB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAIN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_LALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LCTL, LT(1,KC_TAB),  KC_BSPC,     KC_SPC,   LT(2,KC_MINS), KC_RSFT
                                      //`--------------------------'  `--------------------------'

  ),

    [_NAVNUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, LCTL(KC_LSFT), LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_RIGHT), KC_LCBR, KC_RCBR,  KC_7,    KC_8,    KC_9,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_LSFT, KC_LEFT,  KC_UP,  KC_RGHT, KC_LBRC,                       KC_RBRC,  KC_4,    KC_5,    KC_6,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, LCTL(KC_LEFT), KC_DOWN, LCTL(KC_RGHT), KC_LPRN,           KC_RPRN,  KC_1,    KC_2,    KC_3,  KC_PSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, XXXXXXX, XXXXXXX,    KC_LSFT,  KC_LCTL,  KC_0
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,  KC_EXLM,  KC_AT,  KC_HASH, KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, TO(3), KC_DEL,     XXXXXXX, XXXXXXX, LGUI(KC_L)
                                      //`--------------------------'  `--------------------------'
  ),

    [_GAMECHOICE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX,WORKPROD, GAMINGPC, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, TO(4),   XXXXXXX,                      XXXXXXX,WORKNONPROD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    TO(0), XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_Minecraft] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC, XXXXXXX, XXXXXXX,   KC_Q,  XXXXXXX,  XXXXXXX,                      KC_F3,  KC_F6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB,   KC_E,    KC_A,    KC_W,    KC_D,   XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX,  KC_S,  XXXXXXX,  XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, KC_LSFT, KC_SPC,      TO(0), XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),
};

//COMBOS
enum combo_events {
    ENTER,
    REFRESH,
    PRNTSCRN,
    BACKHOMED2,
    BACKHOMERL,
    CAPS,
    ENTER2,
    ALTTAB,
    QS_HOME,
    //QS_MINE,
    //ALTSHFTTAB,
  };

const uint16_t PROGMEM enter[] =            {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM bangit[] =           {KC_BSPC, KC_SPC, COMBO_END};
const uint16_t PROGMEM snagit[] =           {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM homewardboundD2[] =  {KC_2, KC_Q, KC_Z, KC_E, COMBO_END};
const uint16_t PROGMEM homewardboundRL[] =  {KC_NO, KC_TAB, KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM capital[] =          {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM enter2[] =           {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM alttab[] =           {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM quickswitch_home[] = {KC_P, KC_EQL, COMBO_END};

//const uint16_t PROGMEM altshfttab[] =       {KC_R, KC_T, COMBO_END};

combo_t key_combos[] = {
    [ENTER]         = COMBO(enter, KC_ENT),//COMBO_ACTION(enter),
    [REFRESH]       = COMBO(bangit, KC_F5),//COMBO_ACTION(bangit),
    [PRNTSCRN]      = COMBO(snagit, LCTL(S(KC_ENT))),//COMBO_ACTION(snagit),
    [BACKHOMED2]    = COMBO(homewardboundD2, TO(0)),//COMBO_ACTION(homewardbound),
    [BACKHOMERL]    = COMBO(homewardboundRL, TO(0)),
    [CAPS]          = COMBO(capital, KC_CAPS),
    [ENTER2]        = COMBO(enter2, KC_ENT),
    [ALTTAB]        = COMBO(alttab, ALT_TAB),
    [QS_HOME]        = COMBO(quickswitch_home, TG(4))
    //[ALTSHFTTAB]    = COMBO(altshfttab, KC_ENT),
};

 //MACROS
 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WORKPROD:
            if (record->event.pressed) {
                // when keycode WORKPROD is pressed
                SEND_STRING("Rennatrekab03210"SS_TAP(X_ENT));
                //SEND_STRING(SS_TAP(X_ENT));
                //tap_code(KC_ENT);
            }
            else {
                // when keycode WORKPROD is released

            }
            break;
        case WORKNONPROD:
            if (record->event.pressed) {
                // when keycode WORKNONPROD is pressed
                SEND_STRING("Rolyatrekab03210"SS_TAP(X_ENT));
                //SEND_STRING(SS_TAP(X_ENT));
                //tap_code(KC_ENT);
            }
            else {
                // when keycode WORKNONPROD is released

            }
            break;
        case GAMINGPC:
            if (record->event.pressed) {
                // when keycode GAMINGPC is pressed
                SEND_STRING("03210");
            }
            else {
                // when keycode GAMINGPC is released

            }
            break;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                 }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            }
            else {
                unregister_code(KC_TAB);
            }
            break;
        case SWITCHCPU:
            if (record->event.pressed) {
                //SEND_STRING(SS_TAP(X_LCTL) SS_DELAY(200) SS_TAP(X_LCTL) SS_DELAY(200) SS_TAP(X_ENT));
                tap_code(KC_LCTL);
                tap_code(KC_LCTL);
                tap_code(KC_ENT);
                //SEND_STRING(SS_TAP(X_RCTL));
                //SEND_STRING(SS_TAP(X_RCTL));
                //SEND_STRING(SS_TAP(X_ENT));
            }
            else {

            }
            break;
        /*
            case ALT_SHIFT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                 }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            }
            else {
                unregister_code(KC_TAB);
            }
            break;*/
        default:
            return true;
    }
    return true;
};

void matrix_scan_user(void) { // The very important timer.
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
  }

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    }
    return rotation;
}

static void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Main"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("NAVNUM"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("SYMBOLS"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("GAMECHOICE"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Minecraft"), false);
            break;
    }
}

char     key_name = ' ';
uint16_t last_keycode;
uint8_t  last_row;
uint8_t  last_col;

static const char PROGMEM code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

static void set_keylog(uint16_t keycode, keyrecord_t *record) {
    // save the row and column (useful even if we can't find a keycode to show)
    last_row = record->event.key.row;
    last_col = record->event.key.col;

    key_name     = ' ';
    last_keycode = keycode;
    if (IS_QK_MOD_TAP(keycode)) {
        if (record->tap.count) {
            keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
        } else {
            keycode = 0xE0 + biton(QK_MOD_TAP_GET_MODS(keycode) & 0xF) + biton(QK_MOD_TAP_GET_MODS(keycode) & 0x10);
        }
    } else if (IS_QK_LAYER_TAP(keycode) && record->tap.count) {
        keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    } else if (IS_QK_MODS(keycode)) {
        keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
    } else if (IS_QK_ONE_SHOT_MOD(keycode)) {
        keycode = 0xE0 + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0xF) + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0x10);
    }
    if (keycode > ARRAY_SIZE(code_to_name)) {
        return;
    }

    // update keylog
    key_name = pgm_read_byte(&code_to_name[keycode]);
}

static const char *depad_str(const char *depad_str, char depad_char) {
    while (*depad_str == depad_char)
        ++depad_str;
    return depad_str;
}

static void oled_render_keylog(void) {
    oled_write_char('0' + last_row, false);
    oled_write_P(PSTR("x"), false);
    oled_write_char('0' + last_col, false);
    oled_write_P(PSTR(", k"), false);
    const char *last_keycode_str = get_u16_str(last_keycode, ' ');
    oled_write(depad_str(last_keycode_str, ' '), false);
    oled_write_P(PSTR(":"), false);
    oled_write_char(key_name, false);
    oled_advance_page(true);
}

// static void render_bootmagic_status(bool status) {
//     /* Show Ctrl-Gui Swap options */
//     static const char PROGMEM logo[][2][3] = {
//         {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//         {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//     };
//     if (status) {
//         oled_write_ln_P(logo[0][0], false);
//         oled_write_ln_P(logo[0][1], false);
//     } else {
//         oled_write_ln_P(logo[1][0], false);
//         oled_write_ln_P(logo[1][1], false);
//     }
// }

__attribute__((weak)) void oled_render_logo(void) {
    // clang-format off
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    // clang-format on
    oled_write_P(crkbd_logo, false);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return process_record_user(keycode, record);
}
#endif // OLED_ENABLE
