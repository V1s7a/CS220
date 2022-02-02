cmake_minimum_required(VERSION 3.17)
project(PEX4 C)

set(CMAKE_C_STANDARD 99)

add_executable(PEX4 pex4.c ternaryTreeUnitTest.c ternaryTree.c wordList.h wordList.c ternaryTree.h ternaryTreeUnitTest.h)