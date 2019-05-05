# CMake entry point
cmake_minimum_required (VERSION 2.6)
include(CheckIncludeFile)
project (V5CrossCompile)

SET(files 
V5CrossCompile.h
V5CrossCompile.cpp
V5ICompiler.h
V5Compiler.h
V5Compiler.cpp
V5Win32Compiler.h
V5Win32Compiler.cpp
V5Win64Compiler.h
V5Win64Compiler.cpp
)

add_executable(V5CrossCompile ${files}) 
target_link_libraries(V5CrossCompile )
