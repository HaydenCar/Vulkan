#ifndef CREATE_SURFACE_HPP
#define CREATE_SURFACE_HPP
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan_core.h>

// Method to create the surface on the GLFW window for Vulkan
void create_surface(VkInstance &instance, GLFWwindow* &window, VkSurfaceKHR &surface);

#endif // CREATE_SURFACE_HPP
