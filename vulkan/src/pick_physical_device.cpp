#include "pick_physical_device.hpp"
#include "is_device_suitable.hpp"
#include <cstdint>
#include <stdexcept>
#include <vector>
#include <vulkan/vulkan_core.h>

// This function picks the GPU vulkan will use
void pick_physical_device(VkInstance &instance, VkPhysicalDevice &physicalDevice, VkSurfaceKHR &surface){
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

    if (deviceCount == 0) {
        throw std::runtime_error("failed to find GPUs with Vulkan support!");
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount ,devices.data());

    for (const auto& device : devices) {
        if (is_device_suitable(device, surface)) {
            physicalDevice = device;
            break;
        }
    }

    if (physicalDevice == VK_NULL_HANDLE) {
        throw std::runtime_error("failed to find a suitable GPU!");
    }
}
