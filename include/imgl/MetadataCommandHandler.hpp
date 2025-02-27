/**
 * @file MetadataCommandHandler.hpp
 * @author liam 
 * @date 27/02/2025
 */

#ifndef METADATACOMMANDHANDLER_HPP
#define METADATACOMMANDHANDLER_HPP

#include <CLI/CLI.hpp>

#include "Defines.hpp"
#include "CommandData.hpp"

namespace imgl {
	class MetadataCommandHandler {
	public:
    	MetadataCommandHandler() = default;
    	~MetadataCommandHandler() = default;

		void setup(CLI::App& app);
		explicit operator bool() const;

		MetadataCommandData getData() const;

	private:
		CLI::App* metadataHandler{nullptr};
		MetadataCommandData data;
	};
} // namespace imgl

#endif //METADATACOMMANDHANDLER_HPP
