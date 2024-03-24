# CMakeLists.txt

cmake_minimum_required(VERSION 3.0)

project(MyProgram)

# Add source files
set(SOURCES
    functions.cpp
    functions.h
    standart.h
    timer.h
    IO.cpp
    generateFile.cpp
    vector.cpp
)

# Add executable
add_executable(my_program ${SOURCES})
