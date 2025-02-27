/**
 * @file MetadataCommand.hpp
 * @author liam 
 * @date 22/02/2025
 */

#ifndef METADATACOMMAND_HPP
#define METADATACOMMAND_HPP

#include "ICommand.hpp"
#include "CommandData.hpp"
#include "Defines.hpp"
#include "FileUtils.hpp"
#include "ImageProcessor.hpp"

namespace imgl {
	class MetadataCommand : public ICommand {
	public:
    	MetadataCommand(const MetadataCommandData& data);
    	~MetadataCommand() override = default;

		void execute() override;

	private:
		MetadataCommandData data;

		bool validInputPath() const;
	};
} // namespace imgl

#endif //METADATACOMMAND_HPP
