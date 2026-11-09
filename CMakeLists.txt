cmake_minimum_required(VERSION 3.30)
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

find_package(SDL3 CONFIG REQUIRED)
if(SDL3_FOUND)
    message(STATUS "Found SDL3 at: ${SDL3_DIR}")
endif()

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
)

# Custom Command for copying Libraries
add_custom_command(TARGET runwick POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL3::SDL3>
    $<TARGET_FILE_DIR:runwick>
    COMMENT "Copying SDL3 Library to $<TARGET_FILE_DIR:runwick>"
)