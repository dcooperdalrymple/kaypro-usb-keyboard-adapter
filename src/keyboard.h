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

#define KBD_KEYS_LENGTH     6
#define KBD_KEYS_OFFSET     2

#define KBD_MOD_CTRLLEFT    0x01
#define KBD_MOD_SHIFTLEFT   0x02
#define KBD_MOD_ALTLEFT     0x04
#define KBD_MOD_GUILEFT     0x08
#define KBD_MOD_CTRLRIGHT   0x10
#define KBD_MOD_SHIFTRIGHT  0x20
#define KBD_MOD_ALTRIGHT    0x40
#define KBD_MOD_GUIRIGHT    0x80

typedef struct KeyboardState {
    bool ctrl;
    bool shift;
    bool alt;
    bool gui;
    bool capslock;
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
uint8_t keyboard_get_ascii(uint8_t keycode, KeyboardState * state);

#endif
