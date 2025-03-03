cmake_minimum_required(VERSION 3.26)
project(Lab6)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab6 main.cpp
        ui.cpp
        ui.h
        domain.cpp
        domain.h
        service.cpp
        service.h
        repository.cpp
        repository.h
        teste.cpp
        teste.h
        VectorDinamic.h
)
