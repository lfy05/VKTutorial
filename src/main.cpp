#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>
#include <glm/ext/matrix_float4x4.hpp>
#include "VulkanRenderer.h"

GLFWwindow* window;
VulkanRenderer vulkanRenderer;

void initWindow(std::string wName = "Test Window", const int width = 800, const int height = 600) {
	// initialize GLFW
	glfwInit();

	// Set GLFW to NOT work with OpenGL
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr);
}

int main() {
	// Create a Window
	initWindow("Test Window", 800, 600);

	// Create a vulkan rendere instance
	if (vulkanRenderer.initVulkan(window) == EXIT_FAILURE) {
		return EXIT_FAILURE;
	}

	// loop until closed
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		vulkanRenderer.drawFrame();
	}

	vulkanRenderer.cleanUp();

	// Destroy GLFW window
	glfwDestroyWindow(window);
	glfwTerminate();
}
