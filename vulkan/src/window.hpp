#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <GLFW/glfw3.h>

class Window {
public:
    // Method to initialize the window
    void initWindow(GLFWwindow* &window, uint32_t WIDTH, uint32_t HEIGHT);
};

#endif // WINDOW_HPP
