cmake_minimum_required(VERSION 3.13)

project(Stenography)

set(CMAKE_CXX_STANDARD 14)

include_directories('./')

add_executable(Test eliza.c eliza_state.c string_utils.c list.c map.c parser.c rule.c)

add_executable(Test2  string_utils.c map.c)


