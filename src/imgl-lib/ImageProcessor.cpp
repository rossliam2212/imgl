/**
 * @file ImageProcessor.cpp
 * @author liam 
 * @date 03/02/2025
 */

#include "imgl/ImageProcessor.hpp"

namespace imgl {
	void ImageProcessor::applySharpenFilter(Image& img, std::string_view outputPath, float intensity) {
		const int width = img.getWidth();
		const int height = img.getHeight();
		const int channels = img.getChannels();

		FrameBuffer fbo{width, height};
		fbo.bind();

		Shader sharpenShader{DEFAULT_VERT_SHADER, SHARPEN_FRAG_SHADER};
		sharpenShader.enable();

		// TODO move to Image class...
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, img.getTexture());
		sharpenShader.setInt("image", 0);
		sharpenShader.setFloat("intensity", intensity);

		RenderUtils::render();

		outputImage(fbo, outputPath, width, height, channels);

		fbo.unbind();
		sharpenShader.disable();
		RenderUtils::cleanup();
	}

	void ImageProcessor::applyGaussianBlurFilter(Image& img, std::string_view outputPath, float intensity) {

	}

	void ImageProcessor::applyGrayscaleFilter(Image& img, std::string_view outputPath, float intensity) {

	}

	void ImageProcessor::outputImage(const FrameBuffer& fbo, const std::string_view outputPath, const int width, const int height, const int channels) {
		const int format = channels == 4 ? GL_RGBA : GL_RGB;
		auto* pixels = new unsigned char[width * height * 3];
		glBindTexture(GL_TEXTURE_2D, fbo.getTexture());
		glGetTexImage(GL_TEXTURE_2D, 0, format, GL_UNSIGNED_BYTE, pixels);

		if (outputPath.find(EXTENSION_PNG) != std::string::npos) {
			stbi_write_png(outputPath.data(), width, height, channels, pixels, width * channels);
			std::cout << "Image successfully written to " << outputPath << "\n";
		} else if (outputPath.find(EXTENSION_JPG) != std::string::npos || outputPath.find(EXTENSION_JPEG) != std::string::npos) {
			stbi_write_jpg(outputPath.data(), width, height, channels, pixels, 100);
			std::cout << "Image successfully written to " << outputPath << "\n";
		} else if (outputPath.find(EXTENSION_BMP) != std::string::npos) {
			stbi_write_bmp(outputPath.data(), width, height, channels, pixels);
			std::cout << "Image successfully written to " << outputPath << "\n";
		} else {
			std::cerr << "Error: Unsupported file format!" << std::endl;
		}

		delete[] pixels;
	}

} // namespace imgl