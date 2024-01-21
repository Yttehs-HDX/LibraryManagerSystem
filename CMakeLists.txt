cmake_minimum_required(VERSION 3.26)
project(LibraryManagerSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(LibraryManagerSystem main.cpp
        core/data/Book.cpp
        core/data/BookInfo.cpp
        core/data/BookInfo.h
        core/data/BookInfo.h
        core/data/StockedBook.cpp
        core/data/StockedBook.h
        core/Manager.cpp
        core/Manager.h
        ui/Menu.cpp
        ui/Menu.h
)