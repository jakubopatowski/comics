cmake_minimum_required(VERSION 3.14)

project(projekt)

add_executable(main main.cpp)

# Check what is the compiler
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # using regular Clang or AppleClang
  target_compile_options(main PRIVATE -Wpedantic -W)
  if (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    # using clang with clang-cl front end
  elseif (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "GNU")
    # using clang with regular front end
  endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  target_compile_options(main PRIVATE -Wpedantic -W)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  target_compile_options(main PRIVATE /permissive- /W4)
endif()

get_target_property(MAIN_CFLAGS main COMPILE_OPTIONS)
# also see: COMPILE_DEFINITIONS INCLUDE_DIRECTORIES
message("-- Target compiler flags are: ${MAIN_CFLAGS}")

# Fetch Libraries
Include(FetchContent)

# SqLite
#https://www.sqlite.org/2021/sqlite-dll-win32-x86-3340100.zip
#https://www.sqlite.org/2021/sqlite-dll-win64-x64-3340100.zip
#https://www.sqlite.org/2021/sqlite-amalgamation-3340100.zip

FetchContent_Declare(sqlite3 URL "https://www.sqlite.org/2021/sqlite-amalgamation-3340100.zip")
if (NOT sqlite3_POPULATED)
  # notice that we do not call `add_subdirectory`, we simply fetch and then
  # use the subdirectory sources directly.
  FetchContent_Populate(sqlite3)
endif()

target_include_directories(main PRIVATE $<BUILD_INTERFACE:${sqlite3_SOURCE_DIR}>)
target_sources(main PRIVATE ${sqlite3_SOURCE_DIR}/sqlite3.c)

# OpenGL GLFW
# https://learnopengl.com/
FetchContent_Declare(
  glfw3
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.3.2)

FetchContent_GetProperties(glfw3)
if(NOT glfw3_POPULATED)
  FetchContent_Populate(glfw3)
  message(STATUS "Catch source dir: ${glfw3_SOURCE_DIR}")
  message(STATUS "Catch binary dir: ${glfw3_BINARY_DIR}")
  #add_subdirectory(${glfw3_SOURCE_DIR} ${glfw3_BINARY_DIR})
endif()

# Tests
# https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#top
FetchContent_Declare(
  Catch2 
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.4)

FetchContent_GetProperties(Catch2)
if(NOT Catch2_POPULATED)
  FetchContent_Populate(Catch2)
  message(STATUS "Catch source dir: ${catch2_SOURCE_DIR}")
  message(STATUS "Catch binary dir: ${catch2_BINARY_DIR}")
  add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
endif()

add_executable(tests test.cpp)
target_link_libraries(tests Catch2::Catch2)
