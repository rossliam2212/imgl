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

	std::string readFile(std::string_view filePath) {
		std::string content;
		std::ifstream fileStream{filePath.data(), std::ios::in};

		if (!fileStream.is_open()) {
			return "";
		}

		std::string line{};
		while (!fileStream.eof()) {
			std::getline(fileStream, line);
			content.append(line + "\n");
		}

		fileStream.close();
		return content;
	}
} // namespace imgl::utils