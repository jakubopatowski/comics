cmake_policy(SET CMP0071 NEW)

#file(GLOB PUBLIC_HEADER_LIST CONFIGURE_DEPENDS "${comics_SOURCE_DIR}/include/*.hpp")
file(GLOB SRC_LIST CONFIGURE_DEPENDS "*.cpp")
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "*.hpp")

set(project_uis
    "../ui/MainWindow.ui"
)

#set(project_qrcs "../rvl_sequence.qrc")

add_executable(comics_app
    #${PUBLIC_HEADER_LIST}
    ${SRC_LIST}
    ${HEADER_LIST}
    ${project_uis}
    #${project_qrcs}
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET comics_app PROPERTY AUTOMOC ON)
target_compile_features(comics_app PUBLIC cxx_std_11)

target_include_directories(comics_app
    PRIVATE
        .
)

# Check what is the compiler
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # using regular Clang or AppleClang
  target_compile_options(comics_app PRIVATE -Wpedantic -W)
  if (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    # using clang with clang-cl front end
  elseif (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "GNU")
    # using clang with regular front end
  endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  target_compile_options(comics_app PRIVATE -Wpedantic -W)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  target_compile_options(comics_app PRIVATE /permissive- /W4)
endif()

get_target_property(MAIN_CFLAGS comics_app COMPILE_OPTIONS)
# also see: COMPILE_DEFINITIONS INCLUDE_DIRECTORIES
message("-- Target compiler flags are: ${MAIN_CFLAGS}")

target_link_directories(comics_app
    PRIVATE
)

#source_group(
#    TREE "${PROJECT_SOURCE_DIR}/include"
#    PREFIX "Public Header Files"
#    FILES ${PUBLIC_HEADER_LIST})

source_group(
    TREE "${PROJECT_SOURCE_DIR}/src"
    PREFIX "Private Header Files"
    FILES ${HEADER_LIST})

# External deps

#=============== qt6 part
#set(CMAKE_PREFIX_PATH "D:\\Qt6\\6.0.2\\msvc2019_64")
set(CMAKE_PREFIX_PATH "d:\\Qt\\5.15.2\\msvc2019_64")
#For find_package to be successful, CMake must find the Qt installation.
#There are different ways you can tell CMake about Qt:
#    Set the CMAKE_PREFIX_PATH environment variable to include the Qt 6 installation prefix.
#    Set the CMake cache variable CMAKE_PREFIX_PATH to include the Qt 6 installation prefix.
find_package(Qt5 5.15.2 COMPONENTS Widgets Core Gui Sql REQUIRED)

if(Qt5_FOUND)
  message("-- Package Qt found.")
  target_link_libraries(comics_app PRIVATE Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Sql)
else()
  message("-- Package Qt Not found.")
endif()

#=============== end of qt6 part

#=============== SqLite
#https://www.sqlite.org/2021/sqlite-dll-win32-x86-3340100.zip
#https://www.sqlite.org/2021/sqlite-dll-win64-x64-3340100.zip
#https://www.sqlite.org/2021/sqlite-amalgamation-3340100.zip

FetchContent_Declare(
  sqlite3
  URL "https://www.sqlite.org/2021/sqlite-amalgamation-3340100.zip")

if (NOT sqlite3_POPULATED)
  # notice that we do not call `add_subdirectory`, we simply fetch and then
  # use the subdirectory sources directly.
  FetchContent_Populate(sqlite3)
endif()

target_include_directories(comics_app PRIVATE $<BUILD_INTERFACE:${sqlite3_SOURCE_DIR}>)
target_sources(comics_app PRIVATE ${sqlite3_SOURCE_DIR}/sqlite3.c)

#=============== end SqLite