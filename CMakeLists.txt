cmake_minimum_required(VERSION 3.21)
cmake_policy(SET CMP0071 NEW)

project(comics VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

# Fetch Libraries
include(FetchContent)

# Qt
#set(CMAKE_PREFIX_PATH "D:\\Qt6\\6.0.2\\msvc2019_64")
set(CMAKE_PREFIX_PATH "d:\\Qt\\5.15.2\\msvc2019_64")
#For find_package to be successful, CMake must find the Qt installation.
#There are different ways you can tell CMake about Qt:
#    Set the CMAKE_PREFIX_PATH environment variable to include the Qt 6 installation prefix.
#    Set the CMake cache variable CMAKE_PREFIX_PATH to include the Qt 6 installation prefix.
find_package(Qt5 5.15.2 COMPONENTS Widgets Core Gui Sql REQUIRED)

# OpenGL
# https://learnopengl.com/

# GLFW
FetchContent_Declare(
  glfw3
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.3.2)
FetchContent_MakeAvailable(glfw3)

# GLAD
FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG v0.1.34)
FetchContent_MakeAvailable(glad)


enable_testing()
add_subdirectory(src)
add_subdirectory(tests)