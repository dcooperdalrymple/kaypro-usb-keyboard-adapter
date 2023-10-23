/**
 * kaypro-usb-keyboard-adapter: buzzer.h
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZER_WRAP (1000000/BUZZER_FREQ)
#define BUZZER_LEVEL (BUZZER_WRAP*BUZZER_DUTY)

void buzzer_init(void);
void buzzer_update(void);
void buzzer_trigger(void);

#endif
