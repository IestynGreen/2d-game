cmake_minimum_required(VERSION 3.21)
project(SFMLGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFMLGame main.cpp playerClass.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
TARGET_LINK_LIBRARIES(SFMLGame sfml-system sfml-window sfml-graphics sfml-audio)

