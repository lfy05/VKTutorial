#pragma once
#include <vector>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan_core.h>

#include "Utilities.h"

class VulkanRenderer {
public:
	int init(GLFWwindow* newWindow);
	void cleanUp();

private:
	GLFWwindow* window;

	// vulkan components
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;

	// Window Surface
	VkSurfaceKHR surface;

	struct {
		VkPhysicalDevice physicalDevice;
		VkDevice logicalDevice;
	} mainDevice;

	VkQueue graphicsQueue;
	VkQueue presentQueue;

	/* Vulkan Functions*/
	// - create functions
	void createInstance();
	void createLogicalDevice();
	void createSurface();

	// - Get Functions
	void getPhysicalDevice();

	// - support functions
	// -- checker functions
	bool checkInstanceExtensionSupport(std::vector<const char*>* checkExtensions);
	bool checkDeviceSuitable(VkPhysicalDevice device);

	// -- getter functions
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

	const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHORNOS_validation"
	};

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

	// -- validation layer
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();
	void setupDebugMessegner();
	VkResult createDebugUtilsMessengerEXT(VkInstance instance,
	                                      const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
	                                      const VkAllocationCallbacks* pAllocator,
	                                      VkDebugUtilsMessengerEXT* pDebugMessenger);

	void destroyDebugUtilsMessengerEXT(VkInstance instance,
	                                   VkDebugUtilsMessengerEXT debugMessenger,
	                                   const VkAllocationCallbacks* pAllocator);

};