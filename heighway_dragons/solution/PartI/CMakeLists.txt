cmake_minimum_required(VERSION 3.13)

project(project)

set(CMAKE_CXX_STANDARD 14)

include_directories('./')

add_executable(Test dragon.c image.c)

add_executable(Test2 my_dragon.c image.c)

target_link_libraries(Test m)
target_link_libraries(Test2 m)