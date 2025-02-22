/**
 * @file ImageProcessor.cpp
 * @author liam 
 * @date 03/02/2025
 */

#include "imgl/ImageProcessor.hpp"

namespace imgl {
	void ImageProcessor::applyFilter(Image& img, std::string_view outputPath, float intensity, FilterType filterType) {
		const int width = img.getWidth();
		const int height = img.getHeight();
		const int channels = img.getChannels();

		FrameBuffer fbo{width, height};
		fbo.bind();

		Shader shader = retrieveShader(filterType);
		shader.enable();

		// TODO move to Image class...
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, img.getTexture());
		shader.setInt("image", 0);
		shader.setFloat("intensity", intensity);

		RenderUtils::render();

		outputImage(fbo, outputPath, width, height, channels);

		fbo.unbind();
		shader.disable();
		RenderUtils::cleanup();
	}

	Shader ImageProcessor::retrieveShader(const FilterType filterType) {
		switch (filterType) {
			case FilterType::SHARPEN:
				return {DEFAULT_VERT_SHADER, SHARPEN_FRAG_SHADER};
			case FilterType::BOX_BLUR:
				return {DEFAULT_VERT_SHADER, BOX_BLUR_FRAG_SHADER};
			case FilterType::GAUSSIAN_BLUR:
				return {DEFAULT_VERT_SHADER, GAUSSIAN_BLUR_FRAG_SHADER};
			case FilterType::GRAYSCALE:
				return {DEFAULT_VERT_SHADER, GRAY_SCALE_FRAG_SHADER};
			default:
				throw std::runtime_error("Unknown filter type");
		}
	}

	void ImageProcessor::outputImage(const FrameBuffer& fbo, const std::string_view outputPath, const int width, const int height, const int channels) {
		spdlog::debug("Attempting to write image...");

		const int format = channels == 4 ? GL_RGBA : GL_RGB;
		auto* pixels = new unsigned char[width * height * 3];
		glBindTexture(GL_TEXTURE_2D, fbo.getTexture());
		glGetTexImage(GL_TEXTURE_2D, 0, format, GL_UNSIGNED_BYTE, pixels);
		spdlog::debug("Image data: [width='{}', height='{}', channels='{}']", width, height, channels);

		if (outputPath.find(EXTENSION_PNG) != std::string::npos) {
			stbi_write_png(outputPath.data(), width, height, channels, pixels, width * channels);
			spdlog::info("Image successfully written to: '{}'", outputPath);
		} else if (outputPath.find(EXTENSION_JPG) != std::string::npos || outputPath.find(EXTENSION_JPEG) != std::string::npos) {
			stbi_write_jpg(outputPath.data(), width, height, channels, pixels, 100);
			spdlog::info("Image successfully written to: '{}'", outputPath);
		} else if (outputPath.find(EXTENSION_BMP) != std::string::npos) {
			stbi_write_bmp(outputPath.data(), width, height, channels, pixels);
			spdlog::info("Image successfully written to: '{}'", outputPath);
		} else {
			spdlog::error("Failed to write image. Unsupported image format.");
		}

		delete[] pixels;
	}

} // namespace imgl