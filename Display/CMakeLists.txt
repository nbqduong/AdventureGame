set(libname "Display")

set(SOURCES_FILES Windows.cpp
                )


# Create a static library for the App module
add_library(${libname} STATIC ${SOURCES_FILES})

# Specify include directories for this library
target_include_directories(${libname}  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# If AppLib depends on other libraries, link them here
target_link_libraries(${libname}  PRIVATE ${SDL2_LIBRARIES})