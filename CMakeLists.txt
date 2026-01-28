cmake_minimum_required(VERSION 4.0)
project(penguin)

add_executable(penguin 
    src/glad.c
    src/main.cpp
    src/window/window.cpp
    src/core/core.cpp
)

add_subdirectory(include/glfw-master)

target_include_directories(penguin PUBLIC
    src 
    include 
    include/glfw/include
)

target_link_libraries(penguin
    glfw 
    opengl32
)
