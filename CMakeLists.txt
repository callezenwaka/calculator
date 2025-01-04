cmake_minimum_required(VERSION 3.10)
project(Calculator VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

# First, download and build GoogleTest before defining targets
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

# Add main calculator executable
add_executable(calculator 
    src/main.cpp
    src/calculator.cpp
    src/utils.cpp
)

# Add compiler warnings for calculator
if(MSVC)
    target_compile_options(calculator PRIVATE /W4)
else()
    target_compile_options(calculator PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Enable testing
enable_testing()

# Add test executable (only one needed, not two)
add_executable(calculator_tests
    tests/test_main.cpp
    tests/test_calculator.cpp
    src/calculator.cpp
    src/utils.cpp
)

# Link Google Test libraries to test executable
target_link_libraries(calculator_tests gtest gtest_main)

# Add test
add_test(NAME calculator_tests COMMAND calculator_tests)