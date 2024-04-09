cmake_minimum_required(VERSION 3.0)
project(GraphSpMultstep)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(test)

file(GLOB SOURCES "src/*.cpp")

add_executable(GraphSpMultstep ${SOURCES})