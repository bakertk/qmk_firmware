/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
  #include "quantum.h"
  #include "oledImages.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

 enum layers {
    _MAIN = 0,
    _NAVNUM,
    _SYMBOLS,
    _GAMECHOICE,
    _Splitgate,
    _Destiny2,
    _RocketLeague,
    _Spiderheck,
    _Minecraft,
    _Undefined,
};

enum custom_keycodes {
    WORKPROD = SAFE_RANGE,
    WORKNONPROD,
    GAMINGPC,
    ALT_TAB,
    SWITCHCPU,
     //ALT_SHIFT_TAB,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
//#define SWITCHCPU  MT(KC_LCTL, KC_LCTL, KC_ENT)


// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

 //MACROS
 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WORKPROD:
            if (record->event.pressed) {
                // when keycode WORKPROD is pressed
                SEND_STRING("Rennatrekab13211"SS_TAP(X_ENT));
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
                SEND_STRING("Rolyatrekab13211"SS_TAP(X_ENT));
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


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: _MAIN
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC/` |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  + =   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |TAB/[3] |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LGUI   |   Z  |   X  |   C  |   V  |   B  | [ {  | Del  |  |CapsLk|  ] } |   N  |   M  | ,  < | . >  | /  ? |  -  _  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  Alt | Ctrl | Shift|Tab[1]| Bkspc|  | Space|   -  | Shift|SftTab|AltTab|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
[_MAIN] = LAYOUT(
            QK_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                                          KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL,
            LT(3,KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G,                                     KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
            KC_LGUI, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_DEL,                         SWITCHCPU, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
            KC_LALT, KC_LCTL, KC_LSFT, LT(1,KC_TAB), KC_BSPC,                               KC_SPC, LT(2,KC_MINS), KC_RSFT, LSFT(KC_TAB), ALT_TAB
        ),

[_NAVNUM] = LAYOUT(
            KC_NO, LCTL(KC_LSFT), LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_RIGHT), KC_LCBR,      KC_RCBR, KC_7, KC_8, KC_9, KC_NO, KC_NO,
            KC_NO, KC_LSFT, KC_LEFT, KC_UP, KC_RGHT, KC_LBRC,                               KC_RBRC, KC_4, KC_5, KC_6, KC_NO, KC_NO,
            KC_NO, KC_NO, LCTL(KC_LEFT), KC_DOWN, LCTL(KC_RGHT), KC_LPRN, KC_NO, KC_NO,     KC_NO, KC_NO, KC_RPRN, KC_1, KC_2, KC_3, KC_PSLS, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_LSFT, KC_LCTL, KC_0, KC_NO, KC_NO
        ),

[_SYMBOLS] = LAYOUT(
            KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                               KC_CIRC, KC_AMPR, KC_ASTR, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_NO, KC_NO, KC_NO, KC_PEQL, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, OSL(3), KC_DEL,                                            KC_NO, KC_NO, LGUI(KC_L), KC_NO, KC_NO
        ),

[_GAMECHOICE] = LAYOUT(
            KC_NO, KC_NO, KC_NO, KC_NO, TO(4), TO(5),                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_TRNS, KC_NO, KC_NO, KC_NO, TO(6), TO(7),                                     KC_NO, WORKPROD, GAMINGPC, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, TO(8), TO(9), KC_NO, KC_NO,                         KC_NO, WORKNONPROD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        ),

[_Splitgate] = LAYOUT(
            KC_ESC, KC_Z, KC_Q, KC_G, KC_E, KC_TAB,                                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_R, KC_A, KC_W, KC_D, KC_F,                                            bvvKC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_C, KC_V, KC_S, KC_3, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_F, KC_P, KC_SPC,                                               TO(0), KC_NO, KC_NO, KC_NO, KC_NO
        ),

[_Destiny2] = LAYOUT(
            KC_ESC, KC_2, KC_Q, KC_Z, KC_E, KC_TAB,                                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_LSFT, KC_A, KC_W, KC_D, KC_R,                                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_C, KC_V, KC_S, KC_3, KC_NO, KC_NO, KC_NO,                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_F, KC_P, KC_SPC,                                               TO(0), KC_NO, KC_NO, KC_NO, KC_NO
        ),

[_RocketLeague] = LAYOUT(
            KC_ESC, KC_NO, KC_TAB, KC_1, KC_2, KC_3,                                        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_A, KC_W, KC_D, KC_4,                                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_S, KC_NO, KC_NO, KC_NO, KC_NO,                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_LSFT, KC_R,                                             TO(0), KC_NO, KC_NO, KC_NO, KC_NO
        ),

[_Spiderheck] = LAYOUT(
            KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_LSFT, KC_A, KC_W, KC_D, KC_NO,                                        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_S, KC_NO, KC_NO, KC_NO, KC_NO,                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_LCTL, KC_SPC,                                           TO(0), KC_NO, KC_NO, KC_NO, KC_NO
        ),

[_Minecraft] = LAYOUT(
            KC_ESC, KC_NO, KC_NO, KC_Q, KC_E, KC_NO,                                       KC_F3, KC_F6, KC_F5, KC_NO, KC_P, KC_EQL,
            KC_TAB, KC_E, KC_A, KC_W, KC_D, KC_NO,                                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_S, KC_NO, KC_NO, KC_NO, KC_NO,                         SWITCHCPU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_LSFT, KC_LSFT, KC_SPC,                                        TO(0), KC_NO, KC_NO, KC_NO, KC_NO
        ),

[_Undefined] = LAYOUT(
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              TO(0), KC_NO, KC_NO, KC_NO, KC_NO
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
    [QS_HOME]       = COMBO_ACTION(quickswitch_home),// = COMBO(quickswitch_home, TG(8)),
    //[ALTSHFTTAB]    = COMBO(altshfttab, KC_ENT),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (combo_index == QS_HOME && pressed) {
        if (layer_state_cmp(layer_state, _MAIN)) {//IS_LAYER_ON(_MAIN)) {
            //set_single_persistent_default_layer(EU_BASE_);
            //tap_code16(TO(8));
            layer_move(8);
        } else if (layer_state_cmp(layer_state, _Minecraft)) {
            //set_single_persistent_default_layer(DE_BASE_);
            //tap_code16(TO(0));
            layer_move(0);
        }
    }
}

// void process_combo_event(uint16_t combo_index, bool pressed) {
//     switch(combo_index) {
//         case ENTER:
//             if (pressed) {
//                 tap_code16(KC_ENT);
//             }
//             break;
//         case REFRESH:
//             if (pressed) {
//                 tap_code16(KC_F5);
//             }
//             break;
//         case PRNTSCRN:
//             if (pressed) {
//                 tap_code16(LCTL(S(KC_ENT)));
//             }
//             break;
        // case BACKHOME:
        //     if (pressed) {
        //         //layer_clear();
        //         tap_code16(TO(0));
        //         //TO(0);
        //         //SEND_STRING(SS_TAP(TO(0)));
        //     }
        //    break;
    //}
  //}

  #ifdef OLED_ENABLE
  oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
      return OLED_ROTATION_180;
  }

  bool oled_task_kb(void) {
      if (!oled_task_user()) {
          return false;
      }
      if (is_keyboard_master()) {
          // QMK Logo and version information
          // clang-format off
          static const char PROGMEM qmk_logo[] = {
              0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
              0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
              0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
          // clang-format on

         oled_write_P(qmk_logo, false);
             oled_write_P(PSTR("Kyria "), false);
         #if defined(KEYBOARD_splitkb_kyria_rev1)
             oled_write_P(PSTR("rev1\n\n"), false);
         #elif defined(KEYBOARD_splitkb_kyria_rev2)
             oled_write_P(PSTR("rev2\n\n"), false);
         #elif defined(KEYBOARD_splitkb_kyria_rev3)
             oled_write_P(PSTR("rev3\n\n"), false);
         #endif
          // Host Keyboard Layer Status
          oled_write_P(PSTR("Layer: "), false);
          switch (get_highest_layer(layer_state | default_layer_state)) {
              case 0:
                  oled_write_P(PSTR("MAIN\n"), false);
                  break;
              case 1:
                  oled_write_P(PSTR("NAVNUM\n"), false);
                  break;
              case 2:
                  oled_write_P(PSTR("SYMBOLS\n"), false);
                  break;
              case 3:
                  oled_write_P(PSTR("GAMECHOICE\n"), false);
                  break;
              case 4:
                  oled_write_P(PSTR("Splitgate\n"), false);
                  break;
              case 5:
                  oled_write_P(PSTR("Destiny 2\n"), false);
                  break;
              case 6:
                  oled_write_P(PSTR("Rocket League\n"), false);
                  break;
              case 7:
                  oled_write_P(PSTR("Spiderheck\n"), false);
                  break;
              case 8:
                  oled_write_P(PSTR("Minecraft\n"), false);
                  break;
              default:
                  oled_write_P(PSTR("Undefined\n"), false);
          }

          // Host Keyboard LED Status
          led_t led_usb_state = host_keyboard_led_state();
          oled_write_P(led_usb_state.num_lock ? PSTR("YCOTUOPE ") : PSTR("       "), false);
          oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
          oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
      }
      else {
         // clang-format on
          switch (get_highest_layer(layer_state | default_layer_state)) {
             case 0: //MAIN
                 oled_write_raw_P(braves_logo, sizeof(braves_logo));
                 break;
             case 1: //NAVNUM
                 oled_write_raw_P(braves_logo, sizeof(braves_logo));
                 break;
             case 2: //SYMBOLS
                 oled_write_raw_P(braves_logo, sizeof(braves_logo));
                 break;
             case 3: //GAMECHOICE
                 oled_write_raw_P(gamechoice_logo, sizeof(gamechoice_logo));
                 break;
             case 4: //Splitgate
                 oled_write_raw_P(splitgate_logo, sizeof(splitgate_logo));
                 break;
             case 5: //Destiny 2
                 oled_write_raw_P(d2_logo, sizeof(d2_logo));
                 break;
             case 6: //Rocket League
                 oled_write_raw_P(rocketleague_logo, sizeof(rocketleague_logo));
                 break;
             case 7: //Spiderheck
                 oled_write_raw_P(spiderheck_logo, sizeof(spiderheck_logo));
                 break;
             case 8: //Minecraft
                 oled_write_raw_P(minecraft_logo, sizeof(minecraft_logo));
                 break;
             default:
                 //oled_write_P(PSTR("Undefined\n"), false);
                 // clang-format on
                 oled_write_raw_P(braves_logo, sizeof(braves_logo));
         }

      }
      return false;
  }
  #endif

  #ifdef ENCODER_ENABLE
  bool encoder_update_kb(uint8_t index, bool clockwise) {
      if (!encoder_update_user(index, clockwise)) {
          return false;
      }

      if (index == 0) {
          // Volume control
          if (clockwise) {
              tap_code(KC_VOLU);
          } else {
              tap_code(KC_VOLD);
          }
      } else if (index == 1) {
          // Page up/Page down
          if (clockwise) {
              tap_code(KC_PGDN);
          } else {
              tap_code(KC_PGUP);
          }
      }
      return true;
  }
  #endif
