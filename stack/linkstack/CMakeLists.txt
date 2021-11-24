cmake_minimum_required(VERSION 3.1)

project(linkstack)

set(SOURCE 
    test.c
    linkstack.c
)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(${PROJECT_NAME} ${SOURCE})