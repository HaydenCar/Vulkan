#include "setup_debug_messenger.hpp"
#include "check_validation_layer_support.hpp"
#include "debug_callback.hpp"
#include <stdexcept>
#include <vulkan/vulkan_core.h>
#include "create_debug_utils_messenger_ext.hpp"

// This function is used to decide what errors the debugger throws and calls create_debug_utils_messenger_ext to then instantiate the debugger
void setup_debug_messenger(VkDebugUtilsMessengerEXT &debugMessenger,
VkInstance &instance){
    if (!enableValidationLayers) {
        return;
    }

    VkDebugUtilsMessengerCreateInfoEXT createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT| VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    createInfo.pfnUserCallback = debug_callback;
    createInfo.pUserData = nullptr;

    if (create_debug_utils_messenger_ext(instance, &createInfo, nullptr, &debugMessenger) != VK_SUCCESS) {
        throw std::runtime_error("failed to set up debug messenger!");
    }

}
