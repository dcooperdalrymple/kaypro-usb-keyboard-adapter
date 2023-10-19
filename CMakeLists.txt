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

# include pico-pio-usb library
set(PICO_PIO_USB_DIR "${CMAKE_CURRENT_LIST_DIR}/Pico-PIO-USB")
add_subdirectory(${PICO_PIO_USB_DIR} pico_pio_usb)

add_executable(${NAME}
    src/main.cpp
)

pico_enable_stdio_usb(${NAME} 1)

target_link_libraries(${NAME}
    pico_stdlib
    pico_pio_usb
    hardware_gpio
    hardware_uart
    pico_multicore
)

pico_add_extra_outputs(${NAME})

pico_set_program_name(${NAME} ${DESC})
pico_set_program_version(${NAME} ${VERSION})
pico_set_program_url(${NAME} ${URL})
