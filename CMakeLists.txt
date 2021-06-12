cmake_minimum_required(VERSION 3.19)
project(company_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(company_project main.cpp Address.cpp Address.h Boss.cpp Boss.h Company.cpp Company.h Employee.cpp Employee.h Person.cpp Person.h)