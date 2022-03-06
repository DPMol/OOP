cmake_minimum_required(VERSION 3.21)
project(Lab3_4 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab3_4 main.c Interface/interface.h Service/service.h Repozitory/repozitory.h Interface/interface.c)
