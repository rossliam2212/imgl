/**
 * @file TransformCommandHandler.hpp
 * @author liam 
 * @date 31/01/2025
 */

#ifndef TRANSFORMCOMMANDHANDLER_HPP
#define TRANSFORMCOMMANDHANDLER_HPP

#include <CLI/CLI.hpp>

#include "Defines.hpp"
#include "CommandData.hpp"

namespace imgl {
	class TransformCommandHandler {
	public:
    	TransformCommandHandler() = default;
    	~TransformCommandHandler() = default;

		void setup(CLI::App& app);
		explicit operator bool() const;

		TransformCommandData getData() const;

	private:
		CLI::App* transformHandler{nullptr};
		TransformCommandData data;
	};
} // namespace imgl

#endif //TRANSFORMCOMMANDHANDLER_HPP
