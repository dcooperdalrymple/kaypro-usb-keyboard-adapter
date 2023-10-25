/**
 * kaypro-usb-keyboard-adapter: kaypro.h
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

// https://github.com/impressivemachines/Kaypro/blob/master/kaypro_technical.md

#ifndef KAYPRO_H_
#define KAYPRO_H_

#include <stdlib.h>
#include "pico/stdlib.h"

#include "keycodes.h"
#include "keyboard.h"

#define KP_KEY_NONE                 0xff

#define KP_KEY_CTRL_2               0x00
#define KP_KEY_CTRL_A               0x01
#define KP_KEY_CTRL_B               0x02
#define KP_KEY_CTRL_C               0x03
#define KP_KEY_CTRL_D               0x04
#define KP_KEY_CTRL_E               0x05
#define KP_KEY_CTRL_F               0x06
#define KP_KEY_CTRL_G               0x07
#define KP_KEY_CTRL_H               0x08
#define KP_KEY_CTRL_I               0x09
#define KP_KEY_CTRL_J               0x0a
#define KP_KEY_CTRL_K               0x0b
#define KP_KEY_CTRL_L               0x0c
#define KP_KEY_CTRL_M               0x0d
#define KP_KEY_CTRL_N               0x0e
#define KP_KEY_CTRL_O               0x0f
#define KP_KEY_CTRL_P               0x10
#define KP_KEY_CTRL_Q               0x11
#define KP_KEY_CTRL_R               0x12
#define KP_KEY_CTRL_S               0x13
#define KP_KEY_CTRL_T               0x14
#define KP_KEY_CTRL_U               0x15
#define KP_KEY_CTRL_V               0x16
#define KP_KEY_CTRL_W               0x17
#define KP_KEY_CTRL_X               0x18
#define KP_KEY_CTRL_Y               0x19
#define KP_KEY_CTRL_Z               0x1a
#define KP_KEY_CTRL_BRACKET_LEFT    0x1b
#define KP_KEY_CTRL_BACKSLASH       0x1c
#define KP_KEY_CTRL_BRACKET_RIGHT   0x1d
#define KP_KEY_CTRL_6               0x1e
#define KP_KEY_CTRL_MINUS           0x1f
#define KP_KEY_SPACE                0x20
#define KP_KEY_EXCLAMATION          0x21
#define KP_KEY_QUOTE                0x22
#define KP_KEY_HASH                 0x23
#define KP_KEY_DOLLAR               0x24
#define KP_KEY_PERCENT              0x25
#define KP_KEY_AMPERSAND            0x26
#define KP_KEY_APOSTROPHE           0x27
#define KP_KEY_PARENTHESES_LEFT     0x28
#define KP_KEY_PARENTHESES_RIGHT    0x29
#define KP_KEY_ASTERISK             0x2a
#define KP_KEY_PLUS                 0x2b
#define KP_KEY_COMMA                0x2c
#define KP_KEY_MINUS                0x2d
#define KP_KEY_PERIOD               0x2e
#define KP_KEY_SLASH                0x2f
#define KP_KEY_0                    0x30
#define KP_KEY_1                    0x31
#define KP_KEY_2                    0x32
#define KP_KEY_3                    0x33
#define KP_KEY_4                    0x34
#define KP_KEY_5                    0x35
#define KP_KEY_6                    0x36
#define KP_KEY_7                    0x37
#define KP_KEY_8                    0x38
#define KP_KEY_9                    0x39
#define KP_KEY_COLON                0x3a
#define KP_KEY_SEMICOLON            0x3b
#define KP_KEY_LESSTHAN             0x3c
#define KP_KEY_EQUAL                0x3d
#define KP_KEY_GREATERTHAN          0x3e
#define KP_KEY_QUESTION             0x3f
#define KP_KEY_AT                   0x40
#define KP_KEY_A                    0x41
#define KP_KEY_B                    0x42
#define KP_KEY_C                    0x43
#define KP_KEY_D                    0x44
#define KP_KEY_E                    0x45
#define KP_KEY_F                    0x46
#define KP_KEY_G                    0x47
#define KP_KEY_H                    0x48
#define KP_KEY_I                    0x49
#define KP_KEY_J                    0x4a
#define KP_KEY_K                    0x4b
#define KP_KEY_L                    0x4c
#define KP_KEY_M                    0x4d
#define KP_KEY_N                    0x4e
#define KP_KEY_O                    0x4f
#define KP_KEY_P                    0x50
#define KP_KEY_Q                    0x51
#define KP_KEY_R                    0x52
#define KP_KEY_S                    0x53
#define KP_KEY_T                    0x54
#define KP_KEY_U                    0x55
#define KP_KEY_V                    0x56
#define KP_KEY_W                    0x57
#define KP_KEY_X                    0x58
#define KP_KEY_Y                    0x59
#define KP_KEY_Z                    0x5a
#define KP_KEY_BRACKET_LEFT         0x5b
#define KP_KEY_BACKSLASH            0x5c
#define KP_KEY_BRACKET_RIGHT        0x5d
#define KP_KEY_CARET                0x5e
#define KP_KEY_UNDERSCORE           0x5f
#define KP_KEY_GRAVE                0x60
#define KP_KEY_a                    0x61
#define KP_KEY_b                    0x62
#define KP_KEY_c                    0x63
#define KP_KEY_d                    0x64
#define KP_KEY_e                    0x65
#define KP_KEY_f                    0x66
#define KP_KEY_g                    0x67
#define KP_KEY_h                    0x68
#define KP_KEY_i                    0x69
#define KP_KEY_j                    0x6a
#define KP_KEY_k                    0x6b
#define KP_KEY_l                    0x6c
#define KP_KEY_m                    0x6d
#define KP_KEY_n                    0x6e
#define KP_KEY_o                    0x6f
#define KP_KEY_p                    0x70
#define KP_KEY_q                    0x71
#define KP_KEY_r                    0x72
#define KP_KEY_s                    0x73
#define KP_KEY_t                    0x74
#define KP_KEY_u                    0x75
#define KP_KEY_v                    0x76
#define KP_KEY_w                    0x77
#define KP_KEY_x                    0x78
#define KP_KEY_y                    0x79
#define KP_KEY_z                    0x7a
#define KP_KEY_CURLYBRACKET_LEFT    0x7b
#define KP_KEY_PIPE                 0x7c
#define KP_KEY_CURLYBRACKET_RIGHT   0x7d
#define KP_KEY_TILDE                0x7e
#define KP_KEY_DELETE               0x7f
#define KP_KEY_NUMPAD_0             0x81
#define KP_KEY_NUMPAD_DECIMAL       0x82
#define KP_KEY_NUMPAD_1             0xc0
#define KP_KEY_NUMPAD_2             0xc1
#define KP_KEY_NUMPAD_3             0xc2
#define KP_KEY_NUMPAD_ENTER         0xc3
#define KP_KEY_NUMPAD_4             0xd0
#define KP_KEY_NUMPAD_5             0xd1
#define KP_KEY_NUMPAD_6             0xd2
#define KP_KEY_NUMPAD_COMMA         0xd3
#define KP_KEY_NUMPAD_7             0xe1
#define KP_KEY_NUMPAD_8             0xe2
#define KP_KEY_NUMPAD_9             0xe3
#define KP_KEY_NUMPAD_SUBTRACT      0xe4
#define KP_KEY_ARROW_UP             0xf1
#define KP_KEY_ARROW_DOWN           0xf2
#define KP_KEY_ARROW_LEFT           0xf3
#define KP_KEY_ARROW_RIGHT          0xf4

// Duplicates
#define KP_KEY_BACKSPACE            0x08
#define KP_KEY_TAB                  0x09
#define KP_KEY_LINEFEED             0x0a
#define KP_KEY_RETURN               0x0d
#define KP_KEY_ESC                  0x1b

/**
 * Table Format:
 * Index = HID Keycode
 * { No Modifiers, Shift, Ctrl }
 */

#define KP_HID_TABLE \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x00 (HID_KEY_NONE) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x01 */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x02 */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x03 */ \
    { KP_KEY_a, KP_KEY_A, KP_KEY_CTRL_A }, /* 0x04 (HID_KEY_A) */ \
    { KP_KEY_b, KP_KEY_B, KP_KEY_CTRL_B }, /* 0x05 (HID_KEY_B) */ \
    { KP_KEY_c, KP_KEY_C, KP_KEY_CTRL_C }, /* 0x06 (HID_KEY_C) */ \
    { KP_KEY_d, KP_KEY_D, KP_KEY_CTRL_D }, /* 0x07 (HID_KEY_D) */ \
    { KP_KEY_e, KP_KEY_E, KP_KEY_CTRL_E }, /* 0x08 (HID_KEY_E) */ \
    { KP_KEY_f, KP_KEY_F, KP_KEY_CTRL_F }, /* 0x09 (HID_KEY_F) */ \
    { KP_KEY_g, KP_KEY_G, KP_KEY_CTRL_G }, /* 0x0a (HID_KEY_G) */ \
    { KP_KEY_h, KP_KEY_H, KP_KEY_CTRL_H }, /* 0x0b (HID_KEY_H) */ \
    { KP_KEY_i, KP_KEY_I, KP_KEY_CTRL_I }, /* 0x0c (HID_KEY_I) */ \
    { KP_KEY_j, KP_KEY_J, KP_KEY_CTRL_J }, /* 0x0d (HID_KEY_J) */ \
    { KP_KEY_k, KP_KEY_K, KP_KEY_CTRL_K }, /* 0x0e (HID_KEY_K) */ \
    { KP_KEY_l, KP_KEY_L, KP_KEY_CTRL_L }, /* 0x0f (HID_KEY_L) */ \
    { KP_KEY_m, KP_KEY_M, KP_KEY_CTRL_M }, /* 0x10 (HID_KEY_M) */ \
    { KP_KEY_n, KP_KEY_N, KP_KEY_CTRL_N }, /* 0x11 (HID_KEY_N) */ \
    { KP_KEY_o, KP_KEY_O, KP_KEY_CTRL_O }, /* 0x12 (HID_KEY_O) */ \
    { KP_KEY_p, KP_KEY_P, KP_KEY_CTRL_P }, /* 0x13 (HID_KEY_P) */ \
    { KP_KEY_q, KP_KEY_Q, KP_KEY_CTRL_Q }, /* 0x14 (HID_KEY_Q) */ \
    { KP_KEY_r, KP_KEY_R, KP_KEY_CTRL_R }, /* 0x15 (HID_KEY_R) */ \
    { KP_KEY_s, KP_KEY_S, KP_KEY_CTRL_S }, /* 0x16 (HID_KEY_S) */ \
    { KP_KEY_t, KP_KEY_T, KP_KEY_CTRL_T }, /* 0x17 (HID_KEY_T) */ \
    { KP_KEY_u, KP_KEY_U, KP_KEY_CTRL_U }, /* 0x18 (HID_KEY_U) */ \
    { KP_KEY_v, KP_KEY_V, KP_KEY_CTRL_V }, /* 0x19 (HID_KEY_V) */ \
    { KP_KEY_w, KP_KEY_W, KP_KEY_CTRL_W }, /* 0x1a (HID_KEY_W) */ \
    { KP_KEY_x, KP_KEY_X, KP_KEY_CTRL_X }, /* 0x1b (HID_KEY_X) */ \
    { KP_KEY_y, KP_KEY_Y, KP_KEY_CTRL_Y }, /* 0x1c (HID_KEY_Y) */ \
    { KP_KEY_z, KP_KEY_Z, KP_KEY_CTRL_Z }, /* 0x1d (HID_KEY_Z) */ \
    { KP_KEY_1, KP_KEY_EXCLAMATION, KP_KEY_NONE }, /* 0x1e (HID_KEY_1) */ \
    { KP_KEY_2, KP_KEY_AT, KP_KEY_CTRL_2 }, /* 0x1f (HID_KEY_2) */ \
    { KP_KEY_3, KP_KEY_HASH, KP_KEY_NONE }, /* 0x20 (HID_KEY_3) */ \
    { KP_KEY_4, KP_KEY_DOLLAR, KP_KEY_NONE }, /* 0x21 (HID_KEY_4) */ \
    { KP_KEY_5, KP_KEY_PERCENT, KP_KEY_NONE }, /* 0x22 (HID_KEY_5) */ \
    { KP_KEY_6, KP_KEY_CARET, KP_KEY_CTRL_6 }, /* 0x23 (HID_KEY_6) */ \
    { KP_KEY_7, KP_KEY_AMPERSAND, KP_KEY_NONE }, /* 0x24 (HID_KEY_7) */ \
    { KP_KEY_8, KP_KEY_ASTERISK, KP_KEY_NONE }, /* 0x25 (HID_KEY_8) */ \
    { KP_KEY_9, KP_KEY_PARENTHESES_LEFT, KP_KEY_NONE }, /* 0x26 (HID_KEY_9) */ \
    { KP_KEY_0, KP_KEY_PARENTHESES_RIGHT, KP_KEY_NONE }, /* 0x27 (HID_KEY_0) */ \
    { KP_KEY_RETURN, KP_KEY_NONE, KP_KEY_NONE }, /* 0x28 (HID_KEY_ENTER) */ \
    { KP_KEY_ESC, KP_KEY_NONE, KP_KEY_NONE }, /* 0x29 (HID_KEY_ESCAPE) */ \
    { KP_KEY_BACKSPACE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x2a (HID_KEY_BACKSPACE) */ \
    { KP_KEY_TAB, KP_KEY_NONE, KP_KEY_NONE }, /* 0x2b (HID_KEY_TAB) */ \
    { KP_KEY_SPACE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x2c (HID_KEY_SPACE) */ \
    { KP_KEY_MINUS, KP_KEY_UNDERSCORE, KP_KEY_CTRL_MINUS }, /* 0x2d (HID_KEY_MINUS) */ \
    { KP_KEY_EQUAL, KP_KEY_PLUS, KP_KEY_NONE }, /* 0x2e (HID_KEY_EQUAL) */ \
    { KP_KEY_BRACKET_LEFT, KP_KEY_CURLYBRACKET_LEFT, KP_KEY_CTRL_BRACKET_LEFT }, /* 0x2f (HID_KEY_BRACKET_LEFT) */ \
    { KP_KEY_BRACKET_RIGHT, KP_KEY_CURLYBRACKET_RIGHT, KP_KEY_CTRL_BRACKET_RIGHT }, /* 0x30 (HID_KEY_BRACKET_RIGHT) */ \
    { KP_KEY_BACKSLASH, KP_KEY_PIPE, KP_KEY_NONE }, /* 0x31 (HID_KEY_BACKSLASH) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x32 (HID_KEY_EUROPE_1) */ \
    { KP_KEY_SEMICOLON, KP_KEY_COLON, KP_KEY_NONE }, /* 0x33 (HID_KEY_SEMICOLON) */ \
    { KP_KEY_APOSTROPHE, KP_KEY_QUOTE, KP_KEY_NONE }, /* 0x34 (HID_KEY_APOSTROPHE) */ \
    { KP_KEY_GRAVE, KP_KEY_TILDE, KP_KEY_NONE }, /* 0x35 (HID_KEY_GRAVE) */ \
    { KP_KEY_COMMA, KP_KEY_LESSTHAN, KP_KEY_NONE }, /* 0x36 (HID_KEY_COMMA) */ \
    { KP_KEY_PERIOD, KP_KEY_GREATERTHAN, KP_KEY_NONE }, /* 0x37 (HID_KEY_PERIOD) */ \
    { KP_KEY_SLASH, KP_KEY_QUESTION, KP_KEY_NONE }, /* 0x38 (HID_KEY_SLASH) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x39 (HID_KEY_CAPS_LOCK) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x3a (HID_KEY_F1) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x3b (HID_KEY_F2) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x3c (HID_KEY_F3) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x3d (HID_KEY_F4) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x3e (HID_KEY_F5) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x3f (HID_KEY_F6) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x40 (HID_KEY_F7) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x41 (HID_KEY_F8) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x42 (HID_KEY_F9) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x43 (HID_KEY_F10) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x44 (HID_KEY_F11) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x45 (HID_KEY_F12) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x46 (HID_KEY_PRINT_SCREEN) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x47 (HID_KEY_SCROLL_LOCK) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x48 (HID_KEY_PAUSE) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x49 (HID_KEY_INSERT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x4a (HID_KEY_HOME) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x4b (HID_KEY_PAGE_UP) */ \
    { KP_KEY_DELETE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x4c (HID_KEY_DELETE) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x4d (HID_KEY_END) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x4e (HID_KEY_PAGE_DOWN) */ \
    { KP_KEY_ARROW_RIGHT, KP_KEY_NONE, KP_KEY_NONE }, /* 0x4f (HID_KEY_ARROW_RIGHT) */ \
    { KP_KEY_ARROW_LEFT, KP_KEY_NONE, KP_KEY_NONE }, /* 0x50 (HID_KEY_ARROW_LEFT) */ \
    { KP_KEY_ARROW_DOWN, KP_KEY_NONE, KP_KEY_NONE }, /* 0x51 (HID_KEY_ARROW_DOWN) */ \
    { KP_KEY_ARROW_UP, KP_KEY_NONE, KP_KEY_NONE }, /* 0x52 (HID_KEY_ARROW_UP) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x53 (HID_KEY_NUM_LOCK) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x54 (HID_KEY_KEYPAD_DIVIDE) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x55 (HID_KEY_KEYPAD_MULTIPLY) */ \
    { KP_KEY_NUMPAD_SUBTRACT, KP_KEY_NONE, KP_KEY_NONE }, /* 0x56 (HID_KEY_KEYPAD_SUBTRACT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x57 (HID_KEY_KEYPAD_ADD) */ \
    { KP_KEY_NUMPAD_ENTER, KP_KEY_NONE, KP_KEY_NONE }, /* 0x58 (HID_KEY_KEYPAD_ENTER) */ \
    { KP_KEY_NUMPAD_1, KP_KEY_NONE, KP_KEY_NONE }, /* 0x59 (HID_KEY_KEYPAD_1) */ \
    { KP_KEY_NUMPAD_2, KP_KEY_NONE, KP_KEY_NONE }, /* 0x5a (HID_KEY_KEYPAD_2) */ \
    { KP_KEY_NUMPAD_3, KP_KEY_NONE, KP_KEY_NONE }, /* 0x5b (HID_KEY_KEYPAD_3) */ \
    { KP_KEY_NUMPAD_4, KP_KEY_NONE, KP_KEY_NONE }, /* 0x5c (HID_KEY_KEYPAD_4) */ \
    { KP_KEY_NUMPAD_5, KP_KEY_NONE, KP_KEY_NONE }, /* 0x5d (HID_KEY_KEYPAD_5) */ \
    { KP_KEY_NUMPAD_6, KP_KEY_NONE, KP_KEY_NONE }, /* 0x5e (HID_KEY_KEYPAD_6) */ \
    { KP_KEY_NUMPAD_7, KP_KEY_NONE, KP_KEY_NONE }, /* 0x5f (HID_KEY_KEYPAD_7) */ \
    { KP_KEY_NUMPAD_8, KP_KEY_NONE, KP_KEY_NONE }, /* 0x60 (HID_KEY_KEYPAD_8) */ \
    { KP_KEY_NUMPAD_9, KP_KEY_NONE, KP_KEY_NONE }, /* 0x61 (HID_KEY_KEYPAD_9) */ \
    { KP_KEY_NUMPAD_0, KP_KEY_NONE, KP_KEY_NONE }, /* 0x62 (HID_KEY_KEYPAD_0) */ \
    { KP_KEY_NUMPAD_DECIMAL, KP_KEY_NONE, KP_KEY_NONE }, /* 0x63 (HID_KEY_KEYPAD_DECIMAL) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x64 (HID_KEY_EUROPE_2) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x65 (HID_KEY_APPLICATION) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x66 (HID_KEY_POWER) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x67 (HID_KEY_KEYPAD_EQUAL) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x68 (HID_KEY_F13) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x69 (HID_KEY_F14) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x6a (HID_KEY_F15) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x6b (HID_KEY_F16) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x6c (HID_KEY_F17) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x6d (HID_KEY_F18) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x6e (HID_KEY_F19) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x6f (HID_KEY_F20) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x70 (HID_KEY_F21) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x71 (HID_KEY_F22) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x72 (HID_KEY_F23) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x73 (HID_KEY_F24) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x74 (HID_KEY_EXECUTE) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x75 (HID_KEY_HELP) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x76 (HID_KEY_MENU) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x77 (HID_KEY_SELECT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x78 (HID_KEY_STOP) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x79 (HID_KEY_AGAIN) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x7a (HID_KEY_UNDO) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x7b (HID_KEY_CUT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x7c (HID_KEY_COPY) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x7d (HID_KEY_PASTE) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x7e (HID_KEY_FIND) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x7f (HID_KEY_MUTE) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x80 (HID_KEY_VOLUME_UP) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x81 (HID_KEY_VOLUME_DOWN) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x82 (HID_KEY_LOCKING_CAPS_LOCK) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x83 (HID_KEY_LOCKING_NUM_LOCK) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x84 (HID_KEY_LOCKING_SCROLL_LOCK) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x85 (HID_KEY_KEYPAD_COMMA) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x86 (HID_KEY_KEYPAD_EQUAL_SIGN) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x87 (HID_KEY_KANJI1) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x88 (HID_KEY_KANJI2) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x89 (HID_KEY_KANJI3) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x8a (HID_KEY_KANJI4) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x8b (HID_KEY_KANJI5) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x8c (HID_KEY_KANJI6) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x8d (HID_KEY_KANJI7) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x8e (HID_KEY_KANJI8) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x8f (HID_KEY_KANJI9) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x90 (HID_KEY_LANG1) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x91 (HID_KEY_LANG2) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x92 (HID_KEY_LANG3) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x93 (HID_KEY_LANG4) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x94 (HID_KEY_LANG5) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x95 (HID_KEY_LANG6) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x96 (HID_KEY_LANG7) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x97 (HID_KEY_LANG8) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x98 (HID_KEY_LANG9) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x99 (HID_KEY_ALTERNATE_ERASE) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x9a (HID_KEY_SYSREQ_ATTENTION) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x9b (HID_KEY_CANCEL) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x9c (HID_KEY_CLEAR) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x9d (HID_KEY_PRIOR) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x9e (HID_KEY_RETURN) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0x9f (HID_KEY_SEPARATOR) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xa0 (HID_KEY_OUT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xa1 (HID_KEY_OPER) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xa2 (HID_KEY_CLEAR_AGAIN) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xa3 (HID_KEY_CRSEL_PROPS) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xa4 (HID_KEY_EXSEL) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xa5 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xa6 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xa7 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xa8 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xa9 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xaa (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xab (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xac (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xad (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xae (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xaf (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xb0 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xb1 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xb2 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xb3 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xb4 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xb5 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xb6 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xb7 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xb8 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xb9 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xba (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xbb (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xbc (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xbd (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xbe (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xbf (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xc0 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xc1 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xc2 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xc3 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xc4 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xc5 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xc6 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xc7 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xc8 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xc9 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xca (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xcb (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xcc (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xcd (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xce (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xcf (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xd0 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xd1 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xd2 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xd3 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xd4 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xd5 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xd6 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xd7 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xd8 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xd9 (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xda (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xdb (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xdc (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xdd (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xde (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xdf (RESERVED) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xe0 (HID_KEY_CONTROL_LEFT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xe1 (HID_KEY_SHIFT_LEFT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xe2 (HID_KEY_ALT_LEFT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xe3 (HID_KEY_GUI_LEFT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xe4 (HID_KEY_CONTROL_RIGHT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xe5 (HID_KEY_SHIFT_RIGHT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xe6 (HID_KEY_ALT_RIGHT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xe7 (HID_KEY_GUI_RIGHT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xe8 (HID_KEY_MEDIA_PLAYPAUSE) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xe9 (HID_KEY_MEDIA_STOPCD) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xea (HID_KEY_MEDIA_PREVIOUSSONG) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xeb (HID_KEY_MEDIA_NEXTSONG) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xec (HID_KEY_MEDIA_EJECTCD) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xed (HID_KEY_MEDIA_VOLUMEUP) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xee (HID_KEY_MEDIA_VOLUMEDOWN) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xef (HID_KEY_MEDIA_MUTE) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xf0 (HID_KEY_MEDIA_WWW) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xf1 (HID_KEY_MEDIA_BACK) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xf2 (HID_KEY_MEDIA_FORWARD) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xf3 (HID_KEY_MEDIA_STOP) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xf4 (HID_KEY_MEDIA_FIND) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xf5 (HID_KEY_MEDIA_SCROLLUP) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xf6 (HID_KEY_MEDIA_SCROLLDOWN) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xf7 (HID_KEY_MEDIA_EDIT) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xf8 (HID_KEY_MEDIA_SLEEP) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xf9 (HID_KEY_MEDIA_COFFEE) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xfa (HID_KEY_MEDIA_REFRESH) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xfb (HID_KEY_MEDIA_CALC) */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xfc */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xfd */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xfe */ \
    { KP_KEY_NONE, KP_KEY_NONE, KP_KEY_NONE }, /* 0xff */ \

#define KP_HID_TABLE_LEN    256

uint8_t kaypro_get_data(uint8_t keycode, KeyboardState * state);

#endif
