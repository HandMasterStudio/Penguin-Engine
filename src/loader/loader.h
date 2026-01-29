#pragma once 
#include<glad/glad.h>
#include<iostream>
#include<vector>

using namespace std;

class Loader{
public:
    Loader(vector<float> vertices);
    void clean();

    //get
    unsigned int getVao();
private:
    vector<float> vertices;
    unsigned int vao, vbo;
    
    void bind();
    void unBind();
};