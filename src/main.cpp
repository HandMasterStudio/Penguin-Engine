#include<glad/glad.h>
#include<window/window.h>
#include"loader/loader.h"
#include"loader/shaderLoader.h"
#include<iostream>
#include<vector>

using namespace std;

int main(){
    window.setWindowSize(500,400);
    window.init(0,0,0);

    vector<float>vertices{
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top 
    };

    ShaderLoader* shader = new ShaderLoader("res/shader/vertex.shader","res/shader/fragment.shader");
    Loader* traingle = new Loader(vertices);

    while(!glfwWindowShouldClose(window.getWindow())){
        window.color();

        shader->use();
        traingle->renderArrays(traingle->getVao());

        window.swap();
    }
    window.clean();
    return 0;
}