/**
 * @file FrameBuffer.hpp
 * @author liam 
 * @date 03/02/2025
 */

#ifndef FRAMEBUFFER_HPP
#define FRAMEBUFFER_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace imgl {
	class FrameBuffer {
	public:
    	FrameBuffer(int width, int height);
    	~FrameBuffer();

		void bind() const;
		void unbind() const;
		bool complete();
		unsigned int getTexture() const;

	private:
		unsigned int fbo{0};
		unsigned int texture{0};
		int width;
		int height;

	};
} // namespace imgl

#endif //FRAMEBUFFER_HPP
