/**
 * @file FrameBuffer.cpp
 * @author liam 
 * @date 03/02/2025
 */

#include "imgl/FrameBuffer.hpp"

namespace imgl {
	FrameBuffer::FrameBuffer(const int width, const int height)
		: width{width}, height{height} {
		glGenFramebuffers(1, &fbo);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);

		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
			std::cerr << "Error: Framebuffer is not complete!\n";
		}
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	FrameBuffer::~FrameBuffer() {
		glDeleteFramebuffers(1, &fbo);
		glDeleteTextures(1, &texture);
	}

	void FrameBuffer::bind() const {
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
		glViewport(0, 0, width, height);
	}

	void FrameBuffer::unbind() const {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	unsigned int FrameBuffer::getTexture() const {
		return texture;
	}
} // namespace imgl