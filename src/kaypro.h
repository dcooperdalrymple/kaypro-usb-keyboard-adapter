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

#include "keyboard.h"

#define KP_NULL 0xff

#define KP_CTRL_2       0x00
#define KP_CTRL_A       0x01
#define KP_CTRL_B       0x02
#define KP_CTRL_C       0x03
#define KP_CTRL_D       0x04
#define KP_CTRL_E       0x05
#define KP_CTRL_F       0x06
#define KP_CTRL_G       0x07
#define KP_CTRL_H       0x08
#define KP_CTRL_I       0x09
#define KP_CTRL_J       0x0a
#define KP_CTRL_K       0x0b
#define KP_CTRL_L       0x0c
#define KP_CTRL_M       0x0d
#define KP_CTRL_N       0x0e
#define KP_CTRL_O       0x0f
#define KP_CTRL_P       0x10
#define KP_CTRL_Q       0x11
#define KP_CTRL_R       0x12
#define KP_CTRL_S       0x13
#define KP_CTRL_T       0x14
#define KP_CTRL_U       0x15
#define KP_CTRL_V       0x16

#define KP_BACKSPACE    0x08


uint8_t kaypro_get_data(uint8_t keycode, KeyboardState * state);

#endif
