#include "vulkan_init.hpp"
#include "validation_layers.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <vulkan/vulkan_core.h>

/*
void VulkanInit::initVulkan(VkInstance& instance) {
    // Vulkan initialization logic
    // VulkanInit::createInstance(instance);
}
*/

// Creates an instance of Vulkan
void VulkanInit::createInstance(VkInstance& instance){
    // Checks if validation layers are enabled
    if (enableValidationLayers && ValidationLayers::checkValidationLayerSupport(validationLayers)){
        throw std::runtime_error("validation layers requested, but not available!");
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
    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;

    // Creates the instance here
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    if (result != VK_SUCCESS) {
        throw std::runtime_error("Failed to create Vulkan instance!");
    }

    // Check for available Vulkan extensions
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
    std::cout << "extension count: " << extensionCount << "\n";
    std::cout << "available extensions:\n";
    for (const auto& extension : extensions) {
        std::cout << '\t' << extension.extensionName << '\n';
    }
}
