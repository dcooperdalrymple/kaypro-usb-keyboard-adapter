cmake_minimum_required(VERSION 3.13)

set(NAME kaypro-usb)
set(DESC "Kaypro USB Keyboard Adapter")
set(VERSION "1.0")
set(URL "https://github.com/dcooperdalrymple/kaypro-usb-keyboard-adapter")

# initialize pico-sdk from GIT
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_FETCH_FROM_GIT on)

# pico_sdk_import.cmake is a single file copied from this SDK
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(${NAME}
    src/hid.cpp
    src/cdc.cpp
    src/main.cpp
)

# Make sure TinyUSB can find tusb_config.h
target_include_directories(${NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

# In addition to pico_stdlib required for common PicoSDK functionality, add dependency on tinyusb_host
# for TinyUSB device support and tinyusb_board for the additional board support library used by the example
target_link_libraries(${NAME}
    pico_stdlib
    hardware_gpio
    hardware_uart
    tinyusb_host
    tinyusb_board
    pico_multicore
)

#pico_enable_stdio_usb(${NAME} 1)
#pico_enable_stdio_uart(${NAME} 0)

pico_add_extra_outputs(${NAME})

pico_set_program_name(${NAME} ${DESC})
pico_set_program_version(${NAME} ${VERSION})
pico_set_program_url(${NAME} ${URL})
