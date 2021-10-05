cmake_policy(SET CMP0071 NEW)

FetchContent_Declare(
  Catch2 
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.7)

FetchContent_MakeAvailable(Catch2)
# Adds Catch2::Catch2
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

# Tests need to be added as executables first
add_executable(tests test.cpp)

# I'm using C++17 in the test
target_compile_features(tests
  PRIVATE 
    cxx_std_17)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(tests
  PRIVATE   
    Catch2::Catch2)
    
include(CTest)
include(Catch)
catch_discover_tests(tests
WORKING_DIRECTORY "d:\\Projekty\\trunk\\win64-msvc2017_d\\bin" )