cmake_minimum_required(VERSION 3.19)
project(Restaurant_Management_System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Restaurant_Management_System main.cpp my-header/hotels.h my-header/admin.h my-header/customer.h)