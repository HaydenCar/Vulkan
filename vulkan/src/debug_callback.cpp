#include "debug_callback.hpp"
#include <iostream>

// This is where the errors in the VL are made
VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallBackData, void* pUserData){

        std::cerr << "Validation layer: " << pCallBackData->pMessage << "\n";

        return VK_FALSE;
}
