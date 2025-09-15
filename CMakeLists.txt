cmake_minimum_required(VERSION 3.14)
project(lab2_c++)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подавляем предупреждения безопасности Visual Studio
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# Включаем тестирование
enable_testing()

# Основная программа
add_executable(lab2_c++ lab2.cpp)

# Тесты
add_executable(lab2_tests test.cpp)

# Ищем GoogleTest
find_package(GTest REQUIRED)

# Линкуем тесты с GoogleTest
target_link_libraries(lab2_tests GTest::gtest_main)

# Добавляем тест в CTest
add_test(NAME Lab2Tests COMMAND lab2_tests)