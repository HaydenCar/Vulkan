#ifndef CHOOSE_SWAP_PRESENT_MODE_HPP
#define CHOOSE_SWAP_PRESENT_MODE_HPP
#include <vector>
#include <vulkan/vulkan_core.h>

// chooses the colour space for the screen
VkPresentModeKHR choose_swap_present_mode(const std::vector<VkPresentModeKHR>& availablePresentModes);

#endif // CHOOSE_SWAP_PRESENT_MODE_HPP
