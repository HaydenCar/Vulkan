#ifndef VULKAN_INIT_HPP
#define VULKAN_INIT_HPP
#include <vulkan/vulkan_core.h>

class VulkanInit {
public:
    // Method to initialize vulkan
    void initVulkan(VkInstance& instance);

private:
    void createInstance(VkInstance& instance);
};

#endif // VULKAN_INIT_HPP
