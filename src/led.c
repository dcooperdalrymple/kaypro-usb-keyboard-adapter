/**
 * kaypro-usb-keyboard-adapter: led.c
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#include "led.h"

#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

#include "config.h"

uint led_slice;
uint led_channel;
bool led_connected = false;
bool led_capslock = false;

void led_init(void) {
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    led_slice = pwm_gpio_to_slice_num(LED_PIN);
    led_channel = pwm_gpio_to_channel(LED_PIN);

    pwm_config cfg = pwm_get_default_config();
    pwm_config_set_clkdiv(&cfg, SYSCLK_MHZ); // 1MHz
    pwm_config_set_clkdiv_mode(&cfg, PWM_DIV_FREE_RUNNING);
    pwm_init(led_slice, &cfg, false);

    pwm_set_wrap(led_slice, 255);
    pwm_set_phase_correct(led_slice, false);
    pwm_set_chan_level(led_slice, led_channel, 0);

    pwm_set_enabled(led_slice, true);
};

void led_update(void) {
    uint16_t value = 0;
    if (led_connected && led_capslock) {
        value = 256;
    } else if (led_connected) {
        value = 64;
    }
    pwm_set_chan_level(led_slice, led_channel, value);
};

void led_set_connected(bool connected) {
    led_connected = connected;
    led_update();
};

void led_set_capslock(bool capslock) {
    led_capslock = capslock;
    led_update();
};
