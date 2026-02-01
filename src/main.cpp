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
        0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    vector<unsigned int> indices{
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    ShaderLoader* shader = new ShaderLoader("res/shader/vertex.shader","res/shader/fragment.shader");
    Loader* traingle = new Loader(vertices, indices);

    //loader init
    traingle->loadIndices();

    while(!glfwWindowShouldClose(window.getWindow())){
        window.color();

        shader->use();
        traingle->renderElements(traingle->getVao());

        window.swap();
    }
    window.clean();
    return 0;
}