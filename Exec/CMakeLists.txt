cmake_minimum_required(VERSION 3.16)
project(Exec)

set(CMAKE_CXX_STANDARD 17)

include_directories(../Src)

FILE(GLOB StringTools ../Src/*.cpp)

add_executable(Exec
    ${StringTools}

    main.cpp
)
