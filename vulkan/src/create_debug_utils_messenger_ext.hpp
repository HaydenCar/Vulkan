#ifndef CREATE_DEBUG_UTILS_MESSENGER_EXT_HPP
#define CREATE_DEBUG_UTILS_MESSENGER_EXT_HPP
#include <vulkan/vulkan_core.h>

VkResult create_debug_utils_messenger_ext(
    VkInstance instance,
    const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDebugUtilsMessengerEXT* pDebugMessenger);


#endif // CREATE_DEBUG_UTILS_MESSENGER_EXT_HPP
