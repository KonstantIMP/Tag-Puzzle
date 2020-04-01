cmake_minimum_required(VERSION 3.5)

project(tag_puzzle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(tag_puzzle main.cpp tag_puzzle.cpp tag_puzzle.hpp)

target_link_libraries(tag_puzzle sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
