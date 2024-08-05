cmake_minimum_required(VERSION 3.28)
project(DiamondRush)

set(SDL2_IMAGE_LIBRARIES "/usr/local/lib/libSDL2_image.so")

set(SourceFiles
        main.cpp
)

set(libraries
        Resource
        Display
        Logic)

# package
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# include
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})


# Add subdirectory for the App module
add_subdirectory(Resource)
add_subdirectory(Display)
add_subdirectory(Logic)

# excutable
add_executable(${PROJECT_NAME} ${SourceFiles})

# link library
target_link_libraries(${PROJECT_NAME} ${libraries} SDL2::SDL2 ${SDL2_IMAGE_LIBRARIES})

#set(SDL_VIDEODRIVER wayland)





