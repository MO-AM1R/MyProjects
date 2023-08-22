cmake_minimum_required(VERSION 3.25)
project(BST)

set(CMAKE_CXX_STANDARD 23)

add_executable(BST main.cpp BST.h Data.h Student.h test/test.h test/test1.h)
