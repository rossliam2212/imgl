/**
 * @file FilterCommand.cpp
 * @author liam 
 * @date 28/01/2025
 */

#include "imgl/FilterCommand.hpp"

namespace imgl {
	FilterCommand::FilterCommand(const FilterCommandData& data)
		: data{data} {
	}

	void FilterCommand::execute() {
		if (validFilterType() && validInputPath()) {
			Image img{data.inputPath.c_str()};
			if (data.filterType == FILTER_TYPE_SHARPEN) {
				ImageProcessor::applySharpenFilter(img, data.outputPath, data.intensity);
			} else if (data.filterType == FILTER_TYPE_BLUR) {
				ImageProcessor::applyGaussianBlurFilter(img, data.outputPath, data.intensity);
			} else if (data.filterType == FILTER_TYPE_GRAYSCALE) {
				ImageProcessor::applyGrayscaleFilter(img, data.outputPath, data.intensity);
			}
		}
	}

	bool FilterCommand::validFilterType() const {
		static const std::unordered_set filterTypes = {
			FILTER_TYPE_SHARPEN,
			FILTER_TYPE_BLUR,
			FILTER_TYPE_GRAYSCALE
		};
		return filterTypes.find(data.filterType) != std::end(filterTypes);
	}

	bool FilterCommand::validInputPath() const {
		return utils::fileExists(data.inputPath);
	}
} // namespace imgl
