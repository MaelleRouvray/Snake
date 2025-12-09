cmake_minimum_required(VERSION 3.28)
project(snakeProject)  

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_PREFIX_PATH "C:/Users/maell/local/Catch2")
find_package(Catch2 3 REQUIRED)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE Catch2::Catch2WithMain)

include_directories(include)

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

set(Catch2_DIR "C:/Users/maell/Libraries/Catch2/lib/cmake/Catch2")
find_package(Catch2 3 REQUIRED)

add_executable(snake_tests
    tests/test.cpp
    src/snake.cpp
    src/board.cpp
    src/food.cpp)

target_link_libraries(snake_tests PRIVATE Catch2::Catch2WithMain)


enable_testing()
add_test(NAME SnakeTests COMMAND snake_tests)