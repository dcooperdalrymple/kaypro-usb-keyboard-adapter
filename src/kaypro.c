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

static uint8_t const kayproHIDTable[KP_HID_TABLE_LEN][3] =  { KP_HID_TABLE };

uint8_t kaypro_get_data(uint8_t keycode, KeyboardState * state) {
    bool shift = state->shift;
    if (keycode >= HID_KEY_A && keycode <= HID_KEY_Z && state->capslock) shift = !shift;

    if (state->ctrl && kayproHIDTable[keycode][2] != KP_KEY_NONE) {
        return kayproHIDTable[keycode][2];
    } else if (shift && kayproHIDTable[keycode][1] != KP_KEY_NONE) {
        return kayproHIDTable[keycode][1];
    } else {
        return kayproHIDTable[keycode][0];
    }
}
