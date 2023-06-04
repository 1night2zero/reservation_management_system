cmake_minimum_required(VERSION 3.24)
project(reservation_management_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(reservation_management_system main.cpp System.cpp System.h File.h User.cpp User.h Admin.cpp Admin.h Visitor.cpp Visitor.h)
