cmake_minimum_required(VERSION 3.5)

project(tag_puzzle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

configure_file(${PROJECT_SOURCE_DIR}/res/DejaVuSansMono.ttf ${PROJECT_BINARY_DIR}/res/DejaVuSansMono.ttf COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/res/tag_icon.png ${PROJECT_BINARY_DIR}/res/tag_icon.png COPYONLY)
configure_file(${PROJECT_SOURCE_DIR}/res/Wallpaper.ogg ${PROJECT_BINARY_DIR}/res/Wallpaper.ogg COPYONLY)

configure_file(${PROJECT_SOURCE_DIR}/res/icon.svg ${PROJECT_BINARY_DIR}/res/icon.svg COPYONLY)

configure_file(${PROJECT_SOURCE_DIR}/res/tag_puzzle.desktop ${PROJECT_BINARY_DIR}/res/tag_puzzle.desktop COPYONLY)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_executable(tag_puzzle src/main.cpp src/tag_puzzle.cpp src/tag_puzzle.hpp)

target_link_libraries(tag_puzzle sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

install(TARGETS tag_puzzle DESTINATION /usr/bin)

install(FILES ${PROJECT_SOURCE_DIR}/res/DejaVuSansMono.ttf ${PROJECT_SOURCE_DIR}/res/tag_icon.png ${PROJECT_SOURCE_DIR}/res/icon.svg ${PROJECT_SOURCE_DIR}/res/Wallpaper.ogg DESTINATION /usr/share/tag_game/res/)

install(FILES ${PROJECT_SOURCE_DIR}/res/tag_puzzle.desktop DESTINATION /usr/share/applications/tag_puzzle.desktop)
