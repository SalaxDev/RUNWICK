cmake_minimum_required(VERSION 3.19)
project(RUNWICK_PROJECT LANGUAGES CXX VERSION 0.1.0)

# Initial Settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Shared Directories
include_directories(
    "include"
    "libs"
)

# For downloading SDL3 libraries if not found
include(FetchContent)

# Find SDL3 Libraries
# SDL3
find_package(SDL3 CONFIG QUIET)
if(SDL3_FOUND)
    message(STATUS "Found SDL3 at: ${SDL3_DIR}")
else() # Downloading the SDL3 if SDL3 is not available
    message(STATUS "SDL3 not found on system - downloading from source")

    # Pin to a stable release. Check https://github.com/libsdl-org/SDL/releases
    set(SDL3_TAG "release-3.4.20")

    FetchContent_Declare(
        SDL3
        GIT_REPOSITORY  https://github.com/libsdl-org/SDL.git
        GIT_TAG         ${SDL3_TAG}
        GIT_SHALLOW     TRUE
    )

    set(SDL_SHARED          ON  CACHE BOOL "" FORCE)
    set(SDL_STATIC          OFF CACHE BOOL "" FORCE)
    set(SDL_TEST_LIBRARY    OFF CACHE BOOL "" FORCE)
    set(SDL_TESTS           OFF CACHE BOOL "" FORCE)
    set(SDL_EXAMPLES        OFF CACHE BOOL "" FORCE)
    set(SDL_INSTALL         OFF CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(SDL3)
endif()

find_package(SDL3_image CONFIG QUIET)
if (SDL3_image_FOUND)
    message(STATUS "Found SDL3_image at: ${SDL3_image_DIR}")
else()
    message(STATUS "SDL3_image not found on system - downloading from source")
    
    set(SDL3_image_TAG "release-3.4.8")
    
    FetchContent_Declare(
        SDL3_image
        GIT_REPOSITORY  https://github.com/libsdl-org/SDL_image.git
        GIT_TAG         ${SDL3_image_TAG}
        GIT_SHALLOW TRUE
    )
    
    set(SDL_IMAGE_SHARED          ON  CACHE BOOL "" FORCE)
    set(SDL_IMAGE_STATIC          OFF CACHE BOOL "" FORCE)
    set(SDL_IMAGE_TEST_LIBRARY    OFF CACHE BOOL "" FORCE)
    set(SDL_IMAGE_TESTS           OFF CACHE BOOL "" FORCE)
    set(SDL_IMAGE_EXAMPLES        OFF CACHE BOOL "" FORCE)
    set(SDL_IMAGE_INSTALL         OFF CACHE BOOL "" FORCE)
    
    FetchContent_MakeAvailable(SDL3_image)
endif()

# Add Source files Using GLOB
file(GLOB_RECURSE source_file CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*")
message(STATUS "Found *.cpp sources:\n${source_file}")
# RUNWICK Game Program
add_executable(runwick
    ${source_file}
)

# Including Directories
target_include_directories(runwick PRIVATE
    "include/core"
    "include/utils"
)

# Name Changer
set_target_properties(runwick PROPERTIES OUTPUT_NAME "RUNWICK")

# Linker
target_link_libraries(runwick PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
)

# Custom Command for copying Libraries
add_custom_command(TARGET runwick POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL3::SDL3>
    $<TARGET_FILE_DIR:runwick>
    COMMENT "Copying SDL3 Library to $<TARGET_FILE_DIR:runwick>"
)

add_custom_command(TARGET runwick POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL3_image::SDL3_image>
    $<TARGET_FILE_DIR:runwick>
    COMMENT "Copying SDL3_image Library to $<TARGET_FILE_DIR:runwick>"
)