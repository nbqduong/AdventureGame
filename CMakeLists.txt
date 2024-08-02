cmake_minimum_required(VERSION 3.28)
project(DiamondRush)

set(SourceFiles
        main.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SourceFiles})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
set(SDL_VIDEODRIVER wayland)