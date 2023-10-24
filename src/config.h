/**
 * kaypro-usb-keyboard-adapter: config.h
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#define SYSCLK_MHZ          120
#define SYSCLK_KHZ          SYSCLK_MHZ*1000

// UART Serial
#define UART_ID             uart1
#define UART_BAUD_RATE      300
#define UART_TX_PIN         4
#define UART_RX_PIN         5
#define UART_BUFFER_SIZE    32
#define UART_DATA_BITS      8
#define UART_STOP_BITS      1
#define UART_PARITY         0

#define LED_PIN             25

#define BUZZER_PIN          21
#define BUZZER_FREQ         60
#define BUZZER_MS           20
#define BUZZER_DUTY         0.5

#define millis()            (to_ms_since_boot(get_absolute_time()))

#endif
