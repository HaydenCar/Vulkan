#include "is_device_suitable.hpp"
#include "check_device_extension_support.hpp"
#include "find_queue_families.hpp"
#include "query_swap_chain_support.hpp"

// This function checks how suitable the GPU is for our use
bool is_device_suitable(VkPhysicalDevice device, VkSurfaceKHR surface){
    VkPhysicalDeviceProperties deviceProperties;
    vkGetPhysicalDeviceProperties(device, &deviceProperties);

    VkPhysicalDeviceFeatures deviceFeatures;
    vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

    bool extensionsSupported = check_device_extension_support(device);

    bool swapChainAdequate = false;
    if (extensionsSupported) {
        SwapChainSupportDetails swapChainSupport = query_swap_chain_support(device, surface);
        swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
    }

    QueueFamilyIndices indices = find_queue_families(device, surface);

    return indices.isComplete() && extensionsSupported && swapChainAdequate;
}
