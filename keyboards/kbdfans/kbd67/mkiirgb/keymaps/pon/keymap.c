#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"
#include "pon.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_65_ansi_blocker(
        KC_GRV,         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_HOME,
        KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLASH,  KC_END,
        KC_LCTL,        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,     KC_PGUP,
        KC_LSFTCAPS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,                KC_UP,      KC_PGDN,
        TT(_L1),        KC_LGUI,    KC_LALT,                            KC_SPC,                                         TT(_L3),    MO(_L2),                KC_LEFT,    KC_DOWN,    KC_RIGHT
    ),

    [_L1] = LAYOUT_65_ansi_blocker(
        KC_ESC,         KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,     KC_PSCR,
        _______,        KC_MRWD,    KC_MFFD,    _______,    _______,    _______,    _______,    KC_HOME,    KC_PGUP,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,        KC_VOLD,    KC_VOLU,    KC_MUTE,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_DEL,     KC_BSPC,                _______,    _______,
        _______,        KC_MPLY,    KC_MPLY,    KC_MNXT,    KC_MSTP,    _______,    _______,    KC_END,     KC_PGDN,    _______,    _______,    _______,                _______,    _______,
        _______,        KC_CAPS,    _______,                            _______,                                                    _______,    _______,    _______,    _______,    _______
    ),

    [_L2] = LAYOUT_65_ansi_blocker(
        _______,        RGB_NITE,   NK_TOGG,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_SLCK,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    RGB_HUD,    RGB_HUI,    RGB_SAD,    RGB_SAI,    RGB_VAD,    RGB_VAI,    RESET,      KC_NLCK,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    BL_TOGG,    BL_STEP,    BL_DEC,     BL_INC,     BL_BRTG,                _______,    _______,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_TOG,                RGB_MOD,    _______,
        _______,        _______,    _______,                            _______,                                        _______,    _______,                RGB_SPD,    RGB_RMOD,   RGB_SPI
    ),

    [_L3] = LAYOUT_65_ansi_blocker(
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_P7,      KC_P8,      KC_P9,      KC_PPLS,    _______,    _______,    KC_BSPC,    KC_HOME,
        _______,        KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    _______,    _______,    KC_P4,      KC_P5,      KC_P6,      KC_PMNS,    _______,    _______,    KC_DEL,     KC_END,
        _______,        KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,    _______,    _______,    KC_P1,      KC_P2,      KC_P3,      KC_PAST,    _______,                _______,    KC_PGUP,
        _______,        _______,    _______,    _______,    KC_INS,     _______,    _______,    KC_P0,      KC_00,      KC_PDOT,    KC_PSLS,    _______,                KC_UP,      KC_PGDN,
        _______,        _______,    _______,                            _______,                                        _______,    _______,                KC_LEFT,    KC_DOWN,    KC_RGHT
    )
};

#ifdef RGB_MATRIX_ENABLE
    void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        if (get_rgb_nightmode()) rgb_matrix_set_color_all(RGB_OFF);

        #ifdef INVERT_NUMLOCK_INDICATOR
        if (!IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
            rgb_matrix_set_color(LED_PGUP, RGB_ORANGE);
        }
        #else
            if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
            rgb_matrix_set_color(LED_PGUP, RGB_ORANGE);
        }
        #endif // INVERT_NUMLOCK_INDICATOR

        if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
            rgb_matrix_set_color(LED_CAPS, RGB_GREEN);
        }

        if (!IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) {
            rgb_matrix_set_color(LED_DEL, RGB_YELLOW);
        }

        switch(get_highest_layer(layer_state)) {  // special handling per layer
        case _L1:  // on Fn layer select what the encoder does when pressed
            rgb_matrix_set_color(LED_LCTL, RGB_YELLOW);
            rgb_matrix_set_color(LED_1, RGB_YELLOW);

            #ifdef IDLE_TIMEOUT_ENABLE
                // Add RGB Timeout Indicator -- shows 0 to 139 using F row and num row;  larger numbers using 16bit code
                uint16_t timeout_threshold = get_timeout_threshold();
                if (timeout_threshold <= 10) rgb_matrix_set_color(LED_LIST_NUMROW[timeout_threshold], RGB_GOLD);
                else if (timeout_threshold < 140) {
                    rgb_matrix_set_color(LED_LIST_QWERTYROW[(timeout_threshold / 10)], RGB_GOLD);
                    rgb_matrix_set_color(LED_LIST_NUMROW[(timeout_threshold % 10)], RGB_GOLD);
                } else { // >= 140 minutes, just show these 3 lights
                    rgb_matrix_set_color(LED_LIST_NUMROW[10], RGB_GOLD);
                    rgb_matrix_set_color(LED_LIST_NUMROW[11], RGB_GOLD);
                    rgb_matrix_set_color(LED_LIST_NUMROW[12], RGB_GOLD);
                }
            #endif

            break;
        case _L2:
            rgb_matrix_set_color(LED_RCTL, RGB_SPRINGGREEN);
            rgb_matrix_set_color(LED_2, RGB_SPRINGGREEN);

            break;
        case _L3:
            rgb_matrix_set_color(LED_FN, RGB_ORANGE);
            rgb_matrix_set_color(LED_3, RGB_ORANGE);

            for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_ARROWS); i++) {
                rgb_matrix_set_color(LED_LIST_WASD[i], RGB_MAGENTA);
            }

            for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_NUMPAD); i++) {
                rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_MAGENTA);
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
        activate_rgb_nightmode(false);  // Set to true if you want to startup in nightmode, otherwise use Fn + Z to toggle
    #endif
}
