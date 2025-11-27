cmake_minimum_required(VERSION 3.28)
project(snakeProject)  

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})




