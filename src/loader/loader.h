#pragma once 
#include<glad/glad.h>
#include<iostream>
#include<vector>

using namespace std;

class Loader{
public:
    Loader(vector<float> vertices);
    Loader(vector<float> vertices, vector<unsigned int> indices);
    void loadVertices();
    void loadIndices();
    void renderArrays(unsigned int vao); // just need vertices 
    void renderElements(unsigned int vao); //need vertices and indices
    void clean();

    //get
    unsigned int getVao() const;
private:
    vector<float> vertices;
    vector<unsigned int> indices;
    unsigned int vao, vbo, ebo;
    
    void bind();
    void unBind();
};