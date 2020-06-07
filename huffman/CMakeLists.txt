cmake_minimum_required(VERSION 3.13)

project(Stenography)

set(CMAKE_CXX_STANDARD 14)

include_directories('./')

add_executable(Test exam.c main.c)



