#ifndef FIND_QUEUE_FAMILIES_HPP
#define FIND_QUEUE_FAMILIES_HPP
#include <optional>
#include <vulkan/vulkan_core.h>

// Struct to bundle queue family indices
struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

// Find families that GPU supports
QueueFamilyIndices find_queue_families(VkPhysicalDevice &device, VkSurfaceKHR &surface);

#endif // FIND_QUEUE_FAMILIES_HPP
