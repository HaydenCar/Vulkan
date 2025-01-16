#ifndef QUERY_SWAP_CHAIN_SUPPORT_HPP
#define QUERY_SWAP_CHAIN_SUPPORT_HPP
#include <vector>
#include <vulkan/vulkan_core.h>

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

SwapChainSupportDetails query_swap_chain_support(VkPhysicalDevice &device, VkSurfaceKHR &surface);

#endif // QUERY_SWAP_CHAIN_SUPPORT_HPP
