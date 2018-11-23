cmake_minimum_required(VERSION 2.8.2)

enable_testing()

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

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
target_link_libraries(led gtest gtest_main gmock)
add_test(NAME TestLEDBlink COMMAND led)

add_executable(bme280
    ${PROJECT_SOURCE_DIR}/../main/hal/hal-tdd/HAL_TDD.cpp
    TestBME280.cpp ${PROJECT_SOURCE_DIR}/../main/periph/BME280.cpp
)
target_link_libraries(bme280 gtest gtest_main gmock)
add_test(NAME TestBME280 COMMAND bme280)
