#ifndef CHECK_VALIDATION_LAYER_SUPPORT_HPP
#define CHECK_VALIDATION_LAYER_SUPPORT_HPP
#include <vector>

// function that returns a bool that tells if validation layers are supported
bool check_validation_layer_support(const std::vector<const char*>& validationLayers);


extern const std::vector<const char*> validationLayers;

// Extern variables for use in validation
extern const bool enableValidationLayers;

#endif // CHECK_VALIDATION_LAYER_SUPPORT_HPP
