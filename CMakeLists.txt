cmake_minimum_required(VERSION 4.0)
project(penguin)

add_executable(penguin 
    src/glad.c
    src/main.cpp
    src/window/window.cpp
    src/loader/loader.cpp 
    src/loader/shaderLoader.cpp 
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

add_custom_command(TARGET penguin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/res
            $<TARGET_FILE_DIR:penguin>/res
)


