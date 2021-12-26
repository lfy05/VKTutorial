#pragma once
#include <optional>

// indices (locations) of queue families (if they exist at all)
struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	// check if queue families are valid
	bool isComplete() const {
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};
