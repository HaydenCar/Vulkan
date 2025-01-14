#include "is_device_suitable.hpp"
#include "find_queue_families.hpp"

// This function checks how suitable the GPU is for our use
bool is_device_suitable(VkPhysicalDevice device){
    VkPhysicalDeviceProperties deviceProperties;
    vkGetPhysicalDeviceProperties(device, &deviceProperties);

    VkPhysicalDeviceFeatures deviceFeatures;
    vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

    QueueFamilyIndices indices = find_queue_families(device);

    return indices.graphicsFamily.has_value();
}
