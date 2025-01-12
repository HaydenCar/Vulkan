#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <GLFW/glfw3.h>
#include <vulkan/vulkan_core.h>

class Engine {
public:
    // Public method to run the engine
    void run();

private:
    void mainLoop();
    void cleanup();
    VkInstance instance;
    GLFWwindow* window;
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;
};

#endif // ENGINE_HPP
