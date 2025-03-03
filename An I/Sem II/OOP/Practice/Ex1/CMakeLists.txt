cmake_minimum_required(VERSION 3.26)
project(Ex1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_PREFIX_PATH "C:/Qt/6.7.0/mingw_64/lib/cmake")
set(SOURCE_FILES main.cpp)
find_package(Qt5Widgets REQUIRED)

add_executable(Ex1)

target_link_libraries(Ex1 Qt5::Widgets)
