/**
 * @file CommandData.hpp
 * @author liam 
 * @date 30/01/2025
 */

#ifndef COMMANDDATA_HPP
#define COMMANDDATA_HPP

#include <string>

namespace imgl {
	struct FilterCommandData {
		std::string filterType; // TODO Could make the filter type an enum...
		std::string inputPath;
		std::string outputPath;
		float intensity;
	};

	struct TransformCommandData {
		std::string transformType;
		std::string inputPath;
		std::string outputPath;
		float width;
		float height;
		float angle;
	};
} // namespace imgl

#endif //COMMANDDATA_HPP
