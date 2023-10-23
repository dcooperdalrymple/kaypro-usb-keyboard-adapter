/**
 * kaypro-usb-keyboard-adapter: buzzer.c
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#include "buzzer.h"

#include "hardware/gpio.h"
#include "hardware/pwm.h"

#include "config.h"

uint buzzer_slice;
uint buzzer_channel;
uint32_t buzzer_start = 0;
bool buzzer_enabled = false;

void buzzer_init(void) {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    buzzer_slice = pwm_gpio_to_slice_num(BUZZER_PIN);
    buzzer_channel = pwm_gpio_to_channel(BUZZER_PIN);

    pwm_config cfg = pwm_get_default_config();
    pwm_config_set_clkdiv(&cfg, SYSCLK_MHZ); // 1MHz
    pwm_config_set_clkdiv_mode(&cfg, PWM_DIV_FREE_RUNNING);
    pwm_init(buzzer_slice, &cfg, false);

    pwm_set_wrap(buzzer_slice, BUZZER_WRAP);
    pwm_set_phase_correct(buzzer_slice, false);
    pwm_set_chan_level(buzzer_slice, buzzer_channel, BUZZER_LEVEL);

    pwm_set_enabled(buzzer_slice, false);
};

void buzzer_update(void) {
    if (!buzzer_enabled) return;
    if (millis() - buzzer_start < BUZZER_MS) return;
    buzzer_enabled = false;
    pwm_set_enabled(buzzer_slice, false);
};

void buzzer_trigger(void) {
    buzzer_start = millis();
    buzzer_enabled = true;
    pwm_set_enabled(buzzer_slice, true);
};
