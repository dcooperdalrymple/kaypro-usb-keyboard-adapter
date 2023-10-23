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

KeyboardState keyboardState;

void keyboard_update(uint8_t * packet) {
    uint8_t i, j;
    bool found;
    KeyboardState * state = keyboard_read(packet);

    // Check for release
    for (i = 0; i < keyboardState.length; i++) {
        found = false;
        for (j = 0; j < state->length; j++) {
            if (keyboardState.keys[i] == state->keys[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            keyboard_release(keyboardState.keys[i], state);
        }
    }

    // Check for press
    for (i = 0; i < state->length; i++) {
        found = false;
        for (j = 0; j < keyboardState.length; j++) {
            if (state->keys[i] == keyboardState.keys[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            // Special Cases
            switch (state->keys[j]) {
                case KBD_KEY_CAPSLOCK:
                    keyboardState.capslock = !keyboardState.capslock; // toggle
                    break;
            }

            keyboard_press(state->keys[j], state);
        }
    }

    keyboard_copy(state);
    free(state);
}

KeyboardState * keyboard_read(uint8_t * packet) {
    KeyboardState *state = (KeyboardState*) malloc(sizeof(KeyboardState));
    uint8_t i;

    state->ctrl = packet[0] & 0x01;
    state->shift = packet[0] & 0x02;
    state->alt = packet[0] & 0x04;
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
    printf("CAPSLOCK = %s\r\n", keyboardState.capslock ? "ON" : "OFF");

    printf("KEYS = %d\r\n", keyboardState.length);
    for (uint8_t i = 0; i < keyboardState.length; i++) {
        printf("%02x ", keyboardState.keys[i]);
    }
    printf("\r\n\r\n");
}
