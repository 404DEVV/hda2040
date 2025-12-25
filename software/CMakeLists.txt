cmake_minimum_required(VERSION 3.13)

# Pull in Pico SDK (required)
include(pico_sdk_import.cmake)

project(my_project C CXX ASM)

# Initialize the Pico SDK
pico_sdk_init()

# Add your main.c executable
add_executable(hda
    main.c
)
pico_generate_pio_header(hda ${CMAKE_CURRENT_LIST_DIR}/pio_hda_clk.pio)
# Link standard Pico libraries
target_link_libraries(hda pico_stdlib hardware_pio)

# Generate UF2/bin/etc.
pico_add_extra_outputs(hda)
