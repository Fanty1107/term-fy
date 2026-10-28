cmake_minimum_required(VERSION 3.16) 
project(term_fy LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_ttf REQUIRED CONFIG)

add_executable(term_fy src/main.cpp src/SDL3_Context.cpp)
target_include_directories(term_fy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(term_fy PRIVATE SDL3_ttf::SDL3_ttf SDL3::SDL3)

