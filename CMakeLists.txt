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

# Используем FetchContent для загрузки GoogleTest
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

# Загружаем и делаем доступным GoogleTest
FetchContent_MakeAvailable(googletest)

# Тесты
add_executable(lab2_tests test.cpp)

# Линкуем тесты с GoogleTest
target_link_libraries(lab2_tests PRIVATE GTest::gtest GTest::gtest_main)

# Добавляем тест в CTest
include(GoogleTest)
gtest_discover_tests(lab2_tests)

# Альтернативный вариант, если gtest_discover_tests не работает:
# add_test(NAME Lab2Tests COMMAND lab2_tests)