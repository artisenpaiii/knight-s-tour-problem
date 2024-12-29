cmake_minimum_required(VERSION 3.30)
project(KnightTour)

set(CMAKE_CXX_STANDARD 20)

add_executable(KnightTour main.cpp
        Headers/ChessNode.h
        Headers/ChessNode.cpp
        Headers/ChessBoard.h
        Headers/ChessBoard.cpp
        Headers/Knight.h
        Headers/Knight.cpp)

find_package(SFML 2.5 REQUIRED graphics window system)
target_link_libraries(KnightTour sfml-graphics sfml-window sfml-system)