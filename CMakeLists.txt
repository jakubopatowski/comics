cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(cpp_starting_project)

if(MSVC)
  add_compile_options( /W4 )
else()
  add_compile_options( -Wall -Wextra -Wpedantic)
endif()

#=====================
#..:: BOOST SETUP ::..
#=====================

# set boost includes
set(Boost_USE_STATIC_LIBS      OFF)  # only find static libs
set(Boost_USE_DEBUG_LIBS       ON)   # ignore debug libs and
set(Boost_USE_RELEASE_LIBS     OFF)  # only find release libs
set(Boost_USE_MULTITHREADED    ON)
set(Boost_USE_STATIC_RUNTIME   OFF)

if(UNIX)
  message("UNIX environment in use.")
  set(BOOST_LIBRARYDIR         "/usr/lib64")
elseif(MSVC OR WIN32)
  message("MSVC or WIN32 environment in use.")
  set(BOOST_ROOT               "D:/boost/boost_1_74_0_source")
else()
  message("Unknown environment in use.")
endif()

find_package(Boost 1.74.0 REQUIRED COMPONENTS date_time regex)

message("==============================================================")
message("                        ..:: BOOST ::..                       ")
message("==============================================================")
message("Boost_FOUND:                ${Boost_FOUND}")
message("Boost_VERSION:              ${Boost_VERSION}")
message("BOOST_ROOT:                 ${BOOST_ROOT}")
message("Boost_INCLUDE_DIRS:         ${Boost_INCLUDE_DIRS}")
message("Boost_LIBRARY_DIRS:         ${Boost_LIBRARY_DIRS}")
message("Boost_LIBRARIES:            ${Boost_LIBRARIES}")
message("==============================================================")

set(project_sources
  main.cpp)

add_executable(executable ${project_sources})

target_link_libraries(executable
  PRIVATE
  ${Boost_LIBRARIES})

target_include_directories(executable
  PRIVATE
  ${Boost_INCLUDE_DIRS})
