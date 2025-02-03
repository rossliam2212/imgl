/**
 * @file RenderContext.cpp
 * @author liam 
 * @date 03/02/2025
 */

#include "imgl/RenderContext.hpp"

namespace imgl {
	RenderContext::~RenderContext() {
		glfwDestroyWindow(window);
	 	glfwTerminate();
	}

	void RenderContext::init() {
		if (!glfwInit()) {
			std::cerr << "Failed to initialize GLFW\n";
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, " ", nullptr, nullptr);
		if (!window) {
			std::cerr << "Failed to create GLFW window\n";
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK) {
			std::cerr << "Error: Failed to initialize GLEW" << std::endl;
			return;
		}
	}
} // namespace imgl