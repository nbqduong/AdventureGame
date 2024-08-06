set(libname "Logic")

set(SOURCES_FILES Engine.cpp
        ../Include/Debug.cpp
)

# Create a static library for the App module
add_library(${libname} SHARED ${SOURCES_FILES})

# Specify include directories for this library
target_include_directories(${libname}  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# If AppLib depends on other libraries, link them here
target_link_libraries(${libname}  PUBLIC ${SDL2_LIBRARIES} Display )
