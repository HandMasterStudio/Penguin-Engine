#include"loader/loader.h"

Loader::Loader(vector<float> vertices){
    this->vertices = vertices;
    //bind
    bind();

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(float),&vertices[0],GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    //unbind
    unBind();
}

void Loader::clean(){
    cout<<"Clean Loader"<<endl;
    vertices.clear();
}

//get
unsigned int Loader::getVao(){
    return vao; 
}

//private
void Loader::bind(){
    glGenVertexArrays(1,&vao);
    glGenBuffers(1, &vbo);
    cout<<"Loader bind"<<endl;
}

void Loader::unBind(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    cout<<"Loader unBind"<<endl;
}