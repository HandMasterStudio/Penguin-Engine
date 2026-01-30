#include"loader/shaderLoader.h"

ShaderLoader::ShaderLoader(const char* vertexPath, const char* fragmentPath){
    string cVertex = shaderCompiler(vertexPath);
    string cFragment = shaderCompiler(fragmentPath);

    const char* vShaderCode = cVertex.c_str();
    const char* fShaderCode = cFragment.c_str();

    unsigned int vertex, fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    ERROR(vertex, "VERTEX");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment,1,&fShaderCode,NULL);
    glCompileShader(fragment);
    ERROR(fragment, "FRAGMENT");

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment); 
    glLinkProgram(ID);
    ERROR(ID, "PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    cout<<"Delete Shader"<<endl;
}

void ShaderLoader::use(){
    glUseProgram(ID);
}

void ShaderLoader::clean(){
    glDeleteProgram(ID);
    cout<<"Delete program"<<endl;
}

//private
void ShaderLoader::ERROR(GLuint shader, string type){
    GLint succ;
    GLchar infoLog[1024];
    if(type != "PROGRAM"){
        glGetShaderiv(shader,GL_COMPILE_STATUS,&succ);
        if(!succ){
            glGetShaderInfoLog(shader,1024,NULL,infoLog);
            cout<<"ERROR::Shader error type: "<<type<<"\n"<<infoLog<<endl;
        }
    }else{
        glGetProgramiv(shader,GL_LINK_STATUS,&succ);
        cout<<"Program link success"<<endl;
        if(!succ){
                glGetProgramInfoLog(shader,1024,NULL,infoLog);
                cout<<"ERROR::Program link error type: "<<type<<"\n"<<infoLog<<endl;
        }
    }
}

string ShaderLoader::shaderCompiler(const char* file){
    string code;
    ifstream shaderFile;
    shaderFile.exceptions(ifstream::failbit | ifstream::badbit);
    try{
        shaderFile.open(file);
        stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        code = shaderStream.str();
        cout<<"Shader success Compiler"<<endl;
    }catch(ifstream::failure& e){
        cout<<"ERROR::Shader file cannot be read"<<e.what()<<endl;
    }

    return code;
}