cmake_minimum_required(VERSION 3.28)
project(DiamondRush)

set(SDL2_IMAGE_LIBRARIES "/usr/local/lib/libSDL2_image.so")

set(SourceFiles
        main.cpp
)

set(libraries
        Display
        Logic
        Include
)

# package
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# include
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
# Specify include directories for the executable




# Add subdirectory for the App module
add_subdirectory(Include)
add_subdirectory(Display)
add_subdirectory(Logic)


# excutable
add_executable(${PROJECT_NAME} ${SourceFiles})

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/Include
)

# link library
target_link_libraries(${PROJECT_NAME} PUBLIC ${libraries} SDL2::SDL2 ${SDL2_IMAGE_LIBRARIES})

#set(SDL_VIDEODRIVER wayland)





