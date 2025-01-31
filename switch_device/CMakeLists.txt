cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(switch)

# Add all .c files in src directory to the build
FILE(GLOB app_sources src/*.c dk_buttons_and_leds/*.c)
target_sources(app PRIVATE ${app_sources})

# Include the src directory for header files
target_include_directories(app PRIVATE interface include)

zephyr_include_directories(dk_buttons_and_leds)

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})


# Add the dk_buttons_and_leds directory to Zephyr modules
list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_SOURCE_DIR}/dk_buttons_and_leds)

# Set Openthread Module variables
#set(ZEPHYR_OPENTHREAD_MODULE /opnethread)