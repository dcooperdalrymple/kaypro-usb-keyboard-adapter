/**
 * kaypro-usb-keyboard-adapter: main.cpp
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "pico/multicore.h"

// USB
#include <stdlib.h>
#include <string.h>
#include "bsp/board.h"
#include "tusb.h"

#include "config.h"
#include "cdc.hpp"
#include "hid.hpp"

// LED
#include "hardware/gpio.h"

const char* const program_description = "Kaypro USB Keyboard Adapter v1.0";

void core1_main(void);

int main() {
    board_init();

    // picotool declarations
    bi_decl(bi_program_description(program_description));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

    // start up second core
    multicore_launch_core1(core1_main);

    printf(program_description);
    printf("\r\n");

    // init host stack on configured roothub port
    tuh_init(BOARD_TUH_RHPORT);

    while (1) {
        // TinyUSB host task
        tuh_task();

        cdc_app_task();
        hid_app_task();
    }

    return 0;
}

// TinyUSB Callbacks

void tuh_mount_cb(uint8_t dev_addr) {
    // application set-up
    printf("A device with address %d is mounted\r\n", dev_addr);
}

void tuh_umount_cb(uint8_t dev_addr) {
    // application tear-down
    printf("A device with address %d is unmounted\r\n", dev_addr);
}

void core1_main(void) {
    const uint32_t interval_ms = 1000;
    uint32_t start_ms = 0;

    bool led_state = false;
    board_led_write(led_state);

    while (1) {
        if (board_millis() - start_ms >= interval_ms) {
            start_ms += interval_ms;

            led_state = !led_state;
            board_led_write(led_state);
        }
    }
}
