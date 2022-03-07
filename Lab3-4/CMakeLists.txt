cmake_minimum_required(VERSION 3.21)
project(Lab3_4 C)

set(CMAKE_C_STANDARD 11)

include_directories(Domain)
include_directories(Interface)
include_directories(Repozitory)
include_directories(Service)
include_directories(Validators)

add_executable(Lab3_4
        Domain/participant.c
        Domain/participant.h
        Interface/interface.c
        Interface/interface.h
        Repozitory/repozitory.c
        Repozitory/repozitory.h
        Service/service.c
        Service/service.h
        Validators/validators.c
        Validators/validators.h
        main.c)
