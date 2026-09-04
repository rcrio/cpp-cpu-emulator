cmake_minimum_required(VERSION 3.16)

project(CpuEmulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpu-emulator
    src/main.cpp
    src/CPU.cpp
    src/Memory.cpp
    src/ProgramEncoder.cpp
)

target_include_directories(cpu-emulator PRIVATE include)