cmake_minimum_required(VERSION 2.8)

project(tdd-workshop)

enable_testing()

find_package(Threads REQUIRED)

# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/release-1.8.1.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
)

# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

# Set libgtest properties
set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# Create a libgtest_main target to be used as a dependency by test programs
add_library(libgtest_main IMPORTED STATIC GLOBAL)
add_dependencies(libgtest_main gtest)

# Set libgtest_main properties
set_target_properties(libgtest_main PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest_main.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include"
)

# Add path to source files
include_directories(
    ${PROJECT_SOURCE_DIR}/../main/system
    ${PROJECT_SOURCE_DIR}/../main/hal
    ${PROJECT_SOURCE_DIR}/../main/hal/hal-tdd
    ${PROJECT_SOURCE_DIR}/../main
)

# Define TDD flag used in sources
add_definitions(-DTDD)

# -----------------------------------------------------------------------------
# 1. Add files to be compiled
# 2. Link target & GoogleTest libs

add_executable(led
    ${PROJECT_SOURCE_DIR}/../main/hal/hal-tdd/HAL_TDD.cpp
    TestLEDBlink.cpp ${PROJECT_SOURCE_DIR}/../main/system/DebugLED.cpp
)
target_link_libraries(led libgtest libgtest_main libgmock)
add_test(NAME TestLEDBlink COMMAND led)
