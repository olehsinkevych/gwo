cmake_minimum_required(VERSION 3.26)
project(gwo C)

set(CMAKE_C_STANDARD 11)

add_executable(gwo main.c
        functions.c
        utils.c
        wolves_pack.c
        gwo.c)

target_link_libraries(gwo m)