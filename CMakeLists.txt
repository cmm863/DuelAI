cmake_minimum_required(VERSION 2.8.4)
project(DuelAI)

include(FindProtobuf)

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#the actual source directory
include_directories(..)

set(pbuf_sources
    gamestate.pb.cc
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ai.cpp
    ai.h
    baseai.h
    baseai.cpp
    coordinate.h
    coordinate.cpp
    gameconstants.h
    gamestatehandler.cpp
    gamestatehandler.h
    main.cpp
    mappable.cpp
    mappable.h
    protohandler.cpp
    protohandler.h
    tile.cpp
    tile.h
    unit.cpp
    unit.h)

add_executable(DuelAI ${SOURCE_FILES} ${pbuf_sources})
target_link_libraries(DuelAI ${PROTOBUF_LIBRARY})