cmake_minimum_required(VERSION 3.1)

project(dulinklist)

set(SOURCE 
    test.c
    Dulinklist.c
)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(${PROJECT_NAME} ${SOURCE})