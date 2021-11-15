cmake_minimum_required(VERSION 3.1)

project(static_seqlist)

set(SOURCE 
    seqlist_test.c
    static_sqlist.c
)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(${PROJECT_NAME} ${SOURCE})



