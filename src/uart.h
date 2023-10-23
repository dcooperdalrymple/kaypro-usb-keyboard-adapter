/**
 * kaypro-usb-keyboard-adapter: uart.h
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#ifndef UART_H_
#define UART_H_

#include <stdlib.h>
#include "pico/stdlib.h"

void uart_start(void);
void uart_write(uint8_t val);

#endif
