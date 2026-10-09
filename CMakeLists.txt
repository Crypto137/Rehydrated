# rehydrated - ReXGlue Recompiled Project
#
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(rehydrated LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-mssse3)

include(generated/rexglue.cmake)

# Sources
set(REHYDRATED_SOURCES
    src/main.cpp
)

if(WIN32)
    add_executable(rehydrated WIN32 ${REHYDRATED_SOURCES})
else()
    add_executable(rehydrated ${REHYDRATED_SOURCES})
endif()

rexglue_setup_target(rehydrated)

target_include_directories(rehydrated SYSTEM PRIVATE
    "./thirdparty/rexglue-sdk/thirdparty/imgui"
)
