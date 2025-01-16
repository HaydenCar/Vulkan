#ifndef CREATE_LOGICAL_DEVICE_HPP
#define CREATE_LOGICAL_DEVICE_HPP
#include <vulkan/vulkan_core.h>

// Method to create an instance of Vulkan
void create_logical_device(VkPhysicalDevice &physicalDevice, VkDevice &device, VkQueue &graphicsQueue, VkSurfaceKHR &surface, VkQueue &presentQueue);

#endif // CREATE_LOGICAL_DEVICE_HPP
