cmake_minimum_required(VERSION 3.12)

set(ROOT_DIR ${CMAKE_CURRENT_LIST_DIR}/../../)
set(CMAKE_TOOLCHAIN_FILE ${ROOT_DIR}/toolchain-rv32.cmake)

project(hello_world)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(${ROOT_DIR}/common common)
target_link_libraries(${PROJECT_NAME} PRIVATE common)

target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wextra)

include(${ROOT_DIR}/utils.cmake)
add_linker_scripts(${PROJECT_NAME})
add_map_file(${PROJECT_NAME} ${PROJECT_NAME}.map)
make_binary(${PROJECT_NAME} ${PROJECT_NAME}.bin)
