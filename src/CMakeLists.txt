# Set CMake requirements and declare project

cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# Output all command lines used

set(CMAKE_VERBOSE_MAKEFILE ON)

# Ask for the C++ standard directly (C++14 below) -- has to be before executable!

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_EXTENSIONS OFF)

# Declare the build of mpags-cipher main program

add_executable(mpags-cipher 
    mpags-cipher.cpp
    MPAGSCipher/transformChar.cpp
    MPAGSCipher/transformChar.h
    MPAGSCipher/processCmdLine.cpp
    MPAGSCipher/processCmdLine.h
    MPAGSCipher/CaesarCipher.cpp
    MPAGSCipher/CaesarCipher.h
)

target_include_directories(mpags-cipher
    PRIVATE MPAGSCipher
)

# Additional flags

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

# CMake compile features: cross platform way of specifying the features needed for the compiler (like C++11 for example)

target_compile_features(mpags-cipher
    PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
)   
