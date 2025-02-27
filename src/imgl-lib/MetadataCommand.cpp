/**
 * @file MetadataCommand.cpp
 * @author liam 
 * @date 22/02/2025
 */

#include "imgl/MetadataCommand.hpp"

namespace imgl {
	MetadataCommand::MetadataCommand(const MetadataCommandData& data)
		: data{data} {
	}

	void MetadataCommand::execute() {
		spdlog::debug("Executing metadata subcommand...");
		if (validInputPath()) {
			Image img{data.inputPath.c_str()};
		}
	}

	bool MetadataCommand::validInputPath() const {
		return utils::fileExists(data.inputPath);
	}
} // namespace imgl
