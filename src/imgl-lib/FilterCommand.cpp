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
				ImageProcessor::applyFilter(img, data.outputPath, data.intensity, FilterType::SHARPEN);
			} else if (data.filterType == FILTER_TYPE_BOX_BLUR) {
				ImageProcessor::applyFilter(img, data.outputPath, data.intensity, FilterType::BOX_BLUR);
			} else if (data.filterType == FILTER_TYPE_GAUSSIAN_BLUR) {
				ImageProcessor::applyFilter(img, data.outputPath, data.intensity, FilterType::GAUSSIAN_BLUR);
			} else if (data.filterType == FILTER_TYPE_GRAYSCALE) {
				ImageProcessor::applyFilter(img, data.outputPath, data.intensity, FilterType::GRAYSCALE);
			}

			if (data.show) {
				const std::string cmd{"open " + data.outputPath};
				std::system(cmd.c_str());
			}
		}
	}

	bool FilterCommand::validFilterType() const {
		static const std::unordered_set filterTypes = {
			FILTER_TYPE_SHARPEN,
			FILTER_TYPE_BOX_BLUR,
			FILTER_TYPE_GAUSSIAN_BLUR,
			FILTER_TYPE_GRAYSCALE
		};
		return filterTypes.find(data.filterType) != std::end(filterTypes);
	}

	bool FilterCommand::validInputPath() const {
		return utils::fileExists(data.inputPath);
	}
} // namespace imgl
