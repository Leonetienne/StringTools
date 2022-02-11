cmake_minimum_required(VERSION 3.16)
project(Exec)

set(CMAKE_CXX_STANDARD 17)

include_directories(..)
link_directories(../StringTools/cmake-build-debug)

add_executable(Exec main.cpp ../Test/test.cpp)
target_link_libraries(Exec Stringtools)
