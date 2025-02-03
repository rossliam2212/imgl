/**
 * @file TransformCommandHandler.cpp
 * @author liam 
 * @date 31/01/2025
 */

#include "imgl/TransformCommandHandler.hpp"

namespace imgl {
	void TransformCommandHandler::setup(CLI::App& app) {
		transformHandler = app.add_subcommand(TRANSFORM_CMD, "Apply image transformations");

		transformHandler->add_option(TRANSFORM_OPTION_TYPE, data.transformType, "Type of transformation to apply")
			->required();
		transformHandler->add_option(TRANSFORM_OPTION_INPUT, data.inputPath, "Path to input image")
			->required();
		transformHandler->add_option(TRANSFORM_OPTION_OUTPUT, data.outputPath, "Path to output image")
			->required();
		transformHandler->add_option(TRANSFORM_OPTION_ANGLE, data.angle, "Angle to rotate the image by");
		transformHandler->add_option(TRANSFORM_OPTION_WIDTH, data.width, "New image width for resize");
		transformHandler->add_option(TRANSFORM_OPTION_HEIGHT, data.height, "New image height for resize");
	}

	TransformCommandHandler::operator bool() const {
		if (*transformHandler) {
			return true;
		}
		return false;
	}

	TransformCommandData TransformCommandHandler::getData() const {
		return data;
	}
} // namespace imgl