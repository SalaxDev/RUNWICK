cmake_minimum_required(VERSION 3.30)
project(RUNWICK_PROJECT LANGUAGES CXX C VERSION 1.0.0)

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