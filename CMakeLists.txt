cmake_minimum_required(VERSION 3.26)
project(LibraryManagerSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryManagerSystem main.cpp
        data/Book.cpp
        data/Book.h
        data/BookList.cpp
        data/BookList.h
        data/Manager.cpp
        data/Manager.h)
