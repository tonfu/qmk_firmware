#pragma once

#define TAPPING_TOGGLE 2           // TT () set to two taps

#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY

#ifdef RGB_MATRIX_ENABLE
    #ifdef RGB_MATRIX_STARTUP_MODE
        #undef RGB_MATRIX_STARTUP_MODE
    #endif
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#endif
