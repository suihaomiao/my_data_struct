cmake_minimum_required(VERSION 3.1)

project(sqQueue)

set(SOURCE 
    test.c
    sqQueue.c
)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(${PROJECT_NAME} ${SOURCE})