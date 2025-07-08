/* Copyright 2022 splitkb.com <support@splitkb.com>
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

 #include "quantum.h"
/*  #include "oledImages.h"

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
 #endif */
