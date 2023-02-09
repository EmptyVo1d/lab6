cmake_minimum_required(VERSION 3.23)
project(lab6 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab6 main.c MyLibrary.h inputStr.c MyPrint.c modernization.c MyFree.c DelSpace.c)
