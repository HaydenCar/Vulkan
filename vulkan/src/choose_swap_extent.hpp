#ifndef CHOOSE_SWAP_EXTENT_HPP
#define CHOOSE_SWAP_EXTENT_HPP
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan_core.h>


VkExtent2D choose_swap_extent(const VkSurfaceCapabilitiesKHR& capabilities, GLFWwindow* window);

#endif // CHOOSE_SWAP_EXTENT_HPP
