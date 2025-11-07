cmake_minimum_required(VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(tic_tac_toe)

set(SOURCES
	src/main.cpp
	src/engine.cpp
)

add_executable(tic_tac_toe ${SOURCES})

target_include_directories(tic_tac_toe PRIVATE include)
find_package(Curses REQUIRED)
target_link_libraries(tic_tac_toe ${CURSES_LIBRARIES})
