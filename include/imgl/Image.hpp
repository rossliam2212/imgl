/**
 * @file Image.hpp
 * @author liam 
 * @date 03/02/2025
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

#include "stb-image/stb_image.h"

namespace imgl {
	class Image {
	public:
    	Image(const char* path);
    	~Image();

		int getWidth() const;
		int getHeight() const;
		int getChannels() const;
		unsigned char* getData() const;
		unsigned int getTexture() const;

	private:
		int width{0};
		int height{0};
		int channels{0};
		unsigned char* data{nullptr};
		unsigned int texture{0};

		void loadFromFile(const char* path);
		void createTexture();
	};
} // namespace imgl

#endif //IMAGE_HPP
