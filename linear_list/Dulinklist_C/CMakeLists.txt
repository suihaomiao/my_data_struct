cmake_minimum_required(VERSION 3.1)

project(dulinklist)

set(SOURCE 
    test.c
    dulinklist_C.c
)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(${PROJECT_NAME} ${SOURCE})