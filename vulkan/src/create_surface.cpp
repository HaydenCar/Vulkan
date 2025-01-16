#include "create_surface.hpp"
#include <stdexcept>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan_core.h>

// Method to create the surface on the GLFW window for Vulkan
void create_surface(VkInstance &instance, GLFWwindow* &window, VkSurfaceKHR &surface){
    if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) {
        throw std::runtime_error("failed to create window surface!");
    }
}
