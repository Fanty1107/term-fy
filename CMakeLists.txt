cmake_minimum_required(VERSION 3.16) 
project(term_fy LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

find_package(SDL3 REQUIRED CONFIG)

add_executable(term_fy src/main.cpp)
target_include_directories(term_fy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(term_fy PRIVATE SDL3::SDL3)

