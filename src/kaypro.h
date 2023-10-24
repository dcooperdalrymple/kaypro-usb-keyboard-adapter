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

#define KP_NULL 0xff

#define KP_CTRL_2               0x00
#define KP_CTRL_A               0x01
#define KP_CTRL_B               0x02
#define KP_CTRL_C               0x03
#define KP_CTRL_D               0x04
#define KP_CTRL_E               0x05
#define KP_CTRL_F               0x06
#define KP_CTRL_G               0x07
#define KP_CTRL_H               0x08
#define KP_CTRL_I               0x09
#define KP_CTRL_J               0x0a
#define KP_CTRL_K               0x0b
#define KP_CTRL_L               0x0c
#define KP_CTRL_M               0x0d
#define KP_CTRL_N               0x0e
#define KP_CTRL_O               0x0f
#define KP_CTRL_P               0x10
#define KP_CTRL_Q               0x11
#define KP_CTRL_R               0x12
#define KP_CTRL_S               0x13
#define KP_CTRL_T               0x14
#define KP_CTRL_U               0x15
#define KP_CTRL_V               0x16
#define KP_CTRL_W               0x17
#define KP_CTRL_X               0x18
#define KP_CTRL_Y               0x19
#define KP_CTRL_Z               0x1a
#define KP_CTRL_LEFTBRACKET     0x1b
#define KP_CTRL_BACKSLASH       0x1c
#define KP_CTRL_RIGHTBRACKET    0x1d
#define KP_CTRL_6               0x1e
#define KP_CTRL_DASH            0x1f
#define KP_SPACE                0x20
#define KP_EXCLAMATION          0x21
#define KP_DOUBLEQUOTE          0x22
#define KP_HASH                 0x23
#define KP_DOLLAR               0x24
#define KP_PERCENT              0x25
#define KP_AMPERSAND            0x26
#define KP_SINGLEQUOTE          0x27
#define KP_LEFTPARENTHESES      0x28
#define KP_RIGHTPARENTHESES     0x29
#define KP_ASTERISK             0x2a
#define KP_PLUS                 0x2b
#define KP_COMMA                0x2c
#define KP_DASH                 0x2d
#define KP_PERIOD               0x2e
#define KP_FORWARDSLASH         0x2f
#define KP_0                    0x30
#define KP_1                    0x31
#define KP_2                    0x32
#define KP_3                    0x33
#define KP_4                    0x34
#define KP_5                    0x35
#define KP_6                    0x36
#define KP_7                    0x37
#define KP_8                    0x38
#define KP_9                    0x39
#define KP_COLON                0x3a
#define KP_SEMICOLON            0x3b
#define KP_LESSTHAN             0x3c
#define KP_EQUALS               0x3d
#define KP_GREATERTHAN          0x3e
#define KP_QUESTION             0x3f
#define KP_AT                   0x40
#define KP_A                    0x41
#define KP_B                    0x42
#define KP_C                    0x43
#define KP_D                    0x44
#define KP_E                    0x45
#define KP_F                    0x46
#define KP_G                    0x47
#define KP_H                    0x48
#define KP_I                    0x49
#define KP_J                    0x4a
#define KP_K                    0x4b
#define KP_L                    0x4c
#define KP_M                    0x4d
#define KP_N                    0x4e
#define KP_O                    0x4f
#define KP_P                    0x50
#define KP_Q                    0x51
#define KP_R                    0x52
#define KP_S                    0x53
#define KP_T                    0x54
#define KP_U                    0x55
#define KP_V                    0x56
#define KP_W                    0x57
#define KP_X                    0x58
#define KP_Y                    0x59
#define KP_Z                    0x5a
#define KP_LEFTBRACKET          0x5b
#define KP_BACKSLASH            0x5c
#define KP_RIGHTBRACKET         0x5d
#define KP_CARET                0x5e
#define KP_UNDERSCORE           0x5f
#define KP_BACKTICK             0x60
#define KP_a                    0x61
#define KP_b                    0x62
#define KP_c                    0x63
#define KP_d                    0x64
#define KP_e                    0x65
#define KP_f                    0x66
#define KP_g                    0x67
#define KP_h                    0x68
#define KP_i                    0x69
#define KP_j                    0x6a
#define KP_k                    0x6b
#define KP_l                    0x6c
#define KP_m                    0x6d
#define KP_n                    0x6e
#define KP_o                    0x6f
#define KP_p                    0x70
#define KP_q                    0x71
#define KP_r                    0x72
#define KP_s                    0x73
#define KP_t                    0x74
#define KP_u                    0x75
#define KP_v                    0x76
#define KP_w                    0x77
#define KP_x                    0x78
#define KP_y                    0x79
#define KP_z                    0x7a
#define KP_LEFTCURLYBRACKET     0x7b
#define KP_PIPE                 0x7c
#define KP_RIGHTCURLYBRACKET    0x7d
#define KP_TILDE                0x7e
#define KP_DEL                  0x7f
#define KP_NUMPAD_0             0x81
#define KP_NUMPAD_PERIOD        0x82
#define KP_NUMPAD_1             0xc0
#define KP_NUMPAD_2             0xc1
#define KP_NUMPAD_3             0xc2
#define KP_NUMPAD_ENTER         0xc3
#define KP_NUMPAD_4             0xd0
#define KP_NUMPAD_5             0xd1
#define KP_NUMPAD_6             0xd2
#define KP_NUMPAD_COMMA         0xd3
#define KP_NUMPAD_7             0xe1
#define KP_NUMPAD_8             0xe2
#define KP_NUMPAD_9             0xe3
#define KP_NUMPAD_DASH          0xe4
#define KP_CUR_UP               0xf1
#define KP_CUR_DOWN             0xf2
#define KP_CUR_LEFT             0xf3
#define KP_CUR_RIGHT            0xf4

// Duplicates
#define KP_BACKSPACE            0x08
#define KP_TAB                  0x09
#define KP_LINEFEED             0x0a
#define KP_RETURN               0x0d
#define KP_ESC                  0x1b

#define KP_KEYCODE_TABLE \
    { HID_KEY_1, KP_1, KP_EXCLAMATION }, \
    { HID_KEY_2, KP_2, KP_AT }, \
    { HID_KEY_3, KP_3, KP_HASH }, \
    { HID_KEY_4, KP_4, KP_DOLLAR }, \
    { HID_KEY_5, KP_5, KP_PERCENT }, \
    { HID_KEY_6, KP_6, KP_CARET }, \
    { HID_KEY_7, KP_7, KP_AMPERSAND }, \
    { HID_KEY_8, KP_8, KP_ASTERISK }, \
    { HID_KEY_9, KP_9, KP_LEFTPARENTHESES }, \
    { HID_KEY_0, KP_0, KP_RIGHTPARENTHESES }, \
    { HID_KEY_ENTER, KP_RETURN, KP_RETURN }, \
    { HID_KEY_ESCAPE, KP_ESC, KP_ESC }, \
    { HID_KEY_BACKSPACE, KP_BACKSPACE, KP_BACKSPACE }, \
    { HID_KEY_TAB, KP_TAB, KP_TAB }, \
    { HID_KEY_SPACE, KP_SPACE, KP_SPACE }, \
    { HID_KEY_MINUS, KP_DASH, KP_UNDERSCORE }, \
    { HID_KEY_EQUAL, KP_EQUALS, KP_PLUS }, \
    { HID_KEY_BRACKET_LEFT, KP_LEFTBRACKET, KP_LEFTCURLYBRACKET }, \
    { HID_KEY_BRACKET_RIGHT, KP_RIGHTBRACKET, KP_RIGHTCURLYBRACKET }, \
    { HID_KEY_BACKSLASH, KP_BACKSLASH, KP_PIPE }, \
    { HID_KEY_SEMICOLON, KP_SEMICOLON, KP_COLON }, \
    { HID_KEY_APOSTROPHE, KP_SINGLEQUOTE, KP_DOUBLEQUOTE }, \
    { HID_KEY_GRAVE, KP_BACKTICK, KP_TILDE }, \
    { HID_KEY_COMMA, KP_COMMA, KP_LESSTHAN }, \
    { HID_KEY_PERIOD, KP_PERIOD, KP_GREATERTHAN }, \
    { HID_KEY_SLASH, KP_FORWARDSLASH, KP_QUESTION }, \
    { HID_KEY_DELETE, KP_DEL, KP_DEL }, \
    { HID_KEY_ARROW_RIGHT, KP_CUR_RIGHT, KP_CUR_RIGHT }, \
    { HID_KEY_ARROW_LEFT, KP_CUR_LEFT, KP_CUR_LEFT }, \
    { HID_KEY_ARROW_DOWN, KP_CUR_DOWN, KP_CUR_DOWN }, \
    { HID_KEY_ARROW_UP, KP_CUR_UP, KP_CUR_UP }, \
    { HID_KEY_KEYPAD_SUBTRACT, KP_NUMPAD_DASH, KP_NUMPAD_DASH }, \
    { HID_KEY_KEYPAD_ENTER, KP_NUMPAD_ENTER, KP_NUMPAD_ENTER }, \
    { HID_KEY_KEYPAD_1, KP_NUMPAD_1, KP_NUMPAD_1 }, \
    { HID_KEY_KEYPAD_2, KP_NUMPAD_2, KP_NUMPAD_2 }, \
    { HID_KEY_KEYPAD_3, KP_NUMPAD_3, KP_NUMPAD_3 }, \
    { HID_KEY_KEYPAD_4, KP_NUMPAD_4, KP_NUMPAD_4 }, \
    { HID_KEY_KEYPAD_5, KP_NUMPAD_5, KP_NUMPAD_5 }, \
    { HID_KEY_KEYPAD_6, KP_NUMPAD_6, KP_NUMPAD_6 }, \
    { HID_KEY_KEYPAD_7, KP_NUMPAD_7, KP_NUMPAD_7 }, \
    { HID_KEY_KEYPAD_8, KP_NUMPAD_8, KP_NUMPAD_8 }, \
    { HID_KEY_KEYPAD_9, KP_NUMPAD_9, KP_NUMPAD_9 }, \
    { HID_KEY_KEYPAD_0, KP_NUMPAD_0, KP_NUMPAD_0 }, \
    { HID_KEY_KEYPAD_DECIMAL, KP_NUMPAD_PERIOD, KP_NUMPAD_PERIOD }, \
    { HID_KEY_KEYPAD_COMMA, KP_NUMPAD_COMMA, KP_NUMPAD_COMMA }, \

#define KP_KEYCODE_TABLE_LEN    45

uint8_t kaypro_get_data(uint8_t keycode, KeyboardState * state);

#endif
