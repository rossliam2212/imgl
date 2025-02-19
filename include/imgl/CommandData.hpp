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
		std::string filterType;
		std::string inputPath;
		std::string outputPath;
		float intensity;
		bool show;
	};

	struct TransformCommandData {
		std::string transformType;
		std::string inputPath;
		std::string outputPath;
		float width;
		float height;
		float angle;
		bool show;
	};
} // namespace imgl

#endif //COMMANDDATA_HPP
