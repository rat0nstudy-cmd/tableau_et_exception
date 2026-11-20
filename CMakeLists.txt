cmake_minimum_required(VERSION 4.3)
project(tableau_et_exception)

set(CMAKE_CXX_STANDARD 20)

add_executable(tableau_et_exception main.cpp
        menu.cpp
        menu.h
        stack.cpp
        stack.h)
