/**
 * kaypro-usb-keyboard-adapter: keyboard.h
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

// https://kevinboone.me/pico_usb_kbd_lcd.html?i=1
// https://www.win.tue.nl/~aeb/linux/kbd/scancodes-14.html

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <stdlib.h>
#include "pico/stdlib.h"

#define KBD_KEYS_LENGTH 6
#define KBD_KEYS_OFFSET 2

typedef struct KeyboardState {
    bool ctrl;
    bool shift;
    bool alt;
    uint8_t keys[KBD_KEYS_LENGTH];
    uint8_t length;
} KeyboardState;

extern KeyboardState keyboardState;

extern void keyboard_press(uint8_t keycode, KeyboardState * state);
extern void keyboard_release(uint8_t keycode, KeyboardState * state);

void keyboard_update(uint8_t * packet);
KeyboardState * keyboard_read(uint8_t * packet);
void keyboard_copy(KeyboardState * state);
void keyboard_clear(void);
void keyboard_compare(void);
void keyboard_print(void);

#endif
