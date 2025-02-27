/**
 * @file MetadataCommandHandler.cpp
 * @author liam 
 * @date 27/02/2025
 */

#include "imgl/MetadataCommandHandler.hpp"

namespace imgl {
	void MetadataCommandHandler::setup(CLI::App& app) {
		metadataHandler = app.add_subcommand(METADATA_CMD);

		metadataHandler->description(R"(This subcommand retrieves image metadata.)");

		metadataHandler->footer(R"(Examples:
  imgl metadata ~/image.jpg
)");
	}

	MetadataCommandHandler::operator bool() const {
		if (*metadataHandler) {
			return true;
		}
		return false;
	}

	MetadataCommandData MetadataCommandHandler::getData() const {
		return data;
	}
} // namespace imgl