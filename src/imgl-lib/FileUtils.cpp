/**
 * @file FileUtils.cpp
 * @author liam 
 * @date 03/02/2025
 */

#include "imgl/FileUtils.hpp"

namespace imgl::utils {
	bool fileExists(const std::string_view filePath) {
		return fs::exists(filePath) && fs::is_regular_file(filePath);
	}

	bool directoryExists(const std::string_view dirPath) {
		return fs::exists(dirPath) && fs::is_directory(dirPath);
	}
} // namespace imgl::utils