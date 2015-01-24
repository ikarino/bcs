cmake_minimum_required (VERSION 2.6)

project(blood)

add_executable (blood main.cpp GUIField.cpp status.cpp Bloodhand.cpp Daimajin.cpp Summon.cpp Map.cpp Unit.cpp)
target_link_libraries (blood fltk)
set(CMAKE_CXX_FLAGS "-std=c++0x -O3 -Wall")
