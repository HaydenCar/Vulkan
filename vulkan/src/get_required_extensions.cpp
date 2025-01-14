#include "get_required_extensions.hpp"
#include "check_validation_layer_support.hpp"
#include <GLFW/glfw3.h>
#include <cstdint>
#include <vector>
#include <vulkan/vulkan_core.h>

// This finds the required extensions needed to run
std::vector<const char*> get_required_extensions(){
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    // Takes in the array of necessary GLFW extensions
    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    // If validation layers are enabled add the debug extension
    if (enableValidationLayers) {
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }

    return extensions;
}
