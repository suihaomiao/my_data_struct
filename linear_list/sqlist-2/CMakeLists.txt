cmake_minimum_required(VERSION 3.1)

project(sqlist)

set(SOURCE 
    test.c
    sqlist.c
)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(${PROJECT_NAME} ${SOURCE})
