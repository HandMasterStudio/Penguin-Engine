#pragma once 
#include<glad/glad.h>
#include<iostream>
#include<vector>

using namespace std;

class Loader{
public:
    Loader(vector<float> vertices);
    void renderArrays(unsigned int vao); // just need vertices 
    void renderElements(unsigned int vao); //need vertices and indices
    void clean();

    //get
    unsigned int getVao();
private:
    vector<float> vertices;
    unsigned int vao, vbo;
    
    void bind();
    void unBind();
};