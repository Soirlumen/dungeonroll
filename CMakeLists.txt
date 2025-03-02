cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)  # Nebo jinou verzi C++
file(GLOB SOURCES "*.cpp")  # Najde všechny .cpp soubory
add_executable(gej ${SOURCES})
