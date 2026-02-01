#include "window/window.h"

void Window::init(int x, int y, int z){
    glfwInit();
    glfwHint();

    window = glfwCreateWindow(w,h,title,NULL,NULL);
    windowERROR();
    glfwMakeContextCurrent(window);
    gladInit();

    clearColor(x,y,z);
    glClearColor(this->x,this->y,this->z,1);
    cout<<"Opengl Version: "<<glGetString(GL_VERSION)<<endl;
}

void Window::color(){
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::swap(){
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::clean(){
    cout<<"Terminate Window"<<endl;
    glfwTerminate();
}

//set
void Window::setWindowSize(int w, int h){
    this->w = w;
    this->h = h;
    glfwSetWindowSize(window, w,h);
    cout<<"Set window size: "<<w<<","<<h<<endl;
}

void Window::setWindowTitle(const char* title){
    this->title = title;
    glfwSetWindowTitle(window, title);
}

//get 
GLFWwindow* Window::getWindow() const{
    return window;
}

//private
void Window::glfwHint(){
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    cout<<"glfwHint"<<endl;
}

void Window::windowERROR(){
    if(!window){
        cout<<"ERROR::Window failed to create"<<endl;
        glfwTerminate();
        return;
    }
}

void Window::gladInit(){
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    cout << "ERROR::GLAD failed to init" << endl;
    glfwTerminate();
    return;
    }
    cout<<"Glad init"<<endl;
}

void Window::clearColor(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
    cout<<"Setting Up color"<<endl;
}

Window window;