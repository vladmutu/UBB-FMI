cmake_minimum_required(VERSION 3.26)
project(Lab02 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab02 main_.c
        electronic.h
        electronicservice.h
        electronicservice.c
        electronic.c
        electronicrepository.h
        electronicrepository.c
        ui.h
        ui.c
        tests.c
        tests.h)
