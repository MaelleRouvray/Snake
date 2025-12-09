cmake_minimum_required(VERSION 3.28)
project(snakeProject)  

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})


find_package(Catch2 3 REQUIRED)

add_executable(snake_tests
    tests/test.cpp
    src/snake.cpp
    src/board.cpp
    src/food.cpp)

target_link_libraries(snake_tests PRIVATE Catch2::Catch2WithMain)


enable_testing()
add_test(NAME SnakeTests COMMAND snake_tests)