/**
 * kaypro-usb-keyboard-adapter: main.cpp
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "pico/multicore.h"
#include "pico/bootrom.h"
#include "hardware/gpio.h"

#include "pio_usb.h"

#include "config.h"
#include "keyboard.h"
#include "led.h"
#include "buzzer.h"
#include "kaypro.h"
#include "uart.h"

//#define DEBUG
//#define DEBUG_PUTCHAR

#define EP_NUM_KEYBOARD 0x81

const char* const program_description = "Kaypro USB Keyboard Adapter v1.0";

static usb_device_t *usb_device = NULL;

void usb_main(void);
void core1_main(void);

int main() {
    // Default system clock of 125MHz is not appropriate, should be multiple of 12MHz.
    set_sys_clock_khz(SYSCLK_KHZ, true);

    // picotool declarations
    bi_decl(bi_program_description(program_description));

    stdio_init_all();
    printf(program_description);
    printf("\r\n");

    sleep_ms(10);

    multicore_reset_core1();
    // All USB task run in core1
    multicore_launch_core1(core1_main);

    led_init();
    buzzer_init();
    uart_start();

    while (1) {
        usb_main();
        buzzer_update();

        stdio_flush();
        sleep_us(10);
    }

    return 0;
}

void usb_main(void) {
    if (usb_device == NULL) return;

    bool has_connected = false;

    for (int dev_idx = 0; dev_idx < PIO_USB_DEVICE_CNT; dev_idx++) {
        usb_device_t *device = &usb_device[dev_idx];
        if (!device->connected) continue;

        has_connected = true;

        // Print received packet to EPs
        for (int ep_idx = 0; ep_idx < PIO_USB_DEV_EP_CNT; ep_idx++) {
            endpoint_t *ep = pio_usb_get_endpoint(device, ep_idx);
            if (ep == NULL) break;
            if (ep->ep_num != EP_NUM_KEYBOARD) continue;

            uint8_t temp[64];
            int len = pio_usb_get_in_data(ep, temp, sizeof(temp));
            if (len != 8) continue;

            keyboard_update(temp);
            #ifdef DEBUG
            keyboard_print();
            #endif
        }
    }

    led_set_connected(has_connected);
}

void keyboard_press(uint8_t keycode, KeyboardState * state) {
    led_set_capslock(state->capslock);

    uint8_t ch = keyboard_get_ascii(keycode, state);
    uint8_t data = kaypro_get_data(keycode, state);

    #ifdef DEBUG
    printf(":: PRESS ::\r\n");
    printf("HID = %02x\r\n", keycode);
    printf("ASCII = %02x\r\n", ch);
    printf("KAYPRO = %02x\r\n", data);
    #endif

    #ifdef DEBUG_PUTCHAR
    if (ch) putchar(ch);
    #endif

    if (data != KP_KEY_NONE) {
        uart_write(data);
        buzzer_trigger();
    }
}
void keyboard_release(uint8_t keycode, KeyboardState * state) {
    #ifdef DEBUG
    uint8_t ch = keyboard_get_ascii(keycode, state);
    uint8_t data = kaypro_get_data(keycode, state);

    printf(":: RELEASE ::\r\n");
    printf("HID = %02x\r\n", keycode);
    printf("ASCII = %02x\r\n", ch);
    printf("KAYPRO = %02x\r\n", data);
    #endif
}

void core1_main(void) {
    sleep_ms(10);

    // To run USB SOF interrupt in core1, create alarm pool in core1.
    static pio_usb_configuration_t config = PIO_USB_DEFAULT_CONFIG;
    config.alarm_pool = (void*)alarm_pool_create(2, 1);
    usb_device = pio_usb_host_init(&config);

    while (1) {
        pio_usb_host_task();
    }
}
