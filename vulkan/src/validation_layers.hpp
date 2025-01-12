#ifndef VALIDATION_LAYERS_HPP
#define VALIDATION_LAYERS_HPP
#include <vector>

namespace ValidationLayers {
    bool checkValidationLayerSupport(std::vector<const char*> validationLayers);
}

// Extern variables for use in validation
extern const std::vector<const char*> validationLayers;
extern const bool enableValidationLayers;

#endif // VALIDATION_LAYERS_HPP
