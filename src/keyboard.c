/**
 * kaypro-usb-keyboard-adapter: keyboard.c
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#include "keyboard.h"

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#include "config.h"
#include "keycodes.h"

static uint8_t const keycode2ascii[128][2] =  { HID_KEYCODE_TO_ASCII };

KeyboardState keyboardState;

bool in_array(uint8_t value, uint8_t * arr, uint8_t length) {
    for (uint8_t i = 0; i < length; i++) {
        if (value == arr[i]) return true;
    }
    return false;
}

void keyboard_update(uint8_t * packet) {
    uint8_t i;
    KeyboardState * state = keyboard_read(packet);

    // Check for release
    for (i = 0; i < keyboardState.length; i++) {
        if (in_array(keyboardState.keys[i], state->keys, state->length)) continue; // Exit early if no state change
        keyboard_release(keyboardState.keys[i], state);
    }

    // Check for special cases (press before callbacks)
    for (i = 0; i < state->length; i++) {
        if (in_array(state->keys[i], keyboardState.keys, keyboardState.length)) continue; // Exit early if no state change
        switch (state->keys[i]) {
            case HID_KEY_CAPS_LOCK:
                keyboardState.capslock = !keyboardState.capslock; // toggle
                break;
        }
    }

    // Copy special cases to new state
    state->capslock = keyboardState.capslock;

    // Check for press
    for (i = 0; i < state->length; i++) {
        if (in_array(state->keys[i], keyboardState.keys, keyboardState.length)) continue; // Exit early if no state change
        keyboard_press(state->keys[i], state);
    }

    keyboard_copy(state);
    free(state);
}

KeyboardState * keyboard_read(uint8_t * packet) {
    KeyboardState *state = (KeyboardState*) malloc(sizeof(KeyboardState));
    uint8_t i;

    state->ctrl = packet[0] & (KBD_MOD_CTRLLEFT | KBD_MOD_CTRLRIGHT);
    state->shift = packet[0] & (KBD_MOD_SHIFTLEFT | KBD_MOD_SHIFTRIGHT);
    state->alt = packet[0] & (KBD_MOD_ALTLEFT | KBD_MOD_ALTRIGHT);
    state->gui = packet[0] & (KBD_MOD_GUILEFT | KBD_MOD_GUIRIGHT);
    //state->capslock = false;

    state->length = KBD_KEYS_LENGTH;
    for (i = 0; i < KBD_KEYS_LENGTH; i++) {
        if (packet[i+KBD_KEYS_OFFSET] != 0x00) continue;
        state->length = i;
        break;
    }
    for (i = 0; i < KBD_KEYS_LENGTH; i++) {
        state->keys[i] = packet[i+KBD_KEYS_OFFSET];
    }

    return state;
}

void keyboard_copy(KeyboardState * state) {
    uint8_t i;

    keyboardState.ctrl = state->ctrl;
    keyboardState.shift = state->shift;
    keyboardState.alt = state->alt;
    keyboardState.gui = state->gui;
    //keyboardState.capslock = state->capslock;

    keyboardState.length = state->length;

    for (i = 0; i < KBD_KEYS_LENGTH; i++) {
        keyboardState.keys[i] = state->keys[i];
    }
}

void keyboard_clear(void) {
    uint8_t i;

    keyboardState.ctrl = false;
    keyboardState.shift = false;
    keyboardState.alt = false;
    keyboardState.gui = false;
    keyboardState.capslock = false;

    keyboardState.length = 0;
    for (i = 0; i < KBD_KEYS_LENGTH; i++) {
        keyboardState.keys[i] = 0x00;
    }
}

void keyboard_print(void) {
    printf("CTRL = %s\r\n", keyboardState.ctrl ? "ON" : "OFF");
    printf("SHIFT = %s\r\n", keyboardState.shift ? "ON" : "OFF");
    printf("ALT = %s\r\n", keyboardState.alt ? "ON" : "OFF");
    printf("GUI = %s\r\n", keyboardState.gui ? "ON" : "OFF");
    printf("CAPSLOCK = %s\r\n", keyboardState.capslock ? "ON" : "OFF");

    printf("KEYS = %d\r\n", keyboardState.length);
    for (uint8_t i = 0; i < keyboardState.length; i++) {
        printf("%02x ", keyboardState.keys[i]);
    }
    printf("\r\n\r\n");
}

uint8_t keyboard_get_ascii(uint8_t keycode, KeyboardState * state) {
    if (state == NULL) state = &keyboardState;
    bool shift = state->shift;
    if (keycode >= HID_KEY_A && keycode <= HID_KEY_Z && state->capslock) {
        shift = !shift;
    }
    return keycode2ascii[keycode][shift ? 1 : 0];
}
