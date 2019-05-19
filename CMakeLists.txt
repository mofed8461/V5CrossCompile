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
V5SharedLibrary.h
V5SharedLibrary.cpp
)

add_executable(V5CrossCompile ${files}) 
target_link_libraries(V5CrossCompile )



add_library(testLib SHARED V5SharedLibrary.h V5SharedLibrary.cpp lib.h lib.cpp)
target_compile_definitions(testLib PUBLIC DYNAMIC_LIB)



add_executable(testEXE V5SharedLibrary.h V5SharedLibrary.cpp mainTest.cpp)


add_executable(testEXE2 V5SharedLibrary.h V5SharedLibrary.cpp mainTest.cpp lib.h)
target_compile_definitions(testEXE2 PUBLIC STATIC_LOAD)
target_link_libraries(testEXE2 testLib)

