cmake_minimum_required(VERSION 3.27)
project(OOP_LAB_6_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_LAB_6_7 main.cpp
        Masina.cpp
        Masina.h
        repository.cpp
        repository.h
        MasinaService.cpp
        MasinaService.h
        ui.cpp
        ui.h)
