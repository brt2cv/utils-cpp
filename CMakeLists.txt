cmake_minimum_required(VERSION 2.8)
# CMake versions < 3.4.0 do not support try_compile/pthread checks without C as active language.
if(CMAKE_VERSION VERSION_LESS 3.4.0)
  project(tmv_utils)
else()
  project(tmv_utils CXX)
endif()
message(">> 正在编译tmv_utils模块...")

if(CMAKE_COMPILER_IS_GNUCXX)
    message(">> 使用g++编译器")
    # set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -W -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-fPIC)

if(WIN32)
    message(STATUS "Now is windows")
elseif(APPLE)
    message(STATUS "Now is Apple systens.")
elseif(UNIX)
    message(STATUS "Now is UNIX-like OS's.")
endif()

# Determine if fmt is built as a subproject (using add_subdirectory)
# or if it is the master project.
set(MASTER_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(MASTER_PROJECT ON)
  message(STATUS "CMake version: ${CMAKE_VERSION}")
endif()

# set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/test)

###########################################################

include_directories(include)

add_subdirectory(fmt)
add_subdirectory(pystring)

# 编译pybin11
find_package(Python3 COMPONENTS Development)
if(Python3_Development_FOUND)
    message("=============== Python3_Development Found ===============")
    include_directories(${Python3_INCLUDE_DIRS})
    # find_package(pybind11 REQUIRED)
    add_subdirectory(pybind11)
else()
    message(SEND_ERROR "!!!!!!!!!!!!!!! Python3_Development NOT Found, 可能导致pybind11调用失败 !!!!!!!!!!!!!!!")
endif()

aux_source_directory(. DIR_UTILS)
add_library(utils SHARED ${DIR_UTILS} nlohmann_json)

# IF( CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" )
# SET_TARGET_PROPERTIES(utils PROPERTIES COMPILE_FLAGS "-fPIC")
# ENDIF( CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" )

target_link_libraries(utils
    PUBLIC fmtlib pystring)
if(WIN32)
    target_link_libraries(utils kernel32.lib)
elseif(UNIX)
    target_link_libraries(utils dl)
endif()

if(MASTER_PROJECT)
    message(">> 编译test测试项目")
    add_subdirectory(test)
endif()
