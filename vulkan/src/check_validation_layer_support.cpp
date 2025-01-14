#include "check_validation_layer_support.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>
#include <vulkan/vulkan_core.h>

// This function checks if validation layers are supported
bool check_validation_layer_support(const std::vector<const char*>& validationLayers) {
    uint32_t layerCount;
    VkResult result = vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    if (result != VK_SUCCESS) {
        std::cerr << "Failed to enumerate instance layer properties.\n";
        return false;
    }

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    std::cout << "Available Vulkan layers:\n";
    for (const auto& layer : availableLayers) {
        std::cout << '\t' << layer.layerName << '\n';
    }

    for (const char* layerName : validationLayers) {
        bool layerFound = false;

        for (const auto& layerProperties : availableLayers) {
            if (strcmp(layerName, layerProperties.layerName) == 0) {
                layerFound = true;
                break;
            }
        }

        if (!layerFound) {
            std::cerr << "Validation layer not found: " << layerName << '\n';
            return false;
        }
    }

    return true;
}
