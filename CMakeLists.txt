cmake_minimum_required(VERSION 3.21)
project(sqlite3_demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

add_compile_options(-l sqlite3)

add_executable(sqlite3_demo main.cpp sqlite3.c do_insert.cpp do_insert.h do_delete.cpp do_delete.h)
target_link_libraries(sqlite3_demo ${CMAKE_DL_LIBS})
