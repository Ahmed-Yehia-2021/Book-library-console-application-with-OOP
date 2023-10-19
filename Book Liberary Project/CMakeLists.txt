cmake_minimum_required(VERSION 3.22)
project(Book_Liberary_Project)

set(CMAKE_CXX_STANDARD 23)

add_executable(Book_Liberary_Project main.cpp User.cpp User.h Book.cpp Book.h UserList.cpp UserList.h BookList.cpp BookList.h)
