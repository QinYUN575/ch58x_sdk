cmake_minimum_required(VERSION 3.12)

set(ROOT_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../)
set(CMAKE_TOOLCHAIN_FILE ${ROOT_DIR}/toolchain-rv32.cmake)

project(adc)
add_definitions(-DDEBUG)

link_directories(${ROOT_DIR}/components/StdPeriphDriver)
add_subdirectory(${ROOT_DIR}/common common)
add_subdirectory(${ROOT_DIR}/components/RVMSIS rvmsis)
add_subdirectory(${ROOT_DIR}/components/StdPeriphDriver drivers)

add_executable(${PROJECT_NAME} main.c)

link_directories(${ROOT_DIR}/components/StdPeriphDriver)
target_link_libraries(${PROJECT_NAME} PRIVATE common drivers rvmsis libISP583.a)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${ROOT_DIR}/components/StdPeriphDriver/inc)
target_include_directories(${PROJECT_NAME} PUBLIC ${ROOT_DIR}/components/RVMSIS)
include(${ROOT_DIR}/utils.cmake)

add_linker_scripts(${PROJECT_NAME})
add_map_file(${PROJECT_NAME} ${PROJECT_NAME}.map)
make_binary(${PROJECT_NAME} ${PROJECT_NAME}.bin)
