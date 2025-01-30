/**
 * @file FilterCommandHandler.cpp
 * @author liam 
 * @date 30/01/2025
 */

#include "imgl/FilterCommandHandler.hpp"

namespace imgl {
    void FilterCommandHandler::setup(CLI::App& app) {
		// TODO Add these to Defines.hpp when created
		filterHandler = app.add_subcommand("filter", "Apply image filters");
		filterHandler->add_option("type", data.outputPath, "Type of filter to apply")->required();
		filterHandler->add_option("input", data.inputPath, "Path to input image")->required();
		filterHandler->add_option("-o,--output", data.outputPath, "Path to output image")->required();
		filterHandler->add_option("--intensity", data.intensity, "Intensity of the filter")->default_val(0.0);
	}

	FilterCommandHandler::operator bool() const {
		return filterHandler;
	}

	FilterCommandData FilterCommandHandler::getData() const {
    	return data;
    }
} // namespace imgl