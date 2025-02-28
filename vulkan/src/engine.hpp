#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <GLFW/glfw3.h>
#include <vector>
#include <vulkan/vulkan_core.h>

class Engine {
public:
    // Public method to run the engine
    void run();


private:
    void mainLoop();
    void cleanup();
    GLFWwindow* window;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkInstance instance;
    VkDevice device;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkSurfaceKHR surface;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;
};


#endif // ENGINE_HPP
