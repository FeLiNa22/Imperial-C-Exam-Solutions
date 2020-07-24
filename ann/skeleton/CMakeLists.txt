cmake_minimum_required(VERSION 3.13)

project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(train train.c layer.c ann.c rdata.c)


