#ifndef DEBUG_CALLBACK_HPP
#define DEBUG_CALLBACK_HPP
#include <vulkan/vk_platform.h>
#include <vulkan/vulkan_core.h>

extern VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallBackData, void* pUserData);

#endif // DEBUG_CALLBACK_HPP
