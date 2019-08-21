# cmake_minimum_required(VERSION <specify CMake version here>)
project(05_AP_TA)

set(CMAKE_CXX_STANDARD 98)

add_executable(05_AP_TA main.cpp Map.cpp Map.h Simulator.cpp Simulator.h Kid/Kid.cpp Kid/Kid.h Kid/Kid_angry.cpp Kid/Kid_angry.h Kid/Kid_type.h Input_interface.cpp Input_interface.h Kid/Rigid_body.cpp Kid/Rigid_body.h Collision_type.h)