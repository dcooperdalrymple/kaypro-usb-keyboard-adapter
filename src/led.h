/**
 * kaypro-usb-keyboard-adapter: led.h
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#ifndef LED_H_
#define LED_H_

#include <stdlib.h>
#include "pico/stdlib.h"

void led_init(void);
void led_set_connected(bool connected);
void led_set_capslock(bool capslock);

#endif
