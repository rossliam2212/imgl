/**
 * @file FileUtils.hpp
 * @author liam 
 * @date 03/02/2025
 */

#ifndef FILEUTILS_HPP
#define FILEUTILS_HPP

#include <string_view>
#include <filesystem>

namespace fs = std::filesystem;

namespace imgl::utils {
    bool fileExists(std::string_view filePath);
    bool directoryExists(std::string_view dirPath);
} // namespace imgl::utils

#endif //FILEUTILS_HPP
