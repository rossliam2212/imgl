/**
 * @file Defines.hpp
 * @author liam 
 * @date 30/01/2025
 */

#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <string>

namespace imgl {
	inline const char* DEBUG_OPTION{"-d,--debug"};

	inline const char* FILTER_CMD{"filter"};
	inline const char* FILTER_OPTION_TYPE{"type"};
	inline const char* FILTER_OPTION_INPUT{"input"};
	inline const char* FILTER_OPTION_OUTPUT{"-o,--output"};
	inline const char* FILTER_OPTION_INTENSITY{"--intensity"};

	const std::string FILTER_TYPE_SHARPEN{"sharpen"};
	const std::string FILTER_TYPE_BLUR{"blur"};
	const std::string FILTER_TYPE_GRAYSCALE{"grayscale"};
	constexpr float FILTER_OPTION_INTENSITY_MIN{0.1f};
	constexpr float FILTER_OPTION_INTENSITY_MAX{2.f};

	inline const char* TRANSFORM_CMD{"transform"};
	inline const char* TRANSFORM_OPTION_TYPE{"type"};
	inline const char* TRANSFORM_OPTION_INPUT{"input"};
	inline const char* TRANSFORM_OPTION_OUTPUT{"-o,--output"};
	inline const char* TRANSFORM_OPTION_ANGLE{"--angle"};
	inline const char* TRANSFORM_OPTION_WIDTH{"--width"};
	inline const char* TRANSFORM_OPTION_HEIGHT{"--height"};

	inline const char* DEFAULT_VERT_SHADER{"../../../resources/shaders/default_vertex.glsl"};
	inline const char* SHARPEN_FRAG_SHADER{"../../../resources/shaders/sharpen_fragment.glsl"};
	inline const char* BOX_BLUR_FRAG_SHADER{"../../../resources/shaders/box_blur_fragment.glsl"};
	inline const char* GAUSSIAN_BLUR_FRAG_SHADER{"../../../resources/shaders/gaussian_blur_fragment.glsl"};
	inline const char* GRAY_SCALE_FRAG_SHADER{"../../../resources/shaders/grayscale_fragment.glsl"};

	inline const char* EXTENSION_PNG{".png"};
	inline const char* EXTENSION_JPG{".jpg"};
	inline const char* EXTENSION_JPEG{".jpEg"};
	inline const char* EXTENSION_BMP{".bmp"};
} // namespace imgl

#endif //DEFINES_HPP
