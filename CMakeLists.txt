cmake_minimum_required(VERSION 3.28)

project(Haptic_Gestures)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(FindPkgConfig)

add_subdirectory(Haptic_Gestures)
add_subdirectory(tests)
add_subdirectory(examples/click_example)
add_subdirectory(examples/pid_example
)

