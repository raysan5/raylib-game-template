cmake_minimum_required(VERSION 3.7...3.29.2)

set(CMAKE_C_STANDARD 99)

project(Pong VERSION 1.0
             DESCRIPTION "Pong Using Raylib"
             LANGUAGES C)


add_subdirectory(src)
add_subdirectory(raylib)