/**
 * @file RenderUtils.hpp
 * @author liam 
 * @date 04/02/2025
 */

#ifndef RENDERUTILS_HPP
#define RENDERUTILS_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace imgl {
	class RenderUtils {
	public:
    	RenderUtils() = default;
    	~RenderUtils() = default;

		static void render();
		static void cleanup();
};
} // namespace imgl

#endif //RENDERUTILS_HPP
