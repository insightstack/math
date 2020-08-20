cmake_minimum_required(VERSION 3.15)
project(instack_math)

set(CMAKE_CXX_STANDARD 14)

find_package(glog 0.4.0 REQUIRED)

file(GLOB_RECURSE SOURCES "stack/**/*.cc")

add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_library(stack::math ALIAS ${PROJECT_NAME})

#
# Glog
#
target_link_libraries(${PROJECT_NAME} glog::glog)

#
# Stack
#
include_directories(${STACK_INCLUDE_DIRS})