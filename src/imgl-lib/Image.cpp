/**
 * @file Image.cpp
 * @author liam 
 * @date 03/02/2025
 */

#include "imgl/Image.hpp"

namespace imgl {
    Image::Image(const char* path) {
	    loadFromFile(path);
    }

	Image::~Image() {
		if (data) {
			stbi_image_free(data);
		}
    }

	int Image::getWidth() const {
	    return width;
    }

	int Image::getHeight() const {
	    return height;
    }

	int Image::getChannels() const {
	    return channels;
    }

	unsigned char* Image::getData() const {
	    return data;
    }

	void Image::loadFromFile(const char* path) {
		data = stbi_load(path, &width, &height, &channels, 0);
    }
} // namespace imgl