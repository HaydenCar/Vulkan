#ifndef ENGINE_HPP
#define ENGINE_HPP

class Engine {
public:
    // Public method to run the engine
    void run();

private:
    // Private helper methods for Vulkan initialization, main loop, and cleanup
    void initVulkan();
    void mainLoop();
    void cleanup();
};

#endif // ENGINE_HPP
