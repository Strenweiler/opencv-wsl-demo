cmake_minimum_required(VERSION 3.10)

project(OpenCV_Test)

find_package(OpenCV REQUIRED)

add_executable(show_img main.cpp)

target_link_libraries(show_img ${OpenCV_LIBS})
