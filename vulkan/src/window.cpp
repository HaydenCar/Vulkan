#include "window.hpp"
#include <stdexcept>

void Window::initWindow(GLFWwindow* &window, uint32_t WIDTH, uint32_t HEIGHT) {
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Create the window and assign to the window passed by reference
    window = glfwCreateWindow(WIDTH, HEIGHT, "vulkan", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
}
