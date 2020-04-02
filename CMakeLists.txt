cmake_minimum_required(VERSION 3.5)

project(tag_puzzle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(${PROJECT_SOURCE_DIR}/res/DejaVuSansMono.ttf ${PROJECT_BINARY_DIR}/res/DejaVuSansMono.ttf COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/res/tag_icon.png ${PROJECT_BINARY_DIR}/res/tag_icon.png COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/res/Wallpaper.ogg ${PROJECT_BINARY_DIR}/res/Wallpaper.ogg COPYONLY)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(tag_puzzle src/main.cpp src/tag_puzzle.cpp src/tag_puzzle.hpp)

target_link_libraries(tag_puzzle sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
