
cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(basic_usage C CXX ASM)

pico_sdk_init()

add_executable(basic_usage
    main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/rgbled.cpp
)

target_include_directories (basic_usage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../src)

target_link_libraries(basic_usage pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(basic_usage 1)
pico_enable_stdio_uart(basic_usage 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(basic_usage)
