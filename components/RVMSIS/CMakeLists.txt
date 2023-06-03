cmake_minimum_required(VERSION 3.12.4)

project(rvmsis)

# Option to build as shared library (as opposed to static), default: OFF
option(BUILD_SHARED_LIBS "Build shared as library (as opposed to static)" OFF)

file(GLOB_RECURSE SOURCES ./*.c)

if (BUILD_SHARED_LIBS)
  add_library(rvmsis SHARED ${SOURCES})
else()
  add_library(rvmsis STATIC ${SOURCES})
endif()

target_include_directories(rvmsis SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
