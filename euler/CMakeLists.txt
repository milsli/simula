cmake_minimum_required(VERSION 3.5)

project(euler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(euler main.cpp)

install(TARGETS euler
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
