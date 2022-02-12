cmake_minimum_required(VERSION 3.16)
project(Tests)

set(CMAKE_CXX_STANDARD 17)

include_directories(../Src)
link_directories(../Src/cmake-build-debug)

add_executable(Tests
        Catch2.h
        main.cpp
        Lower.cpp
        Upper.cpp
        Replace_Char.cpp
        Replace_String.cpp
)

target_link_libraries(Tests StringTools)
