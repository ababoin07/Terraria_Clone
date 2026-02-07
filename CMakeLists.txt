cmake_minimum_required(VERSION 3.10)
project(SFML_Project)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Assets"
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

add_executable(SFML_Project main.cpp
    PerlinNoise.h
    PerlinNoise.cpp
    Vector2.h
    Vector2.cpp
    Prng.h

)

target_link_libraries(SFML_Project sfml-graphics sfml-window sfml-system sfml-audio)
