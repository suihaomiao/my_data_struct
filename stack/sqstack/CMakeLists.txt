cmake_minimum_required(VERSION 3.1)

project(sqstack)

set(SOURCE 
    test.c
    SqStack.c
)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(${PROJECT_NAME} ${SOURCE})