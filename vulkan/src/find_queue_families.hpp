#ifndef FIND_QUEUE_FAMILIES_HPP
#define FIND_QUEUE_FAMILIES_HPP
#include <optional>
#include <vulkan/vulkan_core.h>

// Struct to bundle queue family indices
struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
};

// Find families that GPU supports
QueueFamilyIndices find_queue_families(VkPhysicalDevice &device);

#endif // FIND_QUEUE_FAMILIES_HPP
