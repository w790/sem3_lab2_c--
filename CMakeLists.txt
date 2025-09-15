cmake_minimum_required(VERSION 3.10.0)
project(lab2_c++ VERSION 0.1.0 LANGUAGES C CXX)

# Version definition
if(DEFINED VERSION_PROJECT)
    add_definitions(-DVERSION_PROJECT="${VERSION_PROJECT}")
else()
    add_definitions(-DVERSION_PROJECT="0")
endif()

# Enable testing before finding GTest
enable_testing()

# Find GTest package with modern CMake
find_package(GTest REQUIRED)

# Main executable
add_executable(lab2_c++ lab2.cpp)

# Test executable
add_executable(lab2_tests test.cpp)

# Link libraries for tests
target_link_libraries(lab2_tests PRIVATE GTest::gtest GTest::gtest_main)

# Add test to CTest
add_test(NAME Lab2Tests COMMAND lab2_tests)

# CPack configuration
set(CPACK_PACKAGE_NAME "lab2_c++")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

if(WIN32)
    set(CPACK_GENERATOR "ZIP")
endif()

if(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Pavel Gilev <pasha_w790@bk.ru>")
endif()

# Installation targets
install(TARGETS lab2_c++ DESTINATION bin)

include(CPack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)