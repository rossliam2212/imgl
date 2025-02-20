/**
 * @file ImageProcessor.hpp
 * @author liam 
 * @date 03/02/2025
 */

#ifndef IMAGEPROCESSOR_HPP
#define IMAGEPROCESSOR_HPP

#include <string_view>
#include <spdlog/spdlog.h>

#include "Defines.hpp"
#include "Image.hpp"
#include "RenderUtils.hpp"
#include "FrameBuffer.hpp"
#include "Shader.hpp"
#include "stb-image/stb_image.h"
#include "stb-image/stb_image_write.h"

namespace imgl {
	enum class FilterType {
		SHARPEN,
		BOX_BLUR,
		GAUSSIAN_BLUR,
		GRAYSCALE
	};

	class ImageProcessor {
	public:
    	ImageProcessor() = default;
    	~ImageProcessor() = default;

		static void applyFilter(Image& img, std::string_view outputPath, float intensity, FilterType filterType);

	private:
		static Shader retrieveShader(FilterType filterType);
		static void outputImage(const FrameBuffer& fbo, std::string_view outputPath, int width, int height, int channels);
	};
} // namespace imgl

#endif //IMAGEPROCESSOR_HPP
