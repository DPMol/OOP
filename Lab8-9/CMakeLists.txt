cmake_minimum_required(VERSION 3.21)
project(Lab8_9)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(Domain)
include_directories(Interface)
include_directories(Repository)
include_directories(Service)
include_directories(test)

add_executable(Lab8_9
        Domain/tenant.cpp
        Domain/tenant.h
        Interface/interface.cpp
        Interface/interface.h
        Repository/repository.cpp
        Repository/repository.h
        Service/service.cpp
        Service/service.h
        test/test.cpp
        test/test.h
        dynamic_array.h
        main.cpp Cart/cart.cpp Cart/cart.h Exception/my_exception.cpp Exception/my_exception.h)
