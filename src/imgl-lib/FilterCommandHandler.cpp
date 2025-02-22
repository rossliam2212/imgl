/**
 * @file FilterCommandHandler.cpp
 * @author liam 
 * @date 30/01/2025
 */

#include "imgl/FilterCommandHandler.hpp"

namespace imgl {
    void FilterCommandHandler::setup(CLI::App& app) {
    	filterHandler = app.add_subcommand(FILTER_CMD);

    	filterHandler->description(R"(This subcommand applies various image filters.

Supported filter types:
- sharpen        [min: 0.0 | max: 2.0]
- box-blur       [min: 0.0 | max: 1.0]
- gaussian-blur  [min: 0.0 | max: 1.0]
- grayscale      [min: 0.0 | max: 1.0]
)");

    	filterHandler->footer(R"(Examples:
  imgl filter sharpen ~/image.jpg --output ~/sharpened.png --intensity=1.5
  imgl filter grayscale ~/image.jpg -o ~/gray.png --intensity=0.5
  imgl filter box-blur ~/image.jpg -o ~/blur.png --intensity=1 --show
)");

		filterHandler->add_option(FILTER_OPTION_TYPE, data.filterType, "Type of filter to apply")
    		->required();
		filterHandler->add_option(FILTER_OPTION_INPUT, data.inputPath, "Path to input image")
    		->required()->check(CLI::ExistingFile);
		filterHandler->add_option(FILTER_OPTION_OUTPUT, data.outputPath, "Path to output image")
    		->required();
		filterHandler->add_option(FILTER_OPTION_INTENSITY, data.intensity, "Intensity of the filter")
    		->check(CLI::Range(0.f, 2.f))->default_val(0.f);

    	filterHandler->add_flag(FILTER_OPTION_SHOW, data.show, "Show the resulting image");
	}

	FilterCommandHandler::operator bool() const {
		if (*filterHandler) {
			return true;
		}
    	return false;
	}

	FilterCommandData FilterCommandHandler::getData() const {
    	return data;
    }
} // namespace imgl