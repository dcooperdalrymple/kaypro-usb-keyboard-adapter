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
#include "uart.h"

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
            if (ep_num != EP_NUM_KEYBOARD) continue;

            uint8_t temp[64];
            int len = pio_usb_get_in_data(ep, temp, sizeof(temp));
            if (len != 8) continue;

            keyboard_update(temp);
            keyboard_print();
        }
    }

    led_set_connected(has_connected);
}

void keyboard_press(uint8_t keycode, KeyboardState * state) {
    printf("PRESS = %02x\r\n", keycode);
    led_set_capslock(state->capslock);
    buzzer_trigger();
}
void keyboard_release(uint8_t keycode, KeyboardState * state) {
    printf("RELEASE = %02x\r\n", keycode);
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
