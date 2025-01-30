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
		std::cout << "FilterCommand::execute()" << std::endl;
	}
} // namespace imgl
