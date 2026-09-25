cmake_minimum_required(VERSION 3.10)

project(TreeSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/lsystem.cpp
    src/runningopt.cpp
    src/turtlestate.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
