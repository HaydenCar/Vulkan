#include <vector>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "engine.hpp"
#include "window.hpp"
#include "vulkan_init.hpp"

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;

#else
    const bool enableValidationLayers = true;
#endif

void Engine::run() {
    Window windowInit;
    windowInit.initWindow(window, WIDTH, HEIGHT);
    VulkanInit vulkanInit;
    vulkanInit.initVulkan(instance);
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
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
}
