#pragma once 
#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<iostream>

// ▄▄   ▄▄ ▄▄ ▄▄  ▄▄ ▄▄▄▄   ▄▄▄  ▄▄   ▄▄*
// ██ ▄ ██ ██ ███▄██ ██▀██ ██▀██ ██ ▄ ██ 
//  ▀█▀█▀  ██ ██ ▀██ ████▀ ▀███▀  ▀█▀█▀  


using namespace std;

class Window{
public:
    void init(int x, int y, int z);
    void color();
    void swap();
    void clean();

    //set
    void setWindowSize(int w, int h);
    void setWindowTitle(const char* title);

    //just dont use it!
    void setW(int w);
    void setH(int h);

    //get 
    GLFWwindow* getWindow() const;
    int getW() const;
    int getH() const;

private: 
    GLFWwindow* window = nullptr;
    int w=600,h=400;
    int x=0,y=0,z=0;
    const char* title = "penguin Engine";

    void glfwHint();
    void windowERROR();
    void gladInit();
    void clearColor(int x, int y, int z);
};

extern Window window;