#pragma once 
#include<glad/glad.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include<string>

using namespace std;

class ShaderLoader{
public:
    ShaderLoader(const char* vertexPath, const char* fragmentPath);
    void use();
    void clean();
private:
    unsigned int ID;

    void ERROR(GLuint shader, string type);
    string shaderCompiler(const char* file);
};