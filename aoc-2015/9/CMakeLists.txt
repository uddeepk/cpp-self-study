cmake_minimum_required(VERSION 3.19)
project(9)

set(CMAKE_CXX_STANDARD 20)
#set("${CMAKE_CXX_FLAGS} -Xclang -fconcepts-ts")
#set (CMAKE_CXX_FLAGS "-Xclang -fmodules")#-ts -fexceptions")

add_executable(9 main.cpp)


#target_compile_options(9 PRIVATE -fmodules-ts)
