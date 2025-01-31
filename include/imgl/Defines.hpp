/**
 * @file Defines.hpp
 * @author liam 
 * @date 30/01/2025
 */

#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <string>

namespace imgl {
	inline const char* FILTER_CMD{"filter"};
	inline const char* FILTER_OPTION_TYPE{"type"};
	inline const char* FILTER_OPTION_INPUT{"input"};
	inline const char* FILTER_OPTION_OUTPUT{"-o,--output"};
	inline const char* FILTER_OPTION_INTENSITY{"--intensity"};

	inline const char* TRANSFORM_CMD{"transform"};
	inline const char* TRANSFORM_OPTION_TYPE{"type"};
	inline const char* TRANSFORM_OPTION_INPUT{"input"};
	inline const char* TRANSFORM_OPTION_OUTPUT{"-o,--output"};
	inline const char* TRANSFORM_OPTION_ANGLE{"--angle"};
	inline const char* TRANSFORM_OPTION_WIDTH{"--width"};
	inline const char* TRANSFORM_OPTION_HEIGHT{"--height"};
} // namespace imgl

#endif //DEFINES_HPP
