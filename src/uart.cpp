/**
 * kaypro-usb-keyboard-adapter: uart.cpp
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#include "uart.hpp"

#include "pico/stdlib.h"
#include "config.h"

Uart::Uart() {

    // Set UART speed
    uart_init(UART_ID, BAUD_RATE);

    // Set UART pins
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    // Enable Tx and Rx FIFOs on UART
    uart_set_fifo_enabled(UART_ID, true);

    // Disable cr/lf conversion on Tx
    uart_set_translate_crlf(UART_ID, false);

    setChannel(MIDI_CHANNEL);

};

Uart::~Uart() {

};

void Uart::sendByte(uint8_t val) {
    while (!uart_is_writable(UART_ID)) { } // blocking
    uart_putc_raw(UART_ID, val);
};
