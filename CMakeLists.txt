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
add_subdirectory(include/glm)

target_include_directories(penguin PUBLIC
    src 
    include 
    include/glfw/include
    include/glm/glm
)

target_link_libraries(penguin
    glfw 
    glm
    opengl32
)

add_custom_command(TARGET penguin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/res
            $<TARGET_FILE_DIR:penguin>/res
)


