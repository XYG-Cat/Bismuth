cmake_minimum_required(VERSION 3.28)
project(Bismuth)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(include)

add_executable(Bismuth
        include/Bismuth/Module.h
        include/Bismuth/TuiTools.h
        include/Bismuth/WorkSpace.h
        src/main.cpp
        src/Module.cpp
        src/TuiTools.cpp
        src/WorkSpace.cpp)
