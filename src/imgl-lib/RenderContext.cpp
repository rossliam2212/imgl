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
			spdlog::error("Failed to initialize GLFW.");
			throw std::runtime_error("Failed to initialize render context");
		}
		spdlog::debug("Successfully initialized GLFW");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, " ", nullptr, nullptr);
		if (!window) {
			spdlog::error("Failed to create GLFW window");
			glfwTerminate();
			throw std::runtime_error("Failed to initialize render context");
		}
		spdlog::debug("Successfully created GLFW window.");
		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK) {
			spdlog::error("Failed to initialize GLEW");
			throw std::runtime_error("Failed to initialize render context");
		}
		spdlog::debug("Successfully initialized GLEW.");
		spdlog::debug("OpenGL Version: {}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
		spdlog::debug("GLSL Version: {}", reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)));
		spdlog::debug("GPU: {}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
		spdlog::debug("Vendor: {}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
	}
} // namespace imgl