# Kaypro USB Keyboard Adapter
Adapter for the Kaypro 2 to replace the original keyboard with a USB keyboard. Uses the Raspberry Pi Pico as a USB host and for serial communication to the RJ11 port on the Kaypro.

## Compiling Firmware

* Configuring: `cmake -B build -S .`
* Compiling/Building: `make -C build`
* Writing: Hold BOOTSEL button on Pico, plug it in via USB, and release BOOTSEL. Copy and paste `kaypro-usb.uf2` into RPI-RP2 drive.
