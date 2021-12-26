#pragma once

// indices (locations) of queue families (if they exist at all)
struct QueueFamilyIndices {
	int graphicsFamily = -1;			// location of graphics queue family

	// check if queue families are valid
	bool isValid() {
		return graphicsFamily >= 0;
	}
};
