cmake_minimum_required(VERSION 3.10)
project(doublets C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

configure_file(words.txt . COPYONLY)

add_executable(doublets
        doublets.c doublets.h
        trie.c trie.h)
target_compile_options(doublets PRIVATE -DDOUBLETS_MAIN)

add_executable(testB
        trie.c trie.h
        doublets.c doublets.h
        testB.c)
target_compile_options(testB PRIVATE -DTESTING)

add_executable(testA
        trie.c trie.h
        doublets.c doublets.h
        testA.c)
target_compile_options(testA PRIVATE -DTESTING)

add_executable(dictionary
        trie.c trie.h)
target_compile_options(dictionary PRIVATE -DDICTIONARY_MAIN)
