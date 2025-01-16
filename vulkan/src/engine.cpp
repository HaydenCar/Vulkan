#include "create_logical_device.hpp"
#include "create_surface.hpp"
#include "create_swap_chain.hpp"
#include "destroy_debug_utils_messenger_ext.hpp"
#include "pick_physical_device.hpp"
#include "setup_debug_messenger.hpp"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "engine.hpp"
#include "init_window.hpp"
#include "create_vk_instance.hpp"
#include "check_validation_layer_support.hpp"
#include "check_device_extension_support.hpp"

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

const std::vector<const char*> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;

#else
    const bool enableValidationLayers = true;
#endif

void Engine::run() {
    init_window(window, WIDTH, HEIGHT);
    create_vk_instance(instance);
    setup_debug_messenger(debugMessenger, instance);
    create_surface(instance, window, surface);
    pick_physical_device(instance, physicalDevice, surface);
    create_logical_device(physicalDevice, device, graphicsQueue, surface, presentQueue);
    create_swap_chain(device, physicalDevice, window, surface, swapChain, swapChainImages, swapChainImageFormat, swapChainExtent);

    mainLoop();

    cleanup();
}

void Engine::mainLoop() {
    // Main loop logic
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void Engine::cleanup() {
    vkDestroySwapchainKHR(device, swapChain, nullptr);
    vkDestroyDevice(device, nullptr);
    if (enableValidationLayers) {
        destroy_debug_utils_messenger_ext(instance, debugMessenger, nullptr);
    }
    vkDestroySurfaceKHR(instance, surface, nullptr);
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
}
