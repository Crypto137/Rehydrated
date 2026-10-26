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
    src/rehydrated_app.cpp
    src/core/network/tcp_server.cpp
    src/core/network/tcp_session.cpp
    src/game/network/game_message_type.cpp
    src/recomp/hooks.cpp
    src/recomp/static_data_dumper.cpp
    src/recomp/network/game_message_dumper.cpp
    src/recomp/network/game_message_translator.cpp
    src/recomp/network/pc_proxy.cpp
    src/recomp/network/xdecoder.cpp
    src/recomp/network/xencoder.cpp
)

if(WIN32)
    add_executable(rehydrated WIN32 ${REHYDRATED_SOURCES})
else()
    add_executable(rehydrated ${REHYDRATED_SOURCES})
endif()

rexglue_setup_target(rehydrated)

target_include_directories(rehydrated SYSTEM PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/rexglue-sdk/thirdparty/imgui"
)

target_link_libraries(rehydrated PRIVATE ws2_32)
