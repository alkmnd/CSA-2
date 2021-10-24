cmake_minimum_required(VERSION 3.20)
project(untitled11)

set(CMAKE_CXX_STANDARD 14)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/bin")
set(BINARY_DIR "${CMAKE_BINARY_DIR}")

add_executable(untitled11 main.cpp Aphorism.cpp Aphorism.h Container.cpp Container.h Proverb.h Puzzle.cpp Puzzle.cpp Puzzle.h WellOfWisdom.cpp WellOfWisdom.h Proverb.cpp )
