# cmake_minimum_required(VERSION <specify CMake version here>)
project(05_AP_TA)

set(CMAKE_CXX_STANDARD 98)

add_executable(05_AP_TA main.cpp Map/Map.cpp Map/Map.h Simulator/Simulator.cpp Simulator/Simulator.h Kid/Kid.cpp Kid/Kid.h Kid/Kid_angry.cpp Kid/Kid_angry.h Kid/Kid_type.h Input_interface/Input_interface.cpp Input_interface/Input_interface.h Rigid_body/Rigid_body.cpp Rigid_body/Rigid_body.h Simulator/Collision_type.h Kid/Kid_peaceful.cpp Kid/Kid_peaceful.h)