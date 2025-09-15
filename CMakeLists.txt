cmake_minimum_required(VERSION 3.10.0)
project(lab2_c++ VERSION 0.1.0 LANGUAGES C CXX)

# Set toolchain file for vcpkg
set(CMAKE_TOOLCHAIN_FILE "C:/study/C++SEM3/lab2/out/build/GCC 14.2.0 x86_64-w64-mingw32 (mingw64)/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Version definition
if(DEFINED VERSION_PROJECT)
    add_definitions(-DVERSION_PROJECT="${VERSION_PROJECT}")
else()
    add_definitions(-DVERSION_PROJECT="0")
endif()

# Find GTest package
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
# Main executable
add_executable(lab2_c++ lab2.cpp)

# Test executable
add_executable(lab2_tests test.cpp)
target_link_libraries(lab2_tests PRIVATE GTest::gtest GTest::gtest_main Threads::Threads)

# Enable testing and add test
enable_testing()
add_test(NAME Lab2Tests COMMAND lab2_tests)

# CPack configuration
set(CPACK_PACKAGE_NAME "LAB2")
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