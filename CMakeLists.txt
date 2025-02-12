cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME LinkedList)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)

project(${PROJECT_NAME} VERSION 1.0 
                        DESCRIPTION "Exercies 7")

add_executable(linked_list_test list/linkedlist.cpp test.cpp)
target_include_directories(linked_list_test PRIVATE list)
target_link_libraries(linked_list_test PRIVATE gtest gmock gtest_main)

enable_testing()
add_test(NAME linked_list_test COMMAND linked_list_test)
