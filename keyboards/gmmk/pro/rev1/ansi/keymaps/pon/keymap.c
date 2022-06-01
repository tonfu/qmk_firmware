/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"
#include "pon.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFTCAPS,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        TT(_L1),   KC_LGUI, KC_LALT,                            KC_SPC,                             TT(_L3),   MO(_L2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_L1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,          _______,
        _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           _______,
        _______, KC_MRWD, KC_MFFD, _______, _______, _______, _______, KC_HOME, KC_PGUP, _______, _______, _______, _______, _______,          _______,
        KC_CAPS, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_BSPC,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_END,  KC_PGDN, _______, _______,          _______, _______, _______,
        _______, KC_WINLCK, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [_L2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, NK_TOGG,          _______,
        _______, RGB_NITE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_SLCK,
        _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RESET,            KC_NLCK,
        _______, _______, _______, _______, _______, _______, _______, BL_TOGG, BL_STEP, BL_DEC,  BL_INC,  BL_BRTG,          _______,          RGB_TOI,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RGB_TOG, RGB_MOD, RGB_TOD,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [_L3] = LAYOUT(
        _______, EMO_SHRUG, EMO_CONFUSE, EMO_SAD, EMO_NERVOUS, EMO_JOY, EMO_TEARS, _______, _______, _______, _______, _______, _______, KC_NO,            _______,
        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______, _______, KC_BSPC,          KC_HOME,
        _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_NO,   KC_NO,   KC_DEL,           KC_END,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_NO,            _______,          KC_PGUP,
        _______,          _______, _______, KC_INS,  _______, _______, KC_P0,   KC_00,   KC_PDOT, KC_PSLS, _______,          KC_NO,   KC_UP,   KC_PGDN,
        _______, KC_NO,   _______,                            _______,                            _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),
};

#if defined(ENCODER_ENABLE) && !defined(ENCODER_DEFAULTACTIONS_ENABLE)     // Encoder Functionality when not using userspace defaults
    void encoder_action_rgbhue(bool clockwise) {
        if (clockwise)
            rgblight_increase_hue_noeeprom();
        else
            rgblight_decrease_hue_noeeprom();
    }

    bool encoder_update_user(uint8_t index, bool clockwise) {
        uint8_t mods_state = get_mods();
        if (mods_state & MOD_BIT(KC_LSFT) ) { // If you are holding L shift, encoder changes layers
            encoder_action_layerchange(clockwise);
        } else if (mods_state & MOD_BIT(KC_RSFT) ) { // If you are holding R shift, Page up/dn
            unregister_mods(MOD_BIT(KC_RSFT));
            encoder_action_navpage(clockwise);
            register_mods(MOD_BIT(KC_RSFT));
        } else if (mods_state & MOD_BIT(KC_LCTL)) {  // if holding Left Ctrl, navigate next/prev word
            encoder_action_navword(clockwise);
        } else if (mods_state & MOD_BIT(KC_RCTL)) {  // if holding Right Ctrl, change rgb hue/colour
            encoder_action_rgbhue(clockwise);
        } else if (mods_state & MOD_BIT(KC_LALT)) {  // if holding Left Alt, change media next/prev track
            encoder_action_mediatrack(clockwise);
        } else  {
            switch(get_highest_layer(layer_state)) {
            case _L1:
                #ifdef IDLE_TIMEOUT_ENABLE
                    timeout_update_threshold(clockwise);
                #endif
                break;
            default:
                encoder_action_volume(clockwise);       // Otherwise it just changes volume
                break;
            }
        }
        return true;
    }
#endif // ENCODER_ENABLE && !ENCODER_DEFAULTACTIONS_ENABLE


#ifdef RGB_MATRIX_ENABLE
    // Capslock, Scroll lock and Numlock  indicator on Left side lights.
    void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        if (get_rgb_nightmode()) rgb_matrix_set_color_all(RGB_OFF);

        #ifdef INVERT_NUMLOCK_INDICATOR
        if (!IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {   // on if NUM lock is OFF
            rgb_matrix_set_color(LED_L1, RGB_ORANGE);
            rgb_matrix_set_color(LED_L2, RGB_ORANGE);
            rgb_matrix_set_color(LED_F10, RGB_ORANGE);
        }
        #else
            if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {   // Normal, on if NUM lock is ON
            rgb_matrix_set_color(LED_L1, RGB_ORANGE);
            rgb_matrix_set_color(LED_L2, RGB_ORANGE);
            rgb_matrix_set_color(LED_F10, RGB_ORANGE);
        }
        #endif // INVERT_NUMLOCK_INDICATOR

        if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
            rgb_matrix_set_color(LED_L3, RGB_GREEN);
            rgb_matrix_set_color(LED_L4, RGB_GREEN);
            rgb_matrix_set_color(LED_L5, RGB_GREEN);
            rgb_matrix_set_color(LED_F11, RGB_GREEN);
            rgb_matrix_set_color(LED_CAPS, RGB_GREEN);
        }

        if (!IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) {
            rgb_matrix_set_color(LED_L6, RGB_WHITE);
            rgb_matrix_set_color(LED_L7, RGB_WHITE);
            rgb_matrix_set_color(LED_F12, RGB_WHITE);
        }

        if (keymap_config.no_gui) {
            rgb_matrix_set_color(LED_LWIN, RGB_RED);  //light up Win key when disabled
        }

        switch(get_highest_layer(layer_state)) {  // special handling per layer
        case _L1:  // on Fn layer select what the encoder does when pressed
            rgb_matrix_set_color(LED_LCTL, RGB_YELLOW);
            rgb_matrix_set_color(LED_F1, RGB_YELLOW);

            // Add RGB Timeout Indicator -- shows 0 to 139 using F row and num row;  larger numbers using 16bit code
            uint16_t timeout_threshold = get_timeout_threshold();
            if (timeout_threshold <= 10) rgb_matrix_set_color(LED_LIST_FUNCROW[timeout_threshold], RGB_RED);
            else if (timeout_threshold < 140) {
                rgb_matrix_set_color(LED_LIST_FUNCROW[(timeout_threshold / 10)], RGB_RED);
                rgb_matrix_set_color(LED_LIST_NUMROW[(timeout_threshold % 10)], RGB_RED);
            } else { // >= 140 minutes, just show these 3 lights
                rgb_matrix_set_color(LED_LIST_NUMROW[10], RGB_RED);
                rgb_matrix_set_color(LED_LIST_NUMROW[11], RGB_RED);
                rgb_matrix_set_color(LED_LIST_NUMROW[12], RGB_RED);
            }
            break;
        case _L2:
            rgb_matrix_set_color(LED_FN, RGB_SPRINGGREEN);
            rgb_matrix_set_color(LED_F2, RGB_SPRINGGREEN);

            break;
        case _L3:
            rgb_matrix_set_color(LED_RALT, RGB_ORANGE);
            rgb_matrix_set_color(LED_F3, RGB_ORANGE);

            for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_ARROWS); i++) {
                rgb_matrix_set_color(LED_LIST_WASD[i], RGB_MAGENTA);
            }

            for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_NUMPAD); i++) {
                rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_MAGENTA);
            }

            for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_ARROWS); i++) {
                rgb_matrix_set_color(LED_LIST_NUMPAD_FUNC[i], RGB_SPRINGGREEN);
            }

            break;
        default:
            break;
        }
    }

    void suspend_power_down_user(void) {
        rgb_matrix_set_suspend_state(true);
    }

    void suspend_wakeup_init_user(void) {
        rgb_matrix_set_suspend_state(false);
    }
#endif

void keyboard_post_init_keymap(void) {
    // keyboard_post_init_user() moved to userspace
    #ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(RGB_NAUTILUS); // Default startup colour
        activate_rgb_nightmode(false);  // Set to true if you want to startup in nightmode, otherwise use Fn + Z to toggle
    #endif
}
