cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(untitled main.cpp Screen.cpp Screen.h Rectangle.cpp Rectangle.h Swarm.cpp Swarm.h util.h util.cpp Particle.cpp Particle.h)
target_link_libraries(untitled ${SDL2_LIBRARIES})