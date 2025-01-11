#include "engine.hpp"

void Engine::run() {
    initVulkan();
    mainLoop();
    cleanup();
}

void Engine::initVulkan() {
    // Vulkan initialization logic
}

void Engine::mainLoop() {
    // Main loop logic
}

void Engine::cleanup() {
    // Cleanup logic
}
