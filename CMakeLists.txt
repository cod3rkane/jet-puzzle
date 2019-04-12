cmake_minimum_required (VERSION 3.6)
project (PuzzleGame)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
	src/main.cpp
)

add_executable(PuzzleGame ${SOURCE_FILES})
