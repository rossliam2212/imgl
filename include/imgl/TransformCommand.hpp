/**
 * @file TransformCommand.hpp
 * @author liam 
 * @date 30/01/2025
 */

#ifndef TRANSFORMCOMMAND_HPP
#define TRANSFORMCOMMAND_HPP

#include "ICommand.hpp"
#include "CommandData.hpp"

namespace imgl {
	class TransformCommand : public ICommand {
	public:
    	TransformCommand(const TransformCommandData& data);
    	~TransformCommand() override = default;

		void execute() override;

	private:
		TransformCommandData data;
	};
} // namespace imgl {

#endif //TRANSFORMCOMMAND_HPP
