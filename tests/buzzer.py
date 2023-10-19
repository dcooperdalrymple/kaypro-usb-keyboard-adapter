import time
import board
import digitalio
import pwmio

frequency = 110
duration = 0.01
repeat = 2.0

buzzer = pwmio.PWMOut(board.GP21, frequency=frequency, duty_cycle=0)

while True:
    buzzer.duty_cycle = int(65535/2)
    time.sleep(duration)
    buzzer.duty_cycle = 0
    time.sleep(repeat-duration)
