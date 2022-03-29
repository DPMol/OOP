cmake_minimum_required(VERSION 3.21)
project(Lab6_7)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab6_7 main.cpp Domain/tenant.cpp Domain/tenant.h Interface/interface.h Interface/interface.cpp Service/service.cpp Service/service.h Repository/repository.cpp Repository/repository.h)
