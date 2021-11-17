cmake_minimum_required(VERSION 3.1)

project(linklist)

set(SOURCE 
    test.c
    linklist.c
)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(${PROJECT_NAME} ${SOURCE})