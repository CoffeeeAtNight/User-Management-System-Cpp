cmake_minimum_required(VERSION 3.25)
project(UMS-CPP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")    

add_executable(UMS-CPP main.cpp ums/UmsInitializer.cpp ums/UmsInitializer.h ums/UmsMain.cpp ums/UmsMain.h)
