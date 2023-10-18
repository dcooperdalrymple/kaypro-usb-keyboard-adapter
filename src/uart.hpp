/**
 * kaypro-usb-keyboard-adapter: uart.hpp
 * @author Cooper Dalrymple
 * @version 1.0
 * @since 1.0
 */

#pragma once

class Uart {

public:

    Uart();
    ~Uart();

    void sendByte(uint8_t val);

}
