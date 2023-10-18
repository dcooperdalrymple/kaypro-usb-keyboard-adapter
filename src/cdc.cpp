/**
 * kaypro-usb-keyboard-adapter: cdc.cpp
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#include "cdc.hpp"

#include "tusb.h"
#include "bsp/board.h"

size_t get_console_inputs(uint8_t* buf, size_t bufsize) {
    size_t count = 0;
    while (count < bufsize) {
        int ch = board_getchar();
        if (ch <= 0) break;

        buf[count] = (uint8_t)ch;
        count++;
    }
    return count;
}

void cdc_app_task(void) {
    uint8_t buf[64 + 1]; // +1 for extra null character
    uint32_t const bufsize = sizeof(buf) - 1;

    uint32_t count = get_console_inputs(buf, bufsize);
    buf[count] = 0;

    // loop over all mounted interfaces
    for (uint8_t idx = 0; idx < CFG_TUH_CDC; idx++) {
        if (tuh_cdc_mounted(idx)) {
            // console --> cdc interfaces
            if (count) {
                tuh_cdc_write(idx, buf, count);
                tuh_cdc_write_flush(idx);
            }
        }
    }
}

// Invoked when received new data
void tuh_cdc_rx_cb(uint8_t idx) {
    uint8_t buf[64 + 1]; // +1 for extra null character
    uint32_t const bufsize = sizeof(buf) - 1;

    // forward cdc interfaces -> console
    uint32_t count = tuh_cdc_read(idx, buf, bufsize);
    buf[count] = 0;

    printf((char*)buf);
}

void tuh_cdc_mount_cb(uint8_t idx) {
    tuh_cdc_itf_info_t itf_info = { 0 };
    tuh_cdc_itf_get_info(idx, &itf_info);

    printf("CDC Interface is mounted: address = %u, itf_num = %u\r\n", itf_info.daddr, itf_info.bInterfaceNumber);

#ifdef CFG_TUH_CDC_LINE_CODING_ON_ENUM
    // CFG_TUH_CDC_LINE_CODING_ON_ENUM must be defined for line coding is set by tinyusb in enumeration
    // otherwise you need to call tuh_cdc_set_line_coding() first
    cdc_line_coding_t line_coding = { 0 };
    if (tuh_cdc_get_local_line_coding(idx, &line_coding)) {
        printf("  Baudrate: %lu, Stop Bits : %u\r\n", line_coding.bit_rate, line_coding.stop_bits);
        printf("  Parity  : %u, Data Width: %u\r\n", line_coding.parity  , line_coding.data_bits);
    }
#endif
}

void tuh_cdc_umount_cb(uint8_t idx) {
    tuh_cdc_itf_info_t itf_info = { 0 };
    tuh_cdc_itf_get_info(idx, &itf_info);

    printf("CDC Interface is unmounted: address = %u, itf_num = %u\r\n", itf_info.daddr, itf_info.bInterfaceNumber);
}
