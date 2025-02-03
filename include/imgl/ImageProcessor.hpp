/**
 * @file ImageProcessor.hpp
 * @author liam 
 * @date 03/02/2025
 */

#ifndef IMAGEPROCESSOR_HPP
#define IMAGEPROCESSOR_HPP

#include <string_view>

#include "Image.hpp"

namespace imgl {
	class ImageProcessor {
	public:
    	ImageProcessor() = default;
    	~ImageProcessor() = default;

		static void applySharpenFilter(std::string_view imagePath, std::string_view outputPath, float intensity);
		static void applyGaussianBlurFilter(std::string_view imagePath, std::string_view outputPath, float intensity);
		static void applyGrayscaleFilter(std::string_view imagePath, std::string_view outputPath, float intensity);
	};
} // namespace imgl

#endif //IMAGEPROCESSOR_HPP
