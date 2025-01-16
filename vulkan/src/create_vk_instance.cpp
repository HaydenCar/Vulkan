#include "create_vk_instance.hpp"
#include "check_validation_layer_support.hpp"
#include "get_required_extensions.hpp"
#include <GLFW/glfw3.h>
#include <cstdint>
#include <iostream>
#include <vector>
#include <vulkan/vulkan_core.h>

// Creates an instance of Vulkan
void create_vk_instance(VkInstance& instance){
    // Checks if validation layers are enabled
    if (enableValidationLayers && check_validation_layer_support(validationLayers)){
        std::cout << "Requested validation layers:\n";
        for (const auto& layer : validationLayers) {
            std::cout << '\t' << layer << '\n';
        }

        if (!check_validation_layer_support(validationLayers)) {
            throw std::runtime_error("Validation layers requested, but not available!");
        }
    }
    std::cout << "Validation layers enabled: " << std::boolalpha << enableValidationLayers << std::endl;
    // Fill out appInfo necessary for createInfo
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "vulkan";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "melonia";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_3;

    // Checks that user has required GLFW extensions
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    if (!glfwExtensions) {
        throw std::runtime_error("Failed to get required GLFW extensions.");
    }

    // Fill out the createInfo struct necessary for instance
    // also references to the appInfo above
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    auto extensions = get_required_extensions();
    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();
    if (enableValidationLayers) {
        std::cout << "Requested validation layers:\n";
            for (const auto& layer : validationLayers) {
                std::cout << '\t' << layer << '\n';
            }
        createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
        createInfo.ppEnabledLayerNames = validationLayers.data();
    } else {
        createInfo.enabledLayerCount = 0;
    }

    // Creates the instance here
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    if (result != VK_SUCCESS) {
        throw std::runtime_error("Failed to create Vulkan instance!");
    }

    // Check for available Vulkan extensions
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> vk_extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, vk_extensions.data());
    std::cout << "extension count: " << extensionCount << "\n";
    std::cout << "available extensions:\n";
    for (const auto& extension : vk_extensions) {
        std::cout << '\t' << extension.extensionName << '\n';
    }
}
