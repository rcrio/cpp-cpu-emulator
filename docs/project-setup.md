# Project setup for learning

## VSCode
- Install VSCode
- Get the C++ extension

## Git
- Install Git
- Do `git init`, to prepare this as a repository
- Create a `.gitignore`, to prevent unneccessary files cluttering the project:
```.gitignore
build/
.vscode/
```
(This is a very basic `.gitignore` and you can use an LLM to generate one or get a template online.)
- Create a `README.md` for the repository
 
## CMake
- Install CMake directly or by `sudo apt install cmake` 
- Make a CMakeLists.txt:
```CMake
cmake_minimum_required(VERSION 3.16)

project(CpuEmulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpu_emulator
    src/main.cpp
)
```

## Ninja
- Install Ninja directly or by `sudo apt install ninja-build`

## Building and running
- For the first build, configure the project with Ninja:
```bash
cmake -S . -B build -G Ninja
```
- Then, you can build using either of the two commands:
```bash
cmake --build build
```
or
```bash
ninja -C build
```
- Run the build:
```bash
./build/cpu-emulator
```

## Folder structure
```
.
├── src/
│   └── main.cpp
├── CMakeLists.txt
└── README.md
```

Folder structure tree was made using https://tree.nathanfriend.com.

`docs` is an extra folder that is not necessary, and includes this `.md` file which is meant to be for learning purposes.