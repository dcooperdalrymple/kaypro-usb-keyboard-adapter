/**
 * kaypro-usb-keyboard-adapter: kaypro.c
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#include "kaypro.h"

#include <stdlib.h>
#include "pico/stdlib.h"

#include "keycodes.h"
#include "keyboard.h"

static uint8_t const keycodeTable[KP_KEYCODE_TABLE_LEN][3] =  { KP_KEYCODE_TABLE };

uint8_t kaypro_get_data(uint8_t keycode, KeyboardState * state) {
    if (keycode == HID_KEY_NONE) return KP_NULL;

    if (keycode >= HID_KEY_A && keycode <= HID_KEY_Z) {

        bool shift = state->shift;
        if (state->capslock) shift = !shift;
        
        // Alphabet
        keycode -= HID_KEY_A;
        if (state->ctrl) {
            return KP_CTRL_A + keycode;
        } else if (shift) {
            return KP_A + keycode;
        } else {
            return KP_a + keycode;
        }

    } else if (!state->shift && keycode >= HID_KEY_1 && keycode <= HID_KEY_0) {

        // Digit
        if (keycode == HID_KEY_0) return KP_0;
        if (keycode == HID_KEY_2 && state->ctrl) return KP_CTRL_2;
        if (keycode == HID_KEY_6 && state->ctrl) return KP_CTRL_6;
        keycode -= HID_KEY_1;
        return KP_1 + keycode;

    }

    for (uint8_t i = 0; i < KP_KEYCODE_TABLE_LEN; i++) {
        if (keycode == keycodeTable[i][0]) return keycodeTable[i][state->shift ? 1 : 2];
    }

    return KP_NULL;
}
