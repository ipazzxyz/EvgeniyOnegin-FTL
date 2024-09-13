cmake_minimum_required(VERSION 3.30)
project(EvgeniyOnegin)
set (CMAKE_CXX_STANDARD 23)
add_executable(EvgeniyOnegin
    src/composition.cpp
    src/data.txt
    src/composition.hpp
    src/line.hpp
    src/line.cpp
    src/poem.cpp
    src/main.cpp
    src/rng.cpp
    src/rng.hpp
    src/poem.hpp
)
target_link_libraries(EvgeniyOnegin)
file(COPY src/data.txt
     DESTINATION build/)