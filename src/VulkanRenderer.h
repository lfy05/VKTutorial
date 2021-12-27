#pragma once
#include <vector>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan_core.h>

#include "Utilities.h"

struct SwapChainSupportDetails;

class VulkanRenderer {
public:
	int initVulkan(GLFWwindow* newWindow);
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
	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	std::vector<VkImageView> swapChainImageViews;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;

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
	bool isDeviceSuitable(VkPhysicalDevice device);

	// -- getter functions
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

	const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHORNOS_validation"
	};

	const std::vector<const char*> deviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
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


	// -- swap chains
	bool checkDeviceExtensionsSupport(VkPhysicalDevice device);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void createSwapChain();
	std::vector<VkImageView> createImageViews();
	void createGraphicsPipeline();
	VkShaderModule createShaderModule(const std::vector<char>& code);
};
