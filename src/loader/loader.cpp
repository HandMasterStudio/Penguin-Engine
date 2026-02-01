#include"loader/loader.h"

Loader::Loader(vector<float> vertices){
    this->vertices = vertices;
}

Loader::Loader(vector<float> vertices, vector<unsigned int> indices){
    this->vertices = vertices;
    this->indices = indices;
}

void Loader::loadVertices(){
    //need to use renderArrays() to render;
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

void Loader::loadIndices(){
    //need to use renderElements() to render;
    //bind
    bind();

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(float),&vertices[0],GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()*sizeof(unsigned int),&indices[0],GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    //unbind
    unBind();
}

void Loader::renderArrays(unsigned int vao){
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Loader::renderElements(unsigned int vao){
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
}

void Loader::clean(){
    cout<<"Clean Loader"<<endl;
    vertices.clear();
    indices.clear();
}

//get
unsigned int Loader::getVao() const{
    return vao; 
}

//private
void Loader::bind(){
    glGenVertexArrays(1,&vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1,&ebo);
    cout<<"Loader bind"<<endl;
}

void Loader::unBind(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    cout<<"Loader unBind"<<endl;
}