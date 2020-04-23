cmake_minimum_required(VERSION 3.4)

project(cpp_starting_project)

if(MSVC)
  add_compile_options( /W4 )
else()
  add_compile_options( -Wall -Wextra -Wpedantic )
endif()

add_executable(executable main.cpp)
