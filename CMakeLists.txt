cmake_minimum_required(VERSION 3.23)
project(BitboardEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(BitboardEngine main.cpp position.cpp position.h constants.h useful.cpp useful.h types.cpp types.h bitboard.cpp bitboard.h)
