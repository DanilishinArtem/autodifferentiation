cmake_minimum_required(VERSION 3.12)
project(autodifferential)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(SOURCES main.cpp src/dual.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})