cmake_minimum_required(VERSION 3.14)

project(projekt)

add_executable(main main.cpp)

# Check what is the compiler
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # using regular Clang or AppleClang
  if (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    # using clang with clang-cl front end
  elseif (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "GNU")
    # using clang with regular front end
  endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
endif()


# Tests

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_GetProperties(Catch2)
if(NOT Catch2_POPULATED)
  FetchContent_Populate(Catch2)
  message(STATUS "Catch source dir: ${catch2_SOURCE_DIR}")
  message(STATUS "Catch binary dir: ${catch2_BINARY_DIR}")
  add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
endif()

add_executable(tests test.cpp)
target_link_libraries(tests Catch2::Catch2)
