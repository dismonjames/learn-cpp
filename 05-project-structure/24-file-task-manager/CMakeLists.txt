cmake_minimum_required(VERSION 3.20)

project(task_manager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
  task_manager
  src/main.cpp
  src/task.cpp
)

target_include_directories(
  task_manager
  PRIVATE
  include
)

target_compile_options(
  task_manager
  PRIVATE
  -Wall
  -Wextra
  -Wpedantic
)
