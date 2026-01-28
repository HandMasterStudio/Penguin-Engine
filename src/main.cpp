#include<glad/glad.h>
#include<window/window.h>
#include<iostream>

using namespace std;

int main(){
    window.setWindowSize(500,400);
    window.init(0,0,0);

    while(!glfwWindowShouldClose(window.getWindow())){
        window.color();
        window.swap();
    }
    window.clean();
    return 0;
}