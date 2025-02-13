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
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

		if (!complete()) {
			std::cerr << "Error: Framebuffer is not complete!\n";
		}
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	FrameBuffer::~FrameBuffer() {
		if (fbo) {
			glDeleteFramebuffers(1, &fbo);
		}
		if (texture) {
			glDeleteTextures(1, &texture);
		}
	}

	void FrameBuffer::bind() const {
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
		glViewport(0, 0, width, height); // Causing error
	}

	void FrameBuffer::unbind() const {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	bool FrameBuffer::complete() {
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
		unsigned int status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		return status == GL_FRAMEBUFFER_COMPLETE;
	}

	unsigned int FrameBuffer::getTexture() const {
		return texture;
	}

} // namespace imgl