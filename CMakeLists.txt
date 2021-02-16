cmake_minimum_required(VERSION 3.17)
project(exercise)

set(CMAKE_CXX_STANDARD 20)

add_executable(exercise main.cpp src/Student.cpp include/Student.h src/StudentGrading.cpp include/StudentGrading.h src/StudentPrinter.cpp include/StudentPrinter.h src/StudentFileManager.cpp include/StudentFileManager.h)