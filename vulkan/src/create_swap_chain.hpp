#ifndef CREATE_SWAP_CHAIN_HPP
#define CREATE_SWAP_CHAIN_HPP
#include <vector>
#include <vulkan/vulkan_core.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// Method to create the swapchain
void create_swap_chain(VkDevice device, VkPhysicalDevice physicalDevice, GLFWwindow* window, VkSurfaceKHR surface,
                    VkSwapchainKHR &swapChain, std::vector<VkImage> &swapChainImages, VkFormat swapChainImageFormat,
                    VkExtent2D swapChainExtent);

#endif // CREATE_SWAP_CHAIN_HPP
