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

const char* const program_description = "Kaypro USB Keyboard Adapter v1.0";

static usb_device_t *usb_device = NULL;

void core1_main(void);

void usb_main(void);
void read_keyboard_state(uint8_t * data);
void print_keyboard_state(void);
void led_main(void);

int main() {
    // default 125MHz is not appropreate. Sysclock should be multiple of 12MHz.
    set_sys_clock_khz(120000, true);

    // picotool declarations
    bi_decl(bi_program_description(program_description));

    stdio_init_all();
    printf(program_description);
    printf("\r\n");

    sleep_ms(10);

    multicore_reset_core1();
    // All USB task run in core1
    multicore_launch_core1(core1_main);

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (1) {
        usb_main();
        led_main();

        stdio_flush();
        sleep_us(10);
    }

    return 0;
}

void usb_main(void) {
    if (usb_device == NULL) return;

    for (int dev_idx = 0; dev_idx < PIO_USB_DEVICE_CNT; dev_idx++) {
        usb_device_t *device = &usb_device[dev_idx];
        if (!device->connected) continue;

        // Print received packet to EPs
        for (int ep_idx = 0; ep_idx < PIO_USB_DEV_EP_CNT; ep_idx++) {
            endpoint_t *ep = pio_usb_get_endpoint(device, ep_idx);

            if (ep == NULL) break;

            uint8_t temp[64];
            int len = pio_usb_get_in_data(ep, temp, sizeof(temp));

            // Logitech Unified Receiver
            if (device->vid == 0x046d && device->pid == 0xc52b && ep->ep_num == 0x81 && len == 8) {
                read_keyboard_state(temp);
                print_keyboard_state();
            }
        }
    }
}

struct {
    bool ctrl;
    bool shift;
    bool caps;
    uint8_t keys[6];
    uint8_t num_keys;
} keyboardState;

// https://kevinboone.me/pico_usb_kbd_lcd.html?i=1
// https://www.win.tue.nl/~aeb/linux/kbd/scancodes-14.html
void read_keyboard_state(uint8_t * data) {
    uint8_t i;

    keyboardState.ctrl = data[0] & 0x01;
    keyboardState.shift = data[0] & 0x02;

    keyboardState.num_keys = 6;
    for (i = 0; i < 6; i++) {
        if (data[i+2] != 0x00) continue;
        keyboardState.num_keys = i;
        break;
    }
    for (i = 0; i < 6; i++) {
        keyboardState.keys[i] = data[i+2];
    }
}

void print_keyboard_state() {
    printf("CTRL = ");
    if (keyboardState.ctrl) {
        printf("ON\r\n");
    } else {
        printf("OFF\r\n");
    }

    printf("SHIFT = ");
    if (keyboardState.shift) {
        printf("ON\r\n");
    } else {
        printf("OFF\r\n");
    }

    printf("KEYS = %d\r\n", keyboardState.num_keys);
    for (uint8_t i = 0; i < keyboardState.num_keys; i++) {
        printf("%02x ", keyboardState.keys[i]);
    }
    printf("\r\n\r\n");
}

void led_main(void) {
    const uint32_t interval_ms = 1000;
    static uint32_t start_ms = to_ms_since_boot(get_absolute_time());

    static bool led_state = false;

    if (to_ms_since_boot(get_absolute_time()) - start_ms < interval_ms) return;
    start_ms += interval_ms;

    led_state = !led_state;
    gpio_put(LED_PIN, led_state);
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
