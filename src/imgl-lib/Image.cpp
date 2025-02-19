/**
 * @file Image.cpp
 * @author liam 
 * @date 03/02/2025
 */

#include "imgl/Image.hpp"

namespace imgl {
    Image::Image(const char* path) {
	    loadFromFile(path);

    	if (data) {
    		createTexture();
    	} else {
    		throw std::runtime_error("Error loading image");
    	}
    }

	Image::~Image() {
		if (data) {
			stbi_image_free(data);
		}
    	glDeleteTextures(1, &texture);
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

	unsigned int Image::getTexture() const {
	    return texture;
    }

	void Image::loadFromFile(const char* path) {
    	// TODO Error handling
		data = stbi_load(path, &width, &height, &channels, 0);
    }

	void Image::createTexture() {
    	glGenTextures(1, &texture);
    	glBindTexture(GL_TEXTURE_2D, texture);

    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    	const int format = channels == 4 ? GL_RGBA : GL_RGB;
    	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    	glGenerateMipmap(GL_TEXTURE_2D);

    	glBindTexture(GL_TEXTURE_2D, 0);
    }
} // namespace imgl