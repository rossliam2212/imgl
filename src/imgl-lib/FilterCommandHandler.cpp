/**
 * @file FilterCommandHandler.cpp
 * @author liam 
 * @date 30/01/2025
 */

#include "imgl/FilterCommandHandler.hpp"

namespace imgl {
    void FilterCommandHandler::setup(CLI::App& app) {
    	filterHandler = app.add_subcommand(FILTER_CMD, "Apply image filters");

		filterHandler->add_option(FILTER_OPTION_TYPE, data.filterType, "Type of filter to apply")
    		->required();
		filterHandler->add_option(FILTER_OPTION_INPUT, data.inputPath, "Path to input image")
    		->required();
		filterHandler->add_option(FILTER_OPTION_OUTPUT, data.outputPath, "Path to output image")
    		->required();
		filterHandler->add_option(FILTER_OPTION_INTENSITY, data.intensity, "Intensity of the filter")
    		->default_val(0.0);
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