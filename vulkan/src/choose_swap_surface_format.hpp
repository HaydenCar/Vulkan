#ifndef CHOOSE_SWAP_SURFACE_FORMAT_HPP
#define CHOOSE_SWAP_SURFACE_FORMAT_HPP
#include <vector>
#include <vulkan/vulkan_core.h>

// chooses the presentation mode for the screen
VkSurfaceFormatKHR choose_swap_surface_format(const std::vector<VkSurfaceFormatKHR>& availableFormats);

#endif // CHOOSE_SWAP_SURFACE_FORMAT_HPP
