# rehydrated - ReXGlue Recompiled Project
#
# The SDK package provides rexglue_project and the rexglue_setup_* functions.

cmake_minimum_required(VERSION 3.25)
project(rehydrated LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (REXSDK_DIR)
  add_subdirectory("${REXSDK_DIR}" rexglue-sdk)
else ()
  find_package(rexglue 0.11.0 REQUIRED CONFIG)
endif ()
rexglue_project(rehydrated OUTPUT_DIR generated/default)

# Host sources. src/main.cpp stays on the executable.
set(REHYDRATED_HOST_SOURCES
    src/hooks.cpp
    src/rehydrated_app.cpp
    src/core/network/tcp_server.cpp
    src/core/network/tcp_session.cpp
    src/game/network/game_message_type.cpp
    src/recomp/gameplay_options.cpp
    src/recomp/input_manager.cpp
    src/recomp/static_data_dumper.cpp
    src/recomp/network/game_message_dumper.cpp
    src/recomp/network/game_message_encoder.cpp
    src/recomp/network/game_message_translator.cpp
    src/recomp/network/pc_proxy.cpp
    src/recomp/network/xdecoder.cpp
    src/recomp/network/xencoder.cpp
    src/recomp/network/xfloat16.cpp
)

# OBJECT and never STATIC, an archive drops the REX_EXPORT symbols.
add_library(rehydrated_common OBJECT ${REHYDRATED_HOST_SOURCES})
rexglue_setup_host_library(rehydrated_common)

if (WIN32)
  add_executable(rehydrated WIN32 src/main.cpp)
else ()
  add_executable(rehydrated src/main.cpp)
endif ()

rexglue_setup_target(rehydrated)
target_link_libraries(rehydrated PRIVATE rehydrated_common)

target_link_libraries(rehydrated PRIVATE ws2_32)
