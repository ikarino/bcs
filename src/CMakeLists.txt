project(bcs)

cmake_minimum_required (VERSION 2.6)

add_executable (bcs
  main.cpp
  GUIField.cpp
  status.cpp 
  Bloodhand.cpp
  Daimajin.cpp
  Summon.cpp
  Map.cpp 
  Unit.cpp
  Input.cpp)
target_link_libraries (bcs fltk)
set(CMAKE_CXX_FLAGS "-O3 -Wall")
