cmake_minimum_required(VERSION 3.28)
project(snakeProject)  

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)



file(GLOB SOURCES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)



find_package(Catch2 3 REQUIRED)

add_executable(snake_tests
    tests/test_snake.cpp 
    tests/test_food.cpp
    src/snake.cpp
    src/board.cpp
    src/food.cpp)

target_link_libraries(snake_tests PRIVATE Catch2::Catch2WithMain)


enable_testing()
add_test(NAME SnakeTests COMMAND snake_tests)