#include "find_queue_families.hpp"
#include <cstdint>
#include <vector>
#include <vulkan/vulkan_core.h>

// Find families that GPU supports
QueueFamilyIndices find_queue_families(VkPhysicalDevice &device, VkSurfaceKHR &surface){
    QueueFamilyIndices indices;

    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    int i = 0;
    for (const auto& queueFamily : queueFamilies) {
        if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.graphicsFamily = i;
        }

        VkBool32 presentSupport = false;
        vkGetPhysicalDeviceSurfaceSupportKHR(device, i, surface, &presentSupport);

        if (presentSupport) {
            indices.presentFamily = i;
        }


        if (indices.isComplete()) {
            break;
        }
        i++;
    }

    return indices;
}
