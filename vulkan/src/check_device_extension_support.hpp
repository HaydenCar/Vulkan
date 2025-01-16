#ifndef CHECK_DEVICE_EXTENSION_SUPPORT_HPP
#define CHECK_DEVICE_EXTENSION_SUPPORT_HPP
#include <vector>
#include <vulkan/vulkan_core.h>

// function that checks if the extensions are supported on the GPU
bool check_device_extension_support(VkPhysicalDevice &device);

extern const std::vector<const char*> deviceExtensions;

#endif // CHECK_DEVICE_EXTENSION_SUPPORT_HPP
