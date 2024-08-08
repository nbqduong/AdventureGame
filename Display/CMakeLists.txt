set(libname "Display")

set(SOURCES_FILES
        Hero.cpp
        Windows.cpp
        TextureManager.cpp
        Deco.cpp
        ObjectFactory.cpp
        ObjectFactory.h

)

set(INTERNAL_LIBS
        Include
        Input
        Arrange
)

set(SDL2_IMAGE_LIBRARIES "/usr/local/lib/libSDL2_image.so")
# Create a static library for the App module
add_library(${libname} SHARED ${SOURCES_FILES})

# Specify include directories for this library
target_include_directories(${libname}  PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/Include
)

# package
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# include
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# If AppLib depends on other libraries, link them here
target_link_libraries(${libname}  PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${INTERNAL_LIBS})