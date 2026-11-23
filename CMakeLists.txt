cmake_minimum_required(VERSION 3.20)
project(state_machine VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(state_machine_lib STATIC
    src/entry.c
    src/map.c
    src/state_machine.c
)

target_include_directories(state_machine_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(state_machine example/main.c)

add_executable(state_machine_test test/map_test.c)

target_link_libraries(state_machine_test
    PRIVATE
    state_machine_lib
)

target_link_libraries(state_machine
    PRIVATE
    state_machine_lib
)

# my_test_framework library linking code
find_package(my_test_framework REQUIRED)

target_link_libraries(state_machine_lib
    PRIVATE
        my_test_framework::my_test_framework
)
